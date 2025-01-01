#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    // Attempt to open non-existent file
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        // Print error details
        printf("Error code (errno): %d\n", errno);
        printf("Error message (perror): ");
        perror("");
        printf("Error message (strerror): %s\n", strerror(errno));
        return 1;
    }
    
    fclose(file);
    return 0;
} 