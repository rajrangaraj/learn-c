#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "todo.h"

TodoList* init_todo_list(int initial_capacity) {
    TodoList *list = malloc(sizeof(TodoList));
    if (!list) return NULL;

    list->tasks = malloc(initial_capacity * sizeof(Task));
    if (!list->tasks) {
        free(list);
        return NULL;
    }

    list->count = 0;
    list->capacity = initial_capacity;
    return list;
}

void free_todo_list(TodoList *list) {
    if (list) {
        free(list->tasks);
        free(list);
    }
}

int add_task(TodoList *list, const char *title, const char *desc, 
             int priority, time_t due_date) {
    if (list->count >= list->capacity) {
        int new_capacity = list->capacity * 2;
        Task *new_tasks = realloc(list->tasks, new_capacity * sizeof(Task));
        if (!new_tasks) return 0;
        
        list->tasks = new_tasks;
        list->capacity = new_capacity;
    }

    Task *task = &list->tasks[list->count];
    task->id = list->count + 1;
    strncpy(task->title, title, MAX_TITLE - 1);
    strncpy(task->description, desc, MAX_DESC - 1);
    task->priority = priority;
    task->due_date = due_date;
    task->completed = 0;

    list->count++;
    return task->id;
}

int remove_task(TodoList *list, int id) {
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            // Shift remaining tasks
            for (int j = i; j < list->count - 1; j++) {
                list->tasks[j] = list->tasks[j + 1];
            }
            list->count--;
            return 1;
        }
    }
    return 0;
}

int complete_task(TodoList *list, int id) {
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            list->tasks[i].completed = 1;
            return 1;
        }
    }
    return 0;
}

void list_tasks(TodoList *list) {
    printf("\nTasks:\n");
    printf("ID  Pri  Done  Due Date    Title\n");
    printf("----------------------------------\n");

    for (int i = 0; i < list->count; i++) {
        Task *task = &list->tasks[i];
        char date_str[11];
        strftime(date_str, sizeof(date_str), "%Y-%m-%d", 
                localtime(&task->due_date));
        
        printf("%2d  %3d  %s  %s  %s\n",
               task->id,
               task->priority,
               task->completed ? "[X]" : "[ ]",
               date_str,
               task->title);
    }
    printf("\n");
}

int main() {
    TodoList *list = init_todo_list(10);
    if (!list) {
        fprintf(stderr, "Failed to initialize todo list\n");
        return 1;
    }

    // Load existing tasks
    if (!load_tasks(list, FILENAME)) {
        printf("No existing tasks found.\n");
    }

    char command;
    while (1) {
        printf("\nTodo List Manager\n");
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. Complete task\n");
        printf("4. List tasks\n");
        printf("5. Save and quit\n");
        printf("Choice: ");

        scanf(" %c", &command);
        getchar(); // Clear newline

        switch (command) {
            case '1': {
                char title[MAX_TITLE];
                char desc[MAX_DESC];
                int priority;
                
                printf("Title: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0;
                
                printf("Description: ");
                fgets(desc, MAX_DESC, stdin);
                desc[strcspn(desc, "\n")] = 0;
                
                printf("Priority (1-3): ");
                scanf("%d", &priority);
                
                time_t now = time(NULL);
                add_task(list, title, desc, priority, now);
                break;
            }
            case '2': {
                int id;
                printf("Task ID: ");
                scanf("%d", &id);
                if (!remove_task(list, id)) {
                    printf("Task not found.\n");
                }
                break;
            }
            case '3': {
                int id;
                printf("Task ID: ");
                scanf("%d", &id);
                if (!complete_task(list, id)) {
                    printf("Task not found.\n");
                }
                break;
            }
            case '4':
                list_tasks(list);
                break;
            case '5':
                save_tasks(list, FILENAME);
                free_todo_list(list);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
} 