#!/bin/bash
echo "Building VS Code Directory Tree Extension"
echo "Compiling TypeScript..."
npx tsc
echo "Packaging extension..."
npx vsce package
echo "Done! VSIX file created."