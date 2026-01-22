#===============================================================================
# JUCE 8 WebView2 Plugin - CMake Configuration
# Schoffhauzer FM Synthesizer with modern HTML faceplate
#===============================================================================
cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME "schoff_FM" CACHE STRING "Plugin name")
set(COMPANY_NAME "9LiveZZZ" CACHE STRING "Company name")
set(PLUGIN_CODE "Schf" CACHE STRING "4-char plugin code")
set(MANUFACTURER_CODE "9Lvz" CACHE STRING "4-char manufacturer code")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch JUCE from GitHub
include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        8.0.0
    GIT_SHALLOW    TRUE
)
set(JUCE_BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
set(JUCE_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(JUCE)

# WebView2 SDK Path
set(WEBVIEW2_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/WebView2" CACHE PATH "WebView2 SDK")

if(WIN32)
    if(NOT EXISTS "${WEBVIEW2_SDK_PATH}/build/native/include/WebView2.h")
        message(WARNING "WebView2 SDK not found at ${WEBVIEW2_SDK_PATH}")
    endif()
endif()

# Create Plugin
juce_add_plugin(${PROJECT_NAME}
    COMPANY_NAME "${COMPANY_NAME}"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    PLUGIN_MANUFACTURER_CODE ${MANUFACTURER_CODE}
    PLUGIN_CODE ${PLUGIN_CODE}
    FORMATS VST3 Standalone
    PRODUCT_NAME "${PROJECT_NAME}"
    NEEDS_WEBVIEW2 TRUE
)

# Source files
target_sources(${PROJECT_NAME} PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
    Source/SpectrumAnalyzer.h
)

# Compile definitions
target_compile_definitions(${PROJECT_NAME} PUBLIC
    JUCE_WEB_BROWSER=1
    JUCE_USE_WIN_WEBVIEW2=1
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_USE_CURL=0
)

# Binary resources (HTML faceplate)
juce_add_binary_data(${PROJECT_NAME}_Data
    HEADER_NAME "BinaryData.h"
    NAMESPACE BinaryData
    SOURCES
        Resources/faceplate.html
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_NAME}_Data
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_core
        juce::juce_data_structures
        juce::juce_dsp
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

# WebView2 paths (Windows only)
if(WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE "${WEBVIEW2_SDK_PATH}/build/native/include")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(WEBVIEW2_ARCH "x64")
    else()
        set(WEBVIEW2_ARCH "x86")
    endif()
    target_link_directories(${PROJECT_NAME} PRIVATE "${WEBVIEW2_SDK_PATH}/build/native/${WEBVIEW2_ARCH}")
endif()

message(STATUS "")
message(STATUS "==========================================")
message(STATUS "  ${PROJECT_NAME} - WebView2 Enabled")
message(STATUS "  FFT Spectrum Analyzer Included")
message(STATUS "==========================================")
