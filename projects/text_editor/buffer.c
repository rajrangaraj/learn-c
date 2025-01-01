#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

// Read file into editor buffer
int editor_open(Editor *ed, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    // Free existing lines
    for (int i = 0; i < ed->count; i++) {
        free(ed->lines[i].text);
    }
    ed->count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        // Expand buffer if needed
        if (ed->count >= ed->capacity) {
            int new_capacity = ed->capacity * 2;
            Line *new_lines = realloc(ed->lines, new_capacity * sizeof(Line));
            if (!new_lines) {
                fclose(fp);
                return 0;
            }
            ed->lines = new_lines;
            ed->capacity = new_capacity;
        }

        // Allocate and copy line
        ed->lines[ed->count].text = strdup(line);
        if (!ed->lines[ed->count].text) {
            fclose(fp);
            return 0;
        }
        ed->lines[ed->count].length = strlen(line);
        ed->count++;
    }

    // Add empty line if file was empty
    if (ed->count == 0) {
        ed->lines[0].text = malloc(MAX_LINE_LENGTH);
        if (!ed->lines[0].text) {
            fclose(fp);
            return 0;
        }
        ed->lines[0].text[0] = '\0';
        ed->lines[0].length = 0;
        ed->count = 1;
    }

    // Store filename
    free(ed->filename);
    ed->filename = strdup(filename);
    ed->modified = 0;

    fclose(fp);
    return 1;
}

// Save buffer to file
int editor_save(Editor *ed) {
    if (!ed->filename) return 0;

    FILE *fp = fopen(ed->filename, "w");
    if (!fp) return 0;

    for (int i = 0; i < ed->count; i++) {
        fprintf(fp, "%s\n", ed->lines[i].text);
    }

    fclose(fp);
    ed->modified = 0;
    return 1;
}

// Search text in buffer
int editor_find(Editor *ed, const char *search_str) {
    if (!search_str || !search_str[0]) return 0;

    for (int i = ed->cursor_y; i < ed->count; i++) {
        char *found = strstr(ed->lines[i].text, search_str);
        if (found) {
            ed->cursor_y = i;
            ed->cursor_x = found - ed->lines[i].text;
            return 1;
        }
    }

    // Wrap around to beginning
    for (int i = 0; i < ed->cursor_y; i++) {
        char *found = strstr(ed->lines[i].text, search_str);
        if (found) {
            ed->cursor_y = i;
            ed->cursor_x = found - ed->lines[i].text;
            return 1;
        }
    }

    return 0;
} 