# Feature Specification: Course Content Provider

**Feature Branch**: `015-course-content-provider`  
**Created**: 2025-11-07  
**Status**: Draft  
**Input**: User description: "Since we have Podman, why not create a content provider that resides in Podman to download from Gitee or other sources without bothering Learning Buddy. Buddy just interacts with Podman to get everything."

## Implementation Summary

This feature implements a Course Content Provider that runs within the Learning Buddy Podman Environment to provide an API for the Learning Buddy extension to access course content. Instead of the extension directly handling Gitee API calls and content downloads, the Course Content Provider (residing in the Learning Buddy Podman Environment) fetches content directly from Gitee or other sources and provides a clean API for the extension to access. The Learning Buddy extension will interact with the Course Content Provider to manage content access, simplifying the extension architecture and improving security.

This specification merges the functionality previously defined in the Gitee Content Delivery specification (008) into the container-based approach, where all content downloading, license verification, and usage tracking now happens within the Learning Buddy Podman Environment. The Course Content Provider is responsible for downloading course material and providing a clean API interface for the Learning Buddy extension. It also orchestrates course-specific Podman environments for development work.

This specification also incorporates anti-bulk copying measures (see feature 009-anti-bulk-copying) that are now implemented within the Course Content Provider for enhanced security.

This specification also incorporates course catalog management, dynamic course structure loading, and content protection that are now implemented within the Course Content Provider for enhanced security and consistency.

The Course Content Provider manages different types of learning materials including:
- **Exercises**: Programming tasks related to specific chapters
- **Solutions**: Reference implementations for exercises
- **Hints**: Guidance to help solve exercises without revealing full solutions
- **Learning Guides**: Documents containing key concepts and learning objectives for chapters

**Note**: Podman is a mandatory requirement for this extension. The Course Content Provider runs exclusively within the Learning Buddy Podman Environment, and all course content (protected and non-protected) is managed through this infrastructure container. Users must have Podman installed and running to access any course content.

**Critical Requirement**: The Learning Buddy extension MUST perform comprehensive Podman environment checks at startup and before any Podman operations to ensure Podman is properly installed and actively running. This is a critical requirement for the proper functioning of the extension.

**Architecture Note**: The Course Content Provider operates within the Learning Buddy Podman Environment and has a distinct role from course-specific Podman environments:
1. **Learning Buddy Podman Environment**: Hosts the Course Content Provider and handles all infrastructure functions including content delivery, license verification, and orchestration of course environments.
2. **Course-Specific Podman Environments**: Created based on course Podmanfiles to provide development tools and runtime environments. These are orchestrated by the Course Content Provider but have no content management responsibilities.

The Course Content Provider securely mounts course materials into Course-Specific Podman Environments as read-only volumes, ensuring content protection while providing development access.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Container-Based Content Download (Priority: P1)

As a learner with a valid license, I want the Podman container to handle downloading protected content from Gitee so that the Learning Buddy extension doesn't need to manage complex download logic.

**Why this priority**: This is the core functionality - moving download logic to containers to simplify the extension.

**Independent Test**: Can be fully tested by verifying that content is downloaded through Podman containers rather than the extension.

**Acceptance Scenarios**:

1. **Given** a user with a valid license, **When** they access protected content, **Then** the Podman container should handle the download from Gitee.
2. **Given** a user without internet access, **When** they try to access content, **Then** the container should provide appropriate error handling.

### User Story 2 - Extension-Container Communication (Priority: P1)

As a learner using the Learning Buddy extension, I want the extension to communicate with Podman containers to manage content access so that I have a seamless learning experience.

**Why this priority**: This is essential for the user experience - the extension must effectively coordinate with containers.

**Independent Test**: Can be fully tested by verifying communication between extension and containers.

**Acceptance Scenarios**:

1. **Given** a user requesting content access, **When** the extension communicates with the container, **Then** the container should respond with appropriate content or status.
2. **Given** a container with downloaded content, **When** the user accesses it through the extension, **Then** they should be able to view and work with the content.

