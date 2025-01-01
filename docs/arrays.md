# Arrays in C
A fundamental data structure that stores a fixed-size sequential collection of elements of the same type.

## Array Basics
- **Declaration and initialization**: Creating arrays using syntax like `int arr[5] = {1,2,3,4,5}` or `char str[] = "hello"`
- **Array indexing**: Accessing array elements using zero-based indices like `arr[0]`, `arr[1]`, etc.
- **Array size**: Determining array length using sizeof operator or tracking size manually
- **Array bounds**: Ensuring array accesses stay within declared bounds to prevent buffer overflows

## Array Operations
- **Traversing arrays**: Iterating through array elements using loops to process each element
- **Searching**: Finding elements using linear search, binary search (for sorted arrays), etc.
- **Sorting**: Arranging elements in order using algorithms like bubble sort, quicksort, etc.
- **Copying arrays**: Duplicating array contents using loops or functions like memcpy()

## Multidimensional Arrays
- **2D arrays**: Two-dimensional arrays like matrices, declared as `int arr[rows][cols]`
- **3D arrays**: Three-dimensional arrays for 3D data, declared as `int arr[x][y][z]`
- **Array of arrays**: Arrays where each element is itself an array
- **Memory layout**: How multidimensional arrays are stored contiguously in row-major order

## Array and Functions
- **Arrays as parameters**: Passing arrays to functions using pointer syntax
- **Returning arrays**: Techniques for returning arrays from functions (using pointers)
- **Dynamic arrays**: Creating variable-sized arrays at runtime using malloc()
- **Array decay to pointers**: How arrays are automatically converted to pointers when passed

## Common Patterns
- **Array as buffer**: Using arrays as temporary storage for data processing
- **Circular arrays**: Arrays that wrap around, useful for queues and buffers
- **Array slicing**: Working with portions or subsections of arrays
- **Array merging**: Combining multiple arrays into a single array