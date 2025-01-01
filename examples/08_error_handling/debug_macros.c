#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Debug macros
#define DEBUG 1

#define LOG_ERROR(msg) do { \
    if (DEBUG) { \
        fprintf(stderr, "[ERROR] %s:%d: %s\n", \
                __FILE__, __LINE__, msg); \
    } \
} while(0)

#define CHECK_NULL(ptr, msg) do { \
    if ((ptr) == NULL) { \
        LOG_ERROR(msg); \
        return NULL; \
    } \
} while(0)

#define CHECK_ERROR(cond, msg) do { \
    if (cond) { \
        LOG_ERROR(msg); \
        return -1; \
    } \
} while(0)

// Example usage
char* allocate_buffer(size_t size) {
    char* buffer = malloc(size);
    CHECK_NULL(buffer, "Memory allocation failed");
    return buffer;
}

int process_data(const char* filename) {
    FILE* file = fopen(filename, "r");
    CHECK_ERROR(!file, "Failed to open file");
    
    char* buffer = allocate_buffer(1024);
    if (!buffer) {
        fclose(file);
        return -1;
    }
    
    // Process data...
    
    free(buffer);
    fclose(file);
    return 0;
}

int main() {
    if (process_data("nonexistent.txt") != 0) {
        printf("Processing failed\n");
        return 1;
    }
    return 0;
} 