#include <stdio.h>

int main() {
    // Append mode
    FILE *append = fopen("log.txt", "a");
    if (append != NULL) {
        fprintf(append, "New log entry\n");
        fclose(append);
    }

    // Update mode (r+)
    FILE *update = fopen("data.txt", "r+");
    if (update != NULL) {
        // Overwrite first character
        fputc('X', update);
        
        // Move to end without overwriting
        fseek(update, 0, SEEK_END);
        fprintf(update, "\nAdded at end");
        
        fclose(update);
    }

    return 0;
} 