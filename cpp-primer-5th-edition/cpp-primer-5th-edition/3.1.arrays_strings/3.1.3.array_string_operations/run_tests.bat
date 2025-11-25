@echo off
REM Test runner script for array and string operations exercise (Windows)

REM Build the project first
echo Building project...
call build.bat > nul 2>&1

REM Check if build was successful
if %errorlevel% neq 0 (
    echo Build failed. Please check your code.
    exit /b 1
)

echo Build successful!

REM Run the Google Test executables
echo Running basic tests...
cd build
test_array_string_operations_basics.exe

echo.
echo Running practice tests...
test_array_string_operations_practice.exe

echo.
echo All tests completed!

REM Return to original directory
cd ..