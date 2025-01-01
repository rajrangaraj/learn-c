#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("nonexistent.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        if (feof(file)) {
            printf("End of file reached\n");
        } else if (ferror(file)) {
            printf("Error reading file: %s\n", strerror(errno));
        }
    }

    fclose(file);
    return 0;
} 