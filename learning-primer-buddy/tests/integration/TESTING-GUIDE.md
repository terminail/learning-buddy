# Test Licenses for Manual Testing

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

### 3. License Required Scenario (No License)
- **File**: No license file needed (start with no licenses)
- **Status**: No license present for protected content
- **Expected Behavior**: Status bar shows "License Required", clicking opens License Purchase page
- **Use Case**: User clicks on protected course without having any license

### 4. License Free Scenario (Invalid License)
- **File**: test-license-invalid.txt
- **Status**: Invalid/malformed license
- **Expected Behavior**: Status bar shows "License Free" for free courses, "License Required" for protected courses
- **Use Case**: User has invalid license, accessing free content

## Testing Workflow

1. **Start with no licenses**: Remove all licenses from License Manager
2. **Test License Required (No License) scenario**: Select a protected course (C++ Primer 5th Edition, JavaScript Complete Guide, React Complete Guide) - should show "License Required"
3. **Test License Free scenario**: Select a free course (Python 3rd Edition, Java Fundamentals, Node.js Backend Development) - should show "License Free"
4. **Test License Required (Invalid License) scenario**: Add invalid license and select protected course - should show "License Required"
5. **Test License Paid scenario**: Add valid license and select protected course - should show "License Paid"

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
| License Required (No License) | Protected | $(warning) License Required | License Purchase Page |
| License Required (Invalid/Expired) | Protected | $(warning) License Required | License Purchase Page |
| License Free | Free | $(info) License Free | License Free Page |
