# Tasks: License Management

**Input**: Design documents from `/specs/023-license-management/`
**Prerequisites**: plan.md (required), spec.md (required for user stories)

**Tests**: The examples below include test tasks. Tests are OPTIONAL - only include them if explicitly requested in the feature specification.

**Organization**: Tasks are grouped by user story to enable independent implementation and testing of each story.

## Format: `[ID] [P?] [Story] Description`

- **[P]**: Can run in parallel (different files, no dependencies)
- **[Story]**: Which user story this task belongs to (e.g., US1, US2, US3)
- Include exact file paths in descriptions

## Path Conventions

- **Single project**: `src/`, `tests/` at repository root

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Project initialization and basic structure

- [ ] T001 Create project structure per implementation plan
- [ ] T002 Initialize TypeScript project with VS Code Extension dependencies
- [ ] T003 [P] Configure linting and formatting tools
- [ ] T004 [P] Setup cryptographic libraries for RSA operations

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before ANY user story can be implemented

**⚠️ CRITICAL**: No user story work can begin until this phase is complete

- [ ] T005 Setup license management data models
- [ ] T006 [P] Implement license management interfaces and types
- [ ] T007 [P] Setup secure license storage infrastructure
- [ ] T008 Create base models for course-specific licenses
- [ ] T009 Configure error handling and logging infrastructure

**Checkpoint**: Foundation ready - user story implementation can now begin in parallel

## Phase 3: User Story 1 - Enter Course-Specific License Key (Priority: P1) 🎯 MVP

**Goal**: Allow paying learners to enter license keys for specific courses to unlock protected content

**Independent Test**: Enter valid license key for specific course and verify protected content becomes accessible

### Implementation for User Story 1

- [ ] T010 [P] [US1] Create CourseLicenseKey interface in src/licenseManagement/types.ts
- [ ] T011 [P] [US1] Implement LicenseManager in src/licenseManagement/licenseManager.ts
- [ ] T012 [US1] Create LicenseUI web-based interface in src/licenseManagement/licenseUI.ts
- [ ] T013 [US1] Add course-specific license entry functionality
- [ ] T014 [US1] Implement clear error messages for invalid licenses

**Checkpoint**: At this point, User Story 1 should be fully functional and testable independently

## Phase 4: User Story 2 - Verify Course-Specific License Authenticity (Priority: P1)

**Goal**: Verify course-specific license key authenticity to protect revenue

**Independent Test**: Use valid and invalid licenses for different courses and verify only valid ones grant access

### Implementation for User Story 2

- [ ] T015 [P] [US2] Create LicenseValidator in src/licenseManagement/licenseValidator.ts
- [ ] T016 [P] [US2] Implement RSA public key cryptography verification
- [ ] T017 [US2] Add license authenticity verification per course
- [ ] T018 [US2] Implement rejection of invalid licenses

**Checkpoint**: At this point, User Stories 1 AND 2 should both work independently

## Phase 5: User Story 3 - Manage Multiple Course Licenses (Priority: P2)

**Goal**: Allow learners to manage license keys for multiple courses independently

**Independent Test**: Add multiple licenses for different courses and verify each course's content access is managed independently

### Implementation for User Story 3

- [ ] T019 [P] [US3] Extend LicenseStorage in src/licenseManagement/licenseStorage.ts
- [ ] T020 [US3] Add support for multiple active licenses
- [ ] T021 [US3] Implement license viewing functionality
- [ ] T022 [US3] Add support for free and paid courses

**Checkpoint**: All user stories should now be independently functional

## Phase 6: User Story 4 - Remove or Revoke Course Licenses (Priority: P2)

**Goal**: Allow learners to remove licenses for specific courses from extension

**Independent Test**: Remove license for specific course and verify associated content becomes inaccessible

### Implementation for User Story 4

- [ ] T023 [P] [US4] Add license removal functionality to LicenseManager
- [ ] T024 [US4] Implement license revocation handling
- [ ] T025 [US4] Add confirmation prompts for license removal

