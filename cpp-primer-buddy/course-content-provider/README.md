# Course Content Provider

A Python-based service for managing course content downloads, licenses, and anti-bulk copying measures using FastAPI and SQLite.

## Features

- License management for course content
- Content download tracking with limits
- Course catalog management
- Anti-bulk copying measures
- RESTful API for integration with Learning Buddy extension
- YAML-driven configuration
- Podman containerization

## Requirements

- Python 3.8+
- Conda environment named "liugejiao" (as specified)
- Podman (instead of Docker)

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

## Container Deployment with Podman

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

## API Endpoints

- `GET /` - Root endpoint
- `GET /health` - Health check
- `POST /licenses/` - Create a new license
- `GET /licenses/{license_key}` - Retrieve a license by key
- `POST /content/` - Create new course content
- `GET /catalog/` - Get course catalog

## Database

The service uses SQLite for data storage with minimal configuration. The database file `course_content.db` will be created automatically when the service starts.