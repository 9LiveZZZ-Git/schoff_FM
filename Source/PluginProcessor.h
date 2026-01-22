#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>
#include "SpectrumAnalyzer.h"
#include "HilbertStereoWidth.h"
#include "LushChorus.h"
#include "StereoDelay.h"

class PluginProcessor : public juce::AudioProcessor
{
public:
    PluginProcessor();
    ~PluginProcessor() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return JucePlugin_Name; }
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState& getAPVTS() { return apvts; }

    // FFT Spectrum Analyzer
    SpectrumAnalyzer spectrumAnalyzer;

    // Waveform buffer for oscilloscope display
    static constexpr int waveformBufferSize = 256;
    std::array<float, waveformBufferSize> waveformBuffer;
    std::atomic<int> waveformWritePos { 0 };
    std::atomic<bool> waveformReady { false };

    void getWaveformData(std::array<float, waveformBufferSize>& dest)
    {
        int pos = waveformWritePos.load();
        for (int i = 0; i < waveformBufferSize; ++i)
        {
            dest[i] = waveformBuffer[(pos + i) % waveformBufferSize];
        }
        waveformReady.store(false);
    }

    bool isWaveformReady() const { return waveformReady.load(); }

private:
    juce::AudioProcessorValueTreeState apvts;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    double currentSampleRate = 44100.0;
    int waveformSampleCounter = 0;
    int waveformDownsampleFactor = 64;  // Capture every Nth sample

    // Hilbert transform stereo widener
    HilbertStereoWidth hilbertStereoWidth;

    // High-quality effects
    LushChorus lushChorus;
    StereoDelay stereoDelay;

    // Oversampling
    std::unique_ptr<juce::dsp::Oversampling<float>> oversampling;
    int currentOversamplingFactor = 1;
    void updateOversampling(int factor);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
