import * as vscode from 'vscode';
import { CourseItem, CourseStructure, CourseChapter, CourseSection } from './types';
import { ContentProtectionManager } from '../contentProtection';
import { CourseContentProviderClient } from '../courseContentProvider';
import { PodmanEnvironmentManager } from '../podmanEnvironmentManager';

export class CourseStructureProvider implements vscode.TreeDataProvider<CourseItem> {
	private _onDidChangeTreeData: vscode.EventEmitter<CourseItem | undefined | void> = new vscode.EventEmitter<CourseItem | undefined | void>();
	readonly onDidChangeTreeData: vscode.Event<CourseItem | undefined | void> = this._onDidChangeTreeData.event;
	private protectionManager: ContentProtectionManager;
	private courseContentProvider: CourseContentProviderClient;
	private defaultCourseStructure: CourseStructure | null = null;
	private podmanNotAvailable: boolean = false;
	private podmanManager: PodmanEnvironmentManager | null = null;
	// Simple toggle for testing scenarios
	private mockPodmanInstalled: boolean = false;

	constructor(private context: vscode.ExtensionContext, protectionManager: ContentProtectionManager) {
		this.protectionManager = protectionManager;
		// Initialize the Course Content Provider client
		this.courseContentProvider = new CourseContentProviderClient(context);
		// Load default course structure when the provider is initialized
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
		// Reload default course structure
		await this.loadDefaultCourseStructure();
		// Refresh the tree view
		this._onDidChangeTreeData.fire();
	}

	getTreeItem(element: CourseItem): vscode.TreeItem {
		return element;
	}

