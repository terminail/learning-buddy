# Prerequisites for macOS

This guide will help you set up the necessary tools to build and run the C++ exercises on macOS.

## Required Tools

1. **C++ Compiler (g++)**
2. **CMake** (version 3.14 or higher)
3. **Google Test Framework**

## Installation Steps

### 1. Install Xcode Command Line Tools

1. **Open Terminal** (Applications → Utilities → Terminal)

2. **Install Xcode Command Line Tools**
   - Run: `xcode-select --install`
   - Click "Install" in the dialog that appears
   - Accept the license agreement

### 2. Install Homebrew (Package Manager)

1. **Install Homebrew**
   - Go to: https://brew.sh/
   - Copy the installation command from the website
   - Paste and run it in Terminal
   - Follow the prompts to complete installation

2. **Verify Homebrew Installation**
   - Run: `brew --version`
   - You should see version information

### 3. Install Required Packages

1. **Install GCC (g++)**
   - Run: `brew install gcc`

2. **Install CMake**
   - Run: `brew install cmake`

3. **Install Google Test**
   - Run: `brew install googletest`

4. **Install Ninja (if not already installed)**
   - Run: `brew install ninja`

5. **Check Ninja**
   - Run: `ninja --version`
   - You should see version information

### 4. Verify Installation

1. **Check g++**
   - Run: `g++ --version`
   - You should see version information

2. **Check CMake**
   - Run: `cmake --version`
   - You should see version information

3. **Check Ninja (if installed)**
   - Run: `ninja --version`
   - You should see version information

## Troubleshooting

- If you get "command not found" errors, make sure Homebrew is properly installed
- If you have multiple C++ compilers, you might need to specify the full path to the desired compiler
- If Google Test is not found, try: `brew link googletest`