#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELD 256
#define MAX_COLUMNS 50

typedef struct {
    char **headers;
    char ***data;
    int rows;
    int cols;
} CSV;

// Function prototypes
CSV* create_csv(void);
void free_csv(CSV *csv);
int parse_line(char *line, char **fields, int max_fields);
CSV* read_csv(const char *filename);
int write_csv(const char *filename, CSV *csv);
void print_csv(CSV *csv);

// Create CSV structure
CSV* create_csv(void) {
    CSV *csv = malloc(sizeof(CSV));
    if (!csv) return NULL;
    
    csv->headers = NULL;
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    
    return csv;
}

// Parse a single CSV line
int parse_line(char *line, char **fields, int max_fields) {
    int field_count = 0;
    char *p = line;
    char *field = malloc(MAX_FIELD);
    int in_quotes = 0;
    int field_pos = 0;
    
    while (*p && field_count < max_fields) {
        if (*p == '"') {
            in_quotes = !in_quotes;
        } else if (*p == ',' && !in_quotes) {
            field[field_pos] = '\0';
            fields[field_count] = strdup(field);
            field_count++;
            field_pos = 0;
        } else {
            field[field_pos++] = *p;
        }
        p++;
    }
    
    // Handle last field
    if (field_pos > 0) {
        field[field_pos] = '\0';
        fields[field_count] = strdup(field);
        field_count++;
    }
    
    free(field);
    return field_count;
}

// Read CSV file
CSV* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;
    
    CSV *csv = create_csv();
    if (!csv) {
        fclose(file);
        return NULL;
    }
    
    char line[MAX_LINE];
    char **fields = malloc(MAX_COLUMNS * sizeof(char*));
    
    // Read headers
    if (fgets(line, MAX_LINE, file)) {
        line[strcspn(line, "\n\r")] = 0;  // Remove newline
        csv->cols = parse_line(line, fields, MAX_COLUMNS);
        csv->headers = fields;
        
        // Prepare for data
        csv->data = NULL;
        csv->rows = 0;
        
        // Read data rows
        while (fgets(line, MAX_LINE, file)) {
            line[strcspn(line, "\n\r")] = 0;
            
            // Reallocate data array
            csv->data = realloc(csv->data, (csv->rows + 1) * sizeof(char**));
            csv->data[csv->rows] = malloc(csv->cols * sizeof(char*));
            
            // Parse row
            fields = malloc(MAX_COLUMNS * sizeof(char*));
            int fields_count = parse_line(line, fields, csv->cols);
            
            // Copy fields
            for (int i = 0; i < csv->cols; i++) {
                csv->data[csv->rows][i] = i < fields_count ? fields[i] : strdup("");
            }
            
            free(fields);
            csv->rows++;
        }
    }
    
    fclose(file);
    return csv;
}

// Write CSV to file
int write_csv(const char *filename, CSV *csv) {
    FILE *file = fopen(filename, "w");
    if (!file) return 0;
    
    // Write headers
    for (int i = 0; i < csv->cols; i++) {
        fprintf(file, "%s%s", csv->headers[i], 
                (i < csv->cols - 1) ? "," : "\n");
    }
    
    // Write data
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            // Check if field needs quotes
            if (strchr(csv->data[i][j], ',')) {
                fprintf(file, "\"%s\"%s", csv->data[i][j],
                        (j < csv->cols - 1) ? "," : "\n");
            } else {
                fprintf(file, "%s%s", csv->data[i][j],
                        (j < csv->cols - 1) ? "," : "\n");
            }
        }
    }
    
    fclose(file);
    return 1;
}

// Free CSV structure
void free_csv(CSV *csv) {
    if (!csv) return;
    
    // Free headers
    for (int i = 0; i < csv->cols; i++) {
        free(csv->headers[i]);
    }
    free(csv->headers);
    
    // Free data
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    
    free(csv);
}

int main() {
    // Create test CSV file
    FILE *test = fopen("test.csv", "w");
    fprintf(test, "Name,Age,City\n");
    fprintf(test, "John Doe,30,\"New York, NY\"\n");
    fprintf(test, "Jane Smith,25,Boston\n");
    fclose(test);
    
    // Read and process CSV
    CSV *csv = read_csv("test.csv");
    if (csv) {
        printf("CSV loaded with %d rows and %d columns\n", 
               csv->rows, csv->cols);
        
        // Write to new file
        write_csv("output.csv", csv);
        
        free_csv(csv);
    }
    
    return 0;
}