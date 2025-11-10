# License Instructions

## For Development and Testing

Test licenses have been generated for all three license scenarios and saved to separate files in this directory.

### Three License Scenarios for Testing

The extension now supports three distinct license scenarios that are automatically detected based on course content and license status:

#### 1. License Paid Scenario (Valid License)
- **Status**: Valid license for protected content
- **Files**: `test-license-valid.txt`
- **Expected Behavior**: Status bar shows "$(check) License Paid", clicking opens License Info page
- **Use Case**: User has purchased access to protected content

#### 2. License Required Scenario (Expired/Invalid License)
- **Status**: Expired or invalid license for protected content
- **Files**: `test-license-expired.txt`, `test-license-invalid.txt`
- **Expected Behavior**: Status bar shows "$(warning) License Required", clicking opens License Purchase page
- **Use Case**: User's license has expired or is invalid, needs to renew

#### 3. License Free Scenario (No License Needed)
- **Status**: Free course content, no license required
- **Files**: No license needed
- **Expected Behavior**: Status bar shows "$(info) License Free", clicking opens License Free page
- **Use Case**: User is accessing free content that doesn't require a license

### Complete Testing Workflow

#### Step 1: Prepare the Environment
1. Open Visual Studio Code
2. Install the extension (if not already installed):
   - Go to Extensions (Ctrl+Shift+X)
   - Click on the "..." menu and select "Install from VSIX"
   - Select the `learning-primer-buddy-0.0.1.vsix` file

#### Step 2: Test License Free Scenario
1. Open the Course Catalog from the C++ Primer Buddy panel
2. Select a free course (Python 3rd Edition, Java Fundamentals, or Node.js Backend Development)
3. Verify the status bar shows "License Free"
4. Click the status bar - should open the License Free page

#### Step 3: Test License Required Scenario
1. Open the Course Catalog
2. Select a protected course (C++ Primer 5th Edition, JavaScript Complete Guide, or React Complete Guide)
3. Verify the status bar shows "License Required" (no valid license)
4. Click the status bar - should open the License Purchase page

#### Step 4: Test License Paid Scenario
1. Open the License Manager from the C++ Primer Buddy panel
2. Copy the license key from `test-license-valid.txt`
3. Paste the license key into the license input field and click "Add License"
4. Select a protected course from the Course Catalog
5. Verify the status bar shows "License Paid"
6. Click the status bar - should open the License Info page

### Course Catalog Reference

#### Free Courses (License Free)
- Python 3rd Edition (Free)
- Java Fundamentals (Free)  
- Node.js Backend Development (Free)

#### Protected Courses (License Required/Paid)
- C++ Primer 5th Edition (Protected)
- JavaScript Complete Guide (Protected)
- React Complete Guide (Protected)

### To generate new test licenses:

Run the following command in your terminal:

```
node generate-test-licenses.js
```

This will generate licenses for all three scenarios and save them to separate files, plus create a comprehensive testing guide.

## For End Users

End users should:

1. Scan the WeChat QR code in the extension
2. Contact the instructor to purchase access
3. Receive their license key via WeChat
4. Enter their license key in the License Manager