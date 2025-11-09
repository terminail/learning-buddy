import yaml
from fastapi import FastAPI, HTTPException, Depends
from peewee import *
from datetime import datetime, timedelta, timezone
from typing import Optional, List
import uuid
import os

# Load configuration from YAML
def load_config():
    config_path = os.path.join(os.path.dirname(__file__), "..", "config.yaml")
    with open(config_path, "r") as f:
        return yaml.safe_load(f)

config = load_config()

# Database setup - Using Peewee with SQLite
db = SqliteDatabase('course_content.db')

# Create FastAPI app
app = FastAPI(
    title="Course Content Provider", 
    description="A service for managing course content downloads, licenses, and anti-bulk copying measures",
    version="0.1.0"
)

# Custom field for timezone-aware datetime
class TimezoneAwareDateTimeField(DateTimeField):
    def db_value(self, value):
        if value and isinstance(value, datetime) and value.tzinfo is None:
            # Assume naive datetime is UTC
            value = value.replace(tzinfo=timezone.utc)
        return super().db_value(value)
    
    def python_value(self, value):
        if value and isinstance(value, datetime) and value.tzinfo is None:
            # Assume naive datetime from database is UTC
            value = value.replace(tzinfo=timezone.utc)
        return super().python_value(value)

# Peewee models
class BaseModel(Model):
    class Meta:
        database = db

def default_expires_at():
    return datetime.now(timezone.utc) + timedelta(days=365)

class License(BaseModel):
    course_id = CharField(index=True)
    license_key = CharField(unique=True, index=True)
    download_limit = IntegerField(default=5)
    downloads_used = IntegerField(default=0)
    is_active = BooleanField(default=True)
    created_at = TimezoneAwareDateTimeField(default=lambda: datetime.now(timezone.utc))
    expires_at = TimezoneAwareDateTimeField(default=default_expires_at)

class CourseContent(BaseModel):
    course_id = CharField(index=True)
    chapter_id = CharField()
    content_type = CharField()  # exercise, solution, hint, learning_guide
    file_path = CharField()
    is_protected = BooleanField(default=True)
    created_at = TimezoneAwareDateTimeField(default=lambda: datetime.now(timezone.utc))

# Create tables
db.connect()
db.create_tables([License, CourseContent])

# Pydantic models for request/response using a different approach
from pydantic import BaseModel as PydanticBaseModel, Field

class LicenseCreate(PydanticBaseModel):
    course_id: str = Field(..., description="The course identifier")
    download_limit: int = Field(5, description="The download limit", ge=0)

class LicenseResponse(PydanticBaseModel):
    id: int = Field(..., description="The license identifier")
    course_id: str = Field(..., description="The course identifier")
    license_key: str = Field(..., description="The license key")
    download_limit: int = Field(..., description="The download limit", ge=0)
    downloads_used: int = Field(..., description="The number of downloads used", ge=0)
    is_active: bool = Field(..., description="Whether the license is active")
    created_at: str = Field(..., description="When the license was created")
    expires_at: str = Field(..., description="When the license expires")

class CourseContentCreate(PydanticBaseModel):
    course_id: str = Field(..., description="The course identifier")
    chapter_id: str = Field(..., description="The chapter identifier")
    content_type: str = Field(..., description="The content type")
    file_path: str = Field(..., description="The file path")
    is_protected: bool = Field(True, description="Whether the content is protected")

class CourseContentResponse(PydanticBaseModel):
    id: int = Field(..., description="The content identifier")
    course_id: str = Field(..., description="The course identifier")
    chapter_id: str = Field(..., description="The chapter identifier")
    content_type: str = Field(..., description="The content type")
    file_path: str = Field(..., description="The file path")
    is_protected: bool = Field(..., description="Whether the content is protected")
    created_at: str = Field(..., description="When the content was created")

# Course structure models
class SectionItem(PydanticBaseModel):
    id: str = Field(..., description="The section identifier")
    title: str = Field(..., description="The section title")
    type: str = Field(..., description="The section type")
    file: str = Field(..., description="The file path")

class ChapterItem(PydanticBaseModel):
    id: str = Field(..., description="The chapter identifier")
    title: str = Field(..., description="The chapter title")
    protected: bool = Field(..., description="Whether the chapter is protected")
    sections: List[SectionItem] = Field(..., description="The sections in this chapter")

class CourseStructureResponse(PydanticBaseModel):
    version: str = Field(..., description="The course structure version")
    title: str = Field(..., description="The course title")
    description: str = Field(..., description="The course description")
    chapters: List[ChapterItem] = Field(..., description="The chapters in this course")
    protectedChapters: List[str] = Field(..., description="List of protected chapter IDs")

# Helper functions
def generate_license_key() -> str:
    """Generate a unique license key"""
    return str(uuid.uuid4()).replace("-", "").upper()

def verify_license(license_key: str, course_id: str) -> Optional[License]:
    """Verify if a license is valid for a specific course"""
    try:
        license = License.get(
            (License.license_key == license_key) &
            (License.course_id == course_id) &
            (License.is_active == True)
        )
        
        if license.expires_at > datetime.now(timezone.utc):
            return license
        return None
    except DoesNotExist:
        return None

# Helper function to format datetime
def format_datetime(dt):
    """Format datetime for JSON serialization"""
    if isinstance(dt, str):
        return dt
    return dt.isoformat()

# Routes
@app.get("/")
def root():
    return {"message": "Course Content Provider API"}

@app.get("/health")
def health_check():
    return {"status": "healthy"}

