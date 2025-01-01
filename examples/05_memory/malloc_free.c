#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Use the allocated memory
    *ptr = 42;
    printf("Value: %d\n", *ptr);

    // Free the memory
    free(ptr);
    ptr = NULL;  // Good practice to avoid dangling pointers

    return 0;
} 