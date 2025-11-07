import * as vscode from 'vscode';
import { CppPrimerTreeViewProvider } from './treeViewProvider';
import { LicenseManager } from './licenseManager';
import { WeChatIntegration } from './wechatIntegration';

export function activate(context: vscode.ExtensionContext) {
	console.log('C++ Primer Buddy extension is now active!');
	
	// Register the tree view provider
	const treeViewProvider = new CppPrimerTreeViewProvider(context);
	const treeView = vscode.window.createTreeView('cppPrimerBuddyView', {
		treeDataProvider: treeViewProvider
	});

	// Register the command for studying selected items
	let studyCommand = vscode.commands.registerCommand('cppPrimerBuddy.studySelected', (item: any) => {
		if (item) {
			treeViewProvider.studyItem(item);
		}
	});

	// Register command to check solution
	let checkSolutionCommand = vscode.commands.registerCommand('cppPrimerBuddy.checkSolution', (item: any) => {
		if (item) {
			treeViewProvider.checkSolution(item);
		}
	});

	// Register command to view solution
	let viewSolutionCommand = vscode.commands.registerCommand('cppPrimerBuddy.viewSolution', (item: any) => {
		if (item) {
			treeViewProvider.viewSolution(item);
		}
	});

	// Register command to show hint
	let showHintCommand = vscode.commands.registerCommand('cppPrimerBuddy.showHint', (item: any) => {
		if (item) {
			treeViewProvider.showHint(item);
		}
	});
	
	// Register command to open license manager
	const licenseManager = new LicenseManager(treeViewProvider['protectionManager']);
	let openLicenseManagerCommand = vscode.commands.registerCommand('cppPrimerBuddy.openLicenseManager', () => {
		licenseManager.showLicensePanel();
	});
	
	// Register command to open WeChat contact
	const wechatIntegration = new WeChatIntegration(context);
	let openWeChatContactCommand = vscode.commands.registerCommand('cppPrimerBuddy.openWeChatContact', () => {
		wechatIntegration.showWeChatPanel();
	});
	
	// Register command to refresh the tree view (useful after adding a license)
	let refreshCommand = vscode.commands.registerCommand('cppPrimerBuddy.refresh', () => {
		treeViewProvider.refresh();
		vscode.window.showInformationMessage('C++ Primer Buddy content refreshed!');
	});
	
	// Register command to change working directory
	let changeWorkingDirectoryCommand = vscode.commands.registerCommand('cppPrimerBuddy.changeWorkingDirectory', () => {
		treeViewProvider.changeWorkingDirectory();
	});

	context.subscriptions.push(
		studyCommand, 
		checkSolutionCommand, 
		viewSolutionCommand, 
		showHintCommand,
		openLicenseManagerCommand,
		openWeChatContactCommand,
		refreshCommand,
		changeWorkingDirectoryCommand,
		treeView,
		licenseManager,
		wechatIntegration
	);
}

export function deactivate() {
    // Cleanup code when extension is deactivated
    console.log('C++ Primer Buddy extension is now deactivated!');
}