### User Story 3 - License Verification in Containers (Priority: P1)

As a course creator, I want license verification to happen in Podman containers so that content access is secure and the extension doesn't handle sensitive license data.

**Why this priority**: This is essential for security - keeping license data within containers.

**Independent Test**: Can be fully tested by verifying that license data is handled within containers.

**Acceptance Scenarios**:

1. **Given** a user with a valid license, **When** they access content, **Then** the container should verify the license without exposing sensitive data to the extension.
2. **Given** a user with an invalid license, **When** they attempt to access content, **Then** the container should deny access and report the status to the extension.

### User Story 4 - Download Limit Enforcement in Containers (Priority: P1)

As a course creator, I want download limits to be enforced within Podman containers so that license sharing is prevented and the extension doesn't need to track usage.

**Why this priority**: This is essential for protecting revenue and ensuring fair usage - without proper limits, users could share licenses unlimitedly.

**Independent Test**: Can be tested by using licenses and verifying that limits are enforced within containers.

**Acceptance Scenarios**:

1. **Given** a license with download limits, **When** a user reaches their limit, **Then** the container should deny further downloads.
2. **Given** multiple users with the same license, **When** they attempt to download content, **Then** the container should track usage centrally.

### User Story 5 - Access Content Offline After Download (Priority: P2)

As a learner, I want to access previously downloaded content offline so that I can study even when I don't have internet access.

**Why this priority**: This enhances user experience by allowing offline study, but is not essential for core functionality.

**Independent Test**: Can be tested by downloading content, disconnecting from the internet, and verifying that previously downloaded content is still accessible.

**Acceptance Scenarios**:

1. **Given** a user who has downloaded content, **When** they lose internet connectivity, **Then** they should still be able to access previously downloaded content through the container.
2. **Given** a user trying to download new content without internet, **When** they attempt to access protected content, **Then** the container should provide a clear message about requiring internet connectivity.

### User Story 6 - Handle API Rate Limits and Errors (Priority: P2)

As a learner, I want the system to handle API rate limits and errors gracefully so that I'm not blocked from using the extension due to temporary issues.

**Why this priority**: This is important for robustness but not core functionality.

**Independent Test**: Can be tested by simulating API errors and verifying appropriate error handling.

**Acceptance Scenarios**:

1. **Given** API rate limiting, **When** a user attempts to download content, **Then** they should receive a clear message about retrying later.
2. **Given** temporary API errors, **When** a user attempts to download content, **Then** the system should retry or provide clear error information.

### User Story 7 - Anti-Bulk Copying Measures (Priority: P1)

As a course creator, I want anti-bulk copying measures to be implemented within the Course Content Provider so that unauthorized redistribution of protected content is made more difficult while still allowing legitimate access.

**Why this priority**: This is essential for protecting course content value and preventing unauthorized redistribution.

**Independent Test**: Can be fully tested by attempting various bulk copying techniques and verifying that appropriate measures are in place.

**Acceptance Scenarios**:

1. **Given** a user attempting rapid content access, **When** they request multiple items quickly, **Then** they should experience enforced delays between accesses.
2. **Given** a user trying to access content outside learning sessions, **When** they attempt access, **Then** they should be prompted to start a new session.
3. **Given** a user accessing content, **When** they view the content, **Then** they should see educational but non-essential elements that don't interfere with learning.

### User Story 8 - Course Catalog Management (Priority: P1)

As a learner using the Learning Buddy extension, I want the Course Content Provider to manage course catalog information so that I can discover and switch between available courses.

**Why this priority**: This is essential for multi-course support and course discovery.

**Independent Test**: Can be fully tested by verifying that the Course Content Provider loads, caches, and provides course catalog information.

**Acceptance Scenarios**:

