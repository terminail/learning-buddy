@echo off
REM Test runner script for if statements exercise

REM Build first if needed
if not exist "build\test_if_statements_basics.exe" if not exist "build\test_if_statements_practice.exe" (
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

REM Run all tests and capture output
echo Running all if statements tests...
test_if_statements_basics.exe > basics_output.txt 2>&1
test_if_statements_practice.exe > practice_output.txt 2>&1

REM Display output with colored PASSED and FAILED messages using PowerShell
powershell -Command "$content = Get-Content '.\basics_output.txt'; foreach ($line in $content) { if ($line -match 'FAILED') { Write-Host $line -ForegroundColor Red } elseif ($line -match 'PASSED') { Write-Host $line -ForegroundColor Green } else { Write-Host $line } }"
echo.
powershell -Command "$content = Get-Content '.\practice_output.txt'; foreach ($line in $content) { if ($line -match 'FAILED') { Write-Host $line -ForegroundColor Red } elseif ($line -match 'PASSED') { Write-Host $line -ForegroundColor Green } else { Write-Host $line } }"

REM Clean up temporary files
del basics_output.txt practice_output.txt

echo.
echo Test execution completed!

REM Return to original directory
cd ..