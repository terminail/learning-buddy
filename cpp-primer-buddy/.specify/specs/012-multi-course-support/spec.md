# Feature Specification: Multi-Course Support

**Feature Branch**: `013-multi-course-support`  
**Created**: 2025-11-07  
**Status**: Draft  
**Input**: User description: "Learning Buddy should support multiple courses, display the default course大纲 (outline) for the specific extension (e.g. 'C++ Primer 5th Buddy'), and show promotional positions for other courses. Clicking on promotional courses should open a list of all courses for the user to select."

**See Also**: 
- [Course Catalog Structure specification](./016-course-catalog/spec.md) for details on catalog and repository structure requirements.
- [Course-Specific Extension Building specification](./017-course-specific-extension/spec.md) for details on building course-specific extensions like "C++ Primer 5th Edition Buddy".
- [Course Validation Tool specification](./018-course-validation-tool/spec.md) for details on validating course repository compliance.
- [Course Content Provider specification](./015-course-content-provider/spec.md) for details on how course content is managed and delivered through Docker containers.

## Implementation Summary

This feature enables Learning Buddy to support multiple courses within a single extension instance. Users can install a course-specific extension (e.g., "C++ Primer 5th Buddy") and immediately see the大纲 (outline) for that specific course. The extension also displays promotional positions for other courses, allowing users to discover and switch to different course content without installing new extensions.

The multi-course support works by:
1. Loading the default course大纲 based on the specific extension installed
2. Displaying promotional positions for other courses at the bottom of the大纲
3. Allowing users to click on promotional courses to switch content within the same extension
4. Restoring the default course when VS Code is restarted
5. Remembering course selection during the same VS Code session
6. Delivering protected content through the secure Docker environment managed by the Course Content Provider
7. Configuring course-specific development environments automatically
8. Providing search capabilities to find courses by name, author, tags, or other metadata

Course search functionality is implemented by indexing course metadata (name, author, tags, summary) and providing a real-time search interface that filters courses as users type. Search results are displayed in a clear, organized manner with relevant course information.

**Note**: Docker is a mandatory requirement for this extension. All course content (protected and non-protected) is managed through the Course Content Provider that runs in the Learning Buddy Docker Environment. Users must have Docker installed and running to access any course content.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Display Default Course大纲 (Priority: P1)

As a learner using a specific Learning Buddy extension (e.g., "C++ Primer 5th Buddy"), I want to see the大纲 (outline) for that specific course by default so that I can immediately start learning the content I installed the extension for.

**Why this priority**: This is the core functionality - users expect to see the content they installed the extension for when they open it.

**Independent Test**: Can be fully tested by installing a specific Learning Buddy extension and verifying that the correct course大纲 is displayed by default.

**Acceptance Scenarios**:

1. **Given** a "C++ Primer 5th Buddy" extension installation, **When** the extension is opened, **Then** the C++ Primer 5th Edition大纲 should be displayed.
2. **Given** a "Python 3rd Edition Buddy" extension installation, **When** the extension is opened, **Then** the Python 3rd Edition大纲 should be displayed.

---

### User Story 2 - View Promotional Courses (Priority: P1)

As a learner using a specific Learning Buddy extension, I want to see promotional positions for other courses so that I can discover and switch to other learning materials.

**Why this priority**: This is essential for course discovery and cross-selling.

**Independent Test**: Can be fully tested by opening the extension and verifying that promotional positions for other courses are displayed.

**Acceptance Scenarios**:

1. **Given** a Learning Buddy extension, **When** the user scrolls to the bottom of the大纲, **Then** promotional positions for other courses should be visible.
2. **Given** promotional course positions, **When** the user hovers over them, **Then** additional information about the courses should be displayed.

---

### User Story 3 - Switch to Other Courses Within Same Extension (Priority: P1)

As a learner interested in other courses, I want to click on promotional courses to view and switch to other course content within the same extension instance, and have the extension restore to its default course when VS Code is restarted.

**Why this priority**: This is essential for the multi-course functionality without requiring installation of new extensions.

**Independent Test**: Can be fully tested by clicking on promotional courses, verifying that the course content changes, and then restarting VS Code to verify it restores to the default course.

**Acceptance Scenarios**:

1. **Given** promotional course positions, **When** the user clicks on one, **Then** the大纲 for that course should be loaded and displayed within the same extension.
2. **Given** a user who has switched to a different course, **When** they restart VS Code, **Then** the extension should display the default course大纲 again.
3. **Given** multiple course switches, **When** the user closes and reopens VS Code, **Then** the extension should always restore to its original default course.

