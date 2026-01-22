/*
    Spectrum Analyzer for Schoffhauzer FM
    Uses JUCE's built-in dsp::FFT class
*/

#pragma once
#include <juce_dsp/juce_dsp.h>
#include <juce_audio_basics/juce_audio_basics.h>
#include <array>
#include <atomic>

class SpectrumAnalyzer
{
public:
    // FFT order: 2^11 = 2048 samples, gives 1024 frequency bins
    static constexpr int fftOrder = 11;
    static constexpr int fftSize = 1 << fftOrder;      // 2048
    static constexpr int numBins = fftSize / 2;        // 1024 frequency bins

    SpectrumAnalyzer()
        : fft(fftOrder),
          window(fftSize, juce::dsp::WindowingFunction<float>::hann)
    {
        std::fill(fftData.begin(), fftData.end(), 0.0f);
        std::fill(fifo.begin(), fifo.end(), 0.0f);
        std::fill(smoothedSpectrum.begin(), smoothedSpectrum.end(), 0.0f);
        fifoIndex = 0;
        nextFFTBlockReady = false;
    }

    // Call this from processBlock() for each sample
    void pushSample(float sample)
    {
        if (fifoIndex < fftSize)
        {
            fifo[fifoIndex++] = sample;

            if (fifoIndex == fftSize)
            {
                // Copy to FFT buffer and apply window
                std::copy(fifo.begin(), fifo.end(), fftData.begin());
                window.multiplyWithWindowingTable(fftData.data(), fftSize);

                // Perform FFT
                fft.performFrequencyOnlyForwardTransform(fftData.data());

                // Convert to dB and smooth
                for (int i = 0; i < numBins; ++i)
                {
                    float magnitude = fftData[i];
                    float db = juce::jlimit(-100.0f, 0.0f,
                        juce::Decibels::gainToDecibels(magnitude / (float)fftSize));

                    // Normalize to 0-1 range (where -100dB = 0, 0dB = 1)
                    float normalized = (db + 100.0f) / 100.0f;

                    // Smooth decay (fast attack, slow release)
                    if (normalized > smoothedSpectrum[i])
                        smoothedSpectrum[i] = normalized;
                    else
                        smoothedSpectrum[i] = smoothedSpectrum[i] * 0.95f + normalized * 0.05f;
                }

                nextFFTBlockReady.store(true);
                fifoIndex = 0;
            }
        }
    }

    // Call from timer callback to check if new data is ready
    bool isFFTReady() const { return nextFFTBlockReady.load(); }

    // Get the spectrum data (0-1 normalized, numBins values)
    const std::array<float, numBins>& getSpectrum()
    {
        nextFFTBlockReady.store(false);
        return smoothedSpectrum;
    }

    // Get bin frequency for a given index
    float getBinFrequency(int binIndex, float sampleRate) const
    {
        return (binIndex * sampleRate) / (float)fftSize;
    }

    int getNumBins() const { return numBins; }

private:
    juce::dsp::FFT fft;
    juce::dsp::WindowingFunction<float> window;

    std::array<float, fftSize> fifo;
    std::array<float, fftSize * 2> fftData;
    std::array<float, numBins> smoothedSpectrum;

    int fifoIndex = 0;
    std::atomic<bool> nextFFTBlockReady { false };
};