	getChildren(element?: CourseItem): vscode.ProviderResult<CourseItem[]> {
		console.log('getChildren called with podmanNotAvailable:', this.podmanNotAvailable);
		console.log('Mock Podman installed status:', this.mockPodmanInstalled);
		
		// Determine if Podman is available based on mock mode
		const isPodmanAvailable = this.mockPodmanInstalled;
		
		console.log('Is Podman available (final):', isPodmanAvailable);
		
		// If Podman is not available (real check or mock), show course structure with Podman information at the end
		if (!isPodmanAvailable) {
			if (!element) {
				// Root level items - course chapters plus multiple Podman information items
				const rootItems = this.getRootItems();
				// Add empty separator item before Podman information
				const separatorItem = new CourseItem(
					" ",
					vscode.TreeItemCollapsibleState.None,
					'podman_separator',
					false,
					false,
					'readme'
				);
				(separatorItem as any).description = "";
				(separatorItem as any).iconPath = undefined;
				rootItems.push(separatorItem);
				
				// Add multiple Podman information items to make it more visible
				for (let i = 0; i < 3; i++) {
					const podmanInfoItem = new CourseItem(
						"🔒 Podman Required",
						vscode.TreeItemCollapsibleState.None,
						`podman_installation_info_${i}`,
						false,
						false,
						'readme'
					);
					// Add description for better visibility
					(podmanInfoItem as any).description = "Click to view installation instructions";
					(podmanInfoItem as any).command = {
						command: 'learningPrimerBuddy.showPodmanInstallationGuide',
						title: 'Show Podman Installation Guide',
						arguments: []
					};
					rootItems.push(podmanInfoItem);
				}
				return Promise.resolve(rootItems);
			} else {
				// For child items, show normal child items
				return Promise.resolve(this.getChildItems(element));
			}
		}

		if (!element) {
			// Root level items - course chapters plus Podman installation info when available
			const rootItems = this.getRootItems();
			
			// Add Podman installation information item when Podman is available
			if (isPodmanAvailable) {
				// Add empty separator item before Podman information
				const separatorItem = new CourseItem(
					" ",
					vscode.TreeItemCollapsibleState.None,
					'podman_separator',
					false,
					false,
					'readme'
				);
				(separatorItem as any).description = "";
				(separatorItem as any).iconPath = undefined;
				rootItems.push(separatorItem);
				
				// Add Course Catalog item
				const courseCatalogItem = new CourseItem(
					"📚 Course Catalog",
					vscode.TreeItemCollapsibleState.None,
					'course_catalog',
					false,
					false,
					'readme'
				);
				(courseCatalogItem as any).description = "Click to view available courses";
				(courseCatalogItem as any).command = {
					command: 'cppPrimerBuddy.openCourseCatalog',
					title: 'Open Course Catalog',
					arguments: []
				};
				rootItems.push(courseCatalogItem);
				
				const podmanInfoItem = new CourseItem(
					"✅ Podman Installation Info",
					vscode.TreeItemCollapsibleState.None,
					'podman_installation_info',
					false,
					false,
					'readme'
				);
				(podmanInfoItem as any).description = "Click to view installation details";
				(podmanInfoItem as any).command = {
					command: 'cppPrimerBuddy.showPodmanInstallationGuide',
					title: 'Show Podman Installation Details',
					arguments: []
				};
				rootItems.push(podmanInfoItem);
			}
			
			return Promise.resolve(rootItems);
		} else {
			// Child items - sections within a chapter
			return Promise.resolve(this.getChildItems(element));
		}
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

	private getCurrentCourseId(): string {
		// Extract course ID from extension name
		// For example, "cpp-primer-5th-buddy" -> "cpp-primer-5th"
		const extensionName = vscode.extensions.all
			.find(ext => ext.id.includes('buddy'))?.id.split('.')[1] || 'cpp-primer-5th';
		
		return extensionName.replace('-buddy', '');
	}

	private async fetchCourseStructureFromRepository(): Promise<CourseStructure | null> {
		// For testing, return the same test data as getDefaultCourseStructure
		// In a real implementation, this would fetch from the course-content-provider
		return this.getDefaultCourseStructure();
	}

	private getDefaultCourseStructure(): CourseStructure {
		// Chapter structure following C++ Primer 5th Edition with test items
		return {
			version: "1.0",
			title: "C++ Primer 5th Edition",
			description: "Learning path for C++ Primer 5th Edition",
			chapters: [
				{
					id: "1_getting_started",
					title: "1. Getting Started",
					protected: false,
					sections: [
						{
							id: "introduction",
							title: "Introduction to C++",
							type: "readme"
						},
						{
							id: "first_program",
							title: "Writing Your First Program",
							type: "exercise"
						},
						{
							id: "compiling",
							title: "Compiling and Running",
							type: "readme"
						}
					]
				},
				{
					id: "2_variables",
					title: "2. Variables and Basic Types",
					protected: false,
					sections: [
						{
							id: "variables_intro",
							title: "Introduction to Variables",
							type: "readme"
						},
						{
							id: "basic_types",
							title: "Basic Built-in Types",
							type: "exercise"
						},
						{
							id: "type_conversion",
							title: "Type Conversions",
							type: "readme"
						}
					]
				},
				{
					id: "3_strings",
					title: "3. Strings, Vectors, and Arrays",
					protected: false,
					sections: [
						{
							id: "string_basics",
							title: "String Basics",
							type: "readme"
						},
						{
							id: "string_operations",
							title: "String Operations",
							type: "exercise"
						},
						{
							id: "vector_basics",
							title: "Vector Basics",
							type: "exercise"
						}
					]
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

	private getRootItems(): CourseItem[] {
		if (!this.defaultCourseStructure) {
			return [];
		}

		const items: CourseItem[] = this.defaultCourseStructure.chapters.map(chapter => {
			const isProtected = this.defaultCourseStructure?.protectedChapters.includes(chapter.id) || false;
			const isAccessible = !isProtected || this.protectionManager.isChapterAccessible(chapter.id);
			
			// Chapters are collapsed by default
			const collapsibleState = chapter.sections && chapter.sections.length > 0 ? 
				vscode.TreeItemCollapsibleState.Collapsed : vscode.TreeItemCollapsibleState.None;
				
			const courseItem = new CourseItem(
				chapter.title,
				collapsibleState,
				chapter.id,
				isProtected && !isAccessible,
				true,
				'directory'
			);
			
			// Add context value for chapter items to enable download command
			// All first-level items are downloadable as they represent complete chapters
			(courseItem as any).contextValue = 'exerciseItem';
			
			return courseItem;
		});
		
		// Note: Podman info item is now added in getChildren method based on availability
		// This ensures it only appears when appropriate
		
		return items;
	}

	private getChildItems(element: CourseItem): CourseItem[] {
		if (!this.defaultCourseStructure) {
			return [];
		}

		// Find the chapter that matches the element's path
		const chapter = this.defaultCourseStructure.chapters.find(ch => ch.id === element.fullPath);
		if (!chapter || !chapter.sections) {
			return [];
		}

		// Create child items for each section
		return chapter.sections.map(section => {
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
	public getCurrentCourseStructure(): CourseStructure | null {
		return this.defaultCourseStructure;
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
	private getInstallationInstructionDetails(_itemPath: string): string {
		return "🔒 Learning Buddy requires Podman to securely deliver course content and manage licenses.\n\n" +
			"Podman runs in a lightweight, daemonless container environment that ensures content protection.\n\n" +
			"📝 Please follow these steps to install Podman on your system:\n\n" +
			"1. Visit the official Podman website (https://podman.io) and download the installer for your operating system.\n" +
			"2. Follow the installation instructions for your platform.\n" +
			"3. After installing Podman, completely close and restart VS Code to ensure the Learning Buddy extension can detect it.\n\n" +
			"🔗 Platform-Specific Installation Guides:\n" +
			"• Windows: Podman Desktop + WSL2\n" +
			"• macOS: Homebrew Installation\n" +
			"• Linux: Distribution Package Managers\n\n" +
			"💬 If you need help with installation, click here to contact our support team via WeChat.";
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
