#!/usr/bin/env node

/**
 * Script to embed Podman binaries and related tools into the extension package.
 * This implements the embedded container strategy for improved user experience.
 */

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

// Function to download and embed Podman
function embedPodman() {
    console.log('Embedding Podman into the extension...');
    
    // Create directory for embedded tools
    const toolsDir = path.join(__dirname, '..', 'embedded-tools');
    if (!fs.existsSync(toolsDir)) {
        fs.mkdirSync(toolsDir, { recursive: true });
    }
    
    // Check if Podman is already installed locally
    try {
        execSync('podman --version', { stdio: 'ignore' });
        console.log('Podman is already available on the system.');
        return true;
    } catch (error) {
        console.log('Podman not found on system. Preparing embedded version...');
    }
    
    // For Windows, we might download a portable version
    // For Linux/Mac, we might use a static binary or AppImage
    const platform = process.platform;
    
    switch (platform) {
        case 'win32':
            return embedPodmanWindows(toolsDir);
        case 'darwin':
            return embedPodmanMac(toolsDir);
        case 'linux':
            return embedPodmanLinux(toolsDir);
        default:
            console.warn(`Unsupported platform: ${platform}`);
            return false;
    }
}

function embedPodmanWindows(toolsDir) {
    console.log('Preparing embedded Podman for Windows...');
    
    // Check if Podman is already downloaded
    const podmanPath = path.join(toolsDir, 'podman.exe');
    if (fs.existsSync(podmanPath)) {
        console.log('Podman executable already exists.');
        return true;
    }
    
    // In a real implementation, this would download the Windows portable version
    // For now, we'll create a more detailed placeholder with download instructions
    const placeholderPath = path.join(toolsDir, 'README-WINDOWS.md');
    const readmeContent = `# Embedded Podman for Windows

## Download Instructions

To use the embedded Podman functionality on Windows, you need to download the Podman portable distribution:

1. Visit the [Podman releases page](https://github.com/containers/podman/releases)
2. Download the latest Windows zip file (e.g., podman-remote-release-windows.zip)
3. Extract the podman.exe file to this directory

## Alternative Installation

You can also install Podman Desktop which includes the required components:
- Download from [Podman Desktop](https://podman-desktop.io/)
- This provides a GUI and command-line tools

## Requirements

- Windows 10 or later
- Enabled WSL2 (Windows Subsystem for Linux)
- At least 4GB of free disk space

## Notes

The embedded Podman will automatically be used if system Podman is not found.
`;
    fs.writeFileSync(placeholderPath, readmeContent);
    console.log('Created detailed instructions for Windows Podman embedding.');
    return true;
}

function embedPodmanMac(toolsDir) {
    console.log('Preparing embedded Podman for macOS...');
    
    // Check if Podman is already downloaded
    const podmanPath = path.join(toolsDir, 'podman');
    if (fs.existsSync(podmanPath)) {
        console.log('Podman executable already exists.');
        return true;
    }
    
    // In a real implementation, this would download a static binary or AppImage
    const placeholderPath = path.join(toolsDir, 'README-MAC.md');
    const readmeContent = `# Embedded Podman for macOS

## Download Instructions

To use the embedded Podman functionality on macOS, you need to download the Podman binary:

1. Visit the [Podman releases page](https://github.com/containers/podman/releases)
2. Download the macOS binary or use Homebrew:
   \`\`\`
   brew install podman
   \`\`\`
3. For embedded use, copy the podman binary to this directory

## Alternative Installation

You can also use Podman Desktop which provides a complete solution:
- Download from [Podman Desktop](https://podman-desktop.io/)

## Requirements

- macOS 10.15 (Catalina) or later
- Intel or Apple Silicon processor

## Notes

The embedded Podman will automatically be used if system Podman is not found.
`;
    fs.writeFileSync(placeholderPath, readmeContent);
    console.log('Created detailed instructions for macOS Podman embedding.');
    return true;
}