1. **Given** a course catalog in a remote repository, **When** the extension is activated, **Then** the Course Content Provider should load and provide the catalog information.
2. **Given** network connectivity issues, **When** the Course Content Provider attempts to load the catalog, **Then** it should handle errors gracefully and provide appropriate feedback.

### User Story 9 - Critical Podman Environment Verification (Priority: P0)

As a learner using the Learning Buddy extension, I want the extension to immediately check if Podman is installed and running so that I know right away if I can use the extension or need to install Podman.

**Why this priority**: This is critical for user experience - users must know immediately if Podman is missing or not running to avoid confusion and wasted time.

**Independent Test**: Can be tested by running the extension on systems with and without Podman installed, and with Podman daemon running and stopped.

**Acceptance Scenarios**:

1. **Given** a system without Podman installed, **When** the extension starts, **Then** it should immediately display a clear error message with installation instructions.
2. **Given** a system with Podman installed but not running, **When** the extension starts, **Then** it should immediately display a clear error message with instructions to start Podman.
3. **Given** a system with Podman installed and running, **When** the extension starts, **Then** it should proceed with normal initialization without any Podman-related warnings.

### Edge Cases

- What happens when Podman is not installed on the user's system? (Answer: Extension must display clear installation requirements and guidance immediately at startup)
- How does the system handle network issues during container-based downloads?
- What happens when the Podman daemon is not running? (Answer: Extension must detect and notify user to start Podman immediately at startup)
- How does the system handle container initialization failures?
- What happens when there's insufficient disk space for downloaded content?
- How does the system handle updates to the container content provider?
- What happens when a container crashes during download?
- What happens when the content repository is unavailable or deleted?
- How does the system handle users who have reached their download limits?
- How does the system handle API rate limits being exceeded?
- How does the system handle expired access tokens?
- How does the system handle users attempting to bypass anti-bulk copying measures?
- How does the system handle course catalog loading failures?
- What happens when course catalog validation fails?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Learning Buddy Podman Environment MUST include built-in content provider for fetching content from Gitee and other sources
- **FR-002**: Learning Buddy extension MUST communicate with Course Content Provider in Learning Buddy Podman Environment to manage content access
- **FR-003**: Course Content Provider MUST handle license verification without exposing sensitive data to the extension
- **FR-004**: Course Content Provider MUST enforce download limits to prevent license sharing
- **FR-005**: Course Content Provider MUST cache downloaded content for offline access
- **FR-006**: Course Content Provider MUST handle network errors and API rate limits gracefully
- **FR-007**: Learning Buddy extension MUST provide a simplified interface for content access
- **FR-008**: Course Content Provider MUST orchestrate course-specific Podman environments for development work
- **FR-009**: Course Content Provider MUST provide clear error messages for download-related issues
- **FR-010**: Learning Buddy extension MUST verify Podman installation and provide clear guidance when Podman is not available
- **FR-011**: Course Content Provider SHOULD support multiple content sources (Gitee, GitHub, etc.)
- **FR-012**: Course Content Provider MUST ensure secure storage of downloaded content
- **FR-013**: Course Content Provider MUST prevent unauthorized access to protected content
- **FR-014**: Learning Buddy extension MUST require Podman for all functionality
- **FR-015**: Course Content Provider MUST support progress reporting for long-running downloads
- **FR-016**: Course Content Provider MUST track license usage in a centralized repository
- **FR-017**: Course Content Provider MUST authenticate with content repositories using secure token handling
- **FR-018**: Course Content Provider MUST anonymize user identification for privacy protection
- **FR-019**: Course Content Provider MUST verify license authenticity before allowing content access
- **FR-020**: Course Content Provider MUST support multiple repositories for content and tracking
- **FR-021**: Course Content Provider MUST securely mount course materials into course-specific Podman environments
- **FR-022**: Course Content Provider MUST isolate course-specific Podman environments from infrastructure functions
- **FR-023**: Learning Buddy extension MUST perform Podman environment checks at startup before any other operations
- **FR-024**: Learning Buddy extension MUST verify Podman daemon is actively running, not just installed
- **FR-025**: Learning Buddy extension MUST immediately block all functionality and display clear error messages if Podman is not properly installed or running
- **FR-026**: Learning Buddy extension MUST provide specific installation guidance with links to Podman installation resources
- **FR-027**: Learning Buddy extension MUST continuously monitor Podman status during operation and handle Podman daemon stoppages gracefully

