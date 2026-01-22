import("stdfaust.lib");

// =============================================================================
// EFFECT PARAMETERS
// =============================================================================

// Harmonic Exciter
exciter_freq = hslider("v:[0]FX/h:[0]Exciter/[0]Freq[scale:log][style:knob]", 3000, 500, 12000, 1);
exciter_drive = hslider("v:[0]FX/h:[0]Exciter/[1]Drive[style:knob]", 0.5, 0, 1, 0.01);
exciter_mix = hslider("v:[0]FX/h:[0]Exciter/[2]Mix[style:knob]", 0, 0, 1, 0.01);

// Chorus
chorus_rate = hslider("v:[0]FX/h:[1]Chorus/[0]Rate[style:knob]", 0.8, 0.1, 4, 0.01);
chorus_depth = hslider("v:[0]FX/h:[1]Chorus/[1]Depth[style:knob]", 0.5, 0, 1, 0.01);
chorus_wet = hslider("v:[0]FX/h:[1]Chorus/[2]Wet[style:knob]", 0, 0, 1, 0.01);

// Delay
delay_time = hslider("v:[0]FX/h:[2]Delay/[0]Time[style:knob]", 0.375, 0.01, 1, 0.001);
delay_fdbk = hslider("v:[0]FX/h:[2]Delay/[1]Fdbk[style:knob]", 0.4, 0, 0.85, 0.01);
delay_tone = hslider("v:[0]FX/h:[2]Delay/[2]Tone[style:knob]", 0.6, 0, 1, 0.01);
delay_wet = hslider("v:[0]FX/h:[2]Delay/[3]Wet[style:knob]", 0, 0, 1, 0.01);

// Reverb
reverb_type = nentry("v:[0]FX/h:[3]Reverb/[0]Type[style:menu{'Freeverb':0;'Zita':1;'Dattorro':2;'JPverb':3;'Greyhole':4}]", 0, 0, 4, 1);
reverb_size = hslider("v:[0]FX/h:[3]Reverb/[1]Size[style:knob]", 0.6, 0.1, 0.95, 0.01);
reverb_damp = hslider("v:[0]FX/h:[3]Reverb/[2]Damp[style:knob]", 0.4, 0, 1, 0.01);
reverb_mod = hslider("v:[0]FX/h:[3]Reverb/[3]Mod[style:knob]", 0.3, 0, 1, 0.01);
reverb_wet = hslider("v:[0]FX/h:[3]Reverb/[4]Wet[style:knob]", 0, 0, 1, 0.01);

// Master
master_gain = hslider("v:[1]MASTER/[0]Gain[unit:dB][style:knob]", -12, -60, 0, 0.1) : ba.db2linear;

// =============================================================================
// EFFECTS FUNCTIONS
// =============================================================================

// Harmonic Exciter
exciterFX(l, r) = (outL, outR)
with {
    hpL = l : fi.highpass(2, exciter_freq);
    hpR = r : fi.highpass(2, exciter_freq);
    driveAmount = 1 + exciter_drive * 8;
    saturate(x) = ma.tanh(x * driveAmount) / driveAmount;
    satL = hpL : saturate;
    satR = hpR : saturate;
    outL = l + satL * exciter_mix * 2;
    outR = r + satR * exciter_mix * 2;
};

// Stereo Chorus
chorusFX(l, r) = (outL, outR)
with {
    lfo1 = os.osc(chorus_rate) * 0.5 + 0.5;
    lfo2 = os.osc(chorus_rate * 0.93) * 0.5 + 0.5;
    lfo3 = os.osc(chorus_rate * 1.07) * 0.5 + 0.5;
    baseDelay = 0.007 * ma.SR;
    modDepth = chorus_depth * 0.010 * ma.SR;
    del1 = baseDelay + lfo1 * modDepth;
    del2 = baseDelay + lfo2 * modDepth;
    del3 = baseDelay + lfo3 * modDepth;
    wetL = (l : de.fdelay(2048, del1)) * 0.5 + (l : de.fdelay(2048, del3)) * 0.5;
    wetR = (r : de.fdelay(2048, del2)) * 0.5 + (r : de.fdelay(2048, del1)) * 0.5;
    outL = l * (1 - chorus_wet) + wetL * chorus_wet;
    outR = r * (1 - chorus_wet) + wetR * chorus_wet;
};

// Stereo Delay
delayFX(l, r) = (outL, outR)
with {
    maxDel = 96000;
    delL = int(delay_time * ma.SR);
    delR = int(delay_time * ma.SR * 0.75);
    lpFreq = 500 + delay_tone * 12000;
    wetL = l : +~(de.delay(maxDel, delL) : fi.lowpass(1, lpFreq) : *(delay_fdbk));
    wetR = r : +~(de.delay(maxDel, delR) : fi.lowpass(1, lpFreq) : *(delay_fdbk));
    outL = l * (1 - delay_wet) + wetL * delay_wet;
    outR = r * (1 - delay_wet) + wetR * delay_wet;
};

// Multi-algorithm Reverb
reverbFX(l, r) = (outL, outR)
with {
    mono = (l + r) * 0.5;
    t60 = 0.5 + reverb_size * 5;

    // 0: Freeverb
    freeverbL = l : re.mono_freeverb(reverb_size, reverb_damp, 0.5, 0);
    freeverbR = r : re.mono_freeverb(reverb_size, reverb_damp, 0.5, 23);

    // 1: Zita Rev1
    zitaOut = mono, mono : re.zita_rev1_stereo(60, 200, 4000, t60, t60 * 0.8, 48000);
    zitaL = zitaOut : _, !;
    zitaR = zitaOut : !, _;

    // 2: Dattorro
    decay = 0.3 + reverb_size * 0.65;
    dattorroOut = l, r : re.dattorro_rev(0, 0.7, 0.625, 0.625, decay, 0.7, 0.5, reverb_damp);
    dattorroL = dattorroOut : _, !;
    dattorroR = dattorroOut : !, _;

    // 3: JPverb
    jpSize = 0.5 + reverb_size * 2;
    jpMod = reverb_mod * 0.5;
    jpverbOut = l, r : re.jpverb(t60, reverb_damp, jpSize, 0.707, jpMod, 2, 1, 1, 0.7, 500, 4000);
    jpverbL = jpverbOut : _, !;
    jpverbR = jpverbOut : !, _;

    // 4: Greyhole
    ghSize = 0.5 + reverb_size * 2;
    ghFeedback = 0.3 + reverb_size * 0.5;
    ghMod = reverb_mod * 0.5;
    greyholeOut = l, r : re.greyhole(t60, reverb_damp, ghSize, 0.5, ghFeedback, ghMod, 2);
    greyholeL = greyholeOut : _, !;
    greyholeR = greyholeOut : !, _;

    // Select reverb type
    wetL = ba.selectn(5, int(reverb_type), freeverbL, zitaL, dattorroL, jpverbL, greyholeL);
    wetR = ba.selectn(5, int(reverb_type), freeverbR, zitaR, dattorroR, jpverbR, greyholeR);

    outL = l * (1 - reverb_wet) + wetL * reverb_wet;
    outR = r * (1 - reverb_wet) + wetR * reverb_wet;
};

// Master output with soft clip
masterFX = _, _ : par(i, 2, *(master_gain) : ma.tanh);

// =============================================================================
// PROCESS
// =============================================================================

process = exciterFX : chorusFX : delayFX : reverbFX : masterFX;
