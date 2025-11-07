# Container Adapters Exercises Summary

This document provides an overview of all container adapters exercises created for learning C++ Primer 5th Edition concepts.

## Exercise Progression

### 9.3a: Stack Basics
**Directory**: [stack_basics](stack_basics/)
**Focus**: Introduction to std::stack container adapter
- Stack declaration and initialization
- LIFO (Last In, First Out) operations
- Stack operations (push, pop, top)
- Capacity and empty checking

### 9.3b: Queue Basics
**Directory**: ../9.3b.container_adapters/queue_basics/
**Focus**: Introduction to std::queue container adapter
- Queue declaration and initialization
- FIFO (First In, First Out) operations
- Queue operations (push, pop, front, back)
- Capacity and empty checking

### 9.3c: Priority Queue Basics
**Directory**: ../9.3c.container_adapters/priority_queue_basics/
**Focus**: Introduction to std::priority_queue container adapter
- Priority queue declaration and initialization
- Priority-based operations (push, pop, top)
- Heap data structure concepts
- Custom priority ordering

## Key Concepts Covered

- **Container Adapters**: Adapting existing containers for specific interfaces
- **Stack Principles**: LIFO data structure
- **Queue Principles**: FIFO data structure
- **Priority Queue Principles**: Priority-based ordering (heap)
- **Underlying Containers**: deque (stack/queue default), vector (priority_queue default)
- **Restricted Access**: No iteration, only specific access methods
- **Common Use Cases**: Different algorithmic applications

## Container Adapter Types

### Stack (LIFO)
- **Operations**: push, pop, top
- **Use Cases**: Function call management, undo mechanisms, expression evaluation

### Queue (FIFO)
- **Operations**: push, pop, front, back
- **Use Cases**: Breadth-first search, task scheduling, buffer management

### Priority Queue (Heap-based)
- **Operations**: push, pop, top (highest priority)
- **Use Cases**: Task scheduling, Dijkstra's algorithm, Huffman coding, heap sort

## Next Topics

After completing container adapters exercises, students should progress to:
- Associative Containers (map, set)
- Generic Algorithms
- Iterators in Depth