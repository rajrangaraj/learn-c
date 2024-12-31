#include <stdio.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("Number at index %d: %d\n", i, numbers[i]);
    }
    return 0;
}
