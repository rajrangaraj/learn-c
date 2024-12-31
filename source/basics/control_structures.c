#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        printf("Count: %d\n", i);
    }

    int number = 10;
    if (number % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
    return 0;
}
