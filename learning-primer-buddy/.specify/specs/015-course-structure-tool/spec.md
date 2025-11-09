# Feature Specification: Course Structure Tool

**Feature Branch**: `018-course-structure-tool`  
**Created**: 2025-11-07  
**Status**: Draft  
**Input**: User description: "Course creators need to provide course structure information and Podmanfile that meets Learning Buddy requirements. Learning Buddy should provide a tool to automatically scan course content, validate compliance, generate compliant course-structure.json files, and quickly check if course content and Podmanfile exist and are compliant."

**See Also**: 
- [Course-Specific Extension specification](../019-course-specific-extension/spec.md) for details on building course-specific extensions.
- [Dynamic Course Structure Generation specification](../014e-dynamic-course-structure/spec.md) for details on how the Course Content Provider automatically scans downloaded course materials at runtime.

## Implementation Summary

This feature provides a command-line tool that course creators can use to both validate their course repositories and automatically generate course-structure.json files that comply with Learning Buddy requirements. The tool automatically scans course content, validates required files, checks Podmanfile compliance, generates compliant course structures, and reports any issues. This helps course creators quickly identify and fix problems before distributing their courses, while also automating the creation of properly formatted course structure files.

For runtime course structure generation, see the [Dynamic Course Structure Generation specification](../014e-dynamic-course-structure/spec.md) which describes how the Course Content Provider automatically scans downloaded course materials to generate course structure information at runtime.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Validate Course Repository Structure (Priority: P1)

As a course creator, I want to validate that my course repository follows the required structure so that I can ensure compatibility with Learning Buddy before distribution.

**Why this priority**: This is the core functionality - ensuring course repositories meet requirements.

**Independent Test**: Can be fully tested by running the validation tool on repositories with various structures and verifying that it correctly identifies compliance issues.

**Acceptance Scenarios**:

1. **Given** a course repository that follows the required structure, **When** I run the validation tool, **Then** it should report that the repository is valid.
2. **Given** a course repository missing required files, **When** I run the validation tool, **Then** it should report the missing files.
3. **Given** a course repository with incorrect directory structure, **When** I run the validation tool, **Then** it should report the structural issues.

### User Story 2 - Validate Course Structure File (Priority: P1)

As a course creator, I want to validate that my course-structure.json file follows the required format so that I can ensure it will load correctly in Learning Buddy.

**Why this priority**: This is essential for course content delivery - malformed course structures will prevent content from loading.

**Independent Test**: Can be fully tested by running the validation tool on course-structure.json files with various issues and verifying that it correctly identifies format problems.

**Acceptance Scenarios**:

1. **Given** a valid course-structure.json file, **When** I run the validation tool, **Then** it should report that the file is valid.
2. **Given** a course-structure.json file with missing required fields, **When** I run the validation tool, **Then** it should report the missing fields.
3. **Given** a course-structure.json file with invalid data types, **When** I run the validation tool, **Then** it should report the type mismatches.

### User Story 6 - Generate Course Structure File (Priority: P1)

As a course creator, I want to automatically generate a compliant course-structure.json file by scanning my course content so that I don't have to manually create and maintain this file.

**Why this priority**: This is essential for reducing the manual effort required to create Learning Buddy-compatible courses.

**Independent Test**: Can be fully tested by running the generation tool on course repositories with various content structures and verifying that it correctly generates compliant course-structure.json files.

**Acceptance Scenarios**:

1. **Given** a course repository with properly organized content, **When** I run the generation tool, **Then** it should create a valid course-structure.json file that accurately represents the course content.
2. **Given** a course repository with mixed content types, **When** I run the generation tool, **Then** it should correctly categorize sections based on file types and naming conventions.
3. **Given** an existing course-structure.json file, **When** I run the generation tool with an update flag, **Then** it should update the existing file while preserving manual customizations.

### User Story 3 - Validate Podmanfile Compliance (Priority: P1)

