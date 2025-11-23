# Chapter 9: Sequential Containers Exercises Overview

This directory contains exercises for Chapter 9 of C++ Primer 5th Edition, which covers sequential containers in C++. Following the teaching philosophy of concept decomposition, this chapter is split into four focused exercises.

## Exercise Progression

### 9.1a: Vector Operations
**Directory**: [vector_operations](vector_operations/)
**Focus**: Fundamental operations with std::vector
- Creating and initializing vectors
- Element access methods (operator[], at(), front(), back())
- Adding and removing elements (push_back(), pop_back(), insert(), erase())
- Vector capacity management (size(), capacity(), resize(), reserve())

### 9.1b: List Operations
**Directory**: [list_operations](list_operations/)
**Focus**: Bidirectional operations with std::list
- Creating and initializing lists
- Iterator-based element access
- Insertion and deletion at any position
- Splice operations for moving elements between lists
- Sorting and merging lists

### 9.1c: Deque Operations
**Directory**: [deque_operations](deque_operations/)
**Focus**: Double-ended queue operations with std::deque
- Creating and initializing deques
- Element access at both ends and random positions
- Efficient insertion and deletion at both ends
- Comparing deque performance with vector and list

### 9.1d: Container Adapters
**Directory**: [container_adapters](container_adapters/)
**Focus**: Stack, queue, and priority_queue adapters
- Using std::stack for LIFO operations
- Using std::queue for FIFO operations
- Using std::priority_queue for priority-based operations
- Understanding underlying container requirements

## Key Concepts Covered

### Sequential Container Types
- **Vector**: Dynamic array with fast random access
- **List**: Doubly-linked list with efficient insertion/deletion
- **Deque**: Double-ended queue with fast access at both ends

### Container Operations
- **Element Access**: operator[], at(), front(), back()
- **Modifiers**: push_back(), pop_back(), insert(), erase()
- **Capacity**: size(), empty(), resize(), capacity(), reserve()
- **Iterators**: begin(), end(), rbegin(), rend()

### Container Adapters
- **Stack**: LIFO (Last In, First Out) adapter
- **Queue**: FIFO (First In, First Out) adapter
- **Priority Queue**: Heap-based priority adapter

## Container Characteristics

### Performance Comparison
| Operation          | Vector    | List      | Deque     |
|-------------------|-----------|-----------|-----------|
| Random Access     | O(1)      | O(n)      | O(1)      |
| Insert/Remove End | O(1) amortized | O(1) | O(1)      |
| Insert/Remove Mid | O(n)      | O(1) with iterator | O(n) |
| Insert/Remove Front | O(n)    | O(1)      | O(1)      |

### Memory Layout
- **Vector**: Contiguous memory allocation
- **List**: Non-contiguous nodes with pointers
- **Deque**: Sequence of fixed-size blocks

## Prerequisites

Students should be familiar with:
- Basic C++ syntax and control structures
- Arrays and basic data structures
- Pointers and references
- Basic STL concepts
- Iterator concepts

## Next Topics

After completing sequential containers exercises, students should progress to:
- Exercise 9.2: Associative Containers
- Exercise 9.3: Container Algorithms
- Exercise 10.1: Generic Algorithms