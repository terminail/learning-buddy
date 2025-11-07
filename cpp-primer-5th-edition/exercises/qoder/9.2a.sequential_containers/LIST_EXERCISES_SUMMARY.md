# List Exercises Summary

This document provides an overview of all list exercises created for learning C++ Primer 5th Edition concepts.

## Exercise Progression

### 9.2a: List Basics
**Directory**: [list_basics](list_basics/)
**Focus**: Introduction to std::list container
- List declaration and initialization
- Bidirectional insertion and deletion (push_front, push_back, insert)
- Iterator usage with lists (bidirectional iterators)
- List-specific operations (pop_front, pop_back)

## Key Concepts Covered

- **List Characteristics**: Doubly-linked list implementation
- **Bidirectional Operations**: Efficient insertion/deletion at both ends
- **Iterator Types**: Bidirectional iterators (not random access)
- **Memory Management**: Non-contiguous storage
- **Performance**: O(1) insertion/deletion, O(n) access

## Comparison with Vectors

| Operation | Vector | List |
|-----------|--------|------|
| Insert at end | O(1) amortized | O(1) |
| Insert at beginning | O(n) | O(1) |
| Insert at middle | O(n) | O(1) + search time |
| Random access | O(1) | O(n) |
| Memory layout | Contiguous | Non-contiguous |

## Next Topics

After completing list exercises, students should progress to:
- List Algorithms (sorting, merging, splicing)
- Other Sequential Containers (deque)
- Container Adapters (stack, queue)