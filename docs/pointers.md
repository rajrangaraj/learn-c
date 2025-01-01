# Pointers in C

## Pointer Basics
- **What is a pointer**: A variable that stores the memory address of another variable. Pointers allow direct manipulation of memory and enable powerful programming techniques.
- **Address operator (&)**: Used to get the memory address of a variable. For example, &x returns the address where variable x is stored.
- **Dereference operator (*)**: Used to access the value stored at the memory address held by a pointer. For example, *ptr retrieves the value that ptr points to.
- **NULL pointers**: Special pointers that don't point to any valid memory location. Used to indicate an invalid or uninitialized pointer.
- **Pointer declaration and initialization**: Pointers are declared using the * symbol (int* ptr) and should be initialized either to NULL or a valid address.

## Pointer Arithmetic
- **Increment and decrement**: Moving pointer to next/previous element using ++ or --. The actual bytes moved depend on the pointer type.
- **Adding/subtracting integers**: Adding or subtracting integers from pointers to move multiple elements forward/backward in memory.
- **Pointer differences**: Subtracting two pointers gives the number of elements between them in memory.
- **Array indexing with pointers**: Arrays can be accessed using pointer arithmetic instead of array indexing (*(ptr + i) is equivalent to arr[i]).

## Pointer Types
- **Generic pointers (void*)**: Pointers that can hold address of any data type. Must be cast to specific type before dereferencing.
- **Function pointers**: Pointers that store addresses of functions. Enable callbacks and dynamic function dispatch.
- **Pointers to pointers**: Pointers that store addresses of other pointers. Used for multi-level indirection and dynamic multi-dimensional arrays.
- **Constant pointers**: Pointers whose address cannot be changed after initialization (int* const ptr).
- **Pointer to constant**: Pointers to values that cannot be modified through the pointer (const int* ptr).

## Common Uses
- **Dynamic memory allocation**: Allocating and managing memory at runtime using malloc(), free() and related functions.
- **Pass by reference**: Passing pointers to functions to allow them to modify original variables instead of copies.
- **Array manipulation**: Efficient array traversal and modification using pointer arithmetic.
- **String handling**: Strings in C are character arrays manipulated using pointers.
- **Data structures**: Implementing linked lists, trees, graphs and other data structures using pointers to connect nodes.

## Advanced Topics
- **Dangling pointers**: Pointers that point to memory that has been freed or is no longer valid. Major source of bugs.
- **Memory leaks**: Memory that remains allocated but unreachable when pointers to it are lost. Causes programs to consume more memory over time.
- **Wild pointers**: Uninitialized pointers that contain garbage values. Must be initialized before use.
- **Pointer alignment**: Memory alignment requirements for different data types to ensure efficient access.
- **Function pointer arrays**: Arrays of function pointers used to implement dispatch tables and callbacks.