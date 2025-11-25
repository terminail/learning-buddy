@echo off
echo Building Python Crash Course 3rd Edition Buddy Extension...

REM Install npm dependencies
echo Installing npm dependencies...
call npm install

REM Check if npm install succeeded
if %ERRORLEVEL% NEQ 0 (
    echo Failed to install npm dependencies
    exit /b %ERRORLEVEL%
)

echo npm dependencies installed successfully

REM Clean previous build
if exist "out" rmdir /s /q "out"

REM Remove old .vsix files
echo Removing old .vsix files...
for %%f in (python-3rd-edition-buddy-*.vsix) do (
    if exist "%%f" (
        echo Deleting: %%f
        del "%%f"
    )
)

REM Compile TypeScript
echo Compiling TypeScript...
call npx tsc -p ./

REM Package the extension
echo Packaging VS Code extension...
call npx vsce package

if %ERRORLEVEL% EQU 0 (
    echo Build completed successfully!
    echo Extension package: python-3rd-edition-buddy-0.0.1.vsix
) else (
    echo Build failed with error code %ERRORLEVEL%
    exit /b %ERRORLEVEL%
)