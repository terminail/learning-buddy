import * as vscode from 'vscode';
import * as path from 'path';
import * as fs from 'fs';
import * as https from 'https';
import { ContentProtectionManager, LicenseInfo } from './contentProtection';
// Import the Course Content Provider client instead of the deprecated GiteeContentDelivery
import { CourseContentProviderClient } from './courseContentProvider';
import { PodmanEnvironmentManager } from './podmanEnvironmentManager';

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
		public readonly itemType: 'exercise' | 'solution' | 'hint' | 'readme' | 'directory' | 'promotion' = 'exercise'
	) {
		super(label, collapsibleState);
		
		(this as any).tooltip = this.label;
		// Remove locked indicator to make locked items appear identical to free items
		(this as any).description = '';
		
		// Set command for certain items
		if (fullPath === 'podman_location' || fullPath === 'change_podman_location') {
			(this as any).command = {
				command: 'cppprimer5thbuddy.itemClicked',
				title: 'Item Clicked',
				arguments: [this]
			};
		}
		
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
				default:
					(this as any).iconPath = new vscode.ThemeIcon('file');
			}
		}
	}
}

export class LearningTreeViewProvider implements vscode.TreeDataProvider<StudyItem> {
	private _onDidChangeTreeData: vscode.EventEmitter<StudyItem | undefined | void> = new vscode.EventEmitter<StudyItem | undefined | void>();
	readonly onDidChangeTreeData: vscode.Event<StudyItem | undefined | void> = this._onDidChangeTreeData.event;
	private protectionManager: ContentProtectionManager;
	// Use CourseContentProviderClient instead of GiteeContentDelivery
	private courseContentProvider: CourseContentProviderClient;
	private defaultCourseStructure: CourseStructure | null = null;
	private defaultCourseCatalog: CourseCatalog | null = null;
	private podmanNotAvailable: boolean = false;
	private podmanManager: PodmanEnvironmentManager;

