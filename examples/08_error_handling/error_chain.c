#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_CHAIN 5

typedef struct ErrorNode {
    char message[256];
    int code;
    struct ErrorNode* next;
} ErrorNode;

typedef struct {
    ErrorNode* head;
    int count;
} ErrorChain;

// Initialize error chain
ErrorChain* create_error_chain() {
    ErrorChain* chain = malloc(sizeof(ErrorChain));
    if (chain) {
        chain->head = NULL;
        chain->count = 0;
    }
    return chain;
}

// Add error to chain
void add_error(ErrorChain* chain, const char* msg, int code) {
    if (chain->count >= MAX_ERROR_CHAIN) return;

    ErrorNode* node = malloc(sizeof(ErrorNode));
    if (!node) return;

    strncpy(node->message, msg, 255);
    node->code = code;
    node->next = chain->head;
    chain->head = node;
    chain->count++;
}

// Print error chain
void print_error_chain(ErrorChain* chain) {
    printf("Error chain:\n");
    ErrorNode* current = chain->head;
    while (current) {
        printf("Code %d: %s\n", current->code, current->message);
        current = current->next;
    }
}

// Free error chain
void free_error_chain(ErrorChain* chain) {
    ErrorNode* current = chain->head;
    while (current) {
        ErrorNode* next = current->next;
        free(current);
        current = next;
    }
    free(chain);
}

// Example usage
int process_with_chain(ErrorChain* chain) {
    FILE* file = fopen("nonexistent.txt", "r");
    if (!file) {
        add_error(chain, "Failed to open file", 1);
        return -1;
    }

    char* buffer = malloc(1024);
    if (!buffer) {
        add_error(chain, "Memory allocation failed", 2);
        fclose(file);
        return -1;
    }

    // Process data...

    free(buffer);
    fclose(file);
    return 0;
}

int main() {
    ErrorChain* chain = create_error_chain();
    if (!chain) return 1;

    if (process_with_chain(chain) != 0) {
        print_error_chain(chain);
    }

    free_error_chain(chain);
    return 0;
} 