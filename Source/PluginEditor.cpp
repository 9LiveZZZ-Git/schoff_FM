#include "PluginEditor.h"

PluginEditor::PluginEditor(PluginProcessor& p)
    : AudioProcessorEditor(&p),
      processor(p),
      webView(
          juce::WebBrowserComponent::Options{}
              .withBackend(juce::WebBrowserComponent::Options::Backend::webview2)
              .withNativeFunction("setParameter",
                  [this](const juce::Array<juce::var>& args,
                         juce::WebBrowserComponent::NativeFunctionCompletion completion) {
                      handleSetParameter(args, std::move(completion));
                  })
              .withNativeFunction("getParameter",
                  [this](const juce::Array<juce::var>& args,
                         juce::WebBrowserComponent::NativeFunctionCompletion completion) {
                      handleGetParameter(args, std::move(completion));
                  })
              .withNativeFunction("getAllParameters",
                  [this](const juce::Array<juce::var>& args,
                         juce::WebBrowserComponent::NativeFunctionCompletion completion) {
                      handleGetAllParameters(args, std::move(completion));
                  })
      )
{
    setSize(920, 680);
    addAndMakeVisible(webView);

    // Load faceplate.html from the same folder as the executable
    auto exeFile = juce::File::getSpecialLocation(juce::File::currentExecutableFile);
    auto faceplateFile = exeFile.getParentDirectory().getChildFile("faceplate.html");

    if (faceplateFile.existsAsFile())
    {
        webView.goToURL(juce::URL(faceplateFile).toString(true));
    }
    else
    {
        // Fallback: try current working directory
        auto cwdFaceplate = juce::File::getCurrentWorkingDirectory().getChildFile("faceplate.html");
        if (cwdFaceplate.existsAsFile())
            webView.goToURL(juce::URL(cwdFaceplate).toString(true));
    }

    startTimerHz(30);
}

PluginEditor::~PluginEditor()
{
    stopTimer();
}

void PluginEditor::resized()
{
    webView.setBounds(getLocalBounds());
}

void PluginEditor::timerCallback()
{
    syncParametersToUI();

    // Send FFT spectrum data
    if (processor.spectrumAnalyzer.isFFTReady())
    {
        sendSpectrumToWebView();
    }

    // Send waveform data for oscilloscope
    if (processor.isWaveformReady())
    {
        sendWaveformToWebView();
    }

    // Send level meter data
    float levelL = processor.getOutputLevelL();
    float levelR = processor.getOutputLevelR();
    juce::String meterJs = "if(window.updateMeterLevels){window.updateMeterLevels("
        + juce::String(levelL, 3) + "," + juce::String(levelR, 3) + ");}";
    webView.evaluateJavascript(meterJs, nullptr);

    // Send MIDI activity
    if (processor.getMidiActivity())
    {
        webView.evaluateJavascript("if(window.midiActivity){window.midiActivity();}", nullptr);
    }

    // Send voice count
    int voices = processor.getActiveVoiceCount();
    juce::String voiceJs = "if(window.updateVoiceCount){window.updateVoiceCount("
        + juce::String(voices) + "," + juce::String(PluginProcessor::maxVoices) + ");}";
    webView.evaluateJavascript(voiceJs, nullptr);
}

std::optional<juce::WebBrowserComponent::Resource> PluginEditor::getResource(const juce::String& url)
{
    // Extract path from URL
    juce::String path = url;

    // Remove the origin prefix if present
    if (path.startsWith("https://plugin.local"))
        path = path.substring(20);

    // Remove leading slash
    if (path.startsWith("/"))
        path = path.substring(1);

    // Serve faceplate.html for root or explicit request
    if (path.isEmpty() || path == "faceplate.html" || path.containsIgnoreCase("faceplate"))
    {
        std::vector<std::byte> data(BinaryData::faceplate_htmlSize);
        std::memcpy(data.data(), BinaryData::faceplate_html, BinaryData::faceplate_htmlSize);

        return juce::WebBrowserComponent::Resource{
            std::move(data),
            juce::String{"text/html; charset=utf-8"}
        };
    }

    return std::nullopt;
}

