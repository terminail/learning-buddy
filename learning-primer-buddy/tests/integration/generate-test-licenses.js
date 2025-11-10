const crypto = require('crypto');
const fs = require('fs');
const path = require('path');

/**
 * Generate test licenses for different scenarios
 */
function generateTestLicenses() {
    try {
        // Load the private key
        const privateKeyPath = path.join(__dirname, '..', 'licence-keys', 'private-key.txt');
        const privateKey = fs.readFileSync(privateKeyPath, 'utf8');
        
        // Scenario 1: Valid License (License Paid scenario)
        const validLicenseData = {
            id: crypto.randomUUID(),
            createdAt: new Date().toISOString(),
            expiresAt: new Date(Date.now() + 365 * 24 * 60 * 60 * 1000).toISOString(), // 1 year from now
            contentPermissions: ['all_chapters'],
            gitee: {
                accessToken: 'test-access-token-valid',
                contentRepo: 'your-username/cpp-primer-content',
                trackingRepo: 'your-username/cpp-primer-tracking',
                branch: 'main'
            },
            limits: {
                maxDownloads: 10
            }
        };

        // Scenario 2: Expired License (License Required scenario - shows license is invalid)
        const expiredLicenseData = {
            id: crypto.randomUUID(),
            createdAt: new Date(Date.now() - 400 * 24 * 60 * 60 * 1000).toISOString(), // 400 days ago
            expiresAt: new Date(Date.now() - 35 * 24 * 60 * 60 * 1000).toISOString(), // 35 days ago
            contentPermissions: ['all_chapters'],
            gitee: {
                accessToken: 'test-access-token-expired',
                contentRepo: 'your-username/cpp-primer-content',
                trackingRepo: 'your-username/cpp-primer-tracking',
                branch: 'main'
            },
            limits: {
                maxDownloads: 5
            }
        };

        // Scenario 3: Invalid License (malformed data)
        const invalidLicenseData = {
            id: crypto.randomUUID(),
            createdAt: new Date().toISOString(),
            expiresAt: new Date(Date.now() + 365 * 24 * 60 * 60 * 1000).toISOString(),
            contentPermissions: ['all_chapters'],
            gitee: {
                accessToken: 'test-access-token-invalid',
                contentRepo: 'your-username/cpp-primer-content',
                trackingRepo: 'your-username/cpp-primer-tracking',
                branch: 'main'
            },
            limits: {
                maxDownloads: 5
            }
        };

        // Generate license keys
        const validLicenseKey = generateLicenseKey(validLicenseData, privateKey);
        const expiredLicenseKey = generateLicenseKey(expiredLicenseData, privateKey);
        
        // Create invalid license by corrupting the signature
        const invalidLicenseKey = generateLicenseKey(invalidLicenseData, privateKey);
        const corruptedInvalidLicenseKey = invalidLicenseKey.replace(/[a-zA-Z0-9]{10}$/, 'INVALID1234');

        // Save to files
        fs.writeFileSync(path.join(__dirname, 'test-license-valid.txt'), validLicenseKey);
        fs.writeFileSync(path.join(__dirname, 'test-license-expired.txt'), expiredLicenseKey);
        fs.writeFileSync(path.join(__dirname, 'test-license-invalid.txt'), corruptedInvalidLicenseKey);

        // Create a test guide
        const testGuide = `# Test Licenses for Manual Testing

## Three License Scenarios for Testing

### 1. License Paid Scenario (Valid License)
- **File**: test-license-valid.txt
- **Status**: Valid license for protected content
- **Expected Behavior**: Status bar shows "License Paid", clicking opens License Info page
- **Use Case**: User has purchased access to protected content

### 2. License Required Scenario (Expired License)
- **File**: test-license-expired.txt  
- **Status**: Expired license for protected content
- **Expected Behavior**: Status bar shows "License Required", clicking opens License Purchase page
- **Use Case**: User's license has expired, needs to renew

### 3. License Free Scenario (No License)
- **File**: test-license-invalid.txt
- **Status**: Invalid/malformed license
- **Expected Behavior**: Status bar shows "License Free" for free courses, "License Required" for protected courses
- **Use Case**: User has no valid license, accessing free content

## Testing Workflow

1. **Start with no licenses**: Remove all licenses from License Manager
2. **Test License Free scenario**: Select a free course (Python 3rd Edition, Java Fundamentals, Node.js Backend Development)
3. **Test License Required scenario**: Select a protected course (C++ Primer 5th Edition, JavaScript Complete Guide, React Complete Guide)
4. **Test License Paid scenario**: Add valid license and select protected course

## Course Catalog Reference

### Free Courses (License Free)
- Python 3rd Edition (Free)
- Java Fundamentals (Free)  
- Node.js Backend Development (Free)

### Protected Courses (License Required/Paid)
- C++ Primer 5th Edition (Protected)
- JavaScript Complete Guide (Protected)
- React Complete Guide (Protected)

## License Manager Usage

1. Open License Manager from the extension
2. Use "Remove All Licenses" to clear existing licenses
3. Copy license key from appropriate test file
4. Paste into license input field and click "Add License"
5. Verify status bar updates correctly

## Status Bar Behavior Summary

| Scenario | Course Type | Status Bar Text | Click Action |
|----------|-------------|-----------------|--------------|
| License Paid | Protected | $(check) License Paid | License Info Page |
| License Required | Protected | $(warning) License Required | License Purchase Page |
| License Free | Free | $(info) License Free | License Free Page |
`;

        fs.writeFileSync(path.join(__dirname, 'TESTING-GUIDE.md'), testGuide);

        console.log('✅ Generated test licenses for all three scenarios:');
        console.log('   - test-license-valid.txt (License Paid scenario)');
        console.log('   - test-license-expired.txt (License Required scenario)');
        console.log('   - test-license-invalid.txt (License Free scenario)');
        console.log('   - TESTING-GUIDE.md (Complete testing instructions)');
        console.log('\n📖 See TESTING-GUIDE.md for detailed testing workflow and scenarios.');
        
        return {
            valid: validLicenseKey,
            expired: expiredLicenseKey,
            invalid: corruptedInvalidLicenseKey
        };
    } catch (error) {
        console.error('Error generating test licenses:', error);
        return null;
    }
}

/**
 * Generate a license key from license data and private key
 */
function generateLicenseKey(licenseData, privateKey) {
    const dataString = JSON.stringify(licenseData);
    const dataBuffer = Buffer.from(dataString, 'utf8');
    const encodedData = dataBuffer.toString('base64');

    const signer = crypto.createSign('SHA256');
    signer.update(encodedData);
    signer.end();
    const signature = signer.sign(privateKey, 'base64');
    
    return `${encodedData}|${signature}`;
}

// Run if called directly
if (require.main === module) {
    generateTestLicenses();
}

module.exports = { generateTestLicenses };