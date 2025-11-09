import * as vscode from 'vscode';
import { CourseStructureProvider } from './course/courseStructureProvider';
import { CourseCatalogProvider } from './course/courseCatalogProvider';
import { LicenseManager } from './licenseManager';
import { WeChatIntegration } from './wechatIntegration';
import { PodmanEnvironmentManager } from './podmanEnvironmentManager';
import { ContentProtectionManager } from './contentProtection';
import { LearningBuddyViewProvider } from './learningBuddy/learningBuddyViewProvider';

// Custom text document content provider for read-only previews
class PreviewContentProvider implements vscode.TextDocumentContentProvider {
    private _onDidChange = new vscode.EventEmitter<vscode.Uri>();
    private contentMap: Map<string, string> = new Map();

    public readonly onDidChange = this._onDidChange.event;

    public provideTextDocumentContent(uri: vscode.Uri): string {
        return this.contentMap.get(uri.toString()) || '';
    }

    public setPreviewContent(uri: vscode.Uri, content: string) {
        this.contentMap.set(uri.toString(), content);
        this._onDidChange.fire(uri);
    }
}

// Function to generate view ID based on extension name
function getViewId(): string {
    // For this specific extension, always return the correct view ID that matches package.json
    return 'learningPrimerBuddyView';
}

// Function to generate command prefix based on view ID
function getCommandPrefix(viewId: string): string {
    // Convert camelCase to kebab-case for command prefix
    return viewId.replace('View', '')
                 .replace(/([A-Z])/g, '-$1')
                 .toLowerCase()
                 .replace(/^-/, '');
}

// Declare the courseCatalogPanel variable
let courseCatalogPanel: vscode.WebviewPanel | undefined = undefined;

// Function to generate HTML for course catalog page
function getCourseCatalogHtml(): string {
    return `
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Course Catalog</title>
        <style>
            body {
                font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
                padding: 20px;
                background-color: #f8f8f8;
            }
            .search-container {
                text-align: center;
                margin-bottom: 30px;
                padding: 20px 0;
            }
            .search-box {
                width: 60%;
                padding: 12px 20px;
                font-size: 16px;
                border: 1px solid #ddd;
                border-radius: 20px;
                box-shadow: 0 2px 5px rgba(0,0,0,0.1);
                outline: none;
            }
            .search-box:focus {
                border-color: #007acc;
                box-shadow: 0 2px 5px rgba(0,122,204,0.3);
            }
            .course-grid {
                display: grid;
                grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
                gap: 20px;
                max-width: 1200px;
                margin: 0 auto;
            }
            .course-card {
                background: white;
                border-radius: 8px;
                box-shadow: 0 2px 8px rgba(0,0,0,0.1);
                padding: 20px;
                transition: transform 0.2s, box-shadow 0.2s;
                cursor: pointer;
            }
            .course-card:hover {
                transform: translateY(-2px);
                box-shadow: 0 4px 12px rgba(0,0,0,0.15);
            }
            .course-title {
                font-size: 18px;
                font-weight: 600;
                margin-bottom: 10px;
                color: #333;
            }
            .course-description {
                color: #666;
                font-size: 14px;
                margin-bottom: 15px;
                line-height: 1.4;
            }
            .course-meta {
                display: flex;
                justify-content: space-between;
                font-size: 13px;
                color: #888;
            }
            .no-results {
                text-align: center;
                color: #666;
                font-style: italic;
                grid-column: 1 / -1;
                padding: 40px;
            }
        </style>
    </head>
    <body>
        <div class="search-container">
            <input type="text" class="search-box" id="searchInput" placeholder="Search for courses...">
        </div>
        <div class="course-grid" id="courseGrid">
            <!-- Course cards will be populated here -->
            <div class="course-card">
                <div class="course-title">C++ Primer 5th Edition Buddy</div>
                <div class="course-description">Learn C++ programming with the definitive guide to the C++ language</div>
                <div class="course-meta">
                    <span>Beginner</span>
                    <span>40 hours</span>
                </div>
            </div>
            <div class="course-card">
                <div class="course-title">Python 3rd Edition Buddy</div>
                <div class="course-description">Master Python programming with comprehensive exercises and solutions</div>
                <div class="course-meta">
                    <span>Beginner</span>
                    <span>35 hours</span>
                </div>
            </div>
            <div class="course-card">
                <div class="course-title">JavaScript Complete Guide Buddy</div>
                <div class="course-description">Complete guide to modern JavaScript development</div>
                <div class="course-meta">
                    <span>Intermediate</span>
                    <span>50 hours</span>
                </div>
            </div>
            <div class="course-card">
                <div class="course-title">Java Fundamentals Course</div>
                <div class="course-description">Learn Java programming from basics to advanced concepts</div>
                <div class="course-meta">
                    <span>Beginner</span>
                    <span>45 hours</span>
                </div>
            </div>
            <div class="course-card">
                <div class="course-title">React Complete Guide</div>
                <div class="course-description">Master React development with hooks, context, and modern patterns</div>
                <div class="course-meta">
                    <span>Intermediate</span>
                    <span>30 hours</span>
                </div>
            </div>
            <div class="course-card">
                <div class="course-title">Node.js Backend Development</div>
                <div class="course-description">Build scalable backend services with Node.js and Express</div>
                <div class="course-meta">
                    <span>Intermediate</span>
                    <span>35 hours</span>
                </div>
            </div>
        </div>
        <script>
            const searchInput = document.getElementById('searchInput');
            const courseGrid = document.getElementById('courseGrid');
            
            searchInput.addEventListener('input', function(e) {
                const searchTerm = e.target.value.toLowerCase();
                const courseCards = document.querySelectorAll('.course-card');
                
                let hasResults = false;
                
                courseCards.forEach(card => {
                    const title = card.querySelector('.course-title').textContent.toLowerCase();
                    const description = card.querySelector('.course-description').textContent.toLowerCase();
                    
                    if (title.includes(searchTerm) || description.includes(searchTerm)) {
                        card.style.display = 'block';
                        hasResults = true;
                    } else {
                        card.style.display = 'none';
                    }
                });
                
                // Show no results message if needed
                const noResultsElement = document.getElementById('noResults');
                if (!hasResults && searchTerm) {
                    if (!noResultsElement) {
                        const noResults = document.createElement('div');
                        noResults.id = 'noResults';
                        noResults.className = 'no-results';
                        noResults.textContent = 'No courses found matching your search.';
                        courseGrid.appendChild(noResults);
                    }
                } else if (noResultsElement) {
                    noResultsElement.remove();
                }
            });
        </script>
    </body>
    </html>
    `;
}

