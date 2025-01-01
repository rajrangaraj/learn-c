#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;
    
    // Basic arithmetic operations
    printf("Addition: %d + %d = %d\n", a, b, a + b);
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    printf("Division: %d / %d = %d\n", a, b, a / b);
    printf("Modulus: %d %% %d = %d\n", a, b, a % b);
    
    // Integer division vs floating-point division
    float c = (float)a / b;
    printf("Float division: %d / %d = %.2f\n", a, b, c);
    
    return 0;
} 