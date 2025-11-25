#!/bin/bash
echo "Building C++ Primer 5th Edition Buddy Extension..."

# Clean previous build
rm -rf out

# Remove old .vsix files
echo "Removing old .vsix files..."
rm -f cpp-primer-5th-edition-buddy-*.vsix

# Compile TypeScript
echo "Compiling TypeScript..."
npx tsc -p ./

# Package the extension
echo "Packaging VS Code extension..."
npx vsce package

if [ $? -eq 0 ]; then
    echo "Build completed successfully!"
    echo "Extension package: cpp-primer-5th-edition-buddy-0.0.1.vsix"
else
    echo "Build failed with error code $?"
    exit $?
fi