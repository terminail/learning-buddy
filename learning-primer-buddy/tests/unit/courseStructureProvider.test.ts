import { MyCoursesProvider } from '../../src/course/myCoursesProvider';
import { CourseContentProtectionManager } from '../../src/courseContentProtectionManager';
import * as vscode from 'vscode';
import { defaultCourseCatalog } from '../../src/course/defaultCourseCatalog';

// Mock the VS Code API
jest.mock('vscode', () => {
    const EventEmitter = jest.fn().mockImplementation(() => {
        return {
            fire: jest.fn(),
            event: jest.fn()
        };
    });
    
    // Mock ThemeIcon
    const ThemeIcon = jest.fn().mockImplementation((iconName) => {
        return {
            id: iconName
        };
    });
    
    return {
        window: {
            showErrorMessage: jest.fn(),
            showInformationMessage: jest.fn()
        },
        extensions: {
            all: [
                {
                    id: 'test.learning-primer-buddy'
                }
            ]
        },
        TreeItem: jest.fn(),
        TreeItemCollapsibleState: {
            None: 0,
            Collapsed: 1
        },
        EventEmitter: EventEmitter,
        ThemeIcon: ThemeIcon,
        ViewColumn: {
            One: 1
        }
    };
});

// Mock CourseContentProtectionManager
jest.mock('../../src/courseContentProtectionManager');

