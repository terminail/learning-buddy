# Tasks: WeChat Integration

**Input**: Design documents from `/specs/024-wechat-integration/`
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
- [ ] T004 [P] Add WeChat QR code image to assets directory

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core infrastructure that MUST be complete before ANY user story can be implemented

**⚠️ CRITICAL**: No user story work can begin until this phase is complete

- [ ] T005 Setup WeChat integration data models
- [ ] T006 [P] Implement WeChat integration interfaces and types
- [ ] T007 Create base models for contact panel
- [ ] T008 Configure error handling and logging infrastructure

**Checkpoint**: Foundation ready - user story implementation can now begin in parallel

## Phase 3: User Story 1 - View WeChat QR Code (Priority: P1) 🎯 MVP

**Goal**: Display WeChat QR code when users encounter locked content

**Independent Test**: Open extension and verify WeChat QR code is displayed when users encounter locked content

### Implementation for User Story 1

- [ ] T009 [P] [US1] Create WeChatIntegration interface in src/wechatIntegration/types.ts
- [ ] T010 [P] [US1] Implement WeChatManager in src/wechatIntegration/wechatManager.ts
- [ ] T011 [US1] Create WeChatContactPanel in src/wechatIntegration/wechatContactPanel.ts
- [ ] T012 [US1] Add "I want to study this" button for locked content
- [ ] T013 [US1] Implement QR code display functionality

**Checkpoint**: At this point, User Story 1 should be fully functional and testable independently

## Phase 4: User Story 2 - Contact Instructor for License (Priority: P1)

**Goal**: Enable users to easily contact instructor through WeChat to obtain license key after purchase

**Independent Test**: Simulate contact process and verify it's straightforward

### Implementation for User Story 2

- [ ] T014 [P] [US2] Add clear instructions for obtaining license keys
- [ ] T015 [US2] Implement contact workflow integration
- [ ] T016 [US2] Ensure QR code links to correct WeChat profile

**Checkpoint**: At this point, User Stories 1 AND 2 should both work independently

## Phase 5: Error Handling

**Goal**: Handle edge cases and error conditions gracefully

### Implementation for Error Handling

- [ ] T017 [P] Implement missing or corrupted QR code file handling
- [ ] T018 [US] Add fallback mechanisms for QR code display

## Phase 6: Cross-Platform Compatibility

**Goal**: Ensure QR code is scannable on both mobile and desktop devices

### Implementation for Cross-Platform Compatibility

- [ ] T019 [P] Test QR code scanning on mobile devices
- [ ] T020 [US] Test QR code scanning on desktop devices
- [ ] T021 [US] Optimize QR code display for different screen sizes

## Phase N: Polish & Cross-Cutting Concerns

**Purpose**: Improvements that affect multiple user stories

- [ ] T022 [P] Documentation updates
- [ ] T023 Code cleanup and refactoring
- [ ] T024 Performance optimization across all stories
- [ ] T025 [P] Additional unit tests
- [ ] T026 Security hardening
- [ ] T027 Run quickstart.md validation

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
4. Each story adds value without breaking previous stories

### Parallel Team Strategy

With multiple developers:

1. Team completes Setup + Foundational together
2. Once Foundational is done:
   - Developer A: User Story 1
   - Developer B: User Story 2
3. Stories complete and integrate independently

## Notes

- [P] tasks = different files, no dependencies
- [Story] label maps task to specific user story for traceability
- Each user story should be independently completable and testable
- Commit after each task or logical group
- Stop at any checkpoint to validate story independently
- Avoid: vague tasks, same file conflicts, cross-story dependencies that break independence