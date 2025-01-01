#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char play_again;
    
    do {
        int target = rand() % 100 + 1;
        int guess, attempts = 0;
        
        printf("\nI'm thinking of a number between 1 and 100\n");
        
        while (1) {
            printf("Enter your guess: ");
            if (scanf("%d", &guess) != 1) {
                printf("Please enter a valid number!\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            
            attempts++;
            
            if (guess < target) {
                printf("Higher!\n");
            } else if (guess > target) {
                printf("Lower!\n");
            } else {
                printf("Correct! You took %d attempts\n", attempts);
                break;
            }
        }
        
        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
        
    } while (play_again == 'y' || play_again == 'Y');
    
    return 0;
} 