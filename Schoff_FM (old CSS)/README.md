# Schoff FM Synth (Old CSS Version)

This is the legacy version of Schoff FM Synth using the original IE-compatible HTML faceplate and JUCE's default WebBrowserComponent (not WebView2). This version is known to work reliably across platforms.

## Pre-built Binaries

- **Windows VST3**: `schoff_stereo.vst3/` - Copy to `C:\Program Files\Common Files\VST3\`
- **Windows Standalone**: `schoff_stereo.exe` - Run directly
- **Windows Standalone (original)**: `schoff_FM.exe` - Original standalone build

## Building from Source

### Prerequisites

1. **JUCE Framework** - Download from [juce.com](https://juce.com/get-juce/)
2. **Faust Compiler** - Download from [faust.grame.fr](https://faust.grame.fr/downloads/)
3. **Platform-specific build tools** (see below)

### Step 1: Generate Plugin Project (Optional)

If you need to regenerate the plugin project from the DSP file:

```bash
cd "Schoff_FM (old CSS)"
faust2juce -nvoices 8 -midi schoff_stereo.dsp
```

Then add the HTML faceplate as a binary resource in the `.jucer` file.

### Step 2: Build for Your Platform

#### Windows (Visual Studio 2019/2022)

1. Install Visual Studio 2019 or 2022 with "Desktop development with C++" workload
2. Open Projucer and load `schoff_stereo/schoff_stereo.jucer`
3. Save to regenerate build files if needed
4. Open `schoff_stereo/Builds/VisualStudio2019/schoff_stereo.sln` (or VS2022)
5. Build in Release mode for x64

Or from command line:
```bash
cd schoff_stereo/Builds/VisualStudio2019
MSBuild.exe schoff_stereo.sln -p:Configuration=Release -p:Platform=x64
```

Output locations:
- VST3: `Builds/VisualStudio2019/x64/Release/VST3/schoff_stereo.vst3/`
- Standalone: `Builds/VisualStudio2019/x64/Release/Standalone Plugin/schoff_stereo.exe`

#### macOS (Xcode)

1. Install Xcode from the App Store
2. Open Projucer and load `schoff_stereo/schoff_stereo.jucer`
3. Save to regenerate build files
4. Open `schoff_stereo/Builds/MacOSX/schoff_stereo.xcodeproj`
5. Select Release scheme and build

Or from command line:
```bash
cd schoff_stereo/Builds/MacOSX
xcodebuild -project schoff_stereo.xcodeproj -configuration Release
```

Output locations:
- VST3: `Builds/MacOSX/build/Release/schoff_stereo.vst3`
- AU: `Builds/MacOSX/build/Release/schoff_stereo.component`
- Standalone: `Builds/MacOSX/build/Release/schoff_stereo.app`

#### Linux

1. Install dependencies:
```bash
sudo apt-get install build-essential libasound2-dev libjack-jackd2-dev \
    libfreetype6-dev libx11-dev libxcomposite-dev libxcursor-dev \
    libxinerama-dev libxrandr-dev libxrender-dev libwebkit2gtk-4.0-dev \
    libcurl4-openssl-dev
```

2. Open Projucer and load `schoff_stereo/schoff_stereo.jucer`
3. Save to regenerate build files
4. Build:
```bash
cd schoff_stereo/Builds/LinuxMakefile
make CONFIG=Release
```

Output locations:
- VST3: `Builds/LinuxMakefile/build/schoff_stereo.vst3`
- Standalone: `Builds/LinuxMakefile/build/schoff_stereo`

#### iOS (Xcode)

1. Open `schoff_stereo/Builds/iOS/schoff_stereo.xcodeproj` in Xcode
2. Configure signing with your Apple Developer account
3. Build for device or simulator

#### Android (Android Studio)

1. Open `schoff_stereo/Builds/Android` in Android Studio
2. Sync Gradle and build

## Project Structure

```
Schoff_FM (old CSS)/
├── schoff_stereo.dsp          # Faust DSP source code
├── schoffhauzer_synth_faceplate.html  # HTML UI (IE-compatible)
├── schoff_FM.exe              # Original standalone (Windows)
├── schoff_stereo.exe          # Built standalone (Windows)
├── schoff_stereo.vst3/        # Built VST3 plugin (Windows)
├── schoff_stereo/             # Generated JUCE plugin project
│   ├── FaustPluginProcessor.cpp
│   ├── schoff_stereo.jucer
│   └── Builds/
│       ├── VisualStudio2019/
│       ├── VisualStudio2022/
│       ├── MacOSX/
│       ├── LinuxMakefile/
│       ├── iOS/
│       └── Android/
├── FaustAudioApplication.cpp  # Original standalone source
├── schoff_FM.jucer            # Original standalone project
└── JuceLibraryCode_standalone/ # JUCE library code for standalone
```

## Technical Notes

- Uses JUCE's default `WebBrowserComponent` (IE/Edge Legacy on Windows, WebKit on macOS/Linux)
- HTML faceplate designed for maximum browser compatibility (IE 9+)
- Parameter communication via `juce://param/` URL scheme interception
- 8-voice polyphonic FM synthesizer with MIDI support

## License

See the main project LICENSE file for licensing information.
