#ifndef EDITOR_H
#define EDITOR_H

#define MAX_LINE_LENGTH 1024
#define INITIAL_CAPACITY 100

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int count;
    int capacity;
    int cursor_x;
    int cursor_y;
    char *filename;
    int modified;
} Editor;

// Editor operations
Editor* editor_init(void);
void editor_free(Editor *ed);
int editor_open(Editor *ed, const char *filename);
int editor_save(Editor *ed);
void editor_insert_char(Editor *ed, char c);
void editor_delete_char(Editor *ed);
void editor_new_line(Editor *ed);

// Cursor movement
void move_cursor_left(Editor *ed);
void move_cursor_right(Editor *ed);
void move_cursor_up(Editor *ed);
void move_cursor_down(Editor *ed);

// Display
void editor_refresh_screen(Editor *ed);
void editor_status_message(Editor *ed, const char *msg);

// Search
int editor_find(Editor *ed, const char *search_str);

#endif 