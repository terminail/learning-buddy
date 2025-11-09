理解了！您需要多个AI联系人，每个AI都有独立的聊天页面。我将修改设计，让AI联系人和朋友联系人在同一列表中，每个都有独立的聊天记录。

## 更新后的 package.json 配置

```json
{
  "contributes": {
    "views": {
      "learning-buddy": [
        {
          "id": "learning-buddy.chat",
          "name": "Learning Buddy",
          "icon": "$(comment-discussion)"
        }
      ]
    },
    "viewsContainers": {
      "activitybar": [
        {
          "id": "learning-buddy",
          "title": "Learning Buddy",
          "icon": "$(heart)"
        }
      ]
    },
    "commands": [
      {
        "command": "learning-buddy.addAI",
        "title": "Add New AI",
        "icon": "$(add)"
      }
    ]
  }
}
```

## 统一聊天界面 HTML 实现（支持多个AI）

```html
<!DOCTYPE html>
<html>
<head>
    <style>
        .chat-container {
            display: flex;
            height: 100vh;
            font-family: var(--vscode-font-family);
            background: var(--vscode-editor-background);
            color: var(--vscode-editor-foreground);
        }
        
        /* 联系人列表 */
        .contacts-panel {
            width: 200px;
            border-right: 1px solid var(--vscode-panel-border);
            display: flex;
            flex-direction: column;
            background: var(--vscode-sideBar-background);
        }
        
        .contacts-header {
            padding: 10px;
            border-bottom: 1px solid var(--vscode-panel-border);
            font-weight: bold;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        
        .contact-list {
            flex: 1;
            overflow-y: auto;
        }
        
        .contact-item {
            padding: 10px;
            cursor: pointer;
            border-bottom: 1px solid var(--vscode-panel-border);
            display: flex;
            align-items: center;
        }
        
        .contact-item:hover {
            background: var(--vscode-list-hoverBackground);
        }
        
        .contact-item.active {
            background: var(--vscode-list-activeSelectionBackground);
            color: var(--vscode-list-activeSelectionForeground);
        }
        
        .contact-avatar {
            width: 32px;
            height: 32px;
            border-radius: 50%;
            margin-right: 10px;
            display: flex;
            align-items: center;
            justify-content: center;
            font-weight: bold;
            font-size: 0.8em;
        }
        
        .ai-avatar {
            background: var(--vscode-charts-blue);
        }
        
        .friend-avatar {
            background: var(--vscode-charts-green);
        }
        
        .contact-info {
            flex: 1;
        }
        
        .contact-name {
            font-weight: bold;
        }
        
        .contact-type {
            font-size: 0.7em;
            opacity: 0.7;
        }
        
        /* 聊天区域 */
        .chat-area {
            flex: 1;
            display: flex;
            flex-direction: column;
        }
        
        .chat-header {
            padding: 10px;
            border-bottom: 1px solid var(--vscode-panel-border);
            font-weight: bold;
            display: flex;
            align-items: center;
            justify-content: space-between;
        }
        
        .contact-description {
            font-size: 0.8em;
            opacity: 0.8;
            font-weight: normal;
        }
        
        .chat-messages {
            flex: 1;
            overflow-y: auto;
            padding: 10px;
            display: flex;
            flex-direction: column;
        }
        
        .message {
            margin: 8px 0;
            padding: 8px 12px;
            border-radius: 8px;
            max-width: 70%;
            word-wrap: break-word;
            position: relative;
        }
        
        .friend-message {
            background: var(--vscode-inputValidation-infoBackground);
            align-self: flex-start;
            border-bottom-left-radius: 2px;
        }
        
        .ai-message {
            background: var(--vscode-inputValidation-infoBackground);
            align-self: flex-start;
            border-bottom-left-radius: 2px;
            border-left: 3px solid var(--vscode-charts-blue);
        }
        
        .self-message {
            background: var(--vscode-inputValidation-warningBackground);
            align-self: flex-end;
            border-bottom-right-radius: 2px;
        }
        
        .message-sender {
            font-size: 0.8em;
            font-weight: bold;
            margin-bottom: 4px;
            display: flex;
            align-items: center;
        }
        
        .sender-avatar {
            width: 16px;
            height: 16px;
            border-radius: 50%;
            margin-right: 6px;
            font-size: 0.7em;
            display: flex;
            align-items: center;
            justify-content: center;
        }
        
        .message-time {
            font-size: 0.7em;
            opacity: 0.7;
            margin-top: 4px;
            text-align: right;
        }
        
        .input-container {
            padding: 10px;
            border-top: 1px solid var(--vscode-panel-border);
            display: flex;
        }
        
        .message-input {
            flex: 1;
            padding: 8px;
            background: var(--vscode-input-background);
            color: var(--vscode-input-foreground);
            border: 1px solid var(--vscode-input-border);
            border-radius: 3px;
        }
        
        .send-button {
            margin-left: 8px;
            padding: 8px 16px;
            background: var(--vscode-button-background);
            color: var(--vscode-button-foreground);
            border: none;
            border-radius: 3px;
            cursor: pointer;
        }
        
        .add-contact-btn {
            background: none;
            border: none;
            color: var(--vscode-button-foreground);
            cursor: pointer;
            padding: 4px;
        }
        
        .typing-indicator {
            font-style: italic;
            color: var(--vscode-descriptionForeground);
            padding: 5px 10px;
        }
    </style>
</head>
<body>
    <div class="chat-container">
        <!-- 联系人面板 -->
        <div class="contacts-panel">
            <div class="contacts-header">
                <span>Contacts</span>
                <button class="add-contact-btn" title="Add New AI" onclick="addNewAI()">$(add)</button>
            </div>
            <div class="contact-list" id="contact-list">
                <!-- 联系人将通过JavaScript动态生成 -->
            </div>
        </div>
        
        <!-- 聊天区域 -->
        <div class="chat-area">
            <div class="chat-header">
                <div>
                    <span id="current-contact-name">Select a contact</span>
                    <div class="contact-description" id="current-contact-desc"></div>
                </div>
            </div>
            
            <div class="chat-messages" id="chat-messages">
                <div style="text-align: center; padding: 20px; color: var(--vscode-descriptionForeground);">
                    Select a contact to start chatting
                </div>
            </div>
            
            <div class="input-container" id="input-container" style="display: none;">
                <input type="text" class="message-input" id="message-input" 
                       placeholder="Type your message...">
                <button class="send-button" onclick="sendMessage()">Send</button>
            </div>
        </div>
    </div>

    <script>
        // 联系人数据
        const contacts = [
            // AI 联系人
            {
                id: 'cpp-tutor',
                name: 'C++ Tutor',
                type: 'ai',
                description: 'Specialized in C++ programming and Primer exercises',
                avatar: 'C++',
                avatarColor: 'var(--vscode-charts-blue)',
                personality: 'educational'
            },
            {
                id: 'code-reviewer',
                name: 'Code Reviewer',
                type: 'ai', 
                description: 'Helps review and improve your code',
                avatar: 'CR',
                avatarColor: 'var(--vscode-charts-purple)',
                personality: 'critical'
            },
            {
                id: 'debug-helper',
                name: 'Debug Assistant',
                type: 'ai',
                description: 'Assists with debugging and problem solving',
                avatar: 'DH',
                avatarColor: 'var(--vscode-charts-orange)',
                personality: 'analytical'
            },
            // 朋友联系人
            {
                id: 'alice',
                name: 'Alice',
                type: 'friend',
                description: 'Classmate from CS101',
                avatar: 'A',
                avatarColor: 'var(--vscode-charts-green)',
                personality: 'friendly'
            },
            {
                id: 'bob',
                name: 'Bob',
                type: 'friend', 
                description: 'Study group partner',
                avatar: 'B',
                avatarColor: 'var(--vscode-charts-yellow)',
                personality: 'helpful'
            }
        ];

        // 聊天记录存储
        const chatHistories = {};
        let currentContact = null;

        // 初始化
        function initialize() {
            renderContactList();
            // 为每个联系人初始化空的聊天记录
            contacts.forEach(contact => {
                chatHistories[contact.id] = [];
            });
        }

        function renderContactList() {
            const contactList = document.getElementById('contact-list');
            contactList.innerHTML = '';

            // 渲染AI联系人
            const aiContacts = contacts.filter(c => c.type === 'ai');
            if (aiContacts.length > 0) {
                const aiHeader = document.createElement('div');
                aiHeader.style.padding = '10px 10px 5px 10px';
                aiHeader.style.fontSize = '0.8em';
                aiHeader.style.opacity = '0.7';
                aiHeader.textContent = 'AI Assistants';
                contactList.appendChild(aiHeader);
                
                aiContacts.forEach(contact => {
                    contactList.appendChild(createContactElement(contact));
                });
            }

            // 渲染朋友联系人
            const friendContacts = contacts.filter(c => c.type === 'friend');
            if (friendContacts.length > 0) {
                const friendHeader = document.createElement('div');
                friendHeader.style.padding = '10px 10px 5px 10px';
                friendHeader.style.fontSize = '0.8em';
                friendHeader.style.opacity = '0.7';
                friendHeader.textContent = 'Friends';
                contactList.appendChild(friendHeader);
                
                friendContacts.forEach(contact => {
                    contactList.appendChild(createContactElement(contact));
                });
            }
        }

        function createContactElement(contact) {
            const contactElement = document.createElement('div');
            contactElement.className = 'contact-item';
            contactElement.setAttribute('data-contact-id', contact.id);
            
            const avatarClass = contact.type === 'ai' ? 'ai-avatar' : 'friend-avatar';
            
            contactElement.innerHTML = `
                <div class="contact-avatar ${avatarClass}" style="background: ${contact.avatarColor}">${contact.avatar}</div>
                <div class="contact-info">
                    <div class="contact-name">${contact.name}</div>
                    <div class="contact-type">${contact.type === 'ai' ? 'AI Assistant' : 'Friend'}</div>
                </div>
            `;
            
            contactElement.addEventListener('click', () => switchContact(contact));
            return contactElement;
        }

        function switchContact(contact) {
            // 更新活跃联系人样式
            document.querySelectorAll('.contact-item').forEach(item => {
                item.classList.remove('active');
            });
            document.querySelector(`[data-contact-id="${contact.id}"]`).classList.add('active');
            
            // 更新当前联系人
            currentContact = contact;
            
            // 更新聊天头
            document.getElementById('current-contact-name').textContent = contact.name;
            document.getElementById('current-contact-desc').textContent = contact.description;
            
            // 显示输入框
            document.getElementById('input-container').style.display = 'flex';
            
            // 加载聊天记录
            loadChatHistory(contact.id);
        }

        function loadChatHistory(contactId) {
            const container = document.getElementById('chat-messages');
            container.innerHTML = '';
            
            const history = chatHistories[contactId] || [];
            
            if (history.length === 0) {
                // 显示欢迎消息
                const welcomeMsg = createWelcomeMessage(contactId);
                container.appendChild(welcomeMsg);
            } else {
                // 显示历史消息
                history.forEach(msg => {
                    container.appendChild(createMessageElement(msg));
                });
            }
            
            container.scrollTop = container.scrollHeight;
        }

        function createWelcomeMessage(contactId) {
            const welcomeDiv = document.createElement('div');
            welcomeDiv.style.textAlign = 'center';
            welcomeDiv.style.padding = '20px';
            welcomeDiv.style.color = 'var(--vscode-descriptionForeground)';
            
            const contact = contacts.find(c => c.id === contactId);
            let welcomeText = '';
            
            if (contact.type === 'ai') {
                welcomeText = `Start a conversation with ${contact.name}! This AI specializes in ${contact.description.toLowerCase()}.`;
            } else {
                welcomeText = `This is the beginning of your conversation with ${contact.name}.`;
            }
            
            welcomeDiv.textContent = welcomeText;
            return welcomeDiv;
        }

        function sendMessage() {
            if (!currentContact) return;
            
            const input = document.getElementById('message-input');
            const message = input.value.trim();
            
            if (message) {
                // 创建消息对象
                const messageObj = {
                    type: 'self',
                    content: message,
                    timestamp: new Date(),
                    contactId: currentContact.id
                };
                
                // 添加到聊天记录
                chatHistories[currentContact.id].push(messageObj);
                
                // 显示消息
                const container = document.getElementById('chat-messages');
                container.appendChild(createMessageElement(messageObj));
                
                // 清空输入框
                input.value = '';
                container.scrollTop = container.scrollHeight;
                
                // 生成回复
                generateReply(message);
            }
        }

        function generateReply(userMessage) {
            if (!currentContact) return;
            
            // 显示输入中指示器
            const container = document.getElementById('chat-messages');
            const typingIndicator = document.createElement('div');
            typingIndicator.className = 'typing-indicator';
            typingIndicator.textContent = `${currentContact.name} is typing...`;
            typingIndicator.id = 'typing-indicator';
            container.appendChild(typingIndicator);
            container.scrollTop = container.scrollHeight;
            
            // 模拟回复延迟
            setTimeout(() => {
                // 移除输入中指示器
                const indicator = document.getElementById('typing-indicator');
                if (indicator) indicator.remove();
                
                let replyContent = '';
                
                if (currentContact.type === 'ai') {
                    replyContent = generateAIResponse(userMessage, currentContact);
                } else {
                    replyContent = generateFriendResponse(userMessage, currentContact);
                }
                
                // 创建回复消息对象
                const replyObj = {
                    type: currentContact.type,
                    content: replyContent,
                    timestamp: new Date(),
                    contactId: currentContact.id,
                    senderName: currentContact.name,
                    avatar: currentContact.avatar,
                    avatarColor: currentContact.avatarColor
                };
                
                // 添加到聊天记录
                chatHistories[currentContact.id].push(replyObj);
                
                // 显示回复
                container.appendChild(createMessageElement(replyObj));
                container.scrollTop = container.scrollHeight;
                
            }, currentContact.type === 'ai' ? 1000 : 2000);
        }

        function generateAIResponse(userMessage, aiContact) {
            // 根据不同AI的性格生成回复
            const responses = {
                'educational': [
                    `I understand you're asking about "${userMessage}". Let me explain this concept step by step.`,
                    `That's a great question about "${userMessage}"! Here's how it works in C++...`,
                    `I can help you understand "${userMessage}". The key points are...`,
                    `Regarding "${userMessage}", this is an important concept. Let me break it down for you.`,
                    `I'd be happy to explain "${userMessage}". Here's a detailed explanation...`
                ],
                'critical': [
                    `Looking at your question about "${userMessage}", I notice some areas for improvement.`,
                    `Your understanding of "${userMessage}" could be enhanced by considering...`,
                    `Let me review your approach to "${userMessage}". Here are some suggestions...`,
                    `For "${userMessage}", here's a more efficient way to think about it...`,
                    `I can help optimize your approach to "${userMessage}". Consider this...`
                ],
                'analytical': [
                    `Let me analyze "${userMessage}" systematically. The main components are...`,
                    `For "${userMessage}", we need to consider these factors...`,
                    `I'll help you debug "${userMessage}". Let's examine this step by step.`,
                    `Analyzing "${userMessage}" reveals these key insights...`,
                    `Let's break down "${userMessage}" into smaller, manageable parts...`
                ]
            };
            
            const personalityResponses = responses[aiContact.personality] || responses['educational'];
            return personalityResponses[Math.floor(Math.random() * personalityResponses.length)];
        }

        function generateFriendResponse(userMessage, friendContact) {
            // 模拟朋友回复
            const responses = {
                'friendly': [
                    `That's interesting! I was also learning about "${userMessage}" recently.`,
                    `Hey, about "${userMessage}" - I found this really helpful resource!`,
                    `I remember struggling with "${userMessage}" too. Want to study together?`,
                    `That's a good question about "${userMessage}". Let me share what I know!`
                ],
                'helpful': [
                    `I can help with "${userMessage}"! Here's what worked for me...`,
                    `For "${userMessage}", I found this approach really effective...`,
                    `Let me explain "${userMessage}" in a different way that might help...`,
                    `I've got some good notes on "${userMessage}". Want me to share them?`
                ]
            };
            
            const personalityResponses = responses[friendContact.personality] || responses['friendly'];
            return personalityResponses[Math.floor(Math.random() * personalityResponses.length)];
        }

        function createMessageElement(messageObj) {
            const messageDiv = document.createElement('div');
            
            let messageClass = '';
            let senderName = 'You';
            let avatarText = 'Y';
            let avatarColor = 'var(--vscode-button-background)';
            
            if (messageObj.type === 'self') {
                messageClass = 'self-message';
            } else if (messageObj.type === 'ai') {
                messageClass = 'ai-message';
                senderName = messageObj.senderName;
                avatarText = messageObj.avatar;
                avatarColor = messageObj.avatarColor;
            } else if (messageObj.type === 'friend') {
                messageClass = 'friend-message';
                senderName = messageObj.senderName;
                avatarText = messageObj.avatar;
                avatarColor = messageObj.avatarColor;
            }
            
            messageDiv.className = `message ${messageClass}`;
            messageDiv.innerHTML = `
                <div class="message-sender">
                    <div class="sender-avatar" style="background: ${avatarColor}">${avatarText}</div>
                    ${senderName}
                </div>
                <div class="message-content">${messageObj.content}</div>
                <div class="message-time">${messageObj.timestamp.toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}</div>
            `;
            
            return messageDiv;
        }

        function addNewAI() {
            // 在实际实现中，这会打开一个对话框来配置新的AI
            const newAI = {
                id: 'ai-' + Date.now(),
                name: 'New AI Assistant',
                type: 'ai',
                description: 'Custom AI assistant',
                avatar: 'AI',
                avatarColor: 'var(--vscode-charts-blue)',
                personality: 'educational'
            };
            
            contacts.push(newAI);
            chatHistories[newAI.id] = [];
            renderContactList();
            
            // 通知VS Code扩展
            if (typeof vscode !== 'undefined') {
                vscode.postMessage({
                    type: 'addAI',
                    aiConfig: newAI
                });
            }
        }

        // 处理Enter键发送
        document.getElementById('message-input').addEventListener('keypress', function(e) {
            if (e.key === 'Enter') {
                sendMessage();
            }
        });

        // 初始化应用
        initialize();
    </script>
