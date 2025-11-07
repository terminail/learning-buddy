# Template Update Process

This document explains how to update the exercise templates when feature specifications change.

## When to Update Templates

The exercise templates should be updated when:

1. **Feature specifications are modified** - Any changes to existing feature specifications
2. **New feature specifications are created** - When new chapters or concepts are added
3. **Industrial tools evolve** - When pytest, Jupyter, or other tools change
4. **Pedagogical approaches improve** - When better teaching methods are discovered
5. **Best practices change** - When coding standards or educational practices evolve

## Update Process

### 1. Review Changed Feature Specifications
- Read the entire updated feature specification
- Identify new requirements or changes to existing requirements
- Note any new learning objectives or concepts
- Highlight industrial tool requirements
- Identify assessment method changes

### 2. Identify Template Modifications
- Determine which template files need updates
- Map feature spec requirements to template elements
- Identify new sections or content needed
- Note any deprecated requirements

### 3. Update Template Files
- Modify README.md to include new learning objectives
- Update exercise.py with new TODO comments
- Enhance solution.py with new implementations
- Add new test cases to test_exercise.py
- Update Jupyter notebook with new content
- Modify run_tests.py if industrial tool usage changes

### 4. Test Updated Template
- Create a sample exercise using the updated template
- Verify all template elements work correctly
- Check that feature spec requirements are met
- Test industrial tool integration
- Validate assessment methods

### 5. Document Changes
- Update TEMPLATE_GUIDE.md with new requirements
- Add entry to version history
- Note any breaking changes
- Update related documentation

## Feature Specification Integration

### Flowchart Visualization Requirements
When feature specifications require flowchart visualizations:
- Add flowchart comments to exercise.py TODO sections
- Include flowchart explanations in solution.py
- Create visual flowchart representations in Jupyter notebooks
- Add tests for flowchart concept understanding

### Industrial Tool Requirements
When feature specifications emphasize industrial tools:
- Ensure pytest is the exclusive testing framework
- Integrate Jupyter notebook testing capabilities
- Follow current best practices for tool usage
- Update documentation to emphasize industrial tools

### Assessment Method Changes
When feature specifications change assessment methods:
- Update test_exercise.py with new test patterns
- Modify run_tests.py to support new assessment approaches
- Update README.md assessment sections
- Ensure Jupyter notebooks support new assessment methods

## Template File Specific Update Guidelines

### README.md Updates
- Add new learning objectives from feature specs
- Include feature-specific requirements
- Update instructions to match feature specs
- Add references to specific feature specification sections

### exercise.py Updates
- Create TODO comments for new concepts
- Add flowchart visualizations when required
- Follow industrial tool usage patterns
- Align with feature specification learning objectives

### solution.py Updates
- Implement new concepts from feature specs
- Include flowchart explanations
- Demonstrate industrial tool usage
- Align with feature specification requirements

### test_exercise.py Updates
- Add tests for new concepts
- Include industrial tool integration tests
- Follow assessment methods from feature specs
- Ensure comprehensive coverage

### Jupyter Notebook Updates
- Include visual flowchart representations
- Support industrial tool integration
- Align with interactive learning approaches
- Follow feature specification requirements

### run_tests.py Updates
- Support industrial tool requirements
- Follow assessment methods from feature specs
- Maintain backward compatibility
- Update error handling if needed

## Example Update Workflow

### Scenario: Adding While Loop Flowchart Requirements
1. **Review Feature Spec** - Note new flowchart visualization requirements for while loops
2. **Identify Modifications** - exercise.py, solution.py, and Jupyter notebook need updates
3. **Update Template Files**:
   - Add flowchart comments to exercise.py
   - Include flowchart explanations in solution.py
   - Create visual flowchart representations in notebook template
4. **Test Template** - Create sample while loop exercise
5. **Document Changes** - Update TEMPLATE_GUIDE.md and version history

## Best Practices for Template Updates

1. **Backward Compatibility** - Maintain compatibility with existing exercises
2. **Clear Documentation** - Document all changes clearly
3. **Comprehensive Testing** - Test all template elements thoroughly
4. **Version Control** - Use version control for template changes
5. **Peer Review** - Have others review template updates
6. **Gradual Rollout** - Apply updates to new exercises first

## Version History Updates

When updating templates due to feature specification changes:
1. Increment version number appropriately
2. Document specific changes made
3. Note which feature specifications drove the changes
4. Update date and author information
5. Include testing results