As a course creator, I want to validate that my Podmanfile meets Learning Buddy requirements so that I can ensure learners will get the correct development environment.

**Why this priority**: This is essential for providing the right development environment - invalid Podmanfiles will prevent environment setup.

**Independent Test**: Can be fully tested by running the validation tool on Podmanfiles with various issues and verifying that it correctly identifies compliance problems.

**Acceptance Scenarios**:

1. **Given** a valid Podmanfile that meets requirements, **When** I run the validation tool, **Then** it should report that the Podmanfile is valid.
2. **Given** a Podmanfile missing required components, **When** I run the validation tool, **Then** it should report the missing components.
3. **Given** a Podmanfile with security issues, **When** I run the validation tool, **Then** it should report the security concerns.

### User Story 4 - Validate Course Catalog Structure (Priority: P2)

As a course catalog maintainer, I want to validate that my course catalog follows the required structure so that I can ensure all courses in the catalog are properly formatted.

**Why this priority**: This enhances catalog quality but is not core to individual course creation.

**Independent Test**: Can be tested by running the validation tool on course catalogs with various issues and verifying that it correctly identifies format problems.

**Acceptance Scenarios**:

1. **Given** a valid course catalog file, **When** I run the validation tool, **Then** it should report that the catalog is valid.
2. **Given** a course catalog with missing required fields, **When** I run the validation tool, **Then** it should report the missing fields.
3. **Given** a course catalog with invalid course entries, **When** I run the validation tool, **Then** it should report the entry issues.

### User Story 5 - Generate Detailed Validation Reports (Priority: P2)

As a course creator, I want the validation tool to generate detailed reports of issues found so that I can understand exactly what needs to be fixed.

**Why this priority**: This enhances user experience by providing clear guidance on fixing issues.

**Independent Test**: Can be tested by running the validation tool on repositories with known issues and verifying that the reports are detailed and actionable.

**Acceptance Scenarios**:

1. **Given** a course repository with multiple issues, **When** I run the validation tool, **Then** it should generate a detailed report listing all issues.
2. **Given** a validation report, **When** I read it, **Then** it should provide clear descriptions of each issue and suggestions for fixing them.
3. **Given** a validation report, **When** I fix the issues and re-run the tool, **Then** it should reflect the improvements.

### Edge Cases

- What happens when the course repository URL is invalid or inaccessible?
- How does the tool handle network connectivity issues when validating remote repositories?
- What happens when the course-structure.json file is malformed JSON?
- How does the tool handle very large course repositories?
- What happens when the Podmanfile contains syntax errors?
- How does the tool handle repositories with multiple Podmanfiles?
- What happens when required directories are empty?

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: Tool MUST validate that course repositories follow the required directory structure
- **FR-002**: Tool MUST validate that required files (course-structure.json, Podmanfile) exist in the repository
- **FR-003**: Tool MUST validate that course-structure.json follows the required JSON format
- **FR-004**: Tool MUST validate that Podmanfile meets Learning Buddy requirements
- **FR-005**: Tool MUST validate that course catalog files follow the required JSON format
- **FR-006**: Tool MUST support validating local course repositories
- **FR-007**: Tool MUST support validating remote course repositories (Gitee, GitHub)
- **FR-008**: Tool MUST provide detailed error reports with actionable suggestions
- **FR-009**: Tool MUST handle network connectivity issues gracefully
- **FR-010**: Tool SHOULD support validating course-specific configuration files
- **FR-011**: Tool SHOULD provide validation summary statistics
- **FR-012**: Tool SHOULD support different output formats (text, JSON, HTML)
- **FR-013**: Tool MUST validate that chapter directories exist and contain required content
- **FR-014**: Tool MUST check for common security issues in Podmanfiles
- **FR-015**: Tool MUST validate that protected chapter references match actual chapter IDs
- **FR-016**: Tool MUST automatically generate course-structure.json files by scanning course content
- **FR-017**: Tool MUST support updating existing course-structure.json files while preserving manual customizations
- **FR-018**: Tool MUST categorize content sections based on file types and naming conventions
- **FR-019**: Tool MUST generate unique and consistent section IDs based on content organization
- **FR-020**: Tool MUST support dry-run mode to preview generated structure without creating files

