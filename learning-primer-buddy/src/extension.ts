import * as vscode from 'vscode';
import { MyCoursesProvider } from './course/myCoursesProvider';
import { LicenseManager } from './license/licenseManager';
import { WeChatIntegration } from './wechat/wechatIntegration';
import { PodmanEnvironmentManager } from './podman/podmanEnvironmentManager';
import { CourseContentProtectionManager } from './courseContentProtectionManager';
import { LearningBuddyChatViewProvider } from './buddy/learningBuddyChatViewProvider';
import { CourseCatalogWebview } from './course/courseCatalogWebview';
import { PreviewContentProvider } from './course/previewContentProvider';
import { getPodmanInstallationGuideContent } from './podman/podmanInstallationGuide';

// Function to generate view ID based on extension name
function getViewId(): string {
    // For this specific extension, always return the correct view ID that matches package.json
    return 'learningPrimerBuddyView';
}

// Function to generate command prefix based on view ID
// Convert camelCase to kebab-case for command prefix
function getCommandPrefix(viewId: string): string {
    return viewId.replace('View', '')
                 .replace(/([A-Z])/g, '-$1')
                 .toLowerCase()
                 .replace(/^-/, '');
}

// Main extension activation function
export async function activate(context: vscode.ExtensionContext) {
	console.log('Learning Buddy extension is now active!');

	// Create the protection manager
	const protectionManager = new CourseContentProtectionManager(context);
	
	// Add debugging to see what licenses are available
	console.log('=== Protection Manager Debug Info ===');
	const initialLicenses = protectionManager.getValidLicenses();
	console.log('Initial valid licenses:', initialLicenses);
	console.log('Initial valid licenses count:', initialLicenses.length);
	
	// Check what's in the global state directly
	try {
		const storedLicenses = context.globalState.get('validLicenses', []);
		console.log('Direct global state check - stored licenses:', storedLicenses);
		console.log('Direct global state check - stored licenses count:', storedLicenses.length);
	} catch (error) {
		console.error('Error checking global state directly:', error);
	}
	console.log('====================================');

	// Create the my courses provider first
	const myCoursesProvider = new MyCoursesProvider(context, protectionManager);

	// Create and initialize the Podman environment manager
	const podmanManager = new PodmanEnvironmentManager(context);
	
	// Set up callback for when Podman is not available
	podmanManager.setOnPodmanNotAvailableCallback(() => {
		console.log('Podman not available - notifying my courses provider');
		myCoursesProvider.setPodmanNotAvailable(true);
	});

	// Initialize Podman environment
	console.log('Initializing Podman environment...');
	const podmanAvailable = await podmanManager.initialize();
	console.log('Podman environment initialization result:', podmanAvailable);
	
	// If Podman is available, notify the my courses provider
	if (podmanAvailable) {
		console.log('Podman is available - updating my courses provider');
		myCoursesProvider.setPodmanNotAvailable(false);
	}

	// Create the Learning Buddy chat view provider
	const learningBuddyChatViewProvider = new LearningBuddyChatViewProvider(context.extensionUri);
	
	// Create the preview content provider
	const previewContentProvider = new PreviewContentProvider();
	const previewContentProviderRegistration = vscode.workspace.registerTextDocumentContentProvider('learning-primer-buddy-preview', previewContentProvider);
	
	// Create a status bar item for license information
	const licenseStatusBarItem = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Left, 100);
	licenseStatusBarItem.tooltip = "Manage your Learning Buddy license";
	licenseStatusBarItem.command = "learningbuddygeneric.openLicenseManager";
	
	// Initial update of the license status bar
	LicenseManager.updateLicenseStatusBar(protectionManager, myCoursesProvider, licenseStatusBarItem);

	// Register the my courses view
	const myCoursesView = vscode.window.createTreeView('learningPrimerBuddyView', {
		treeDataProvider: myCoursesProvider,
		showCollapseAll: true
	});

	// Register the Learning Buddy chat view in the panel area
	const learningBuddyViewDisposable = vscode.window.registerWebviewViewProvider(
		'learning-buddy.chat',
		learningBuddyChatViewProvider
	);

	// Generate command prefix using the helper function
	const viewId = getViewId();
	const commandPrefix = getCommandPrefix(viewId);

	// Function to update Learning Buddy chat view title
	function updateLearningBuddyViewTitle(courseName: string) {
		// Update the Learning Buddy chat view title to reflect the current course
		console.log(`Updating Learning Buddy chat view title to: Learning Buddy: ${courseName}`);
		
		// Call the updateCourseTitle method on the LearningBuddyChatViewProvider instance
		learningBuddyChatViewProvider.updateCourseTitle(courseName);
	}
	
	// Register commands
	// Course selection and management commands
	const selectCourseCommand = vscode.commands.registerCommand('learningPrimerBuddy.selectCourse', async (courseId: string, courseName: string, isProtected: boolean) => {
		// Update the current course in the my courses provider
		await myCoursesProvider.setCurrentCourse(courseId);
		
		// Save the current course ID to global state so the course catalog can access it
		await context.globalState.update('currentCourseId', courseId);
		
		// Update the license status bar to reflect the new course
		LicenseManager.updateLicenseStatusBar(protectionManager, myCoursesProvider, licenseStatusBarItem);
		
		// Refresh the my courses view to show the new course
		myCoursesProvider.refresh();
		
		// Update the Learning Buddy chat view title
		updateLearningBuddyViewTitle(courseName);
		
		// Show success message
		vscode.window.showInformationMessage(`Course selected: ${courseName}`);
		
		// Log the protection status for debugging
		console.log(`Course protection status: ${isProtected ? 'Protected' : 'Free'}`);
	});

	const openCourseCatalogCommand = vscode.commands.registerCommand('learningPrimerBuddy.openCourseCatalog', () => {
		// Open the commerce-style course catalog webview in the main panel
		CourseCatalogWebview.createOrShow(context.extensionUri, context);
	});
	
	const refreshCommand = vscode.commands.registerCommand('learningPrimerBuddy.refresh', () => {
		vscode.window.showInformationMessage('Refreshing course structure...');
		myCoursesProvider.refresh();
	});
	
	// Podman-related commands
	const showPodmanInstallationGuideCommand = vscode.commands.registerCommand('learningPrimerBuddy.showPodmanInstallationGuide', () => {
		const panel = vscode.window.createWebviewPanel(
			'podmanInstallationGuide',
			'Podman Installation Guide',
			vscode.ViewColumn.One,
			{
				enableScripts: true,
				retainContextWhenHidden: true,
				enableFindWidget: true,
				localResourceRoots: [vscode.Uri.joinPath(context.extensionUri, 'media')],
				enableCommandUris: true
			}
		);
		
		panel.webview.html = getPodmanInstallationGuideContent();
	});

	const changePodmanLocationCommand = vscode.commands.registerCommand('learningPrimerBuddy.changePodmanLocation', async () => {
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
			context.globalState.update('customPodmanPath', podmanPath);
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
	});
	
	// License-related commands
	const openLicenseManagerCommand = vscode.commands.registerCommand('learningPrimerBuddy.openLicenseManager', async () => {
		// Check for valid license using the protection manager
		const hasValidLicense = protectionManager.getValidLicenses().length > 0;
		// Get current course structure to check for protected content
		const courseStructure = myCoursesProvider.getCurrentCourseStructure();
		const hasProtectedContent = courseStructure && 
			courseStructure.protectedChapters && 
			courseStructure.protectedChapters.length > 0;

		const licenseManager = new LicenseManager(protectionManager);

		// Determine which page to open based on the three license scenarios
		if (hasValidLicense) {
			// License Paid scenario: User has valid license
			await licenseManager.showLicenseInfoPage();
		} else if (hasProtectedContent) {
			// License Required scenario: Course has protected content but no license
			await licenseManager.showLicensePurchasePage();
		} else {
			// License Free scenario: No license needed, course has no protected content
			await licenseManager.showLicenseFreePage();
		}
	});
	
	// Command to toggle mock Podman status for testing
	let toggleMockPodmanStatusCommand = vscode.commands.registerCommand('learningPrimerBuddy.toggleMockPodmanStatus', () => {
		myCoursesProvider.toggleMockPodmanStatus();
		const status = myCoursesProvider.getMockPodmanStatus() ? "installed" : "not installed";
		vscode.window.showInformationMessage(`Mock Podman status toggled: ${status}`);
		// Note: License status is independent of Podman status, so no need to update license status bar
	});
	
	// Command to toggle mock license status for testing
	let toggleMockLicenseStatusCommand = vscode.commands.registerCommand('learningPrimerBuddy.toggleMockLicenseStatus', async () => {
		// Toggle between having a mock license and not having one
		const hasLicense = protectionManager.getValidLicenses().length > 0;
		
		if (hasLicense) {
			// Clear mock licenses
			protectionManager.clearMockLicenses();
			vscode.window.showInformationMessage('Mock license status: License Free (no valid license)');
		} else {
			// Add a mock license
			const mockLicenseKey = 'mock-license-' + Date.now();
			protectionManager.addMockLicense(mockLicenseKey);
			vscode.window.showInformationMessage('Mock license status: License Paid (valid license)');
		}
		
		// Update the status bar to reflect the new license status
		LicenseManager.updateLicenseStatusBar(protectionManager, myCoursesProvider, licenseStatusBarItem);
	});
	
	// Command to clear all licenses (for testing)
	let clearLicensesCommand = vscode.commands.registerCommand('learningPrimerBuddy.clearLicenses', async () => {
		try {
			// Clear licenses from protection manager
			const protectionManager = new CourseContentProtectionManager(context);
			
			// Clear the global state
			await context.globalState.update('validLicenses', []);
			
			vscode.window.showInformationMessage('Licenses cleared successfully!');
			
			// Show updated license status
			const updatedLicenses = protectionManager.getValidLicenses();
			console.log('Licenses after clearing:', updatedLicenses);
			console.log('Licenses count after clearing:', updatedLicenses.length);
		} catch (error) {
			console.error('Error clearing licenses:', error);
			vscode.window.showErrorMessage('Error clearing licenses: ' + error);
		}
	});
	
	// Content preview and download commands
	let previewExerciseCommand = vscode.commands.registerCommand('learningPrimerBuddy.previewExercise', async (item: any) => {
		if (!item || !item.fullPath) {
			vscode.window.showErrorMessage('Invalid exercise item');
			return;
		}
		
		// Show a preview of the exercise in a read-only editor
		const exercisePath = item.fullPath;
		vscode.window.showInformationMessage(`Previewing exercise: ${exercisePath}`);
		
		// In a real implementation, this would fetch the exercise content from the course content provider
		// and display it in a read-only editor. For now, we'll just show a message.
		
		const previewContent = `// Preview of exercise: ${exercisePath}

// This is a read-only preview.
// To edit and run this exercise, download it to your workspace.

// Exercise content would appear here...`;
		
		const previewDoc = await vscode.workspace.openTextDocument({
			content: previewContent,
			language: 'learning'
		});
		
		await vscode.window.showTextDocument(previewDoc, {
			preview: true,
			preserveFocus: false
		});
	});
	
	let downloadExerciseCommand = vscode.commands.registerCommand('learningPrimerBuddy.downloadExercise', async (item: any) => {
		if (!item || !item.fullPath) {
			vscode.window.showErrorMessage('Invalid exercise item');
			return;
		}
		
		// Check for valid license using the protection manager
		const hasValidLicense = protectionManager.getValidLicenses().length > 0;
		
		// If no valid license, show license purchase page
		if (!hasValidLicense) {
			const licenseManager = new LicenseManager(protectionManager);
			await licenseManager.showLicensePurchasePage();
			return;
		}
		
		// Download the exercise to the workspace
		const exercisePath = item.fullPath;
		vscode.window.showInformationMessage(`Downloading exercise: ${exercisePath}`);
		
		// In a real implementation, this would:
		// 1. Fetch the exercise content from the course content provider
		// 2. Save it to the user's workspace
		// 3. Open the downloaded file in an editable editor
		
		// For now, we'll just show a message
		vscode.window.showInformationMessage(`Exercise ${exercisePath} downloaded to workspace and ready for editing!`);
	});
	
	let previewContentCommand = vscode.commands.registerCommand('learningPrimerBuddy.previewContent', async (item: any) => {
		if (!item || !item.fullPath) {
			vscode.window.showErrorMessage('Invalid content item');
			return;
		}
		
		// Update the license status bar item
		LicenseManager.updateLicenseStatusBar(protectionManager, myCoursesProvider, licenseStatusBarItem);
		
		// Preview the content in a read-only editor
		const contentPath = item.fullPath;
		const contentType = item.itemType || 'content';
		
		vscode.window.showInformationMessage(`Previewing ${contentType}: ${contentPath}`);
		
		// Generate content based on type
		let previewContent = `// Preview of ${contentType}: ${contentPath}

`;
		
		switch (contentType) {
			case 'readme':
				previewContent += `/*
 * README CONTENT
 * =============
 * This is the README content for ${contentPath}
 * 
 * Key concepts covered:
 * - Introduction to the topic
 * - Learning objectives
 * - Prerequisites
 * 
 * This content is for preview purposes only.
 * To edit and work with this content, download it to your workspace.
 */`;
				break;
			case 'exercise':
				previewContent += `/*
 * EXERCISE: ${contentPath}
 * =======================
 * 
 * Instructions:
 * Complete the code below according to the specifications.
 * 
 * Requirements:
 * - Follow best practices
 * - Include comments where necessary
 * - Test your solution
 * 
 * This is a preview of the exercise.
 * Download to your workspace to edit and run.
 */

#include <iostream>

int main() {
    // Your code here
    
    return 0;
}`;
				break;
			case 'solution':
				previewContent += `/*
 * SOLUTION: ${contentPath}
 * =======================
 * 
 * This is the model solution for the exercise.
 * 
 * Study this solution to understand:
 * - Best practices
 * - Efficient approaches
 * - Common patterns
 * 
 * Note: This is for learning purposes only.
 */

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    
    return 0;
}`;
				break;
			case 'hint':
				previewContent += `/*
 * HINT: ${contentPath}
 * ===================
 * 
 * Need help with the exercise?
 * 
 * Hints:
 * 1. Consider using a loop for repetitive tasks
 * 2. Remember to validate your inputs
 * 3. Check for edge cases
 * 
 * Try to solve the exercise on your own first,
 * then refer to the solution if needed.
 */`;
				break;
			default:
				previewContent += `// Content preview for ${contentPath}
// This is a read-only preview
// Download to edit`;
		}
		
		// Create a virtual URI for the preview
		const previewUri = vscode.Uri.parse(`learning-primer-buddy-preview://${contentPath}`);
		
		// Set the content in our provider
		previewContentProvider.setPreviewContent(previewUri, previewContent);
		
		// Open the document using our custom provider
		const doc = await vscode.workspace.openTextDocument(previewUri);
		await vscode.window.showTextDocument(doc, { preview: true });
	});
	
	// WeChat integration commands
	let openWeChatContactCommand = vscode.commands.registerCommand('learningPrimerBuddy.openWeChatContact', async () => {
		const weChatIntegration = new WeChatIntegration(context);
		await weChatIntegration.showWeChatPanel();
	});

	// Command for study selected item
	let studySelectedCommand = vscode.commands.registerCommand('learningPrimerBuddy.studySelected', async (item: any) => {
		if (!item) {
			vscode.window.showErrorMessage('Invalid item selected');
			return;
		}
		
		vscode.window.showInformationMessage(`Starting study of: ${item.label || item.name || item.fullPath || 'Unknown item'}`);
		// In a real implementation, this would start the learning process for the selected item
	});

	// Command for course item selection
	let courseItemSelectCommand = vscode.commands.registerCommand('learningPrimerBuddy.courseItemSelect', async (item: any) => {
		if (!item) {
			vscode.window.showErrorMessage('Invalid course item selected');
			return;
		}
		
		vscode.window.showInformationMessage(`Selected course item: ${item.label || item.name || item.fullPath || 'Unknown item'}`);
		// In a real implementation, this would handle the course item selection
	});

	// Add to context subscriptions
	context.subscriptions.push(myCoursesView);
	context.subscriptions.push(learningBuddyViewDisposable);
	context.subscriptions.push(openCourseCatalogCommand);
	context.subscriptions.push(showPodmanInstallationGuideCommand);
	context.subscriptions.push(toggleMockPodmanStatusCommand);
	context.subscriptions.push(previewExerciseCommand);
	context.subscriptions.push(downloadExerciseCommand);
	context.subscriptions.push(openLicenseManagerCommand);
	context.subscriptions.push(openWeChatContactCommand);
	context.subscriptions.push(changePodmanLocationCommand);
	context.subscriptions.push(studySelectedCommand);
	context.subscriptions.push(courseItemSelectCommand);
	context.subscriptions.push(clearLicensesCommand);
	context.subscriptions.push(previewContentProviderRegistration);
	context.subscriptions.push(licenseStatusBarItem);
}