---

### User Story 4 - Access Course Content Through Docker Environment (Priority: P1)

As a learner accessing protected course content, I want the content to be delivered directly to a secure Docker development environment so that materials are protected from unauthorized copying.

**Why this priority**: This is essential for content protection - all protected materials must be stored within Docker containers rather than on the host filesystem.

**Independent Test**: Can be fully tested by accessing protected content and verifying that files are downloaded directly into the Docker container rather than the host filesystem.

**Acceptance Scenarios**:

1. **Given** a user with valid license access, **When** they access protected content, **Then** the Docker container should handle downloading materials directly from Gitee or other sources.
2. **Given** downloaded content in the container, **When** a user tries to access files from the host system, **Then** they should not find the protected materials.

---

### User Story 5 - Use Course-Specific Development Environment (Priority: P1)

As a learner working on course exercises, I want the development environment to be automatically configured with all the tools and dependencies required for that specific course so that I can focus on learning rather than environment setup.

**Why this priority**: This is essential for providing the right tools for each course's exercises without manual setup.

**Independent Test**: Can be fully tested by selecting different courses and verifying that appropriate development environments are automatically configured.

**Acceptance Scenarios**:

1. **Given** a C++ course with specific compiler requirements, **When** the Docker environment is initialized, **Then** it should contain the correct C++ compiler version.
2. **Given** a Python course with specific library dependencies, **When** the Docker environment is initialized, **Then** it should contain the required Python libraries.
3. **Given** a course requiring specific development tools, **When** the Docker environment is initialized, **Then** it should contain those tools.

---

### User Story 5 - Maintain Course Context During Session (Priority: P2)

As a learner switching between courses, I want the extension to remember my current course selection during the same VS Code session so that I don't have to reselect it if I navigate away and back.

**Why this priority**: This enhances user experience but is not core functionality.

**Independent Test**: Can be tested by switching courses, navigating away from the extension, and returning to verify the same course is still displayed.

**Acceptance Scenarios**:

1. **Given** a user who has selected a course, **When** they navigate away from the extension and return, **Then** the same course should be displayed.
2. **Given** multiple course selections within a session, **When** the user navigates between different views, **Then** the current course should be preserved.

---

### User Story 6 - Implement Secure Caching Policy (Priority: P1)

As a learner, I want the extension to implement a secure caching policy that caches only non-protected metadata locally while delivering protected content directly to Docker containers so that content remains secure.

**Why this priority**: This is essential for maintaining content security while providing good performance.

**Independent Test**: Can be tested by accessing both protected and non-protected content and verifying that only metadata is cached locally.

**Acceptance Scenarios**:

1. **Given** a user accessing course content, **When** the extension loads course structures, **Then** only metadata should be cached locally.
2. **Given** a user accessing protected content, **When** the extension delivers content, **Then** it should be delivered directly to Docker containers without caching on the host.
3. **Given** cached metadata, **When** the user goes offline, **Then** they should still be able to access previously loaded course outlines.

---

### User Story 7 - Search for Courses (Priority: P1)

As a learner with many available courses, I want to search for specific courses by name, author, tags, or other metadata so that I can quickly find courses I'm interested in without browsing through promotional positions.

**Why this priority**: This enhances user experience by providing efficient course discovery, especially when there are many courses available.

**Independent Test**: Can be tested by entering search terms and verifying that relevant courses are returned in the search results.

**Acceptance Scenarios**:

1. **Given** a course catalog with multiple courses, **When** the user searches by course name, **Then** the system should return courses matching that name.
2. **Given** a course catalog with courses by different authors, **When** the user searches by author name, **Then** the system should return courses by that author.
3. **Given** a course catalog with tagged courses, **When** the user searches by tag, **Then** the system should return courses with that tag.
4. **Given** a large course catalog, **When** the user performs a search, **Then** the results should be displayed quickly and be easy to navigate.

---

### Edge Cases

