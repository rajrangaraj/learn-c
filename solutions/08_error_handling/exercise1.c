#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>

#define MAX_PATH 256
#define MAX_ERROR 1024

typedef struct {
    FILE *file;
    char timestamp[26];
    char filepath[MAX_PATH];
} ErrorLog;

typedef struct {
    char message[MAX_ERROR];
    int code;
    char timestamp[26];
} Error;

// Function prototypes
ErrorLog* init_error_log(const char *logpath);
void log_error(ErrorLog *log, const char *message, int error_code);
void close_error_log(ErrorLog *log);
int process_file(const char *filepath, ErrorLog *log);
int process_directory(const char *dirpath, ErrorLog *log);
char* get_timestamp(void);

// Initialize error log
ErrorLog* init_error_log(const char *logpath) {
    ErrorLog *log = malloc(sizeof(ErrorLog));
    if (!log) return NULL;

    log->file = fopen(logpath, "a");
    if (!log->file) {
        free(log);
        return NULL;
    }

    strncpy(log->filepath, logpath, MAX_PATH - 1);
    return log;
}

// Get current timestamp
char* get_timestamp(void) {
    static char buffer[26];
    time_t timer = time(NULL);
    struct tm* tm_info = localtime(&timer);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}

// Log error with timestamp
void log_error(ErrorLog *log, const char *message, int error_code) {
    if (!log || !log->file) return;

    fprintf(log->file, "[%s] Error %d: %s - %s\n",
            get_timestamp(), error_code, message,
            error_code ? strerror(error_code) : "");
    fflush(log->file);
}

// Process single file
int process_file(const char *filepath, ErrorLog *log) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        log_error(log, filepath, errno);
        return -1;
    }

    // Allocate buffer for file processing
    char *buffer = malloc(1024);
    if (!buffer) {
        log_error(log, "Memory allocation failed", errno);
        fclose(file);
        return -1;
    }

    // Process file content
    int status = 0;
    while (fgets(buffer, 1024, file)) {
        // Example validation: check for empty lines
        if (strlen(buffer) <= 1) {
            log_error(log, "Empty line found", 0);
            continue;
        }

        // Process valid line...
    }

    // Cleanup
    free(buffer);
    fclose(file);
    return status;
}

// Process directory
int process_directory(const char *dirpath, ErrorLog *log) {
    DIR *dir = opendir(dirpath);
    if (!dir) {
        log_error(log, "Failed to open directory", errno);
        return -1;
    }

    struct dirent *entry;
    int error_count = 0;
    char filepath[MAX_PATH];

    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 || 
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full file path
        snprintf(filepath, MAX_PATH, "%s/%s", dirpath, entry->d_name);

        // Process file
        if (process_file(filepath, log) < 0) {
            error_count++;
            log_error(log, "Failed to process file", errno);
            continue;  // Continue with next file despite error
        }
    }

    closedir(dir);
    return error_count;
}

// Close error log
void close_error_log(ErrorLog *log) {
    if (log) {
        if (log->file) {
            fclose(log->file);
        }
        free(log);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Initialize error log
    ErrorLog *log = init_error_log("error.log");
    if (!log) {
        fprintf(stderr, "Failed to initialize error log\n");
        return 1;
    }

    // Process directory
    int result = process_directory(argv[1], log);
    
    // Report results
    if (result < 0) {
        printf("Directory processing failed\n");
    } else if (result > 0) {
        printf("Processed with %d errors\n", result);
    } else {
        printf("Processing completed successfully\n");
    }

    // Cleanup
    close_error_log(log);
    return result < 0 ? 1 : 0;
} 