#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int number;
    char input[100];
    char name[50];
    float price;
    
    // Example 1: Number range validation
    printf("Enter a number between 1 and 10: ");
    if (fgets(input, sizeof(input), stdin) != NULL &&
        sscanf(input, "%d", &number) == 1) {
        
        if (number >= 1 && number <= 10) {
            printf("Valid number: %d\n", number);
        } else {
            printf("Number out of range!\n");
        }
    } else {
        printf("Invalid input! Please enter a number.\n");
    }
    
    // Example 2: String length and character validation
    printf("\nEnter your name (letters only): ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0; // Remove newline
        
        int valid = 1;
        for (int i = 0; input[i]; i++) {
            if (!isalpha(input[i]) && !isspace(input[i])) {
                valid = 0;
                break;
            }
        }
        
        if (valid && strlen(input) > 0 && strlen(input) < 50) {
            strcpy(name, input);
            printf("Valid name: %s\n", name);
        } else {
            printf("Invalid name! Use only letters and spaces.\n");
        }
    }
    
    // Example 3: Positive float validation
    printf("\nEnter a price (positive number): ");
    if (fgets(input, sizeof(input), stdin) != NULL &&
        sscanf(input, "%f", &price) == 1) {
        
        if (price > 0.0) {
            printf("Valid price: $%.2f\n", price);
        } else {
            printf("Price must be positive!\n");
        }
    } else {
        printf("Invalid price format!\n");
    }
    
    return 0;
} 