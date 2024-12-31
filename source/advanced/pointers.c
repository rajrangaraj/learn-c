#include <stdio.h>

int main() {
    int number = 10;
    int *ptr = &number;

    printf("Value: %d, Address: %p\n", *ptr, ptr);
    return 0;
}
