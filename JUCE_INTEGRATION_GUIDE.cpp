// =============================================================================
// SCHOFFHAUZER FM SYNTHESIZER - JUCE INTEGRATION GUIDE
// =============================================================================
//
// This guide shows how to use the HTML faceplate with JUCE for VST/Standalone
//
// =============================================================================

// OPTION 1: faust2juce (Recommended for quick start)
// ---------------------------------------------------
// 
// 1. Install Faust: https://faust.grame.fr/downloads/
// 
// 2. Export to JUCE project:
//    faust2juce -nvoices 8 -midi schoff_stereo.dsp
//
// 3. This creates a JUCE project with:
//    - FaustPluginProcessor.cpp/h (DSP)
//    - FaustPluginEditor.cpp/h (Generic UI - we'll replace this)
//
// 4. Replace the generic UI with WebView faceplate (see OPTION 2 below)


// OPTION 2: JUCE WebBrowserComponent (Custom HTML GUI)
// ----------------------------------------------------
//
// In your PluginEditor.h:

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class SchoffhauzerEditor : public juce::AudioProcessorEditor,
                           private juce::WebBrowserComponent::Listener
{
public:
    SchoffhauzerEditor(SchoffhauzerProcessor& p) 
        : AudioProcessorEditor(&p), processor(p)
    {
        // Create WebView
        webView = std::make_unique<juce::WebBrowserComponent>();
        addAndMakeVisible(webView.get());
        
        // Load HTML faceplate from binary resources or file
        // Option A: From file
        juce::File htmlFile = juce::File::getSpecialLocation(
            juce::File::currentApplicationFile)
            .getSiblingFile("schoffhauzer_synth_faceplate.html");
        webView->goToURL(htmlFile.getFullPathName());
        
        // Option B: From embedded binary resource
        // juce::String html = juce::String::createStringFromData(
        //     BinaryData::schoffhauzer_synth_faceplate_html,
        //     BinaryData::schoffhauzer_synth_faceplate_htmlSize);
        // webView->goToURL("data:text/html," + juce::URL::addEscapeChars(html, false));
        
        setSize(900, 800);
    }
    
    void resized() override
    {
        webView->setBounds(getLocalBounds());
    }
    
    // Handle messages from JavaScript
    bool pageAboutToLoad(const juce::String& url) override
    {
        // Intercept juce:// protocol for parameter changes
        if (url.startsWith("juce://param/"))
        {
            auto parts = juce::StringArray::fromTokens(url.fromFirstOccurrenceOf("juce://param/", false, false), "/", "");
            if (parts.size() >= 2)
            {
                juce::String param = parts[0];
                float value = parts[1].getFloatValue();
                
                // Map parameter name to processor parameter
                if (auto* p = processor.getParameters()[getParamIndex(param)])
                {
                    p->setValueNotifyingHost(value);
                }
            }
            return false; // Don't actually navigate
        }
        return true;
    }
    
    // Send parameter changes TO JavaScript
    void parameterChanged(const juce::String& param, float value)
    {
        juce::String js = "window.updateParameter('" + param + "', " + juce::String(value) + ");";
        webView->goToURL("javascript:" + juce::URL::addEscapeChars(js, false));
    }
    
private:
    SchoffhauzerProcessor& processor;
    std::unique_ptr<juce::WebBrowserComponent> webView;
    
    int getParamIndex(const juce::String& name)
    {
        // Map UI param names to Faust parameter indices
        static std::map<juce::String, int> paramMap = {
            {"osc1_wave", 0},
            {"osc1_octave", 1},
            {"osc1_semi", 2},
            // ... add all parameters
        };
        auto it = paramMap.find(name);
        return it != paramMap.end() ? it->second : -1;
    }
};


// OPTION 3: Native JUCE LookAndFeel (Best performance)
// ----------------------------------------------------
//
// Convert the CSS themes to JUCE LookAndFeel classes.
// This is more work but gives best performance and native feel.
//
// Example theme class:

