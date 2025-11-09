const crypto = require('crypto');
const fs = require('fs');
const path = require('path');

/**
 * Generate a properly signed test license
 */
function generateTestLicense() {
    try {
        // Load the private key
        const privateKeyPath = path.join(__dirname, 'licence-keys', 'private-key.txt');
        const privateKey = fs.readFileSync(privateKeyPath, 'utf8');
        
        // Create license data with Gitee access information
        const licenseData = {
            id: crypto.randomUUID(),
            createdAt: new Date().toISOString(),
            expiresAt: new Date(Date.now() + 365 * 24 * 60 * 60 * 1000).toISOString(), // 1 year from now
            contentPermissions: ['all_chapters'],
            gitee: {
                accessToken: 'test-access-token', // This would be an encrypted token in a real implementation
                contentRepo: 'your-username/cpp-primer-content', // Replace with actual repository
                trackingRepo: 'your-username/cpp-primer-tracking', // Replace with actual repository
                branch: 'main'
            },
            limits: {
                maxDownloads: 5 // Test download limit
            }
        };

        // Convert to JSON and base64 encode
        const dataString = JSON.stringify(licenseData);
        const dataBuffer = Buffer.from(dataString, 'utf8');
        const encodedData = dataBuffer.toString('base64');

        // Sign the data with the private key
        const signer = crypto.createSign('SHA256');
        signer.update(encodedData);
        signer.end();
        const signature = signer.sign(privateKey, 'base64');
        
        // Combine data and signature
        const licenseKey = `${encodedData}|${signature}`;
        
        console.log('Generated test license key:');
        console.log(licenseKey);
        console.log('\nTo use this license:');
        console.log('1. Open the License Manager in the extension');
        console.log('2. Paste this key into the license input field');
        console.log('3. Click "Add License"');
        
        // Also save to a file for easier access
        const licenseFilePath = path.join(__dirname, 'test-license.txt');
        fs.writeFileSync(licenseFilePath, licenseKey);
        console.log(`\nLicense also saved to: ${licenseFilePath}`);
        
        return licenseKey;
    } catch (error) {
        console.error('Error generating test license:', error);
        return null;
    }
}

// Run if called directly
if (require.main === module) {
    generateTestLicense();
}

module.exports = { generateTestLicense };