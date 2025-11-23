# Prerequisites for Windows

This guide will help you set up the necessary tools to build and run the C++ exercises on Windows.

## Required Tools

1. **C++ Compiler (g++)** - GNU Compiler Collection for C++. Compiles C++ source code into executable programs. Minimum version: GCC 7.0 or higher (C++17 support required). Recommended: GCC 9.0+ for full C++17 features.
2. **CMake** (version 3.14 or higher) - Cross-platform build system generator. Creates build files for your development environment. Required for Google Test integration and modern C++ project management. Recommended: CMake 3.20+ for best Google Test support.
3. **Google Test Framework** - Testing framework for C++. Used to write and run unit tests for the exercises. Installed via MSYS2 package manager with C++17 support.
4. **MSYS2** (recommended for g++ on Windows) - Software distribution and building platform for Windows. Provides a Unix-like environment and package management.

## Recommended Editors/IDEs

1. **Visual Studio Code** - Free, lightweight editor with excellent C++ support through extensions.
2. **Code::Blocks** - Free C++ IDE that works well with MinGW/MSYS2.
3. **CLion** - Professional C++ IDE by JetBrains (paid, but free for students).
4. **Vim/Neovim** - Terminal-based editor, good for learning command-line workflows.

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
   - You should see version information like: `g++ (GCC) 11.2.0`
   - Expected: gcc version 7.0 or higher (C++17 support). Recommended: gcc version 9.0 or higher for full C++17 features.
   - **Run this command in**: Any terminal (Command Prompt, PowerShell, or MSYS2 terminal)

3. **Check CMake**
   - Run: `cmake --version`
   - You should see version information like: `cmake version 4.1.2`
   - Expected: cmake version 3.14 or higher. Your version (4.1.2) is more than sufficient for Google Test.
   - **Run this command in**: Any terminal (Command Prompt, PowerShell, or MSYS2 terminal)

4. **Install Ninja (if not already installed)**
   - **Important**: You must run this command in an MSYS2 MinGW 64-bit terminal.
   - To open MSYS2 MinGW 64-bit terminal:
     - **Method 1 (Start Menu)**: Click Start Menu → MSYS2 → MSYS2 MinGW 64-bit
     - **Method 2 (Command Line)**: Press `Win + R`, type `C:\msys64\mingw64.exe`, and press Enter
     - **Method 3 (Direct Execution)**: Navigate to `C:\msys64\` and double-click `mingw64.exe`
     - **Method 4 (From PATH)**: Open Command Prompt or PowerShell, then run: `mingw64.exe`
   - In the MSYS2 MinGW 64-bit terminal, you should see a prompt like: `user@computer MINGW64 ~`
   - Run: `pacman -S mingw-w64-x86_64-ninja`
   - **Do not run this command in**: Command Prompt (`C:\>`) or PowerShell (`PS C:\>`)

5. **Check Ninja**
   - Run: `ninja --version`
   - You should see version information like: `1.11.1`
   - Expected: ninja version 1.10 or higher.
   - **Run this command in**: Any terminal (Command Prompt, PowerShell, or MSYS2 terminal). Expected: ninja version 1.10 or higher.

**Ninja** - Small build system with a focus on speed. Used by CMake to perform fast builds of the exercises.

## Troubleshooting

- If commands are not found, make sure you've restarted your terminal after updating PATH
  - **Correct terminal prompt**: `user@computer MINGW64 ~`
  - **Wrong terminals**: Command Prompt (`C:\>`) or PowerShell (`PS C:\>`)
- If you get permission errors, try running the terminal as Administrator
- If packages fail to install, make sure your MSYS2 is fully updated
- If `pacman` command is not found:
  - **You're likely in the wrong terminal**
  - Close your current terminal
  - Open MSYS2 MinGW 64-bit terminal using one of these methods:
    - **Method 1**: Start Menu → MSYS2 → MSYS2 MinGW 64-bit
    - **Method 2**: Press `Win + R`, type `C:\msys64\mingw64.exe`, press Enter
    - **Method 3**: Navigate to `C:\msys64\` and double-click `mingw64.exe`
    - **Method 4 (From PATH)**: Open Command Prompt or PowerShell, then run: `mingw64.exe`
  - Verify prompt shows: `user@computer MINGW64 ~`