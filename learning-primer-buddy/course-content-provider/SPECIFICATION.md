# Course Content Provider Implementation

## Overview

This document describes the Python implementation of the Course Content Provider service that runs within the Learning Buddy Podman Environment. This service provides an API for the Learning Buddy extension to access course content, handling content downloads, license verification, and anti-bulk copying measures.

## Architecture

The service is built using:
- **FastAPI**: A modern, fast (high-performance) web framework for building APIs with Python 3.7+ based on standard Python type hints.
- **SQLite**: A lightweight disk-based database for storing license information, content metadata, and download records (no complex configuration needed).
- **Peewee**: Lightweight ORM for database operations (instead of SQLAlchemy).
- **PyYAML**: For YAML-driven configuration management.
- **Podman**: Containerization platform (instead of Docker).

## Key Components

### 1. License Management
- Creation of course-specific licenses with download limits
- License validation and expiration checking
- Download usage tracking to prevent license sharing

### 2. Content Management
- Storage of course content metadata
- Content type classification (exercises, solutions, hints, learning guides)
- Protection status tracking for content

### 3. Download Tracking
- Recording of all content downloads with timestamps
- IP address tracking for anti-bulk copying measures
- Integration with license management for usage limits

### 4. Course Catalog
- Static course catalog information
- Course metadata including free/paid status
- Version information for content updates

### 5. Configuration Management
- YAML-driven configuration for all service settings
- Environment-specific configuration support
- Centralized configuration management

## API Endpoints

### Health and Information
- `GET /` - Root endpoint returning service information
- `GET /health` - Health check endpoint

### License Management
- `POST /licenses/` - Create a new license
- `GET /licenses/{license_key}` - Retrieve license information

### Content Operations
- `POST /content/` - Add new course content (administrative)
- `POST /content/download/` - Download content with license verification

### Course Catalog
- `GET /catalog/` - Retrieve course catalog information

## Security Measures

### License Verification
- All content downloads require a valid license
- Licenses are course-specific
- Download limits prevent unauthorized sharing

### Anti-Bulk Copying
- IP address tracking for download patterns
- Rate limiting for content access
- Download usage tracking per license

### Data Protection
- SQLite database with structured data storage (no complex configuration needed)
- License keys generated with UUID for uniqueness
- Content metadata separated from actual content files

## Configuration

The service uses YAML-driven configuration through `config.yaml`. For SQLite, no complex database configuration is needed:

```yaml
server:
  host: "0.0.0.0"
  port: 8000
  debug: false

database:
  # SQLite is used with default settings
  url: "sqlite:///./course_content.db"

security:
  license_key_length: 32
  default_download_limit: 5
  license_validity_days: 365

anti_bulk_copying:
  rate_limit_window_seconds: 60
  max_downloads_per_window: 10
  session_timeout_minutes: 30
```

The SQLite database file `course_content.db` will be automatically created in the current directory when the service starts.

## Integration with Learning Buddy

The Course Content Provider service integrates with the Learning Buddy VS Code extension through RESTful API calls:

1. **License Management**: The extension can create and validate licenses through API calls
2. **Content Access**: Content downloads are mediated through the service with license verification
3. **Course Discovery**: Course catalog information is provided by the service
4. **Usage Tracking**: Download limits are enforced by the service

## Deployment

The service is designed to run in a Podman container as part of the Learning Buddy Podman Environment:

1. **Containerization**: Podmanfile provided for building the container image (using Podman instead of Docker)
2. **Environment**: Uses conda environment "liugejiao" as specified
3. **Database**: SQLite database stored locally within the container (no complex configuration needed)
4. **Networking**: Service exposes port 8000 for API access
5. **Configuration**: YAML-driven configuration for easy customization

## Dependency Management

The service uses `pyproject.toml` for dependency management instead of requirements.txt:

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

## Future Enhancements

1. **Dynamic Course Catalog**: Integration with remote repositories for course catalog updates
2. **Content Delivery**: Actual content file delivery through the service
3. **Advanced Anti-Bulk Copying**: More sophisticated measures for preventing unauthorized copying
4. **Multi-user Support**: Enhanced tracking for multiple users with the same license
5. **Content Updates**: Version management and update notifications for course materials
6. **Authentication**: User authentication and authorization
7. **Metrics**: Monitoring and metrics collection
8. **Logging**: Centralized logging with different levels