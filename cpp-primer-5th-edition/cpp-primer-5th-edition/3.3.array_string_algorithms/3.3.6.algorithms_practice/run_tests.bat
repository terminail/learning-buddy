@echo off
REM Test runner script for algorithms practice exercise

REM Build the project first
echo Building project...
call build.bat > nul 2>&1

REM Check if build was successful
if %errorlevel% neq 0 (
    echo Build failed. Please check your code.
    exit /b 1
)

echo Build successful!

REM Navigate to build directory
cd build

REM Run all tests and capture output
echo Running basic tests...
test_algorithms_practice_basics.exe > basics_output.txt 2>&1

echo.
echo Running practice tests...
test_algorithms_practice_practice.exe > practice_output.txt 2>&1

REM Display output with colored PASSED and FAILED messages using PowerShell
powershell -Command "$content = Get-Content '.\basics_output.txt'; foreach ($line in $content) { if ($line -match 'FAILED') { Write-Host $line -ForegroundColor Red } elseif ($line -match 'PASSED') { Write-Host $line -ForegroundColor Green } else { Write-Host $line } }"
echo.
powershell -Command "$content = Get-Content '.\practice_output.txt'; foreach ($line in $content) { if ($line -match 'FAILED') { Write-Host $line -ForegroundColor Red } elseif ($line -match 'PASSED') { Write-Host $line -ForegroundColor Green } else { Write-Host $line } }"

REM Clean up temporary files
del basics_output.txt practice_output.txt

echo.
echo All tests completed!

REM Return to original directory
cd ..