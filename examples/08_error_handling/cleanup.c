#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *file;
    char *buffer;
    size_t size;
} Resource;

Resource* init_resource() {
    Resource *res = malloc(sizeof(Resource));
    if (!res) return NULL;
    
    res->file = NULL;
    res->buffer = NULL;
    res->size = 0;
    
    return res;
}

void cleanup_resource(Resource *res) {
    if (res) {
        if (res->file) fclose(res->file);
        free(res->buffer);
        free(res);
    }
}

int process_resource(const char *filename) {
    Resource *res = init_resource();
    if (!res) {
        fprintf(stderr, "Failed to allocate resource\n");
        return -1;
    }
    
    // Open file
    res->file = fopen(filename, "r");
    if (!res->file) {
        fprintf(stderr, "Failed to open file\n");
        cleanup_resource(res);
        return -1;
    }
    
    // Allocate buffer
    res->buffer = malloc(1024);
    if (!res->buffer) {
        fprintf(stderr, "Failed to allocate buffer\n");
        cleanup_resource(res);
        return -1;
    }
    
    // Process data...
    
    cleanup_resource(res);
    return 0;
}

int main() {
    return process_resource("data.txt");
} 