# Feature Specification: Generic Learning Buddy

**Feature Branch**: `011-generic-learning-buddy`  
**Created**: 2025-11-07  
**Status**: Draft  
**Input**: User description: "Upgrade C++ Primer Buddy to a generic Learning Buddy that can be customized for different books/courses. For example, it should be possible to specify a name, description, and exercise repository URL to build a specific extension."

**See Also**: 
- [Course Catalog Structure specification](./016-course-catalog/spec.md) for details on catalog and repository structure requirements for multi-course support.
- [Course Learning Buddy Building specification](../019-course-learning-buddy/spec.md) for details on building course-specific extensions like "C++ Primer 5th Edition Buddy".
- [Course Validation Tool specification](./018-course-validation-tool/spec.md) for details on validating course repository compliance.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Customize Extension Configuration (Priority: P1)

As a course creator, I want to customize the extension with a specific name, description, and repository URL so that I can create a tailored learning experience for my students.

**Why this priority**: This is the core functionality for making the extension generic and reusable for different courses.

**Independent Test**: Can be fully tested by creating a configuration file with custom values and verifying that the extension uses those values when building and packaging.

**Acceptance Scenarios**:

1. **Given** a configuration file with custom name, description, and repository URL, **When** the extension is built, **Then** the packaged extension should use those values in its metadata.
2. **Given** a default configuration, **When** no custom values are provided, **Then** the extension should build with default values (C++ Primer 5th Edition).

---

### User Story 2 - Build Custom Extension Package (Priority: P1)

As a course creator, I want to build a custom extension package with my course-specific configuration so that I can distribute it to my students through the VS Code marketplace.

**Why this priority**: This is essential for the distribution of customized learning experiences.

**Independent Test**: Can be fully tested by running the build process with a custom configuration and verifying that a properly configured VSIX file is created.

**Acceptance Scenarios**:

1. **Given** a custom configuration file, **When** the build process is executed, **Then** a VSIX file should be created with the custom name and metadata.
2. **Given** a built custom extension, **When** it is installed in VS Code, **Then** it should display the custom name and description in the marketplace and UI.

---

### User Story 3 - Load Dynamic Course Structure (Priority: P1)

As a course creator, I want the Learning Buddy to load the course structure dynamically from a Gitee repository so that I can update the course content and structure without requiring users to reinstall the extension.

**Why this priority**: This is essential for maintaining course content without requiring extension rebuilds.

**Independent Test**: Can be fully tested by updating the course structure in the Gitee repository and verifying that the extension loads the updated structure when opened.

**Acceptance Scenarios**:

1. **Given** a course structure file in the Gitee repository, **When** a user opens the Learning Buddy extension, **Then** the extension should load and display the course structure from the repository.
2. **Given** an updated course structure in the Gitee repository, **When** a user refreshes the Learning Buddy view, **Then** the extension should load and display the updated structure.

---

### User Story 4 - Support Multiple Courses Within Same Extension (Priority: P1)

As a learner using a specific Learning Buddy extension, I want to see the default course outline for that extension and be able to switch to other courses without installing new extensions, with the extension restoring to its default course on restart.

**Why this priority**: This is essential for creating a comprehensive learning platform without extension proliferation.

**Independent Test**: Can be fully tested by installing a specific Learning Buddy extension, switching to other courses, and verifying that the extension restores to its default course on restart.

**Acceptance Scenarios**:

1. **Given** a "C++ Primer 5th Buddy" extension installation, **When** the extension is opened, **Then** the C++ Primer 5th Edition outline should be displayed by default.
2. **Given** promotional course positions, **When** the user clicks on one, **Then** the outline for that course should be loaded within the same extension.
3. **Given** a user who has switched courses, **When** they restart VS Code, **Then** the extension should restore to its default course outline.

---

### User Story 5 - Deliver Content Through Podman Environment (Priority: P1)

As a course creator, I want protected content to be delivered directly to a secure Podman development environment so that learning materials are protected from unauthorized copying.

**Why this priority**: This is essential for content protection - all protected materials must be stored within Podman containers rather than on the host filesystem.

**Independent Test**: Can be fully tested by accessing protected content and verifying that files are downloaded directly into the Podman container rather than the host filesystem.

**Acceptance Scenarios**:

1. **Given** a user with valid license access, **When** they access protected content, **Then** the Podman container should handle downloading materials directly from Gitee or other sources.
2. **Given** downloaded content in the container, **When** a user tries to access files from the host system, **Then** they should not find the protected materials.

---

### User Story 6 - Provide Course-Specific Development Environments (Priority: P1)

