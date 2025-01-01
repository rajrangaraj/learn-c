#include <stdio.h>
#include <stdlib.h>

void bad_function() {
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 42;
    // Memory leak: forgot to free ptr
    return; // ptr is lost here
}

void good_function() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) return;
    
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    
    free(ptr);
    ptr = NULL;
}

int main() {
    bad_function();  // Creates a memory leak
    good_function(); // Properly manages memory
    return 0;
} 