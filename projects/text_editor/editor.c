#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "editor.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

// Initialize editor
Editor* editor_init(void) {
    Editor *ed = malloc(sizeof(Editor));
    if (!ed) return NULL;

    ed->lines = malloc(INITIAL_CAPACITY * sizeof(Line));
    if (!ed->lines) {
        free(ed);
        return NULL;
    }

    ed->count = 0;
    ed->capacity = INITIAL_CAPACITY;
    ed->cursor_x = 0;
    ed->cursor_y = 0;
    ed->filename = NULL;
    ed->modified = 0;

    // Add empty line
    ed->lines[0].text = malloc(MAX_LINE_LENGTH);
    if (!ed->lines[0].text) {
        free(ed->lines);
        free(ed);
        return NULL;
    }
    ed->lines[0].text[0] = '\0';
    ed->lines[0].length = 0;
    ed->count = 1;

    return ed;
}

// Free editor memory
void editor_free(Editor *ed) {
    if (!ed) return;

    for (int i = 0; i < ed->count; i++) {
        free(ed->lines[i].text);
    }
    free(ed->lines);
    free(ed->filename);
    free(ed);
}

// Insert character at cursor
void editor_insert_char(Editor *ed, char c) {
    Line *line = &ed->lines[ed->cursor_y];
    
    if (line->length >= MAX_LINE_LENGTH - 1) return;

    // Make space for new character
    memmove(&line->text[ed->cursor_x + 1],
            &line->text[ed->cursor_x],
            line->length - ed->cursor_x);
    
    line->text[ed->cursor_x] = c;
    line->length++;
    ed->cursor_x++;
    ed->modified = 1;
}

// Delete character at cursor
void editor_delete_char(Editor *ed) {
    Line *line = &ed->lines[ed->cursor_y];
    
    if (ed->cursor_x == 0 && ed->cursor_y == 0) return;

    if (ed->cursor_x > 0) {
        memmove(&line->text[ed->cursor_x - 1],
                &line->text[ed->cursor_x],
                line->length - ed->cursor_x);
        ed->cursor_x--;
        line->length--;
        ed->modified = 1;
    } else if (ed->cursor_y > 0) {
        // Merge with previous line
        Line *prev = &ed->lines[ed->cursor_y - 1];
        int old_length = prev->length;
        
        strncat(prev->text, line->text, 
                MAX_LINE_LENGTH - prev->length - 1);
        
        // Remove current line
        free(line->text);
        memmove(&ed->lines[ed->cursor_y],
                &ed->lines[ed->cursor_y + 1],
                (ed->count - ed->cursor_y - 1) * sizeof(Line));
        
        ed->count--;
        ed->cursor_y--;
        ed->cursor_x = old_length;
        ed->modified = 1;
    }
}

// Create new line at cursor
void editor_new_line(Editor *ed) {
    if (ed->count >= ed->capacity) {
        int new_capacity = ed->capacity * 2;
        Line *new_lines = realloc(ed->lines, 
                                 new_capacity * sizeof(Line));
        if (!new_lines) return;
        
        ed->lines = new_lines;
        ed->capacity = new_capacity;
    }

    // Make space for new line
    memmove(&ed->lines[ed->cursor_y + 2],
            &ed->lines[ed->cursor_y + 1],
            (ed->count - ed->cursor_y - 1) * sizeof(Line));

    // Create new line
    ed->lines[ed->cursor_y + 1].text = malloc(MAX_LINE_LENGTH);
    if (!ed->lines[ed->cursor_y + 1].text) return;

    // Split current line
    Line *curr = &ed->lines[ed->cursor_y];
    Line *next = &ed->lines[ed->cursor_y + 1];
    
    strncpy(next->text, &curr->text[ed->cursor_x],
            MAX_LINE_LENGTH - 1);
    curr->text[ed->cursor_x] = '\0';
    
    next->length = strlen(next->text);
    curr->length = ed->cursor_x;

    ed->count++;
    ed->cursor_y++;
    ed->cursor_x = 0;
    ed->modified = 1;
}

// Main editor loop
int main(int argc, char *argv[]) {
    Editor *ed = editor_init();
    if (!ed) {
        fprintf(stderr, "Failed to initialize editor\n");
        return 1;
    }

    // Open file if specified
    if (argc > 1) {
        if (!editor_open(ed, argv[1])) {
            editor_free(ed);
            return 1;
        }
    }

    while (1) {
        editor_refresh_screen(ed);
        
        int c = getchar();
        if (c == EOF) break;

        switch (c) {
            case '\r':
            case '\n':
                editor_new_line(ed);
                break;
            case 127: // Backspace
            case '\b':
                editor_delete_char(ed);
                break;
            case 17: // Ctrl+Q
                if (!ed->modified || 
                    editor_save(ed)) {
                    editor_free(ed);
                    return 0;
                }
                break;
            case 19: // Ctrl+S
                editor_save(ed);
                break;
            default:
                if (!iscntrl(c)) {
                    editor_insert_char(ed, c);
                }
        }
    }

    editor_free(ed);
    return 0;
} 