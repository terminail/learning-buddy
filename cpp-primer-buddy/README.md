# Learning Buddy

Learning Buddy is a VS Code extension that helps learners navigate programming course materials through a visual directory tree interface. Originally designed for C++ Primer 5th Edition, it has been upgraded to support multiple courses through a generic architecture.

## Features

- Visual directory tree interface for navigating course materials
- Automatic copying of exercise files to your working directory
- Direct access to solutions and hints for exercises
- License-based access control for protected content
- Integration with WeChat for license management and instructor contact
- Multi-course support with promotional positions for other courses

## Course-Specific vs Generic Extensions

There are two types of Learning Buddy extensions:

1. **Course-Specific Extensions** (e.g., "C++ Primer 5th Edition Buddy"):
   - Focus on a single course
   - Provide immediate access to that course's materials
   - Do not support switching between courses
   - Promote the generic Learning Buddy extension for multi-course access

2. **Generic Learning Buddy Extension**:
   - Supports multiple courses
   - Allows switching between different courses within the same extension
   - Shows promotional positions for other courses
   - Clicking on a promotional course allows you to view that course's content within the same extension

## Getting Started

### For Course-Specific Extensions

1. Install the course-specific extension from the VS Code Marketplace (e.g., "C++ Primer 5th Edition Buddy")
2. Open the extension panel in VS Code
3. Browse the course大纲 (outline) in the tree view
4. Click on any exercise to copy it to your working directory
5. To access other courses, click on the "Discover More Courses" promotional item and install the generic Learning Buddy extension

### For Generic Learning Buddy Extension

1. Install the generic Learning Buddy extension from the VS Code Marketplace
2. Open the extension panel in VS Code
3. Browse the default course大纲 (outline) in the tree view
4. At the bottom of the大纲, you'll see promotional positions for other courses
5. Clicking on a promotional course allows you to view that course's content within the same extension
6. The extension will restore to its default course when VS Code is restarted

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

The generic Learning Buddy extension supports multiple courses with the following features:

- At the bottom of the course大纲, you'll see promotional positions for other courses
- Clicking on a promotional course allows you to view that course's content within the same extension
- The extension remembers your course selection during the same VS Code session
- When VS Code is restarted, the extension restores to its default course

## Requirements

- VS Code 1.100.0 or higher
- Node.js 16.x or higher
- Internet connection for accessing remote content and license verification
- WeChat for license management and instructor contact

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

## Contributing

Contributions are welcome! Please read the contributing guidelines before submitting pull requests.

## License

This project is licensed under the ISC License - see the LICENSE.md file for details.

## Support

For support, contact the instructor through WeChat or open an issue on the GitHub repository.
