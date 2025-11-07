import * as vscode from 'vscode';
import * as path from 'path';
import * as fs from 'fs';
import * as https from 'https';
import { ContentProtectionManager, LicenseInfo } from './contentProtection';
import { GiteeContentDelivery } from './giteeContentDelivery';

// Simple HTTPS request function as an alternative to fetch
function httpsRequest(url: string, options: any = {}): Promise<any> {
    return new Promise((resolve, reject) => {
        const urlObj = new URL(url);
        const requestOptions = {
            hostname: urlObj.hostname,
            port: urlObj.port,
            path: urlObj.pathname + urlObj.search,
            method: options.method || 'GET',
            headers: options.headers || {}
        };

        const req = https.request(requestOptions, (res) => {
            let data = '';
            
            res.on('data', (chunk) => {
                data += chunk;
            });
            
            res.on('end', () => {
                try {
                    const jsonData = JSON.parse(data);
                    resolve({
                        ok: (res.statusCode || 0) >= 200 && (res.statusCode || 0) < 300,
                        status: res.statusCode || 0,
                        statusText: res.statusMessage || '',
                        json: () => Promise.resolve(jsonData),
                        text: () => Promise.resolve(data)
                    });
                } catch (error) {
                    resolve({
                        ok: (res.statusCode || 0) >= 200 && (res.statusCode || 0) < 300,
                        status: res.statusCode || 0,
                        statusText: res.statusMessage || '',
                        text: () => Promise.resolve(data)
                    });
                }
            });
        });
        
        req.on('error', (error) => {
            reject(error);
        });
        
        if (options.body) {
            req.write(options.body);
        }
        
        req.end();
    });
}

// Define the course structure types
interface CourseSection {
    id: string;
    title: string;
    type: 'exercise' | 'solution' | 'hint' | 'readme' | 'directory';
    file?: string;
}

interface CourseChapter {
    id: string;
    title: string;
    protected: boolean;
    sections?: CourseSection[];
}

interface CourseStructure {
    version: string;
    title: string;
    description: string;
    chapters: CourseChapter[];
    protectedChapters: string[];
}

// Define the course catalog types
interface CourseRepository {
    type: string;
    url: string;
    branch: string;
}

interface CourseInfo {
    id: string;
    name: string;
    description: string;
    repository: CourseRepository;
    icon?: string;
    level?: string;
    estimatedHours?: number;
}

interface CourseCatalog {
    version: string;
    courses: CourseInfo[];
}

export class StudyItem extends vscode.TreeItem {
	constructor(
		public readonly label: string,
		public readonly collapsibleState: vscode.TreeItemCollapsibleState,
		public readonly fullPath: string,
		public readonly isLocked: boolean = false,
		public readonly isDirectory: boolean = false,
		public readonly itemType: 'exercise' | 'solution' | 'hint' | 'readme' | 'directory' | 'promotion' | 'courseCatalog' = 'exercise'
	) {
		super(label, collapsibleState);
		
		(this as any).tooltip = this.label;
		// Remove locked indicator to make locked items appear identical to free items
		(this as any).description = '';
		
		// Use the same context value for all items to maintain consistent UI
		switch (itemType) {
			case 'exercise':
				(this as any).contextValue = 'studyItem';
				break;
			case 'solution':
				(this as any).contextValue = 'solutionItem';
				break;
			case 'hint':
				(this as any).contextValue = 'hintItem';
				break;
			case 'readme':
				(this as any).contextValue = 'readmeItem';
				break;
			case 'directory':
				(this as any).contextValue = 'directoryItem';
				break;
			case 'promotion':
				(this as any).contextValue = 'promotionItem';
				break;
			case 'courseCatalog':
				(this as any).contextValue = 'courseCatalogItem';
				break;
		}
		
		// Set icon based on item type (same icons for locked and unlocked items)
		if (isDirectory) {
			(this as any).iconPath = new vscode.ThemeIcon('folder');
		} else {
			switch (itemType) {
				case 'exercise':
					(this as any).iconPath = new vscode.ThemeIcon('file-code');
					break;
				case 'solution':
					(this as any).iconPath = new vscode.ThemeIcon('eye');
					break;
				case 'hint':
					(this as any).iconPath = new vscode.ThemeIcon('lightbulb');
					break;
				case 'readme':
					(this as any).iconPath = new vscode.ThemeIcon('book');
					break;
				case 'promotion':
					(this as any).iconPath = new vscode.ThemeIcon('megaphone');
					break;
				case 'courseCatalog':
					(this as any).iconPath = new vscode.ThemeIcon('library');
					break;
				default:
					(this as any).iconPath = new vscode.ThemeIcon('file');
			}
		}
	}
}

