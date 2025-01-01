#include <stdio.h>

int main() {
    FILE *file = fopen("numbers.txt", "w+");
    if (file == NULL) return 1;

    // Write some numbers
    fprintf(file, "1 2 3 4 5");
    
    // Move to start of file
    fseek(file, 0, SEEK_SET);
    
    // Read first number
    int num;
    fscanf(file, "%d", &num);
    printf("First number: %d\n", num);
    
    // Get current position
    long pos = ftell(file);
    printf("Current position: %ld\n", pos);
    
    // Move to end and append
    fseek(file, 0, SEEK_END);
    fprintf(file, " 6 7 8");
    
    fclose(file);
    return 0;
} 