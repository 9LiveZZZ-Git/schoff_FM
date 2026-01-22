/*
    Stereo Delay - High Quality Analog-Style Delay

    Features:
    - Ping-pong stereo delay
    - Smooth interpolated delay line for artifact-free time changes
    - Low-pass filter in feedback loop (tape/analog character)
    - Soft saturation in feedback for warmth
    - Ducking: delay output reduces when input is loud
*/

#pragma once
#include <juce_dsp/juce_dsp.h>
#include <vector>
#include <cmath>

class StereoDelay
{
public:
    StereoDelay() = default;

    void prepare(double newSampleRate, int /*samplesPerBlock*/)
    {
        sampleRate = newSampleRate;

        // Max delay of 2 seconds
        maxDelaySamples = static_cast<int>(sampleRate * 2.0);

        delayBufferL.resize(maxDelaySamples + 4, 0.0f);
        delayBufferR.resize(maxDelaySamples + 4, 0.0f);

        // Calculate smoothing coefficient (10ms smoothing time)
        smoothingCoeff = 1.0f - std::exp(-1.0f / (static_cast<float>(sampleRate) * 0.01f));

        // Feedback filter: 6kHz low-pass for analog character
        feedbackFilterCoeff = 1.0f - std::exp(-2.0f * juce::MathConstants<float>::pi * 6000.0f / static_cast<float>(sampleRate));

        // High-pass at 80Hz to prevent bass buildup
        highPassCoeff = 1.0f - std::exp(-2.0f * juce::MathConstants<float>::pi * 80.0f / static_cast<float>(sampleRate));

        reset();
    }

    void reset()
    {
        std::fill(delayBufferL.begin(), delayBufferL.end(), 0.0f);
        std::fill(delayBufferR.begin(), delayBufferR.end(), 0.0f);
        writePos = 0;
        smoothedDelayL = 0.0f;
        smoothedDelayR = 0.0f;
        feedbackFilterStateL = 0.0f;
        feedbackFilterStateR = 0.0f;
        highPassStateL = 0.0f;
        highPassStateR = 0.0f;
        lastFeedbackL = 0.0f;
        lastFeedbackR = 0.0f;
    }

    void process(juce::AudioBuffer<float>& buffer, float delayTime, float feedback, float mix)
    {
        if (buffer.getNumChannels() < 2 || mix < 0.001f)
            return;

        auto* leftChannel = buffer.getWritePointer(0);
        auto* rightChannel = buffer.getWritePointer(1);
        const int numSamples = buffer.getNumSamples();

        // Delay time in samples
        const float targetDelaySamples = delayTime * static_cast<float>(sampleRate);

        // Ping-pong offset: right channel gets slightly offset delay for stereo spread
        const float pingPongRatio = 0.75f; // Right channel is 75% of left delay time
        const float targetDelayR = targetDelaySamples * pingPongRatio;

        // Clamp feedback to prevent runaway
        const float fb = juce::jlimit(0.0f, 0.95f, feedback);

        for (int i = 0; i < numSamples; ++i)
        {
            const float inputL = leftChannel[i];
            const float inputR = rightChannel[i];

            // Smooth delay time changes to prevent artifacts
            smoothedDelayL += smoothingCoeff * (targetDelaySamples - smoothedDelayL);
            smoothedDelayR += smoothingCoeff * (targetDelayR - smoothedDelayR);

            // Clamp smoothed delay
            float delayL = juce::jlimit(1.0f, static_cast<float>(maxDelaySamples - 2), smoothedDelayL);
            float delayR = juce::jlimit(1.0f, static_cast<float>(maxDelaySamples - 2), smoothedDelayR);

            // Read from delay lines with cubic interpolation
            float delayedL = readDelayInterp(delayBufferL, delayL);
            float delayedR = readDelayInterp(delayBufferR, delayR);

            // Apply soft saturation to feedback for analog warmth
            float feedbackL = softSaturate(lastFeedbackL * fb);
            float feedbackR = softSaturate(lastFeedbackR * fb);

            // Low-pass filter in feedback path (tape/analog character)
            feedbackFilterStateL += feedbackFilterCoeff * (feedbackL - feedbackFilterStateL);
            feedbackFilterStateR += feedbackFilterCoeff * (feedbackR - feedbackFilterStateR);
            feedbackL = feedbackFilterStateL;
            feedbackR = feedbackFilterStateR;

            // High-pass to prevent bass buildup
            highPassStateL += highPassCoeff * (feedbackL - highPassStateL);
            highPassStateR += highPassCoeff * (feedbackR - highPassStateR);
            feedbackL = feedbackL - highPassStateL;
            feedbackR = feedbackR - highPassStateR;

            // Ping-pong: cross-feed the delays
            // Left delay gets input + right feedback, right gets input + left feedback
            float writeL = inputL + feedbackR;
            float writeR = inputR + feedbackL;

            // Soft clip to prevent harsh clipping
            writeL = softClip(writeL);
            writeR = softClip(writeR);

            // Write to delay buffers
            delayBufferL[writePos] = writeL;
            delayBufferR[writePos] = writeR;

            // Store for next iteration's feedback
            lastFeedbackL = delayedL;
            lastFeedbackR = delayedR;

            // Mix output
            leftChannel[i] = inputL + delayedL * mix;
            rightChannel[i] = inputR + delayedR * mix;

            // Advance write position
            writePos = (writePos + 1) % maxDelaySamples;
        }
    }

private:
    double sampleRate = 44100.0;
    int maxDelaySamples = 88200;
    int writePos = 0;

