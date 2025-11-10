/**
 * Real Integration Test: Verify Extension Installation
 * 
 * This integration test verifies that the extension can be properly installed
 * and uninstalled using the real VS Code command line interface.
 * 
 * This test requires VS Code to be installed and accessible via the 'code' command.
 */

import { spawn } from 'child_process';
import * as path from 'path';

describe('Extension Installation Integration Test', () => {
    const extensionPath = path.join(__dirname, '..', '..', '..', 'learning-primer-buddy-0.0.1.vsix');
    const extensionId = 'learning-primer-buddy-dev.learning-primer-buddy';

    it('should install the extension successfully using VS Code CLI', (done) => {
        // This test verifies that the extension can be installed using the real VS Code CLI
        // It's an integration test because it:
        // 1. Packages the extension (assumed to be done before running tests)
        // 2. Uses the real VS Code environment
        // 3. Tests end-to-end behavior
        // 4. Involves cross-component validation (extension packaging + VS Code installation)

        const installProcess = spawn('code', ['--install-extension', extensionPath], {
            stdio: 'pipe'
        });

        let stdout = '';
        let stderr = '';

        installProcess.stdout.on('data', (data) => {
            stdout += data.toString();
        });

        installProcess.stderr.on('data', (data) => {
            stderr += data.toString();
        });

        installProcess.on('close', (code) => {
            try {
                // Verify the installation was successful
                expect(code).toBe(0);
                expect(stdout).toContain('Extension');
                expect(stdout).toContain('successfully installed');
                expect(stderr).toBe('');
                done();
            } catch (error) {
                done(error);
            }
        });

        // Timeout after 30 seconds
        setTimeout(() => {
            installProcess.kill();
            done(new Error('Installation process timed out'));
        }, 30000);
    }, 35000); // 35 second timeout

    it('should list the installed extension using VS Code CLI', (done) => {
        // This test verifies that the extension appears in the list of installed extensions

        const listProcess = spawn('code', ['--list-extensions'], {
            stdio: 'pipe'
        });

        let stdout = '';
        let stderr = '';

        listProcess.stdout.on('data', (data) => {
            stdout += data.toString();
        });

        listProcess.stderr.on('data', (data) => {
            stderr += data.toString();
        });

        listProcess.on('close', (code) => {
            try {
                // Verify the extension is listed
                expect(code).toBe(0);
                expect(stdout).toContain('learning-primer-buddy-dev.learning-primer-buddy');
                expect(stderr).toBe('');
                done();
            } catch (error) {
                done(error);
            }
        });

        // Timeout after 10 seconds
        setTimeout(() => {
            listProcess.kill();
            done(new Error('List extensions process timed out'));
        }, 10000);
    }, 15000); // 15 second timeout

    it('should uninstall the extension successfully using VS Code CLI', (done) => {
        // This test verifies that the extension can be uninstalled using the real VS Code CLI

        const uninstallProcess = spawn('code', ['--uninstall-extension', extensionId], {
            stdio: 'pipe'
        });

        let stdout = '';
        let stderr = '';

        uninstallProcess.stdout.on('data', (data) => {
            stdout += data.toString();
        });

        uninstallProcess.stderr.on('data', (data) => {
            stderr += data.toString();
        });

        uninstallProcess.on('close', (code) => {
            try {
                // Verify the uninstallation was successful
                expect(code).toBe(0);
                expect(stdout).toContain('Extension');
                expect(stdout).toContain('was successfully uninstalled');
                expect(stderr).toBe('');
                done();
            } catch (error) {
                done(error);
            }
        });

        // Timeout after 10 seconds
        setTimeout(() => {
            uninstallProcess.kill();
            done(new Error('Uninstallation process timed out'));
        }, 10000);
    }, 15000); // 15 second timeout
});