@app.post("/licenses/", response_model=LicenseResponse)
def create_license(license: LicenseCreate):
    """Create a new license for a course"""
    db_license = License.create(
        course_id=license.course_id,
        license_key=generate_license_key(),
        download_limit=license.download_limit,
        downloads_used=0,
        is_active=True,
        created_at=datetime.now(timezone.utc),
        expires_at=datetime.now(timezone.utc) + timedelta(days=365)
    )
    
    return {
        "id": db_license.id,
        "course_id": db_license.course_id,
        "license_key": db_license.license_key,
        "download_limit": db_license.download_limit,
        "downloads_used": db_license.downloads_used,
        "is_active": db_license.is_active,
        "created_at": format_datetime(db_license.created_at),
        "expires_at": format_datetime(db_license.expires_at)
    }

@app.get("/licenses/{license_key}", response_model=LicenseResponse)
def get_license(license_key: str):
    """Retrieve a license by its key"""
    try:
        db_license = License.get(License.license_key == license_key)
        return {
            "id": db_license.id,
            "course_id": db_license.course_id,
            "license_key": db_license.license_key,
            "download_limit": db_license.download_limit,
            "downloads_used": db_license.downloads_used,
            "is_active": db_license.is_active,
            "created_at": format_datetime(db_license.created_at),
            "expires_at": format_datetime(db_license.expires_at)
        }
    except DoesNotExist:
        raise HTTPException(status_code=404, detail="License not found")

@app.get("/catalog/")
def get_course_catalog():
    """Retrieve course catalog information"""
    return {
        "courses": [
            {
                "id": "cpp-primer-5th",
                "name": "C++ Primer 5th Edition",
                "description": "Learn C++ programming with this comprehensive guide",
                "version": "1.0.0",
                "is_free": False
            },
            {
                "id": "python-3rd",
                "name": "Python Programming 3rd Edition",
                "description": "Master Python programming concepts",
                "version": "1.0.0",
                "is_free": True
            }
        ]
    }

@app.get("/courses/{course_id}/structure", response_model=CourseStructureResponse)
def get_course_structure(course_id: str):
    """Retrieve the structure/navigation data for a specific course"""
    # This is a sample implementation - in a real system, this would load from a course-structure.json file
    # or fetch from a remote repository based on the course_id
    
    if course_id == "cpp-primer-5th":
        return CourseStructureResponse(
            version="1.0.0",
            title="C++ Primer 5th Edition",
            description="Learn C++ programming with this comprehensive guide",
            chapters=[
                ChapterItem(
                    id="1_getting_started",
                    title="1. Getting Started",
                    protected=False,
                    sections=[
                        SectionItem(id="1_1_introduction", title="Introduction", type="readme", file="chapters/1_getting_started/introduction.md"),
                        SectionItem(id="1_2_hello_world", title="Hello, World", type="exercise", file="chapters/1_getting_started/hello_world.cpp")
                    ]
                ),
                ChapterItem(
                    id="2_variables",
                    title="2. Variables and Basic Types",
                    protected=False,
                    sections=[
                        SectionItem(id="2_1_variables", title="Variables", type="readme", file="chapters/2_variables/variables.md"),
                        SectionItem(id="2_2_exercise", title="Variables Exercise", type="exercise", file="chapters/2_variables/exercise.cpp")
                    ]
                ),
                ChapterItem(
                    id="7_classes",
                    title="7. Classes",
                    protected=True,
                    sections=[
                        SectionItem(id="7_1_classes", title="Classes", type="readme", file="chapters/7_classes/classes.md"),
                        SectionItem(id="7_2_exercise", title="Classes Exercise", type="exercise", file="chapters/7_classes/exercise.cpp")
                    ]
                )
            ],
            protectedChapters=["7_classes"]
        )
    elif course_id == "python-3rd":
        return CourseStructureResponse(
            version="1.0.0",
            title="Python Programming 3rd Edition",
            description="Master Python programming concepts",
            chapters=[
                ChapterItem(
                    id="1_introduction",
                    title="1. Introduction to Python",
                    protected=False,
                    sections=[
                        SectionItem(id="1_1_welcome", title="Welcome", type="readme", file="chapters/1_introduction/welcome.md"),
                        SectionItem(id="1_2_first_program", title="First Program", type="exercise", file="chapters/1_introduction/first_program.py")
                    ]
                ),
                ChapterItem(
                    id="2_basics",
                    title="2. Python Basics",
                    protected=False,
                    sections=[
                        SectionItem(id="2_1_variables", title="Variables", type="readme", file="chapters/2_basics/variables.md"),
                        SectionItem(id="2_2_exercise", title="Basics Exercise", type="exercise", file="chapters/2_basics/exercise.py")
                    ]
                )
            ],
            protectedChapters=[]
        )
    else:
        raise HTTPException(status_code=404, detail=f"Course {course_id} not found")

@app.post("/content/", response_model=CourseContentResponse)
def create_content(content: CourseContentCreate):
    """Add new course content to the database"""
    db_content = CourseContent.create(
        course_id=content.course_id,
        chapter_id=content.chapter_id,
        content_type=content.content_type,
        file_path=content.file_path,
        is_protected=content.is_protected,
        created_at=datetime.now(timezone.utc)
    )
    
    return {
        "id": db_content.id,
        "course_id": db_content.course_id,
        "chapter_id": db_content.chapter_id,
        "content_type": db_content.content_type,
        "file_path": db_content.file_path,
        "is_protected": db_content.is_protected,
        "created_at": format_datetime(db_content.created_at)
    }

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(
        app, 
        host=config["server"]["host"], 
        port=config["server"]["port"]
    )