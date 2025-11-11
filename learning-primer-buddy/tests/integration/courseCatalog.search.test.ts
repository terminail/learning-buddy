import * as vscode from 'vscode';
import { CourseContentProviderClient } from '../../src/courseContentProviderClient';

/**
 * Integration Test: Course Catalog Search Functionality
 * 
 * This test verifies that the course catalog search functionality works correctly
 * with different search scenarios.
 */

describe('Course Catalog Search', () => {
    let client: CourseContentProviderClient;
    
    beforeAll(() => {
        // Initialize the client with a mock context
        const mockContext = {
            globalState: {
                get: jest.fn(),
                update: jest.fn()
            }
        } as unknown as vscode.ExtensionContext;
        
        client = new CourseContentProviderClient(mockContext);
    });
    
    it('should handle empty search term', async () => {
        // This test verifies that an empty search returns all courses
        // Perform empty search
        const result = await client.searchCourses('');
        
        // Should return all courses from the default catalog (10 courses)
        expect(result.courses).toHaveLength(10);
        expect(result.courses[0].id).toBe('cpp-primer-5th');
    });

    it('should handle search with results', async () => {
        // This test verifies that searching for a term returns matching courses
        // Perform search for "Python"
        const result = await client.searchCourses('Python');
        
        // Should return matching courses
        expect(result.courses.length).toBeGreaterThan(0);
        expect(result.courses[0].title).toContain('Python');
    });

    it('should handle search with no results', async () => {
        // This test verifies that searching for a term with no matches returns empty array
        // Perform search for a term that won't match anything
        const result = await client.searchCourses('NonExistentCourse');
        
        // Should return empty array
        expect(result.courses).toHaveLength(0);
    });

    it('should handle special characters in search term', async () => {
        // This test verifies that searching with special characters works correctly
        // Perform search with special characters
        const result = await client.searchCourses('C++');
        
        // Should handle special characters correctly
        expect(result.courses.length).toBeGreaterThan(0);
        expect(result.courses[0].title).toContain('C++');
    });

    it('should handle case insensitive search', async () => {
        // This test verifies that search is case insensitive
        // Perform searches with different cases for "JavaScript"
        const result1 = await client.searchCourses('javascript');
        const result2 = await client.searchCourses('JAVASCRIPT');
        const result3 = await client.searchCourses('JavaScript');
        
        // All should return the same result
        expect(result1.courses.length).toBeGreaterThan(0);
        expect(result1.courses.length).toBe(result2.courses.length);
        expect(result2.courses.length).toBe(result3.courses.length);
    });
});