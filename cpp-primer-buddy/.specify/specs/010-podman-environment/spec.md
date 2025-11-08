# Feature Specification: Podman Environment

**Feature Branch**: `010-podman-environment`  
**Created**: 2025-11-07  
**Status**: Draft  
**Input**: User description: "Replace Docker with Podman for enhanced security and rootless operation."

## Implementation Summary

This feature implements integration with an embedded Podman development environment that is packaged with the extension for lightweight, daemonless operation. The embedded Podman environment provides a secure, isolated infrastructure environment where the Course Content Provider runs to manage learning materials. Content downloading functionality has been moved to Podman containers (see feature 014b-content-downloading) where built-in content providers fetch content directly from Gitee or other sources. This approach enhances content protection by keeping materials within the container filesystem rather than on the host system, while also simplifying installation and improving startup performance.

For course-specific development environments, see the [Course Podmanfile Support specification](./013-course-podmanfile-support/spec.md) which extends this feature to provide automatic, course-specific environment setup.

For container-based content downloading, see the [Course Content Provider specification](../014-course-content-provider/spec.md) which moves content downloading functionality into Podman containers to simplify the extension architecture.

**Note**: Podman is a **mandatory requirement** for this extension. All course content, including both protected and non-protected materials, is delivered through Podman containers. The extension includes embedded Podman functionality for lightweight, daemonless operation, eliminating the need for separate Podman installation.

**Critical Requirement**: The Learning Buddy extension MUST perform comprehensive Podman environment checks at startup and before any Podman operations to ensure the embedded Podman functionality is properly initialized and actively running. This is a critical requirement for the proper functioning of the extension.

**Architecture Note**: There are two distinct types of Podman environments in this system:
1. **Learning Buddy Podman Environment**: This is the primary infrastructure container that hosts the Course Content Provider and manages all content delivery, licensing, and orchestration of course-specific environments. This environment is embedded and managed by the Learning Buddy extension.
2. **Course-Specific Podman Environments**: These are development containers that are created based on course-specific Podmanfiles. They provide the development tools and runtime environments needed for specific courses. These environments are orchestrated by the Learning Buddy Podman Environment and are isolated from the infrastructure container.

The Learning Buddy Podman Environment handles content delivery and orchestrates Course-Specific Podman Environments without interference. Course-Specific Podman Environments are purely for development and exercise work, with course materials securely mounted from the Learning Buddy Podman Environment.

## Enhancement: Persistent Installation Instructions

When Podman is not installed or not available on the user's system, the extension now displays persistent installation instructions directly in the Learning Buddy panel instead of transient popup dialogs. This enhancement improves the user experience by providing clear, always-visible guidance on how to resolve the Podman dependency issue.

The panel shows:
- Clear explanation of why Podman is required
- Step-by-step installation instructions
- Direct links to platform-specific installation guides
- Contact support option for additional help

This approach ensures users always know what to do when Podman is missing, rather than having to remember transient error messages.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Initialize Embedded Podman Environment (Priority: P1)

As a C++ Primer 5th Edition learner, I want the extension to automatically initialize the embedded Podman development environment so that I have a complete, secure development setup without manual configuration.

**Why this priority**: This is essential for providing a seamless user experience with the containerized development environment.

**Independent Test**: Can be fully tested by installing the extension and verifying that the embedded Podman environment is initialized automatically.

**Acceptance Scenarios**:

1. **Given** a fresh extension installation, **When** a user accesses protected content, **Then** the extension should automatically initialize the embedded Podman environment.
2. **Given** an existing Podman environment, **When** a user accesses content, **Then** the extension should verify the environment is up-to-date and start it if needed.

### User Story 2 - Access Content Through Podman Container Communication (Priority: P1)

As a C++ Primer 5th Edition learner, I want the extension to communicate with Podman containers to manage content access so that content downloading and management happens securely within containers.

