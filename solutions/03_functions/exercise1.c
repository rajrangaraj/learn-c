#include <stdio.h>
#include <stdlib.h>

#define HISTORY_SIZE 5

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
int divide(double a, double b, double* result);
int power(double base, int exp, double* result);
int factorial(int n, long* result);
void add_to_history(double result);
void print_history(void);

// Global history array
double history[HISTORY_SIZE] = {0};
int history_count = 0;

// Basic operations
double add(double a, double b) {
    double result = a + b;
    add_to_history(result);
    return result;
}

double subtract(double a, double b) {
    double result = a - b;
    add_to_history(result);
    return result;
}

double multiply(double a, double b) {
    double result = a * b;
    add_to_history(result);
    return result;
}

int divide(double a, double b, double* result) {
    if (b == 0) return 0;
    *result = a / b;
    add_to_history(*result);
    return 1;
}

// Advanced operations
int power(double base, int exp, double* result) {
    if (exp < 0) return 0;
    
    *result = 1;
    for (int i = 0; i < exp; i++) {
        *result *= base;
    }
    add_to_history(*result);
    return 1;
}

int factorial(int n, long* result) {
    if (n < 0) return 0;
    
    *result = 1;
    for (int i = 2; i <= n; i++) {
        *result *= i;
    }
    add_to_history(*result);
    return 1;
}

// History management
void add_to_history(double result) {
    for (int i = HISTORY_SIZE - 1; i > 0; i--) {
        history[i] = history[i-1];
    }
    history[0] = result;
    if (history_count < HISTORY_SIZE) history_count++;
}

void print_history(void) {
    printf("\nLast %d results:\n", history_count);
    for (int i = 0; i < history_count; i++) {
        printf("%d: %.2f\n", i+1, history[i]);
    }
}

int main() {
    double result;
    
    // Test calculator functions
    printf("2 + 3 = %.2f\n", add(2, 3));
    printf("5 - 3 = %.2f\n", subtract(5, 3));
    printf("4 * 3 = %.2f\n", multiply(4, 3));
    
    if (divide(10, 2, &result)) {
        printf("10 / 2 = %.2f\n", result);
    }
    
    if (power(2, 3, &result)) {
        printf("2^3 = %.2f\n", result);
    }
    
    long fact_result;
    if (factorial(5, &fact_result)) {
        printf("5! = %ld\n", fact_result);
    }
    
    print_history();
    return 0;
} 