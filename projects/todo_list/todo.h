#ifndef TODO_H
#define TODO_H

#include <time.h>

#define MAX_TITLE 100
#define MAX_DESC 256
#define FILENAME "tasks.dat"

typedef struct {
    int id;
    char title[MAX_TITLE];
    char description[MAX_DESC];
    int priority;  // 1 (High) to 3 (Low)
    time_t due_date;
    int completed;
} Task;

typedef struct {
    Task *tasks;
    int count;
    int capacity;
} TodoList;

// Core functions
TodoList* init_todo_list(int initial_capacity);
void free_todo_list(TodoList *list);
int add_task(TodoList *list, const char *title, const char *desc, int priority, time_t due_date);
int remove_task(TodoList *list, int id);
int complete_task(TodoList *list, int id);
void list_tasks(TodoList *list);

// File operations
int save_tasks(TodoList *list, const char *filename);
int load_tasks(TodoList *list, const char *filename);

#endif 