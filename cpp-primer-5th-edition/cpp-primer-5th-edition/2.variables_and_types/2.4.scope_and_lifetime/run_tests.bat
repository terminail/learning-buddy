@echo off
REM Test runner script for scope_and_lifetime exercise (Windows)

REM Check if build directory exists
if not exist "build" (
    echo Build directory not found. Please run build.bat first.
    exit /b 1
)

REM Navigate to build directory
cd build

REM Run all tests
echo Running all scope and lifetime tests...
test_scope_and_lifetime_basics.exe
echo.
test_scope_and_lifetime_practice.exe

echo.
echo Test execution completed!

REM Return to original directory
cd ..