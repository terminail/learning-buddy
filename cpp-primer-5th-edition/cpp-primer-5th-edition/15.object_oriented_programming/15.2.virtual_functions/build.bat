@echo off
REM Build script for virtual_functions exercise

echo Building virtual functions exercise...

REM Clean any existing build directory to avoid path conflicts
if exist build rmdir /s /q build

REM Create build directory
mkdir build
cd build

REM Configure with CMake
REM Use default compiler detection for Windows
cmake .. -G "MinGW Makefiles"

REM Build the project
mingw32-make

echo Build completed successfully!
echo To run tests, use: run_tests.bat

REM Return to original directory
cd ..