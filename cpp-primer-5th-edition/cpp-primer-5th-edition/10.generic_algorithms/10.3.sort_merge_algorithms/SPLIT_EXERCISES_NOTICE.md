# Notice: Sort and Merge Algorithms Exercises Have Been Split

Following the teaching philosophy outlined in [TEACHING_PHILOSOPHY.md](../doc/TEACHING_PHILOSOPHY.md), 
the original "Sort and Merge Algorithms" exercise has been split into three smaller, 
more focused exercises to improve learning effectiveness.

## Why We Split This Exercise

1. **Concept Decomposition**: The original exercise covered too many concepts at once, 
   making it difficult for students to focus on individual algorithms.

2. **Progressive Difficulty**: By splitting the exercise, we can introduce concepts 
   gradually, starting with basic sorting, then advancing to partial sorting, 
   and finally covering merge algorithms.

3. **Confidence Building**: Smaller exercises allow students to experience more 
   frequent successes, building confidence as they progress.

4. **Clearer Structure**: Each new exercise has a focused learning objective, 
   making it easier for students to understand what they need to learn.

## New Exercises

### 10.3a: Basic Sorting Algorithms
**Directory**: [../10.3a.basic_sorting_algorithms](../10.3a.basic_sorting_algorithms/)
**Focus**: Fundamental sorting algorithms
- Using std::sort for basic container sorting
- Using std::stable_sort to maintain relative order
- Sorting containers of custom objects with lambda expressions
- Working with different sorting orders (ascending/descending)

### 10.3b: Advanced Sorting Algorithms
**Directory**: [../10.3b.advanced_sorting_algorithms](../10.3b.advanced_sorting_algorithms/)
**Focus**: Partial sorting and selection algorithms
- Using std::partial_sort for partial ordering
- Using std::nth_element for efficient selection
- Performance comparison of sorting approaches
- When to use partial sorting vs. full sorting

### 10.3c: Merge Algorithms
**Directory**: [../10.3c.merge_algorithms](../10.3c.merge_algorithms/)
**Focus**: Merging sorted sequences
- Using std::merge to combine sorted sequences
- Using std::inplace_merge for adjacent sorted sequences
- Working with merge algorithms and custom comparators
- Memory-efficient merging techniques

## Benefits of This Approach

1. **Reduced Cognitive Load**: Each exercise focuses on a single concept, 
   preventing information overload.

2. **Better Retention**: Focused practice on individual algorithms reinforces learning.

3. **Clear Progression**: Students can clearly see their learning path and progress.

4. **Modern Skills Development**: Each exercise follows modern C++ best practices 
   and uses up-to-date tools and techniques.

This change aligns with our commitment to providing the best possible learning 
experience for students working through C++ Primer 5th Edition.