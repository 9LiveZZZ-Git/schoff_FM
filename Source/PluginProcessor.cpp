#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor()
    : AudioProcessor(BusesProperties()
          .withInput("Input", juce::AudioChannelSet::stereo(), true)
          .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      apvts(*this, nullptr, "Parameters", createParameterLayout())
{
}

PluginProcessor::~PluginProcessor() {}

juce::AudioProcessorValueTreeState::ParameterLayout PluginProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;

    // =========================================================================
    // OSCILLATOR 1
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterChoice>(
        "osc1_wave", "OSC1 Wave",
        juce::StringArray{ "Saw", "Saw+", "Tri", "Tri+", "Sqr", "Pulse", "Sine" }, 0));

    params.push_back(std::make_unique<juce::AudioParameterInt>(
        "osc1_octave", "OSC1 Octave", -3, 3, 0));

    params.push_back(std::make_unique<juce::AudioParameterInt>(
        "osc1_semi", "OSC1 Semi", -12, 12, 0));

    params.push_back(std::make_unique<juce::AudioParameterInt>(
        "osc1_fine", "OSC1 Fine", -100, 100, 0));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "osc1_pw", "OSC1 PW",
        juce::NormalisableRange<float>(0.05f, 0.95f, 0.01f), 0.5f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "osc1_gain", "OSC1 Level",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.7f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "osc1_pan", "OSC1 Pan",
        juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f), 0.0f));

    // =========================================================================
    // OSCILLATOR 2
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterChoice>(
        "osc2_wave", "OSC2 Wave",
        juce::StringArray{ "Saw", "Saw+", "Tri", "Tri+", "Sqr", "Pulse", "Sine" }, 0));

    params.push_back(std::make_unique<juce::AudioParameterInt>(
        "osc2_octave", "OSC2 Octave", -3, 3, 0));

    params.push_back(std::make_unique<juce::AudioParameterInt>(
        "osc2_semi", "OSC2 Semi", -12, 12, 0));

    params.push_back(std::make_unique<juce::AudioParameterInt>(
        "osc2_fine", "OSC2 Fine", -100, 100, 0));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "osc2_pw", "OSC2 PW",
        juce::NormalisableRange<float>(0.05f, 0.95f, 0.01f), 0.5f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "osc2_gain", "OSC2 Level",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.7f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "osc2_pan", "OSC2 Pan",
        juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f), 0.0f));

    // =========================================================================
    // SUB OSCILLATOR
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterChoice>(
        "sub_wave", "Sub Wave",
        juce::StringArray{ "Sine", "Square", "Saw", "Tri" }, 0));

    params.push_back(std::make_unique<juce::AudioParameterChoice>(
        "sub_octave", "Sub Octave",
        juce::StringArray{ "-2", "-1" }, 1));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "sub_level", "Sub Level",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

    // =========================================================================
    // NOISE
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterChoice>(
        "noise_type", "Noise Type",
        juce::StringArray{ "White", "Pink", "Brown" }, 0));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "noise_level", "Noise Level",
        juce::NormalisableRange<float>(0.0f, 0.5f, 0.01f), 0.0f));

    // =========================================================================
    // FILTER
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "filter_cutoff", "Filter Cutoff",
        juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.3f), 8000.0f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "filter_reso", "Filter Resonance",
        juce::NormalisableRange<float>(0.5f, 10.0f, 0.1f), 1.0f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "filter_env", "Filter Env Amount",
        juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f), 0.3f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "filter_key", "Filter Key Track",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "filter_drive", "Filter Drive",
        juce::NormalisableRange<float>(1.0f, 4.0f, 0.1f), 1.0f));

    // =========================================================================
    // AMP ENVELOPE
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "amp_a", "Amp Attack",
        juce::NormalisableRange<float>(0.001f, 4.0f, 0.001f, 0.3f), 0.01f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "amp_d", "Amp Decay",
        juce::NormalisableRange<float>(0.001f, 4.0f, 0.001f, 0.3f), 0.2f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "amp_s", "Amp Sustain",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.7f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "amp_r", "Amp Release",
        juce::NormalisableRange<float>(0.001f, 8.0f, 0.001f, 0.3f), 0.3f));

    // =========================================================================
    // FILTER ENVELOPE
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "flt_a", "Filter Attack",
        juce::NormalisableRange<float>(0.001f, 4.0f, 0.001f, 0.3f), 0.01f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "flt_d", "Filter Decay",
        juce::NormalisableRange<float>(0.001f, 4.0f, 0.001f, 0.3f), 0.3f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "flt_s", "Filter Sustain",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.3f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "flt_r", "Filter Release",
        juce::NormalisableRange<float>(0.001f, 8.0f, 0.001f, 0.3f), 0.5f));

    // =========================================================================
    // EXCITER
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "exciter_freq", "Exciter Freq",
        juce::NormalisableRange<float>(500.0f, 12000.0f, 1.0f, 0.3f), 3000.0f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "exciter_drive", "Exciter Drive",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.5f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "exciter_mix", "Exciter Mix",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

    // =========================================================================
    // CHORUS
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "chorus_rate", "Chorus Rate",
        juce::NormalisableRange<float>(0.1f, 4.0f, 0.01f), 0.8f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "chorus_depth", "Chorus Depth",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.5f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "chorus_wet", "Chorus Wet",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

    // =========================================================================
    // DELAY
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "delay_time", "Delay Time",
        juce::NormalisableRange<float>(0.01f, 1.0f, 0.001f), 0.375f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "delay_fdbk", "Delay Feedback",
        juce::NormalisableRange<float>(0.0f, 0.85f, 0.01f), 0.4f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "delay_wet", "Delay Wet",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

    // =========================================================================
    // REVERB
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterChoice>(
        "reverb_type", "Reverb Type",
        juce::StringArray{ "Freeverb", "Zita", "Dattorro", "JPverb", "Greyhole" }, 0));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "reverb_size", "Reverb Size",
        juce::NormalisableRange<float>(0.1f, 0.95f, 0.01f), 0.6f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "reverb_wet", "Reverb Wet",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

    // =========================================================================
    // MASTER
    // =========================================================================
    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "master_width", "Master Width",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 1.0f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        "master_gain", "Master Gain",
        juce::NormalisableRange<float>(-60.0f, 0.0f, 0.1f), -12.0f));

    // Oversampling: 0=Off, 1=x4, 2=x8
    params.push_back(std::make_unique<juce::AudioParameterChoice>(
        "oversampling", "Oversampling",
        juce::StringArray{ "Off", "x4", "x8" }, 0));

    return { params.begin(), params.end() };
}

void PluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    currentSampleRate = sampleRate;

    // Initialize Hilbert stereo widener
    hilbertStereoWidth.prepare(sampleRate, samplesPerBlock);

    // Initialize high-quality effects
    lushChorus.prepare(sampleRate, samplesPerBlock);
    stereoDelay.prepare(sampleRate, samplesPerBlock);

    // Initialize oversampling (create with max factor of 8x = 3 stages)
    oversampling = std::make_unique<juce::dsp::Oversampling<float>>(
        2, // numChannels
        3, // maxOversamplingFactor (2^3 = 8x)
        juce::dsp::Oversampling<float>::filterHalfBandPolyphaseIIR,
        true // isMaxQuality
    );
    oversampling->initProcessing(static_cast<size_t>(samplesPerBlock));

    // Initialize your Faust DSP here if needed
}

void PluginProcessor::releaseResources()
{
    if (oversampling)
        oversampling->reset();
}

void PluginProcessor::updateOversampling(int factor)
{
    if (factor != currentOversamplingFactor && oversampling)
    {
        currentOversamplingFactor = factor;
        // Reinitialize effects at the oversampled rate
        double osRate = currentSampleRate * static_cast<double>(factor);
        lushChorus.prepare(osRate, 512);
        stereoDelay.prepare(osRate, 512);
        hilbertStereoWidth.prepare(osRate, 512);
    }
}

void PluginProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    // Check for MIDI activity
    if (!midiMessages.isEmpty())
    {
        for (const auto metadata : midiMessages)
        {
            if (metadata.getMessage().isNoteOn())
            {
                midiActivity.store(true);
                break;
            }
        }
    }

    for (auto i = getTotalNumInputChannels(); i < getTotalNumOutputChannels(); ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // Get parameters
    float chorusRate = apvts.getRawParameterValue("chorus_rate")->load();
    float chorusDepth = apvts.getRawParameterValue("chorus_depth")->load();
    float chorusWet = apvts.getRawParameterValue("chorus_wet")->load();

    float delayTime = apvts.getRawParameterValue("delay_time")->load();
    float delayFeedback = apvts.getRawParameterValue("delay_fdbk")->load();
    float delayWet = apvts.getRawParameterValue("delay_wet")->load();

    float widthParam = apvts.getRawParameterValue("master_width")->load();
    float widthAmount = widthParam * 2.0f; // Map 0-1 to 0-2

    int oversamplingChoice = static_cast<int>(apvts.getRawParameterValue("oversampling")->load());

    // Determine oversampling factor: 0=Off(1x), 1=x4, 2=x8
    int osFactor = 1;
    if (oversamplingChoice == 1) osFactor = 4;
    else if (oversamplingChoice == 2) osFactor = 8;

    // Update oversampling if changed
    if (osFactor != currentOversamplingFactor)
        updateOversampling(osFactor);

    // Process with or without oversampling
    if (osFactor > 1 && oversampling)
    {
        // Create a dsp::AudioBlock from the buffer
        juce::dsp::AudioBlock<float> block(buffer);

        // Upsample
        auto osBlock = (osFactor == 4)
            ? oversampling->processSamplesUp(block)
            : oversampling->processSamplesUp(block);

        // Create temporary buffer for oversampled processing
        juce::AudioBuffer<float> osBuffer(static_cast<int>(osBlock.getNumChannels()),
                                          static_cast<int>(osBlock.getNumSamples()));
        for (int ch = 0; ch < static_cast<int>(osBlock.getNumChannels()); ++ch)
            osBuffer.copyFrom(ch, 0, osBlock.getChannelPointer(static_cast<size_t>(ch)),
                             static_cast<int>(osBlock.getNumSamples()));

        // TODO: Process your Faust DSP here (in the oversampled domain)

        // Apply effects in oversampled domain
        lushChorus.process(osBuffer, chorusRate, chorusDepth, chorusWet);
        stereoDelay.process(osBuffer, delayTime, delayFeedback, delayWet);
        hilbertStereoWidth.process(osBuffer, widthAmount);

        // Copy back to osBlock
        for (int ch = 0; ch < static_cast<int>(osBlock.getNumChannels()); ++ch)
            juce::FloatVectorOperations::copy(osBlock.getChannelPointer(static_cast<size_t>(ch)),
                                              osBuffer.getReadPointer(ch),
                                              static_cast<int>(osBlock.getNumSamples()));

        // Downsample
        oversampling->processSamplesDown(block);
    }
    else
    {
        // TODO: Process your Faust DSP here

        // Apply effects at native sample rate
        lushChorus.process(buffer, chorusRate, chorusDepth, chorusWet);
        stereoDelay.process(buffer, delayTime, delayFeedback, delayWet);
        hilbertStereoWidth.process(buffer, widthAmount);
    }

    // Calculate downsample factor based on sample rate (target ~60 updates per second)
    waveformDownsampleFactor = juce::jmax(1, static_cast<int>(currentSampleRate / (waveformBufferSize * 60)));

    // Feed samples to spectrum analyzer and waveform buffer (after all processing)
    for (int i = 0; i < buffer.getNumSamples(); ++i)
    {
        float sample = 0.0f;
        for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
            sample += buffer.getSample(ch, i);
        sample /= static_cast<float>(juce::jmax(1, buffer.getNumChannels()));

        // Feed to FFT analyzer
        spectrumAnalyzer.pushSample(sample);

        // Fill waveform buffer (downsampled for display)
        waveformSampleCounter++;
        if (waveformSampleCounter >= waveformDownsampleFactor)
        {
            waveformSampleCounter = 0;
            int pos = waveformWritePos.load();
            waveformBuffer[pos] = sample;
            pos = (pos + 1) % waveformBufferSize;
            waveformWritePos.store(pos);

            // Mark as ready when buffer is filled
            if (pos == 0)
                waveformReady.store(true);
        }
    }

    // Calculate output levels for metering
    float peakL = 0.0f, peakR = 0.0f;
    if (buffer.getNumChannels() >= 2)
    {
        auto* leftData = buffer.getReadPointer(0);
        auto* rightData = buffer.getReadPointer(1);
        for (int i = 0; i < buffer.getNumSamples(); ++i)
        {
            peakL = juce::jmax(peakL, std::abs(leftData[i]));
            peakR = juce::jmax(peakR, std::abs(rightData[i]));
        }
    }
    else if (buffer.getNumChannels() >= 1)
    {
        auto* data = buffer.getReadPointer(0);
        for (int i = 0; i < buffer.getNumSamples(); ++i)
        {
            peakL = juce::jmax(peakL, std::abs(data[i]));
        }
        peakR = peakL;
    }
    outputLevelL.store(peakL);
    outputLevelR.store(peakR);
}

juce::AudioProcessorEditor* PluginProcessor::createEditor()
{
    return new PluginEditor(*this);
}

void PluginProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    auto state = apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
    if (xml && xml->hasTagName(apvts.state.getType()))
        apvts.replaceState(juce::ValueTree::fromXml(*xml));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
