# Python Exercise Template Guide

This guide defines the template structure and requirements for creating Python exercises based on the feature specifications. It should be updated whenever feature specifications change.

**Note**: All specifications must be created following the chapter order defined in SPECIFICATION_REQUIREMENTS.md to ensure proper learning progression.

## Template Structure

Each exercise must follow this exact structure:
```
exercise_name/
├── README.md              # Exercise instructions and learning objectives
├── exercise.py            # Incomplete code with TODO comments for students
├── solution.py            # Complete reference solution
├── test_exercise.py       # Test cases using pytest
├── run_tests.py           # Script to run pytest tests
└── exercise_name.ipynb    # Interactive Jupyter notebook
```

## File Requirements

### README.md
**Purpose**: Clear instructions and learning objectives for the exercise

**Required Sections**:
1. **Exercise Title** - Clear, descriptive title
2. **Learning Objectives** - Bullet points of what students will learn
3. **Instructions** - Step-by-step guidance on completing the exercise
4. **Requirements** - Technical requirements and constraints
5. **Getting Started** - How to begin working on the exercise
6. **Feature-Specific Content** - Any content required by feature specifications
7. **Alternative: Interactive Learning** - Jupyter notebook usage instructions
8. **Reference** - Book chapter and page references

**Feature-Specific Requirements**:
- Include flowchart visualization sections when required by feature specs
- Emphasize industrial tools (pytest, Jupyter notebooks)
- Reference specific concepts from feature specifications

### exercise.py
**Purpose**: Incomplete code with TODO comments for students to complete

**Required Elements**:
1. **Header Comment** - Exercise title and purpose
2. **TODO Comments** - Numbered, clear instructions for each task
3. **Feature-Specific TODOs** - Any requirements from feature specifications
4. **Flowchart Visualizations** - ASCII flowcharts when required by feature specs
5. **if __name__ == "__main__"** block - Test code section

**Feature-Specific Requirements**:
- Include flowchart visualization comments for loops and control structures
- Follow industrial tool usage patterns (pytest testing)
- Align with learning objectives from feature specifications

### solution.py
**Purpose**: Complete reference solution for the exercise

**Required Elements**:
1. **Header Comment** - Exercise title and purpose
2. **Complete Implementation** - Working solution for all TODOs
3. **Feature-Specific Content** - Any requirements from feature specifications
4. **Flowchart Explanations** - Comments explaining flowchart concepts
5. **if __name__ == "__main__"** block - Test code to verify solution

**Feature-Specific Requirements**:
- Include flowchart explanation comments for loops and control structures
- Demonstrate industrial tool usage (pytest testing)
- Align with learning objectives from feature specifications

### test_exercise.py
**Purpose**: Test cases to verify exercise solutions using pytest

**Required Elements**:
1. **Header Comment** - Exercise title and purpose
2. **Pytest Import Pattern** - Handle missing pytest gracefully
3. **Test Functions** - Functions that verify exercise implementation
4. **Feature-Specific Tests** - Any requirements from feature specifications
5. **Output Verification** - Test that code runs without errors

**Feature-Specific Requirements**:
- Use pytest as the exclusive testing framework
- Include tests for industrial tool integration
- Align with assessment methods from feature specifications

### run_tests.py
**Purpose**: Script to run pytest tests

**Required Elements**:
1. **Shebang Line** - `#!/usr/bin/env python3`
2. **Header Comment** - Exercise title and purpose
3. **Subprocess Pattern** - Run pytest using subprocess
4. **Error Handling** - Handle missing pytest gracefully
5. **Installation Logic** - Install pytest if missing
6. **Success/Failure Reporting** - Clear test results

**Feature-Specific Requirements**:
- Support industrial tools (pytest)
- Follow assessment methods from feature specifications

### exercise_name.ipynb
**Purpose**: Interactive Jupyter notebook for hands-on learning

**Required Elements**:
1. **Exercise Title** - Clear, descriptive title
2. **Instructions Section** - Learning objectives and requirements
3. **Feature-Specific Content** - Any requirements from feature specifications
4. **Code Cells** - Interactive implementation of exercise tasks
5. **Flowchart Visualization** - Visual flowcharts when required by feature specs
6. **Testing Section** - How to run tests from notebook
7. **Metadata** - Proper notebook metadata

**Feature-Specific Requirements**:
- Include flowchart visualization sections for loops and control structures
- Support industrial tools (pytest integration)
- Align with interactive learning approaches from feature specifications

## Template Update Process

This template guide must be updated when:
1. **Feature specifications change** - Any updates to feature specs require template updates
2. **Industrial tools evolve** - Changes in pytest, Jupyter, etc. require updates
3. **Pedagogical approaches improve** - Better teaching methods should be incorporated
4. **Best practices change** - Updated coding standards require template updates

**Update Procedure**:
1. Review changed feature specifications
2. Identify required template modifications
3. Update this guide with new requirements
4. Modify template files to match new requirements
5. Test template with a sample exercise
6. Document changes in version history

## Version History

### v1.0 - Initial Template
- Basic exercise structure
- Standard file templates
- Initial feature specification alignment

### v1.1 - Industrial Tools Enhancement
- Emphasis on pytest as exclusive testing framework
- Jupyter notebook integration requirements
- Industrial tool usage patterns

### v1.2 - Flowchart Visualization Enhancement
- Flowchart visualization requirements for loops
- Control structure visualization patterns
- Feature specification alignment for visual learning

## Best Practices

1. **Consistency** - All exercises must follow the same template structure
2. **Clarity** - TODO comments must be clear and actionable
3. **Completeness** - All feature specification requirements must be implemented
4. **Testing** - All exercises must include comprehensive pytest tests
5. **Interactivity** - All exercises must include Jupyter notebook versions
6. **Documentation** - All files must include appropriate comments and documentation
7. **Industrial Alignment** - All exercises must use current industrial tools and practices