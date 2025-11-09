# Feature Specification: License Management

**Feature Branch**: `023-license-management`  
**Created**: 2025-11-05  
**Status**: **Enhanced**  
**Input**: User description: "Support license key management using private key encryption, allowing users to unlock protected content after payment"

## Enhancement Notice

This specification has been enhanced to support multi-course licensing where licenses are now course-specific. Some courses may be free while others are paid, allowing for flexible licensing models within the same Learning Buddy extension.

## Updates to Implementation (2025-11-09)

### Persistent Download Icons with Conditional Actions

The license management system now integrates with the course structure navigation to provide a better user experience:

1. **Persistent Download Icons**: Download icons are always visible for first-level items (chapters) regardless of license status
2. **Conditional Actions**: When users click download icons:
   - With Valid License: Content is downloaded to the workspace
   - Without Valid License: Users are directed to the license purchase page
3. **License Status Bar**: Provides immediate visibility into current license status

### License Status Bar Integration

The extension now includes a license status bar that:
- Shows current license status ("License Free", "License Paid", or "License Required")
- Opens appropriate license information page when clicked
- Uses mock Podman status for testing different scenarios

### Content Preview Without License

All content remains previewable regardless of license status, allowing users to evaluate course materials before purchasing while still protecting actual downloads.

## Implementation Summary

This feature implements the extension-level license management functionality for Learning Buddy. It provides the user interface for license management, communicates with the Course Content Provider for license verification, and displays license status information to users.

With the multi-course support in Learning Buddy, licenses are now course-specific, allowing some courses to be free while others are paid. Each course can have its own licensing model, and users can manage licenses for multiple courses independently.

### License Status Definitions

The system now supports three distinct license statuses:

1. **License Free** - For courses that do not require any license verification. These courses are freely accessible to all users without restrictions.

2. **License Paid** - For courses that require a valid paid license. Users must have an active, valid license to access protected content in these courses.

3. **License Required** - For courses that require a license but the user does not have an active license. This status indicates that access is restricted until a valid license is obtained.

The License Management component handles:
- Displaying license status information in the status bar using the three status definitions
- Providing UI for users to add, remove, and manage licenses
- Communicating with the Course Content Provider for license verification
- Enforcing license requirements before allowing content downloads
- Supporting all three license statuses (Free, Paid, Required) within the same extension
- Providing clear indication of which courses require licenses
- Handling license-related errors and providing user guidance

**Note**: Podman is a mandatory requirement for this extension. The License Management component communicates with the Course Content Provider running in the Learning Buddy Podman Environment. Users must have Podman installed and running to access any course content.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Enter Course-Specific License Key (Priority: P1)

As a paying learner, I want to enter my license key for a specific course so that I can unlock the protected content I've purchased for that course.

**Why this priority**: This is the core functionality for converting a purchase into access - without it, users can't benefit from their purchase.

**Independent Test**: Can be fully tested by entering a valid license key for a specific course and verifying that protected content for that course becomes accessible.

**Acceptance Scenarios**:

1. **Given** a user with a valid license key for Course A, **When** they enter it in the extension, **Then** the system should validate it and unlock protected content for Course A only.
2. **Given** a user with an invalid license key for Course B, **When** they enter it, **Then** they should receive a clear error message explaining why it's invalid.
3. **Given** a free course C, **When** a user accesses content from Course C, **Then** no license key should be required.

### User Story 2 - Verify Course-Specific License Authenticity (Priority: P1)

As a course creator, I want the extension to verify course-specific license key authenticity so that only legitimate purchasers can access protected content for their specific course.

**Why this priority**: This is essential for protecting revenue - without proper verification, the protection system can be bypassed.

**Independent Test**: Can be fully tested by using both valid and invalid licenses for different courses and verifying that only valid ones grant access to their respective courses.

**Acceptance Scenarios**:

1. **Given** a valid license signed with the private key for Course A, **When** the extension verifies it, **Then** it should be accepted as authentic and grant access to Course A content only.
2. **Given** an invalid license (unsigned or signed with wrong key) for Course B, **When** the extension verifies it, **Then** it should be rejected as inauthentic and deny access to Course B content.
3. **Given** a valid license for Course A, **When** a user tries to access Course B content, **Then** they should be prompted for a Course B license.