</body>
</html>
```

## TypeScript 视图提供程序

```typescript
import * as vscode from 'vscode';

export class UnifiedChatViewProvider implements vscode.WebviewViewProvider {
    public static readonly viewType = 'learning-buddy.chat';
    
    private _view?: vscode.WebviewView;

    constructor(private readonly _extensionUri: vscode.Uri) {}

    public resolveWebviewView(
        webviewView: vscode.WebviewView,
        context: vscode.WebviewViewResolveContext,
        _token: vscode.CancellationToken,
    ) {
        this._view = webviewView;

        webviewView.webview.options = {
            enableScripts: true,
            localResourceRoots: [this._extensionUri]
        };

        webviewView.webview.html = this._getHtmlForWebview(webviewView.webview);
        
        // 处理来自webview的消息
        webviewView.webview.onDidReceiveMessage(data => {
            switch (data.type) {
                case 'sendMessage':
                    this._handleMessage(data.message, data.contactId);
                    break;
                case 'addAI':
                    this._handleAddAI(data.aiConfig);
                    break;
            }
        });
    }

    private _getHtmlForWebview(webview: vscode.Webview): string {
        // 返回上面的HTML内容
        // 在实际实现中，需要将上面的HTML代码嵌入到这里
        return `...`;
    }

    private _handleMessage(message: string, contactId: string) {
        // 处理发送的消息
        // 这里可以集成真实的AI服务
        console.log(`Message to ${contactId}: ${message}`);
    }

