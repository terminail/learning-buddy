# Learning Buddy Development Tools

This directory contains development tools to help developers create and test Learning Buddy extensions more efficiently.

## Overview

The development tools provide functionality for:
1. Generating test licenses for development and testing
2. Debugging license verification issues
3. Creating generic learning buddy extensions
4. Creating course-specific learning buddy extensions

## Tools Included

### 1. License Generation Tools
- `generate-test-license.js` - Generates cryptographically valid test licenses
- `create-test-license.js` - Alternative license generation script
- `test-license.txt` - Sample test license file

### 2. Extension Generation Tools
- `generate-extension.js` - Demonstrates how to generate both generic and course learning buddy extensions
- Uses the existing `build-custom-extension.js` script under the hood

## Usage Examples

### Generating Test Licenses
```bash
# Generate a test license
node generate-test-license.js

# Create a test license with custom parameters
node create-test-license.js
```

### Generating Generic Learning Buddy Extensions
```javascript
const { generateGenericExtension } = require('./generate-extension.js');

const config = {
  "name": "my-course-buddy",
  "displayName": "My Course Buddy",
  "description": "A custom learning buddy extension",
  "publisher": "my-learning-dev"
};

generateGenericExtension(config);
```

### Generating Course Learning Buddy Extensions
```javascript
const { generateCourseExtension } = require('./generate-extension.js');

const config = {
  "name": "python-data-science-buddy",
  "displayName": "Python Data Science Buddy",
  "description": "Learning buddy for Python Data Science course",
  "publisher": "data-science-dev",
  "course": {
    "defaultId": "python-data-science",
    "defaultName": "Python Data Science",
    "repository": "https://gitee.com/learning-buddy/python-data-science-course"
  }
  // ... additional course-specific configuration
};

generateCourseExtension(config);
```

### Using Example Configuration Files

The dev-tools directory includes example configuration files that you can use as templates:

- `example-generic-config.json` - Template for generic learning buddy extensions
- `example-course-config.json` - Template for course learning buddy extensions

You can copy and modify these files for your specific needs:

```bash
# Copy the example configuration
cp dev-tools/example-generic-config.json my-config.json

# Modify the configuration as needed
# Then use it to generate your extension
node build-custom-extension.js my-config.json
```

## Prerequisites

- Node.js 16.x or higher
- npm 8.x or higher
- VS Code Extension Manager (vsce) installed globally:
  ```bash
  npm install -g vsce
  ```

## Development Workflow

1. Create a configuration file for your extension (JSON format)
2. Use the development tools to generate the extension
3. Test the generated VSIX file in VS Code
4. Debug any issues using the debugging utilities
5. Iterate as needed

## Configuration File Formats

### Generic Learning Buddy Configuration
```json
{
  "name": "extension-name",
  "displayName": "Extension Display Name",
  "description": "Extension description",
  "publisher": "publisher-name"
}
```

### Course Learning Buddy Configuration
```json
{
  "name": "course-buddy-name",
  "displayName": "Course Buddy Display Name",
  "description": "Course buddy description",
  "publisher": "publisher-name",
  "course": {
    "defaultId": "course-id",
    "defaultName": "Course Name",
    "repository": "https://gitee.com/learning-buddy/course-repo"
  },
  "branding": {
    "primaryColor": "#3776ab",
    "promotionalBanner": "icons/banner.png"
  }
}
```

## Troubleshooting

### Common Issues

1. **VSIX packaging fails**
   - Ensure vsce is installed globally
   - Check that all required fields are present in the configuration

2. **Extension doesn't load correctly**
   - Verify that the configuration file is valid JSON
   - Check that all referenced files (icons, etc.) exist

3. **License verification issues**
   - Use the debugging tools to trace the verification process
   - Ensure the test license was generated with the correct private key

### Getting Help

For issues with the development tools, please:
1. Check the console output for error messages
2. Verify your configuration files are valid
3. Ensure all prerequisites are installed
4. Consult the main project documentation