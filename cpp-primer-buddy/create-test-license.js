const crypto = require('crypto');
const fs = require('fs');
const path = require('path');

/**
 * Generate a properly signed test license and save it to a file
 */
function createTestLicense() {
    try {
        // Load the private key
        const privateKeyPath = path.join(__dirname, 'licence-keys', 'private-key.txt');
        const privateKey = fs.readFileSync(privateKeyPath, 'utf8');
        
        // Create license data
        const licenseData = {
            id: crypto.randomUUID(),
            createdAt: new Date().toISOString(),
            expiresAt: new Date(Date.now() + 365 * 24 * 60 * 60 * 1000).toISOString(), // 1 year from now
            contentPermissions: ['all_chapters']
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
        
        // Save to file
        const licenseFilePath = path.join(__dirname, 'test-license.txt');
        fs.writeFileSync(licenseFilePath, licenseKey);
        
        console.log('Test license generated and saved to:');
        console.log(licenseFilePath);
        console.log('\nTo use this license:');
        console.log('1. Open the License Manager in the extension');
        console.log('2. Open the test-license.txt file and copy its contents');
        console.log('3. Paste the license key into the license input field');
        console.log('4. Click "Add License"');
        
        return licenseKey;
    } catch (error) {
        console.error('Error generating test license:', error);
        return null;
    }
}

// Run if called directly
if (require.main === module) {
    createTestLicense();
}

module.exports = { createTestLicense };