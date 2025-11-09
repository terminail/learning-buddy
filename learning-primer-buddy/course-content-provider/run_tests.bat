@echo off

REM Test runner for the Course Content Provider service

echo Running Course Content Provider Tests
echo ====================================

REM Check if we're in the right directory
if not exist "pyproject.toml" (
    echo Error: pyproject.toml not found. Please run this script from the course-content-provider directory.
    pause
    exit /b 1
)

REM Install dependencies if not already installed
echo Installing dependencies...
pip install -e .[dev]

REM Run tests
echo Running tests...
python -m pytest tests -v

echo Tests completed.

pause