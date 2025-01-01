#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

// Move cursor left
void move_cursor_left(Editor *ed) {
    if (ed->cursor_x > 0) {
        ed->cursor_x--;
    } else if (ed->cursor_y > 0) {
        ed->cursor_y--;
        ed->cursor_x = ed->lines[ed->cursor_y].length;
    }
}

// Move cursor right
void move_cursor_right(Editor *ed) {
    Line *line = &ed->lines[ed->cursor_y];
    if (ed->cursor_x < line->length) {
        ed->cursor_x++;
    } else if (ed->cursor_y < ed->count - 1) {
        ed->cursor_y++;
        ed->cursor_x = 0;
    }
}

// Move cursor up
void move_cursor_up(Editor *ed) {
    if (ed->cursor_y > 0) {
        ed->cursor_y--;
        Line *line = &ed->lines[ed->cursor_y];
        if (ed->cursor_x > line->length) {
            ed->cursor_x = line->length;
        }
    }
}

// Move cursor down
void move_cursor_down(Editor *ed) {
    if (ed->cursor_y < ed->count - 1) {
        ed->cursor_y++;
        Line *line = &ed->lines[ed->cursor_y];
        if (ed->cursor_x > line->length) {
            ed->cursor_x = line->length;
        }
    }
}

// Clear screen and display buffer
void editor_refresh_screen(Editor *ed) {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
#endif

    // Display line numbers and content
    for (int i = 0; i < ed->count; i++) {
        printf("%3d │ ", i + 1);
        if (i == ed->cursor_y) {
            // Print line with cursor
            Line *line = &ed->lines[i];
            for (int j = 0; j < line->length; j++) {
                if (j == ed->cursor_x) {
                    printf("\033[7m%c\033[m", line->text[j]);
                } else {
                    putchar(line->text[j]);
                }
            }
            if (ed->cursor_x == line->length) {
                printf("\033[7m \033[m");
            }
        } else {
            printf("%s", ed->lines[i].text);
        }
        printf("\n");
    }

    // Display status line
    printf("\n─────────────────────────────\n");
    printf("%s%s | %d lines | Cursor: %d,%d", 
           ed->filename ? ed->filename : "New File",
           ed->modified ? " [Modified]" : "",
           ed->count,
           ed->cursor_y + 1,
           ed->cursor_x + 1);
}

// Display status message
void editor_status_message(Editor *ed, const char *msg) {
    printf("\n%s", msg);
}

// Process command mode
void process_command(Editor *ed, char *cmd) {
    if (strcmp(cmd, "q") == 0) {
        if (!ed->modified || editor_save(ed)) {
            exit(0);
        }
    } else if (strcmp(cmd, "w") == 0) {
        editor_save(ed);
    } else if (strncmp(cmd, "find ", 5) == 0) {
        editor_find(ed, cmd + 5);
    }
} 