As a course creator, I want my course to provide a Podmanfile that defines the specific development environment needed for my course's exercises so that learners can automatically get the right tools without manual setup.

**Why this priority**: This is essential for ensuring learners have the right environment for course exercises.

**Independent Test**: Can be fully tested by providing a Podmanfile with course and verifying that learners get the appropriate development environment.

**Acceptance Scenarios**:

1. **Given** a course with a Podmanfile specifying C++ compiler requirements, **When** a learner accesses the course, **Then** the Podman environment should contain the correct C++ compiler.
2. **Given** a course with a Podmanfile specifying Python dependencies, **When** a learner accesses the course, **Then** the Podman environment should contain the required Python libraries.
3. **Given** a course without a Podmanfile, **When** a learner accesses the course, **Then** the extension should provide a default development environment.

---

### User Story 7 - Support Multiple Content Sources (Priority: P2)

As a course creator, I want the extension to support different content sources (GitHub, Gitee, local files) so that I can choose the most appropriate hosting solution for my content.

**Why this priority**: This enhances flexibility but is not core to the main functionality.

**Independent Test**: Can be tested by configuring different content sources and verifying that the extension can access content from each.

**Acceptance Scenarios**:

1. **Given** a configuration with a GitHub repository URL, **When** the extension tries to access content, **Then** it should successfully fetch content from GitHub.
2. **Given** a configuration with a Gitee repository URL, **When** the extension tries to access content, **Then** it should successfully fetch content from Gitee.

---

### User Story 8 - Maintain Backward Compatibility (Priority: P2)

As a current user of C++ Primer Buddy, I want the upgrade to maintain backward compatibility so that my existing setup continues to work without changes.

**Why this priority**: This ensures existing users are not disrupted by the upgrade.

**Independent Test**: Can be tested by running the upgraded extension with existing configurations and verifying that it behaves the same as before.

**Acceptance Scenarios**:

1. **Given** an existing C++ Primer Buddy installation, **When** the generic version is installed, **Then** all existing functionality should continue to work.
2. **Given** no custom configuration, **When** the extension is built, **Then** it should default to C++ Primer 5th Edition behavior.

---

### User Story 9 - Implement Secure Caching Policy (Priority: P1)

As a course creator and learner, I want the extension to implement a secure caching policy that caches only non-protected metadata locally while delivering protected content directly to Podman containers so that content remains secure.

**Why this priority**: This is essential for maintaining content security while providing good performance.

**Independent Test**: Can be tested by accessing both protected and non-protected content and verifying that only metadata is cached locally.

**Acceptance Scenarios**:

1. **Given** a user accessing course content, **When** the extension loads course structures, **Then** only metadata should be cached locally.
2. **Given** a user accessing protected content, **When** the extension delivers content, **Then** it should be delivered directly to Podman containers without caching on the host.
3. **Given** cached metadata, **When** the user goes offline, **Then** they should still be able to access previously loaded course outlines.

---

### Edge Cases

- What happens when the configuration file is missing or malformed?
- How does the system handle unsupported content repository types?
- What happens when the specified repository URL is invalid or inaccessible?
- How does the system handle very large configuration files?
- What happens when the course structure file in the repository is missing or malformed?
- How does the system handle network connectivity issues when loading course structure?
- What happens when the course catalog is unavailable?
- How does the system handle very large numbers of courses?
- What happens when Podman is not installed on the user's system?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST support custom configuration of extension name, description, and content repository URL
- **FR-002**: System MUST build VSIX packages with custom metadata based on configuration
- **FR-003**: System MUST support multiple content source types (GitHub, Gitee, local)
- **FR-004**: System MUST maintain backward compatibility with existing C++ Primer Buddy installations
- **FR-005**: System MUST provide clear error messages for invalid configurations
- **FR-006**: System SHOULD support command-line parameters for configuration overrides
- **FR-007**: System SHOULD validate configuration files before building
- **FR-008**: System MUST allow configuration through a JSON file
- **FR-009**: System MUST default to C++ Primer 5th Edition when no custom configuration is provided
- **FR-010**: System MUST support chapter-level protection configuration
- **FR-011**: System MUST preserve all existing functionality (license management, WeChat integration, etc.)
- **FR-012**: System MUST load course structure dynamically from the configured repository on extension activation
- **FR-013**: System MUST support a refresh mechanism to reload course structure from the repository
- **FR-014**: System MUST NOT cache protected content on the host filesystem
- **FR-015**: System MUST deliver protected content directly to the Podman development environment through container-based downloaders
- **FR-016**: System MAY cache non-protected metadata (course structures, catalogs, Podmanfiles) locally for performance (Podman images are managed by Podman daemon)
- **FR-017**: System MUST display the outline for the specific course associated with the extension by default
- **FR-018**: System MUST show promotional positions for other courses at the bottom of the outline
- **FR-019**: System MUST allow users to switch to different courses within the same extension instance
- **FR-020**: System MUST restore the default course outline when VS Code is restarted
- **FR-021**: System MUST NOT require installation of new extensions for course switching
- **FR-022**: System MUST integrate with VS Code Dev Containers for seamless access to Podman environment
- **FR-023**: System MUST clearly distinguish between cached metadata and protected content in its implementation
- **FR-024**: System MUST ensure that cached metadata does not contain any protected content
- **FR-025**: System MUST support course-specific Podmanfiles for development environment configuration
- **FR-026**: System MUST automatically build Podman environments from course-provided Podmanfiles
- **FR-027**: System MUST provide fallback to default development environment when course Podmanfiles are unavailable
- **FR-028**: System MUST validate course Podmanfiles for correctness and security
- **FR-029**: System MUST support course catalogs following the standardized catalog structure
- **FR-030**: System MUST validate that course repositories follow the required structure as defined in the course catalog specification
- **FR-031**: System SHOULD provide a validation tool for course creators to check repository compliance

