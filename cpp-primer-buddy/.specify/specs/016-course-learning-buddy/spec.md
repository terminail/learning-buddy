# Feature Specification: Course Learning Buddy Building

**Feature Branch**: `019-course-learning-buddy`  
**Created**: 2025-11-07  
**Status**: Draft  
**Input**: User description: "Need explicit feature spec about building extension for specific course e.g. C++ Primer 5th Edition Buddy"

**See Also**: [Course Structure Tool specification](../018-course-structure-tool/spec.md) for details on validating and generating course structure files.

## Implementation Summary

This feature defines the process and requirements for building course-specific Learning Buddy extensions, such as "C++ Primer 5th Edition Buddy". Each Course Learning Buddy is built from the generic Learning Buddy codebase using a course-specific configuration that customizes the extension's metadata, default course content, and branding.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Build Course Learning Buddy (Priority: P1)

As a course creator, I want to build a Course Learning Buddy (e.g., "C++ Primer 5th Edition Buddy") so that my students can easily identify and install the extension for my course.

**Why this priority**: This is the core functionality for creating recognizable, course-branded extensions.

**Independent Test**: Can be fully tested by running the build process with a course-specific configuration and verifying that the resulting VSIX file has the correct metadata.

**Acceptance Scenarios**:

1. **Given** a C++ Primer 5th Edition configuration, **When** the build process is executed, **Then** a VSIX file should be created with "C++ Primer 5th Edition Buddy" as the extension name.
2. **Given** a Python 3rd Edition configuration, **When** the build process is executed, **Then** a VSIX file should be created with "Python 3rd Edition Buddy" as the extension name.

### User Story 2 - Install and Use Course Learning Buddy (Priority: P1)

As a student, I want to install a Course Learning Buddy and immediately see the content for that course so that I can begin learning without additional configuration.

**Why this priority**: This is essential for providing a seamless user experience with course-specific extensions.

**Independent Test**: Can be fully tested by installing a Course Learning Buddy and verifying that it displays the correct default course content.

**Acceptance Scenarios**:

1. **Given** a "C++ Primer 5th Edition Buddy" extension installation, **When** the extension is opened, **Then** the C++ Primer 5th Edition大纲 should be displayed by default.
2. **Given** a "Python 3rd Edition Buddy" extension installation, **When** the extension is opened, **Then** the Python 3rd Edition大纲 should be displayed by default.

### User Story 3 - Access Course Content Without Additional Configuration (Priority: P1)

As a student using a Course Learning Buddy, I want to access the course content immediately without needing to configure repository URLs or other settings so that I can focus on learning.

**Why this priority**: This is essential for providing a seamless out-of-the-box experience.

**Independent Test**: Can be fully tested by installing a Course Learning Buddy and verifying that all content is accessible without additional configuration.

**Acceptance Scenarios**:

1. **Given** a Course Learning Buddy installation, **When** the extension is activated, **Then** it should automatically load content from the pre-configured repository.
2. **Given** a Course Learning Buddy with protected content, **When** I access that content with a valid license, **Then** it should be delivered through the Docker environment without additional setup.

### User Story 4 - Maintain Course Learning Buddy Branding (Priority: P1)

As a course creator, I want my Course Learning Buddy to maintain consistent branding (name, description, icon) so that students can easily identify it in the VS Code marketplace and extension panel.

**Why this priority**: This is essential for course recognition and professional presentation.

**Independent Test**: Can be fully tested by examining the extension metadata in the VSIX file and VS Code marketplace.

**Acceptance Scenarios**:

1. **Given** a C++ Primer 5th Edition Buddy VSIX file, **When** it is examined, **Then** it should contain "C++ Primer 5th Edition Buddy" as the extension name.
2. **Given** a Course Learning Buddy installed in VS Code, **When** it is viewed in the extension panel, **Then** it should display the correct course-specific name and description.

### User Story 5 - Support Multi-Course Discovery (Priority: P2)

As a student using a Course Learning Buddy, I want to discover and switch to other courses so that I can explore additional learning materials.

**Why this priority**: This enhances the learning experience by enabling course discovery.

**Independent Test**: Can be tested by installing a Course Learning Buddy and verifying that promotional positions for other courses are displayed.

**Acceptance Scenarios**:

1. **Given** a Course Learning Buddy, **When** I view the course大纲, **Then** I should see promotional positions for other courses at the bottom.
2. **Given** promotional course positions, **When** I click on one, **Then** I should be able to switch to that course within the same extension instance.

### User Story 6 - Preserve Existing Functionality (Priority: P2)

As a current user of a Course Learning Buddy, I want all existing Learning Buddy functionality to work correctly so that my learning experience is not disrupted.

**Why this priority**: This ensures backward compatibility and maintains user trust.

