#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

long get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

int copy_file(const char *source, const char *dest) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        printf("Error: Cannot open source file\n");
        return 1;
    }

    if (file_exists(dest)) {
        printf("Warning: Destination file exists. Overwrite? (y/n): ");
        char response;
        scanf(" %c", &response);
        if (response != 'y' && response != 'Y') {
            fclose(src);
            return 1;
        }
    }

    FILE *dst = fopen(dest, "wb");
    if (!dst) {
        printf("Error: Cannot create destination file\n");
        fclose(src);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    long total_bytes = get_file_size(src);
    long bytes_copied = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes_read, dst);
        bytes_copied += bytes_read;
        float progress = (float)bytes_copied / total_bytes * 100;
        printf("\rProgress: %.1f%%", progress);
    }

    printf("\nFile copied successfully!\n");

    fclose(src);
    fclose(dst);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    return copy_file(argv[1], argv[2]);
} 