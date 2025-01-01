#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;
    
    // Allocate array dynamically
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) return 1;

    // Initialize array
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    // Resize array (realloc)
    int new_size = 10;
    int *temp = (int *)realloc(array, new_size * sizeof(int));
    if (temp != NULL) {
        array = temp;
        // Initialize new elements
        for (int i = size; i < new_size; i++) {
            array[i] = i + 1;
        }
    }

    // Print and free
    for (int i = 0; i < new_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
} 