void PluginEditor::handleSetParameter(const juce::Array<juce::var>& args,
                                       juce::WebBrowserComponent::NativeFunctionCompletion completion)
{
    if (args.size() >= 2)
    {
        auto id = args[0].toString();
        auto value = static_cast<float>(args[1]);

        if (auto* param = processor.getAPVTS().getParameter(id))
        {
            auto range = processor.getAPVTS().getParameterRange(id);
            float normalized = range.convertTo0to1(value);
            param->setValueNotifyingHost(normalized);
            completion(juce::var(true));
            return;
        }
    }
    completion(juce::var(false));
}

void PluginEditor::handleGetParameter(const juce::Array<juce::var>& args,
                                       juce::WebBrowserComponent::NativeFunctionCompletion completion)
{
    if (args.size() >= 1)
    {
        auto id = args[0].toString();
        if (auto* param = processor.getAPVTS().getParameter(id))
        {
            auto range = processor.getAPVTS().getParameterRange(id);
            float value = range.convertFrom0to1(param->getValue());
            completion(juce::var(value));
            return;
        }
    }
    completion(juce::var());
}

void PluginEditor::handleGetAllParameters(const juce::Array<juce::var>& args,
                                           juce::WebBrowserComponent::NativeFunctionCompletion completion)
{
    juce::ignoreUnused(args);
    juce::DynamicObject::Ptr obj = new juce::DynamicObject();

    for (auto* param : processor.getParameters())
    {
        if (auto* p = dynamic_cast<juce::AudioProcessorParameterWithID*>(param))
        {
            auto range = processor.getAPVTS().getParameterRange(p->getParameterID());
            float value = range.convertFrom0to1(param->getValue());
            obj->setProperty(p->getParameterID(), value);
        }
    }

    completion(juce::var(obj.get()));
}

void PluginEditor::syncParametersToUI()
{
    juce::String js = "if(window.updateParameter){";

    for (auto* param : processor.getParameters())
    {
        if (auto* p = dynamic_cast<juce::AudioProcessorParameterWithID*>(param))
        {
            auto range = processor.getAPVTS().getParameterRange(p->getParameterID());
            float value = range.convertFrom0to1(param->getValue());
            js += "window.updateParameter('" + p->getParameterID() + "'," + juce::String(value) + ");";
        }
    }

    js += "}";
    webView.evaluateJavascript(js, nullptr);
}

void PluginEditor::sendSpectrumToWebView()
{
    const auto& spectrum = processor.spectrumAnalyzer.getSpectrum();
    float sampleRate = (float)processor.getSampleRate();
    if (sampleRate <= 0) sampleRate = 44100.0f;

    int numBins = processor.spectrumAnalyzer.getNumBins();

    juce::String js = "if(window.updateScopeData){window.updateScopeData([";

    const int displayBins = 256;
    const float minFreq = 20.0f;
    const float maxFreq = 20000.0f;

    for (int i = 0; i < displayBins; ++i)
    {
        float t = (float)i / (displayBins - 1);
        float freq = minFreq * std::pow(maxFreq / minFreq, t);

        int bin = (int)(freq * (float)SpectrumAnalyzer::fftSize / sampleRate);
        bin = juce::jlimit(0, numBins - 1, bin);

        float value = spectrum[bin];

        js += juce::String(value, 3);
        if (i < displayBins - 1)
            js += ",";
    }

    js += "]);}";
    webView.evaluateJavascript(js, nullptr);
}

void PluginEditor::sendWaveformToWebView()
{
    std::array<float, PluginProcessor::waveformBufferSize> waveform;
    processor.getWaveformData(waveform);

    juce::String js = "if(window.updateWaveformData){window.updateWaveformData([";

    for (int i = 0; i < PluginProcessor::waveformBufferSize; ++i)
    {
        // Scale to -1 to 1 range for display
        js += juce::String(waveform[i], 3);
        if (i < PluginProcessor::waveformBufferSize - 1)
            js += ",";
    }

    js += "]);}";
    webView.evaluateJavascript(js, nullptr);
}