## Phase 7: Container Integration

**Goal**: Implement license verification within Podman containers for security

### Implementation for Container Integration

- [ ] T026 [P] Create ContainerLicenseManager in src/containerIntegration/containerLicenseManager.ts
- [ ] T027 [P] Implement UsageTracker in src/containerIntegration/usageTracker.ts
- [ ] T028 [US] Add PrivacyManager in src/containerIntegration/privacyManager.ts
- [ ] T029 [US] Implement container-based license verification
- [ ] T030 [US] Add download limit enforcement per course

## Phase 8: Development Tools

**Goal**: Provide development tools for generating test licenses

### Implementation for Development Tools

- [ ] T031 [P] Add license generation utilities
- [ ] T032 [US] Create test license management tools

## Phase 9: Error Handling

**Goal**: Handle edge cases and error conditions gracefully

### Implementation for Error Handling

- [ ] T033 [P] Implement revoked license handling
- [ ] T034 [US] Add support for different license expiration dates
- [ ] T035 [US] Handle offline license entry
- [ ] T036 [US] Manage malformed or corrupted license keys
- [ ] T037 [US] Handle mixed license scenarios (some courses licensed, others not)

## Phase N: Polish & Cross-Cutting Concerns

**Purpose**: Improvements that affect multiple user stories

- [ ] T038 [P] Documentation updates
- [ ] T039 Code cleanup and refactoring
- [ ] T040 Performance optimization across all stories
- [ ] T041 [P] Additional unit tests
- [ ] T042 Security hardening
- [ ] T043 Run quickstart.md validation

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies - can start immediately
- **Foundational (Phase 2)**: Depends on Setup completion - BLOCKS all user stories
- **User Stories (Phase 3+)**: All depend on Foundational phase completion
  - User stories can then proceed in parallel (if staffed)
  - Or sequentially in priority order (P1 → P2 → P3)

### User Story Dependencies

- **User Story 1 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 2 (P1)**: Can start after Foundational (Phase 2) - Depends on User Story 1
- **User Story 3 (P2)**: Can start after Foundational (Phase 2) - Depends on User Stories 1 and 2
- **User Story 4 (P2)**: Can start after Foundational (Phase 2) - Depends on User Stories 1 and 2

### Within Each User Story

- Models before services
- Services before endpoints
- Core implementation before integration
- Story complete before moving to next priority

### Parallel Opportunities

- All Setup tasks marked [P] can run in parallel
- All Foundational tasks marked [P] can run in parallel (within Phase 2)
- Once Foundational phase completes, all user stories can start in parallel (if team capacity allows)
- All tests for a user story marked [P] can run in parallel
- Models within a story marked [P] can run in parallel
- Different user stories can be worked on in parallel by different team members

## Implementation Strategy

### MVP First (User Stories 1-2 Only)

1. Complete Phase 1: Setup
2. Complete Phase 2: Foundational (CRITICAL - blocks all stories)
3. Complete Phase 3: User Story 1
4. Complete Phase 4: User Story 2
5. **STOP and VALIDATE**: Test User Stories 1 and 2 independently
6. Deploy/demo if ready

### Incremental Delivery

1. Complete Setup + Foundational → Foundation ready
2. Add User Story 1 → Test independently → Deploy/Demo (MVP!)
3. Add User Story 2 → Test independently → Deploy/Demo
4. Add User Story 3 → Test independently → Deploy/Demo
5. Each story adds value without breaking previous stories

### Parallel Team Strategy

With multiple developers:

1. Team completes Setup + Foundational together
2. Once Foundational is done:
   - Developer A: User Story 1
   - Developer B: User Story 2
   - Developer C: User Story 3 + 4
3. Stories complete and integrate independently

## Notes

- [P] tasks = different files, no dependencies
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable
- Commit after each task or logical group
- Stop at any checkpoint to validate story independently
- Avoid: vague tasks, same file conflicts, cross-story dependencies that break independence