export class CppPrimerTreeViewProvider implements vscode.TreeDataProvider<StudyItem> {
	private _onDidChangeTreeData: vscode.EventEmitter<StudyItem | undefined | void> = new vscode.EventEmitter<StudyItem | undefined | void>();
	readonly onDidChangeTreeData: vscode.Event<StudyItem | undefined | void> = this._onDidChangeTreeData.event;
	private protectionManager: ContentProtectionManager;
	private giteeContentDelivery: GiteeContentDelivery;
	private defaultCourseStructure: CourseStructure | null = null;
	private defaultCourseCatalog: CourseCatalog | null = null;
	// Remove currentCourseStructure and currentCourseId since we're not switching courses anymore

	constructor(private context: vscode.ExtensionContext) {
		this.protectionManager = new ContentProtectionManager(context);
		this.giteeContentDelivery = new GiteeContentDelivery(context);
		// Load default course structure and catalog when the provider is initialized
		this.loadDefaultCourseStructure();
		this.loadDefaultCourseCatalog();
		// No need to set current course structure since we're not switching courses
	}

	getTreeItem(element: StudyItem): vscode.TreeItem {
		return element;
	}

	getChildren(element?: StudyItem): vscode.ProviderResult<StudyItem[]> {
		if (!element) {
			// Root level items - chapters + promotional courses
			const items: StudyItem[] = [];
			
			// Add course chapters
			items.push(...this.getRootItems());
			
			// Add promotional courses section
			items.push(new StudyItem(
				'Discover More Courses',
				vscode.TreeItemCollapsibleState.None,
				'promotional_courses',
				false,
				false,
				'promotion'
			));
			
			return Promise.resolve(items);
		} else {
			// Handle different types of items
			if (element.fullPath === 'promotional_courses') {
				// Show promotion for generic Learning Buddy extension
				return Promise.resolve([new StudyItem(
					'Get Generic Learning Buddy Extension',
					vscode.TreeItemCollapsibleState.None,
					'generic_learning_buddy_promo',
					false,
					false,
					'promotion'
				)]);
			} else {
				// Child items - exercises and materials
				return Promise.resolve(this.getChildItems(element));
			}
		}
	}

	private getCurrentCourseId(): string {
		// Extract course ID from extension name
		// For example, "cpp-primer-5th-buddy" -> "cpp-primer-5th"
		const extensionName = vscode.extensions.all
			.find(ext => ext.id.includes('buddy'))?.id.split('.')[1] || 'cpp-primer-5th';
		
		return extensionName.replace('-buddy', '');
	}

	private async loadDefaultCourseStructure(): Promise<void> {
		try {
			// Try to load from cache first
			const cachedStructure = this.context.globalState.get<CourseStructure>(`courseStructure_${this.getCurrentCourseId()}`);
			if (cachedStructure) {
				this.defaultCourseStructure = cachedStructure;
			}

			// Try to load from remote repository
			const structure = await this.fetchCourseStructureFromRepository();
			if (structure) {
				this.defaultCourseStructure = structure;
				// Cache the structure
				this.context.globalState.update(`courseStructure_${this.getCurrentCourseId()}`, structure);
			} else if (this.defaultCourseStructure) {
				// Already have cached structure
				return;
			} else {
				// Fallback to default structure
				this.defaultCourseStructure = this.getDefaultCourseStructure();
			}
		} catch (error) {
			console.error('Error loading default course structure:', error);
			// Fallback to default structure
			this.defaultCourseStructure = this.getDefaultCourseStructure();
		}
	}

	private async loadDefaultCourseCatalog(): Promise<void> {
		try {
			// Try to load from remote repository
			const catalog = await this.fetchCourseCatalogFromRepository();
			if (catalog) {
				this.defaultCourseCatalog = catalog;
			} else {
				// Fallback to default catalog
				this.defaultCourseCatalog = this.getDefaultCourseCatalog();
			}
		} catch (error) {
			console.error('Error loading course catalog:', error);
			// Fallback to default catalog
			this.defaultCourseCatalog = this.getDefaultCourseCatalog();
		}
	}