### Key Entities

- **ContainerContentDownloader**: Built-in downloader within Podman containers that fetches content from remote sources (replaces GiteeContentDelivery)
- **ContainerLicenseManager**: Handles license verification within Podman containers (replaces GiteeLicense)
- **ContainerUsageTracker**: Enforces download limits within Podman containers (replaces GiteeUsageTracker)
- **ExtensionContainerInterface**: Simplified interface in the extension for communicating with containers
- **ContainerContentCache**: Storage for downloaded content within Podman containers (replaces ContentCache)
- **ContainerErrorReporter**: Handles error reporting from containers to the extension (replaces GiteeAPIHandler)
- **ContainerAPIHandler**: Handles API requests with error handling and rate limiting within containers
- **PodmanStatusChecker**: Critical component that verifies Podman installation and active status at startup and during operation
- **AntiBulkCopyingController**: Coordinates all anti-bulk copying measures within the Course Content Provider
- **CatalogManager**: Manages course catalog loading, caching, and validation within the Course Content Provider
- **Exercise**: A programming task related to a specific chapter
- **Solution**: The correct implementation of an exercise
- **Hint**: Guidance to help solve an exercise without revealing the full solution
- **LearningGuide**: A document containing key concepts and learning objectives for a chapter
- **ContentAccessController**: Manages access to learning materials based on chapter unlock status
- **ProtectedContent**: Content that requires a valid license for access
- **FreeContent**: Content that is accessible without any license requirements

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Content is downloaded through Podman containers in 95% of cases with valid licenses
- **SC-002**: License verification is handled within containers in 100% of cases
- **SC-003**: Download limits are enforced within containers in 100% of cases
- **SC-004**: Previously downloaded content is accessible offline through containers in 100% of cases
- **SC-005**: Network errors are handled gracefully by containers with appropriate user feedback in 95% of cases
- **SC-006**: Extension-container communication works correctly in 99% of cases
- **SC-007**: 90% of users can successfully access content through VS Code Dev Containers
- **SC-008**: Extension performs fewer direct network operations (reduced by 80%)
- **SC-009**: Container-based downloads complete successfully in 90% of cases within 5 minutes
- **SC-010**: Error messages from containers are properly reported to users in 95% of error cases
- **SC-011**: Protected content is successfully downloaded from repositories in 95% of attempts with valid licenses
- **SC-012**: Download limits are enforced correctly in 100% of cases using centralized tracking
- **SC-013**: License usage is tracked centrally with 99% accuracy
- **SC-014**: API errors are handled gracefully with appropriate user feedback in 95% of cases
- **SC-015**: Podman installation and status verification completes in 100% of cases within 2 seconds
- **SC-016**: Clear error messages are displayed for Podman issues in 100% of cases
- **SC-017**: Extension blocks all functionality when Podman is not available in 100% of cases
- **SC-018**: Podman status monitoring detects changes in daemon status in 95% of cases within 5 seconds
- **SC-019**: Anti-bulk copying measures are implemented within the Course Content Provider in 100% of cases
- **SC-020**: Rate limiting is enforced in 100% of rapid access attempts
- **SC-021**: Learning sessions are properly managed in 99% of cases
- **SC-022**: Activity requirements are enforced in 100% of cases
- **SC-023**: Course catalog is loaded dynamically from repository by Course Content Provider in 95% of cases with network connectivity
- **SC-024**: Course catalog refresh works correctly through Course Content Provider in 100% of cases
- **SC-025**: Offline mode works with cached course catalog in Course Content Provider in 90% of cases
