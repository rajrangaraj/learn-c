# Functions in C

## Function Basics
- **Function declaration**: A statement that tells the compiler about a function's name, return type, and parameters. Also called a function prototype. Example: `int add(int a, int b);`

- **Function definition**: The actual implementation of a function that contains the code to be executed. Includes function header and body with statements. Example:
  ```c
  int add(int a, int b) {
      return a + b;
  }
  ```

- **Return types**: The type of value a function returns to the caller
  - Common return types: int, float, char, void, pointers, structs
  - Must match declaration
  - Use return statement to send value back
  - **void** means no return value

- **Parameters**: Values passed to a function when it is called
  - **Formal parameters**: Variables in function declaration/definition
  - **Actual parameters**: Values passed during function call
  - Must match in number and type
  - Each parameter needs type declaration
  - Can have zero or more parameters

- **void functions**: Functions that don't return a value
  - Declared with **void** return type
  - Used for tasks like printing, updating globals
  - No return value expected
  - Can use bare return statement to exit early
  - Example: `void printMessage(char* msg)`

## Parameter Passing
- **Pass by value**: Copy of actual parameter is passed to function
- **Pass by reference**: Function receives address of actual parameter
- **Array parameters**: Arrays are passed by reference
- **Function pointers**: Pointers to functions

## Function Types
- **Standard library functions**: Functions provided by the C standard library
- **User-defined functions**: Functions created by the programmer
- **Recursive functions**: Functions that call themselves
- **Inline functions**: Functions that are expanded in line with the calling code

## Variable Scope
- **Local variables**: Variables declared inside a function
- **Global variables**: Variables declared outside all functions
- **Static variables**: Variables that retain their value between function calls
- **Block scope**: Variables declared inside a block (e.g., inside a function or loop)

## Advanced Topics
- **Function overloading**: Lack of support in C
- **Variadic functions**: Functions that accept a variable number of arguments
- **Callback functions**: Functions passed as arguments to other functions
- **Function pointers**: Pointers to functions
