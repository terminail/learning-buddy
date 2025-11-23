# Prerequisites for macOS

This guide will help you set up the necessary tools to build and run the C++ exercises on macOS.

## Required Tools

1. **C++ Compiler (g++)** - GNU Compiler Collection for C++. Compiles C++ source code into executable programs. Minimum version: GCC 7.0 or higher (C++14 support required). Recommended: GCC 9.0+ (C++17 support).
2. **CMake** (version 3.14 or higher) - Cross-platform build system generator. Creates build files for your development environment. Required for Google Test integration and modern C++ project management. Recommended: CMake 3.20+ for best Google Test support.
3. **Google Test Framework** - Testing framework for C++. Used to write and run unit tests for the exercises. Installed via Homebrew with C++17 support.

## Recommended Editors/IDEs

1. **Visual Studio Code** - Free, lightweight editor with excellent C++ support through extensions.
2. **Xcode** - Apple's IDE with built-in C++ support.
3. **CLion** - Professional C++ IDE by JetBrains (paid, but free for students).
4. **Vim/Neovim** - Terminal-based editor, good for learning command-line workflows.

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

**Ninja** - Small build system with a focus on speed. Used by CMake to perform fast builds of the exercises.

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