	private async fetchCourseStructureFromRepository(): Promise<CourseStructure | null> {
		// In a real implementation, this would fetch from the configured repository
		// For now, we'll return null to use the default structure
		// This would be implemented based on the extension configuration
		return null;
	}

	private async fetchCourseCatalogFromRepository(): Promise<CourseCatalog | null> {
		// In a real implementation, this would fetch from a central catalog repository
		// For now, we'll return null to use the default catalog
		return null;
	}

	private getDefaultCourseStructure(): CourseStructure {
		// Chapter structure following C++ Primer 5th Edition
		return {
			version: "1.0",
			title: "C++ Primer 5th Edition",
			description: "Learning path for C++ Primer 5th Edition",
			chapters: [
				{
					id: "1_getting_started",
					title: "1. Getting Started",
					protected: false
				},
				{
					id: "2_variables",
					title: "2. Variables and Basic Types",
					protected: false
				},
				{
					id: "3_strings",
					title: "3. Strings, Vectors, and Arrays",
					protected: false
				},
				{
					id: "4_expressions",
					title: "4. Expressions",
					protected: false
				},
				{
					id: "5_statements",
					title: "5. Statements",
					protected: false
				},
				{
					id: "6_functions",
					title: "6. Functions",
					protected: false
				},
				{
					id: "7_classes",
					title: "7. Classes",
					protected: true
				},
				{
					id: "8_io",
					title: "8. The IO Library",
					protected: true
				}
			],
			protectedChapters: ["7_classes", "8_io"]
		};
	}

	private getDefaultCourseCatalog(): CourseCatalog {
		// Default course catalog with sample courses
		return {
			version: "1.0",
			courses: [
				{
					id: "cpp-primer-5th",
					name: "C++ Primer 5th Edition Buddy",
					description: "Learn C++ programming with the definitive guide to the C++ language",
					repository: {
						type: "github",
						url: "https://github.com/conanchen/cpp_primer_5th",
						branch: "main"
					},
					level: "Beginner",
					estimatedHours: 40
				},
				{
					id: "python-3rd",
					name: "Python 3rd Edition Buddy",
					description: "Master Python programming with comprehensive exercises and solutions",
					repository: {
						type: "github",
						url: "https://github.com/conanchen/python_3rd_edition",
						branch: "main"
					},
					level: "Beginner",
					estimatedHours: 35
				},
				{
					id: "javascript-complete",
					name: "JavaScript Complete Guide Buddy",
					description: "Complete guide to modern JavaScript development",
					repository: {
						type: "github",
						url: "https://github.com/conanchen/javascript_complete",
						branch: "main"
					},
					level: "Intermediate",
					estimatedHours: 50
				}
			]
		};
	}

	private getRootItems(): StudyItem[] {
		if (!this.defaultCourseStructure) {
			return [];
		}

		const items: StudyItem[] = this.defaultCourseStructure.chapters.map(chapter => {
			const isProtected = this.defaultCourseStructure?.protectedChapters.includes(chapter.id) || false;
			const isAccessible = !isProtected || this.protectionManager.isChapterAccessible(chapter.id);
			return new StudyItem(
				chapter.title,
				chapter.sections && chapter.sections.length > 0 ? vscode.TreeItemCollapsibleState.Collapsed : vscode.TreeItemCollapsibleState.None,
				chapter.id,
				isProtected && !isAccessible,
				true,
				'directory'
			);
		});
		
		return items;
	}

	private getPromotionalCourses(): StudyItem[] {
		// Simplified to show a single promotional item for the generic Learning Buddy extension
		return [
			new StudyItem(
				'Get Generic Learning Buddy Extension',
				vscode.TreeItemCollapsibleState.None,
				'generic_learning_buddy_promo',
				false,
				false,
				'promotion'
			)
		];
	}