### Course Repository Structure Validation

The tool MUST validate that course repositories follow this structure:

```
course-repo/
├── course-structure.json     # Required: Course structure definition
├── Podmanfile                # Required: Podmanfile for course environment
├── README.md                 # Optional: Course overview
├── chapters/                 # Required: Course content organized by chapters
│   ├── 1_introduction/
│   ├── 2_basics/
│   └── 3_advanced/
└── exercises/                # Optional: Additional exercise materials
```

### Course Structure File Validation

The tool MUST validate that course-structure.json contains these required fields:

```json
{
  "version": "string",
  "title": "string",
  "description": "string",
  "chapters": [
    {
      "id": "string",
      "title": "string",
      "protected": "boolean",
      "sections": [
        {
          "id": "string",
          "title": "string",
          "type": "string",
          "file": "string"
        }
      ]
    }
  ],
  "protectedChapters": ["string"]
}
```

### Podmanfile Validation

The tool MUST validate that Podmanfiles:
- Contain a valid FROM instruction
- Include necessary development tools for the course
- Do not contain obvious security vulnerabilities
- Follow best practices for containerization

### Course Structure Generation

The tool MUST automatically generate course-structure.json files by:
1. Scanning chapter directories in the course repository
2. Identifying content files based on file extensions and naming patterns
3. Creating appropriate section entries for each content file
4. Assigning section types based on file extensions (e.g., .md files as 'readme', .py files as 'exercise')
5. Generating unique section IDs based on chapter and file names
6. Creating a hierarchical structure that reflects the course organization

The tool SHOULD support customization options for:
- Section type mapping (e.g., mapping specific file extensions to specific section types)
- ID generation patterns
- Protected chapter designation
- Content categorization rules

### Key Entities

- **CourseStructureTool**: Main tool that coordinates all validation and generation processes
- **RepositoryValidator**: Validates course repository structure and required files
- **StructureValidator**: Validates course-structure.json format and content
- **StructureGenerator**: Automatically generates course-structure.json files from course content
- **PodmanfileValidator**: Validates Podmanfile compliance and security
- **CatalogValidator**: Validates course catalog structure and content
- **ReportGenerator**: Generates detailed validation reports
- **ValidationResult**: Contains validation results and issues found
- **GenerationResult**: Contains generated course structure and any warnings
- **CourseRepository**: Represents a course repository to be validated

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Course repositories that follow required structure are validated as valid in 100% of cases
- **SC-002**: Course repositories with structural issues are correctly identified in 99% of cases
- **SC-003**: Valid course-structure.json files are validated as valid in 100% of cases
- **SC-004**: Invalid course-structure.json files are correctly identified in 99% of cases
- **SC-005**: Valid Podmanfiles are validated as valid in 100% of cases
- **SC-006**: Invalid Podmanfiles are correctly identified in 95% of cases
- **SC-007**: Valid course catalogs are validated as valid in 100% of cases
- **SC-008**: Invalid course catalogs are correctly identified in 99% of cases
- **SC-009**: Detailed validation reports are generated with actionable suggestions in 100% of cases
- **SC-010**: Network connectivity issues are handled gracefully in 99% of cases
- **SC-011**: Local repositories are validated successfully in 100% of cases
- **SC-012**: Remote repositories are validated successfully in 95% of cases with network connectivity
- **SC-013**: Course-structure.json files are automatically generated from course content in 95% of cases
- **SC-014**: Generated course structures accurately represent course content organization in 90% of cases
- **SC-015**: Existing course-structure.json files are updated while preserving customizations in 100% of cases
- **SC-016**: Section categorization based on file types is correct in 95% of cases