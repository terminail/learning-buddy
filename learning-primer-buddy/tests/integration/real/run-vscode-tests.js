#!/usr/bin/env node

/**
 * VS Code Extension Integration Test Runner
 * 
 * This script runs the existing automated integration tests which already handle
 * packaging, installing, and testing the extension in the real VS Code environment.
 */

const { spawn } = require('child_process');
const path = require('path');

async function runCommand(command, args, options = {}) {
    return new Promise((resolve, reject) => {
        console.log(`Running: ${command} ${args.join(' ')}`);
        
        const process = spawn(command, args, {
            cwd: path.join(__dirname, '..', '..'),
            ...options,
            shell: true // Use shell to ensure commands are found
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

async function main() {
    try {
        console.log('=== Running VS Code Extension Integration Tests ===');
        console.log('Using the existing automated integration test framework...\n');
        
        // Run the existing automated integration test
        await runCommand('npm', ['run', 'test:integration:automated']);
        
        console.log('✅ All VS Code extension integration tests passed!');
    } catch (err) {
        console.error('❌ Failed to run VS Code extension integration tests');
        console.error(err);
        process.exit(1);
    }
}

if (require.main === module) {
    main();
}