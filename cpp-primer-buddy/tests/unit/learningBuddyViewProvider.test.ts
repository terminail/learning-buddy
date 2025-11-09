import { LearningBuddyViewProvider } from '../../src/learningBuddy/learningBuddyViewProvider';

describe('LearningBuddyViewProvider', () => {
    test('should create provider instance', () => {
        // Create a mock extension URI for testing
        const mockExtensionUri = {
            path: '/mock/path',
            fsPath: '/mock/path'
        };
        
        const provider = new LearningBuddyViewProvider(mockExtensionUri as any);
        expect(provider).toBeInstanceOf(LearningBuddyViewProvider);
        expect(LearningBuddyViewProvider.viewType).toBe('learningBuddyView');
    });

    test('should generate contact list with Chinese AI prioritized', () => {
        // Create a mock extension URI for testing
        const mockExtensionUri = {
            path: '/mock/path',
            fsPath: '/mock/path'
        };
        
        const provider = new LearningBuddyViewProvider(mockExtensionUri as any);
        
        // Access the private method for testing
        const getContactListHtml = (provider as any)._getContactListHtml.bind(provider);
        const contactListHtml = getContactListHtml();
        
        // Check that the contact list contains expected AI websites
        expect(contactListHtml).toContain('Doubao');
        expect(contactListHtml).toContain('Yuanbao (Tencent)');
        expect(contactListHtml).toContain('Qwen (Alibaba)');
        expect(contactListHtml).toContain('ERNIE Bot (Baidu)');
        expect(contactListHtml).toContain('DeepSeek');
        expect(contactListHtml).toContain('Kimi');
        expect(contactListHtml).toContain('ChatGPT');
        expect(contactListHtml).toContain('Claude');
        expect(contactListHtml).toContain('Gemini');
        expect(contactListHtml).toContain('Microsoft Copilot');
        expect(contactListHtml).toContain('Perplexity AI');
    });
});