# Feature Specification: Learning Buddy View

**Feature Branch**: `027-learning-buddy-view`  
**Created**: 2025-11-09  
**Status**: Draft  
**Input**: User description: "I want Buddy to add a Learning Buddy view next to DEBUG CONSOLE, PROBLEMS and other views. The view's left sidebar should mainly contain contacts such as groups, friends, and AI websites. When clicking on groups or friends, the interface that opens on the right should be a chat interface with two columns - friend information on the left and my information on the right. When clicking on AI websites, the AI website should open on the right. Currently, the contacts are mainly AI websites like DeepSeek, Doubao, Kimi, and ChatGPT. Please find these AI websites and add them to the contact list, which should be hardcoded for now."

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Add Learning Buddy View to VS Code (Priority: P1)

As a learner, I want to see a Learning Buddy view in VS Code alongside DEBUG CONSOLE and PROBLEMS views so that I can access AI assistance and learning resources without switching contexts.

**Why this priority**: This is the core functionality requested by the user to integrate learning resources directly into the VS Code interface.

**Independent Test**: Can be fully tested by opening VS Code and verifying that the Learning Buddy view appears in the panel area alongside other views.

**Acceptance Scenarios**:

1. **Given** the Learning Buddy extension is installed, **When** VS Code is opened, **Then** a "Learning Buddy" view should appear in the panel area.
2. **Given** the Learning Buddy view is visible, **When** I click on it, **Then** it should display a contact list with AI websites.
3. **Given** the Learning Buddy view is visible, **When** I resize the panel, **Then** the view should resize appropriately.

---

### User Story 2 - Display AI Website Contacts with Chinese AI Prioritized (Priority: P1)

As a learner, I want to see a list of AI website contacts in the Learning Buddy view with Chinese AI websites from major domestic companies prioritized, so that I can quickly access popular AI assistants for help with my studies.

**Why this priority**: This addresses the user's specific request to prioritize Chinese AI websites from companies like Tencent, Alibaba, and Baidu.

**Independent Test**: Can be fully tested by verifying that the contact list displays the specified AI websites with Chinese AI websites appearing first.

**Acceptance Scenarios**:

1. **Given** the Learning Buddy view is open, **When** it loads, **Then** it should display a list of AI website contacts with Chinese AI websites prioritized including Doubao, Yuanbao (Tencent), Qwen (Alibaba), ERNIE Bot (Baidu), DeepSeek, and Kimi.
2. **Given** the contact list is displayed, **When** I hover over a contact, **Then** it should show a tooltip with the website URL.
3. **Given** the contact list is displayed, **When** I click on a contact, **Then** it should open the AI website in the right panel.

---

### User Story 3 - Open AI Websites in Right Panel (Priority: P1)

As a learner, I want to click on AI website contacts and have them open in the right panel of the Learning Buddy view so that I can use AI assistance without leaving VS Code.

**Why this priority**: This is essential for the integrated experience the user requested.

**Independent Test**: Can be fully tested by clicking on AI contacts and verifying that websites open in the right panel.

**Acceptance Scenarios**:

1. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Doubao", **Then** doubao.com should open in the right panel.
2. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Yuanbao (Tencent)", **Then** yuanbao.tencent.com should open in the right panel.
3. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Qwen (Alibaba)", **Then** tongyi.aliyun.com should open in the right panel.
4. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "ERNIE Bot (Baidu)", **Then** yiyan.baidu.com should open in the right panel.
5. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "DeepSeek", **Then** chat.deepseek.com should open in the right panel.
6. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Kimi", **Then** kimi.com should open in the right panel.
7. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "ChatGPT", **Then** chatgpt.com should open in the right panel.
8. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Claude", **Then** claude.ai should open in the right panel.
9. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Gemini", **Then** gemini.google.com should open in the right panel.
10. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Microsoft Copilot", **Then** copilot.microsoft.com should open in the right panel.
11. **Given** the Learning Buddy view is open with AI contacts, **When** I click on "Perplexity AI", **Then** perplexity.ai should open in the right panel.

---

### User Story 4 - Future Chat Interface Support (Priority: P2)

As a learner, I want the Learning Buddy view to support future chat interfaces for groups and friends so that I can have more interactive learning experiences with left/right chat panels as described.

**Why this priority**: This is a planned enhancement for future development based on the user's requirements.

**Independent Test**: Can be tested by verifying that the architecture supports future chat interface development.

**Acceptance Scenarios**:

1. **Given** the Learning Buddy view architecture, **When** future chat features are implemented, **Then** it should support left/right chat panels as described in the requirements.
2. **Given** the Learning Buddy view architecture, **When** group contacts are added, **Then** they should display in the contact list.
3. **Given** the Learning Buddy view architecture, **When** friend contacts are added, **Then** they should display in the contact list.

---

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: System MUST add a "Learning Buddy" view to VS Code panel area alongside DEBUG CONSOLE and PROBLEMS
- **FR-002**: System MUST display a contact list in the left panel of the Learning Buddy view
- **FR-003**: System MUST prioritize Chinese AI websites from major domestic companies (Tencent, Alibaba, Baidu, ByteDance)
- **FR-004**: System MUST include Doubao (doubao.com) in the contact list (prioritized)
- **FR-005**: System MUST include Yuanbao from Tencent (yuanbao.tencent.com) in the contact list (prioritized)
- **FR-006**: System MUST include Qwen from Alibaba (tongyi.aliyun.com) in the contact list (prioritized)
- **FR-007**: System MUST include ERNIE Bot from Baidu (yiyan.baidu.com) in the contact list (prioritized)
- **FR-008**: System MUST include DeepSeek (chat.deepseek.com) in the contact list
- **FR-009**: System MUST include Kimi (kimi.com) in the contact list
- **FR-010**: System MUST include ChatGPT (chatgpt.com) in the contact list
- **FR-011**: System MUST include Claude (claude.ai) in the contact list
- **FR-012**: System MUST include Gemini (gemini.google.com) in the contact list
- **FR-013**: System MUST include Microsoft Copilot (copilot.microsoft.com) in the contact list
- **FR-014**: System MUST include Perplexity AI (perplexity.ai) in the contact list
- **FR-015**: System MUST open AI websites in the right panel when contacts are clicked
- **FR-016**: System SHOULD support future chat interface development with left/right panels for groups and friends
- **FR-017**: System MAY include additional AI websites in the contact list
- **FR-018**: System MUST maintain existing Learning Buddy functionality while adding the new view
- **FR-019**: System MUST use hardcoded contact list for initial implementation

### Key Entities

- **LearningBuddyView**: The new VS Code view that appears in the panel area
- **ContactList**: The left panel component displaying AI website contacts
- **WebViewPanel**: The right panel component displaying AI websites
- **AIContact**: Individual contact items representing AI websites
- **ChatInterface**: Future component for group/friend chat (left/right panels)

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: Learning Buddy view appears in VS Code panel area in 100% of cases
- **SC-002**: Contact list displays all specified AI websites in 100% of cases with Chinese AI websites prioritized
- **SC-003**: Clicking AI contacts opens websites in right panel in 100% of cases
- **SC-004**: Existing Learning Buddy functionality remains unaffected in 100% of cases
- **SC-005**: View properly resizes with panel adjustments in 100% of cases
- **SC-006**: Tooltips display correctly on contact hover in 100% of cases
- **SC-007**: Architecture supports future chat interface development in 100% of cases
- **SC-008**: Contact list uses hardcoded data in 100% of cases
- **SC-009**: Chinese AI websites from major domestic companies appear first in the contact list in 100% of cases