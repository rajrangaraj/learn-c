#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "editor.h"
#include "syntax.h"
#include "history.h"

// Auto-indent
void auto_indent(Editor *ed) {
    if (ed->cursor_y > 0) {
        Line *prev = &ed->lines[ed->cursor_y - 1];
        int indent = 0;
        while (indent < prev->length && isspace(prev->text[indent])) {
            indent++;
        }
        
        if (indent > 0) {
            Line *curr = &ed->lines[ed->cursor_y];
            memmove(&curr->text[indent], curr->text, curr->length + 1);
            memcpy(curr->text, prev->text, indent);
            curr->length += indent;
            ed->cursor_x += indent;
        }
    }
}

// Auto-complete brackets
void auto_complete_bracket(Editor *ed, char c) {
    char closing;
    switch (c) {
        case '(': closing = ')'; break;
        case '[': closing = ']'; break;
        case '{': closing = '}'; break;
        case '"': closing = '"'; break;
        case '\'': closing = '\''; break;
        default: return;
    }

    editor_insert_char(ed, c);
    editor_insert_char(ed, closing);
    move_cursor_left(ed);
}

// Word wrap
void word_wrap(Editor *ed, int width) {
    for (int i = 0; i < ed->count; i++) {
        Line *line = &ed->lines[i];
        if (line->length > width) {
            int break_pos = width;
            while (break_pos > 0 && !isspace(line->text[break_pos])) {
                break_pos--;
            }
            
            if (break_pos > 0) {
                ed->cursor_y = i;
                ed->cursor_x = break_pos;
                editor_new_line(ed);
            }
        }
    }
}

// Multiple cursors
typedef struct {
    int x, y;
} Cursor;

void add_cursor(Editor *ed, int x, int y) {
    if (ed->num_cursors < MAX_CURSORS) {
        ed->cursors[ed->num_cursors].x = x;
        ed->cursors[ed->num_cursors].y = y;
        ed->num_cursors++;
    }
}

void remove_cursor(Editor *ed) {
    if (ed->num_cursors > 1) {
        ed->num_cursors--;
    }
}

// Block selection
void start_block_selection(Editor *ed) {
    ed->block_start_x = ed->cursor_x;
    ed->block_start_y = ed->cursor_y;
    ed->block_selecting = 1;
}

void end_block_selection(Editor *ed) {
    ed->block_selecting = 0;
}

void copy_block(Editor *ed) {
    if (!ed->block_selecting) return;
    
    int start_y = ed->block_start_y < ed->cursor_y ? 
                  ed->block_start_y : ed->cursor_y;
    int end_y = ed->block_start_y < ed->cursor_y ? 
                ed->cursor_y : ed->block_start_y;
    
    // Allocate and copy selected text
    // ... implementation details ...
} 