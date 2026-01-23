import("stdfaust.lib");

declare options "[midi:on][nvoices:8]";

// =============================================================================
// MIDI
// =============================================================================
freq = hslider("v:[0]OSCILLATORS/[0]freq[style:knob][scale:log]", 440, 20, 20000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");

// =============================================================================
// SCHOFFHAUZER OSCILLATORS
// =============================================================================

schoffSaw(f) = output : fi.dcblocker
with {
    beta = max(1.0 - 9.0 * f / ma.SR, 0.0);
    phasor = os.phasor(1, f);
    onepole = *(0.5) : +~*(0.5);
    output = (phasor * 2.0 * ma.PI + _ * beta : sin) ~ onepole;
};

enhancedSaw(f) = output : fi.dcblocker
with {
    beta = max(1.0 - 9.0 * f / ma.SR, 0.0);
    phasor = os.phasor(1, f);
    avgFB = _ <: _, mem : + : *(0.5);
    output = (phasor * 2.0 * ma.PI + _ * beta : sin) ~ avgFB;
};

schoffTri(f) = output : fi.dcblocker
with {
    fn = f / ma.SR;
    c2 = max(0.5 - 12.0 * fn, 0.0);
    c1 = (0.75 - c2) * min(max(1.44 - 11.5 * fn, 0.0), 1.0);
    phasor = os.phasor(1, f);
    polyFB(x) = c1 * x * x + c2 * x * x * x * x;
    output = (phasor * 2.0 * ma.PI + _ : sin) ~ polyFB;
};

enhancedTri(f) = output : fi.dcblocker
with {
    fn = f / ma.SR;
    c2 = max(0.5 - 12.0 * fn, 0.0);
    c1 = (0.75 - c2) * min(max(1.44 - 11.5 * fn, 0.0), 1.0);
    phasor = os.phasor(1, f);
    polyFB(x) = c1 * x * x + c2 * x * x * x * x;
    onepole = *(0.5) : +~*(0.5);
    output = (phasor * 2.0 * ma.PI + _ : sin) ~ (polyFB : onepole);
};

schoffSquare(f) = schoffSaw(f) : max(-1) : min(1) : *(1.2) : max(-1) : min(1);

schoffPulse(f, pw) = (saw1 - saw2) * 0.5 : fi.dcblocker
with {
    beta = max(1.0 - 9.0 * f / ma.SR, 0.0);
    onepole = *(0.5) : +~*(0.5);
    phasor1 = os.phasor(1, f);
    phasor2 = ma.frac(phasor1 + pw);
    saw1 = (phasor1 * 2.0 * ma.PI + _ * beta : sin) ~ onepole;
    saw2 = (phasor2 * 2.0 * ma.PI + _ * beta : sin) ~ onepole;
};

pureSine(f) = os.osc(f);

selectWave(wt, f, pw) = ba.selectn(7, int(wt),
    schoffSaw(f),
    enhancedSaw(f),
    schoffTri(f),
    enhancedTri(f),
    schoffSquare(f),
    schoffPulse(f, pw),
    pureSine(f)
);

// =============================================================================
// HILBERT TRANSFORM
// =============================================================================

allpass1(c) = fi.tf1(c, 1, c);

hilbertStereo(pan, phase, x) = left, right
with {
    p = (pan + 1) * 0.5;
    panL = cos(p * ma.PI * 0.5);
    panR = sin(p * ma.PI * 0.5);
    
    c1 = 0.6923878;
    c2 = 0.9360654322959;
    c3 = 0.9882295226860;
    c4 = 0.9987488452737;
    
    a1 = 0.4021921162426;
    a2 = 0.8561710882420;
    a3 = 0.9722909545651;
    a4 = 0.9952884791278;
    
    shifted = x : allpass1(c1) : allpass1(c2) : allpass1(c3) : allpass1(c4);
    delayed = x : allpass1(a1) : allpass1(a2) : allpass1(a3) : allpass1(a4);
    
    phaseBlend = phase / 90.0;
    spreadL = delayed;
    spreadR = delayed * (1 - phaseBlend) + shifted * phaseBlend;
    
    left = spreadL * panL;
    right = spreadR * panR;
};

// =============================================================================
// CRISP PROCESSOR (for sub osc)
// =============================================================================

crispProcess(x) = out
with {
    noiseSignal = no.noise : fi.highpass(2, crisp_hpf) : fi.lowpass(2, crisp_lpf);
    env = abs(x) : fi.lowpass(1, 50);
    driveGain = 1 + crisp_drive * 4;
    crispSignal = x * noiseSignal * env * driveGain;
    out = x + crispSignal * crisp_amt * 2;
};

// =============================================================================
// PARAMETERS - OSCILLATORS
// =============================================================================

// OSC 1
osc1_wave = nentry("v:[0]OSCILLATORS/h:[1]OSC1/[0]Wave[style:menu{'Saw':0;'Saw+':1;'Tri':2;'Tri+':3;'Square':4;'Pulse':5;'Sine':6}]", 0, 0, 6, 1);
osc1_octave = nentry("v:[0]OSCILLATORS/h:[1]OSC1/[1]Oct[style:knob]", 0, -3, 3, 1);
osc1_semi = nentry("v:[0]OSCILLATORS/h:[1]OSC1/[2]Semi[style:knob]", 0, -12, 12, 1);
osc1_fine = hslider("v:[0]OSCILLATORS/h:[1]OSC1/[3]Fine[style:knob]", 0, -100, 100, 1);
osc1_pw = hslider("v:[0]OSCILLATORS/h:[1]OSC1/[4]PW[style:knob]", 0.5, 0.05, 0.95, 0.01);
osc1_gain = hslider("v:[0]OSCILLATORS/h:[1]OSC1/[5]Level[style:knob]", 0.7, 0, 1, 0.01);
osc1_pan = hslider("v:[0]OSCILLATORS/h:[1]OSC1/[6]Pan[style:knob]", 0, -1, 1, 0.01);
osc1_stereo = hslider("v:[0]OSCILLATORS/h:[1]OSC1/[7]Stereo[style:knob]", 0, 0, 90, 1);

// OSC 2
osc2_wave = nentry("v:[0]OSCILLATORS/h:[2]OSC2/[0]Wave[style:menu{'Saw':0;'Saw+':1;'Tri':2;'Tri+':3;'Square':4;'Pulse':5;'Sine':6}]", 0, 0, 6, 1);
osc2_octave = nentry("v:[0]OSCILLATORS/h:[2]OSC2/[1]Oct[style:knob]", 0, -3, 3, 1);
osc2_semi = nentry("v:[0]OSCILLATORS/h:[2]OSC2/[2]Semi[style:knob]", 0, -12, 12, 1);
osc2_fine = hslider("v:[0]OSCILLATORS/h:[2]OSC2/[3]Fine[style:knob]", 0, -100, 100, 1);
osc2_pw = hslider("v:[0]OSCILLATORS/h:[2]OSC2/[4]PW[style:knob]", 0.5, 0.05, 0.95, 0.01);
osc2_gain = hslider("v:[0]OSCILLATORS/h:[2]OSC2/[5]Level[style:knob]", 0.7, 0, 1, 0.01);
osc2_pan = hslider("v:[0]OSCILLATORS/h:[2]OSC2/[6]Pan[style:knob]", 0, -1, 1, 0.01);
osc2_stereo = hslider("v:[0]OSCILLATORS/h:[2]OSC2/[7]Stereo[style:knob]", 0, 0, 90, 1);

// SUB + CRISP
sub_wave = nentry("v:[0]OSCILLATORS/h:[3]SUB/[0]Wave[style:menu{'Sine':0;'Square':1;'Saw':2;'Tri':3}]", 0, 0, 3, 1);
sub_octave = nentry("v:[0]OSCILLATORS/h:[3]SUB/[1]Oct[style:menu{'-2':0;'-1':1}]", 1, 0, 1, 1);
sub_level = hslider("v:[0]OSCILLATORS/h:[3]SUB/[2]Level[style:knob]", 0, 0, 1, 0.01);
crisp_amt = hslider("v:[0]OSCILLATORS/h:[3]SUB/[3]Crisp[style:knob]", 0, 0, 1, 0.01);
crisp_hpf = hslider("v:[0]OSCILLATORS/h:[3]SUB/[4]CrspHPF[scale:log][style:knob]", 2000, 500, 16000, 1);
crisp_lpf = hslider("v:[0]OSCILLATORS/h:[3]SUB/[5]CrspLPF[scale:log][style:knob]", 12000, 2000, 20000, 1);
crisp_drive = hslider("v:[0]OSCILLATORS/h:[3]SUB/[6]CrspDrv[style:knob]", 0.5, 0, 1, 0.01);

// NOISE
noise_type = nentry("v:[0]OSCILLATORS/h:[4]NOISE/[0]Type[style:menu{'White':0;'Pink':1;'Brown':2}]", 0, 0, 2, 1);
noise_level = hslider("v:[0]OSCILLATORS/h:[4]NOISE/[1]Level[style:knob]", 0, 0, 0.5, 0.01);

// =============================================================================
// PARAMETERS - FILTER
// =============================================================================

filter_cutoff = hslider("v:[1]FILTER/[0]Cutoff[scale:log][style:knob]", 8000, 20, 20000, 1) : si.smoo;
filter_reso = hslider("v:[1]FILTER/[1]Reso[style:knob]", 1, 0.5, 10, 0.1) : si.smoo;
filter_env = hslider("v:[1]FILTER/[2]EnvAmt[style:knob]", 0.3, -1, 1, 0.01) : si.smoo;
filter_key = hslider("v:[1]FILTER/[3]KeyTrk[style:knob]", 0, 0, 1, 0.01) : si.smoo;
filter_amt = hslider("v:[1]FILTER/[4]Amount[style:knob]", 1, 0, 1, 0.01) : si.smoo;

// =============================================================================
// PARAMETERS - ENVELOPES
// =============================================================================

amp_a = hslider("v:[2]ENVELOPES/h:[0]AMP/[0]A[style:knob]", 0.01, 0.001, 4, 0.001);
amp_d = hslider("v:[2]ENVELOPES/h:[0]AMP/[1]D[style:knob]", 0.2, 0.001, 4, 0.001);
amp_s = hslider("v:[2]ENVELOPES/h:[0]AMP/[2]S[style:knob]", 0.7, 0, 1, 0.01);
amp_r = hslider("v:[2]ENVELOPES/h:[0]AMP/[3]R[style:knob]", 0.3, 0.001, 8, 0.001);

flt_a = hslider("v:[2]ENVELOPES/h:[1]FILTER/[0]A[style:knob]", 0.01, 0.001, 4, 0.001);
flt_d = hslider("v:[2]ENVELOPES/h:[1]FILTER/[1]D[style:knob]", 0.3, 0.001, 4, 0.001);
flt_s = hslider("v:[2]ENVELOPES/h:[1]FILTER/[2]S[style:knob]", 0.3, 0, 1, 0.01);
flt_r = hslider("v:[2]ENVELOPES/h:[1]FILTER/[3]R[style:knob]", 0.5, 0.001, 8, 0.001);

// =============================================================================
// PARAMETERS - MASTER
// =============================================================================

master_width = hslider("v:[3]MASTER/[0]Width[style:knob]", 1, 0, 1, 0.01);
master_gain = hslider("v:[3]MASTER/[1]Gain[unit:dB][style:knob]", -12, -60, 0, 0.1) : ba.db2linear;

// =============================================================================
// PARAMETERS - EFFECTS
// =============================================================================

// Harmonic Exciter
exciter_freq = hslider("v:[4]FX/h:[0]Exciter/[0]Freq[scale:log][style:knob]", 3000, 500, 12000, 1);
exciter_drive = hslider("v:[4]FX/h:[0]Exciter/[1]Drive[style:knob]", 0.5, 0, 1, 0.01);
exciter_mix = hslider("v:[4]FX/h:[0]Exciter/[2]Mix[style:knob]", 0, 0, 1, 0.01);

// Chorus
chorus_rate = hslider("v:[4]FX/h:[1]Chorus/[0]Rate[style:knob]", 0.8, 0.1, 4, 0.01);
chorus_depth = hslider("v:[4]FX/h:[1]Chorus/[1]Depth[style:knob]", 0.5, 0, 1, 0.01);
chorus_wet = hslider("v:[4]FX/h:[1]Chorus/[2]Wet[style:knob]", 0, 0, 1, 0.01);

// Delay
delay_time = hslider("v:[4]FX/h:[2]Delay/[0]Time[style:knob]", 0.375, 0.01, 1, 0.001);
delay_fdbk = hslider("v:[4]FX/h:[2]Delay/[1]Fdbk[style:knob]", 0.4, 0, 0.85, 0.01);
delay_tone = hslider("v:[4]FX/h:[2]Delay/[2]Tone[style:knob]", 0.6, 0, 1, 0.01);
delay_wet = hslider("v:[4]FX/h:[2]Delay/[3]Wet[style:knob]", 0, 0, 1, 0.01);

// Reverb (multiple algorithms)
reverb_type = nentry("v:[4]FX/h:[3]Reverb/[0]Type[style:menu{'Freeverb':0;'Zita':1;'Dattorro':2;'JPverb':3;'Greyhole':4}]", 0, 0, 4, 1);
reverb_size = hslider("v:[4]FX/h:[3]Reverb/[1]Size[style:knob]", 0.6, 0.1, 0.95, 0.01);
reverb_damp = hslider("v:[4]FX/h:[3]Reverb/[2]Damp[style:knob]", 0.4, 0, 1, 0.01);
reverb_mod = hslider("v:[4]FX/h:[3]Reverb/[3]Mod[style:knob]", 0.3, 0, 1, 0.01);
reverb_wet = hslider("v:[4]FX/h:[3]Reverb/[4]Wet[style:knob]", 0, 0, 1, 0.01);

// =============================================================================
// ENVELOPES
// =============================================================================

ampEnv = en.adsr(amp_a, amp_d, amp_s, amp_r, gate);
fltEnv = en.adsr(flt_a, flt_d, flt_s, flt_r, gate);

// =============================================================================
// VOICE
// =============================================================================

// Oscillator frequencies
osc1_freq = freq * (2 ^ (osc1_octave + osc1_semi/12.0 + osc1_fine/1200.0));
osc2_freq = freq * (2 ^ (osc2_octave + osc2_semi/12.0 + osc2_fine/1200.0));

// Generate oscillators
osc1_mono = selectWave(osc1_wave, osc1_freq, osc1_pw) * osc1_gain;
osc2_mono = selectWave(osc2_wave, osc2_freq, osc2_pw) * osc2_gain;

// Hilbert stereo
osc1_out = hilbertStereo(osc1_pan, osc1_stereo, osc1_mono);
osc2_out = hilbertStereo(osc2_pan, osc2_stereo, osc2_mono);

osc1_L = osc1_out : _, !;
osc1_R = osc1_out : !, _;
osc2_L = osc2_out : _, !;
osc2_R = osc2_out : !, _;

// Sub oscillator with Crisp (mono, centered)
subFreq = freq / select2(int(sub_octave), 4, 2);
subRaw = ba.selectn(4, int(sub_wave),
    os.osc(subFreq),
    os.square(subFreq),
    os.sawtooth(subFreq),
    os.triangle(subFreq)
);
subSignal = subRaw : crispProcess : *(sub_level);

// Noise
noiseSignal = ba.selectn(3, int(noise_type),
    no.noise,
    no.pink_noise,
    no.noise : fi.lowpass(1, 200)
) * noise_level;

// Mix all sources
mix_L = osc1_L + osc2_L + subSignal + noiseSignal;
mix_R = osc1_R + osc2_R + subSignal + noiseSignal;

// Filter frequency with envelope and key tracking
filterFreq = filter_cutoff * (2 ^ (fltEnv * filter_env * 4 + filter_key * (freq - 440) / 440 * 2));
filterFreqClamped = max(20, min(18000, filterFreq));

// Classic resonant lowpass filter with amount control
filteredRaw_L = mix_L : fi.resonlp(filterFreqClamped, filter_reso, 1);
filteredRaw_R = mix_R : fi.resonlp(filterFreqClamped, filter_reso, 1);
filtered_L = mix_L * (1 - filter_amt) + filteredRaw_L * filter_amt;
filtered_R = mix_R * (1 - filter_amt) + filteredRaw_R * filter_amt;

// Master width (M/S)
mid = (filtered_L + filtered_R) * 0.5;
side = (filtered_L - filtered_R) * 0.5;
wide_L = mid + side * master_width;
wide_R = mid - side * master_width;

// Apply envelope and gain
voice_L = wide_L * ampEnv * gain;
voice_R = wide_R * ampEnv * gain;

// =============================================================================
// EFFECTS FUNCTIONS
// =============================================================================

// Harmonic Exciter (Aphex-style: highpass -> saturation -> blend)
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
    
    // 0: Freeverb (classic Schroeder)
    freeverbL = l : re.mono_freeverb(reverb_size, reverb_damp, 0.5, 0);
    freeverbR = r : re.mono_freeverb(reverb_size, reverb_damp, 0.5, 23);
    
    // 1: Zita Rev1 (studio quality FDN)
    zitaOut = mono, mono : re.zita_rev1_stereo(60, 200, 4000, t60, t60 * 0.8, 48000);
    zitaL = zitaOut : _, !;
    zitaR = zitaOut : !, _;
    
    // 2: Dattorro (plate style)
    decay = 0.3 + reverb_size * 0.65;
    dattorroOut = l, r : re.dattorro_rev(0, 0.7, 0.625, 0.625, decay, 0.7, 0.5, reverb_damp);
    dattorroL = dattorroOut : _, !;
    dattorroR = dattorroOut : !, _;
    
    // 3: JPverb (lush algorithmic, Lexicon-style)
    jpSize = 0.5 + reverb_size * 2;
    jpMod = reverb_mod * 0.5;
    jpverbOut = l, r : re.jpverb(t60, reverb_damp, jpSize, 0.707, jpMod, 2, 1, 1, 0.7, 500, 4000);
    jpverbL = jpverbOut : _, !;
    jpverbR = jpverbOut : !, _;
    
    // 4: Greyhole (spacey echo/reverb hybrid, Eventide-style)
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
masterFX = (_ * master_gain : ma.tanh), (_ * master_gain : ma.tanh);

// =============================================================================
// OUTPUT - Full synth with integrated effects chain
// =============================================================================

process = voice_L, voice_R : exciterFX : chorusFX : delayFX : reverbFX : masterFX;
