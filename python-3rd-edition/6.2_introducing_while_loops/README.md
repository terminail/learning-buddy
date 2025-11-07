# Introducing While Loops

## Learning Objectives
In this exercise, you will learn:
- How to create while loops in Python
- How to set conditions for loop termination
- How to avoid infinite loops
- How to visualize loop execution flow using flowcharts
- The difference between for and while loop execution patterns

## Instructions
Complete the TODO sections in [exercise.py](exercise.py) to:
1. Create basic while loops
2. Set appropriate conditions for loop termination
3. Practice avoiding infinite loops
4. Understand while loop flow through visualizations

## Requirements
- Use while loops to repeat code blocks
- Set clear conditions for loop termination
- Avoid infinite loops by ensuring loop conditions can be met
- Visualize and understand while loop execution flow using flowchart representations
- Follow Python best practices for looping

## Getting Started
1. Open [exercise.py](exercise.py)
2. Complete the TODO sections
3. Run your code with `python exercise.py`
4. Run tests with `python run_tests.py` or `python -m pytest test_exercise.py -v`

## Understanding While Loop Flow with Flowcharts

### Basic While Loop Flowchart
```
Start
  |
  ▼
Initialize variables
  |
  ▼
┌─────────────────┐
│  Check Condition│
└─────────┬───────┘
          │ True
          ▼
  ┌───────────────┐
  │ Execute Loop  │
  │   Body        │
  └───────────────┘
          │
          ▼
  Update loop variables
          │
          ▼
          │ False
          ▼
       End
```

### For vs While Loop Comparison
- **For loops**: Used when you know the number of iterations in advance
- **While loops**: Used when you continue until a condition is met

## Alternative: Interactive Learning
For a better interactive learning experience, we recommend using VS Code with the Jupyter extension:
1. Install VS Code from https://code.visualstudio.com/
2. Install the "Jupyter" and "Python" extensions from the Extensions marketplace
3. Open [6.2_introducing_while_loops.ipynb](6.2_introducing_while_loops.ipynb) directly in VS Code
4. Run notebook cells interactively within VS Code

## Reference
This exercise covers content from Chapter 7 of Python Crash Course, 3rd Edition:
- "Introducing while Loops" (pages 114-118)