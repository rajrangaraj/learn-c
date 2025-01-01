# C Programming Basics
## Introduction to C
- **Language overview**: C is a general-purpose, procedural programming language that provides low-level memory access and maps efficiently to machine instructions
- **History**: Developed by Dennis Ritchie at Bell Labs between 1969-1973 for the Unix operating system
- **Key features**: 
  - Structured programming
  - Lexical variable scope
  - Static type system
  - Compiled language
  - Platform independence

## Program Structure
- **Basic elements**: Keywords, identifiers, constants, strings, operators
- **Program organization**:
  - Header files (#include directives)
  - Function declarations
  - Global variables
  - Main function
  - User-defined functions
- **Compilation process**:
  - Preprocessing
  - Compilation
  - Assembly
  - Linking

## First Program
- **Hello World example**:
  ```c
  #include <stdio.h>
  
  int main() {
      printf("Hello, World!\n");
      return 0;
  }
  ```
- **Program components**:
  - Header inclusion
  - Main function declaration
  - Function body
  - Statements and expressions
  - Return statement

## Comments and Documentation
- **Single-line comments**: Using // for brief explanations
- **Multi-line comments**: Using /* */ for detailed documentation
- **Documentation practices**:
  - Function documentation
  - Variable documentation
  - Code organization
  - Meaningful naming conventions

## Coding Style
- **Indentation**: Consistent use of spaces or tabs
- **Naming conventions**: 
  - Meaningful variable names
  - Function naming
  - Constant naming
- **Spacing and formatting**:
  - Around operators
  - After commas
  - Around brackets
- **Code organization**:
  - One statement per line
  - Logical grouping of related code
  - Consistent brace placement

## Variables and Data Types

### Basic Data Types
- `int`: Integer numbers (e.g., -1, 0, 42)
- `float`: Decimal numbers (e.g., 3.14)
- `double`: Double precision decimal numbers
- `char`: Single characters (e.g., 'A', '1', '$')

### Variable Declaration
- `int a;` declares an integer variable named `a`.
- `float b = 3.14;` declares a float variable named `b` and initializes it to 3.14.
- `char c = 'X';` declares a character variable named `c` and initializes it to 'X'.

### Data Types in C
- `int`: Integer numbers (e.g., -1, 0, 42)
- `float`: Decimal numbers (e.g., 3.14)
- `double`: Double precision decimal numbers
- `char`: Single characters (e.g., 'A', '1', '$')
    

## Operators
- **Arithmetic operators**: Basic mathematical operations
  - `+` Addition (a + b)
  - `-` Subtraction (a - b) 
  - `*` Multiplication (a * b)
  - `/` Division (a / b)
  - `%` Modulo/remainder (a % b)

- **Relational operators**: Compare values and return true/false
  - `==` Equal to (a == b)
  - `!=` Not equal to (a != b)
  - `>` Greater than (a > b)
  - `<` Less than (a < b)
  - `>=` Greater than or equal to (a >= b)
  - `<=` Less than or equal to (a <= b)

- **Logical operators**: Combine conditions
  - `&&` Logical AND (a && b) - true if both operands are true
  - `||` Logical OR (a || b) - true if either operand is true
  - `!` Logical NOT (!a) - inverts the logical state

- **Bitwise operators**: Manipulate individual bits
  - `&` Bitwise AND
  - `|` Bitwise OR
  - `^` Bitwise XOR
  - `~` Bitwise NOT
  - `<<` Left shift
  - `>>` Right shift

- **Assignment operators**: Assign values to variables
  - `=` Simple assignment (a = b)
  - `+=` Add and assign (a += b is same as a = a + b)
  - `-=` Subtract and assign
  - `*=` Multiply and assign
  - `/=` Divide and assign
  - `%=` Modulo and assign
  - Bitwise assignment (`&=`, `|=`, `^=`, `<<=`, `>>=`)

- **Increment/decrement**: Change value by 1
  - `++` Increment (++a or a++)
  - `--` Decrement (--a or a--)
  - Prefix (++a) - increment first, then use value
  - Postfix (a++) - use value first, then increment

- **Operator precedence**: Order of operations
  1. Parentheses ()
  2. Increment/decrement, unary +/-
  3. Multiplication, division, modulo
  4. Addition, subtraction
  5. Bitwise shifts
  6. Relational operators
  7. Equality operators
  8. Bitwise AND, OR, XOR
  9. Logical AND, OR
  10. Assignment operators


## Input/Output Basics
- **printf and scanf**: Standard functions for formatted input/output. printf() prints formatted text to stdout, while scanf() reads formatted input from stdin. Both use format specifiers like %d, %f, %s etc.
- **getchar and putchar**: Simple character I/O functions. getchar() reads a single character from stdin, putchar() writes a single character to stdout. Useful for character-by-character processing.
- **Basic formatting**: Format specifiers control how values are displayed:
  - %d for integers
  - %f for floating point 
  - %c for characters
  - %s for strings
  - Width and precision modifiers
  - Left/right alignment
  - Leading zeros
  - Plus/minus signs