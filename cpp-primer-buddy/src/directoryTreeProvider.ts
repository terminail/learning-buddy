import * as vscode from 'vscode';
import * as path from 'path';
import * as fs from 'fs';

export class StudyItem extends vscode.TreeItem {
	constructor(
		public readonly label: string,
		public readonly collapsibleState: vscode.TreeItemCollapsibleState,
		public readonly fullPath: string,
		public readonly isLocked: boolean = false,
		public readonly isDirectory: boolean = false,
		public readonly itemType: 'exercise' | 'solution' | 'hint' | 'readme' | 'directory' = 'exercise'
	) {
		super(label, collapsibleState);
		
		(this as any).tooltip = this.label;
		(this as any).description = isLocked ? '(locked)' : '';
		
		// Set the context value for menu visibility
		if (isLocked) {
			(this as any).contextValue = 'lockedItem';
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
				case 'directory':
					(this as any).contextValue = 'directoryItem';
					break;
			}
		}
		
		// Set icon based on item type
		if (isLocked) {
			(this as any).iconPath = new vscode.ThemeIcon('lock');
		} else if (isDirectory) {
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
				default:
					(this as any).iconPath = new vscode.ThemeIcon('file');
			}
		}
	}
}

export class CppPrimerTreeViewProvider implements vscode.TreeDataProvider<StudyItem> {
	private _onDidChangeTreeData: vscode.EventEmitter<StudyItem | undefined | void> = new vscode.EventEmitter<StudyItem | undefined | void>();
	readonly onDidChangeTreeData: vscode.Event<StudyItem | undefined | void> = this._onDidChangeTreeData.event;

	constructor(private context: vscode.ExtensionContext) {}

	getTreeItem(element: StudyItem): vscode.TreeItem {
		return element;
	}

	getChildren(element?: StudyItem): vscode.ProviderResult<StudyItem[]> {
		if (!element) {
			// Root level items - chapters
			return Promise.resolve(this.getRootItems());
		} else {
			// Child items - exercises and materials
			return Promise.resolve(this.getChildItems(element));
		}
	}

	private getRootItems(): StudyItem[] {
		// Chapter structure following C++ Primer 5th Edition
		const items: StudyItem[] = [
			new StudyItem('1. Getting Started', vscode.TreeItemCollapsibleState.Collapsed, '1_getting_started', false, true, 'directory'),
			new StudyItem('2. Variables and Basic Types', vscode.TreeItemCollapsibleState.Collapsed, '2_variables', false, true, 'directory'),
			new StudyItem('3. Strings, Vectors, and Arrays', vscode.TreeItemCollapsibleState.Collapsed, '3_strings', false, true, 'directory'),
			new StudyItem('4. Expressions', vscode.TreeItemCollapsibleState.Collapsed, '4_expressions', false, true, 'directory'),
			new StudyItem('5. Statements', vscode.TreeItemCollapsibleState.Collapsed, '5_statements', false, true, 'directory'),
			new StudyItem('6. Functions', vscode.TreeItemCollapsibleState.Collapsed, '6_functions', false, true, 'directory'),
			new StudyItem('7. Classes', vscode.TreeItemCollapsibleState.Collapsed, '7_classes', true, true, 'directory'),
			new StudyItem('8. The IO Library', vscode.TreeItemCollapsibleState.Collapsed, '8_io', true, true, 'directory')
		];
		
		return items;
	}

