# Security in C Programming

## Common Vulnerabilities
- **Buffer overflows**: Writing data beyond array bounds, corrupting adjacent memory. Can allow code execution. Prevent with bounds checking and safe string functions.
- **Integer overflows**: When arithmetic operations exceed the max value for the integer type. Can lead to buffer overflows or logical errors. Use appropriate integer types and check for overflow.
- **Format string attacks**: When untrusted format strings are passed to printf-family functions. Can leak memory or enable code execution. Always use constant format strings.
- **Memory leaks**: Failing to free allocated memory, causing program to consume more memory over time. Track allocations and ensure proper cleanup.
- **Use after free**: Accessing memory after it has been freed. Causes undefined behavior and crashes. Set pointers to NULL after freeing.

## Secure Coding
- **Input validation**: Verify all input meets expected format and constraints before processing. Check lengths, types, ranges and sanitize.
- **Bounds checking**: Validate array indices and buffer sizes before reading/writing. Use safe string functions that take size parameters.
- **Safe string handling**: Use strncpy, strncat instead of strcpy, strcat. Check string lengths. Ensure proper null termination.
- **Memory management**: Track all allocations, validate sizes, check for overflow, free properly. Use tools to detect leaks.
- **Error handling**: Check return values, handle errors gracefully, avoid information leaks in error messages.

## Security Functions
- **Random number generation**: Use cryptographically secure RNG (like /dev/urandom) for security purposes. Standard rand() is predictable.
- **Cryptographic functions**: Use established crypto libraries for encryption, hashing, signing. Don't implement crypto yourself.
- **Secure memory functions**: Use memset_s to clear sensitive data, as regular memset can be optimized away. Lock memory containing secrets.
- **Authentication**: Securely verify identity using strong password hashing (like bcrypt), challenge-response protocols, tokens.
- **Access control**: Validate permissions before operations. Drop privileges when possible. Implement role-based access control.

## Security Testing
- **Static analysis**: Automated code scanning to find potential vulnerabilities without running the program. Use tools like Coverity.
- **Dynamic analysis**: Runtime testing to find memory errors and other bugs. Tools like Valgrind and AddressSanitizer.
- **Fuzzing**: Automated testing with random/invalid inputs to find crashes and vulnerabilities. Use tools like AFL.
- **Penetration testing**: Actively trying to find and exploit security vulnerabilities. Both automated and manual testing.
- **Code review**: Manual inspection of code for security issues. Use checklists and multiple reviewers.

## Best Practices
- **Least privilege**: Run with minimal necessary permissions. Drop privileges when possible. Compartmentalize functionality.
- **Defense in depth**: Multiple layers of security controls. Don't rely on single protection mechanism.
- **Secure defaults**: Start with restrictive settings that must be explicitly loosened. Make the secure way the easy way.
- **Input sanitization**: Clean and normalize input before processing. Remove/escape dangerous characters. Use whitelisting.
- **Error handling**: Fail securely. Don't leak sensitive info in errors. Log security events. Handle all error cases.