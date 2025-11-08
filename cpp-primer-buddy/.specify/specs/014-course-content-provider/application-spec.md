# Course Content Provider Application Specification

**Feature**: Course Content Provider Application
**Specification ID**: 014-course-content-provider-application
**Created**: 2025-11-08
**Status**: Draft
**Related Specifications**: 014a-course-catalog-management, 014b-content-downloading, 014c-license-management, 014d-anti-bulk-copying, 014e-dynamic-course-structure, 015-course-structure-tool

## Overview

This specification defines the Course Content Provider as a standalone application that provides an API for the Learning Buddy extension to access course content. The application is designed to run within a container (specificly the Learning Buddy Podman Environment) but does not need to know about or manage containerization itself.

The Course Content Provider application focuses solely on:
- Content delivery through a RESTful API
- License verification and management
- Download limit enforcement
- Course catalog management
- Anti-bulk copying measures
- Dynamic course structure generation (scans downloaded materials to automatically generate navigation structure)

**Important Note**: The Course Content Provider application is container-agnostic. It is designed to run in any container environment (Podman, Docker, etc.) but does not contain any container-specific code or dependencies. Containerization is handled entirely by the infrastructure layer, not by the application itself.

For development-time tooling, see the [Course Structure Tool specification](../015-course-structure-tool/spec.md) which provides course creators with validation and generation capabilities for course repositories.

## Architecture

The Course Content Provider application is built using:
- **FastAPI**: A modern, fast web framework for building APIs with Python
- **SQLite**: Lightweight database for storing license information and content metadata
- **Peewee**: Lightweight ORM for database operations
- **PyYAML**: For YAML-driven configuration management

### Separation of Concerns

The application follows a clear separation of concerns:
1. **Application Layer**: Contains all business logic for content delivery, licensing, and security
2. **Infrastructure Layer**: Handles containerization, networking, and deployment (managed by Podman)
3. **Data Layer**: SQLite database for persistent storage

The application does not:
- Manage containers or container orchestration
- Handle Podman-specific commands or APIs
- Include container runtime dependencies
- Perform infrastructure-level operations

## Core Functionality

### Content Delivery API

The application provides a RESTful API for content delivery:

**Endpoints**:
- `GET /health` - Health check endpoint
- `GET /catalog/` - Retrieve course catalog information
- `GET /courses/{course_id}/structure` - Retrieve course structure/navigation data (supports both static and dynamic generation)
- `GET /content/{course_id}/{content_path}` - Retrieve specific content with license verification
- `POST /licenses/` - Create a new license
- `GET /licenses/{license_key}` - Verify and retrieve license information

### License Management

The application handles license management independently of containerization:
- Creation of course-specific licenses with download limits
- License validation and expiration checking
- Download usage tracking to prevent license sharing

### Anti-Bulk Copying Measures

The application implements anti-bulk copying measures:
- Rate limiting for content access
- Download usage tracking per license
- Session management for learning activities

### Course Catalog Management

The application manages course catalog information:
- Static course catalog with metadata
- Course-specific structure and navigation data
- Free/paid course differentiation

### Dynamic Course Structure Generation

The application can automatically scan downloaded course materials to generate course structure information:

**Features**:
- File system scanning to identify chapters, sections, and exercises
- Automatic detection of content protection requirements
- Incremental scanning for performance optimization
- Compatibility with existing static course structure format

## Implementation Details

### Configuration

The application uses YAML-driven configuration through `config.yaml`:

```yaml
server:
  host: "0.0.0.0"
  port: 8000
  debug: false

database:
  url: "sqlite:///./course_content.db"

security:
  license_key_length: 32
  default_download_limit: 5
  license_validity_days: 365

anti_bulk_copying:
  rate_limit_window_seconds: 60
  max_downloads_per_window: 10
  session_timeout_minutes: 30

dynamic_structure:
  enabled: true
  scan_interval_seconds: 300
  naming_conventions:
    chapter_patterns: ["chapter-*", "ch-*", "\\d+.*"]
    exercise_patterns: ["exercise-*", "ex-*", ".*exercise.*"]
    solution_patterns: ["solution-*", "sol-*", ".*solution.*"]
    protected_patterns: ["protected-*", ".*protected.*"]
```

### Database

The application uses SQLite for data storage:
- License information with download limits and usage tracking
- Course content metadata
- Download records for anti-bulk copying measures
- Cached course structure information

The database is automatically created when the application starts and requires no complex configuration.

### Dependencies

The application uses standard Python dependencies managed through `pyproject.toml`:

```toml
[project.dependencies]
fastapi = "==0.104.1"
uvicorn = "[standard]==0.24.0"
peewee = "==3.17.0"
pydantic = "==2.5.0"
pydantic-settings = "==2.0.3"
python-multipart = "==0.0.6"
requests = "==2.31.0"
PyYAML = "==6.0.1"
```

## Container Integration