**Why this priority**: This is the core security feature - keeping protected content within the container prevents unauthorized copying while simplifying the extension architecture.

**Independent Test**: Can be fully tested by accessing protected content and verifying that the extension communicates with containers rather than directly downloading files.

**Acceptance Scenarios**:

1. **Given** a user with valid license access, **When** they access protected content, **Then** the extension should communicate with Podman containers that handle content downloading.
2. **Given** downloaded content in the container, **When** a user tries to access files from the host system, **Then** they should not find the protected materials.

### User Story 3 - Access Content Through VS Code with Dev Containers (Priority: P1)

As a C++ Primer 5th Edition learner, I want to access learning materials through VS Code connected to the Podman container so that I can develop and study in a secure environment.

**Why this priority**: This is essential for the core user experience - learners need to access content through their IDE.

**Independent Test**: Can be fully tested by connecting VS Code to the container and verifying that content is accessible through the editor.

**Acceptance Scenarios**:

1. **Given** a user with VS Code and the Remote-Containers extension, **When** they open the workspace, **Then** they should be able to connect to the Podman container and access content.
2. **Given** a connected user, **When** they open protected files, **Then** they should be able to edit, compile, and run code within the container.

### User Story 4 - Secure Container Access with Authentication (Priority: P2)

As a course creator, I want the Podman container to require authentication for access so that unauthorized users cannot access the development environment.

**Why this priority**: This enhances security but is not core functionality.

**Independent Test**: Can be tested by attempting to access the container without proper authentication.

**Acceptance Scenarios**:

1. **Given** a user trying to access the container, **When** they don't provide the correct password, **Then** they should be denied access.
2. **Given** a user with the correct password, **When** they try to access the container, **Then** they should be granted access.

### User Story 5 - Manage Container Resources (Priority: P2)

As a C++ Primer 5th Edition learner, I want the Podman container to have appropriate resource limits so that it doesn't consume excessive system resources.

**Why this priority**: This enhances user experience by preventing resource abuse but is not core functionality.

**Independent Test**: Can be tested by monitoring container resource usage during intensive operations.

**Acceptance Scenarios**:

1. **Given** a user running intensive compilation tasks, **When** the container approaches resource limits, **Then** performance should be maintained within reasonable bounds.
2. **Given** multiple containers running, **When** system resources are monitored, **Then** each container should respect its allocated limits.

### User Story 6 - Critical Embedded Podman Environment Verification (Priority: P0)

As a learner using the Learning Buddy extension, I want the extension to immediately check if the embedded Podman is initialized and running so that I know right away if I can use the extension.

**Why this priority**: This is critical for user experience - users must know immediately if embedded Podman is missing or not running to avoid confusion and wasted time.

**Independent Test**: Can be tested by running the extension on systems with and without embedded Podman properly initialized, and with embedded Podman running and stopped.

**Acceptance Scenarios**:

1. **Given** a system where embedded Podman fails to initialize, **When** the extension starts, **Then** it should immediately display a clear error message with troubleshooting instructions and prevent all functionality.
2. **Given** a system with embedded Podman initialized but not running, **When** the extension starts, **Then** it should immediately display a clear error message with instructions to start embedded Podman and prevent all functionality.
3. **Given** a system with embedded Podman initialized and running, **When** the extension starts, **Then** it should proceed with normal initialization without any embedded Podman-related warnings.

### User Story 7 - Specify Custom Podman Installation Folder (Priority: P2)

As a system administrator or advanced user, I want to specify a custom Podman installation folder so that I can use Podman installed in non-standard locations or enterprise-managed installations.

**Why this priority**: This enhances flexibility for enterprise environments and advanced users but is not core functionality for typical users.

**Independent Test**: Can be tested by installing Podman in a non-standard location and verifying that the extension can use it when the folder is specified.

**Acceptance Scenarios**:

