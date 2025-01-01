#include <stdio.h>

// Function declaration
int add(int a, int b);
void greet(char name[]);
int factorial(int n);

int main() {
    // Function calls
    printf("Sum: %d\n", add(5, 3));
    greet("Alice");
    printf("Factorial of 5: %d\n", factorial(5));
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
} 