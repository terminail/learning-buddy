# Course Content Provider

A Python-based service for managing course content downloads, licenses, and anti-bulk copying measures using FastAPI and SQLite.

## Role in the Learning Buddy Platform

The Course Content Provider is a critical component of the Learning Buddy Extension Platform. It runs within a container (specifically using Podman in the Learning Buddy environment) and serves as the secure backend that handles all protected content delivery, license management, and anti-bulk copying measures. This service ensures that educational materials are protected while providing a seamless learning experience for students using the Learning Buddy Extension in VS Code.

**Important Note**: The Course Content Provider is a container-agnostic application. It is designed to run in any container environment but does not contain any container-specific code. Containerization is handled entirely by the infrastructure layer.

## Features

- License management for course content
- Content download tracking with limits
- Course catalog management
- Anti-bulk copying measures
- RESTful API for integration with Learning Buddy extension
- YAML-driven configuration
- Container-agnostic design (runs in Podman in the Learning Buddy environment)
- Dynamic course structure generation (scans downloaded materials to automatically generate navigation structure)

## Requirements

- Python 3.8+
- Conda environment named "liugejiao" (as specified)
- Container runtime (Podman in the Learning Buddy environment)

## Setup

1. Create and activate the conda environment:
   ```bash
   conda create -n liugejiao python=3.12
   conda activate liugejiao
   ```

2. Install dependencies using pyproject.toml:
   ```bash
   pip install .
   ```

   Or for development (including test dependencies):
   ```bash
   pip install .[dev]
   ```

## Configuration

The service is configured using `config.yaml`. For SQLite, no complex database configuration is needed:

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
# ... more configuration options
```

The SQLite database file `course_content.db` will be automatically created in the current directory when the service starts.

## Running the Service

### Direct execution:
```bash
python src/app.py
```

### Using the installed script:
```bash
course-content-provider
```

The service will start on `http://localhost:8000`.

## Testing

### Running Tests

To run the tests, you can use one of the following methods:

1. Using the test runner script:
   ```bash
   python run_tests.py
   ```

2. Using pytest directly:
   ```bash
   pip install -e .[dev]
   pytest tests -v
   ```

3. Using the platform-specific scripts:
   ```bash
   ./run_tests.sh    # On Linux/Mac
   run_tests.bat     # On Windows
   ```

### Test Coverage

The tests cover the following functionality:
- Health check endpoint
- Root endpoint
- License creation and retrieval
- Course content creation
- Course catalog retrieval
- Dynamic course structure generation

## Container Deployment

The application is designed to run in containers but is container-agnostic:

### With Podman (Learning Buddy Environment):
1. Build the container image:
   ```bash
   podman build -t course-content-provider -f Podmanfile .
   ```

2. Run the container:
   ```bash
   podman run -p 8000:8000 course-content-provider
   ```

3. Run with persistent database:
   ```bash
   podman run -p 8000:8000 -v ./data:/app/data course-content-provider
   ```

### With Docker (Alternative):
1. Build the container image:
   ```bash
   docker build -t course-content-provider -f Dockerfile .
   ```

2. Run the container:
   ```bash
   docker run -p 8000:8000 course-content-provider
   ```

## API Endpoints

- `GET /` - Root endpoint
- `GET /health` - Health check
- `POST /licenses/` - Create a new license
- `GET /licenses/{license_key}` - Retrieve a license by key
- `POST /content/` - Create new course content
- `GET /catalog/` - Get course catalog
- `GET /courses/{course_id}/structure` - Get dynamically generated course structure

## Dynamic Course Structure Generation

The Course Content Provider can automatically scan downloaded course materials to generate course structure information. This feature eliminates the need for static course structure definitions and makes the system more maintainable by automatically adapting to changes in course repositories.

### How It Works

1. The Course Content Provider scans the file system of downloaded course materials
2. It identifies chapters, sections, and exercises based on naming conventions and directory structure
3. It automatically detects which content should be protected based on naming patterns
4. The Learning Buddy extension calls the Course Content Provider API to retrieve the dynamically generated course structure

### File Naming Conventions

The scanner recognizes the following patterns:
- Chapter directories: `chapter-*`, `ch-*`, or numeric prefixes
- Exercise files: `exercise-*`, `ex-*`, or files with "exercise" in the name
- Solution files: `solution-*`, `sol-*`, or files with "solution" in the name
- Protected content: Files in directories with "protected" in the name or specific naming patterns

## Database

The service uses SQLite for data storage with minimal configuration. The database file `course_content.db` will be created automatically when the service starts.