The application is designed to run in containers but does not manage containerization:

### Container Requirements
- Python 3.12 runtime environment
- Standard networking capabilities
- File system access for SQLite database and course materials
- Port exposure for API access (default: 8000)

### Container Responsibilities
The container environment handles:
- Application lifecycle management
- Networking and port mapping
- File system persistence
- Resource allocation and limits
- Security isolation

### Application Responsibilities
The application handles:
- Business logic for content delivery
- License verification and management
- Data persistence through SQLite
- API request handling
- Security measures
- File system scanning for dynamic course structure generation

## Security Considerations

### License Verification
- All content downloads require a valid license
- Licenses are course-specific
- Download limits prevent unauthorized sharing

### Anti-Bulk Copying
- Rate limiting for content access
- Download usage tracking per license
- Session management for learning activities

### Data Protection
- SQLite database with structured data storage
- License keys generated with UUID for uniqueness
- Content metadata separated from actual content files

### File System Access
- Scanning operations are restricted to course material directories
- Permission errors are handled gracefully
- File system access is logged for security auditing

## Integration with Learning Buddy Extension

The Course Content Provider application integrates with the Learning Buddy VS Code extension through RESTful API calls:

1. **License Management**: The extension can create and validate licenses through API calls
2. **Content Access**: Content downloads are mediated through the application with license verification
3. **Course Discovery**: Course catalog information is provided by the application
4. **Course Navigation**: Dynamic course structure is provided by the application
5. **Usage Tracking**: Download limits are enforced by the application

### Persistent Installation Instructions Enhancement

When the Learning Buddy extension cannot connect to the Course Content Provider (typically due to Podman not being installed or running), the extension now displays persistent installation instructions directly in the Learning Buddy panel instead of transient popup dialogs. This enhancement improves the user experience by providing clear, always-visible guidance on how to resolve the Podman dependency issue.

The panel shows:
- Clear explanation of why Podman is required
- Step-by-step installation instructions
- Direct links to platform-specific installation guides
- Contact support option for additional help

This approach ensures users always know what to do when Podman is missing, rather than having to remember transient error messages.

## Deployment

The application is designed for container deployment:

### Build Process
1. Python dependencies are installed through `pyproject.toml`
2. Application code is copied to the container
3. SQLite database is created on first run
4. Configuration is applied through environment variables or config files

### Runtime Requirements
- Python 3.12+
- Standard networking
- File system access
- Port 8000 (configurable)

### Scaling Considerations
- The application is stateless except for the SQLite database
- Multiple instances can run with a shared database
- Load balancing can be applied at the infrastructure level

## Testing Requirements

### Unit Tests
- API endpoint validation
- License management functionality
- Content delivery logic
- Database operations
- File system scanning components

### Integration Tests
- End-to-end API workflows
- License verification scenarios
- Content download processes
- Anti-bulk copying measures
- Dynamic course structure generation

### Security Tests
- License validation edge cases
- Rate limiting enforcement
- Database security
- Input validation
- File system access controls

### Performance Tests
- File system scanning performance with various repository sizes
- API response times under load
- Memory usage during scanning operations
- Incremental scanning efficiency

## Future Enhancements

### API Extensions
- Dynamic course catalog updates
- Content version management
- User authentication and authorization
- Metrics and monitoring endpoints
- Advanced course structure customization

### Security Improvements
- Enhanced anti-bulk copying measures
- Advanced rate limiting
- Session management improvements
- Audit logging
- Enhanced file system access controls

### Performance Optimizations
- Caching mechanisms for scanned course structures
- Database query optimization
- Asynchronous processing for large repositories
- Memory usage improvements
- Parallel scanning for multi-core systems

## Success Criteria

### Measurable Outcomes
- **SC-001**: API endpoints respond correctly in 99% of requests
- **SC-002**: License verification works accurately in 100% of cases
- **SC-003**: Download limits are enforced correctly in 100% of cases
- **SC-004**: Course catalog information is provided accurately in 100% of cases
- **SC-005**: Anti-bulk copying measures are effective in 95% of attempted violations
- **SC-006**: Database operations complete successfully in 99% of cases
- **SC-007**: Application starts and becomes available within 30 seconds in 95% of deployments
- **SC-008**: Memory usage stays under 100MB during normal operation in 95% of cases
- **SC-009**: Container-agnostic design allows deployment in any container platform in 100% of cases
- **SC-010**: Dynamic course structure generation completes within 30 seconds for 90% of repositories under 1000 files
- **SC-011**: Course structure API responds within 2 seconds in 95% of cases
- **SC-012**: Protected content is correctly identified in 90% of course repositories
- **SC-013**: Persistent installation instructions are displayed in 100% of cases when Podman is not available
- **SC-014**: Detailed installation guidance is provided in 100% of cases when users click on installation instruction items
- **SC-015**: Contact support option works in 100% of cases when Podman is not available