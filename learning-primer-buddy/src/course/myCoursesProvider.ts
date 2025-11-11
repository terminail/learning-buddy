import * as vscode from 'vscode';
import { CourseItem } from './types';
import { defaultCourseCatalog } from './defaultCourseCatalog';
import { CourseContentProtectionManager } from '../courseContentProtectionManager';
import { CourseContentProviderClient } from '../courseContentProviderClient';
import { PodmanEnvironmentManager } from '../podman/podmanEnvironmentManager';

export class MyCoursesProvider implements vscode.TreeDataProvider<CourseItem> {
	private _onDidChangeTreeData: vscode.EventEmitter<CourseItem | undefined | void> = new vscode.EventEmitter<CourseItem | undefined | void>();
	readonly onDidChangeTreeData: vscode.Event<CourseItem | undefined | void> = this._onDidChangeTreeData.event;
	private protectionManager: CourseContentProtectionManager;
	private courseContentProvider: CourseContentProviderClient;
	private defaultCourseStructure: any | null = null;
	private podmanNotAvailable: boolean = false;
	private podmanManager: PodmanEnvironmentManager | null = null;
	// Simple toggle for testing scenarios
	private mockPodmanInstalled: boolean = false;
	// Current course ID for dynamic course switching
	private currentCourseId: string = this.getCurrentCourseId();

	constructor(private context: vscode.ExtensionContext, protectionManager: CourseContentProtectionManager) {
		this.protectionManager = protectionManager;
		// Initialize the Course Content Provider client
		this.courseContentProvider = new CourseContentProviderClient(context);
		// Load sample course catalog data when the provider is initialized
		this.loadDefaultCourseStructure();
	}

	/**
	 * Set whether Podman is not available
	 */
	public setPodmanNotAvailable(notAvailable: boolean): void {
		console.log('Setting podmanNotAvailable to:', notAvailable);
		this.podmanNotAvailable = notAvailable;
		this._onDidChangeTreeData.fire();
	}

	/**
	 * Refresh the tree view to reflect license changes or updated course structure
	 */
	public async refresh(): Promise<void> {
		// Reload sample course catalog data
		await this.loadDefaultCourseStructure();
		// Refresh the tree view
		this._onDidChangeTreeData.fire();
	}

	getTreeItem(element: CourseItem): vscode.TreeItem {
		return element;
	}