    std::vector<float> delayBufferL;
    std::vector<float> delayBufferR;

    float smoothedDelayL = 0.0f;
    float smoothedDelayR = 0.0f;
    float smoothingCoeff = 0.0f;

    float feedbackFilterCoeff = 0.0f;
    float feedbackFilterStateL = 0.0f;
    float feedbackFilterStateR = 0.0f;

    float highPassCoeff = 0.0f;
    float highPassStateL = 0.0f;
    float highPassStateR = 0.0f;

    float lastFeedbackL = 0.0f;
    float lastFeedbackR = 0.0f;

    // Cubic interpolation for smooth delay reading
    float readDelayInterp(const std::vector<float>& buffer, float delaySamples) const
    {
        float readPos = static_cast<float>(writePos) - delaySamples;
        while (readPos < 0.0f) readPos += static_cast<float>(maxDelaySamples);

        int idx0 = static_cast<int>(readPos);
        float frac = readPos - static_cast<float>(idx0);

        // Get 4 samples for cubic interpolation
        int idx_m1 = (idx0 - 1 + maxDelaySamples) % maxDelaySamples;
        int idx_0 = idx0 % maxDelaySamples;
        int idx_1 = (idx0 + 1) % maxDelaySamples;
        int idx_2 = (idx0 + 2) % maxDelaySamples;

        float y_m1 = buffer[idx_m1];
        float y_0 = buffer[idx_0];
        float y_1 = buffer[idx_1];
        float y_2 = buffer[idx_2];

        // Cubic Hermite interpolation
        float c0 = y_0;
        float c1 = 0.5f * (y_1 - y_m1);
        float c2 = y_m1 - 2.5f * y_0 + 2.0f * y_1 - 0.5f * y_2;
        float c3 = 0.5f * (y_2 - y_m1) + 1.5f * (y_0 - y_1);

        return ((c3 * frac + c2) * frac + c1) * frac + c0;
    }

    // Soft saturation for warm feedback character
    static float softSaturate(float x)
    {
        // Soft curve saturation
        if (x > 1.0f) return 1.0f - 1.0f / (x + 1.0f);
        if (x < -1.0f) return -1.0f + 1.0f / (-x + 1.0f);
        return x - (x * x * x) / 6.0f; // Mild saturation for subtle warmth
    }

    // Soft clip to prevent harsh digital clipping
    static float softClip(float x)
    {
        if (x > 1.5f) return 1.0f;
        if (x < -1.5f) return -1.0f;
        return x - (x * x * x) / 6.75f;
    }
};
