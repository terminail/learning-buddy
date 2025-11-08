import * as vscode from 'vscode';
import { CourseItem, CourseCatalog, CourseInfo } from './types';
import { CourseContentProviderClient } from '../courseContentProvider';

export class CourseCatalogProvider implements vscode.TreeDataProvider<CourseItem> {
	private _onDidChangeTreeData: vscode.EventEmitter<CourseItem | undefined | void> = new vscode.EventEmitter<CourseItem | undefined | void>();
	readonly onDidChangeTreeData: vscode.Event<CourseItem | undefined | void> = this._onDidChangeTreeData.event;
	private courseContentProvider: CourseContentProviderClient;
	private defaultCourseCatalog: CourseCatalog | null = null;
	private searchTerm: string = '';

	constructor(private context: vscode.ExtensionContext) {
		// Initialize the Course Content Provider client
		this.courseContentProvider = new CourseContentProviderClient(context);
		// Load default course catalog when the provider is initialized
		this.loadDefaultCourseCatalog();
	}

	/**
	 * Set search term to filter courses
	 */
	public setSearchTerm(term: string): void {
		this.searchTerm = term;
		this.refresh();
	}

	/**
	 * Refresh the tree view to reflect updated course catalog
	 */
	public async refresh(): Promise<void> {
		// Reload default course catalog
		await this.loadDefaultCourseCatalog();
		// Refresh the tree view
		this._onDidChangeTreeData.fire();
	}

	getTreeItem(element: CourseItem): vscode.TreeItem {
		return element;
	}

	getChildren(element?: CourseItem): vscode.ProviderResult<CourseItem[]> {
		if (!element) {
			// Root level items - course catalog displayed as grid
			return Promise.resolve(this.getRootItems());
		} else {
			// For grid layout, we don't need child items
			return Promise.resolve([]);
		}
	}

	private async loadDefaultCourseCatalog(): Promise<void> {
		try {
			// Try to load from cache first
			const cachedCatalog = this.context.globalState.get<CourseCatalog>(`courseCatalog`);
			if (cachedCatalog && !this.searchTerm) {
				this.defaultCourseCatalog = cachedCatalog;
				return;
			}

			// Use the Course Content Provider to fetch catalog
			// If we have a search term, use it to filter results
			let catalog: CourseCatalog | null = null;
			if (this.searchTerm) {
				const searchResults = await this.courseContentProvider.searchCourses(this.searchTerm);
				if (searchResults) {
					catalog = searchResults;
				}
			} else {
				// Otherwise, get the full catalog
				catalog = await this.courseContentProvider.getCourseCatalog();
			}

			if (catalog) {
				this.defaultCourseCatalog = catalog;
				// Cache the catalog (only cache full catalog, not search results)
				if (!this.searchTerm) {
					this.context.globalState.update(`courseCatalog`, catalog);
				}
			} else if (this.defaultCourseCatalog) {
				// Already have cached catalog
				return;
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
				},
				{
					id: "java-fundamentals",
					name: "Java Fundamentals Course",
					description: "Learn Java programming from basics to advanced concepts",
					repository: {
						type: "github",
						url: "https://github.com/conanchen/java_fundamentals",
						branch: "main"
					},
					level: "Beginner",
					estimatedHours: 45
				},
				{
					id: "react-complete",
					name: "React Complete Guide",
					description: "Master React development with hooks, context, and modern patterns",
					repository: {
						type: "github",
						url: "https://github.com/conanchen/react_complete",
						branch: "main"
					},
					level: "Intermediate",
					estimatedHours: 30
				},
				{
					id: "nodejs-backend",
					name: "Node.js Backend Development",
					description: "Build scalable backend services with Node.js and Express",
					repository: {
						type: "github",
						url: "https://github.com/conanchen/nodejs_backend",
						branch: "main"
					},
					level: "Intermediate",
					estimatedHours: 35
				}
			]
		};
	}

	private getRootItems(): CourseItem[] {
		if (!this.defaultCourseCatalog) {
			return [];
		}

		// Create grid-like display with course cards
		const items: CourseItem[] = this.defaultCourseCatalog.courses.map(course => {
			// Create a descriptive label that shows key course information
			const label = `${course.name}`;
			const description = `${course.level || 'Not specified'} • ${course.estimatedHours || '?'} hours`;
			
			// Create a course item that represents a "card" in our grid
			const courseItem = new CourseItem(
				label,
				vscode.TreeItemCollapsibleState.None, // No children for grid layout
				course.id,
				false,
				false, // Not a directory
				'exercise' // Use exercise icon for course cards
			);
			
			// Add description with level and hours
			(courseItem as any).description = description;
			
			// Add tooltip with full course details
			(courseItem as any).tooltip = `${course.name}\n${course.description}\nLevel: ${course.level || 'Not specified'}\nEstimated Hours: ${course.estimatedHours || 'Not specified'}`;
			
			// Add context value for menu actions
			(courseItem as any).contextValue = 'courseItem';
			
			return courseItem;
		});
		
		// If no courses found, show a message
		if (items.length === 0 && this.searchTerm) {
			const noResultsItem = new CourseItem(
				`No courses found for "${this.searchTerm}"`,
				vscode.TreeItemCollapsibleState.None,
				'no-results',
				false,
				false,
				'readme'
			);
			(noResultsItem as any).description = 'Try a different search term';
			items.push(noResultsItem);
		}
		
		return items;
	}
}