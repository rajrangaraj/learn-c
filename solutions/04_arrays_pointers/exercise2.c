#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int** create_matrix(int rows, int cols);
void free_matrix(int** matrix, int rows);
void print_matrix(int** matrix, int rows, int cols);
int** add_matrices(int** m1, int** m2, int rows, int cols);
int** multiply_matrices(int** m1, int** m2, int r1, int c1, int c2);
int** transpose_matrix(int** matrix, int rows, int cols);
int determinant_2x2(int** matrix);
int determinant_3x3(int** matrix);

// Create matrix
int** create_matrix(int rows, int cols) {
    int** matrix = malloc(rows * sizeof(int*));
    if (!matrix) return NULL;
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Free matrix
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Print matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Add matrices
int** add_matrices(int** m1, int** m2, int rows, int cols) {
    int** result = create_matrix(rows, cols);
    if (!result) return NULL;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

// Multiply matrices
int** multiply_matrices(int** m1, int** m2, int r1, int c1, int c2) {
    int** result = create_matrix(r1, c2);
    if (!result) return NULL;
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

// Transpose matrix
int** transpose_matrix(int** matrix, int rows, int cols) {
    int** result = create_matrix(cols, rows);
    if (!result) return NULL;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// Calculate 2x2 determinant
int determinant_2x2(int** matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Calculate 3x3 determinant
int determinant_3x3(int** matrix) {
    int det = 0;
    det += matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    det -= matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    det += matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

int main() {
    // Create test matrices
    int** m1 = create_matrix(2, 2);
    int** m2 = create_matrix(2, 2);
    
    // Initialize matrices
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;
    
    m2[0][0] = 5; m2[0][1] = 6;
    m2[1][0] = 7; m2[1][1] = 8;
    
    // Test operations
    printf("Matrix 1:\n");
    print_matrix(m1, 2, 2);
    
    printf("Matrix 2:\n");
    print_matrix(m2, 2, 2);
    
    int** sum = add_matrices(m1, m2, 2, 2);
    printf("Sum:\n");
    print_matrix(sum, 2, 2);
    
    int** product = multiply_matrices(m1, m2, 2, 2, 2);
    printf("Product:\n");
    print_matrix(product, 2, 2);
    
    printf("Determinant of Matrix 1: %d\n", determinant_2x2(m1));
    
    // Clean up
    free_matrix(m1, 2);
    free_matrix(m2, 2);
    free_matrix(sum, 2);
    free_matrix(product, 2);
    
    return 0;
} 