#include <stdio.h>

int main() {
    // Array declaration and initialization
    int numbers[] = {1, 2, 3, 4, 5};
    
    // Array traversal
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // 2D array
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // Print matrix
    printf("Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
} 