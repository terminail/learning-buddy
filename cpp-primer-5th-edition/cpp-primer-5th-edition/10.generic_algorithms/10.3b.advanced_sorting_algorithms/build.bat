@echo off
REM Build script for advanced sorting algorithms exercise
REM This script builds the exercise using CMake and MinGW Make

echo Building advanced sorting algorithms exercise...

REM Remove any existing build directory
if exist "build" rmdir /s /q build

REM Create build directory
mkdir build
cd build

REM Configure with CMake using MinGW Makefiles
cmake .. -G "MinGW Makefiles"

REM Build the project
mingw32-make

echo Build completed successfully!
echo To run tests, use: run_tests.bat