#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define error codes
#define SUCCESS 0
#define ERROR_FILE_OPEN -1
#define ERROR_MEMORY -2
#define ERROR_INVALID_INPUT -3

// Function that returns error code
int process_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return ERROR_FILE_OPEN;
    
    char *buffer = malloc(1000);
    if (!buffer) {
        fclose(file);
        return ERROR_MEMORY;
    }
    
    // Process file...
    
    free(buffer);
    fclose(file);
    return SUCCESS;
}

int main() {
    int result = process_data("data.txt");
    
    switch (result) {
        case SUCCESS:
            printf("Operation successful\n");
            break;
        case ERROR_FILE_OPEN:
            fprintf(stderr, "Failed to open file\n");
            break;
        case ERROR_MEMORY:
            fprintf(stderr, "Memory allocation failed\n");
            break;
        default:
            fprintf(stderr, "Unknown error: %d\n", result);
    }
    
    return result != SUCCESS;
} 