    private _handleAddAI(aiConfig: any) {
        // 处理添加新AI的请求
        vscode.window.showInformationMessage(`Adding new AI: ${aiConfig.name}`);
    }
}
```

## 扩展激活

```typescript
export function activate(context: vscode.ExtensionContext) {
    // 注册统一的聊天视图
    const chatProvider = new UnifiedChatViewProvider(context.extensionUri);
    context.subscriptions.push(
        vscode.window.registerWebviewViewProvider(
            UnifiedChatViewProvider.viewType, 
            chatProvider
        )
    );

    // 注册添加AI的命令
    const addAICmd = vscode.commands.registerCommand('learning-buddy.addAI', () => {
        vscode.window.showInputBox({
            prompt: 'Enter name for new AI assistant',
            placeHolder: 'AI Assistant Name'
        }).then(name => {
            if (name) {
                // 这里可以触发webview添加新AI
            }
        });
    });
    context.subscriptions.push(addAICmd);
}
```

这个设计现在支持：

- ✅ **多个AI联系人**：每个AI都有独立的聊天记录和个性
- ✅ **多个朋友联系人**：与真实朋友的聊天
- ✅ **统一界面**：所有联系人在同一个侧边栏中
- ✅ **独立聊天历史**：每个联系人有完全独立的对话记录
- ✅ **个性回复**：不同AI根据其专业领域生成不同的回复
- ✅ **添加新AI**：支持动态添加新的AI助手

您可以根据需要添加更多AI类型（如Python导师、算法专家等），每个都会有自己独立的聊天上下文和回复风格。