1. **Given** Podman installed in a non-standard directory, **When** the extension starts and cannot find Podman in standard locations, **Then** it should prompt the user to specify an installation folder.
2. **Given** a user specifies a custom Podman folder, **When** the folder contains a valid Podman executable, **Then** the extension should use that Podman installation.
3. **Given** a user specifies a custom Podman folder, **When** the folder does not contain a valid Podman executable, **Then** the extension should show an appropriate error message.

### User Story 8 - Cross-Platform Podman Support (Priority: P1)

As a learner using the Learning Buddy extension, I want the extension to work consistently across Windows, macOS, and Linux so that I can use it regardless of my operating system.

**Why this priority**: This is essential for broad user adoption and accessibility.

**Independent Test**: Can be tested by running the extension on different operating systems and verifying consistent behavior.

**Acceptance Scenarios**:

1. **Given** a user on Windows, **When** they install and run the extension, **Then** it should properly detect and use Podman.
2. **Given** a user on macOS, **When** they install and run the extension, **Then** it should properly detect and use Podman.
3. **Given** a user on Linux, **When** they install and run the extension, **Then** it should properly detect and use Podman.

### User Story 9 - Persistent Installation Instructions (Priority: P0)

As a learner using the Learning Buddy extension, I want to see persistent installation instructions in the panel when Podman is not available so that I always know what to do to resolve the issue.

**Why this priority**: This is critical for user experience - users must have clear, always-visible guidance when Podman is missing.

**Independent Test**: Can be tested by running the extension on systems without Podman installed and verifying that installation instructions are displayed in the panel.

**Acceptance Scenarios**:

1. **Given** a system where Podman is not installed, **When** the extension starts, **Then** it should display persistent installation instructions in the Learning Buddy panel.
2. **Given** a system where Podman is not installed, **When** the user clicks on installation instruction items, **Then** they should see detailed guidance.
3. **Given** a system where Podman is not installed, **When** the user clicks the support contact option, **Then** they should be directed to contact support.

### Edge Cases

- What happens when embedded Podman fails to initialize? (Answer: Extension must display clear error and guidance immediately at startup and prevent all functionality)
- How does the system handle network issues during environment initialization?
- What happens when the embedded Podman is not running? (Answer: Extension must detect and notify user immediately at startup and prevent all functionality)
- How does the system handle container initialization failures?
- What happens when there's insufficient disk space for the container?
- How does the system handle updates to the Podman environment?
- What happens when a custom Podman installation becomes invalid? (Answer: Extension must detect and prompt user for new location)
- How does the system handle platform-specific command syntax and file paths?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Extension MUST include embedded Podman functionality for lightweight, daemonless operation
- **FR-002**: Extension MUST initialize the Podman environment automatically
- **FR-003**: Extension MUST communicate with Podman containers to manage content access (content downloading handled by containers per 014b-content-downloading)
- **FR-004**: Extension MUST prevent protected content from being stored on the host filesystem
- **FR-005**: Extension MUST integrate with VS Code Dev Containers for seamless access
- **FR-006**: Extension MUST provide secure container access with authentication
- **FR-007**: Extension MUST manage container resources with appropriate limits
- **FR-008**: Extension MUST verify embedded Podman functionality and provide clear error messages when Podman is not available
- **FR-009**: Extension MUST require embedded Podman to be initialized and running for all functionality
- **FR-010**: Extension MUST update the Podman environment when newer versions are available
- **FR-011**: Extension MUST perform Podman environment checks at startup before any other operations
- **FR-012**: Extension MUST verify embedded Podman is actively running
- **FR-013**: Extension MUST immediately block all functionality and display clear error messages if embedded Podman is not properly initialized or running
- **FR-014**: Extension MUST provide specific troubleshooting guidance for embedded Podman issues
- **FR-015**: Extension MUST continuously monitor Podman status during operation and handle Podman daemon stoppages gracefully
- **FR-016**: Extension MUST provide cross-platform support for Windows, macOS, and Linux
- **FR-017**: Extension MUST handle platform-specific command syntax and file paths
- **FR-018**: Extension MUST provide platform-appropriate error messages and installation guidance
- **FR-019**: Extension MUST prompt user to specify custom Podman installation folder when Podman is not found in standard locations
- **FR-020**: Extension MUST validate that the specified folder contains a valid Podman executable
- **FR-021**: Extension MUST remember the custom Podman installation folder between VS Code sessions
- **FR-022**: Extension MUST NOT provide a "Continue Anyway" option when Podman is not available as it is a mandatory requirement
- **FR-023**: Extension MUST support Podman Desktop and WSL2-based Podman on Windows
- **FR-024**: Extension MUST support Homebrew-installed Podman on macOS
- **FR-025**: Extension MUST support distribution package managers (apt, dnf, pacman) on Linux
- **FR-026**: Extension MUST handle case-sensitive file systems on macOS
- **FR-027**: Extension MUST support both Intel and Apple Silicon architectures on macOS
- **FR-028**: Extension MUST handle various shell environments (bash, zsh, etc.) on Linux
- **FR-029**: Extension MUST support systemd-based and non-systemd systems on Linux
- **FR-030**: Extension MUST handle user permissions for rootless Podman on Linux
- **FR-031**: Extension MUST display persistent installation instructions in the panel when Podman is not available
- **FR-032**: Extension MUST provide detailed installation guidance when users click on installation instruction items
- **FR-033**: Extension MUST provide a contact support option when Podman is not available
- **FR-034**: Extension MUST include platform-specific installation links in the installation guidance