class CelestialLookAndFeel : public juce::LookAndFeel_V4
{
public:
    CelestialLookAndFeel()
    {
        // Colors from CSS
        setColour(juce::ResizableWindow::backgroundColourId, juce::Colour(0xff0a0a0f));
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(0xff00f5a0));
        setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(0xff252535));
        setColour(juce::Label::textColourId, juce::Colour(0xffe8e8f0));
    }
    
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
                          float sliderPosProportional, float rotaryStartAngle,
                          float rotaryEndAngle, juce::Slider& slider) override
    {
        // Custom knob drawing matching CSS style
        auto radius = (float)juce::jmin(width / 2, height / 2) - 4.0f;
        auto centreX = (float)x + (float)width * 0.5f;
        auto centreY = (float)y + (float)height * 0.5f;
        auto angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
        
        // Track
        juce::Path track;
        track.addCentredArc(centreX, centreY, radius, radius, 0.0f,
                           rotaryStartAngle, rotaryEndAngle, true);
        g.setColour(juce::Colour(0xff252535));
        g.strokePath(track, juce::PathStrokeType(3.0f, juce::PathStrokeType::curved,
                                                   juce::PathStrokeType::rounded));
        
        // Value arc
        juce::Path valueArc;
        valueArc.addCentredArc(centreX, centreY, radius, radius, 0.0f,
                               rotaryStartAngle, angle, true);
        g.setColour(juce::Colour(0xff00f5a0));
        g.strokePath(valueArc, juce::PathStrokeType(3.0f, juce::PathStrokeType::curved,
                                                     juce::PathStrokeType::rounded));
        
        // Center
        g.setColour(juce::Colour(0xff1a1a26));
        g.fillEllipse(centreX - radius * 0.65f, centreY - radius * 0.65f,
                      radius * 1.3f, radius * 1.3f);
        
        // Indicator
        juce::Path indicator;
        auto indicatorRadius = radius * 0.45f;
        auto indicatorX = centreX + indicatorRadius * std::cos(angle - juce::MathConstants<float>::halfPi);
        auto indicatorY = centreY + indicatorRadius * std::sin(angle - juce::MathConstants<float>::halfPi);
        g.setColour(juce::Colour(0xff00f5a0));
        g.fillEllipse(indicatorX - 2.5f, indicatorY - 2.5f, 5.0f, 5.0f);
    }
};


// =============================================================================
// FAUST PARAMETER PATHS
// =============================================================================
//
// These are the parameter paths generated by Faust from schoff_stereo.dsp:
//
// Oscillator 1:
//   /OSCILLATORS/OSC1/Wave
//   /OSCILLATORS/OSC1/Oct
//   /OSCILLATORS/OSC1/Semi
//   /OSCILLATORS/OSC1/Fine
//   /OSCILLATORS/OSC1/PW
//   /OSCILLATORS/OSC1/Level
//   /OSCILLATORS/OSC1/Pan
//   /OSCILLATORS/OSC1/Stereo
//
// Oscillator 2:
//   /OSCILLATORS/OSC2/Wave
//   /OSCILLATORS/OSC2/Oct
//   /OSCILLATORS/OSC2/Semi
//   /OSCILLATORS/OSC2/Fine
//   /OSCILLATORS/OSC2/PW
//   /OSCILLATORS/OSC2/Level
//   /OSCILLATORS/OSC2/Pan
//   /OSCILLATORS/OSC2/Stereo
//
// Sub:
//   /OSCILLATORS/SUB/Wave
//   /OSCILLATORS/SUB/Oct
//   /OSCILLATORS/SUB/Level
//   /OSCILLATORS/SUB/Crisp
//   /OSCILLATORS/SUB/CrspHPF
//   /OSCILLATORS/SUB/CrspLPF
//   /OSCILLATORS/SUB/CrspDrv
//
// Noise:
//   /OSCILLATORS/NOISE/Type
//   /OSCILLATORS/NOISE/Level
//
// Filter:
//   /FILTER/Cutoff
//   /FILTER/Reso
//   /FILTER/EnvAmt
//   /FILTER/KeyTrk
//   /FILTER/Amount
//
// Envelopes:
//   /ENVELOPES/AMP/A, D, S, R
//   /ENVELOPES/FILTER/A, D, S, R
//
// Master:
//   /MASTER/Width
//   /MASTER/Gain
//
// Effects:
//   /FX/Exciter/Freq, Drive, Mix
//   /FX/Chorus/Rate, Depth, Wet
//   /FX/Delay/Time, Fdbk, Tone, Wet
//   /FX/Reverb/Type, Size, Damp, Mod, Wet


// =============================================================================
// BUILD INSTRUCTIONS
// =============================================================================
//
// 1. Install JUCE: https://juce.com/get-juce/download
// 2. Install Faust: https://faust.grame.fr/downloads/
// 3. Generate JUCE project: faust2juce -nvoices 8 -midi schoff_stereo.dsp
// 4. Open in Projucer, add WebBrowserComponent to modules
// 5. Replace PluginEditor with WebView version above
// 6. Add schoffhauzer_synth_faceplate.html to BinaryData
// 7. Build VST3/AU/Standalone targets
//
// For standalone testing without compiling:
// - Open schoffhauzer_synth_faceplate.html in browser
// - Use with Web MIDI or Web Audio Faust compiler
