# Prerequisites for Linux/WSL

This guide will help you set up the necessary tools to build and run the C++ exercises on Linux or Windows Subsystem for Linux (WSL).

## Installing WSL (Windows Subsystem for Linux)

If you're using Windows and want to run Linux tools, you can install WSL:

1. **Enable WSL**
   - Open PowerShell as Administrator
   - Run: `wsl --install`
   - This command will enable the required components, download the latest Linux kernel, set WSL 2 as the default, and install a Linux distribution (Ubuntu by default)

2. **Restart Your Computer**
   - A restart may be required to complete the installation

3. **Set Up Your Linux User**
   - After restarting, launch Ubuntu (or your chosen distribution) from the Start Menu
   - Create a username and password when prompted

4. **Update Your Linux Distribution**
   - Run: `sudo apt update && sudo apt upgrade`

## Required Tools

1. **C++ Compiler (g++)** - GNU Compiler Collection for C++. Compiles C++ source code into executable programs. Minimum version: GCC 7.0 or higher (C++17 support required). Recommended: GCC 9.0+ for full C++17 features.
2. **CMake** (version 3.14 or higher) - Cross-platform build system generator. Creates build files for your development environment. Required for Google Test integration and modern C++ project management. Recommended: CMake 3.20+ for best Google Test support.
3. **Google Test Framework** - Testing framework for C++. Used to write and run unit tests for the exercises. Installed via package manager with C++17 support.

## Recommended Editors/IDEs

1. **Visual Studio Code** - Free, lightweight editor with excellent C++ support through extensions.
2. **Vim/Neovim** - Terminal-based editor, excellent for Linux/WSL environments.
3. **CLion** - Professional C++ IDE by JetBrains (paid, but free for students).
4. **Code::Blocks** - Free C++ IDE that works well on Linux.

## Installation Steps

### For Ubuntu/Debian-based distributions:

### 1. Update Package Lists

1. **Open Terminal**

2. **Update package lists**
   - Run: `sudo apt update`

### 2. Install Required Packages

1. **Install GCC (g++)**
   - Run: `sudo apt install build-essential`

2. **Install CMake**
   - Run: `sudo apt install cmake`

3. **Install Google Test**
   - Run: `sudo apt install libgtest-dev`

4. **Install Ninja (if not already installed)**
   - Run: `sudo apt install ninja-build`

5. **Check Ninja**
   - Run: `ninja --version`
   - You should see version information

**Ninja** - Small build system with a focus on speed. Used by CMake to perform fast builds of the exercises.

### 3. Build Google Test (if needed)

On some distributions, you may need to build Google Test from source:

1. **Navigate to Google Test directory**
   - Run: `cd /usr/src/gtest`

2. **Create build directory**
   - Run: `sudo mkdir build && cd build`

3. **Build Google Test**
   - Run: `sudo cmake ..`
   - Run: `sudo make`

4. **Install libraries**
   - Run: `sudo cp *.a /usr/lib`

### For CentOS/RHEL/Fedora-based distributions:

### 1. Install Required Packages

1. **Install GCC (g++)**
   - For CentOS/RHEL: `sudo yum install gcc gcc-c++ make`
   - For Fedora: `sudo dnf install gcc gcc-c++ make`

2. **Install CMake**
   - For CentOS/RHEL: `sudo yum install cmake`
   - For Fedora: `sudo dnf install cmake`

3. **Install Google Test**
   - For CentOS/RHEL: `sudo yum install gtest-devel`
   - For Fedora: `sudo dnf install gtest-devel`

4. **Install Ninja (if not already installed)**
   - For CentOS/RHEL: `sudo yum install ninja-build`
   - For Fedora: `sudo dnf install ninja-build`

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

- If you get permission errors, make sure you're using sudo for package installations
- If Google Test is not found, make sure the development package is installed
- If commands are not found, make sure your package manager is up to date