	constructor(private context: vscode.ExtensionContext, podmanManager: PodmanEnvironmentManager) {
		this.podmanManager = podmanManager;
		this.protectionManager = new ContentProtectionManager(context);
		// Initialize the Course Content Provider client
		this.courseContentProvider = new CourseContentProviderClient(context);
		// Load default course structure and catalog when the provider is initialized
		this.loadDefaultCourseStructure();
		this.loadDefaultCourseCatalog();
		
		// FOR TESTING: Force show installation guide
		// Remove this line for production
		// this.podmanNotAvailable = true;
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
	 * Handle click on tree items
	 */
	public async onItemClicked(item: StudyItem): Promise<void> {
		if (item.fullPath === 'change_podman_location') {
			// User wants to change Podman location
			await this.changePodmanLocation();
		} else if (item.fullPath === 'podman_location') {
			// User clicked on Podman location, show options
			const selection = await vscode.window.showInformationMessage(
				'Podman Location Options',
				'Change Location',
				'Copy Path'
			);
			
			switch (selection) {
				case 'Change Location':
					await this.changePodmanLocation();
					break;
				case 'Copy Path':
					const podmanExecutable = this.podmanManager.getPodmanExecutable();
					if (podmanExecutable) {
						await vscode.env.clipboard.writeText(podmanExecutable);
						vscode.window.showInformationMessage('Podman path copied to clipboard');
					}
					break;
			}
		} else if (item.fullPath === 'podman_not_found') {
			// User clicked on "Podman not found" item, show installation instructions
			this.setPodmanNotAvailable(true);
		} else if (item.fullPath === 'installation_link') {
			// User clicked on installation link, open Podman website
			vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation'));
		}
	}

	getTreeItem(element: StudyItem): vscode.TreeItem {
		return element;
	}

	getChildren(element?: StudyItem): vscode.ProviderResult<StudyItem[]> {
		console.log('getChildren called with podmanNotAvailable:', this.podmanNotAvailable);
		// If Podman is not available, show installation instructions

		if (this.podmanNotAvailable) {

			console.log('Showing Podman installation instructions');

			if (!element) {

				// Root level - show Podman installation instructions

				return Promise.resolve([

					new StudyItem(

						'🔒 Podman Required for Learning Buddy',

						vscode.TreeItemCollapsibleState.None,

						'podman_required',

						false,

						false,

						'readme'

					),

					new StudyItem(

						'📦 Why Podman is Required',

						vscode.TreeItemCollapsibleState.Collapsed,

						'why_podman_required',

						false,

						false,

						'readme'

					),

					new StudyItem(

						'📝 Installation Steps',

						vscode.TreeItemCollapsibleState.Collapsed,

						'installation_instructions',

						false,

						false,

						'readme'

					),

					new StudyItem(

						'1. Install Podman on Your System',

						vscode.TreeItemCollapsibleState.None,

						'install_step_1',

						false,

						false,

						'readme'

					),

					new StudyItem(

						'2. Restart VS Code After Installation',

						vscode.TreeItemCollapsibleState.None,

						'install_step_2',

						false,

						false,

						'readme'

					),

					new StudyItem(

						'🔗 Platform-Specific Installation Guides',

						vscode.TreeItemCollapsibleState.Collapsed,

						'platform_guides',

						false,

						false,

						'readme'

					),

					new StudyItem(

						'Need Help? Contact Support',

						vscode.TreeItemCollapsibleState.None,

						'support_contact',

						false,

						false,

						'promotion'

					)

				]);

			} else {

				// Handle clicks on installation instruction items

				switch (element.fullPath) {

					case 'support_contact':

						// Open WeChat contact for support

						vscode.commands.executeCommand('cppprimer5thbuddy.openWeChatContact');

						return Promise.resolve([]);

					case 'why_podman_required':

						// Show details about why Podman is required

						return Promise.resolve([

							new StudyItem(

								'• Secure content delivery through containerization',

								vscode.TreeItemCollapsibleState.None,

								'why_podman_detail_1',

								false,

								false,

								'readme'

							),

							new StudyItem(

								'• Daemonless operation for lightweight experience',

								vscode.TreeItemCollapsibleState.None,

								'why_podman_detail_2',

								false,

								false,

								'readme'

							),

							new StudyItem(

								'• Content protection from unauthorized access',

								vscode.TreeItemCollapsibleState.None,

								'why_podman_detail_3',

								false,

								false,

								'readme'

							),

							new StudyItem(

								'• Isolated development environment management',

								vscode.TreeItemCollapsibleState.None,

								'why_podman_detail_4',

								false,

								false,

								'readme'

							)

						]);

					case 'platform_guides':

						// Show platform-specific installation guides

						return Promise.resolve([

							new StudyItem(

								'Windows: Podman Desktop + WSL2',

								vscode.TreeItemCollapsibleState.None,

								'installation_link_windows',

								false,

								false,

								'readme'

							),

							new StudyItem(

								'macOS: Homebrew Installation',

								vscode.TreeItemCollapsibleState.None,

								'installation_link_macos',

								false,

								false,

								'readme'

							),

							new StudyItem(

								'Linux: Distribution Package Managers',

								vscode.TreeItemCollapsibleState.None,

								'installation_link_linux',

								false,

								false,

								'readme'

							)

						]);

					case 'installation_link_windows':

						// Open Windows installation guide

						vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation#windows'));

						return Promise.resolve([]);

					case 'installation_link_macos':

						// Open macOS installation guide

						vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation#macos'));

						return Promise.resolve([]);

					case 'installation_link_linux':

						// Open Linux installation guide

						vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation#linux'));

						return Promise.resolve([]);

					default:

						// Show detailed information for each instruction item

						return Promise.resolve([

							new StudyItem(

								this.getInstallationInstructionDetails(element.fullPath),

								vscode.TreeItemCollapsibleState.None,

								`${element.fullPath}_details`,

								false,

								false,

								'readme'

							)

						]);

				}

			}

		}

		console.log('Showing normal course content');

		if (!element) {

			// Root level items - organize like a split panel with clear sections

			const items: StudyItem[] = [];

			// TOP SECTION: Course Content (like the top part of a split panel)
			// Add a header for the course section
			items.push(new StudyItem(
				'📚 Course Structure',
				vscode.TreeItemCollapsibleState.Expanded,
				'course_section_header',
				false,
				true,
				'directory'
			));

			// Add course chapters under the course section
			const courseItems = this.getRootItems();
			items.push(...courseItems);

			// Add a separator between sections
			items.push(new StudyItem(
				'',
				vscode.TreeItemCollapsibleState.None,
				'separator',
				false,
				false,
				'readme'
			));

			// BOTTOM SECTION: Podman Information (like the bottom part of a split panel)
			// Add a header for the Podman section
			items.push(new StudyItem(
				'🔧 Podman Environment',
				vscode.TreeItemCollapsibleState.Expanded,
				'podman_section_header',
				false,
				true,
				'readme'
			));

			// Check if Podman is available
			const podmanExecutable = this.podmanManager.getPodmanExecutable();
			if (podmanExecutable) {
				// Add Podman installation information with option to change location
				const podmanItem = new StudyItem(
					`✅ Podman: ${podmanExecutable}`,
					vscode.TreeItemCollapsibleState.None,
					'podman_location',
					false,
					false,
					'readme'
				);
				items.push(podmanItem);
			} else {
				// If Podman is not available but podmanNotAvailable flag is not set,
				// we should still show some information about Podman requirement
				const installItem = new StudyItem(
					'❌ Podman Required - Click to Install/Configure',
					vscode.TreeItemCollapsibleState.None,
					'podman_not_found',
					false,
					false,
					'readme'
				);
				items.push(installItem);
			}

			// Add promotional courses section at the very end
			items.push(new StudyItem(
				'🎯 Discover More Courses',
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
			} else if (element.fullPath === 'podman_section_header') {
				// Podman section header - show nothing as children since we show podman info directly
				return Promise.resolve([]);
			} else if (element.fullPath === 'course_section_header') {
				// Course section header - show nothing as children since we show course info directly
				return Promise.resolve([]);
			} else if (element.fullPath === 'separator') {
				// Separator - no children
				return Promise.resolve([]);
			} else if (element.fullPath === 'podman_location') {
				// Handle click on Podman location - allow user to change it
				return Promise.resolve([
					new StudyItem(
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
				// Set the podmanNotAvailable flag to true and refresh the view
				this.podmanNotAvailable = true;
				this._onDidChangeTreeData.fire();
				return Promise.resolve([]);
			} else if (element.fullPath === 'view_installation_instructions') {
				// Show detailed installation instructions
				return Promise.resolve([
					new StudyItem(
						'Visit podman.io for installation instructions',
						vscode.TreeItemCollapsibleState.None,
						'installation_link',
						false,
						false,
						'readme'
					)
				]);
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
		// If Podman is not available, show installation instructions
		if (this.podmanNotAvailable) {
			this.showPodmanInstallationInstructions();
			return;
		}

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
			// Try to fetch content through Course Content Provider first, fall back to WeChat contact
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
		// If Podman is not available, show installation instructions
		if (this.podmanNotAvailable) {
			this.showPodmanInstallationInstructions();
			return;
		}

		if (item.isLocked) {
			// Try to fetch content through Course Content Provider first, fall back to WeChat contact
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
		// If Podman is not available, show installation instructions
		if (this.podmanNotAvailable) {
			this.showPodmanInstallationInstructions();
			return;
		}

		if (item.isLocked) {
			// Try to fetch content through Course Content Provider first, fall back to WeChat contact
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
		// If Podman is not available, show installation instructions
		if (this.podmanNotAvailable) {
			this.showPodmanInstallationInstructions();
			return;
		}

		if (item.isLocked) {
			// For hints, we'll still use WeChat contact as they're typically short text
			vscode.commands.executeCommand('cppprimer5thbuddy.openWeChatContact');
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
			
			// For locked content, try to fetch through Course Content Provider first
			if (item.isLocked) {
				this.fetchContentFromGitee(item, contentType, workingDir);
				return;
			}
			
			// Copy exercise content to workspace (existing logic for unlocked content)
			this.copyLocalContent(item, contentType, workingDir);
		});
	}
	
	/**
	 * Fetch content from the Course Content Provider running in the Podman environment
	 * @param licenseInfo License information for content access
	 * @param filePath Path to the file in the course repository
	 * @param contentType Type of content (exercise, solution, etc.)
	 * @returns Content as string, or null if failed
	 */
	private async fetchContentFromProvider(licenseInfo: LicenseInfo, filePath: string, _contentType: string): Promise<string | null> {
		try {
			// Use the Course Content Provider client to fetch content
			// This implements the specification requirement that all content delivery
			// happens within the Learning Buddy Podman Environment
			const content = await this.courseContentProvider.fetchContent(licenseInfo, filePath);
			
			if (content === null) {
				// The Course Content Provider is not available or the Podman environment is not running
				vscode.window.showErrorMessage(
					'Course Content Provider is not available. ' +
					'Please ensure the Learning Buddy Podman Environment is running. ' +
					'Refer to the installation guide for setup instructions.'
				);
			}
			
			return content;
		} catch (error) {
			console.error('Error communicating with Course Content Provider:', error);
			vscode.window.showErrorMessage(`Failed to communicate with Course Content Provider: ${error}`);
			return null;
		}
	}
	
	/**
	 * Fetch content through the Course Content Provider for locked items
	 * This implements the specification requirement that all content delivery
	 * happens within the Learning Buddy Podman Environment
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
			
			// Find a license with content access
			let validLicense: LicenseInfo | null = null;
			for (const license of licenses) {
				// Any valid license can be used for content access through the Course Content Provider
				validLicense = license;
				break;
			}
			
			if (!validLicense) {
				// No valid license, fall back to WeChat contact
				vscode.commands.executeCommand('cppprimer5thbuddy.openWeChatContact');
				return;
			}
			
			// Determine the file path in the course repository
			const pathParts = item.fullPath.split('/');
			const chapterDir = pathParts[0];
			const fileName = pathParts[1];
			
			// Map chapter directories to repository paths
			const chapterPathMap: { [key: string]: string } = {
				'7_classes': 'chapter7',
				'8_io': 'chapter8'
			};
			
			const chapterPath = chapterPathMap[chapterDir];
			if (!chapterPath) {
				vscode.window.showErrorMessage(`No repository path found for chapter: ${chapterDir}`);
				return;
			}
			
			// Construct the file path in the course repository
			let contentPath: string;
			if (contentType === 'solution') {
				contentPath = `${chapterPath}/solutions/${fileName}`;
			} else {
				contentPath = `${chapterPath}/exercises/${fileName}`;
			}
			
			// Fetch content from the Course Content Provider
			const content = await this.fetchContentFromProvider(validLicense, contentPath, contentType);
			
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
				// Failed to fetch content through Course Content Provider
				vscode.window.showErrorMessage(
					'Failed to fetch content through Course Content Provider. ' +
					'Please ensure the Learning Buddy Podman Environment is running and try again. ' +
					'If the problem persists, contact the instructor through WeChat for assistance.'
				);
				// Fall back to WeChat contact as a last resort
				vscode.commands.executeCommand('cppprimer5thbuddy.openWeChatContact');
			}
		} catch (error) {
			console.error('Error fetching content through Course Content Provider:', error);
			vscode.window.showErrorMessage(`Failed to fetch content through Course Content Provider: ${error}`);
			// Fall back to WeChat contact
			vscode.commands.executeCommand('cppprimer5thbuddy.openWeChatContact');
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
		let workingDir = this.context.globalState.get<string>('cppprimer5thbuddy.workingDirectory');
		
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
				this.context.globalState.update('cppprimer5thbuddy.workingDirectory', workingDir);
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
			this.context.globalState.update('cppprimer5thbuddy.workingDirectory', workingDir);
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
	 * Show Podman installation instructions to the user
	 */
	private showPodmanInstallationInstructions(): void {
		vscode.window.showInformationMessage(
			'Learning Buddy requires Podman to function properly. ' +
			'Please install Podman on your system and restart VS Code. ' +
			'Visit podman.io for installation instructions.',
			'Install Podman',
			'More Information'
		).then(selection => {
			switch (selection) {
				case 'Install Podman':
					// Open Podman installation page
					vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation'));
					break;
				case 'More Information':
					// Open documentation
					vscode.env.openExternal(vscode.Uri.parse('https://github.com/conanchen/programming-learning-vscode-buddy'));
					break;
			}
		});
	}
	
	/**

	 * Allow user to change the Podman installation location

	 */

	public async changePodmanLocation(): Promise<void> {

		// Ask user to select the Podman executable file directly instead of the directory

		const selectedUri = await vscode.window.showOpenDialog({

			canSelectFiles: true,

			canSelectFolders: false,

			canSelectMany: false,

			openLabel: 'Select Podman Executable',

			filters: process.platform === 'win32' ? { 'Executable': ['exe'] } : { 'Executable': ['*'] }

		});

		

		if (selectedUri && selectedUri.length > 0) {

			const podmanPath = selectedUri[0].fsPath;

			// Save the custom Podman path

			this.context.globalState.update('customPodmanPath', podmanPath);

			vscode.window.showInformationMessage(`Podman executable updated to: ${podmanPath}. Please restart VS Code to apply changes.`);

		} else {

			// User cancelled, offer to install Podman automatically

			vscode.window.showInformationMessage(

				'Would you like to install Podman automatically?',

				'Yes, Install Podman',

				'No, I will install manually'

			).then(selection => {

				if (selection === 'Yes, Install Podman') {

					// Open Podman installation page

					vscode.env.openExternal(vscode.Uri.parse('https://podman.io/getting-started/installation'));

				}

			});

		}

	}
}