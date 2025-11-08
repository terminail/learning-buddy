# Tasks: Generic Learning Buddy

**Input**: Design documents from `/specs/011-generic-learning-buddy/`
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

- [ ] T004 Setup configuration management framework
- [ ] T005 [P] Implement configuration file schema and validation
- [ ] T006 [P] Setup Podman environment management infrastructure
- [ ] T007 Create base models for course structure and metadata
- [ ] T008 Configure error handling and logging infrastructure

**Checkpoint**: Foundation ready - user story implementation can now begin in parallel

## Phase 3: User Story 1 - Customize Extension Configuration (Priority: P1) 🎯 MVP

**Goal**: Support custom configuration of extension name, description, and repository URL

**Independent Test**: Create configuration file with custom values and verify extension uses those values when building and packaging

### Implementation for User Story 1

- [ ] T009 [P] [US1] Create Configuration interface in src/configuration/types.ts
- [ ] T010 [P] [US1] Implement ConfigManager in src/configuration/configManager.ts
- [ ] T011 [US1] Add default configuration that maintains backward compatibility with C++ Primer 5th Edition
- [ ] T012 [US1] Implement configuration validation in src/utils/validators.ts
- [ ] T013 [US1] Add command-line parameter support for configuration overrides

**Checkpoint**: At this point, User Story 1 should be fully functional and testable independently

## Phase 4: User Story 2 - Build Custom Extension Package (Priority: P1)

**Goal**: Build custom extension packages with course-specific configuration

**Independent Test**: Run build process with custom configuration and verify VSIX file is created with custom name and metadata

### Implementation for User Story 2

- [ ] T014 [P] [US2] Create build system integration in src/build/buildSystem.ts
- [ ] T015 [US2] Implement VSIX package generation with custom metadata
- [ ] T016 [US2] Add build validation to ensure custom metadata is correctly embedded

**Checkpoint**: At this point, User Stories 1 AND 2 should both work independently

## Phase 5: User Story 3 - Load Dynamic Course Structure (Priority: P1)

**Goal**: Load course structure dynamically from Gitee repository

**Independent Test**: Update course structure in repository and verify extension loads updated structure when opened

### Implementation for User Story 3

- [ ] T017 [P] [US3] Create CourseStructure interface in src/courseStructure/types.ts
- [ ] T018 [P] [US3] Implement StructureLoader in src/courseStructure/structureLoader.ts
- [ ] T019 [US3] Add refresh mechanism to reload course structure from repository
- [ ] T020 [US3] Implement error handling for missing/malformed course structure files

**Checkpoint**: All user stories should now be independently functional

## Phase 6: User Story 4 - Support Multiple Courses Within Same Extension (Priority: P1)

**Goal**: Support multiple courses within same extension with default course restoration on restart

**Independent Test**: Install specific Learning Buddy extension, switch courses, and verify extension restores to default course on restart

### Implementation for User Story 4

- [ ] T021 [P] [US4] Create CourseContext management in src/courseContext/contextManager.ts
- [ ] T022 [US4] Implement course switching functionality within same extension instance
- [ ] T023 [US4] Add session state management to remember course selection
- [ ] T024 [US4] Implement default course restoration on VS Code restart

## Phase 7: User Story 5 - Deliver Content Through Podman Environment (Priority: P1)

**Goal**: Deliver protected content directly to secure Podman development environment

**Independent Test**: Access protected content and verify files are downloaded directly into Podman container rather than host filesystem

### Implementation for User Story 5

- [ ] T025 [P] [US5] Create PodmanEnvironmentManager in src/contentDelivery/podmanManager.ts
- [ ] T026 [US5] Implement secure content delivery through container-based downloaders
- [ ] T027 [US5] Ensure protected content is not cached on host filesystem

## Phase 8: User Story 6 - Provide Course-Specific Development Environments (Priority: P1)

**Goal**: Provide Podmanfile that defines specific development environment needed for course exercises

**Independent Test**: Provide Podmanfile with course and verify learners get appropriate development environment

### Implementation for User Story 6

- [ ] T028 [P] [US6] Create PodmanfileManager in src/contentDelivery/podmanfileManager.ts
- [ ] T029 [P] [US6] Implement EnvironmentBuilder in src/contentDelivery/environmentBuilder.ts
- [ ] T030 [US6] Add PodmanfileValidator in src/utils/validators.ts
- [ ] T031 [US6] Implement fallback to default development environment

## Phase 9: User Story 7 - Support Multiple Content Sources (Priority: P2)

**Goal**: Support different content sources (GitHub, Gitee, local files)

**Independent Test**: Configure different content sources and verify extension can access content from each

### Implementation for User Story 7

- [ ] T032 [P] [US7] Extend StructureLoader to support multiple content source types
- [ ] T033 [US7] Add content source validation and error handling

## Phase 10: User Story 8 - Maintain Backward Compatibility (Priority: P2)

**Goal**: Maintain backward compatibility with existing C++ Primer Buddy installations

**Independent Test**: Run upgraded extension with existing configurations and verify it behaves the same as before

### Implementation for User Story 8

- [ ] T034 [P] [US8] Implement backward compatibility checks
- [ ] T035 [US8] Add migration path for existing configurations

## Phase 11: User Story 9 - Implement Secure Caching Policy (Priority: P1)

**Goal**: Implement secure caching policy that caches only non-protected metadata locally

**Independent Test**: Access both protected and non-protected content and verify that only metadata is cached locally

### Implementation for User Story 9

- [ ] T036 [P] [US9] Create MetadataCache in src/contentDelivery/metadataCache.ts
- [ ] T037 [US9] Implement secure caching policy that distinguishes metadata from protected content
- [ ] T038 [US9] Add validation to ensure cached metadata contains no protected content

## Phase N: Polish & Cross-Cutting Concerns

**Purpose**: Improvements that affect multiple user stories

- [ ] T039 [P] Documentation updates
- [ ] T040 Code cleanup and refactoring
- [ ] T041 Performance optimization across all stories
- [ ] T042 [P] Additional unit tests
- [ ] T043 Security hardening
- [ ] T044 Run quickstart.md validation

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
- **User Story 4 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 5 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 6 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 7 (P2)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 8 (P2)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 9 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories

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
   - Developer A: User Story 1 + 2
   - Developer B: User Story 3 + 4
   - Developer C: User Story 5 + 6
3. Stories complete and integrate independently

## Notes

- [P] tasks = different files, no dependencies
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable
- Commit after each task or logical group
- Stop at any checkpoint to validate story independently
- Avoid: vague tasks, same file conflicts, cross-story dependencies that break independence