- What happens when the course catalog is unavailable?
- How does the system handle very large numbers of courses?
- What happens when a user selects a course that is no longer available?
- How does the system handle network connectivity issues when loading course catalogs?
- What happens when the promotional positions configuration is missing or malformed?
- What happens when a course structure file is missing or malformed?
- What happens when Docker is not installed on the user's system?
- How does the system handle Docker container initialization failures?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST display the大纲 for the specific course associated with the extension by default
- **FR-002**: System MUST show promotional positions for other courses at the bottom of the大纲
- **FR-003**: System MUST allow users to click on promotional courses to switch to other course content within the same extension instance
- **FR-004**: System MUST restore the default course大纲 when VS Code is restarted
- **FR-005**: System MUST remember the user's course selection during the same VS Code session
- **FR-006**: System MUST handle errors gracefully when course catalogs are unavailable
- **FR-007**: System SHOULD display course descriptions and other relevant information in promotional positions
- **FR-008**: System SHOULD support a configurable number of promotional positions
- **FR-009**: System MUST preserve all existing functionality (license management, WeChat integration, etc.) when switching courses
- **FR-010**: System MUST support both local and remote course catalogs following the standardized catalog structure
- **FR-011**: System MUST NOT require installation of new extensions to switch courses
- **FR-012**: System MUST NOT cache protected content on the host filesystem
- **FR-013**: System MUST deliver protected content directly to the Docker development environment through container-based downloaders
- **FR-014**: System MAY cache non-protected metadata (course structures, catalogs, Dockerfiles) locally for performance (Docker images are managed by Docker daemon)
- **FR-015**: System MUST integrate with VS Code Dev Containers for seamless access to Docker environment
- **FR-016**: System MUST clearly distinguish between cached metadata and protected content in its implementation
- **FR-017**: System MUST ensure that cached metadata does not contain any protected content
- **FR-018**: System MUST download and use course-specific Dockerfiles to configure development environments
- **FR-019**: System MUST automatically build Docker environments with tools and dependencies required for each course
- **FR-020**: System MUST provide fallback to default development environment when course-specific Dockerfiles are unavailable
- **FR-021**: System MUST validate that course repositories follow the required structure as defined in the course catalog specification
- **FR-022**: System MUST support building course-specific extensions (e.g., "C++ Primer 5th Edition Buddy") using the generic Learning Buddy codebase
- **FR-023**: System SHOULD provide a validation tool for course creators to check repository compliance
- **FR-024**: System MUST provide a search interface for finding courses by name, author, tags, or other metadata
- **FR-025**: System MUST support real-time search filtering as users type
- **FR-026**: System MUST display search results in a clear, organized manner with relevant course information
- **FR-027**: System MUST allow users to switch to courses from search results without requiring new extension installations

### Key Entities

- **CourseCatalog**: Collection of all available courses with their metadata following the standardized catalog structure
- **PromotionalPosition**: Display position for promoting other courses
- **CourseContext**: Current course selection and related state
- **CourseMetadata**: Information about a course (title, description, repository, etc.)
- **SessionState**: Temporary state maintained during a VS Code session
- **DockerEnvironmentManager**: Manages Docker container for secure content delivery
- **MetadataCache**: Manages caching of non-protected course metadata for performance
- **ContentDeliveryManager**: Ensures protected content is delivered directly to Docker containers without host caching
- **DockerfileManager**: Manages downloading and caching of course-specific Dockerfiles
- **EnvironmentBuilder**: Handles building Docker environments from course-specific Dockerfiles
- **CourseSearchEngine**: Handles searching and filtering of courses based on user queries

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Default course大纲 is displayed correctly in 100% of cases
- **SC-002**: Promotional positions for other courses are displayed in 100% of cases
- **SC-003**: Course switching works correctly within the same extension in 99% of cases
- **SC-004**: Extension restores to default course on VS Code restart in 100% of cases
- **SC-005**: Course selection is remembered during the same session in 95% of cases
- **SC-006**: Error handling for unavailable course catalogs works in 99% of cases
- **SC-007**: All existing features work correctly when switching courses
- **SC-008**: No new extension installation is required for course switching
- **SC-009**: Protected content is not accessible from the host filesystem in 100% of cases
- **SC-010**: 90% of users can successfully access content through VS Code Dev Containers
- **SC-011**: Non-protected metadata may be cached locally for performance
- **SC-012**: Protected content is never cached on the host filesystem in 100% of cases
- **SC-013**: Cached metadata does not contain any protected content in 100% of cases
- **SC-014**: Course-specific Dockerfiles are downloaded successfully in 95% of cases
- **SC-015**: Course-specific development environments are built and initialized in 90% of cases
- **SC-016**: Default development environments are provided as fallback in 99% of cases when Dockerfiles are unavailable
- **SC-017**: Course repository validation tool correctly identifies compliance issues in 95% of cases
- **SC-018**: Course search functionality returns relevant results in 95% of cases
- **SC-019**: Course search results are displayed within 2 seconds of user input in 90% of cases
- **SC-020**: Users can successfully switch to courses from search results in 99% of cases
