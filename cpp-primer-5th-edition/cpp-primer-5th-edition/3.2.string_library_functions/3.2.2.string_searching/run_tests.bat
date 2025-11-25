@echo off
REM Test runner script for string_searching exercise

REM Build first if needed
if not exist "build\test_string_searching_basics.exe" if not exist "build\test_string_searching_practice.exe" (
    echo Building project first...
    call build.bat > nul 2>&1
)

REM Check if build directory exists
if not exist "build" (
    echo Build directory not found. Please run build.bat first.
    exit /b 1
)

REM Navigate to build directory
cd build

REM Run all tests
echo Running all string searching tests...
test_string_searching_basics.exe
echo.
test_string_searching_practice.exe

echo.
echo Test execution completed!

REM Return to original directory
cd ..