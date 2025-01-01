#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;

    // Basic pointer operations
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value at ptr: %d\n", *ptr);
    
    // Modifying value through pointer
    *ptr = 20;
    printf("New value of x: %d\n", x);
    
    // Array and pointer arithmetic
    int arr[] = {1, 2, 3};
    int *arrPtr = arr;
    
    printf("Array values: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", *(arrPtr + i));
    }
    printf("\n");
    
    return 0;
} 