#include <stdio.h>

int main() {
    // For loop
    printf("Counting up:\n");
    for (int i = 1; i <= 3; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // While loop
    printf("Counting down:\n");
    int count = 3;
    while (count > 0) {
        printf("%d ", count);
        count--;
    }
    printf("\n");

    // Do-while loop
    int num = 1;
    do {
        printf("This runs at least once: %d\n", num);
    } while (num < 1);

    return 0;
} 