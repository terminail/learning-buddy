# Prerequisites for Windows

This guide will help you set up the necessary tools to build and run the C++ exercises on Windows.

## Required Tools

1. **C++ Compiler (g++)**
2. **CMake** (version 3.14 or higher)
3. **Google Test Framework**
4. **MSYS2** (recommended for g++ on Windows)

## Installation Steps

### 1. Install MSYS2

1. **Download MSYS2**
   - Go to: https://www.msys2.org/
   - Download the installer (usually named `msys2-x86_64-*.exe`)

2. **Install MSYS2**
   - Run the downloaded installer
   - Choose the default installation directory: `C:\msys64`
   - Complete the installation

3. **Update MSYS2**
   - Open MSYS2 MSYS terminal (from Start Menu → MSYS2 → MSYS2 MSYS)
   - Run: `pacman -Syu`
   - Close the terminal when prompted
   - Reopen MSYS2 MSYS terminal
   - Run: `pacman -Su`

### 2. Install Required Packages

1. **Open MSYS2 MinGW 64-bit terminal** (Start Menu → MSYS2 → MSYS2 MinGW 64-bit)

2. **Install GCC (g++)**
   - Run: `pacman -S mingw-w64-x86_64-gcc`

3. **Install CMake**
   - Run: `pacman -S mingw-w64-x86_64-cmake`

4. **Install Google Test**
   - Run: `pacman -S mingw-w64-x86_64-gtest`

5. **Install Ninja (optional but recommended)**
   - Run: `pacman -S mingw-w64-x86_64-ninja`

### 3. Add to System PATH

1. **Open System Environment Variables**
   - Press `Win + R`, type `sysdm.cpl`, press Enter
   - Click "Environment Variables"

2. **Edit PATH Variable**
   - In "System variables" section, find and select "Path"
   - Click "Edit"
   - Click "New" and add these paths:
     ```
     C:\msys64\mingw64\bin
     C:\msys64\usr\bin
     ```

3. **Apply Changes**
   - Click "OK" to close all dialogs
   - Restart any open terminals or command prompts

### 4. Verify Installation

1. **Open a new Command Prompt** (not MSYS2 terminal)

2. **Check g++**
   - Run: `g++ --version`
   - You should see version information

3. **Check CMake**
   - Run: `cmake --version`
   - You should see version information

4. **Check Ninja (if installed)**
   - Run: `ninja --version`
   - You should see version information

## Troubleshooting

- If commands are not found, make sure you've restarted your terminal after updating PATH
- If you get permission errors, try running the terminal as Administrator
- If packages fail to install, make sure your MSYS2 is fully updated