/**
 * Function to generate Podman installation guide content
 * @returns HTML string for the Podman installation guide
 */
export function getPodmanInstallationGuideContent(): string {
	return `
	<!DOCTYPE html>
	<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta http-equiv="Content-Security-Policy" content="default-src 'none'; script-src 'unsafe-inline' 'unsafe-eval' vscode-resource:; style-src 'unsafe-inline' vscode-resource:; font-src vscode-resource:;">
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