### User Story 3 - Manage Multiple Course Licenses (Priority: P2)

As a learner, I want to manage license keys for multiple courses independently so that I can access different courses I've purchased separately or access free courses without license requirements.

**Why this priority**: This enhances user experience for customers who purchase content for multiple courses or access free courses.

**Independent Test**: Can be tested by adding multiple licenses for different courses and verifying that each course's content access is managed independently.

**Acceptance Scenarios**:

1. **Given** a user with valid licenses for Course A and Course B, **When** they access content from both courses, **Then** both courses should be accessible independently.
2. **Given** a user with a license for paid Course A and access to free Course B, **When** they view their license management interface, **Then** they should see the license for Course A but no license requirement for Course B.
3. **Given** a user with expired licenses for Course A, **When** they try to access Course A content, **Then** they should be prompted to renew while still having access to other courses.

### User Story 4 - Remove or Revoke Course Licenses (Priority: P2)

As a learner, I want to remove licenses for specific courses from the extension so that I can manage my access on different machines or when I no longer need access to those courses.

**Why this priority**: This is important for user control but not essential for core functionality.

**Independent Test**: Can be tested by removing a license for a specific course and verifying that associated content for that course becomes inaccessible.

**Acceptance Scenarios**:

1. **Given** a user with an active license for Course A, **When** they remove it from the extension, **Then** associated protected content for Course A should become inaccessible while other courses remain accessible.
2. **Given** a user viewing their license management interface, **When** they select to remove a license for Course B, **Then** they should be prompted to confirm the action for Course B only.

### User Story 5 - Persistent Download Icons with Conditional Actions (Priority: P1)

As a learner, I want to always see download icons for downloadable content so that I can easily identify what content I can access, with the action depending on my license status.

**Why this priority**: This is essential for user experience - clear indication of what content is downloadable.

**Independent Test**: Can be fully tested by verifying that download icons are always visible regardless of license status.

**Acceptance Scenarios**:

1. **Given** a user without a valid license, **When** they view the course structure, **Then** download icons should be visible for all downloadable content.
2. **Given** a user with a valid license, **When** they view the course structure, **Then** download icons should be visible for all downloadable content.
3. **Given** any user, **When** they click a download icon, **Then** the action should be appropriate based on their license status.

### User Story 6 - License Status Awareness (Priority: P1)

As a learner, I want to easily see my current license status so that I understand whether I can access protected content.

**Why this priority**: This is essential for user experience - clear indication of access rights.

**Independent Test**: Can be tested by viewing the license status bar and verifying that it accurately reflects the current license status.

**Acceptance Scenarios**:

1. **Given** a user with a valid license, **When** they view the extension, **Then** the license status bar should show "License Paid".
2. **Given** a user without a valid license but with Podman installed, **When** they view the extension, **Then** the license status bar should show "License Free".
3. **Given** a user without Podman installed, **When** they view the extension, **Then** the license status bar should show "License Required".
3. **Given** any user, **When** they click the license status bar, **Then** they should be directed to appropriate license information.

### User Story 7 - Content Preview Without License (Priority: P2)

As a learner, I want to preview content even when I don't have a valid license so that I can evaluate the course before purchasing.

**Why this priority**: This enhances user experience by allowing content evaluation.

**Independent Test**: Can be tested by accessing content preview functionality without a valid license.

**Acceptance Scenarios**:

1. **Given** a user without a valid license, **When** they preview content, **Then** they should be able to view the content in read-only mode.
2. **Given** a user with a valid license, **When** they preview content, **Then** they should be able to view the content in read-only mode.

### Edge Cases

