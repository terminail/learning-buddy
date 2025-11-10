import * as vscode from 'vscode';
import { CourseItem, CourseCatalog } from './types';
import { CourseContentProviderClient } from '../courseContentProviderClient';

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

	// Add command handler for course selection
	public handleCourseSelection(courseId: string): void {
		// Trigger the course selection command
		vscode.commands.executeCommand('learningPrimerBuddy.selectCourse', courseId);
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
		// Default course catalog with sample courses for license status testing
		// Courses are designed to test all three license scenarios:
		// 1. License Paid - User has valid license for protected course
		// 2. License Free - Course has no protected content (free course)
		// 3. License Required - User has no license for protected course
		return {
			version: "1.0",
			type: "catalog",
			courses: [
				{
					id: "cpp-primer-5th",
					title: "C++ Primer 5th Edition (Protected)",
					description: "Learn C++ programming with the definitive guide to the C++ language - PROTECTED CONTENT",
					type: "course",
					exercises: [
						{
							id: "intro-exercise",
							title: "Introduction to C++",
							description: "Basic concepts of C++ programming",
							type: "exercise",
							folders: [],
							files: []
						}
					]
				},
				{
					id: "python-3rd",
					title: "Python 3rd Edition (Free)",
					description: "Master Python programming with comprehensive exercises and solutions - FREE CONTENT",
					type: "course",
					exercises: [
						{
							id: "python-intro",
							title: "Python Basics",
							description: "Introduction to Python programming",
							type: "exercise",
							folders: [],
							files: []
						}
					]
				},
				{
					id: "javascript-complete",
					title: "JavaScript Complete Guide (Protected)",
					description: "Complete guide to modern JavaScript development - PROTECTED CONTENT",
					type: "course",
					exercises: [
						{
							id: "js-fundamentals",
							title: "JavaScript Fundamentals",
							description: "Core JavaScript concepts",
							type: "exercise",
							folders: [],
							files: []
						}
					]
				},
				{
					id: "java-fundamentals",
					title: "Java Fundamentals (Free)",
					description: "Learn Java programming from basics to advanced concepts - FREE CONTENT",
					type: "course",
					exercises: [
						{
							id: "java-intro",
							title: "Java Introduction",
							description: "Basics of Java programming",
							type: "exercise",
							folders: [],
							files: []
						}
					]
				},
				{
					id: "react-complete",
					title: "React Complete Guide (Protected)",
					description: "Master React development with hooks, context, and modern patterns - PROTECTED CONTENT",
					type: "course",
					exercises: [
						{
							id: "react-basics",
							title: "React Basics",
							description: "Introduction to React development",
							type: "exercise",
							folders: [],
							files: []
						}
					]
				},
				{
					id: "nodejs-backend",
					title: "Node.js Backend Development (Free)",
					description: "Build scalable backend services with Node.js and Express - FREE CONTENT",
					type: "course",
					exercises: [
						{
							id: "nodejs-intro",
							title: "Node.js Introduction",
							description: "Basics of Node.js development",
							type: "exercise",
							folders: [],
							files: []
						}
					]
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
			const label = `${course.title}`;
			const description = `${course.exercises.length} exercises`;
			
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
			(courseItem as any).tooltip = `${course.title}\n${course.description}\nExercises: ${course.exercises.length}`;
			
			// Add context value for menu actions
			(courseItem as any).contextValue = 'courseItem';
			
			// Add command to handle course selection when clicked
			(courseItem as any).command = {
				command: 'learningPrimerBuddy.selectCourse',
				title: 'Select Course',
				arguments: [course.id, course.title, false]
			};
			
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