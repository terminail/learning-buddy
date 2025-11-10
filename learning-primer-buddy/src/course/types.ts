import * as vscode from 'vscode';

// New model: CourseCatalog has many Course, 
// Course has many CourseExercise, etc.

// High-level types
export interface CourseCatalog {
    version: string;
    courses: Course[];
    type: 'catalog';
}

export interface Course {
    id: string;
    title: string;
    description: string;
    exercises: CourseExercise[];
    type: 'course';
}

// Mid-level types
export interface CourseExercise {
    id: string;
    title: string;
    description: string;
    folders: Folder[];
    files: File[];
    type: 'exercise';
}

// Low-level types
export interface Folder {
    id: string;
    name: string;
    path: string;
    folders: Folder[];
    files: File[];
    type: 'folder';
}

export interface File {
    id: string;
    name: string;
    path: string;
    extension: string;
    type: 'file';
}

// CourseItem class for VS Code tree view
export class CourseItem extends vscode.TreeItem {
	constructor(
		public readonly label: string,
		public readonly collapsibleState: vscode.TreeItemCollapsibleState,
		public readonly fullPath: string,
		public readonly isLocked: boolean = false,
		public readonly isDirectory: boolean = false,
		public readonly itemType: 'exercise' | 'solution' | 'hint' | 'readme' | 'directory' | 'promotion' | 'file' | 'folder' = 'exercise'
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
				case 'file':
					(this as any).contextValue = 'fileItem';
					break;
				case 'folder':
					(this as any).contextValue = 'folderItem';
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
				case 'file':
					(this as any).iconPath = new vscode.ThemeIcon('file');
					break;
				case 'folder':
					(this as any).iconPath = new vscode.ThemeIcon('folder');
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