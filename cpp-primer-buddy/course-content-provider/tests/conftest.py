import tempfile
import os
import sys

# Add the src directory to the path so we can import the app
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

import pytest

@pytest.fixture
def client():
    """Create a test client for the FastAPI app"""
    # Import inside the fixture to avoid module-level import issues
    from fastapi.testclient import TestClient
    from src.app import app
    with TestClient(app) as client:
        yield client

@pytest.fixture
def temp_db():
    """Create a temporary database for testing"""
    # Import inside the fixture to avoid module-level import issues
    import tempfile
    import os
    from src.app import db
    
    # Create a temporary database file
    temp_db_file = tempfile.NamedTemporaryFile(suffix='.db', delete=False)
    temp_db_file.close()
    
    # Save the original database path
    original_db_path = db.database
    
    # Initialize the database with the temporary file
    db.init(temp_db_file.name)
    
    # Create tables
    db.create_tables([db.models[0] for db.models[0] in db.models])
    
    yield temp_db_file.name
    
    # Cleanup
    db.init(original_db_path)
    try:
        os.unlink(temp_db_file.name)
    except:
        pass