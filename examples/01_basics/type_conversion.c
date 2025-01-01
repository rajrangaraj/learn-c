#include <stdio.h>

int main() {
    // Implicit conversion
    int i = 10;
    float f = i;    // int to float
    printf("Int to float: %d -> %.1f\n", i, f);
    
    // Explicit conversion (casting)
    float pi = 3.14159;
    int rounded = (int)pi;
    printf("Float to int: %.2f -> %d\n", pi, rounded);
    
    // Character to integer
    char c = 'A';
    int ascii = c;
    printf("Character '%c' to ASCII: %d\n", c, ascii);
    
    return 0;
} 