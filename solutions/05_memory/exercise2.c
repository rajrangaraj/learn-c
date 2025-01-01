#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows1, cols1, rows2, cols2;
    
    printf("Enter dimensions of first matrix (rows cols): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter dimensions of second matrix (rows cols): ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Invalid dimensions for matrix multiplication!\n");
        return 1;
    }

    // Create matrices
    int **matrix1 = create_matrix(rows1, cols1);
    int **matrix2 = create_matrix(rows2, cols2);
    int **result = create_matrix(rows1, cols2);

    if (!matrix1 || !matrix2 || !result) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Fill with random numbers
    srand(time(NULL));
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++)
            matrix1[i][j] = rand() % 10;
    
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++)
            matrix2[i][j] = rand() % 10;

    // Multiply matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print result
    printf("\nResult:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free_matrix(matrix1, rows1);
    free_matrix(matrix2, rows2);
    free_matrix(result, rows1);

    return 0;
} 