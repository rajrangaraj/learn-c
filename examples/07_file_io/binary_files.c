#include <stdio.h>

struct Record {
    int id;
    char name[50];
    float score;
};

int main() {
    struct Record records[] = {
        {1, "Alice", 95.5},
        {2, "Bob", 89.0}
    };

    // Write binary data
    FILE *binWrite = fopen("data.bin", "wb");
    if (binWrite != NULL) {
        fwrite(records, sizeof(struct Record), 2, binWrite);
        fclose(binWrite);
    }

    // Read binary data
    FILE *binRead = fopen("data.bin", "rb");
    if (binRead != NULL) {
        struct Record readRec;
        while (fread(&readRec, sizeof(struct Record), 1, binRead)) {
            printf("ID: %d, Name: %s, Score: %.1f\n", 
                   readRec.id, readRec.name, readRec.score);
        }
        fclose(binRead);
    }

    return 0;
} 