describe('MyCoursesProvider', () => {
    let courseStructureProvider: MyCoursesProvider;
    let mockContext: vscode.ExtensionContext;
    let mockProtectionManager: CourseContentProtectionManager;

    beforeEach(() => {
        // Create a mock context
        mockContext = {
            globalState: {
                get: jest.fn(),
                update: jest.fn()
            },
            extensionPath: '/test/path'
        } as any;

        // Create a mock protection manager
        mockProtectionManager = new CourseContentProtectionManager(mockContext);

        courseStructureProvider = new MyCoursesProvider(mockContext, mockProtectionManager);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    test('should create MyCoursesProvider instance', () => {
        expect(courseStructureProvider).toBeInstanceOf(MyCoursesProvider);
    });

    test('should have refresh method', () => {
        expect(typeof courseStructureProvider.refresh).toBe('function');
    });

    test('should have setPodmanNotAvailable method', () => {
        expect(typeof courseStructureProvider.setPodmanNotAvailable).toBe('function');
    });

    test('should have getTreeItem method', () => {
        expect(typeof courseStructureProvider.getTreeItem).toBe('function');
    });

    test('should have getChildren method', () => {
        expect(typeof courseStructureProvider.getChildren).toBe('function');
    });

    test('should set podman not available status', () => {
        const initialFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        courseStructureProvider.setPodmanNotAvailable(true);
        const finalFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        
        expect(finalFireCount).toBe(initialFireCount + 1);
    });

    test('should refresh course structure', async () => {
        const initialFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        await courseStructureProvider.refresh();
        const finalFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        
        expect(finalFireCount).toBe(initialFireCount + 1);
    });

    test('should get tree item', () => {
        // Create a mock course item
        const mockCourseItem = {
            label: 'Test Chapter',
            collapsibleState: 0 // None
        };
        
        const result = courseStructureProvider.getTreeItem(mockCourseItem as any);
        expect(result).toBe(mockCourseItem);
    });

    test('should get root children when podman is not available', async () => {
        // Set mock podman status to not available
        (courseStructureProvider as any).mockPodmanInstalled = false;
        
        const children = await courseStructureProvider.getChildren();
        expect(children).toBeDefined();
        expect(Array.isArray(children)).toBe(true);
    });

    test('should get root children when podman is available', async () => {
        // Set mock podman status to available
        (courseStructureProvider as any).mockPodmanInstalled = true;
        
        const children = await courseStructureProvider.getChildren();
        expect(children).toBeDefined();
        expect(Array.isArray(children)).toBe(true);
    });

    test('should get child items for a chapter', async () => {
        // Create a mock chapter item
        const mockChapterItem = {
            label: 'Test Chapter',
            fullPath: '1_getting_started',
            collapsibleState: 1 // Collapsed
        };
        
        const children = await courseStructureProvider.getChildren(mockChapterItem as any);
        expect(children).toBeDefined();
        expect(Array.isArray(children)).toBe(true);
    });

    test('should toggle mock podman status', () => {
        const initialStatus = courseStructureProvider.getMockPodmanStatus();
        courseStructureProvider.toggleMockPodmanStatus();
        const toggledStatus = courseStructureProvider.getMockPodmanStatus();
        
        expect(toggledStatus).toBe(!initialStatus);
    });

    test('should get current mock podman status', () => {
        const status = courseStructureProvider.getMockPodmanStatus();
        expect(typeof status).toBe('boolean');
    });

    test('should use EXACT data from defaultCourseCatalog.ts for fallback', async () => {
        // Verify that the defaultCourseCatalog contains the EXACT expected data
        expect(defaultCourseCatalog).toBeDefined();
        expect(defaultCourseCatalog.courses).toBeDefined();
        expect(Array.isArray(defaultCourseCatalog.courses)).toBe(true);
        expect(defaultCourseCatalog.courses.length).toBe(1); // Should have exactly 1 course
        
        // Verify the first course is C++ Primer with EXACT data
        const firstCourse = defaultCourseCatalog.courses[0];
        expect(firstCourse.id).toBe('cpp-primer-5th');
        expect(firstCourse.title).toBe('C++ Primer 5th Edition');
        expect(firstCourse.description).toBe('Learning path for C++ Primer 5th Edition');
        expect(firstCourse.type).toBe('course');
        
        // Verify exercises exist with EXACT data
        expect(Array.isArray(firstCourse.exercises)).toBe(true);
        expect(firstCourse.exercises.length).toBe(3); // Should have exactly 3 exercises
        
        // Verify EXACT exercise data
        const [exercise1, exercise2, exercise3] = firstCourse.exercises;
        
        // Exercise 1: Getting Started
        expect(exercise1.id).toBe('getting_started');
        expect(exercise1.title).toBe('1. Getting Started');
        expect(exercise1.description).toBe('Introduction to C++ programming');
        expect(exercise1.type).toBe('exercise');
        
        // Exercise 1 folders and files
        expect(Array.isArray(exercise1.folders)).toBe(true);
        expect(exercise1.folders.length).toBe(1);
        const examplesFolder = exercise1.folders[0];
        expect(examplesFolder.id).toBe('examples');
        expect(examplesFolder.name).toBe('examples');
        expect(examplesFolder.path).toBe('/1_getting_started/examples');
        expect(examplesFolder.type).toBe('folder');
        expect(Array.isArray(examplesFolder.folders)).toBe(true);
        expect(examplesFolder.folders.length).toBe(0);
        expect(Array.isArray(examplesFolder.files)).toBe(true);
        expect(examplesFolder.files.length).toBe(2);
        
        // Examples folder files
        const [helloCpp, variablesCpp] = examplesFolder.files;
        expect(helloCpp.id).toBe('hello_cpp');
        expect(helloCpp.name).toBe('hello.cpp');
        expect(helloCpp.path).toBe('/1_getting_started/examples/hello.cpp');
        expect(helloCpp.extension).toBe('cpp');
        expect(helloCpp.type).toBe('file');
        
        expect(variablesCpp.id).toBe('variables_cpp');
        expect(variablesCpp.name).toBe('variables.cpp');
        expect(variablesCpp.path).toBe('/1_getting_started/examples/variables.cpp');
        expect(variablesCpp.extension).toBe('cpp');
        expect(variablesCpp.type).toBe('file');
        
        // Exercise 1 direct files
        expect(Array.isArray(exercise1.files)).toBe(true);
        expect(exercise1.files.length).toBe(3);
        const [introCpp, helloWorld, compilingGuide] = exercise1.files;
        expect(introCpp.id).toBe('intro_cpp');
        expect(introCpp.name).toBe('introduction.md');
        expect(introCpp.path).toBe('/1_getting_started/introduction.md');
        expect(introCpp.extension).toBe('md');
        expect(introCpp.type).toBe('file');
        
        expect(helloWorld.id).toBe('hello_world');
        expect(helloWorld.name).toBe('hello_world.cpp');
        expect(helloWorld.path).toBe('/1_getting_started/hello_world.cpp');
        expect(helloWorld.extension).toBe('cpp');
        expect(helloWorld.type).toBe('file');
        
        expect(compilingGuide.id).toBe('compiling_guide');
        expect(compilingGuide.name).toBe('compiling_guide.md');
        expect(compilingGuide.path).toBe('/1_getting_started/compiling_guide.md');
        expect(compilingGuide.extension).toBe('md');
        expect(compilingGuide.type).toBe('file');
        
        // Exercise 2: Variables and Basic Types
        expect(exercise2.id).toBe('variables_basic_types');
        expect(exercise2.title).toBe('2. Variables and Basic Types');
        expect(exercise2.description).toBe('Understanding variables and basic data types in C++');
        expect(exercise2.type).toBe('exercise');
        
        // Exercise 2 folders and files
        expect(Array.isArray(exercise2.folders)).toBe(true);
        expect(exercise2.folders.length).toBe(1);
        const exercisesFolder = exercise2.folders[0];
        expect(exercisesFolder.id).toBe('exercises');
        expect(exercisesFolder.name).toBe('exercises');
        expect(exercisesFolder.path).toBe('/2_variables/exercises');
        expect(exercisesFolder.type).toBe('folder');
        expect(Array.isArray(exercisesFolder.folders)).toBe(true);
        expect(exercisesFolder.folders.length).toBe(1);
        expect(Array.isArray(exercisesFolder.files)).toBe(true);
        expect(exercisesFolder.files.length).toBe(2);
        
        // Exercise 2 nested folders
        const solutionsFolder = exercisesFolder.folders[0];
        expect(solutionsFolder.id).toBe('solutions');
        expect(solutionsFolder.name).toBe('solutions');
        expect(solutionsFolder.path).toBe('/2_variables/exercises/solutions');
        expect(solutionsFolder.type).toBe('folder');
        expect(Array.isArray(solutionsFolder.folders)).toBe(true);
        expect(solutionsFolder.folders.length).toBe(0);
        expect(Array.isArray(solutionsFolder.files)).toBe(true);
        expect(solutionsFolder.files.length).toBe(2);
        
        // Solutions folder files
        const [solution1, solution2] = solutionsFolder.files;
        expect(solution1.id).toBe('solution1');
        expect(solution1.name).toBe('solution1.cpp');
        expect(solution1.path).toBe('/2_variables/exercises/solutions/solution1.cpp');
        expect(solution1.extension).toBe('cpp');
        expect(solution1.type).toBe('file');
        
        expect(solution2.id).toBe('solution2');
        expect(solution2.name).toBe('solution2.cpp');
        expect(solution2.path).toBe('/2_variables/exercises/solutions/solution2.cpp');
        expect(solution2.extension).toBe('cpp');
        expect(solution2.type).toBe('file');
        
        // Exercise 2 direct files in exercises folder
        const [exercise1File, exercise2File] = exercisesFolder.files;
        expect(exercise1File.id).toBe('exercise1');
        expect(exercise1File.name).toBe('exercise1.cpp');
        expect(exercise1File.path).toBe('/2_variables/exercises/exercise1.cpp');
        expect(exercise1File.extension).toBe('cpp');
        expect(exercise1File.type).toBe('file');
        
        expect(exercise2File.id).toBe('exercise2');
        expect(exercise2File.name).toBe('exercise2.cpp');
        expect(exercise2File.path).toBe('/2_variables/exercises/exercise2.cpp');
        expect(exercise2File.extension).toBe('cpp');
        expect(exercise2File.type).toBe('file');
        
        // Exercise 2 direct files
        expect(Array.isArray(exercise2.files)).toBe(true);
        expect(exercise2.files.length).toBe(3);
        const [variablesOverview, dataTypes, typeConversion] = exercise2.files;
        expect(variablesOverview.id).toBe('variables_overview');
        expect(variablesOverview.name).toBe('variables_overview.md');
        expect(variablesOverview.path).toBe('/2_variables/variables_overview.md');
        expect(variablesOverview.extension).toBe('md');
        expect(variablesOverview.type).toBe('file');
        
        expect(dataTypes.id).toBe('data_types');
        expect(dataTypes.name).toBe('data_types.cpp');
        expect(dataTypes.path).toBe('/2_variables/data_types.cpp');
        expect(dataTypes.extension).toBe('cpp');
        expect(dataTypes.type).toBe('file');
        
        expect(typeConversion.id).toBe('type_conversion');
        expect(typeConversion.name).toBe('type_conversion.cpp');
        expect(typeConversion.path).toBe('/2_variables/type_conversion.cpp');
        expect(typeConversion.extension).toBe('cpp');
        expect(typeConversion.type).toBe('file');
        
        // Exercise 3: Strings, Vectors, and Arrays
        expect(exercise3.id).toBe('strings_vectors_arrays');
        expect(exercise3.title).toBe('3. Strings, Vectors, and Arrays');
        expect(exercise3.description).toBe('Working with strings, vectors, and arrays in C++');
        expect(exercise3.type).toBe('exercise');
        
        // Exercise 3 folders and files
        expect(Array.isArray(exercise3.folders)).toBe(true);
        expect(exercise3.folders.length).toBe(1);
        const projectsFolder = exercise3.folders[0];
        expect(projectsFolder.id).toBe('projects');
        expect(projectsFolder.name).toBe('projects');
        expect(projectsFolder.path).toBe('/3_strings/projects');
        expect(projectsFolder.type).toBe('folder');
        expect(Array.isArray(projectsFolder.folders)).toBe(true);
        expect(projectsFolder.folders.length).toBe(1);
        expect(Array.isArray(projectsFolder.files)).toBe(true);
        expect(projectsFolder.files.length).toBe(0);
        
        // Exercise 3 nested folders
        const stringAnalyzerFolder = projectsFolder.folders[0];
        expect(stringAnalyzerFolder.id).toBe('string_analyzer');
        expect(stringAnalyzerFolder.name).toBe('string_analyzer');
        expect(stringAnalyzerFolder.path).toBe('/3_strings/projects/string_analyzer');
        expect(stringAnalyzerFolder.type).toBe('folder');
        expect(Array.isArray(stringAnalyzerFolder.folders)).toBe(true);
        expect(stringAnalyzerFolder.folders.length).toBe(0);
        expect(Array.isArray(stringAnalyzerFolder.files)).toBe(true);
        expect(stringAnalyzerFolder.files.length).toBe(4);
        
        // String analyzer folder files
        const [mainCpp, stringUtilsCpp, stringUtilsH, makefile] = stringAnalyzerFolder.files;
        expect(mainCpp.id).toBe('main');
        expect(mainCpp.name).toBe('main.cpp');
        expect(mainCpp.path).toBe('/3_strings/projects/string_analyzer/main.cpp');
        expect(mainCpp.extension).toBe('cpp');
        expect(mainCpp.type).toBe('file');
        
        expect(stringUtilsCpp.id).toBe('string_utils_cpp');
        expect(stringUtilsCpp.name).toBe('string_utils.cpp');
        expect(stringUtilsCpp.path).toBe('/3_strings/projects/string_analyzer/string_utils.cpp');
        expect(stringUtilsCpp.extension).toBe('cpp');
        expect(stringUtilsCpp.type).toBe('file');
        
        expect(stringUtilsH.id).toBe('string_utils_h');
        expect(stringUtilsH.name).toBe('string_utils.h');
        expect(stringUtilsH.path).toBe('/3_strings/projects/string_analyzer/string_utils.h');
        expect(stringUtilsH.extension).toBe('h');
        expect(stringUtilsH.type).toBe('file');
        
        expect(makefile.id).toBe('makefile');
        expect(makefile.name).toBe('Makefile');
        expect(makefile.path).toBe('/3_strings/projects/string_analyzer/Makefile');
        expect(makefile.extension).toBe('makefile');
        expect(makefile.type).toBe('file');
        
        // Exercise 3 direct files
        expect(Array.isArray(exercise3.files)).toBe(true);
        expect(exercise3.files.length).toBe(4);
        const [stringsBasics, stringOperations, vectorsGuide, arraysBasics] = exercise3.files;
        expect(stringsBasics.id).toBe('strings_basics');
        expect(stringsBasics.name).toBe('strings_basics.md');
        expect(stringsBasics.path).toBe('/3_strings/strings_basics.md');
        expect(stringsBasics.extension).toBe('md');
        expect(stringsBasics.type).toBe('file');
        
        expect(stringOperations.id).toBe('string_operations');
        expect(stringOperations.name).toBe('string_operations.cpp');
        expect(stringOperations.path).toBe('/3_strings/string_operations.cpp');
        expect(stringOperations.extension).toBe('cpp');
        expect(stringOperations.type).toBe('file');
        
        expect(vectorsGuide.id).toBe('vectors_guide');
        expect(vectorsGuide.name).toBe('vectors_guide.md');
        expect(vectorsGuide.path).toBe('/3_strings/vectors_guide.md');
        expect(vectorsGuide.extension).toBe('md');
        expect(vectorsGuide.type).toBe('file');
        
        expect(arraysBasics.id).toBe('arrays_basics');
        expect(arraysBasics.name).toBe('arrays_basics.cpp');
        expect(arraysBasics.path).toBe('/3_strings/arrays_basics.cpp');
        expect(arraysBasics.extension).toBe('cpp');
        expect(arraysBasics.type).toBe('file');
    });
    
    test('should fallback to EXACT default course catalog when remote loading fails', async () => {
        // Mock the loadDefaultCourseStructure method to simulate failure
        const mockLoadDefaultCourseStructure = jest.spyOn(courseStructureProvider as any, 'loadDefaultCourseStructure');
        mockLoadDefaultCourseStructure.mockImplementation(async () => {
            // Simulate failure to load from remote, should fallback to default
            (courseStructureProvider as any).defaultCourseStructure = (courseStructureProvider as any).provideMySampleCourseCatalog();
        });
        
        // Refresh to trigger the fallback mechanism
        await courseStructureProvider.refresh();
        
        // Verify that the default course structure is set to the EXACT defaultCourseCatalog
        expect((courseStructureProvider as any).defaultCourseStructure).toBe(defaultCourseCatalog);
        
        // Verify that the structure contains the EXACT expected course
        const courseStructure = (courseStructureProvider as any).defaultCourseStructure;
        expect(courseStructure.courses[0].id).toBe('cpp-primer-5th');
        expect(courseStructure.courses[0].title).toBe('C++ Primer 5th Edition');
        
        // Verify that the exercises are EXACTLY as defined in defaultCourseCatalog.ts
        const exercises = courseStructure.courses[0].exercises;
        expect(exercises[0].id).toBe('getting_started');
        expect(exercises[0].title).toBe('1. Getting Started');
        expect(exercises[1].id).toBe('variables_basic_types');
        expect(exercises[1].title).toBe('2. Variables and Basic Types');
        expect(exercises[2].id).toBe('strings_vectors_arrays');
        expect(exercises[2].title).toBe('3. Strings, Vectors, and Arrays');
    });
    
    test('should provide course content structure using EXACT data from defaultCourseCatalog.ts', async () => {
        // Set the default course structure to the EXACT defaultCourseCatalog
        (courseStructureProvider as any).defaultCourseStructure = defaultCourseCatalog;
        
        // Get course content structure for the cpp-primer-5th course
        const courseContent = (courseStructureProvider as any).provideCourseContentStructure('cpp-primer-5th');
        
        // Verify that the course content structure uses EXACT data from defaultCourseCatalog.ts
        expect(Array.isArray(courseContent)).toBe(true);
        expect(courseContent.length).toBe(3); // Should have exactly 3 exercises
        
        // Verify EXACT exercise titles from defaultCourseCatalog.ts
        const exerciseTitles = courseContent.map((item: any) => item.label);
        expect(exerciseTitles).toContain('📘 1. Getting Started');
        expect(exerciseTitles).toContain('📘 2. Variables and Basic Types');
        expect(exerciseTitles).toContain('📘 3. Strings, Vectors, and Arrays');
        
        // Verify EXACT exercise IDs from defaultCourseCatalog.ts
        const exerciseIds = courseContent.map((item: any) => item.fullPath);
        expect(exerciseIds).toContain('getting_started');
        expect(exerciseIds).toContain('variables_basic_types');
        expect(exerciseIds).toContain('strings_vectors_arrays');
    });
});