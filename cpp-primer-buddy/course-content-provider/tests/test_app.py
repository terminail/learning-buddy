import sys
import os

# Add the src directory to the path so we can import the app
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

# Skip tests if dependencies are not available
try:
    import pytest
    from fastapi.testclient import TestClient
    from src.app import app
    DEPENDENCIES_AVAILABLE = True
except ImportError as e:
    print(f"Import error: {e}")
    DEPENDENCIES_AVAILABLE = False

if DEPENDENCIES_AVAILABLE:
    def get_client():
        """Create a test client for the FastAPI app"""
        return TestClient(app)

    def test_health_check():
        """Test the health check endpoint"""
        client = get_client()
        response = client.get("/health")
        assert response.status_code == 200
        assert response.json() == {"status": "healthy"}

    def test_root_endpoint():
        """Test the root endpoint"""
        client = get_client()
        response = client.get("/")
        assert response.status_code == 200
        assert "message" in response.json()

    def test_create_license():
        """Test creating a license"""
        client = get_client()
        # Test data
        license_data = {
            "course_id": "test-course",
            "download_limit": 5
        }
        
        response = client.post("/licenses/", json=license_data)
        assert response.status_code == 200
        
        # Check response structure
        data = response.json()
        assert "id" in data
        assert data["course_id"] == "test-course"
        assert data["download_limit"] == 5
        assert data["downloads_used"] == 0
        assert data["is_active"] == True
        assert "license_key" in data
        assert len(data["license_key"]) > 0

    def test_get_license():
        """Test retrieving a license"""
        client = get_client()
        # First create a license
        license_data = {
            "course_id": "test-course-2",
            "download_limit": 3
        }
        
        create_response = client.post("/licenses/", json=license_data)
        assert create_response.status_code == 200
        created_license = create_response.json()
        license_key = created_license["license_key"]
        
        # Now retrieve the license
        response = client.get(f"/licenses/{license_key}")
        assert response.status_code == 200
        
        data = response.json()
        assert data["course_id"] == "test-course-2"
        assert data["download_limit"] == 3
        assert data["license_key"] == license_key

    def test_get_nonexistent_license():
        """Test retrieving a non-existent license"""
        client = get_client()
        response = client.get("/licenses/NONEXISTENT_KEY")
        assert response.status_code == 404

    def test_create_content():
        """Test creating course content"""
        client = get_client()
        content_data = {
            "course_id": "test-course",
            "chapter_id": "chapter-1",
            "content_type": "exercise",
            "file_path": "/exercises/ch1/ex1.cpp",
            "is_protected": True
        }
        
        response = client.post("/content/", json=content_data)
        assert response.status_code == 200
        
        data = response.json()
        assert "id" in data
        assert data["course_id"] == "test-course"
        assert data["chapter_id"] == "chapter-1"
        assert data["content_type"] == "exercise"
        assert data["file_path"] == "/exercises/ch1/ex1.cpp"
        assert data["is_protected"] == True

    def test_get_catalog():
        """Test retrieving the course catalog"""
        client = get_client()
        response = client.get("/catalog/")
        assert response.status_code == 200
        
        data = response.json()
        assert "courses" in data
        assert isinstance(data["courses"], list)
else:
    # Create dummy tests that are skipped when dependencies are not available
    def test_dependencies_not_available():
        """Skip tests when dependencies are not available"""
        pytest.skip("Dependencies not available")