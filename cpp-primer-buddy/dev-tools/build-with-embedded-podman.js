#!/usr/bin/env node

/**
 * Build script that includes embedded Podman functionality
 */

const { execSync } = require('child_process');
const path = require('path');
const os = require('os');

function main() {
    const platform = os.platform();
    console.log(`Building Learning Buddy Extension with embedded Podman support for ${getPlatformName(platform)}...`);
    
    try {
        // 1. Compile TypeScript files
        console.log('Compiling TypeScript files...');
        execSync('npm run compile', { stdio: 'inherit' });
        
        // 2. Embed Podman tools
        console.log('Embedding Podman tools...');
        execSync('node dev-tools/embed-podman.js', { stdio: 'inherit' });
        
        // 3. Show platform-specific information
        showPlatformSpecificInfo(platform);
        
        // 4. Package the extension
        console.log('Packaging the extension...');
        execSync('vsce package', { stdio: 'inherit' });
        
        console.log('Build completed successfully!');
        console.log('The extension now includes embedded Podman support for your platform.');
        console.log('\nNext steps:');
        console.log('1. Follow the platform-specific instructions in embedded-tools/');
        console.log('2. Install the generated .vsix file in VS Code');
        console.log('3. Restart VS Code to activate the extension');
        
    } catch (error) {
        console.error('Build failed:', error.message);
        process.exit(1);
    }
}

function getPlatformName(platform) {
    switch (platform) {
        case 'win32': return 'Windows';
        case 'darwin': return 'macOS';
        case 'linux': return 'Linux';
        default: return platform;
    }
}

function showPlatformSpecificInfo(platform) {
    console.log('\nPlatform-specific information:');
    
    switch (platform) {
        case 'win32':
            console.log('- Ensure WSL2 is enabled for optimal Podman performance');
            console.log('- Follow the instructions in embedded-tools/README-WINDOWS.md');
            break;
        case 'darwin':
            console.log('- Ensure you have the latest Xcode command line tools');
            console.log('- Follow the instructions in embedded-tools/README-MAC.md');
            break;
        case 'linux':
            console.log('- Ensure your user is in the appropriate groups for rootless Podman');
            console.log('- Follow the instructions in embedded-tools/README-LINUX.md');
            break;
        default:
            console.log('- Platform-specific instructions are in the embedded-tools directory');
    }
    
    console.log('- The Course Content Provider image should be built and placed in embedded-images/');
}

if (require.main === module) {
    main();
}