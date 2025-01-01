#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nCaught SIGINT (Ctrl+C)\n");
            exit(1);
            break;
        case SIGSEGV:
            printf("\nCaught SIGSEGV (Segmentation fault)\n");
            exit(1);
            break;
        case SIGFPE:
            printf("\nCaught SIGFPE (Floating point exception)\n");
            exit(1);
            break;
    }
}

int main() {
    // Register signal handlers
    signal(SIGINT, signal_handler);
    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);

    printf("Program running. Try Ctrl+C...\n");
    
    // Infinite loop to keep program running
    while(1) {
        sleep(1);
    }

    return 0;
} 