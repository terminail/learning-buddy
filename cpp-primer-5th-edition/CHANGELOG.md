# Change Log

All notable changes to the C++ Primer 5th Edition Buddy extension will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Changed
- Further optimized extension packaging to exclude build artifacts
- Reduced package size to 1.19MB

### Added
- Included build and run examples with detailed logs in exercises for enhanced learning experience

### Fixed
- Moved extension icon to media folder and updated README.md image path for proper display on Open VSX marketplace
- Added icon property to package.json to properly display extension icon in marketplace
- Replaced large extension icon with properly sized 512x512 icon for better marketplace display

## [0.0.1] - 2025-11-28

### Added
- Initial release of C++ Primer 5th Edition Buddy extension
- Tree view navigation for all chapters and exercises from the C++ Primer 5th Edition book
- Read-only file viewing for example code and exercise instructions
- Download workspace feature to copy chapters to a user-defined location
- Configurable download path setting in VS Code settings
- Bidirectional sync between tree view download path selection and VS Code settings
- Truly read-only mode for files with CSS user-select prevention
- Build and run examples with detailed logs for hands-on learning experience

### Changed
- Improved file opening to show original filenames without prefixes
- Enhanced tree view with better organization and visual separation
- Optimized extension packaging to exclude unnecessary build directories and compiled executables
- Reduced package size from over 145MB to just 1.19MB by excluding build artifacts

### Fixed
- Command registration issues preventing file opening
- Permission errors with temporary file creation
- Text selection issues in read-only files