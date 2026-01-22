#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include "PluginProcessor.h"
#include "BinaryData.h"

class PluginEditor : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    explicit PluginEditor(PluginProcessor&);
    ~PluginEditor() override;

    void paint(juce::Graphics&) override {}
    void resized() override;

private:
    void timerCallback() override;

    std::optional<juce::WebBrowserComponent::Resource> getResource(const juce::String& url);

    void handleSetParameter(const juce::Array<juce::var>& args,
                           juce::WebBrowserComponent::NativeFunctionCompletion completion);
    void handleGetParameter(const juce::Array<juce::var>& args,
                           juce::WebBrowserComponent::NativeFunctionCompletion completion);
    void handleGetAllParameters(const juce::Array<juce::var>& args,
                                juce::WebBrowserComponent::NativeFunctionCompletion completion);
    void handleSetScale(const juce::Array<juce::var>& args,
                        juce::WebBrowserComponent::NativeFunctionCompletion completion);

    void syncParametersToUI();
    void sendSpectrumToWebView();
    void sendWaveformToWebView();

    PluginProcessor& processor;
    juce::WebBrowserComponent webView;

    static constexpr int baseWidth = 920;
    static constexpr int baseHeight = 680;
    float currentScale = 1.0f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};