**Independent Test**: Can be tested by running a Course Learning Buddy and verifying that all existing features work correctly.

**Acceptance Scenarios**:

1. **Given** a Course Learning Buddy, **When** I access protected content with a valid license, **Then** the license management system should work correctly.
2. **Given** a Course Learning Buddy, **When** I use the WeChat integration, **Then** it should function as expected.

### Edge Cases

- What happens when the Course Learning Buddy configuration is missing or malformed?
- How does the system handle courses with missing or invalid repository URLs?
- What happens when a Course Learning Buddy is built with an invalid Dockerfile?
- How does the system handle very large course content in Course Learning Buddy?
- What happens when a Course Learning Buddy references a non-existent course structure?
- How does the system handle network connectivity issues during Course Learning Buddy activation?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST support building Course Learning Buddy with custom names, descriptions, and icons
- **FR-002**: System MUST embed course-specific repository URLs in the extension metadata during build
- **FR-003**: System MUST set the default course for Course Learning Buddy based on configuration
- **FR-004**: System MUST generate VSIX packages with course-specific branding and metadata
- **FR-005**: System MUST provide clear error messages for invalid Course Learning Buddy configurations
- **FR-006**: System SHOULD support command-line parameters for Course Learning Buddy build overrides
- **FR-007**: System SHOULD validate Course Learning Buddy configurations before building
- **FR-008**: System MUST allow Course Learning Buddy configuration through JSON files
- **FR-009**: System MUST preserve all existing Learning Buddy functionality in Course Learning Buddy
- **FR-010**: System MUST support course-specific chapter protection configurations
- **FR-011**: System MUST automatically load course content from pre-configured repositories
- **FR-012**: System MUST support course-specific Dockerfiles for development environment configuration
- **FR-013**: System MUST validate that Course Learning Buddy repositories follow the required structure
- **FR-014**: System MUST support multi-course discovery in Course Learning Buddy
- **FR-015**: System SHOULD provide templates for common Course Learning Buddy configurations
- **FR-016**: System SHOULD support versioning for Course Learning Buddy
- **FR-017**: System MUST ensure Course Learning Buddy can be updated without losing user data
- **FR-018**: System MUST handle Course Learning Buddy updates gracefully

### Course Learning Buddy Structure

Each Course Learning Buddy MUST follow this structure:

```
course-learning-buddy/
├── package.json              # Extension manifest with course-specific metadata
├── course-config.json        # Course-specific configuration (embedded during build)
├── icons/                    # Course-specific icons
│   ├── extension-icon.png
│   └── promotional-banner.png
├── src/                      # Generic Learning Buddy source code
└── out/                      # Compiled JavaScript output
```

### Course Learning Buddy Configuration Format

Course Learning Buddy MUST use this JSON configuration format:

```json
{
  "extension": {
    "name": "Course Name Buddy",
    "displayName": "Course Name Buddy",
    "description": "Learning Buddy extension for Course Name",
    "icon": "icons/extension-icon.png"
  },
  "course": {
    "defaultId": "course-identifier",
    "defaultName": "Course Name",
    "repository": "https://gitee.com/username/course-repo",
    "dockerfile": "Dockerfile"
  },
  "branding": {
    "primaryColor": "#3498db",
    "promotionalBanner": "icons/promotional-banner.png"
  }
}
```

### Key Entities

- **CourseLearningBuddyBuilder**: Handles the building process for Course Learning Buddy
- **CourseLearningBuddyConfig**: Contains course-specific configuration parameters
- **ExtensionMetadata**: Course Learning Buddy metadata (name, description, icons)
- **CourseRepository**: Pre-configured repository for Course Learning Buddy content
- **CourseBranding**: Course-specific visual branding elements
- **BuildSystem**: Handles the packaging process with Course Learning Buddy configurations

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Course Learning Buddy can be built with unique names and descriptions in 100% of cases
- **SC-002**: Built extensions correctly display Course Learning Buddy metadata in VS Code marketplace
- **SC-003**: Course Learning Buddy automatically load the correct default course content in 100% of cases
- **SC-004**: Course Learning Buddy preserve all existing Learning Buddy functionality
- **SC-005**: Configuration validation catches errors in 99% of invalid Course Learning Buddy configuration cases
- **SC-006**: Course Learning Buddy can be successfully installed and used in VS Code
- **SC-007**: Course content is loaded dynamically from pre-configured repositories in 95% of cases with network connectivity
- **SC-008**: Course Learning Buddy display correct branding in VS Code extension panel in 100% of cases
- **SC-009**: Multi-course discovery works correctly in Course Learning Buddy in 99% of cases
- **SC-010**: Course Learning Buddy can be updated without losing user data in 100% of cases
- **SC-011**: Course Learning Buddy repositories following the required structure are validated successfully in 95% of cases
