#!/usr/bin/env node

/**
 * Integration Test Procedure: Extension Installation and Uninstallation
 * 
 * This script automatically runs the complete integration test procedure for the Learning Buddy extension.
 * Integration tests verify the complete functionality of the extension by testing it in the 
 * actual VS Code environment.
 * 
 * This is an integration test because it involves:
 * - Multiple components working together (packaging, installation, VS Code environment)
 * - End-to-end behavior verification
 * - Cross-component validation
 * - Real environment interaction
 */

const { exec } = require('child_process');
const path = require('path');
const fs = require('fs');

// VS Code installation paths on Windows
const VSCODE_PATHS = [
    path.join(process.env.LOCALAPPDATA || '', 'Programs', 'Microsoft VS Code', 'bin', 'code.cmd'),
    path.join(process.env.PROGRAMFILES || '', 'Microsoft VS Code', 'bin', 'code.cmd'),
    path.join(process.env['PROGRAMFILES(X86)'] || '', 'Microsoft VS Code', 'bin', 'code.cmd')
];

function findVSCode() {
    for (const vscodePath of VSCODE_PATHS) {
        if (fs.existsSync(vscodePath)) {
            return `"${vscodePath}"`; // Quote the path to handle spaces
        }
    }
    return 'code'; // fallback to PATH
}

async function runCommand(command, options = {}) {
    return new Promise((resolve, reject) => {
        console.log(`Running: ${command}`);
        
        const process = exec(command, {
            cwd: path.join(__dirname, '..'),
            ...options
        });

        let stdout = '';
        let stderr = '';

        process.stdout.on('data', (data) => {
            stdout += data.toString();
            if (!options.silent) {
                process.stdout.write(data);
            }
        });

        process.stderr.on('data', (data) => {
            stderr += data.toString();
            if (!options.silent) {
                process.stderr.write(data);
            }
        });

        process.on('close', (code) => {
            if (code === 0) {
                resolve({ code, stdout, stderr });
            } else {
                reject(new Error(`Command failed with exit code ${code}: ${stderr}`));
            }
        });

        process.on('error', (error) => {
            reject(error);
        });
    });
}

async function checkPrerequisites() {
    console.log('Checking prerequisites...');
    
    try {
        // Check if npm is available
        await runCommand('npm --version', { silent: true });
        console.log('✅ npm is available');
    } catch (error) {
        throw new Error('npm is not available. Please ensure Node.js is installed.');
    }
    
    try {
        // Check if VS Code is available
        const vscodePath = findVSCode();
        if (vscodePath !== 'code') {
            console.log(`✅ VS Code found at: ${vscodePath.replace(/"/g, '')}`);
        } else {
            await runCommand('code --version', { silent: true });
            console.log('✅ VS Code is available in PATH');
        }
    } catch (error) {
        throw new Error('VS Code is not available. Please ensure VS Code is installed and accessible.');
    }
    
    console.log('All prerequisites are met!\n');
}

async function runIntegrationTests() {
    console.log('=== Learning Buddy Extension Integration Test Procedure ===\n');
    
    try {
        // Check prerequisites
        await checkPrerequisites();
        
        // 1. Package the extension
        console.log('1. Packaging the extension...');
        await runCommand('npm run package');
        console.log('✅ Extension packaged successfully!\n');

        // 2. Install the extension
        console.log('2. Installing the extension...');
        const vscodePath = findVSCode();
        // The vsix file is created in the root directory
        const vsixPath = path.join(__dirname, '..', '..', 'learning-primer-buddy-0.0.1.vsix');
        await runCommand(`${vscodePath} --install-extension "${vsixPath}"`);
        console.log('✅ Extension installed successfully!\n');

        // 3. Verify installation
        console.log('3. Verifying installation...');
        const vscodePathForList = findVSCode();
        const { stdout } = await runCommand(`${vscodePathForList} --list-extensions`, { silent: true });
        if (stdout.includes('learning-primer-buddy-dev.learning-primer-buddy')) {
            console.log('✅ Extension found in the list of installed extensions!\n');
        } else {
            throw new Error('Extension not found in the list of installed extensions');
        }

        // 4. Run automated verification
        console.log('4. Running automated verification tests...');
        await runCommand('npm run test:integration:verify');
        console.log('✅ Automated verification tests passed!\n');

        // 5. Uninstall the extension
        console.log('5. Uninstalling the extension...');
        const vscodePathForUninstall = findVSCode();
        await runCommand(`${vscodePathForUninstall} --uninstall-extension learning-primer-buddy-dev.learning-primer-buddy`);
        console.log('✅ Extension uninstalled successfully!\n');

        // 6. Verify uninstallation
        console.log('6. Verifying uninstallation...');
        const vscodePathForVerify = findVSCode();
        const { stdout: uninstallStdout } = await runCommand(`${vscodePathForVerify} --list-extensions`, { silent: true });
        if (!uninstallStdout.includes('learning-primer-buddy-dev.learning-primer-buddy')) {
            console.log('✅ Extension successfully removed from the list of installed extensions!\n');
        } else {
            throw new Error('Extension still found in the list of installed extensions after uninstallation');
        }

        console.log('🎉 All integration tests passed successfully!');
        console.log('');
        console.log('Summary of what was tested:');
        console.log('- Extension packaging');
        console.log('- Extension installation via VS Code CLI');
        console.log('- Extension listing verification');
        console.log('- Automated functionality verification');
        console.log('- Extension uninstallation via VS Code CLI');
        console.log('- Extension removal verification');
        console.log('');
        console.log('This is a true integration test because it involves:');
        console.log('- Multiple components working together (packaging, installation, VS Code environment)');
        console.log('- End-to-end behavior verification');
        console.log('- Cross-component validation');
        console.log('- Real environment interaction');
        console.log('');
        console.log('For additional real integration testing using VS Code Developer Tools, you can also run:');
        console.log('npm run test:integration:real');
        console.log('');
        console.log('This will provide instructions for running real integration tests in VS Code\'s Developer Tools console.');
    } catch (error) {
        console.error('❌ Integration test failed:', error.message);
        console.log('');
        console.log('Please check the error message above and ensure:');
        console.log('- VS Code is installed and accessible via the "code" command');
        console.log('- The extension packages correctly');
        console.log('- VS Code has the necessary permissions to install extensions');
        process.exit(1);
    }
}

// Run the integration tests
if (require.main === module) {
    runIntegrationTests();
}

module.exports = { runIntegrationTests };