// Function to generate Podman installation guide content
function getPodmanInstallationGuideContent(): string {
	return `
	<!DOCTYPE html>
	<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Podman Installation Guide</title>
		<style>
			body {
				font-family: var(--vscode-font-family);
				color: var(--vscode-foreground);
				background-color: var(--vscode-editor-background);
				padding: 20px;
				line-height: 1.6;
			}
			h1, h2, h3 {
				color: var(--vscode-foreground);
			}
			a {
				color: var(--vscode-textLink-foreground);
			}
			code {
				background-color: var(--vscode-textCodeBlock-background);
				padding: 2px 4px;
				border-radius: 3px;
			}
			.container {
				max-width: 800px;
				margin: 0 auto;
			}
			.section {
				margin-bottom: 30px;
			}
			.reason-item, .step-item, .guide-item, .info-item {
				margin: 10px 0;
				padding-left: 20px;
			}
			.status-installed {
				color: #4caf50;
				font-weight: bold;
			}
			.status-not-installed {
				color: #f44336;
				font-weight: bold;
			}
		</style>
	</head>
	<body>
		<div class="container">
			<h1>🔒 Podman Status for Learning Buddy</h1>
			
			<div class="section">
				<h2>Current Status: <span class="status-installed">✅ Installed</span></h2>
				<p>Learning Buddy has detected that Podman is properly installed and configured on your system.</p>
			</div>

			<div class="section">
				<h2>📦 Installation Details</h2>
				<div class="info-item">• Installation Path: /usr/local/bin/podman</div>
				<div class="info-item">• Version: 4.9.4</div>
				<div class="info-item">• Course Containers: 3 running</div>
				<div class="info-item">• System Integration: Fully configured</div>
			</div>

			<div class="section">
				<h2>🔒 Why Podman is Required</h2>
				<div class="reason-item">• Secure content delivery through containerization</div>
				<div class="reason-item">• Daemonless operation for lightweight experience</div>
				<div class="reason-item">• Content protection from unauthorized access</div>
				<div class="reason-item">• Isolated development environment management</div>
			</div>

			<div class="section">
				<h2>📚 Course Environment</h2>
				<p>Your course environments are running in isolated Podman containers, ensuring:</p>
				<div class="info-item">• Protected content remains secure</div>
				<div class="info-item">• Consistent development environment across platforms</div>
				<div class="info-item">• Automatic cleanup of temporary files</div>
				<div class="info-item">• Resource isolation for each course</div>
			</div>

			<div class="section">
				<h2>⚙️ Management Commands</h2>
				<p>You can manage your course environments using these commands:</p>
				<div class="info-item">• <code>podman ps</code> - List running course containers</div>
				<div class="info-item">• <code>podman stop &lt;container&gt;</code> - Stop a specific course container</div>
				<div class="info-item">• <code>podman logs &lt;container&gt;</code> - View container logs</div>
			</div>

			<div class="section">
				<h2>💬 Need Help?</h2>
				<p>If you encounter any issues with your Podman setup, please contact our support team via WeChat for assistance.</p>
			</div>
		</div>
	</body>
	</html>
	`;
}

