#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    int code;
    char message[256];
    char timestamp[26];
} Error;

void init_error(Error *err) {
    err->code = 0;
    err->message[0] = '\0';
    err->timestamp[0] = '\0';
}

void set_error(Error *err, int code, const char *msg) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    
    err->code = code;
    strncpy(err->message, msg, 255);
    strftime(err->timestamp, 26, "%Y-%m-%d %H:%M:%S", tm_info);
}

int divide_numbers(int a, int b, int *result, Error *err) {
    if (b == 0) {
        set_error(err, 1, "Division by zero");
        return 0;
    }
    
    *result = a / b;
    return 1;
}

int main() {
    Error err;
    init_error(&err);
    
    int result;
    if (!divide_numbers(10, 0, &result, &err)) {
        printf("Error %d at %s: %s\n", 
               err.code, err.timestamp, err.message);
        return 1;
    }
    
    printf("Result: %d\n", result);
    return 0;
} 