#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int find_min_max(int *arr, int size, int *min, int *max);
double calculate_average(int *arr, int size);
void reverse_array(int *arr, int size);
void rotate_array(int *arr, int size, int positions);
int remove_duplicates(int *arr, int *size);

// Find minimum and maximum values - O(n)
int find_min_max(int *arr, int size, int *min, int *max) {
    if (size <= 0 || arr == NULL) return 0;
    
    *min = *max = arr[0];
    for (int *p = arr + 1; p < arr + size; p++) {
        if (*p < *min) *min = *p;
        if (*p > *max) *max = *p;
    }
    return 1;
}

// Calculate average - O(n)
double calculate_average(int *arr, int size) {
    if (size <= 0) return 0;
    
    double sum = 0;
    for (int *p = arr; p < arr + size; p++) {
        sum += *p;
    }
    return sum / size;
}

// Reverse array in-place - O(n/2)
void reverse_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Rotate array by N positions - O(n)
void rotate_array(int *arr, int size, int positions) {
    positions = positions % size;
    if (positions < 0) positions += size;
    
    // Reverse entire array
    reverse_array(arr, size);
    // Reverse first positions elements
    reverse_array(arr, positions);
    // Reverse remaining elements
    reverse_array(arr + positions, size - positions);
}

// Remove duplicates - O(n^2)
int remove_duplicates(int *arr, int *size) {
    if (*size <= 1) return 1;
    
    int write = 1;
    for (int read = 1; read < *size; read++) {
        int is_duplicate = 0;
        
        // Check if current element is duplicate
        for (int i = 0; i < write; i++) {
            if (arr[read] == arr[i]) {
                is_duplicate = 1;
                break;
            }
        }
        
        if (!is_duplicate) {
            arr[write] = arr[read];
            write++;
        }
    }
    
    *size = write;
    return 1;
}

int main() {
    int arr[] = {4, 2, 7, 2, 1, 8, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Test min/max
    int min, max;
    if (find_min_max(arr, size, &min, &max)) {
        printf("Min: %d, Max: %d\n", min, max);
    }
    
    // Test average
    printf("Average: %.2f\n", calculate_average(arr, size));
    
    // Test reverse
    reverse_array(arr, size);
    printf("Reversed: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Test rotate
    rotate_array(arr, size, 3);
    printf("Rotated by 3: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Test remove duplicates
    remove_duplicates(arr, &size);
    printf("Without duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
} 