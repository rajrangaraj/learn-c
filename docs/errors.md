# Error Handling in C
A comprehensive guide to handling errors and exceptions in C programming.

## Introduction
Error handling is crucial in C programming to ensure robust and reliable software. It involves detecting, reporting, and recovering from various types of errors that can occur during program execution.

## Error Categories
- **Compile-time errors**: Syntax errors and other issues caught by the compiler
- **Runtime errors**: Errors that occur during program execution like division by zero
- **Logical errors**: Mistakes in program logic that produce incorrect results
- **System errors**: Errors from operating system or hardware like file not found
- **User errors**: Invalid input or usage errors from program users

## Error Detection
- **Return value checking**: Examining function return values for error codes
- **Status flags**: Using global or local flags to track error states
- **Error conditions**: Testing for error conditions before operations
- **Validation**: Input validation and bounds checking
- **Assertions**: Runtime verification of program assumptions

## Error Reporting
- **Error messages**: Clear, informative messages describing the error
- **Error codes**: Numeric codes indicating specific error types
- **Error logging**: Recording errors to log files for later analysis
- **Debug output**: Additional information for debugging
- **User feedback**: Appropriate error communication to end users

## Error Recovery
- **Graceful degradation**: Continuing with reduced functionality
- **Resource cleanup**: Properly freeing resources on error
- **State restoration**: Returning to known good state
- **Retry mechanisms**: Attempting operations again after errors
- **Fallback options**: Alternative approaches when primary method fails

## Error Prevention
- **Defensive programming**: Anticipating and preventing potential errors
- **Input validation**: Thorough checking of all input data
- **Resource management**: Proper allocation and deallocation
- **Exception handling**: Structured approach to error handling
- **Testing**: Comprehensive testing to catch errors early

## Error Basics
- **Error types**: Different types of errors that can occur in a program
- **Error detection**: Methods to identify errors in a program
- **Error reporting**: Techniques to communicate errors to the user or developer
- **Error recovery**: Strategies to handle and recover from errors
- **Error codes**: Numeric codes used to represent specific errors

## Error Handling Tools
- **errno**: Global variable that holds the error number    
- **perror**: Prints an error message to stderr
- **strerror**: Converts an error number to a string
- **assert**: Checks for an error condition and halts program execution if true
- **Exit codes**: Standardized codes used to indicate program termination status

## Error Handling Patterns
- **Return codes**: Using return values to indicate errors
- **Error flags**: Using global or local flags to track error states
- **Error callbacks**: Using function pointers to handle errors
- **Cleanup handlers**: Registering cleanup functions to handle resource deallocation
- **Exception simulation**: Simulating exceptions using error codes and error handling functions

## System Errors
- **File errors**: Errors related to file operations
- **Memory errors**: Errors related to memory allocation and deallocation
    - **Runtime errors**: Errors that occur during program execution like division by zero
- **Logic errors**: Mistakes in program logic that produce incorrect results
- **System calls**: Errors from operating system or hardware like file not found

## Best Practices
- **Error checking**: Checking for errors in function return values
- **Resource cleanup**: Properly freeing resources on error
- **Error logging**: Recording errors to log files for later analysis
- **Error prevention**: Anticipating and preventing potential errors
- **Defensive programming**: Anticipating and preventing potential errors
