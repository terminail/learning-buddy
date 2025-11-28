# Change Log

All notable changes to the Python Crash Course 3rd Edition Buddy extension will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.0.1] - 2025-11-28

### Added
- Initial release of Python Crash Course 3rd Edition Buddy extension
- Tree view navigation for chapters and exercises from the Python Crash Course 3rd Edition book
- Read-only file viewing for example code and exercise instructions
- Download workspace feature to copy chapters to a user-defined location
- Configurable download path setting in VS Code settings
- Bidirectional sync between tree view download path selection and VS Code settings
- Truly read-only mode for files with CSS user-select prevention

### Changed
- Improved file opening to show original filenames without prefixes
- Enhanced tree view with better organization and visual separation
- Optimized extension packaging to exclude unnecessary files
- Updated README.md with proper formatting and image reference

### Fixed
- Command registration issues preventing file opening
- Permission errors with temporary file creation
- Text selection issues in read-only files
- Corrected .gitignore configuration to properly track extension files