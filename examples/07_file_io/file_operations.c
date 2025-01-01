#include <stdio.h>

int main() {
    // Writing to a file
    FILE *writeFile = fopen("test.txt", "w");
    if (writeFile != NULL) {
        fprintf(writeFile, "Hello, File I/O!\n");
        fclose(writeFile);
    }

    // Reading from a file
    FILE *readFile = fopen("test.txt", "r");
    if (readFile != NULL) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), readFile)) {
            printf("Read: %s", buffer);
        }
        fclose(readFile);
    }

    return 0;
} 