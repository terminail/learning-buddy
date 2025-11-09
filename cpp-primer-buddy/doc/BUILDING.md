# Building and Packaging the VS Code Directory Tree Extension

This document explains how to build and package the extension for installation in VS Code.

## Prerequisites

1. Node.js (version 14 or higher)
2. npm (comes with Node.js)

## Building the Extension

1. Open a terminal/command prompt in the project directory
2. Install dependencies:
   ```
   npm install
   ```

3. Compile the TypeScript code:
   ```
   npx tsc
   ```

   This will generate JavaScript files in the `out/` directory.

## Packaging the Extension

1. Install vsce (VS Code Extension Manager) globally:
   ```
   npm install -g @vscode/vsce
   ```

2. Package the extension:
   ```
   vsce package
   ```

   This will create a `.vsix` file in the project directory.

## Installing the Extension

1. Open VS Code
2. Go to the Extensions view (Ctrl+Shift+X)
3. Click on the "..." menu and select "Install from VSIX..."
4. Select the generated `.vsix` file

## Alternative Installation (Development)

For development and testing:

1. Open the project folder in VS Code
2. Press F5 to launch the extension in a new Extension Development Host window

## Troubleshooting

If you encounter any issues:

1. Make sure all dependencies are installed:
   ```
   npm install
   ```

2. Check that the TypeScript compilation succeeds:
   ```
   npx tsc --project tsconfig.json
   ```

3. Ensure you have the latest version of vsce:
   ```
   npm install -g @vscode/vsce@latest
   ```