	public getChildren(element?: CourseItem): vscode.ProviderResult<CourseItem[]> {
		console.log('getChildren called with podmanNotAvailable:', this.podmanNotAvailable);
		console.log('Mock Podman installed status:', this.mockPodmanInstalled);
		
		// Always show the My Courses section regardless of Podman status
		// The Podman installation instructions will be shown in the Podman section if needed

		if (!element) {
			// Root level items - show My Courses directly (10 courses) above Podman section
			console.log('Building root level tree view items');
			const items: CourseItem[] = [];

			// Add user's collected courses (10 courses) directly without a section header
			console.log('Getting My Courses');
			const myCourses = this.getMyCourses();
			console.log('Retrieved', myCourses.length, 'courses from getMyCourses()');
			console.log('Adding courses to items array');
			items.push(...myCourses);
			console.log('Total items after adding courses:', items.length);

			// Add a separator between sections (empty with gray background, no icon)
			const separatorItem = new CourseItem(
				'', // Empty label
				vscode.TreeItemCollapsibleState.None,
				'separator',
				false,
				false,
				'readme'
			);
			// Set custom styling for the separator
			(separatorItem as any).iconPath = undefined; // No icon
			(separatorItem as any).contextValue = 'separator'; // Custom context value for styling
			items.push(separatorItem);

			// BOTTOM SECTION: Podman Information
			// Add a header for the Podman section
			console.log('Adding Podman Environment header');
			items.push(new CourseItem(
				'🔧 Podman Environment',
				vscode.TreeItemCollapsibleState.Expanded,
				'podman_section_header',
				false,
				true,
				'readme'
			));

			// Check if Podman is available
			const podmanExecutable = this.podmanManager?.getPodmanExecutable();
			if (podmanExecutable) {
				// Add Podman installation information with option to change location
				const podmanItem = new CourseItem(
					`✅ Podman: ${podmanExecutable}`,
					vscode.TreeItemCollapsibleState.None,
					'podman_location',
					false,
					false,
					'readme'
				);
				items.push(podmanItem);
			} else if (this.podmanNotAvailable || this.mockPodmanInstalled === false) {
				// Show installation instructions when Podman is not available
				const installItem = new CourseItem(
					'❌ Podman Required - Click to Install/Configure',
					vscode.TreeItemCollapsibleState.None,
					'podman_not_found',
					false,
					false,
					'readme'
				);
				items.push(installItem);
			}

			console.log('Final tree view items count:', items.length);
			return Promise.resolve(items);
		} else {
			// Handle different types of items
			console.log('Handling child items for element:', element.fullPath);
			// Remove the my_courses_header handling since we no longer have that section
			if (element.fullPath.startsWith('my_course_')) {
				// Handle course item click - show course structure
				const courseId = element.fullPath.replace('my_course_', '');
				console.log('Showing course structure for course ID:', courseId);
				return Promise.resolve(this.provideCourseContentStructure(courseId));
			} else if (element.fullPath === 'podman_section_header') {
				// Podman section header - show nothing as children since we show podman info directly
				return Promise.resolve([]);
			} else if (element.fullPath === 'separator') {
				// Separator - no children
				return Promise.resolve([]);
			} else if (element.fullPath === 'podman_location') {
				// Handle click on Podman location - allow user to change it
				return Promise.resolve([
					new CourseItem(
						'Click to change Podman installation location',
						vscode.TreeItemCollapsibleState.None,
						'change_podman_location',
						false,
						false,
						'readme'
					)
				]);
			} else if (element.fullPath === 'podman_not_found') {
				// Handle click on Podman not found item - show installation instructions
				// Show detailed installation instructions when user clicks on this item
				return Promise.resolve([
					new CourseItem(
						'🔒 Podman Required for Learning Buddy',
						vscode.TreeItemCollapsibleState.None,
						'podman_required',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'📦 Why Podman is Required',
						vscode.TreeItemCollapsibleState.Collapsed,
						'why_podman_required',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'📝 Installation Steps',
						vscode.TreeItemCollapsibleState.Collapsed,
						'installation_instructions',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'1. Install Podman on Your System',
						vscode.TreeItemCollapsibleState.None,
						'install_step_1',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'2. Restart VS Code After Installation',
						vscode.TreeItemCollapsibleState.None,
						'install_step_2',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'🔗 Platform-Specific Installation Guides',
						vscode.TreeItemCollapsibleState.Collapsed,
						'platform_guides',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'Need Help? Contact Support',
						vscode.TreeItemCollapsibleState.None,
						'support_contact',
						false,
						false,
						'promotion'
					)
				]);
			} else if (element.fullPath === 'why_podman_required') {
				// Show details about why Podman is required
				return Promise.resolve([
					new CourseItem(
						'• Secure content delivery through containerization',
						vscode.TreeItemCollapsibleState.None,
						'why_podman_detail_1',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'• Daemonless operation for lightweight experience',
						vscode.TreeItemCollapsibleState.None,
						'why_podman_detail_2',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'• Content protection from unauthorized access',
						vscode.TreeItemCollapsibleState.None,
						'why_podman_detail_3',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'• Isolated development environment management',
						vscode.TreeItemCollapsibleState.None,
						'why_podman_detail_4',
						false,
						false,
						'readme'
					)
				]);
			} else if (element.fullPath === 'platform_guides') {
				// Show platform-specific installation guides
				return Promise.resolve([
					new CourseItem(
						'Windows: Podman Desktop + WSL2',
						vscode.TreeItemCollapsibleState.None,
						'installation_link_windows',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'macOS: Homebrew Installation',
						vscode.TreeItemCollapsibleState.None,
						'installation_link_macos',
						false,
						false,
						'readme'
					),
					new CourseItem(
						'Linux: Distribution Package Managers',
						vscode.TreeItemCollapsibleState.None,
						'installation_link_linux',
						false,
						false,
						'readme'
					)
				]);
			} else if (element.fullPath === 'installation_link_windows') {
				// Open Windows installation guide
				vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation#windows'));
				return Promise.resolve([]);
			} else if (element.fullPath === 'installation_link_macos') {
				// Open macOS installation guide
				vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation#macos'));
				return Promise.resolve([]);
			} else if (element.fullPath === 'installation_link_linux') {
				// Open Linux installation guide
				vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation#linux'));
				return Promise.resolve([]);
			} else if (element.fullPath === 'support_contact') {
				// Open WeChat contact for support
				vscode.commands.executeCommand('learningPrimerBuddy.openWeChatContact');
				return Promise.resolve([]);
			} else {
				// Handle items from our new model structure
				// Check if this is an exercise item
				if (this.defaultCourseStructure) {
					// Check if this is an exercise
					let isExercise = false;
					for (const course of this.defaultCourseStructure.courses) {
						if (course.exercises.find((e: any) => e.id === element.fullPath)) {
							isExercise = true;
							break;
						}
					}
					
					if (isExercise) {
						// Handle exercise children (folders and files)
						return Promise.resolve(this.getExerciseChildren(element));
					}
					
					// Check if this is a folder
					let isFolder = false;
					search: for (const course of this.defaultCourseStructure.courses) {
						for (const exercise of course.exercises) {
							// Check direct folders
							if (exercise.folders.find((f: any) => f.id === element.fullPath)) {
								isFolder = true;
								break search;
							}
							
							// Check nested folders
							const searchFolders = (folders: any[]) => {
								for (const folder of folders) {
									if (folder.id === element.fullPath) {
										isFolder = true;
										return true;
									}
									if (folder.folders && searchFolders(folder.folders)) {
										return true;
									}
								}
								return false;
							};
							
							if (searchFolders(exercise.folders)) {
								break search;
							}
						}
					}
					
					if (isFolder) {
						// Handle folder children (subfolders and files)
						return Promise.resolve(this.getFolderChildren(element));
					}
				}
				
				// For backward compatibility, handle items from the old course structure
				// This should only happen if there are still references to the old structure
				console.log('Handling old course structure item:', element.fullPath);
				// Check if this is a course item that needs to show the complex structure
				if (element.fullPath.startsWith('my_course_')) {
					// Handle course item click - show course structure
					const courseId = element.fullPath.replace('my_course_', '');
					console.log('Showing course structure for course ID:', courseId);
					return Promise.resolve(this.provideCourseContentStructure(courseId));
				} else if (element.fullPath.includes('_') && !element.fullPath.includes('podman') && !element.fullPath.includes('separator')) {
					// Handle children of course items in the complex structure
					return Promise.resolve(this.getCourseStructureChildren(element));
				}
				// Fallback to old method for any remaining cases
				return Promise.resolve(this.getChildItems(element));
			}
		}
	}

