# Tasks: Multi-Course Support

**Input**: Design documents from `/specs/012-multi-course-support/`
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

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before ANY user story can be implemented

**⚠️ CRITICAL**: No user story work can begin until this phase is complete

- [ ] T004 Setup course catalog management framework
- [ ] T005 [P] Implement course catalog data models and interfaces
- [ ] T006 [P] Setup Podman environment management infrastructure
- [ ] T007 Create base models for course context and session state
- [ ] T008 Configure error handling and logging infrastructure

**Checkpoint**: Foundation ready - user story implementation can now begin in parallel

## Phase 3: User Story 1 - Display Default Course Outline (Priority: P1) 🎯 MVP

**Goal**: Display outline for default course by default in generic Learning Buddy extension

**Independent Test**: Install generic Learning Buddy extension and verify correct course outline is displayed by default

### Implementation for User Story 1

- [ ] T009 [P] [US1] Create CourseMetadata interface in src/courseCatalog/types.ts
- [ ] T010 [P] [US1] Implement CatalogManager in src/courseCatalog/catalogManager.ts
- [ ] T011 [US1] Add default course loading based on extension configuration
- [ ] T012 [US1] Implement course outline display in tree view

**Checkpoint**: At this point, User Story 1 should be fully functional and testable independently

## Phase 4: User Story 2 - View Promotional Courses (Priority: P1)

**Goal**: Show promotional positions for other courses at bottom of outline

**Independent Test**: Open extension and verify promotional positions for other courses are displayed

### Implementation for User Story 2

- [ ] T013 [P] [US2] Extend CatalogManager to provide promotional course data
- [ ] T014 [US2] Implement promotional positions display in tree view
- [ ] T015 [US2] Add hover information for promotional courses

**Checkpoint**: At this point, User Stories 1 AND 2 should both work independently

## Phase 5: User Story 3 - Switch to Other Courses Within Same Extension (Priority: P1)

**Goal**: Enable clicking on promotional courses to switch content within same extension instance

**Independent Test**: Click on promotional courses, verify course content changes, restart VS Code to verify default course restoration

### Implementation for User Story 3

- [ ] T016 [P] [US3] Create CourseContext interface in src/courseContext/types.ts
- [ ] T017 [P] [US3] Implement ContextManager in src/courseContext/contextManager.ts
- [ ] T018 [US3] Add session state management in src/courseContext/sessionState.ts
- [ ] T019 [US3] Implement course switching functionality
- [ ] T020 [US3] Add default course restoration on VS Code restart

**Checkpoint**: All user stories should now be independently functional

## Phase 6: User Story 3b - Course-Specific Extensions Promote Generic Learning Buddy (Priority: P1)

**Goal**: Inform learners using course-specific extensions about how to access other courses

**Independent Test**: Install course-specific extension and verify it promotes generic Learning Buddy extension

### Implementation for User Story 3b

- [ ] T021 [P] [US3b] Add promotional position for generic Learning Buddy in course-specific extensions
- [ ] T022 [US3b] Implement navigation to generic Learning Buddy information

## Phase 7: User Story 4 - Access Course Content Through Podman Environment (Priority: P1)

**Goal**: Deliver protected content directly to secure Podman development environment

**Independent Test**: Access protected content and verify files are downloaded directly into Podman container

### Implementation for User Story 4

- [ ] T023 [P] [US4] Create PodmanEnvironmentManager in src/contentDelivery/podmanManager.ts
- [ ] T024 [US4] Implement secure content delivery through container-based downloaders
- [ ] T025 [US4] Ensure protected content is not cached on host filesystem

## Phase 8: User Story 5 - Use Course-Specific Development Environment (Priority: P1)

**Goal**: Automatically configure development environment with tools required for specific course

**Independent Test**: Select different courses and verify appropriate development environments are configured

### Implementation for User Story 5

- [ ] T026 [P] [US5] Create PodmanfileManager in src/contentDelivery/podmanfileManager.ts
- [ ] T027 [P] [US5] Implement EnvironmentBuilder in src/contentDelivery/environmentBuilder.ts
- [ ] T028 [US5] Add automatic building of Podman environments with course-specific tools
- [ ] T029 [US5] Implement fallback to default development environment

## Phase 9: User Story 6 - Maintain Course Context During Session (Priority: P2)

**Goal**: Remember current course selection during same VS Code session

**Independent Test**: Switch courses, navigate away from extension, return to verify same course is displayed

### Implementation for User Story 6

- [ ] T030 [P] [US6] Enhance SessionState management in src/courseContext/sessionState.ts
- [ ] T031 [US6] Implement course context preservation during navigation

## Phase 10: User Story 7 - Implement Secure Caching Policy (Priority: P1)

**Goal**: Cache only non-protected metadata locally while delivering protected content to Podman containers

**Independent Test**: Access both protected and non-protected content and verify only metadata is cached locally

### Implementation for User Story 7

- [ ] T032 [P] [US7] Create MetadataCache in src/contentDelivery/metadataCache.ts
- [ ] T033 [US7] Implement secure caching policy that distinguishes metadata from protected content
- [ ] T034 [US7] Add validation to ensure cached metadata contains no protected content

## Phase 11: User Story 8 - Search for Courses (Priority: P1)

**Goal**: Enable search for specific courses by name, author, tags, or other metadata

**Independent Test**: Enter search terms and verify relevant courses are returned in search results

### Implementation for User Story 8

- [ ] T035 [P] [US8] Create CourseSearchEngine in src/courseCatalog/searchEngine.ts
- [ ] T036 [P] [US8] Implement search indexing for course metadata
- [ ] T037 [US8] Add real-time search filtering as users type
- [ ] T038 [US8] Implement clear, organized display of search results
- [ ] T039 [US8] Enable course switching from search results

## Phase N: Polish & Cross-Cutting Concerns

**Purpose**: Improvements that affect multiple user stories

- [ ] T040 [P] Documentation updates
- [ ] T041 Code cleanup and refactoring
- [ ] T042 Performance optimization across all stories
- [ ] T043 [P] Additional unit tests
- [ ] T044 Security hardening
- [ ] T045 Run quickstart.md validation

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
- **User Story 3 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 3b (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 4 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 5 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 6 (P2)**: Can start after Foundational (Phase 2) - Depends on User Story 3
- **User Story 7 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 8 (P1)**: Can start after Foundational (Phase 2) - Depends on User Story 1

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

### MVP First (User Stories 1-3 Only)

1. Complete Phase 1: Setup
2. Complete Phase 2: Foundational (CRITICAL - blocks all stories)
3. Complete Phase 3: User Story 1
4. Complete Phase 4: User Story 2
5. Complete Phase 5: User Story 3
6. **STOP and VALIDATE**: Test User Stories 1-3 independently
7. Deploy/demo if ready

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
   - Developer A: User Story 1 + 2
   - Developer B: User Story 3 + 3b
   - Developer C: User Story 4 + 5
3. Stories complete and integrate independently

## Notes

- [P] tasks = different files, no dependencies
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable
- Commit after each task or logical group
- Stop at any checkpoint to validate story independently
- Avoid: vague tasks, same file conflicts, cross-story dependencies that break independence