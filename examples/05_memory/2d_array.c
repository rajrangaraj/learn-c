#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols = 4;

    // Allocate 2D array
    int **array = (int **)malloc(rows * sizeof(int *));
    if (array == NULL) return 1;

    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            // Clean up previously allocated memory
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    // Use array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
} 