function embedPodmanLinux(toolsDir) {
    console.log('Preparing embedded Podman for Linux...');
    
    // Check if Podman is already downloaded
    const podmanPath = path.join(toolsDir, 'podman');
    if (fs.existsSync(podmanPath)) {
        console.log('Podman executable already exists.');
        return true;
    }
    
    // In a real implementation, this would download a static binary
    const placeholderPath = path.join(toolsDir, 'README-LINUX.md');
    const readmeContent = `# Embedded Podman for Linux

## Download Instructions

To use the embedded Podman functionality on Linux, you can download a static binary:

1. Visit the [Podman releases page](https://github.com/containers/podman/releases)
2. Download the static binary for your architecture
3. Extract and copy the podman binary to this directory

## Alternative Installation

Most Linux distributions have Podman packages available:

### Ubuntu/Debian:
\`\`\`
sudo apt update
sudo apt install podman
\`\`\`

### Fedora/RHEL/CentOS:
\`\`\`
sudo dnf install podman
\`\`\`

### Arch Linux:
\`\`\`
sudo pacman -S podman
\`\`\`

## Requirements

- Most modern Linux distributions (kernel 3.10 or higher)
- systemd or compatible init system (for rootless operation)

## Notes

The embedded Podman will automatically be used if system Podman is not found.
`;
    fs.writeFileSync(placeholderPath, readmeContent);
    console.log('Created detailed instructions for Linux Podman embedding.');
    return true;
}

// Function to embed Course Content Provider container image
function embedCourseContentProvider() {
    console.log('Embedding Course Content Provider container image...');
    
    // Create directory for embedded images
    const imagesDir = path.join(__dirname, '..', 'embedded-images');
    if (!fs.existsSync(imagesDir)) {
        fs.mkdirSync(imagesDir, { recursive: true });
    }
    
    // Check if image already exists
    const imageTarPath = path.join(imagesDir, 'course-content-provider.tar');
    if (fs.existsSync(imageTarPath)) {
        console.log('Course Content Provider image already exists.');
        return true;
    }
    
    // In a real implementation, this would:
    // 1. Build the Course Content Provider image
    // 2. Export it as a tar file
    // 3. Include it in the extension package
    
    const ccpDir = path.join(__dirname, '..', 'course-content-provider');
    if (!fs.existsSync(ccpDir)) {
        console.warn('Course Content Provider directory not found.');
        return false;
    }
    
    const readmeContent = `# Embedded Container Images

## Course Content Provider Image

The Course Content Provider image will be embedded here during the build process.

## Build Process

To build and embed the image:

1. Navigate to the course-content-provider directory
2. Build the image:
   \`\`\`
   podman build -t course-content-provider -f Podmanfile .
   \`\`\`
3. Export the image:
   \`\`\`
   podman save course-content-provider -o course-content-provider.tar
   \`\`\`
4. Move the tar file to this directory

## Loading the Image

The extension will automatically load the embedded image if needed:
\`\`\`
podman load -i course-content-provider.tar
\`\`\`

## Notes

- The embedded image reduces dependency on external repositories
- Image loading happens automatically during container startup
- Updates to the image require rebuilding the extension package
`;
    
    const placeholderPath = path.join(imagesDir, 'README.md');
    fs.writeFileSync(placeholderPath, readmeContent);
    console.log('Created detailed instructions for embedded container images.');
    
    return true;
}

// Function to load embedded images
function loadEmbeddedImages() {
    console.log('Loading embedded container images...');
    
    const imagesDir = path.join(__dirname, '..', 'embedded-images');
    if (!fs.existsSync(imagesDir)) {
        console.log('No embedded images directory found.');
        return true;
    }
    
    // Check for image tar files
    const files = fs.readdirSync(imagesDir);
    const imageFiles = files.filter(file => file.endsWith('.tar'));
    
    if (imageFiles.length === 0) {
        console.log('No embedded images found.');
        return true;
    }
    
    // In a real implementation, this would load the images
    console.log(`Found ${imageFiles.length} embedded images:`);
    imageFiles.forEach(file => {
        console.log(`  - ${file}`);
    });
    
    console.log('In a full implementation, these images would be loaded into Podman.');
    return true;
}

// Main function
function main() {
    console.log('Starting embedding process...');
    
    try {
        // Embed Podman
        if (!embedPodman()) {
            console.error('Failed to embed Podman.');
            process.exit(1);
        }
        
        // Embed Course Content Provider
        if (!embedCourseContentProvider()) {
            console.error('Failed to embed Course Content Provider.');
            process.exit(1);
        }
        
        // Load embedded images
        if (!loadEmbeddedImages()) {
            console.error('Failed to load embedded images.');
            process.exit(1);
        }
        
        console.log('Embedding process completed successfully.');
        console.log('\nNext steps:');
        console.log('1. Follow the platform-specific instructions in embedded-tools/');
        console.log('2. Build the Course Content Provider image and place it in embedded-images/');
        console.log('3. Package the extension with: npm run package');
    } catch (error) {
        console.error('Error during embedding process:', error);
        process.exit(1);
    }
}

// Run if called directly
if (require.main === module) {
    main();
}

module.exports = {
    embedPodman,
    embedCourseContentProvider,
    loadEmbeddedImages
};