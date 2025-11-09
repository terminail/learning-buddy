# Tasks: Course Structure Navigation

**Input**: Design documents from `/specs/021-course-structure-navigation/`
**Prerequisites**: plan.md (required), spec.md (required for user stories), research.md, data-model.md, contracts/

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
- [ ] T003 [P] Configure linting and formatting tools for TypeScript

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before ANY user story can be implemented

**⚠️ CRITICAL**: No user story work can begin until this phase is complete

- [ ] T004 Setup Course Content Provider API client in src/courseContentProvider.ts
- [ ] T005 [P] Implement base tree view provider structure in src/treeViewProvider.ts
- [ ] T006 [P] Setup VS Code extension activation in src/extension.ts
- [ ] T007 Create base models for ChapterItem and SectionItem
- [ ] T008 Configure error handling and logging infrastructure
- [ ] T009 Setup environment configuration management

**Checkpoint**: Foundation ready - user story implementation can now begin in parallel

## Phase 3: User Story 1 - View Course Structure (Priority: P1) 🎯 MVP

**Goal**: Display a structured course navigation that follows the course chapters in the VS Code activity bar

**Independent Test**: Open VS Code with the extension installed and verify that the course structure view appears in the activity bar and correctly displays the chapter structure.

### Tests for User Story 1 (OPTIONAL - only if tests requested) ⚠️

> **NOTE: Write these tests FIRST, ensure they FAIL before implementation**

- [ ] T010 [P] [US1] Unit test for tree view provider initialization in tests/unit/treeViewProvider.test.ts
- [ ] T011 [P] [US1] Integration test for course structure display in tests/integration/courseStructureNavigation.test.ts

### Implementation for User Story 1

- [ ] T012 [P] [US1] Create ChapterItem model in src/treeViewProvider.ts
- [ ] T013 [P] [US1] Create SectionItem model in src/treeViewProvider.ts
- [ ] T014 [US1] Implement tree view provider getChildren method in src/treeViewProvider.ts (depends on T012, T013)
- [ ] T015 [US1] Implement tree view provider getTreeItem method in src/treeViewProvider.ts
- [ ] T016 [US1] Register tree view in extension activation in src/extension.ts
- [ ] T017 [US1] Add proper icons for chapters and sections
- [ ] T018 [US1] Implement course structure loading from Course Content Provider

**Checkpoint**: At this point, User Story 1 should be fully functional and testable independently

## Phase 4: User Story 2 - Navigate Chapters and Sections (Priority: P1)

**Goal**: Enable navigation through chapters and sections in the course structure to access specific learning materials

**Independent Test**: Click on chapters and sections in the course structure and verify that the appropriate actions are triggered.

### Tests for User Story 2 (OPTIONAL - only if tests requested) ⚠️

- [ ] T019 [P] [US2] Unit test for chapter expand/collapse in tests/unit/treeViewProvider.test.ts
- [ ] T020 [P] [US2] Integration test for section navigation in tests/integration/courseStructureNavigation.test.ts

### Implementation for User Story 2

- [ ] T021 [P] [US2] Implement chapter expand/collapse logic in src/treeViewProvider.ts
- [ ] T022 [US2] Implement section click handling in src/treeViewProvider.ts
- [ ] T023 [US2] Add command registration for section navigation in src/extension.ts
- [ ] T024 [US2] Implement learning material access functionality
- [ ] T025 [US2] Add keyboard navigation support

**Checkpoint**: At this point, User Stories 1 AND 2 should both work independently

## Phase 5: User Story 3 - Access Locked Content Information (Priority: P2)

**Goal**: Show which chapters are locked and provide information on how to unlock them

**Independent Test**: View locked chapters and verify that appropriate lock indicators and information are displayed.

### Tests for User Story 3 (OPTIONAL - only if tests requested) ⚠️

- [ ] T026 [P] [US3] Unit test for locked content visualization in tests/unit/treeViewProvider.test.ts
- [ ] T027 [P] [US3] Integration test for lock tooltips in tests/integration/courseStructureNavigation.test.ts

### Implementation for User Story 3

- [ ] T028 [P] [US3] Add lock status property to ChapterItem model
- [ ] T029 [US3] Implement lock icon display for locked chapters
- [ ] T030 [US3] Add hover tooltip functionality for locked chapters
- [ ] T031 [US3] Implement unlock information display

**Checkpoint**: All user stories should now be independently functional

## Phase 6: User Story 4 - View Course Version Information (Priority: P2)

**Goal**: Display the version of the course materials being used

**Independent Test**: View the course information and verify that version information is displayed.

### Tests for User Story 4 (OPTIONAL - only if tests requested) ⚠️

- [ ] T032 [P] [US4] Unit test for version information display in tests/unit/treeViewProvider.test.ts

