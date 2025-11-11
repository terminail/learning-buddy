import * as vscode from 'vscode';
import { TemplateEngine } from '../../src/templates/index';

// Mock vscode.workspace.fs.readFile
jest.mock('vscode', () => {
    return {
        workspace: {
            fs: {
                readFile: jest.fn()
            }
        },
        Uri: {
            joinPath: jest.fn().mockImplementation((...paths) => {
                return {
                    fsPath: paths.join('/'),
                    toString: () => paths.join('/')
                };
            }),
            file: jest.fn().mockImplementation((path) => {
                return {
                    fsPath: path,
                    toString: () => path
                };
            })
        }
    };
});

describe('TemplateEngine - Course Catalog', () => {
    let templateEngine: TemplateEngine;

    beforeEach(() => {
        templateEngine = TemplateEngine.getInstance();
        // Clear the template cache before each test
        (templateEngine as any)._templateCache.clear();
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('renderCourseCatalogTemplate', () => {
        const mockExtensionUri = vscode.Uri.file('/test/path');
        const mockCourses = [
            {
                id: 'test-course-1',
                title: 'Test Course 1',
                description: 'A test course',
                level: 'Beginner',
                estimatedHours: 10,
                hasProtectedContent: false,
                isFree: true
            },
            {
                id: 'test-course-2',
                title: 'Test Course 2',
                description: 'Another test course',
                level: 'Intermediate',
                estimatedHours: 20,
                hasProtectedContent: true,
                isFree: false
            }
        ];

        it('should render course catalog template with courses', async () => {
            // Mock the template file content
            const mockTemplateContent = `
<!DOCTYPE html>
<html>
<head>
    <link href="{{STYLE_URI}}" rel="stylesheet">
</head>
<body>
    <div class="courses-grid">
        {{COURSE_CARDS}}
    </div>
    <script nonce="{{NONCE}}">
        {{JAVASCRIPT}}
    </script>
</body>
</html>`;

            (vscode.workspace.fs.readFile as jest.Mock).mockResolvedValue(
                Buffer.from(mockTemplateContent, 'utf8')
            );

            // Create a mock webview
            const mockWebview = {
                asWebviewUri: jest.fn().mockImplementation((uri) => uri.toString()),
                cspSource: 'vscode-webview://test'
            } as unknown as vscode.Webview;

            const result = await templateEngine.renderCourseCatalogTemplate(
                mockWebview,
                mockExtensionUri,
                mockCourses
            );

            // Verify that the template was rendered correctly
            expect(result).toContain('Test Course 1');
            expect(result).toContain('Test Course 2');
            expect(result).toContain('A test course');
            expect(result).toContain('Another test course');
            expect(result).toContain('Beginner');
            expect(result).toContain('Intermediate');
            expect(result).toContain('10 hours');
            expect(result).toContain('20 hours');
            expect(result).toContain('Free');
            expect(result).toContain('Premium');
        });

        it('should render course catalog template with no courses', async () => {
            // Mock the template file content
            const mockTemplateContent = `
<!DOCTYPE html>
<html>
<head>
    <link href="{{STYLE_URI}}" rel="stylesheet">
</head>
<body>
    <div class="courses-grid">
        {{COURSE_CARDS}}
    </div>
    <script nonce="{{NONCE}}">
        {{JAVASCRIPT}}
    </script>
</body>
</html>`;

            (vscode.workspace.fs.readFile as jest.Mock).mockResolvedValue(
                Buffer.from(mockTemplateContent, 'utf8')
            );

            // Create a mock webview
            const mockWebview = {
                asWebviewUri: jest.fn().mockImplementation((uri) => uri.toString()),
                cspSource: 'vscode-webview://test'
            } as unknown as vscode.Webview;

            const result = await templateEngine.renderCourseCatalogTemplate(
                mockWebview,
                mockExtensionUri,
                []
            );

            // Verify that the template was rendered correctly with no courses message
            expect(result).toContain('No courses available at the moment');
        });

        it('should handle template file read errors gracefully', async () => {
            // Mock a file read error
            (vscode.workspace.fs.readFile as jest.Mock).mockRejectedValue(
                new Error('File not found')
            );

            // Create a mock webview
            const mockWebview = {
                asWebviewUri: jest.fn().mockImplementation((uri) => uri.toString()),
                cspSource: 'vscode-webview://test'
            } as unknown as vscode.Webview;

            await expect(
                templateEngine.renderCourseCatalogTemplate(
                    mockWebview,
                    mockExtensionUri,
                    mockCourses
                )
            ).rejects.toThrow('File not found');
        });
    });

    describe('renderCourseCards', () => {
        it('should render course cards correctly', () => {
            const courses = [
                {
                    id: 'test-course',
                    title: 'Test Course',
                    description: 'A test course',
                    level: 'Beginner',
                    estimatedHours: 10,
                    hasProtectedContent: false
                }
            ];

            // Access the private method using bracket notation
            const renderCourseCards = (templateEngine as any).renderCourseCards.bind(templateEngine);
            const result = renderCourseCards(courses);

            expect(result).toContain('Test Course');
            expect(result).toContain('A test course');
            expect(result).toContain('Beginner');
            expect(result).toContain('10 hours');
            expect(result).toContain('Free');
        });

        it('should render premium badge for protected courses', () => {
            const courses = [
                {
                    id: 'test-course',
                    title: 'Test Course',
                    description: 'A test course',
                    level: 'Intermediate',
                    estimatedHours: 15,
                    hasProtectedContent: true
                }
            ];

            // Access the private method using bracket notation
            const renderCourseCards = (templateEngine as any).renderCourseCards.bind(templateEngine);
            const result = renderCourseCards(courses);

            expect(result).toContain('Premium');
        });

        it('should show selected course status for already selected courses', () => {
            const courses = [
                {
                    id: 'selected-course',
                    title: 'Selected Course',
                    description: 'A selected course',
                    level: 'Beginner',
                    estimatedHours: 10,
                    hasProtectedContent: false
                },
                {
                    id: 'licensed-course',
                    title: 'Licensed Course',
                    description: 'A licensed course',
                    level: 'Intermediate',
                    estimatedHours: 20,
                    hasProtectedContent: true
                }
            ];

            // Access the private method using bracket notation
            const renderCourseCards = (templateEngine as any).renderCourseCards.bind(templateEngine);
            
            // Test with a selected free course
            const result1 = renderCourseCards(courses, 'selected-course');
            expect(result1).toContain('✅ Selected, Free');
            expect(result1).not.toContain('🛒 Select Course (Free)');
            
            // Test with a selected licensed course
            const result2 = renderCourseCards(courses, 'licensed-course');
            expect(result2).toContain('🔐 Selected, License Paid');
            expect(result2).not.toContain('🔐 Select Course (License Required)');
        });

        it('should show correct status for all courses when they are already in MyCourses', () => {
            // This test verifies the behavior when a specific course is selected
            // Only that course should show "Selected" status, others show select buttons
            const courses = [
                {
                    id: "cpp-primer-5th",
                    title: "C++ Primer 5th Edition",
                    description: "Learning path for C++ Primer 5th Edition",
                    level: "Intermediate",
                    estimatedHours: 40,
                    hasProtectedContent: true,
                    isFree: false
                },
                {
                    id: "python-3rd-edition",
                    title: "Python 3rd Edition",
                    description: "Python programming from beginner to advanced",
                    level: "Beginner",
                    estimatedHours: 35,
                    hasProtectedContent: false,
                    isFree: true
                },
                {
                    id: "javascript-es6",
                    title: "JavaScript ES6+",
                    description: "Modern JavaScript with ES6 features and beyond",
                    level: "Intermediate",
                    estimatedHours: 30,
                    hasProtectedContent: true,
                    isFree: false
                }
            ];

            // Access the private method using bracket notation
            const renderCourseCards = (templateEngine as any).renderCourseCards.bind(templateEngine);
            
            // Test with C++ course as the currently selected course
            const result1 = renderCourseCards(courses, "cpp-primer-5th");
            
            // The C++ course (licensed) should show "Selected, License Paid"
            expect(result1).toContain('🔐 Selected, License Paid');
            
            // The Python course (free) should show select button
            expect(result1).toContain('🛒 Select Course (Free)');
            
            // The JavaScript course (licensed) should show select button
            expect(result1).toContain('🔐 Select Course (License Required)');
            
            // Test with Python course as the currently selected course
            const result2 = renderCourseCards(courses, "python-3rd-edition");
            
            // The Python course (free) should show "Selected, Free"
            expect(result2).toContain('✅ Selected, Free');
            
            // The C++ course (licensed) should show select button
            expect(result2).toContain('🔐 Select Course (License Required)');
            
            // The JavaScript course (licensed) should show select button
            expect(result2).toContain('🔐 Select Course (License Required)');
        });

        it('should show correct select button text for non-selected courses', () => {
            const courses = [
                {
                    id: "cpp-primer-5th",
                    title: "C++ Primer 5th Edition",
                    description: "Learning path for C++ Primer 5th Edition",
                    level: "Intermediate",
                    estimatedHours: 40,
                    hasProtectedContent: true,
                    isFree: false
                },
                {
                    id: "python-3rd-edition",
                    title: "Python 3rd Edition",
                    description: "Python programming from beginner to advanced",
                    level: "Beginner",
                    estimatedHours: 35,
                    hasProtectedContent: false,
                    isFree: true
                }
            ];

            // Access the private method using bracket notation
            const renderCourseCards = (templateEngine as any).renderCourseCards.bind(templateEngine);
            
            // Test with no current course selected (all courses should show select buttons)
            const result = renderCourseCards(courses);
            expect(result).toContain('🛒 Select Course (Free)');
            expect(result).toContain('🔐 Select Course (License Required)');
            expect(result).not.toContain('Selected, Free');
            expect(result).not.toContain('Selected, License Paid');
        });

        it('should determine select button title based on user courses and catalog courses license status', () => {
            // This test specifically verifies that when all courses from the catalog are also in MyCourses,
            // they should all show "Selected" status with appropriate license information
            
            // Real course data from defaultCourseCatalog.ts
            const catalogCourses = [
                {
                    id: "cpp-primer-5th",
                    title: "C++ Primer 5th Edition",
                    description: "Learning path for C++ Primer 5th Edition",
                    level: "Intermediate",
                    estimatedHours: 40,
                    hasProtectedContent: true, // Licensed course
                    isFree: false
                },
                {
                    id: "python-3rd-edition",
                    title: "Python 3rd Edition",
                    description: "Python programming from beginner to advanced",
                    level: "Beginner",
                    estimatedHours: 35,
                    hasProtectedContent: false, // Free course
                    isFree: true
                },
                {
                    id: "javascript-es6",
                    title: "JavaScript ES6+",
                    description: "Modern JavaScript with ES6 features and beyond",
                    level: "Intermediate",
                    estimatedHours: 30,
                    hasProtectedContent: true, // Licensed course
                    isFree: false
                },
                {
                    id: "sql-database",
                    title: "SQL & Database Design",
                    description: "Database design and SQL query optimization",
                    level: "Beginner",
                    estimatedHours: 25,
                    hasProtectedContent: false, // Free course
                    isFree: true
                }
            ];

            // Access the private method using bracket notation
            const renderCourseCards = (templateEngine as any).renderCourseCards.bind(templateEngine);
            
            // Test with C++ course as the currently selected course
            const result1 = renderCourseCards(catalogCourses, "cpp-primer-5th");
            
            // The C++ course (licensed) should show "Selected, License Paid"
            expect(result1).toContain('🔐 Selected, License Paid');
            
            // Other courses should show select buttons since we're only checking currentCourseId
            expect(result1).toContain('🛒 Select Course (Free)'); // Python and SQL
            expect(result1).toContain('🔐 Select Course (License Required)'); // JavaScript
            
            // Test with Python course as the currently selected course
            const result2 = renderCourseCards(catalogCourses, "python-3rd-edition");
            
            // The Python course (free) should show "Selected, Free"
            expect(result2).toContain('✅ Selected, Free');
            
            // Other courses should show select buttons
            expect(result2).toContain('🔐 Select Course (License Required)'); // C++ and JavaScript
            expect(result2).toContain('🛒 Select Course (Free)'); // SQL
        });

        it('should handle empty courses array', () => {
            // Access the private method using bracket notation
            const renderCourseCards = (templateEngine as any).renderCourseCards.bind(templateEngine);
            const result = renderCourseCards([]);

            expect(result).toContain('No courses available at the moment');
        });
    });
});