	private async loadDefaultCourseStructure(): Promise<void> {
		try {
			// Try to load from cache first
			const cachedStructure = this.context.globalState.get<any>(`courseStructure_${this.getCurrentCourseId()}`);
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
				this.defaultCourseStructure = this.provideMySampleCourseCatalog();
			}
		} catch (error) {
			console.error('Error loading default course structure:', error);
			// Fallback to default structure
			this.defaultCourseStructure = this.provideMySampleCourseCatalog();
		}
	}

	private getCurrentCourseId(): string {
		// Return the current course ID if set, otherwise extract from extension name
		if (this.currentCourseId) {
			return this.currentCourseId;
		}
		
		// Extract course ID from extension name
		// For example, "cpp-primer-5th-buddy" -> "cpp-primer-5th"
		const extensionName = vscode.extensions.all
			.find(ext => ext.id.includes('buddy'))?.id.split('.')[1] || 'cpp-primer-5th';
		
		return extensionName.replace('-buddy', '');
	}

	/**
	 * Set the current course ID and refresh the structure
	 */
	public async setCurrentCourse(courseId: string): Promise<void> {
		this.currentCourseId = courseId;
		console.log('Setting current course to:', courseId);
		
		// Clear the cached structure for the new course
		await this.loadDefaultCourseStructure();
		
		// Refresh the tree view to show the new course structure
		this._onDidChangeTreeData.fire();
	}

	private async fetchCourseStructureFromRepository(): Promise<any | null> {
		// For testing, return the same test data as getMySampleCourseCatalog
		// In a real implementation, this would fetch from the course-content-provider
		return this.provideMySampleCourseCatalog();
	}

	private provideMySampleCourseCatalog(): any {
		// Chapter structure following our new model: CourseCatalog -> Course -> CourseExercise -> Folder/File
		return defaultCourseCatalog;
	}

	private provideCourseContentStructure(courseId: string): CourseItem[] {
		// Get the course from our new model structure
		if (!this.defaultCourseStructure) {
			return [];
		}

		// Find the course in the catalog
		const course = this.defaultCourseStructure.courses.find((c: any) => c.id === courseId);
		if (!course) {
			return [
				new CourseItem(
					'No structure available for this course',
					vscode.TreeItemCollapsibleState.None,
					'no_structure',
					false,
					false,
					'readme'
				)
			];
		}

		// Convert exercises to CourseItems
		return course.exercises.map((exercise: any) => {
			const exerciseItem = new CourseItem(
				`📘 ${exercise.title}`,
				exercise.folders.length > 0 || exercise.files.length > 0 ? 
					vscode.TreeItemCollapsibleState.Collapsed : 
					vscode.TreeItemCollapsibleState.None,
				exercise.id,
				false,
				true,
				'exercise'
			);
			exerciseItem.contextValue = 'studyItem';
			exerciseItem.tooltip = exercise.description;
			return exerciseItem;
		});
	}

	// Add a new method to handle child items for exercises in our new model
	private getExerciseChildren(element: CourseItem): CourseItem[] {
		if (!this.defaultCourseStructure) {
			return [];
		}

		// Find the course that contains this exercise
		let exercise: any = null;
		for (const course of this.defaultCourseStructure.courses) {
			exercise = course.exercises.find((e: any) => e.id === element.fullPath);
			if (exercise) break;
		}

		if (!exercise) {
			return [];
		}

		const children: CourseItem[] = [];

		// Add folders first
		exercise.folders.forEach((folder: any) => {
			const folderItem = new CourseItem(
				`📁 ${folder.name}`,
				folder.folders.length > 0 || folder.files.length > 0 ? 
					vscode.TreeItemCollapsibleState.Collapsed : 
					vscode.TreeItemCollapsibleState.None,
				folder.id,
				false,
				true,
				'folder'
			);
			folderItem.contextValue = 'folderItem';
			folderItem.tooltip = folder.path;
			children.push(folderItem);
		});

		// Add files
		exercise.files.forEach((file: any) => {
			const icon = file.name.endsWith('.md') ? '📝' : 
						file.name.endsWith('.cpp') ? '🔍' : 
						file.name.endsWith('.py') ? '🐍' : 
						file.name.endsWith('.js') ? '📜' : 
						file.name.endsWith('.html') ? '🌐' : 
						file.name.endsWith('.css') ? '🎨' : 
						file.name.endsWith('.sql') ? '📊' : 
						file.name.endsWith('.yml') || file.name.endsWith('.yaml') ? '⚙️' : 
						'📄';
			
			const fileItem = new CourseItem(
				`${icon} ${file.name}`,
				vscode.TreeItemCollapsibleState.None,
				file.id,
				false,
				false,
				'file'
			);
			fileItem.contextValue = 'fileItem';
			fileItem.tooltip = file.path;
			children.push(fileItem);
		});

		return children;
	}

	// Add a new method to handle child items for folders in our new model
	private getFolderChildren(element: CourseItem): CourseItem[] {
		if (!this.defaultCourseStructure) {
			return [];
		}

		// Find the folder in any course/exercise
		let targetFolder: any = null;
		
		// Search through all courses, exercises, and folders
		for (const course of this.defaultCourseStructure.courses) {
			for (const exercise of course.exercises) {
				// Check direct folders in exercise
				targetFolder = exercise.folders.find((f: any) => f.id === element.fullPath);
				if (targetFolder) break;
				
				// Recursively search nested folders
				const searchFolders = (folders: any[]) => {
					for (const folder of folders) {
						if (folder.id === element.fullPath) {
							targetFolder = folder;
							return true;
						}
						if (folder.folders && searchFolders(folder.folders)) {
							return true;
						}
					}
					return false;
				};
				
				if (searchFolders(exercise.folders)) {
					break;
				}
			}
			if (targetFolder) break;
		}

		if (!targetFolder) {
			return [];
		}

		const children: CourseItem[] = [];

		// Add subfolders first
		targetFolder.folders.forEach((folder: any) => {
			const folderItem = new CourseItem(
				`📁 ${folder.name}`,
				folder.folders.length > 0 || folder.files.length > 0 ? 
					vscode.TreeItemCollapsibleState.Collapsed : 
					vscode.TreeItemCollapsibleState.None,
				folder.id,
				false,
				true,
				'folder'
			);
			folderItem.contextValue = 'folderItem';
			folderItem.tooltip = folder.path;
			children.push(folderItem);
		});

		// Add files
		targetFolder.files.forEach((file: any) => {
			const icon = file.name.endsWith('.md') ? '📝' : 
						file.name.endsWith('.cpp') ? '🔍' : 
						file.name.endsWith('.py') ? '🐍' : 
						file.name.endsWith('.js') ? '📜' : 
						file.name.endsWith('.html') ? '🌐' : 
						file.name.endsWith('.css') ? '🎨' : 
						file.name.endsWith('.sql') ? '📊' : 
						file.name.endsWith('.yml') || file.name.endsWith('.yaml') ? '⚙️' : 
						'📄';
			
			const fileItem = new CourseItem(
				`${icon} ${file.name}`,
				vscode.TreeItemCollapsibleState.None,
				file.id,
				false,
				false,
				'file'
			);
			fileItem.contextValue = 'fileItem';
			fileItem.tooltip = file.path;
			children.push(fileItem);
		});

		return children;
	}

	// Add a new method to handle child items for the complex structure
	private getCourseStructureChildren(element: CourseItem): CourseItem[] {
		// Extract the course ID and item path from the element's fullPath
		const pathParts = element.fullPath.split('_');
		const courseId = pathParts[0];
		
		// Find the course structure
		const courseContentStructures: { [key: string]: { title: string; structure: any[] } } = {
			"cpp-primer-5th": {
				title: "C++ Primer 5th Edition",
				structure: [
					{
						name: "1. Getting Started",
						type: "directory",
						children: [
							{ name: "introduction.md", type: "file" },
							{ name: "hello_world.cpp", type: "file" },
							{ name: "compiling_guide.md", type: "file" },
							{
								name: "examples",
								type: "directory",
								children: [
									{ name: "hello.cpp", type: "file" },
									{ name: "variables.cpp", type: "file" }
								]
							}
						]
					},
					{
						name: "2. Variables and Basic Types",
						type: "directory",
						children: [
							{ name: "variables_overview.md", type: "file" },
							{ name: "data_types.cpp", type: "file" },
							{ name: "type_conversion.cpp", type: "file" },
							{
								name: "exercises",
								type: "directory",
								children: [
									{ name: "exercise1.cpp", type: "file" },
									{ name: "exercise2.cpp", type: "file" },
									{ name: "solutions", type: "directory", children: [
										{ name: "solution1.cpp", type: "file" },
										{ name: "solution2.cpp", type: "file" }
									]}
								]
							}
						]
					},
					{
						name: "3. Strings, Vectors, and Arrays",
						type: "directory",
						children: [
							{ name: "strings_basics.md", type: "file" },
							{ name: "string_operations.cpp", type: "file" },
							{ name: "vectors_guide.md", type: "file" },
							{ name: "arrays_basics.cpp", type: "file" },
							{
								name: "projects",
								type: "directory",
								children: [
									{
										name: "string_analyzer",
										type: "directory",
										children: [
											{ name: "main.cpp", type: "file" },
											{ name: "string_utils.cpp", type: "file" },
											{ name: "string_utils.h", type: "file" },
											{ name: "Makefile", type: "file" }
										]
									}
								]
							}
						]
					}
				]
			},
			"python-3rd-edition": {
				title: "Python 3rd Edition",
				structure: [
					{
						name: "1. Python Basics",
						type: "directory",
						children: [
							{ name: "introduction.md", type: "file" },
							{ name: "hello_world.py", type: "file" },
							{ name: "variables.py", type: "file" },
							{
								name: "examples",
								type: "directory",
								children: [
									{ name: "basics.py", type: "file" },
									{ name: "data_types.py", type: "file" }
								]
							}
						]
					},
					{
						name: "2. Control Flow",
						type: "directory",
						children: [
							{ name: "control_flow.md", type: "file" },
							{ name: "if_statements.py", type: "file" },
							{ name: "loops.py", type: "file" },
							{
								name: "exercises",
								type: "directory",
								children: [
									{ name: "loop_exercises.py", type: "file" },
									{ name: "conditional_exercises.py", type: "file" },
									{ name: "solutions", type: "directory", children: [
										{ name: "loop_solutions.py", type: "file" },
										{ name: "conditional_solutions.py", type: "file" }
									]}
								]
							}
						]
					}
				]
			},
			"javascript-es6": {
				title: "JavaScript ES6+",
				structure: [
					{
						name: "1. JavaScript Fundamentals",
						type: "directory",
						children: [
							{ name: "basics.md", type: "file" },
							{ name: "variables.js", type: "file" },
							{ name: "functions.js", type: "file" },
							{
								name: "examples",
								type: "directory",
								children: [
									{ name: "arrow_functions.js", type: "file" },
									{ name: "template_literals.js", type: "file" }
								]
							}
						]
					},
					{
						name: "2. ES6 Features",
						type: "directory",
						children: [
							{ name: "es6_features.md", type: "file" },
							{ name: "let_const.js", type: "file" },
							{ name: "destructuring.js", type: "file" },
							{
								name: "projects",
								type: "directory",
								children: [
									{
										name: "todo_app",
										type: "directory",
										children: [
											{ name: "index.html", type: "file" },
											{ name: "app.js", type: "file" },
											{ name: "styles.css", type: "file" }
										]
									}
								]
							}
						]
					}
				]
			},
			"data-structures-algorithms": {
				title: "Data Structures & Algorithms",
				structure: [
					{
						name: "1. Introduction to Algorithms",
						type: "directory",
						children: [
							{ name: "intro.md", type: "file" },
							{ name: "complexity_analysis.py", type: "file" },
							{
								name: "notes",
								type: "directory",
								children: [
									{ name: "big_o_notation.md", type: "file" }
								]
							}
						]
					}
				]
			},
			"web-development": {
				title: "Web Development Full Stack",
				structure: [
					{
						name: "1. HTML5 and CSS3",
						type: "directory",
						children: [
							{ name: "html_basics.md", type: "file" },
							{ name: "css_fundamentals.md", type: "file" },
							{ name: "index.html", type: "file" },
							{ name: "styles.css", type: "file" },
							{
								name: "projects",
								type: "directory",
								children: [
									{
										name: "portfolio_site",
										type: "directory",
										children: [
											{ name: "index.html", type: "file" },
											{ name: "style.css", type: "file" },
											{ name: "script.js", type: "file" },
											{
												name: "assets",
												type: "directory",
												children: [
													{ name: "logo.png", type: "file" },
													{ name: "background.jpg", type: "file" }
												]
											}
										]
									}
								]
							}
						]
					}
				]
			},
			"machine-learning": {
				title: "Machine Learning Fundamentals",
				structure: [
					{
						name: "1. Introduction to ML",
						type: "directory",
						children: [
							{ name: "ml_basics.md", type: "file" },
							{ name: "linear_regression.py", type: "file" },
							{
								name: "datasets",
								type: "directory",
								children: [
									{ name: "sample_data.csv", type: "file" }
								]
							}
						]
					}
				]
			},
			"docker-kubernetes": {
				title: "Docker & Kubernetes",
				structure: [
					{
						name: "1. Container Basics",
						type: "directory",
						children: [
							{ name: "container_intro.md", type: "file" },
							{ name: "Dockerfile", type: "file" },
							{ name: "docker-compose.yml", type: "file" },
							{
								name: "examples",
								type: "directory",
								children: [
									{
										name: "nginx_container",
										type: "directory",
										children: [
											{ name: "Dockerfile", type: "file" },
											{ name: "index.html", type: "file" }
										]
									}
								]
							}
						]
					}
				]
			},
			"react-native": {
				title: "React Native Mobile Development",
				structure: [
					{
						name: "1. React Native Setup",
						type: "directory",
						children: [
							{ name: "setup_guide.md", type: "file" },
							{ name: "App.js", type: "file" },
							{
								name: "components",
								type: "directory",
								children: [
									{ name: "Header.js", type: "file" },
									{ name: "Button.js", type: "file" }
								]
							}
						]
					}
				]
			},
			"sql-database": {
				title: "SQL & Database Design",
				structure: [
					{
						name: "1. Database Fundamentals",
						type: "directory",
						children: [
							{ name: "db_basics.md", type: "file" },
							{ name: "schema_design.sql", type: "file" },
							{
								name: "queries",
								type: "directory",
								children: [
									{ name: "select_queries.sql", type: "file" },
									{ name: "join_examples.sql", type: "file" }
								]
							}
						]
					}
				]
			},
			"git-version-control": {
				title: "Git Version Control",
				structure: [
					{
						name: "1. Git Basics",
						type: "directory",
						children: [
							{ name: "git_intro.md", type: "file" },
							{ name: "commands_reference.md", type: "file" },
							{
								name: "workflows",
								type: "directory",
								children: [
									{ name: "feature_branch_workflow.md", type: "file" },
									{ name: "gitflow_workflow.md", type: "file" }
								]
							}
						]
					}
				]
			}
		};

		const courseData = courseContentStructures[courseId];
		if (!courseData) {
			return [];
		}

		// Helper function to find children based on path
		const findChildren = (structure: any[], pathParts: string[], currentIndex: number = 1): any[] => {
			if (currentIndex >= pathParts.length) {
				return structure;
			}

			const index = parseInt(pathParts[currentIndex]);
			if (isNaN(index) || index < 0 || index >= structure.length) {
				return [];
			}

			const item = structure[index];
			if (item.type === "directory" && item.children) {
				return findChildren(item.children, pathParts, currentIndex + 1);
			}

			return [];
		};

		// Get the children for this element
		const children = findChildren(courseData.structure, pathParts);
		
		// Convert children to CourseItems
		const convertToCourseItems = (items: any[], parentId: string = element.fullPath): CourseItem[] => {
			return items.map((item, index) => {
				const itemId = `${parentId}_${index}`;
				
				if (item.type === "directory") {
					const dirItem = new CourseItem(
						`📁 ${item.name}`,
						item.children && item.children.length > 0 ? 
							vscode.TreeItemCollapsibleState.Collapsed : 
							vscode.TreeItemCollapsibleState.None,
						itemId,
						false,
						true,
						'directory'
					);
					dirItem.contextValue = 'studyItem';
					dirItem.tooltip = `Directory: ${item.name}`;
					return dirItem;
				} else {
					// File item
					const icon = item.name.endsWith('.md') ? '📝' : 
								item.name.endsWith('.cpp') ? '🔍' : 
								item.name.endsWith('.py') ? '🐍' : 
								item.name.endsWith('.js') ? '📜' : 
								item.name.endsWith('.html') ? '🌐' : 
								item.name.endsWith('.css') ? '🎨' : 
								item.name.endsWith('.sql') ? '📊' : 
								item.name.endsWith('.yml') || item.name.endsWith('.yaml') ? '⚙️' : 
								'📄';
					
					const fileItem = new CourseItem(
						`${icon} ${item.name}`,
						vscode.TreeItemCollapsibleState.None,
						itemId,
						false,
						false,
						'readme'
					);
					fileItem.contextValue = 'studyItem';
					fileItem.tooltip = `File: ${item.name}`;
					return fileItem;
				}
			});
		};

		return convertToCourseItems(children);
	}

	private getMyCourses(): CourseItem[] {
		// Use data from defaultCourseCatalog instead of hardcoded data
		if (!this.defaultCourseStructure || !this.defaultCourseStructure.courses) {
			return [];
		}

		// Map the courses from defaultCourseCatalog to the format expected by My Courses view
		// For now, we'll use some dummy progress data since the defaultCourseCatalog doesn't include progress
		const progressData: { [key: string]: string } = {
			"cpp-primer-5th": "75%",
			"python-3rd-edition": "60%",
			"javascript-es6": "45%",
			"data-structures-algorithms": "30%",
			"web-development": "20%",
			"machine-learning": "15%",
			"docker-kubernetes": "90%",
			"react-native": "50%",
			"sql-database": "80%",
			"git-version-control": "95%"
		};

		return this.defaultCourseStructure.courses.map((course: any) => {
			const progress = progressData[course.id] || "50%"; // Default to 50% if no progress data
			const courseItem = new CourseItem(
				`📖 ${course.title} (${progress})`,
				vscode.TreeItemCollapsibleState.Collapsed,
				`my_course_${course.id}`,
				false,
				true,
				'directory'
			);
			courseItem.tooltip = course.description;
			courseItem.contextValue = 'courseItem';
			return courseItem;
		});
	}

	private getChildItems(element: CourseItem): CourseItem[] {
		if (!this.defaultCourseStructure) {
			return [];
		}

		// Find the chapter that matches the element's path
		const chapter = this.defaultCourseStructure.chapters.find((ch: any) => ch.id === element.fullPath);
		if (!chapter || !chapter.sections) {
			return [];
		}

		// Create child items for each section
		return chapter.sections.map((section: any) => {
			// Determine item type based on section type
			let itemType: 'exercise' | 'solution' | 'hint' | 'readme' | 'directory' = 'exercise';
			switch (section.type) {
				case 'solution':
					itemType = 'solution';
					break;
				case 'hint':
					itemType = 'hint';
					break;
				case 'readme':
					itemType = 'readme';
					break;
				default:
					itemType = 'exercise';
			}

			// Create page items (no download option)
			const courseItem = new CourseItem(
				section.title,
				vscode.TreeItemCollapsibleState.None, // Sections don't have children
				`${chapter.id}/${section.id}`,
				false, // Sections are not locked
				false, // Sections are not directories (they are pages)
				itemType
			);
			
			// Add context value for page items
			if (itemType === 'exercise') {
				(courseItem as any).contextValue = 'exerciseItem';
			} else {
				(courseItem as any).contextValue = 'pageItem';
			}
			
			return courseItem;
		});
	}

	/**
	 * Get the current course structure
	 */
	public getCurrentCourseStructure(): any | null {
		return this.defaultCourseStructure;
	}

	/**
	 * Get the list of course IDs that the user has in their My Courses
	 */
	public getMyCourseIds(): string[] {
		const myCourses = this.getMyCourses();
		return myCourses.map(course => {
			// Extract course ID from the fullPath (e.g., "my_course_cpp-primer-5th" -> "cpp-primer-5th")
			const match = course.fullPath.match(/^my_course_(.+)$/);
			return match ? match[1] : '';
		}).filter(id => id !== '');
	}

	/**
	 * Get Podman installation information item
	 */
	private getPodmanInfoItem(): CourseItem {
		// This would need to be implemented to check Podman status
		// For now, we'll add a placeholder that will be updated when we have access to Podman status
		return new CourseItem(
			'🐳 Podman Environment',
			vscode.TreeItemCollapsibleState.Collapsed,
			'podman_info',
			false,
			true,
			'readme'
		);
	}

	/**
	 * Get children for Podman info item
	 */
	private getPodmanInfoChildren(): CourseItem[] {
		const childItems: CourseItem[] = [];

		// Use mock flag for testing, otherwise check real installation
		const isPodmanInstalled = this.mockPodmanInstalled || 
			(!!this.podmanManager && !!this.podmanManager.getPodmanExecutable());
		
		let podmanPath: string | null = null;
		if (this.mockPodmanInstalled) {
			podmanPath = "/mock/path/to/podman";
		} else if (this.podmanManager) {
			podmanPath = this.podmanManager.getPodmanExecutable();
		}

		// Create a single comprehensive information item
		let infoText: string;
		
		if (!isPodmanInstalled) {
			// Podman is not installed, show installation instructions
			infoText = "🔒 Podman Not Installed - Required for Learning Buddy\n\n" +
				"📝 Why Podman is Required:\n" +
				"• Secure content delivery through containerization\n" +
				"• Daemonless operation for lightweight experience\n" +
				"• Content protection from unauthorized access\n" +
				"• Isolated development environment management\n\n" +
				"📥 Installation Instructions:\n" +
				"1. Visit the official Podman website (podman.io)\n" +
				"2. Download the installer for your operating system\n" +
				"3. Follow the installation instructions for your platform\n" +
				"4. Restart VS Code after installation\n\n" +
				"🔗 Platform-Specific Guides:\n" +
				"• Windows: Podman Desktop + WSL2\n" +
				"• macOS: Homebrew Installation\n" +
				"• Linux: Distribution Package Managers";
		} else {
			// Podman is installed, show installation details
			const displayPath = podmanPath || 'Unknown path';
			
			infoText = "✅ Podman Successfully Installed\n\n" +
				`📁 Installation Path: ${displayPath}\n\n` +
				"📦 Course Containers:\n" +
				"• Course containers will be automatically managed\n" +
				"• Content is securely delivered through containers\n" +
				"• Development environments are isolated and secure\n\n" +
				"🔄 To refresh Podman status, use the 'Refresh Podman Status' command";
		}

		// Create a single child item with all the information
		const infoItem = new CourseItem(
			infoText,
			vscode.TreeItemCollapsibleState.None,
			'podman_info_details',
			false,
			false,
			'readme'
		);
		
		// Set a longer description to make it more visible
		(infoItem as any).description = "Click to view details";
		
		childItems.push(infoItem);
		
		return childItems;
	}

	private getPodmanInstallationItems(element?: CourseItem): vscode.ProviderResult<CourseItem[]> {
		if (!element) {
			// Root level - show Podman installation instructions as a single long text item
			const installationInstructions = new CourseItem(
				"🔒 Podman Required for Learning Buddy\n\n" +
				"Learning Buddy requires Podman to securely deliver course content and manage licenses. " +
				"Podman runs in a lightweight, daemonless container environment that ensures content protection.\n\n" +
				"📦 Why Podman is Required:\n" +
				"• Secure content delivery through containerization\n" +
				"• Daemonless operation for lightweight experience\n" +
				"• Content protection from unauthorized access\n" +
				"• Isolated development environment management\n\n" +
				"📝 Installation Steps:\n" +
				"1. Visit the official Podman website (https://podman.io) and download the installer for your operating system.\n" +
				"2. Follow the installation instructions for your platform.\n" +
				"3. After installing Podman, completely close and restart VS Code to ensure the Learning Buddy extension can detect it.\n\n" +
				"🔗 Platform-Specific Installation Guides:\n" +
				"• Windows: Podman Desktop + WSL2\n" +
				"• macOS: Homebrew Installation\n" +
				"• Linux: Distribution Package Managers\n\n" +
				"Need Help? Contact Support via WeChat.",
				vscode.TreeItemCollapsibleState.None,
				'podman_installation_instructions',
				false,
				false,
				'readme'
			);
			
			// Add description for better visibility
			(installationInstructions as any).description = "Click to view installation instructions";
			
			return Promise.resolve([installationInstructions]);
		} else {
			// For child items, return empty array since we're using a single item approach
			return Promise.resolve([]);
		}
	}

	/**
	 * Get detailed installation instruction text based on the item path
	 */
	private getInstallationInstructionDetails(itemPath: string): string {
		switch (itemPath) {
			case 'podman_required':
				return '🔒 Learning Buddy requires Podman to securely deliver course content and manage licenses. ' +
				       'Podman runs in a lightweight, daemonless container environment that ensures content protection.';
			case 'installation_instructions':
				return '📝 Please follow these steps to install Podman on your system:';
			case 'install_step_1':
				return '1. Visit the official Podman website (podman.io) and download the installer for your operating system. ' +
				       'Follow the installation instructions for your platform.';
			case 'install_step_2':
				return '2. After installing Podman, completely close and restart VS Code to ensure the Learning Buddy extension can detect it.';
			case 'support_contact':
				return '💬 If you need help with installation, click here to contact our support team via WeChat.';
			default:
				return 'Please follow the installation instructions above to use the Learning Buddy extension.';
		}
	}

	/**
	 * Toggle mock Podman installation status for testing
	 */
	public toggleMockPodmanStatus(): void {
		// Toggle the mock status
		this.mockPodmanInstalled = !this.mockPodmanInstalled;
		console.log('Mock Podman status toggled to:', this.mockPodmanInstalled ? 'installed' : 'not installed');
		// Refresh the tree view to show the changes
		this._onDidChangeTreeData.fire();
	}
	
	/**
	 * Get current mock status for display
	 */
	public getMockPodmanStatus(): boolean {
		return this.mockPodmanInstalled;
	}

}