	private getChildItems(parent: StudyItem): StudyItem[] {
		const childItems: StudyItem[] = [];
		
		if (!parent.isLocked) {
			// Only show children for unlocked items
			switch (parent.fullPath) {
				case '1_getting_started':
					childItems.push(
						new StudyItem('Hello World Program', vscode.TreeItemCollapsibleState.None, '1_getting_started/hello_world.cpp', false, false, 'exercise'),
						new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, '1_getting_started/solution.cpp', false, false, 'solution'),
						new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, '1_getting_started/README.md', false, false, 'readme'),
						new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, '1_getting_started/hint.md', false, false, 'hint')
					);
					break;
				case '2_variables':
					childItems.push(
						new StudyItem('Variable Declarations', vscode.TreeItemCollapsibleState.None, '2_variables/exercise.cpp', false, false, 'exercise'),
						new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, '2_variables/solution.cpp', false, false, 'solution'),
						new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, '2_variables/README.md', false, false, 'readme'),
						new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, '2_variables/hint.md', false, false, 'hint')
					);
					break;
				case '3_strings':
					childItems.push(
						new StudyItem('String Operations', vscode.TreeItemCollapsibleState.None, '3_strings/exercise.cpp', false, false, 'exercise'),
						new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, '3_strings/solution.cpp', false, false, 'solution'),
						new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, '3_strings/README.md', false, false, 'readme'),
						new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, '3_strings/hint.md', false, false, 'hint')
					);
					break;
				case '4_expressions':
					childItems.push(
						new StudyItem('Arithmetic Expressions', vscode.TreeItemCollapsibleState.None, '4_expressions/exercise.cpp', false, false, 'exercise'),
						new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, '4_expressions/solution.cpp', false, false, 'solution'),
						new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, '4_expressions/README.md', false, false, 'readme'),
						new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, '4_expressions/hint.md', false, false, 'hint')
					);
					break;
				case '5_statements':
					childItems.push(
						new StudyItem('Control Flow', vscode.TreeItemCollapsibleState.None, '5_statements/exercise.cpp', false, false, 'exercise'),
						new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, '5_statements/solution.cpp', false, false, 'solution'),
						new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, '5_statements/README.md', false, false, 'readme'),
						new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, '5_statements/hint.md', false, false, 'hint')
					);
					break;
				case '6_functions':
					childItems.push(
						new StudyItem('Function Basics', vscode.TreeItemCollapsibleState.None, '6_functions/exercise.cpp', false, false, 'exercise'),
						new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, '6_functions/solution.cpp', false, false, 'solution'),
						new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, '6_functions/README.md', false, false, 'readme'),
						new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, '6_functions/hint.md', false, false, 'hint')
					);
					break;
				default:
					// For other unlocked directories, show sample content
					childItems.push(
						new StudyItem('Exercise', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/exercise.cpp', false, false, 'exercise'),
						new StudyItem('Solution', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/solution.cpp', false, false, 'solution'),
						new StudyItem('Learning Guide', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/README.md', false, false, 'readme'),
						new StudyItem('Hint', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/hint.md', false, false, 'hint')
					);
			}
		} else {
			// Show locked message for locked chapters
			childItems.push(
				new StudyItem('Content Locked', vscode.TreeItemCollapsibleState.None, parent.fullPath + '/locked', true, false, 'exercise')
			);
		}
		
		return childItems;
	}

	studyItem(item: StudyItem): void {
		if (item.isLocked) {
			vscode.window.showErrorMessage('This content is locked. Please complete previous chapters to unlock.');
			return;
		}
		
		// Copy exercise content to workspace
		this.copyContent(item, 'exercise');
	}

	checkSolution(item: StudyItem): void {
		if (item.isLocked) {
			vscode.window.showErrorMessage('This content is locked.');
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
			vscode.window.showErrorMessage('This content is locked.');
			return;
		}
		
		// Show the solution content
		this.copyContent(item, 'solution');
	}

	showHint(item: StudyItem): void {
		if (item.isLocked) {
			vscode.window.showErrorMessage('This content is locked.');
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
			`3. Refer to C++ Primer 5th Edition Chapter ${item.fullPath.split('_')[0]}
` +
			`4. Try compiling your code to see error messages`
		);
	}

	private copyContent(item: StudyItem, contentType: 'exercise' | 'solution'): void {
		// In a real implementation, this would:
		// 1. Determine the source directory (where the actual cpp_primer_5th content is stored)
		// 2. Ask user for destination directory
		// 3. Copy files from source to destination
		
		let message = '';
		switch (contentType) {
			case 'exercise':
				message = `Exercise "${item.label}" would be copied to your workspace for you to complete.`;
				break;
			case 'solution':
				message = `Solution for "${item.label}" would be opened for reference.`;
				break;
		}
		
		vscode.window.showInformationMessage(message);
		
		// This is where you would implement the actual file copying logic
		// For now, we'll just show a message
	}
}