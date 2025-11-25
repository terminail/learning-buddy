@echo off
REM Test runner script for variable_initialization exercise (Windows)

REM Check if build directory exists
if not exist "build" (
    echo Build directory not found. Please run build.bat first.
    exit /b 1
)

REM Navigate to build directory
cd build

REM Run all tests
echo Running all variable initialization tests...
test_variable_initialization_basics.exe
echo.
test_variable_initialization_practice.exe

echo.
echo Test execution completed!

REM Return to original directory
cd ..