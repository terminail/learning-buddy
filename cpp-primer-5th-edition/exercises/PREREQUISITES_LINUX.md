# Prerequisites for Linux/WSL

This guide will help you set up the necessary tools to build and run the C++ exercises on Linux or Windows Subsystem for Linux (WSL).

## Required Tools

1. **C++ Compiler (g++)**
2. **CMake** (version 3.14 or higher)
3. **Google Test Framework**

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

4. **Install Ninja (optional but recommended)**
   - Run: `sudo apt install ninja-build`

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

4. **Install Ninja (optional but recommended)**
   - For CentOS/RHEL: `sudo yum install ninja-build`
   - For Fedora: `sudo dnf install ninja-build`

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