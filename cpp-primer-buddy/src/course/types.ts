import * as vscode from 'vscode';

// Define the course structure types
export interface CourseSection {
    id: string;
    title: string;
    type: 'exercise' | 'solution' | 'hint' | 'readme' | 'directory';
    file?: string;
}

export interface CourseChapter {
    id: string;
    title: string;
    protected: boolean;
    sections?: CourseSection[];
}

export interface CourseStructure {
    version: string;
    title: string;
    description: string;
    chapters: CourseChapter[];
    protectedChapters: string[];
}

// Define the course catalog types
export interface CourseRepository {
    type: string;
    url: string;
    branch: string;
}

export interface CourseInfo {
    id: string;
    name: string;
    description: string;
    repository: CourseRepository;
    icon?: string;
    level?: string;
    estimatedHours?: number;
}

export interface CourseCatalog {
    version: string;
    courses: CourseInfo[];
}

export class CourseItem extends vscode.TreeItem {
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
		
		// Set context value based on whether this is a first-level item, folder, or page
		if (isDirectory) {
			// This is handled in the course structure provider
		} else {
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
				case 'promotion':
					(this as any).contextValue = 'promotionItem';
					break;
				default:
					(this as any).contextValue = 'pageItem';
			}
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
		
		// Add command for page items to preview content
		if (!isDirectory) {
			// Add a command to preview the content
			(this as any).command = {
				command: 'learningPrimerBuddy.previewContent',
				title: 'Preview Content',
				arguments: [this]
			};
		}
	}
}
