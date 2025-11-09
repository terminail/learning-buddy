module.exports = {
    window: {
        showErrorMessage: jest.fn(),
        showInformationMessage: jest.fn(),
        createTreeView: jest.fn(),
        createWebviewPanel: jest.fn(() => ({
            webview: {
                html: ''
            }
        }))
    },
    ExtensionContext: jest.fn(),
    TreeItem: class TreeItem {
        constructor(label, collapsibleState) {
            this.label = label;
            this.collapsibleState = collapsibleState;
        }
    },
    TreeItemCollapsibleState: {
        None: 0,
        Collapsed: 1,
        Expanded: 2
    },
    ThemeIcon: class ThemeIcon {
        constructor(iconName) {
            this.iconName = iconName;
        }
    },
    Event: jest.fn(),
    EventEmitter: class EventEmitter {
        constructor() {
            this.event = jest.fn();
        }
        fire() {}
    }
};