# Schoffhauzer FM Synthesizer

A modern FM synthesizer plugin built with JUCE 8 and WebView2, featuring a sleek HTML/CSS user interface.

## Features

- **8-voice polyphonic FM synthesis**
- **2 oscillators** with 7 waveforms each (Saw, Saw+, Tri, Tri+, Sqr, Pulse, Sine)
- **Sub oscillator** with octave selection
- **Noise generator** (White, Pink, Brown)
- **Multi-mode filter** with envelope modulation
- **2 ADSR envelopes** (Amplitude & Filter)
- **LFO** with multiple destinations
- **Effects**: Chorus, Delay, Reverb (5 algorithms), Stereo Width
- **Oversampling** (Off, x4, x8)
- **Real-time spectrum analyzer and oscilloscope**
- **Multiple UI themes** (Celestial, Neon, Void, Ember, Heaven, Hell, Death)
- **Resizable window** with UI scaling (50% - 200%)

## Requirements

### Build Requirements
- **CMake** 3.22 or higher
- **C++17** compatible compiler
- **Visual Studio 2019/2022** (Windows)
- **WebView2 Runtime** (Windows - usually pre-installed on Windows 10/11)

### Dependencies (automatically fetched)
- **JUCE 8.0.0** - Fetched via CMake FetchContent

### Manual Dependencies
- **WebView2 SDK** - Must be downloaded separately

## Build Instructions

### 1. Clone the repository
```bash
git clone https://github.com/9LiveZZZ-Git/schoff_FM.git
cd schoff_FM
```

### 2. Download WebView2 SDK
Download the WebView2 SDK NuGet package and extract to `ThirdParty/WebView2/`:
```
ThirdParty/
└── WebView2/
    └── build/
        └── native/
            ├── include/
            │   └── WebView2.h
            └── x64/
                └── WebView2LoaderStatic.lib
```

You can download it from: https://www.nuget.org/packages/Microsoft.Web.WebView2

Or use NuGet:
```powershell
nuget install Microsoft.Web.WebView2 -OutputDirectory ThirdParty
mv ThirdParty/Microsoft.Web.WebView2.*/build ThirdParty/WebView2/build
```

### 3. Configure and Build
```bash
# Create build directory
mkdir build
cd build

# Configure
cmake .. -G "Visual Studio 16 2019" -A x64
# Or for VS 2022:
cmake .. -G "Visual Studio 17 2022" -A x64

# Build Release
cmake --build . --config Release
```

### 4. Output Location
After building, the plugin files will be in:
- **Standalone**: `build/schoff_FM_artefacts/Release/Standalone/schoff_FM.exe`
- **VST3**: `build/schoff_FM_artefacts/Release/VST3/schoff_FM.vst3/`

### 5. Running the Standalone
Copy `faceplate.html` from `Resources/` or `Schoff_FM Modern/` to the same folder as the executable, or it will use the embedded version.

## Pre-built Binaries

Pre-built Windows binaries are available in the `Schoff_FM Modern/` folder:
- `schoff_FM.exe` - Standalone application
- `schoff_FM.vst3/` - VST3 plugin
- `faceplate.html` - UI template
- `WebView2Loader.dll` - WebView2 runtime loader

## Project Structure

```
schoff_FM/
├── Source/                 # C++ source files
│   ├── PluginProcessor.cpp # Audio processing & parameters
│   ├── PluginProcessor.h
│   ├── PluginEditor.cpp    # WebView2 UI integration
│   ├── PluginEditor.h
│   ├── SpectrumAnalyzer.h  # FFT spectrum analysis
│   ├── HilbertStereoWidth.h # Stereo widening DSP
│   ├── LushChorus.h        # Chorus effect
│   └── StereoDelay.h       # Ping-pong delay
├── Resources/              # Build resources
│   └── faceplate.html      # UI template (embedded in binary)
├── Schoff_FM Modern/       # Pre-built release binaries
├── CMakeLists.txt          # CMake build configuration
└── README.md
```

## License

Copyright 2025 9LiveZZZ

## Credits

Built with [JUCE](https://juce.com/) framework.