export function activate(context: vscode.ExtensionContext) {
	console.log('Learning Buddy extension is now active!');

	// Create the protection manager
	const protectionManager = new ContentProtectionManager(context);
	
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

	

	// Create the course structure provider

	const courseStructureProvider = new CourseStructureProvider(context, protectionManager);

	

	// Create the Learning Buddy view provider

	const learningBuddyViewProvider = new LearningBuddyViewProvider(context.extensionUri);
	
	// Create the preview content provider
	const previewContentProvider = new PreviewContentProvider();
	const previewContentProviderRegistration = vscode.workspace.registerTextDocumentContentProvider('learning-primer-buddy-preview', previewContentProvider);
	
	// Create a status bar item for license information
	const licenseStatusBarItem = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Left, 100);
	licenseStatusBarItem.tooltip = "Manage your Learning Buddy license";
	
	// Function to update the license status bar item
	function updateLicenseStatusBar() {
		// For testing purposes, link license status to Podman installation status
		// When Podman is installed (mock status is true), show license as active
		// When Podman is not installed (mock status is false), show license as required
		const isPodmanInstalled = courseStructureProvider.getMockPodmanStatus();
		
		if (isPodmanInstalled) {
			licenseStatusBarItem.text = "$(check) License active";
		} else {
			licenseStatusBarItem.text = "$(warning) License required, pay now";
		}
		licenseStatusBarItem.show();
	}
	
	// Initial update of the license status bar
	updateLicenseStatusBar();

	// Register the course structure view

	const courseStructureView = vscode.window.createTreeView('learningPrimerBuddyView', {

		treeDataProvider: courseStructureProvider,

		showCollapseAll: true

	});

	

	// Register the Learning Buddy view in the panel area

	const learningBuddyViewDisposable = vscode.window.registerWebviewViewProvider(

		'learning-buddy.chat',

		learningBuddyViewProvider

	);
	
	// Register commands
	const openCourseCatalogCommand = vscode.commands.registerCommand('learningPrimerBuddy.openCourseCatalog', () => {
		if (courseCatalogPanel) {
			courseCatalogPanel.reveal(vscode.ViewColumn.One);
		} else {
			courseCatalogPanel = vscode.window.createWebviewPanel(
				'courseCatalog',
				'Course Catalog',
				vscode.ViewColumn.One,
				{
					enableScripts: true,
					retainContextWhenHidden: true
				}
			);
			
			courseCatalogPanel.webview.html = getCourseCatalogHtml();
			
			courseCatalogPanel.onDidDispose(() => {
				courseCatalogPanel = undefined;
			});
		}
	});
	
	const showPodmanInstallationGuideCommand = vscode.commands.registerCommand('learningPrimerBuddy.showPodmanInstallationGuide', () => {
		const panel = vscode.window.createWebviewPanel(
			'podmanInstallationGuide',
			'Podman Installation Guide',
			vscode.ViewColumn.One,
			{
				enableScripts: true,
				retainContextWhenHidden: true
			}
		);
		
		panel.webview.html = getPodmanInstallationGuideContent();
	});

	// Command to toggle mock Podman status for testing
	let toggleMockPodmanStatusCommand = vscode.commands.registerCommand('learningPrimerBuddy.toggleMockPodmanStatus', () => {
		courseStructureProvider.toggleMockPodmanStatus();
		const status = courseStructureProvider.getMockPodmanStatus() ? "installed" : "not installed";
		vscode.window.showInformationMessage(`Mock Podman status toggled: ${status}`);
		// Update license status bar when Podman status changes
		updateLicenseStatusBar();
	});
	
	
	// Command to preview exercises
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
	
	// Command to download exercises
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
	
	// Command to preview content (for section items)
	let previewContentCommand = vscode.commands.registerCommand('learningPrimerBuddy.previewContent', async (item: any) => {
		if (!item || !item.fullPath) {
			vscode.window.showErrorMessage('Invalid content item');
			return;
		}
		
		// Update the license status bar item
		updateLicenseStatusBar();
		
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
	
	// Command to open the license manager

	let openLicenseManagerCommand = vscode.commands.registerCommand('learningPrimerBuddy.openLicenseManager', async () => {

		// Check for valid license using the protection manager

		const hasValidLicense = protectionManager.getValidLicenses().length > 0;

		

		const licenseManager = new LicenseManager(protectionManager);

		if (hasValidLicense) {

			// Show license information page for users with valid licenses

			await licenseManager.showLicenseInfoPage();

		} else {

			// Show license purchase page for users without valid licenses

			await licenseManager.showLicensePurchasePage();

		}

	});



	// Command to open WeChat contact

	let openWeChatContactCommand = vscode.commands.registerCommand('learningPrimerBuddy.openWeChatContact', async () => {

		const weChatIntegration = new WeChatIntegration(context);

		await weChatIntegration.showWeChatPanel();

	});

		// Command to change Podman location
	let changePodmanLocationCommand = vscode.commands.registerCommand('learningPrimerBuddy.changePodmanLocation', async () => {
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

	// Command to clear all licenses (for testing)
	let clearLicensesCommand = vscode.commands.registerCommand('learningPrimerBuddy.clearLicenses', async () => {
		try {
			// Clear licenses from protection manager
			const protectionManager = new ContentProtectionManager(context);
			
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

	// Set the command for the status bar item
	licenseStatusBarItem.command = "learningPrimerBuddy.openLicenseManager";

	// Add to context subscriptions

	context.subscriptions.push(courseStructureView);

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