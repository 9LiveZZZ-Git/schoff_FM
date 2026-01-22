/*
    JUCE FFT Integration for Schoffhauzer FM Spectrum Analyzer
    
    Add this to your PluginProcessor.h/.cpp to send FFT data to the WebView.
    Uses JUCE's built-in dsp::FFT class.
*/

#pragma once
#include <JuceHeader.h>
#include <array>
#include <atomic>

// =============================================================================
// FFT ANALYZER CLASS - Add to PluginProcessor.h
// =============================================================================

class SpectrumAnalyzer
{
public:
    // FFT order: 2^11 = 2048 samples, gives 1024 frequency bins
    // For higher resolution, use 12 (4096) or 13 (8192)
    static constexpr int fftOrder = 11;
    static constexpr int fftSize = 1 << fftOrder;      // 2048
    static constexpr int numBins = fftSize / 2;        // 1024 frequency bins
    
    SpectrumAnalyzer() : fft(fftOrder), window(fftSize, juce::dsp::WindowingFunction<float>::hann)
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


// =============================================================================
// PLUGIN PROCESSOR INTEGRATION
// =============================================================================

/*
In your PluginProcessor.h, add:

    SpectrumAnalyzer spectrumAnalyzer;

In processBlock(), add after your audio processing:

    // Feed samples to spectrum analyzer (mono mix or just left channel)
    for (int i = 0; i < buffer.getNumSamples(); ++i)
    {
        float sample = 0.0f;
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
            sample += buffer.getSample(ch, i);
        sample /= buffer.getNumChannels();
        
        spectrumAnalyzer.pushSample(sample);
    }
*/


// =============================================================================
// PLUGIN EDITOR - WEBVIEW FFT DATA SENDER
// =============================================================================

/*
In your PluginEditor, add a timer to send FFT data to the WebView.

class SchoffhauzerEditor : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    SchoffhauzerEditor(SchoffhauzerProcessor& p) 
        : AudioProcessorEditor(p), processor(p)
    {
        // ... setup WebView ...
        startTimerHz(30); // 30fps update rate
    }
    
    ~SchoffhauzerEditor() override { stopTimer(); }
    
private:
    void timerCallback() override
    {
        if (processor.spectrumAnalyzer.isFFTReady())
        {
            sendSpectrumToWebView();
        }
    }
    
    void sendSpectrumToWebView()
    {
        const auto& spectrum = processor.spectrumAnalyzer.getSpectrum();
        float sampleRate = processor.getSampleRate();
        int numBins = processor.spectrumAnalyzer.getNumBins();
        
        // Build JSON array of spectrum data
        // For efficiency, we'll downsample to ~256 display bins with log scaling
        juce::String js = "window.updateFFTData([";
        
        const int displayBins = 256;
        const float minFreq = 20.0f;
        const float maxFreq = 20000.0f;
        
        for (int i = 0; i < displayBins; ++i)
        {
            // Log-scale frequency mapping
            float t = (float)i / (displayBins - 1);
            float freq = minFreq * std::pow(maxFreq / minFreq, t);
            
            // Find corresponding FFT bin
            int bin = (int)(freq * (float)SpectrumAnalyzer::fftSize / sampleRate);
            bin = juce::jlimit(0, numBins - 1, bin);
            
            float value = spectrum[bin];
            
            js += juce::String(value, 4);
            if (i < displayBins - 1) js += ",";
        }
        
        js += "]);";
        
        // Execute in WebView
        webView.evaluateJavascript(js, nullptr);
    }
    
    SchoffhauzerProcessor& processor;
    // juce::WebBrowserComponent webView; // Your WebView
};
*/


// =============================================================================
// ALTERNATIVE: Encode as compact string for older WebView
// =============================================================================

/*
If evaluating JSON arrays is slow, encode as a compact string:

    juce::String encodeSpectrumAsString(const std::array<float, 1024>& spectrum, int displayBins)
    {
        juce::String result = "F"; // Prefix to identify FFT data
        
        for (int i = 0; i < displayBins; ++i)
        {
            // Map 0.0-1.0 to 00-99
            int encoded = juce::jlimit(0, 99, (int)(spectrum[i] * 99.0f));
            result += juce::String::formatted("%02d", encoded);
        }
        
        return result;
    }
    
Then in JS:
    
    window.fftString = encodedString;
    
And decode in the HTML:

    function decodeFFT(str) {
        if (!str || str.charAt(0) !== 'F') return null;
        var data = [];
        for (var i = 0; i < 256; i++) {
            var encoded = parseInt(str.substr(1 + i * 2, 2), 10);
            data.push(encoded / 99.0);
        }
        return data;
    }
*/