### Implementation for User Story 4

- [ ] T033 [P] [US4] Add version information to course structure model
- [ ] T034 [US4] Implement version display in tree view
- [ ] T035 [US4] Handle missing version information gracefully

**Checkpoint**: User Stories 1-4 should now be independently functional

## Phase 7: User Story 5 - Refresh Course Content (Priority: P1)

**Goal**: Provide a mechanism to refresh course content to get the latest updates

**Independent Test**: Update course materials in the repository and verify that users can refresh to get the latest content.

### Tests for User Story 5 (OPTIONAL - only if tests requested) ⚠️

- [ ] T036 [P] [US5] Unit test for refresh functionality in tests/unit/treeViewProvider.test.ts
- [ ] T037 [P] [US5] Integration test for content refresh in tests/integration/courseStructureNavigation.test.ts

### Implementation for User Story 5

- [ ] T038 [P] [US5] Implement refresh command in src/extension.ts
- [ ] T039 [US5] Add refresh button to tree view toolbar
- [ ] T040 [US5] Implement course content reloading from Course Content Provider
- [ ] T041 [US5] Add update notification system
- [ ] T042 [US5] Implement progress data preservation during refreshes
- [ ] T043 [US5] Add error handling for network issues during refresh

**Checkpoint**: All user stories should now be independently functional

## Phase 8: Polish & Cross-Cutting Concerns

**Purpose**: Improvements that affect multiple user stories

- [ ] T044 [P] Documentation updates in README.md
- [ ] T045 Code cleanup and refactoring
- [ ] T046 Performance optimization for large course structures
- [ ] T047 [P] Additional unit tests in tests/unit/
- [ ] T048 Security hardening
- [ ] T049 Run quickstart validation
- [ ] T050 Add special character handling for chapter/section names
- [ ] T051 Implement accessibility support
- [ ] T052 Add smooth animations for expand/collapse

## Dependencies & Execution Order

### Phase Dependencies

- **Setup (Phase 1)**: No dependencies - can start immediately
- **Foundational (Phase 2)**: Depends on Setup completion - BLOCKS all user stories
- **User Stories (Phase 3+)**: All depend on Foundational phase completion
  - User stories can then proceed in parallel (if staffed)
  - Or sequentially in priority order (P1 → P2 → P3)
- **Polish (Final Phase)**: Depends on all desired user stories being complete

### User Story Dependencies

- **User Story 1 (P1)**: Can start after Foundational (Phase 2) - No dependencies on other stories
- **User Story 2 (P1)**: Can start after Foundational (Phase 2) - May integrate with US1 but should be independently testable
- **User Story 5 (P1)**: Can start after Foundational (Phase 2) - May integrate with US1/US2 but should be independently testable
- **User Story 3 (P2)**: Can start after Foundational (Phase 2) - May integrate with US1 but should be independently testable
- **User Story 4 (P2)**: Can start after Foundational (Phase 2) - May integrate with US1 but should be independently testable

### Within Each User Story

- Tests (if included) MUST be written and FAIL before implementation
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

## Parallel Example: User Story 1

```bash
# Launch all tests for User Story 1 together (if tests requested):
Task: "Unit test for tree view provider initialization in tests/unit/treeViewProvider.test.ts"
Task: "Integration test for course structure display in tests/integration/courseStructureNavigation.test.ts"

# Launch all models for User Story 1 together:
Task: "Create ChapterItem model in src/treeViewProvider.ts"
Task: "Create SectionItem model in src/treeViewProvider.ts"
```

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1: Setup
2. Complete Phase 2: Foundational (CRITICAL - blocks all stories)
3. Complete Phase 3: User Story 1
4. **STOP and VALIDATE**: Test User Story 1 independently
5. Deploy/demo if ready

### Incremental Delivery

1. Complete Setup + Foundational → Foundation ready
2. Add User Story 1 → Test independently → Deploy/Demo (MVP!)
3. Add User Story 2 → Test independently → Deploy/Demo
4. Add User Story 5 → Test independently → Deploy/Demo
5. Add User Story 3 → Test independently → Deploy/Demo
6. Add User Story 4 → Test independently → Deploy/Demo
7. Each story adds value without breaking previous stories

### Parallel Team Strategy

With multiple developers:

1. Team completes Setup + Foundational together
2. Once Foundational is done:
   - Developer A: User Story 1 + User Story 2
   - Developer B: User Story 5
   - Developer C: User Story 3 + User Story 4
3. Stories complete and integrate independently

## Notes

- [P] tasks = different files, no dependencies
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable
- Verify tests fail before implementing
- Commit after each task or logical group
- Stop at any checkpoint to validate story independently
- Avoid: vague tasks, same file conflicts, cross-story dependencies that break independence