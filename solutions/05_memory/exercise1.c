#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_strings(char **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // Clear newline

    // Allocate array of string pointers
    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) return 1;

    // Get strings from user
    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(100 * sizeof(char));
        if (strings[i] == NULL) {
            // Clean up previous allocations
            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            return 1;
        }
        printf("Enter string %d: ", i + 1);
        fgets(strings[i], 100, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0; // Remove newline
    }

    // Sort and print
    sort_strings(strings, n);
    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
} 