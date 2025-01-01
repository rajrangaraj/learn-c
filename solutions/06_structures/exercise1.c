#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_GRADES 5

typedef struct {
    int id;
    char name[MAX_NAME];
    float grades[MAX_GRADES];
    float average;
} Student;

typedef struct {
    Student *students;
    int capacity;
    int size;
} Database;

// Function prototypes
Database* create_database(int capacity);
void free_database(Database *db);
int add_student(Database *db, int id, const char *name);
int remove_student(Database *db, int id);
int update_grades(Database *db, int id, float *grades);
void sort_by_average(Database *db);
Student* search_by_id(Database *db, int id);
Student* search_by_name(Database *db, const char *name);

// Create database
Database* create_database(int capacity) {
    Database *db = malloc(sizeof(Database));
    if (!db) return NULL;
    
    db->students = malloc(capacity * sizeof(Student));
    if (!db->students) {
        free(db);
        return NULL;
    }
    
    db->capacity = capacity;
    db->size = 0;
    return db;
}

// Free database
void free_database(Database *db) {
    if (db) {
        free(db->students);
        free(db);
    }
}

// Add student
int add_student(Database *db, int id, const char *name) {
    if (db->size >= db->capacity) return 0;
    
    Student *s = &db->students[db->size];
    s->id = id;
    strncpy(s->name, name, MAX_NAME - 1);
    s->name[MAX_NAME - 1] = '\0';
    
    for (int i = 0; i < MAX_GRADES; i++) {
        s->grades[i] = 0.0f;
    }
    s->average = 0.0f;
    
    db->size++;
    return 1;
}

// Update grades and average
int update_grades(Database *db, int id, float *grades) {
    Student *s = search_by_id(db, id);
    if (!s) return 0;
    
    float sum = 0;
    for (int i = 0; i < MAX_GRADES; i++) {
        s->grades[i] = grades[i];
        sum += grades[i];
    }
    s->average = sum / MAX_GRADES;
    return 1;
}

// Sort by average grade
void sort_by_average(Database *db) {
    for (int i = 0; i < db->size - 1; i++) {
        for (int j = 0; j < db->size - i - 1; j++) {
            if (db->students[j].average < db->students[j + 1].average) {
                Student temp = db->students[j];
                db->students[j] = db->students[j + 1];
                db->students[j + 1] = temp;
            }
        }
    }
}

// Search functions
Student* search_by_id(Database *db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->students[i].id == id) {
            return &db->students[i];
        }
    }
    return NULL;
}

Student* search_by_name(Database *db, const char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->students[i].name, name) == 0) {
            return &db->students[i];
        }
    }
    return NULL;
}

int main() {
    Database *db = create_database(100);
    if (!db) return 1;
    
    // Add students
    add_student(db, 1, "Alice");
    add_student(db, 2, "Bob");
    
    // Update grades
    float grades1[] = {85, 90, 92, 88, 95};
    float grades2[] = {78, 82, 85, 80, 88};
    
    update_grades(db, 1, grades1);
    update_grades(db, 2, grades2);
    
    // Sort and print
    sort_by_average(db);
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d, Name: %s, Average: %.2f\n",
               db->students[i].id,
               db->students[i].name,
               db->students[i].average);
    }
    
    free_database(db);
    return 0;
} 