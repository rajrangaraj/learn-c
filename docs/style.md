# C Coding Style Guide

## Code Organization
- **File structure**: Organize source files logically by functionality. Keep related functions together. Separate interface (.h) from implementation (.c).
- **Header files**: Contain declarations, prototypes, and definitions needed by other files. Use include guards. Keep includes minimal.
- **Source files**: Contain implementations of functions declared in headers. Group related functions together. One logical unit per file.
- **Include guards**: Prevent multiple inclusion of headers using #ifndef/#define/#endif. Use unique names based on file path.
- **Module organization**: Group related functionality into modules/components. Clear interfaces between modules. Minimize dependencies.

## Naming Conventions
- **Variable names**: Use descriptive lowercase names with underscores (snake_case). Indicate scope/type where helpful (e.g. g_ for globals).
- **Function names**: Use descriptive verb_noun format in snake_case. Names should clearly indicate purpose (e.g. calculate_total).
- **Type names**: Use PascalCase for structs/enums/typedefs. Include _t suffix for typedef types (e.g. UserData_t).
- **Macro names**: Use UPPERCASE with underscores. Clear names that won't conflict (e.g. MAX_BUFFER_SIZE).
- **Constants**: Use UPPERCASE for #define constants. Can use k prefix for const variables (e.g. kMaxSize).

## Formatting
- **Indentation**: Use consistent indentation (4 spaces or 1 tab). Align related items. No mixed tabs/spaces.
- **Braces**: Opening brace on same line for functions/control statements. Closing brace on own line. Always use braces.
- **Line length**: Limit lines to 80-100 characters. Break long lines logically with proper indentation.
- **Spacing**: One space after keywords/commas. No space after function names. Align operators. Blank lines between logical sections.
- **Comments**: Proper spacing around comments. Align multi-line comments. Use // for single line, /* */ for multi-line.

## Documentation
- **Function documentation**: Document purpose, parameters, return value, errors. Use consistent format (e.g. Doxygen).
- **File headers**: Include copyright, brief description, author, date. List major changes in revision history.
- **Inline comments**: Explain complex logic or non-obvious code. Keep comments current with code changes.
- **API documentation**: Thoroughly document public interfaces. Include usage examples. Note thread-safety/error handling.
- **Version control comments**: Clear commit messages. Tag releases. Document breaking changes.

## Best Practices
- **Code readability**: Write clear, self-documenting code. Use meaningful names. Keep functions small and focused.
- **Maintainability**: Follow DRY principle. Minimize global state. Use const correctly. Handle errors properly.
- **Portability**: Use standard C features. Abstract platform-specific code. Check for common portability issues.
- **Consistency**: Follow team/project conventions consistently. Use static analyzers and formatters.
- **Code reviews**: Review all changes. Check style/logic/security. Address feedback completely.