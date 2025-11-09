# Coding Standard Checklist

This checklist is based on the hybrid HTML template approach described in html_template.md for VS Code extension development.

## Project Structure

- [ ] Follow the recommended project structure:
  ```
  learning-buddy/
  ├── src/
  │   ├── extension.ts          # Main extension entry point
  │   ├── providers/
  │   │   └── ChatViewProvider.ts
  │   └── templates/           # Template modules
  │       ├── index.ts         # Main template loader
  │       ├── base.ts          # Base HTML structure
  │       └── components.ts    # Reusable UI components
  ├── media/                   # Static assets
  │   ├── chat-template.html   # Main HTML template
  │   └── styles/
  │       └── chat.css
  └── package.json
  ```

## Template Engine Implementation

- [ ] Create a singleton TemplateEngine class
- [ ] Implement `renderMainTemplate()` method that:
  - [ ] Reads external HTML template files
  - [ ] Replaces placeholders with dynamic content
  - [ ] Uses `vscode.workspace.fs.readFile()` for file reading
  - [ ] Properly handles webview resource URIs with `webview.asWebviewUri()`
- [ ] Create reusable component functions for UI elements
- [ ] Use template literals for dynamic components in code

## HTML Template Structure

- [ ] Keep main HTML structure in external `.html` files in the `media/` directory
- [ ] Use placeholder syntax `{{variable_name}}` for dynamic content
- [ ] Separate static structure from dynamic content
- [ ] Include proper meta tags:
  ```html
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  ```

## Component Templates

- [ ] Create separate component functions for reusable UI elements
- [ ] Use template literals for component generation
- [ ] Pass data as parameters to component functions
- [ ] Return HTML strings from component functions
- [ ] Example components:
  - [ ] Contact lists
  - [ ] Message bubbles
  - [ ] Input areas
  - [ ] Welcome messages

## Webview Provider Implementation

- [ ] Implement `resolveWebviewView()` method properly
- [ ] Set webview options:
  ```typescript
  webviewView.webview.options = {
      enableScripts: true,
      localResourceRoots: [
          vscode.Uri.joinPath(this._extensionUri, 'media')
      ]
  };
  ```
- [ ] Use the template engine to generate HTML content
- [ ] Set up message handling with `webview.onDidReceiveMessage()`
- [ ] Implement data fetching methods for dynamic content

## Placeholder Replacement

- [ ] Use consistent placeholder syntax `{{variable_name}}`
- [ ] Replace placeholders with actual values before rendering
- [ ] Handle missing data gracefully
- [ ] Escape HTML content when necessary

## JavaScript Implementation

- [ ] Keep core application logic in external JavaScript
- [ ] Use event delegation for dynamic elements
- [ ] Implement proper error handling
- [ ] Add console logging for debugging
- [ ] Use proper DOM ready checks:
  ```javascript
  if (document.readyState === 'loading') {
      document.addEventListener('DOMContentLoaded', initializeComponents);
  } else {
      setTimeout(initializeComponents, 100);
  }
  ```

## CSS Styling

- [ ] Keep CSS in separate files in the `media/styles/` directory
- [ ] Link CSS files properly in HTML templates
- [ ] Use VS Code CSS variables for consistency:
  ```css
  --vscode-editor-background
  --vscode-editor-foreground
  --vscode-button-background
  ```

## Performance Considerations

- [ ] Minimize DOM manipulation
- [ ] Cache template files when possible
- [ ] Use efficient placeholder replacement
- [ ] Avoid unnecessary re-renders

## Type Safety

- [ ] Use TypeScript interfaces for data structures
- [ ] Define proper types for template data
- [ ] Use type checking for component parameters
- [ ] Implement proper error handling for missing data

## Maintainability

- [ ] Keep static HTML in files, dynamic components in code
- [ ] Use clear, descriptive names for components
- [ ] Document complex template logic
- [ ] Separate concerns between structure, style, and behavior