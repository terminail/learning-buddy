# Generic Learning Buddy Extension

The Generic Learning Buddy extension is a VS Code extension that supports multiple programming courses through a single installation. Unlike course-specific extensions, it allows users to switch between different courses without installing new extensions.

## Features

1. Support multiple courses with a single installation
2. Switch between different courses without installing new extensions
3. Visual directory tree interface for navigating course materials
4. Automatic copying of exercise files to your working directory
5. Direct access to solutions and hints for exercises
6. License-based access control for protected content
7. Integration with WeChat for license management and instructor contact
8. Multi-course support with promotional positions for other courses

## Getting Started

1. Install the Generic Learning Buddy extension from the VS Code Marketplace
2. Open the extension panel in VS Code
3. Browse the default course大纲 (outline) in the tree view
4. At the bottom of the大纲, you'll see promotional positions for other courses
5. Clicking on a promotional course shows more information about that course
6. Clicking on a promotional course allows you to view that course's content within the same extension
7. The extension will restore to its default course when VS Code is restarted

## Course Switching

The Generic Learning Buddy extension supports switching between courses:

- Users can switch between different courses without installing new extensions
- The extension remembers the current course during the same VS Code session
- When VS Code is restarted, the extension restores to its default course
- All existing functionality (license management, WeChat integration, etc.) works correctly when switching courses

## Usage

### Navigating Course Materials

The extension presents a tree view of the course大纲 (outline) with chapters and exercises. Protected content (marked with a lock icon) requires a valid license to access.

### Working with Exercises

1. Click on any exercise in the tree view to copy it to your working directory
2. The extension will prompt you to select or create a working directory if one isn't already set
3. The exercise file will be opened automatically in the editor

### Accessing Solutions and Hints

- Right-click on any exercise to view options for checking your solution, viewing the solution, or getting a hint
- For protected content, these features may require a valid license

### License Management

- Protected content requires a valid license to access
- Licenses can be managed through the License Manager (accessible via the command palette)
- Contact the instructor through WeChat for license inquiries

### Multi-Course Support

The extension supports multiple courses with the following features:

- At the bottom of the course大纲, you'll see promotional positions for other courses
- Clicking on a promotional course allows you to view that course's content within the same extension
- The extension remembers your course selection during the same VS Code session
- When VS Code is restarted, the extension restores to its default course

## Development

### Prerequisites

- Node.js 16.x or higher
- npm 8.x or higher
- VS Code 1.100.0 or higher

### Building the Extension

1. Clone the repository
2. Run `npm install` to install dependencies
3. Run `npm run compile` to compile TypeScript files
4. Run `npm run package` to create a VSIX package

### Custom Course Extensions

To create a custom course extension:

1. Use the `generate-extension.js` script to create a new extension
2. Configure the course details in the extension manifest
3. Package the extension with `npm run package-extension`

Note: Course-specific extensions do not support course switching. They focus on providing content for their specific course and promote the generic Learning Buddy extension for multi-course access.

### Course Structure Validation

Use the `validate-course.js` script to validate course structure files:

```bash
npm run validate-course -- path/to/course-structure.json
```

### License Generation

For development purposes, you can generate test licenses:

```bash
npm run generate-license
```

## Testing

To ensure quality, test the following scenarios:

1. **Install and basic functionality**: Verify that the extension installs correctly and displays the default course大纲
2. **Exercise copying**: Test that exercises can be copied to the working directory and opened in the editor
3. **Solution and hint access**: Verify that solutions and hints can be accessed for both free and protected content
4. **License management**: Test that license management works correctly for protected content
5. **WeChat integration**: Verify that WeChat integration works for license management and instructor contact
6. **Course switching**: Verify that users can switch between courses within the same extension
7. **Session persistence**: Verify that the current course is remembered during the same VS Code session
8. **Default course restoration**: Verify that the extension restores to its default course when VS Code is restarted
9. **Promotional positioning**: Use appropriate promotional positioning to place promotional courses where they're easily discoverable but don't interfere with the main learning content
10. **Multi-course functionality**: Test all multi-course features work correctly
11. **Content protection**: Ensure that protected content is properly protected and only accessible with valid licenses

## Contributing

Contributions are welcome! Please read the contributing guidelines before submitting pull requests.

## License

This project is licensed under the ISC License - see the LICENSE.md file for details.

## Support

For support, contact the instructor through WeChat or open an issue on the GitHub repository.