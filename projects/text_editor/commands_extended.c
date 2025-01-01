#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"
#include "syntax.h"
#include "history.h"

// Extended commands
void process_extended_command(Editor *ed, char *cmd) {
    if (strcmp(cmd, "q") == 0) {
        if (!ed->modified || editor_save(ed)) {
            exit(0);
        }
    } else if (strcmp(cmd, "w") == 0) {
        editor_save(ed);
    } else if (strncmp(cmd, "find ", 5) == 0) {
        editor_find(ed, cmd + 5);
    } else if (strcmp(cmd, "undo") == 0) {
        history_undo(ed);
    } else if (strcmp(cmd, "redo") == 0) {
        history_redo(ed);
    } else if (strncmp(cmd, "syntax ", 7) == 0) {
        ed->syntax_rule = get_syntax_rule(cmd + 7);
    } else if (strcmp(cmd, "line") == 0) {
        ed->show_line_numbers = !ed->show_line_numbers;
    } else if (strncmp(cmd, "tab ", 4) == 0) {
        ed->tab_size = atoi(cmd + 4);
    } else if (strcmp(cmd, "help") == 0) {
        display_help(ed);
    }
}

// Help screen
void display_help(Editor *ed) {
    static const char *help_text[] = {
        "Editor Commands:",
        "-------------",
        "Ctrl+S - Save file",
        "Ctrl+Q - Quit",
        "Ctrl+F - Find text",
        "Ctrl+Z - Undo",
        "Ctrl+Y - Redo",
        "",
        "Command Mode (':'):",
        "w    - Write file",
        "q    - Quit",
        "find <text> - Search text",
        "syntax <language> - Set syntax highlighting",
        "line - Toggle line numbers",
        "tab <size> - Set tab size",
        "help - Show this help",
        NULL
    };

    editor_clear_screen();
    for (const char **p = help_text; *p; p++) {
        printf("%s\n", *p);
    }
    printf("\nPress any key to continue...");
    getchar();
} 