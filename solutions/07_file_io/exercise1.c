#include <stdio.h>

int main() {
    // Writing to file
    FILE *writeFile = fopen("students.txt", "w");
    if (writeFile == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    fprintf(writeFile, "Alice,20\n");
    fprintf(writeFile, "Bob,22\n");
    fprintf(writeFile, "Charlie,21\n");
    fclose(writeFile);

    // Reading from file
    FILE *readFile = fopen("students.txt", "r");
    if (readFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), readFile)) {
        printf("Record: %s", line);
    }

    fclose(readFile);
    return 0;
} 