	private getChildItems(parent: StudyItem): StudyItem[] {
		const childItems: StudyItem[] = [];
		
		if (!this.defaultCourseStructure) {
			return childItems;
		}

		// Find the chapter in the course structure
		const chapter = this.defaultCourseStructure.chapters.find(ch => ch.id === parent.fullPath);
		
		if (!chapter) {
			return childItems;
		}

		// Check if chapter is accessible (either not protected or has valid license)
		const isChapterAccessible = this.protectionManager.isChapterAccessible(parent.fullPath);
		
		if (isChapterAccessible && chapter.sections) {
			// Only show children for accessible items
			chapter.sections.forEach(section => {
				childItems.push(
					new StudyItem(
						section.title,
						vscode.TreeItemCollapsibleState.None,
						`${parent.fullPath}/${section.file || section.id}`,
						false,
						false,
						section.type
					)
				);
			});
		} else if (!isChapterAccessible) {
			// Show locked message for inaccessible chapters
			childItems.push(
				new StudyItem(
					'Content Locked - Requires License',
					vscode.TreeItemCollapsibleState.None,
					`${parent.fullPath}/locked`,
					true,
					false,
					'exercise'
				)
			);
		} else {
			// Show sample content for accessible chapters without defined sections
			childItems.push(
				new StudyItem('Exercise', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/exercise.cpp', false, false, 'exercise'),
				new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/solution.cpp', false, false, 'solution'),
				new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/README.md', false, false, 'readme'),
				new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/hint.md', false, false, 'hint')
			);
		}
		
		return childItems;
	}

	studyItem(item: StudyItem): void {
		if (item.itemType === 'promotion' && item.fullPath === 'promotional_courses') {
			// Handle promotional course click - show promotion for generic Learning Buddy extension
			vscode.window.showInformationMessage(
				'To access more courses, please install the Generic Learning Buddy extension from the VS Code Marketplace. ' +
				'This course-specific extension focuses only on C++ Primer 5th Edition content.',
				'Get Generic Learning Buddy',
				'Close'
			).then(selection => {
				if (selection === 'Get Generic Learning Buddy') {
					// Open VS Code marketplace page for the generic Learning Buddy extension
					vscode.env.openExternal(vscode.Uri.parse('https://marketplace.visualstudio.com/items?itemName=cpp-primer-buddy-dev.learning-buddy'));
				}
			});
			return;
		} else if (item.itemType === 'promotion' && item.fullPath === 'generic_learning_buddy_promo') {
			// Handle click on the generic Learning Buddy promotion item
			vscode.window.showInformationMessage(
				'To access more courses, please install the Generic Learning Buddy extension from the VS Code Marketplace. ' +
				'This course-specific extension focuses only on C++ Primer 5th Edition content.',
				'Get Generic Learning Buddy',
				'Close'
			).then(selection => {
				if (selection === 'Get Generic Learning Buddy') {
					// Open VS Code marketplace page for the generic Learning Buddy extension
					vscode.env.openExternal(vscode.Uri.parse('https://marketplace.visualstudio.com/items?itemName=cpp-primer-buddy-dev.learning-buddy'));
				}
			});
			return;
		}

		if (item.isLocked) {
			// Try to fetch content from Gitee first, fall back to WeChat contact
			this.getWorkingDirectory().then(workingDir => {
				if (workingDir) {
					this.fetchContentFromGitee(item, 'exercise', workingDir);
				}
			});
			return;
		}
		
		// Copy exercise content to workspace
		this.copyContent(item, 'exercise');
	}

	checkSolution(item: StudyItem): void {
		if (item.isLocked) {
			// Try to fetch content from Gitee first, fall back to WeChat contact
			this.getWorkingDirectory().then(workingDir => {
				if (workingDir) {
					this.fetchContentFromGitee(item, 'solution', workingDir);
				}
			});
			return;
		}
		
		// In a real implementation, this would:
		// 1. Run tests or compile the student's solution
		// 2. Compare with expected output
		// 3. Provide feedback
		
		vscode.window.showInformationMessage(
			`In a real implementation, this would check your solution for "${item.label}" and provide feedback.`
		);
	}

	viewSolution(item: StudyItem): void {
		if (item.isLocked) {
			// Try to fetch content from Gitee first, fall back to WeChat contact
			this.getWorkingDirectory().then(workingDir => {
				if (workingDir) {
					this.fetchContentFromGitee(item, 'solution', workingDir);
				}
			});
			return;
		}
		
		// Show the solution content
		this.copyContent(item, 'solution');
	}

	showHint(item: StudyItem): void {
		if (item.isLocked) {
			// For hints, we'll still use WeChat contact as they're typically short text
			vscode.commands.executeCommand('cppPrimerBuddy.openWeChatContact');
			return;
		}
		
		// In a real implementation, this would show hints for the exercise
		vscode.window.showInformationMessage(
			`Hint for "${item.label}": 

` +
			`1. Read the Learning Guide carefully
` +
			`2. Look at the TODO comments in the code
` +
			`3. Refer to the textbook chapter
` +
			`4. Try compiling your code to see error messages`
		);
	}

	private copyContent(item: StudyItem, contentType: 'exercise' | 'solution'): void {
		// Get the working directory from settings or ask user to specify one
		this.getWorkingDirectory().then(workingDir => {
			if (!workingDir) {
				return;
			}
			
			// For locked content, try to fetch from Gitee first
			if (item.isLocked) {
				this.fetchContentFromGitee(item, contentType, workingDir);
				return;
			}
			
			// Copy exercise content to workspace (existing logic for unlocked content)
			this.copyLocalContent(item, contentType, workingDir);
		});
	}
	
	/**
	 * Fetch content from Gitee for locked items
	 */
	private async fetchContentFromGitee(item: StudyItem, contentType: 'exercise' | 'solution', workingDir: string): Promise<void> {
		try {
			// If working directory is not provided, get it from settings or ask user
			if (!workingDir) {
				const dir = await this.getWorkingDirectory();
				if (!dir) {
					return;
				}
				workingDir = dir;
			}
			
			// Get valid licenses
			const licenses = this.protectionManager.getValidLicenses();
			
			// Find a license with Gitee access
			let giteeLicense: LicenseInfo | null = null;
			for (const license of licenses) {
				if (license.gitee) {
					giteeLicense = license;
					break;
				}
			}
			
			if (!giteeLicense) {
				// No license with Gitee access, fall back to WeChat contact
				vscode.commands.executeCommand('cppPrimerBuddy.openWeChatContact');
				return;
			}
			
			// Determine the file path in the Gitee repository
			const pathParts = item.fullPath.split('/');
			const chapterDir = pathParts[0];
			const fileName = pathParts[1];
			
			// Map chapter directories to Gitee paths
			const chapterGiteePathMap: { [key: string]: string } = {
				'7_classes': 'chapter7',
				'8_io': 'chapter8'
			};
			
			const giteeChapterPath = chapterGiteePathMap[chapterDir];
			if (!giteeChapterPath) {
				vscode.window.showErrorMessage(`No Gitee path found for chapter: ${chapterDir}`);
				return;
			}
			
			// Construct the file path in the Gitee repository
			let giteeFilePath: string;
			if (contentType === 'solution') {
				giteeFilePath = `${giteeChapterPath}/solutions/${fileName}`;
			} else {
				giteeFilePath = `${giteeChapterPath}/exercises/${fileName}`;
			}
			
			// Fetch content from Gitee
			const content = await this.giteeContentDelivery.fetchContent(giteeLicense, giteeFilePath);
			
			if (content) {
				// Determine destination file path
				const destFileName = fileName;
				const destFilePath = path.join(workingDir, destFileName);
				
				// Write content to file
				fs.writeFileSync(destFilePath, content);
				
				let message = '';
				switch (contentType) {
					case 'exercise':
						message = `Exercise "${item.label}" has been downloaded and copied to your working directory: ${workingDir}`;
						break;
					case 'solution':
						message = `Solution for "${item.label}" has been downloaded and copied to your working directory: ${workingDir}`;
						break;
				}
				
				vscode.window.showInformationMessage(message);
				
				// Open the copied file in the editor
				vscode.workspace.openTextDocument(destFilePath).then((doc: vscode.TextDocument) => {
					vscode.window.showTextDocument(doc);
				});
			} else {
				// Failed to fetch content, fall back to WeChat contact
				vscode.commands.executeCommand('cppPrimerBuddy.openWeChatContact');
			}
		} catch (error) {
			console.error('Error fetching content from Gitee:', error);
			vscode.window.showErrorMessage(`Failed to fetch content from Gitee: ${error}`);
			// Fall back to WeChat contact
			vscode.commands.executeCommand('cppPrimerBuddy.openWeChatContact');
		}
	}
	
	/**
	 * Copy content from local files (existing logic)
	 */
	private copyLocalContent(item: StudyItem, contentType: 'exercise' | 'solution', workingDir: string): void {
		// Determine the source directory based on the item path
		// First, try to find the cpp_primer_5th directory in the current workspace
		let sourceBasePath = '';
		const workspaceFolders = vscode.workspace.workspaceFolders;
		if (workspaceFolders && workspaceFolders.length > 0) {
			// Look for cpp_primer_5th in the first workspace folder
			const workspacePath = workspaceFolders[0].uri.fsPath;
			const possiblePaths = [
				path.join(workspacePath, 'cpp_primer_5th', 'exercises'),
				path.join(workspacePath, '..', 'cpp_primer_5th', 'exercises'),
				path.join(workspacePath, 'cpp-primer-buddy', 'cpp_primer_5th', 'exercises')
			];
			
			for (const possiblePath of possiblePaths) {
				if (fs.existsSync(possiblePath)) {
					sourceBasePath = possiblePath;
					break;
				}
			}
		}
		
		// If not found in workspace, fall back to extension path
		if (!sourceBasePath) {
			sourceBasePath = path.join(this.context.extensionPath, '..', 'cpp_primer_5th', 'exercises');
		}
		
		// Extract chapter and exercise information from the item path
		// The item.fullPath is in the format "7_classes/person.cpp" or "8_io/io_practice.cpp"
		const pathParts = item.fullPath.split('/');
		const chapterDir = pathParts[0]; // e.g., "7_classes"
		const fileName = pathParts[1]; // e.g., "person.cpp"
		
		// Map chapter directories to exercise directories
		const chapterExerciseMap: { [key: string]: string } = {
			'1_getting_started': '1.1_intro_cpp',
			'2_variables': '2.1_variables_types',
			'3_strings': '3.1_strings_vectors',
			'4_expressions': '4.1_expressions',
			'5_statements': '5.1_control_flow',
			'6_functions': '6.1_functions',
			'7_classes': '7.1_classes',
			'8_io': '8.1_io_library'
			// Add more mappings as needed
		};
		
		const exerciseDir = chapterExerciseMap[chapterDir];
		if (!exerciseDir) {
			vscode.window.showErrorMessage(`No exercise directory found for chapter: ${chapterDir}`);
			return;
		}
		
		// Debug information
		console.log('Workspace folders:', vscode.workspace.workspaceFolders);
		console.log('Source base path:', sourceBasePath);
		console.log('Exercise directory:', exerciseDir);
		console.log('Chapter directory:', chapterDir);
		console.log('File name:', fileName);
		
		// Determine source file path
		let sourceFilePath: string;
		if (contentType === 'solution') {
			// Check if there's a specific solution file
			const specificSolutionPath = path.join(sourceBasePath, exerciseDir, 'variable_exercise_solution.cpp');
			if (fs.existsSync(specificSolutionPath)) {
				sourceFilePath = specificSolutionPath;
			} else {
				// Fall back to generic solution.cpp
				sourceFilePath = path.join(sourceBasePath, exerciseDir, 'solution.cpp');
			}
		} else {
			// For exercise content, we need to determine which file to copy
			if (fileName.endsWith('.h')) {
				sourceFilePath = path.join(sourceBasePath, exerciseDir, fileName);
			} else if (fileName.includes('main')) {
				sourceFilePath = path.join(sourceBasePath, exerciseDir, 'main.cpp');
			} else if (fileName.includes('person')) {
				// For person.cpp or person.h files
				sourceFilePath = path.join(sourceBasePath, exerciseDir, fileName);
			} else {
				// Check if there's a specific exercise file
				const specificExercisePath = path.join(sourceBasePath, exerciseDir, 'variable_exercise.cpp');
				if (fs.existsSync(specificExercisePath)) {
					sourceFilePath = specificExercisePath;
				} else {
					// Fall back to main.cpp for exercise files
					sourceFilePath = path.join(sourceBasePath, exerciseDir, 'main.cpp');
				}
			}
		}
		
		// Determine destination file path
		let destFileName: string;
		if (contentType === 'solution') {
			// Check if there's a specific solution file
			const specificSolutionPath = path.join(sourceBasePath, exerciseDir, 'variable_exercise_solution.cpp');
			if (fs.existsSync(specificSolutionPath)) {
				destFileName = 'solution.cpp';
			} else {
				destFileName = 'solution.cpp';
			}
		} else {
			// For exercise content
			if (fileName.endsWith('.h')) {
				destFileName = fileName;
			} else if (fileName.includes('main')) {
				destFileName = 'main.cpp';
			} else if (fileName.includes('person')) {
				destFileName = fileName;
			} else {
				// Check if there's a specific exercise file
				const specificExercisePath = path.join(sourceBasePath, exerciseDir, 'variable_exercise.cpp');
				if (fs.existsSync(specificExercisePath)) {
					destFileName = 'exercise.cpp';
				} else {
					destFileName = 'main.cpp';
				}
			}
		}
		const destFilePath = path.join(workingDir, destFileName);
		
		// Check if source file exists
		if (!fs.existsSync(sourceFilePath)) {
			// Add more detailed error information
			let errorMessage = `Source file not found: ${sourceFilePath}\n` +
				`Source base path: ${sourceBasePath}\n` +
				`Exercise directory: ${exerciseDir}\n` +
				`File name: ${fileName}\n` +
				`Content type: ${contentType}\n`;
			
			// Check what files actually exist in the directory
			const exerciseDirPath = path.join(sourceBasePath, exerciseDir);
			if (fs.existsSync(exerciseDirPath)) {
				const files = fs.readdirSync(exerciseDirPath);
				errorMessage += `Files in directory: ${files.join(', ')}\n`;
			} else {
				errorMessage += `Exercise directory does not exist: ${exerciseDirPath}\n`;
			}
			
			vscode.window.showErrorMessage(errorMessage);
			console.error(errorMessage);
			return;
		}
		
		// Copy the file
		try {
			fs.copyFileSync(sourceFilePath, destFilePath);
			
			let message = '';
			switch (contentType) {
				case 'exercise':
					message = `Exercise "${item.label}" has been copied to your working directory: ${workingDir}`;
					break;
				case 'solution':
					message = `Solution for "${item.label}" has been copied to your working directory: ${workingDir}`;
					break;
			}
			
			vscode.window.showInformationMessage(message);
			
			// Open the copied file in the editor
			vscode.workspace.openTextDocument(destFilePath).then((doc: vscode.TextDocument) => {
				vscode.window.showTextDocument(doc);
			});
		} catch (error) {
			vscode.window.showErrorMessage(`Failed to copy file: ${error}`);
		}
	}
	
	/**
	 * Get the working directory from settings or ask user to specify one
	 * @returns Promise<string> The working directory path
	 */
	private async getWorkingDirectory(): Promise<string | undefined> {
		// First, try to get the working directory from settings
		let workingDir = this.context.globalState.get<string>('cppPrimerBuddy.workingDirectory');
		
		// If not set, ask user to specify one
		if (!workingDir) {
			const selectedUri = await vscode.window.showOpenDialog({
				canSelectFiles: false,
				canSelectFolders: true,
				canSelectMany: false,
				openLabel: 'Select Working Directory'
			});
			
			if (selectedUri && selectedUri.length > 0) {
				workingDir = selectedUri[0].fsPath;
				// Save the working directory for future use
				this.context.globalState.update('cppPrimerBuddy.workingDirectory', workingDir);
			} else {
				// User cancelled the dialog
				return undefined;
			}
		}
		
		return workingDir;
	}
	
	/**
	 * Allow user to change the working directory
	 */
	public async changeWorkingDirectory(): Promise<void> {
		const selectedUri = await vscode.window.showOpenDialog({
			canSelectFiles: false,
			canSelectFolders: true,
			canSelectMany: false,
			openLabel: 'Select New Working Directory'
		});
		
		if (selectedUri && selectedUri.length > 0) {
			const workingDir = selectedUri[0].fsPath;
			this.context.globalState.update('cppPrimerBuddy.workingDirectory', workingDir);
			vscode.window.showInformationMessage(`Working directory updated to: ${workingDir}`);
		}
	}
	
	/**
	 * Refresh the tree view to reflect license changes or updated course structure
	 */
	public async refresh(): Promise<void> {
		// Reload default course structure
		await this.loadDefaultCourseStructure();
		// Reload course catalog
		await this.loadDefaultCourseCatalog();
		// Refresh the tree view
		this._onDidChangeTreeData.fire();
	}
}