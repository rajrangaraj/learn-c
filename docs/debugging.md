# Debugging C Programs
A comprehensive guide to debugging techniques and tools for C programming.

## Debugging Tools
- **GDB basics**: GNU Debugger (GDB) is a powerful command-line debugger that allows you to inspect program state, set breakpoints, and step through code execution
- **Debugger commands**: Common GDB commands like run, next, step, continue, print, and backtrace for controlling program execution and examining variables
- **Breakpoints**: Points in code where execution pauses, allowing inspection of program state at specific locations
- **Watch points**: Special breakpoints that trigger when a variable's value changes
- **Stack traces**: Display of current call stack showing function call hierarchy leading to current point of execution

## Debugging Techniques
- **Print debugging**: Adding printf statements to track program flow and variable values
- **Log files**: Writing debug information to files for later analysis, especially useful for long-running programs
- **Assert statements**: Runtime checks that verify program assumptions and invariants
- **Error handling**: Proper implementation of error detection, reporting, and recovery mechanisms
- **Memory checking**: Techniques to detect memory leaks, buffer overflows, and invalid memory access

## Common Issues
- **Segmentation faults**: Program crashes from invalid memory access, often due to null pointers or array bounds violations
- **Memory leaks**: Failure to properly free allocated memory, leading to resource exhaustion
- **Undefined behavior**: Program behavior not defined by C standard, leading to unpredictable results
- **Race conditions**: Timing-dependent bugs in concurrent programs where outcome depends on execution order
- **Logic errors**: Mistakes in program logic leading to incorrect results despite valid syntax

## Debug Builds
- **Debug vs Release**: Different build configurations optimized for debugging or performance
- **Compiler options**: Flags like -g for debug symbols, -Wall for warnings, -O0 to disable optimizations
- **Debug symbols**: Additional information embedded in executable to aid debugging
- **Optimization levels**: Different levels of compiler optimization that can affect debugging
- **Conditional compilation**: Using preprocessor directives like #ifdef DEBUG for debug-only code

## Tools and Utilities
- **Valgrind**: Powerful tool for memory debugging, memory leak detection, and profiling
- **Address sanitizer**: Runtime memory error detector that finds buffer overflows and use-after-free bugs
- **Memory sanitizer**: Tool for finding uninitialized memory reads
- **Static analyzers**: Tools that analyze source code without running it to find potential bugs
- **Profilers**: Tools like gprof for analyzing program performance and identifying bottlenecks