### Key Entities

- **PodmanEnvironmentManager**: Manages initializing, and controlling the embedded Podman environment
- **ExtensionContainerInterface**: Simplified interface in the extension for communicating with containers (replaces ContentDownloader)
- **ContainerAccessController**: Manages secure access to the Podman container
- **ResourceMonitor**: Monitors and manages container resource usage
- **PodmanEnvironment**: The embedded Podman development environment
- **PodmanStatusChecker**: Critical component that verifies Podman installation and active status at startup and during operation

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Embedded Podman environment is initialized in 95% of cases within 30 seconds
- **SC-002**: Learning materials are accessed through the embedded container in 99% of cases
- **SC-003**: Protected content is not accessible from the host filesystem in 100% of cases
- **SC-004**: Container starts successfully in 98% of attempts
- **SC-005**: Resource limits are enforced in 100% of cases
- **SC-006**: Authentication prevents unauthorized access in 100% of cases
- **SC-007**: 90% of users can successfully access content through VS Code Dev Containers
- **SC-008**: Podman installation and status verification completes in 100% of cases within 2 seconds
- **SC-009**: Clear error messages are displayed for Podman issues in 100% of cases
- **SC-010**: Extension blocks all functionality when Podman is not available in 100% of cases
- **SC-011**: Podman status monitoring detects changes in daemon status in 95% of cases within 5 seconds
- **SC-012**: Cross-platform functionality works on Windows, macOS, and Linux in 95% of cases
- **SC-013**: Platform-specific error messages are displayed in 100% of error cases
- **SC-014**: Installation guidance leads to successful installation in 90% of cases
- **SC-015**: Custom Podman folder specification works on 100% of supported platforms
- **SC-016**: Custom Podman path is correctly saved and loaded in 100% of cases
- **SC-017**: Extension prevents all functionality when Podman is not available in 100% of cases
- **SC-018**: Windows-specific Podman support works in 95% of cases
- **SC-019**: macOS-specific Podman support works in 95% of cases
- **SC-020**: Linux-specific Podman support works in 95% of cases
- **SC-021**: Persistent installation instructions are displayed in 100% of cases when Podman is not available
- **SC-022**: Detailed installation guidance is provided in 100% of cases when users click on installation instruction items
- **SC-023**: Contact support option works in 100% of cases when Podman is not available
- **SC-024**: Platform-specific installation links work in 100% of cases