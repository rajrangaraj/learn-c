#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file) {
        fprintf(file, "This is a sample text file.\n");
        fclose(file);
    }
    return 0;
}