- What happens when a user enters a license that has been revoked by the issuer for a specific course?
- How does the system handle license keys with different expiration dates for different courses?
- What happens when a user tries to enter a license while offline for a specific course?
- How does the system handle malformed or corrupted license keys for different courses?
- How does the system handle users who have licenses for some courses but not others?
- How does the system handle users clicking download icons without valid licenses?
- How does the system handle users clicking download icons with valid licenses?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Extension MUST provide a user interface for entering license keys per course
- **FR-002**: Extension MUST verify license key authenticity using cryptographic signatures per course
- **FR-003**: Extension MUST store valid licenses securely per course
- **FR-004**: Extension MUST grant access to protected content only with valid licenses for the specific course
- **FR-005**: Extension MUST provide clear error messages for invalid licenses per course
- **FR-006**: Extension SHOULD support multiple active licenses for different courses
- **FR-007**: Extension SHOULD allow users to view their active licenses per course
- **FR-008**: Extension SHOULD allow users to remove licenses for specific courses
- **FR-009**: Extension MUST reject revoked or expired licenses per course
- **FR-010**: Extension MUST handle license verification failures gracefully per course
- **FR-011**: Extension MUST provide development tools for generating test licenses
- **FR-012**: Extension MUST support both free and paid courses within the same extension
- **FR-013**: Extension MUST clearly indicate which courses require licenses and which are free
- **FR-014**: Extension MUST handle license expiration per course independently
- **FR-015**: Extension MUST handle license verification within Podman containers for each course
- **FR-016**: Extension MUST enforce download limits per course to prevent license sharing
- **FR-017**: Extension MUST track license usage per course in a centralized repository
- **FR-018**: Extension MUST anonymize user identification for privacy protection
- **FR-019**: Extension MUST support multiple repositories for tracking per course
- **FR-020**: Extension MUST always show download icons for downloadable content regardless of license status
- **FR-021**: Extension MUST check license status when users click download icons
- **FR-022**: Extension MUST direct users without valid licenses to the purchase page when they click download icons
- **FR-023**: Extension MUST provide a license status bar that shows current license status
- **FR-024**: Extension MUST allow users to click the license status bar to view license information or purchase options
- **FR-025**: Extension MUST allow content preview regardless of license status

### Key Entities

- **LicenseManager**: Manages license keys and their validation through a web-based UI per course
- **CourseLicenseKey**: A cryptographic key that grants access to protected content for a specific course
- **CourseLicenseStorage**: Secure storage for active license keys using VS Code's global state per course
- **CourseLicenseValidator**: Verifies the authenticity and validity of license keys using RSA public key cryptography per course
- **LicenseUI**: Web-based user interface for license management operations per course
- **ContainerLicenseManager**: Handles license verification within Podman containers for each course
- **ContainerUsageTracker**: Enforces download limits within Podman containers per course
- **UsageTracker**: Tracks license usage in a centralized repository per course
- **PrivacyManager**: Anonymizes user identification for privacy protection
- **LicenseStatusBar**: Status bar item that shows current license status and provides access to license management
- **DownloadActionHandler**: Component that handles download icon clicks with appropriate license checking
- **ContentPreviewer**: Component that allows content preview regardless of license status

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Valid license keys are accepted and verified within 3 seconds in 99% of cases per course
- **SC-002**: Invalid license keys are rejected with appropriate error messages in 100% of cases per course
- **SC-003**: Protected content access is granted only with valid licenses for the specific course
- **SC-004**: License storage is secure and resistant to tampering per course
- **SC-005**: Users can successfully manage (add/remove/view) licenses per course in the interface
- **SC-006**: Free courses require no license verification in 100% of cases
- **SC-007**: Paid courses require valid license verification in 100% of cases
- **SC-008**: License expiration is handled per course independently in 100% of cases
- **SC-009**: License verification is handled within containers per course in 100% of cases
- **SC-010**: Download limits are enforced within containers per course in 100% of cases
- **SC-011**: License usage is tracked centrally per course with 99% accuracy
- **SC-012**: User identification is anonymized for privacy protection in 100% of cases
- **SC-013**: Error handling for license issues provides appropriate feedback in 95% of error cases
- **SC-014**: Download icons are visible for all downloadable content in 100% of cases
- **SC-015**: Users without valid licenses are directed to purchase page when clicking download icons in 100% of cases
- **SC-016**: Users with valid licenses can download content when clicking download icons in 95% of cases
- **SC-017**: License status bar accurately reflects current license status in 100% of cases
- **SC-018**: Content preview works for all users regardless of license status in 100% of cases