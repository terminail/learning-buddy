@echo off

REM Course Content Provider Startup Script

echo Course Content Provider - Startup Script
echo ========================================

REM Check if conda is available
conda --version >nul 2>&1
if %errorlevel% neq 0 (
    echo Error: Conda is not installed or not in PATH
    echo Please install Miniconda or Anaconda first
    pause
    exit /b 1
)

REM Check if conda environment exists
conda env list | findstr liugejiao >nul
if %errorlevel% neq 0 (
    echo Creating conda environment 'liugejiao'
    conda create -n liugejiao python=3.12 -y
)

REM Activate conda environment
echo Activating conda environment 'liugejiao'
call conda activate liugejiao

REM Install dependencies using pyproject.toml
echo Installing dependencies from pyproject.toml
pip install .

REM Check if Podman is available
podman --version >nul 2>&1
if %errorlevel% equ 0 (
    echo Podman is available. You can also run the service in a container:
    echo   podman build -t course-content-provider -f Podmanfile .
    echo   podman run -p 8000:8000 course-content-provider
    echo.
)

REM Start the service
echo Starting Course Content Provider service
echo Service will be available at http://localhost:8000
echo Press Ctrl+C to stop the service
echo.

course-content-provider

pause