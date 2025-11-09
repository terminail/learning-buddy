好的，我来帮您将视图名称从 "AI Chat" 改为 "Learning Buddy"。以下是更新后的 `package.json` 配置部分：

## 更新后的 package.json 配置

```json
{
  "contributes": {
    "viewsContainers": {
      "panel": [
        {
          "id": "learning-buddy-panel",
          "title": "Learning Buddy",
          "icon": "$(heart)"
        }
      ]
    },
    "views": {
      "learning-buddy-panel": [
        {
          "id": "learning-buddy.chat",
          "name": "Learning Buddy",  // 从 "AI Chat" 改为 "Learning Buddy"
          "type": "webview"
        }
      ]
    }
  }
}
```

## 完整的 package.json 示例

```json
{
  "name": "learning-buddy",
  "displayName": "Learning Buddy",
  "description": "AI-powered programming learning companion for beginners",
  "version": "1.0.0",
  "engines": {
    "vscode": "^1.74.0"
  },
  "categories": [
    "Education",
    "Other"
  ],
  "activationEvents": [
    "onView:learning-buddy.chat"
  ],
  "main": "./out/extension.js",
  "contributes": {
    "viewsContainers": {
      "panel": [
        {
          "id": "learning-buddy-panel",
          "title": "Learning Buddy",
          "icon": "$(heart)"
        }
      ]
    },
    "views": {
      "learning-buddy-panel": [
        {
          "id": "learning-buddy.chat",
          "name": "Learning Buddy",
          "type": "webview"
        }
      ]
    },
    "commands": [
      {
        "command": "learning-buddy.addAI",
        "title": "Add New AI",
        "icon": "$(add)"
      },
      {
        "command": "learning-buddy.focus",
        "title": "Focus Learning Buddy",
        "category": "Learning Buddy"
      }
    ],
    "menus": {
      "view/title": [
        {
          "command": "learning-buddy.addAI",
          "when": "view == learning-buddy.chat",
          "group": "navigation"
        }
      ]
    }
  }
}
```

## TypeScript 实现保持不变

您的 `WebviewViewProvider` 实现不需要改变，只需要确保注册时使用正确的视图ID：

```typescript
// 在 extension.ts 中
export function activate(context: vscode.ExtensionContext) {
    // 注册 Learning Buddy 视图提供程序
    const provider = new LearningBuddyViewProvider(context.extensionUri);
    context.subscriptions.push(
        vscode.window.registerWebviewViewProvider(
            'learning-buddy.chat', // 与 package.json 中的视图 ID 匹配
            provider
        )
    );

    // 可选：添加聚焦命令
    const focusCommand = vscode.commands.registerCommand('learning-buddy.focus', () => {
        // 这个命令可以让用户快速跳转到 Learning Buddy 面板
        vscode.commands.executeCommand('learning-buddy-panel.focus');
    });
    context.subscriptions.push(focusCommand);
}
```

## 效果说明

这个更改会让您的扩展在VS Code中显示为：

- **面板标题**：Learning Buddy（在底部面板区域）
- **视图名称**：Learning Buddy（在面板内部的标签页名称）

这样的命名更加一致，用户会清楚地知道这个面板就是您的 "Learning Buddy" 扩展的主要界面，而不是仅仅看到 "AI Chat" 这样功能性的名称。

如果您还需要调整其他部分的命名或者有任何其他修改需求，请告诉我！