### Key Entities

- **Configuration**: Contains customization parameters for the extension (name, description, repository URL)
- **BuildSystem**: Handles the packaging process with custom configurations
- **ContentSource**: Represents different types of content repositories (GitHub, Gitee, local)
- **ExtensionMetadata**: Metadata that will be embedded in the VSIX package
- **ChapterDefinition**: Defines the structure and properties of learning chapters
- **CourseStructure**: Represents the dynamic course structure loaded from the repository
- **StructureLoader**: Component responsible for loading course structure from remote repositories
- **CourseCatalog**: Collection of all available courses with their metadata following the standardized catalog structure
- **PromotionalPosition**: Display position for promoting other courses
- **PodmanEnvironmentManager**: Manages Podman container for secure content delivery
- **MetadataCache**: Manages caching of non-protected course metadata for performance
- **ContentDeliveryManager**: Ensures protected content is delivered directly to Podman containers without host caching
- **PodmanfileManager**: Manages downloading and caching of course-specific Podmanfiles
- **EnvironmentBuilder**: Handles building Podman environments from course-specific Podmanfiles
- **PodmanfileValidator**: Validates Podmanfiles for correctness and security

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Custom extensions can be built with unique names and descriptions in 100% of cases
- **SC-002**: Built extensions correctly display custom metadata in VS Code marketplace
- **SC-003**: Extensions support multiple content source types with 95% success rate
- **SC-004**: Backward compatibility is maintained for existing C++ Primer Buddy installations
- **SC-005**: Configuration validation catches errors in 99% of invalid configuration cases
- **SC-006**: All existing features (license management, WeChat integration) work in custom extensions
- **SC-007**: Custom extensions can be successfully installed and used in VS Code
- **SC-008**: Course structure is loaded dynamically from Gitee repository in 95% of cases with network connectivity
- **SC-009**: Course structure refresh works correctly in 100% of cases
- **SC-010**: Error handling for missing/malformed course structure files works in 99% of cases
- **SC-011**: Default course outline is displayed correctly in 100% of cases
- **SC-012**: Promotional positions for other courses are displayed in 100% of cases
- **SC-013**: Course switching works correctly within the same extension in 99% of cases
- **SC-014**: Extension restores to default course on VS Code restart in 100% of cases
- **SC-015**: No new extension installation is required for course switching
- **SC-016**: Protected content is not accessible from the host filesystem in 100% of cases
- **SC-017**: 90% of users can successfully access content through VS Code Dev Containers
- **SC-018**: Non-protected metadata may be cached locally for performance
- **SC-019**: Protected content is never cached on the host filesystem in 100% of cases
- **SC-020**: Cached metadata does not contain any protected content in 100% of cases
- **SC-021**: Course-specific Podmanfiles are downloaded successfully in 95% of cases
- **SC-022**: Course-specific development environments are built and initialized in 90% of cases
- **SC-023**: Default development environments are provided as fallback in 99% of cases when Podmanfiles are unavailable
- **SC-024**: Podmanfile validation provides clear error messages in 95% of error cases
- **SC-025**: Course catalogs following the standardized structure are loaded successfully in 95% of cases
- **SC-026**: Course repositories following the required structure are validated successfully in 95% of cases
- **SC-027**: Course repository validation tool correctly identifies compliance issues in 95% of cases
