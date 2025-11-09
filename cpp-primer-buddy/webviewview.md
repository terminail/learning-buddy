Great! I'll help you add a resizable splitter between the contact list and chat area, and fix the issue where the chat doesn't show when clicking AI items.

## Updated HTML with Resizable Splitter

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
            width: 250px;
            min-width: 150px;
            max-width: 400px;
            border-right: 1px solid var(--vscode-panel-border);
            display: flex;
            flex-direction: column;
            background: var(--vscode-sideBar-background);
            resize: horizontal;
            overflow: hidden;
        }
        
        /* 可调整大小的分割线 */
        .resizer {
            width: 4px;
            background: var(--vscode-panel-border);
            cursor: col-resize;
            transition: background-color 0.2s;
        }
        
        .resizer:hover {
            background: var(--vscode-focusBorder);
        }
        
        .resizer.dragging {
            background: var(--vscode-button-background);
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
            min-width: 300px;
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
            display: none; /* Initially hidden */
            flex-direction: column;
        }
        
        .message-input {
            flex: 1;
            padding: 8px;
            background: var(--vscode-input-background);
            color: var(--vscode-input-foreground);
            border: 1px solid var(--vscode-input-border);
            border-radius: 3px;
            margin-bottom: 8px;
        }
        
        .send-button {
            padding: 8px 16px;
            background: var(--vscode-button-background);
            color: var(--vscode-button-foreground);
            border: none;
            border-radius: 3px;
            cursor: pointer;
            align-self: flex-end;
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
        
        .welcome-message {
            text-align: center;
            padding: 40px 20px;
            color: var(--vscode-descriptionForeground);
        }
        
        .no-contact-selected {
            display: flex;
            align-items: center;
            justify-content: center;
            height: 100%;
            color: var(--vscode-descriptionForeground);
            font-style: italic;
        }
    </style>
</head>
<body>
    <div class="chat-container">
        <!-- 联系人面板 -->
        <div class="contacts-panel" id="contacts-panel">
            <div class="contacts-header">
                <span>Contacts</span>
                <button class="add-contact-btn" title="Add New AI" onclick="addNewAI()">$(add)</button>
            </div>
            <div class="contact-list" id="contact-list">
                <!-- 联系人将通过JavaScript动态生成 -->
            </div>
        </div>
        
        <!-- 可调整大小的分割线 -->
        <div class="resizer" id="resizer"></div>
        
        <!-- 聊天区域 -->
        <div class="chat-area">
            <div class="chat-header">
                <div>
                    <span id="current-contact-name">Select a contact</span>
                    <div class="contact-description" id="current-contact-desc"></div>
                </div>
            </div>
            
            <div class="chat-messages" id="chat-messages">
                <div class="no-contact-selected" id="no-contact-selected">
                    Please select a contact to start chatting
                </div>
                <!-- 消息将动态插入到这里 -->
            </div>
            
            <div class="input-container" id="input-container">
                <textarea class="message-input" id="message-input" 
                          placeholder="Type your message..." rows="3"></textarea>
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
            setupResizer();
            // 为每个联系人初始化空的聊天记录
            contacts.forEach(contact => {
                chatHistories[contact.id] = [];
            });
        }

        function setupResizer() {
            const resizer = document.getElementById('resizer');
            const contactsPanel = document.getElementById('contacts-panel');
            let isResizing = false;

            resizer.addEventListener('mousedown', function(e) {
                isResizing = true;
                resizer.classList.add('dragging');
                document.body.style.cursor = 'col-resize';
                document.body.style.userSelect = 'none';
            });

            document.addEventListener('mousemove', function(e) {
                if (!isResizing) return;
                
                const newWidth = e.clientX - contactsPanel.getBoundingClientRect().left;
                if (newWidth > 150 && newWidth < 400) {
                    contactsPanel.style.width = newWidth + 'px';
                }
            });

            document.addEventListener('mouseup', function() {
                if (isResizing) {
                    isResizing = false;
                    resizer.classList.remove('dragging');
                    document.body.style.cursor = '';
                    document.body.style.userSelect = '';
                }
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
            
            // 隐藏"未选择联系人"消息
            document.getElementById('no-contact-selected').style.display = 'none';
            
            // 加载聊天记录
            loadChatHistory(contact.id);
        }

        function loadChatHistory(contactId) {
            const container = document.getElementById('chat-messages');
            
            // 清空当前消息（除了当前联系人的消息）
            const allMessages = container.querySelectorAll('.message');
            allMessages.forEach(msg => {
                if (msg.getAttribute('data-contact') !== contactId) {
                    msg.style.display = 'none';
                } else {
                    msg.style.display = 'flex';
                }
            });
            
            // 检查是否有可见消息
            const visibleMessages = container.querySelectorAll(`.message[data-contact="${contactId}"]`);
            if (visibleMessages.length === 0) {
                // 显示欢迎消息
                showWelcomeMessage(contactId);
            }
            
            container.scrollTop = container.scrollHeight;
        }

        function showWelcomeMessage(contactId) {
            const container = document.getElementById('chat-messages');
            const contact = contacts.find(c => c.id === contactId);
            
            // 移除可能存在的欢迎消息
            const existingWelcome = container.querySelector('.welcome-message');
            if (existingWelcome) {
                existingWelcome.remove();
            }
            
            const welcomeDiv = document.createElement('div');
            welcomeDiv.className = 'welcome-message';
            welcomeDiv.setAttribute('data-contact', contactId);
            
            let welcomeText = '';
            if (contact.type === 'ai') {
                welcomeText = `Start a conversation with ${contact.name}! This AI specializes in ${contact.description.toLowerCase()}`;
            } else {
                welcomeText = `This is the beginning of your conversation with ${contact.name}.`;
            }
            
            welcomeDiv.textContent = welcomeText;
            container.appendChild(welcomeDiv);
        }

        function sendMessage() {
            if (!currentContact) return;
            
            const input = document.getElementById('message-input');
            const message = input.value.trim();
            
            if (message) {
                // 移除欢迎消息
                const welcomeMsg = document.querySelector(`.welcome-message[data-contact="${currentContact.id}"]`);
                if (welcomeMsg) {
                    welcomeMsg.remove();
                }
                
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
            messageDiv.setAttribute('data-contact', messageObj.contactId);
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

        // 处理Enter键发送（但不包括Shift+Enter）
        document.getElementById('message-input').addEventListener('keydown', function(e) {
            if (e.key === 'Enter' && !e.shiftKey) {
                e.preventDefault();
                sendMessage();
            }
        });

        // 初始化应用
        initialize();
    </script>
</body>
</html>
```

## Key Changes Made:

### 1. **Added Resizable Splitter**
- Created a `.resizer` element between the contacts panel and chat area
- Added JavaScript drag handling with `mousedown`, `mousemove`, and `mouseup` events
- Set minimum (150px) and maximum (400px) width constraints
- Visual feedback during dragging with color changes

### 2. **Fixed Chat Display Issues**
- Changed input container to be hidden by default: `display: none`
- Added proper display logic in `switchContact()` function
- Created a "no contact selected" message that shows initially
- Fixed the welcome message display for new contacts
- Improved message filtering to properly show/hide messages based on selected contact

### 3. **Improved User Experience**
- Changed message input to a `<textarea>` for multi-line input
- Added `Shift+Enter` for new lines, `Enter` alone sends the message
- Better visual separation between contacts and chat area
- Improved scrolling behavior

### 4. **Enhanced Styling**
- Added proper constraints for panel sizes
- Better visual feedback for the resizer
- Improved message display with consistent spacing

Now when you click on any AI or friend contact:
1. The contact will be highlighted in the left panel
2. The chat header will update with the contact's name and description
3. The input area will become visible
4. The chat history for that contact will load (or a welcome message will show for new conversations)
5. You can resize the contact panel by dragging the resizer bar

The chat should now work properly for all AI contacts!