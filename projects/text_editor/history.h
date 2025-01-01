#ifndef HISTORY_H
#define HISTORY_H

#include "editor.h"

#define MAX_HISTORY 100

typedef enum {
    ACTION_INSERT,
    ACTION_DELETE,
    ACTION_NEWLINE
} ActionType;

typedef struct {
    ActionType type;
    int x, y;
    char *text;
} Action;

typedef struct {
    Action *actions;
    int count;
    int current;
} History;

void history_init(Editor *ed);
void history_free(Editor *ed);
void history_add(Editor *ed, ActionType type, int x, int y, const char *text);
void history_undo(Editor *ed);
void history_redo(Editor *ed);

#endif 