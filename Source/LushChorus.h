/*
    Lush Chorus - High Quality Multi-Voice Chorus

    Features:
    - 4 voices with different LFO phases for rich stereo spread
    - Cubic interpolated delay lines for smooth modulation
    - Optional high-pass filter on wet signal to prevent muddy bass
    - Separate L/R modulation for natural stereo image
*/

#pragma once
#include <juce_dsp/juce_dsp.h>
#include <array>
#include <cmath>

class LushChorus
{
public:
    LushChorus() = default;

    void prepare(double newSampleRate, int /*samplesPerBlock*/)
    {
        sampleRate = newSampleRate;

        // Max delay of 50ms for chorus
        maxDelaySamples = static_cast<int>(sampleRate * 0.05);

        // Initialize delay buffers (stereo, 4 voices each)
        for (int v = 0; v < numVoices; ++v)
        {
            delayBufferL[v].resize(maxDelaySamples + 4, 0.0f);
            delayBufferR[v].resize(maxDelaySamples + 4, 0.0f);
        }

        // Initialize high-pass filter for wet signal (removes muddy bass)
        highPassCoeff = 1.0f - std::exp(-2.0f * juce::MathConstants<float>::pi * 80.0f / static_cast<float>(sampleRate));

        reset();
    }

    void reset()
    {
        for (int v = 0; v < numVoices; ++v)
        {
            std::fill(delayBufferL[v].begin(), delayBufferL[v].end(), 0.0f);
            std::fill(delayBufferR[v].begin(), delayBufferR[v].end(), 0.0f);
            writePos[v] = 0;
        }
        lfoPhase = 0.0f;
        hpStateL = 0.0f;
        hpStateR = 0.0f;
    }

    void process(juce::AudioBuffer<float>& buffer, float rate, float depth, float mix)
    {
        if (buffer.getNumChannels() < 2 || mix < 0.001f)
            return;

        auto* leftChannel = buffer.getWritePointer(0);
        auto* rightChannel = buffer.getWritePointer(1);
        const int numSamples = buffer.getNumSamples();

        // Voice LFO phase offsets for rich stereo spread
        const float phaseOffsets[numVoices] = { 0.0f, 0.25f, 0.5f, 0.75f };

        // Stereo offset between L/R for each voice
        const float stereoOffset = 0.125f;

        // Base delay time: 7-15ms range
        const float baseDelayMs = 10.0f;
        const float baseDelaySamples = baseDelayMs * 0.001f * static_cast<float>(sampleRate);

        // Modulation depth in samples (±3ms at full depth)
        const float modDepthSamples = depth * 3.0f * 0.001f * static_cast<float>(sampleRate);

        // LFO increment per sample
        const float lfoInc = rate / static_cast<float>(sampleRate);

        for (int i = 0; i < numSamples; ++i)
        {
            const float inputL = leftChannel[i];
            const float inputR = rightChannel[i];

            float wetL = 0.0f;
            float wetR = 0.0f;

            // Process each voice
            for (int v = 0; v < numVoices; ++v)
            {
                // Write input to delay buffers
                delayBufferL[v][writePos[v]] = inputL;
                delayBufferR[v][writePos[v]] = inputR;

                // Calculate LFO value for this voice (with stereo offset)
                float voicePhase = lfoPhase + phaseOffsets[v];
                if (voicePhase >= 1.0f) voicePhase -= 1.0f;

                float voicePhaseR = voicePhase + stereoOffset;
                if (voicePhaseR >= 1.0f) voicePhaseR -= 1.0f;

                // Smooth sine LFO with slight triangle blend for character
                float lfoL = std::sin(voicePhase * juce::MathConstants<float>::twoPi);
                float lfoR = std::sin(voicePhaseR * juce::MathConstants<float>::twoPi);

                // Calculate delay times
                float delayL = baseDelaySamples + lfoL * modDepthSamples;
                float delayR = baseDelaySamples + lfoR * modDepthSamples;

                // Clamp delay times
                delayL = juce::jlimit(1.0f, static_cast<float>(maxDelaySamples - 2), delayL);
                delayR = juce::jlimit(1.0f, static_cast<float>(maxDelaySamples - 2), delayR);

                // Read from delay with cubic interpolation
                wetL += readDelayInterp(delayBufferL[v], writePos[v], delayL);
                wetR += readDelayInterp(delayBufferR[v], writePos[v], delayR);

                // Advance write position for this voice
                writePos[v] = (writePos[v] + 1) % maxDelaySamples;
            }

            // Average the voices
            wetL *= 0.25f;
            wetR *= 0.25f;

            // High-pass filter on wet signal to reduce muddiness
            hpStateL += highPassCoeff * (wetL - hpStateL);
            hpStateR += highPassCoeff * (wetR - hpStateR);
            float filteredWetL = wetL - hpStateL;
            float filteredWetR = wetR - hpStateR;

            // Mix dry and wet
            leftChannel[i] = inputL * (1.0f - mix * 0.5f) + filteredWetL * mix;
            rightChannel[i] = inputR * (1.0f - mix * 0.5f) + filteredWetR * mix;

            // Advance LFO phase
            lfoPhase += lfoInc;
            if (lfoPhase >= 1.0f) lfoPhase -= 1.0f;
        }
    }

private:
    double sampleRate = 44100.0;
    static constexpr int numVoices = 4;
    int maxDelaySamples = 2205;

    std::array<std::vector<float>, numVoices> delayBufferL;
    std::array<std::vector<float>, numVoices> delayBufferR;
    std::array<int, numVoices> writePos = { 0, 0, 0, 0 };

    float lfoPhase = 0.0f;
    float highPassCoeff = 0.0f;
    float hpStateL = 0.0f;
    float hpStateR = 0.0f;

    // Cubic Hermite interpolation for smooth delay reading
    float readDelayInterp(const std::vector<float>& buffer, int writePosition, float delaySamples) const
    {
        float readPos = static_cast<float>(writePosition) - delaySamples;
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
};
