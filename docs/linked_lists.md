# Linked Lists in C

## Singly Linked Lists
- **Node structure**: A node in a singly linked list contains two parts:
  - Data: Stores the actual value
  - Next pointer: Points to the next node in the list
- **List creation**: Process of initializing an empty list with a NULL head pointer
- **Insertion operations**: Three main types:
  - **Insert at beginning**: O(1)
  - **Insert at end**: O(n)
  - **Insert at position**: O(n)
- **Deletion operations**: Three main types:
  - **Delete from beginning**: O(1)
  - **Delete from end**: O(n)
  - **Delete from position**: O(n)
- **Traversal**: Process of visiting each node sequentially by following next pointers

## Doubly Linked Lists
- **Node structure**: Contains three parts:
  - **Previous pointer**: Points to previous node
  - **Data**: Stores the value
  - **Next pointer**: Points to next node
- **Forward/backward traversal**: Can traverse in both directions using prev/next pointers
- **Insertion operations**: Similar to singly linked list but requires updating prev pointers
- **Deletion operations**: Requires updating both prev and next pointers of adjacent nodes
- **List reversal**: Can be done by swapping prev and next pointers of each node

## Circular Linked Lists
- **Single circular**: Last node points back to first node instead of NULL
- **Double circular**: Both first node's prev and last node's next point to each other
- **Operations**: Similar to regular linked lists but need special handling for the circular nature
- **Applications**: Round-robin scheduling, circular buffers, game loops
- **Implementation**: Requires careful handling of the circular reference during operations

## Advanced Operations
- **Merging lists**: Combining two sorted lists while maintaining order
- **Sorting lists**: Implementation of sorting algorithms like merge sort and insertion sort
- **Finding cycles**: Detecting if a linked list has a cycle using Floyd's algorithm
- **List partitioning**: Dividing list into parts based on certain criteria
- **List manipulation**: Operations like reversing, rotating, or rearranging nodes

## Common Applications
- **Memory management**: Used in memory allocators for managing free blocks
- **Symbol tables**: Implementing hash table chains and compiler symbol tables
- **Undo systems**: Maintaining history of operations in applications
- **Polynomial arithmetic**: Representing and manipulating polynomials
- **Memory efficient arrays**: Dynamic arrays that can grow and shrink efficiently