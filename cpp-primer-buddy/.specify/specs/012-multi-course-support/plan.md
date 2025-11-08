# Implementation Plan: Multi-Course Support

**Branch**: `013-multi-course-support` | **Date**: 2025-11-08 | **Spec**: [spec.md](./spec.md)

**Input**: Feature specification from `/specs/012-multi-course-support/spec.md`

## Summary

Enable Learning Buddy to support multiple courses. Users can install the generic Learning Buddy extension and immediately see the outline for a default course. The extension also displays promotional positions for other courses, allowing users to discover and switch to different course content without installing new extensions. As of 2025-11-07, course-specific extensions no longer support course switching functionality.

## Technical Context

**Language/Version**: TypeScript (VS Code Extension)  
**Primary Dependencies**: VS Code Extension API, Podman, Node.js  
**Storage**: VS Code Memento API for state, Podman volumes for content, course catalogs  
**Testing**: VS Code Extension testing framework  
**Target Platform**: VS Code with Podman support  
**Project Type**: VS Code Extension  
**Performance Goals**: Sub-2-second course structure loading, 90% success rate for content delivery, 2-second search response time  
**Constraints**: All protected content must be delivered through Podman containers, no host filesystem caching, course-specific extensions don't support switching  
**Scale/Scope**: Single extension supporting multiple courses with dynamic configuration and search capabilities

## Constitution Check

*GATE: Must pass before Phase 0 research. Re-check after Phase 1 design.*

[Gates determined based on constitution file]

## Project Structure

### Documentation (this feature)

```text
specs/012-multi-course-support/
├── plan.md              # This file (/speckit.plan command output)
├── spec.md              # Feature specification
├── checklist.md         # Implementation checklist
├── tasks.md             # Implementation tasks
```

### Source Code (repository root)

```text
src/
├── courseCatalog/
│   ├── catalogManager.ts
│   ├── searchEngine.ts
│   └── types.ts
├── courseContext/
│   ├── contextManager.ts
│   └── sessionState.ts
├── contentDelivery/
│   ├── podmanManager.ts
│   ├── contentProvider.ts
│   └── metadataCache.ts
├── extension.ts
├── treeViewProvider.ts
└── utils/
    └── validators.ts

tests/
├── unit/
│   ├── catalogManager.test.ts
│   ├── searchEngine.test.ts
│   └── contextManager.test.ts
└── integration/
    └── extension.test.ts
```

**Structure Decision**: Using a modular approach with clear separation of concerns:
- Course catalog management for multi-course support
- Course context management for state and switching
- Content delivery through Podman containers for security
- Search engine for course discovery
- Integration with existing VS Code extension architecture

## Complexity Tracking

> **Fill ONLY if Constitution Check has violations that must be justified**

| Violation | Why Needed | Simpler Alternative Rejected Because |
|-----------|------------|-------------------------------------|
| Podman dependency | Required for secure content delivery | Direct file system access would compromise content protection |
| Course catalog system | Essential for multi-course discovery | Hardcoded course lists would not scale |
| Search functionality | Essential for course discovery with many courses | Manual browsing would be inefficient |