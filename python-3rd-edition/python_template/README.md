# Python Exercise Template

This is a template for creating clean, consistent Python exercises for the Python Crash Course study plan.

## Files
- `README.md` - Clear instructions for the exercise
- `exercise.py` - Incomplete code with TODO comments for students to complete
- `solution.py` - Complete reference solution
- `test_exercise.py` - Test cases to verify the solution (pytest)
- `run_tests.py` - Script to run pytest tests
- `exercise_name.ipynb` - Interactive Jupyter notebook

## How to Use This Template
1. Copy this entire directory and rename it appropriately (e.g., `1.1_variables_strings`)
2. Update the README.md with exercise-specific instructions
3. Modify exercise.py with the actual exercise content and TODO comments
4. Implement the complete solution in solution.py
5. Create appropriate test cases in test_exercise.py (pytest)
6. Update the test runner script with the correct file names
7. Update the Jupyter notebook with exercise-specific content

## Exercise Structure Guidelines
- Keep exercises focused on a single concept or chapter
- Provide clear TODO comments in exercise.py
- Include comprehensive test cases that verify correct implementation
- Use consistent Python 3.x syntax across all exercises
- Follow the same directory structure and file naming conventions
- Include pytest test files for comprehensive testing
- Provide an interactive Jupyter notebook for hands-on learning
- **Include flowchart visualizations when required by feature specifications**
- **Emphasize industrial tools (pytest, Jupyter notebooks) throughout**

## Feature-Specific Requirements
When creating exercises based on feature specifications, ensure:
- All learning objectives from the feature spec are covered
- Required concepts from the feature spec are implemented
- Industrial tools (pytest, Jupyter notebooks) are properly integrated
- Flowchart visualizations are included when specified in the feature spec

## Testing Options
Students can test their code in multiple ways:
1. **Pytest**: Run `python run_tests.py` or `python -m pytest test_exercise.py -v`
2. **Interactive**: Use the Jupyter notebook for hands-on experimentation

## Template Guide
This template follows the TEMPLATE_GUIDE.md specification which should be updated whenever feature specifications change.