#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "course.h"
#include "database.h"

StudentDB* init_student_db(int initial_capacity) {
    StudentDB *db = malloc(sizeof(StudentDB));
    if (!db) return NULL;

    db->students = malloc(initial_capacity * sizeof(Student));
    if (!db->students) {
        free(db);
        return NULL;
    }

    db->count = 0;
    db->capacity = initial_capacity;
    return db;
}

void free_student_db(StudentDB *db) {
    if (db) {
        free(db->students);
        free(db);
    }
}

int add_student(StudentDB *db, Student student) {
    if (db->count >= db->capacity) {
        int new_capacity = db->capacity * 2;
        Student *new_students = realloc(db->students, 
                                      new_capacity * sizeof(Student));
        if (!new_students) return 0;
        
        db->students = new_students;
        db->capacity = new_capacity;
    }

    // Generate unique ID
    student.id = db->count + 1001;  // Start IDs at 1001
    student.active = 1;
    student.course_count = 0;
    student.gpa = 0.0;

    db->students[db->count] = student;
    db->count++;

    // Save to persistent storage
    save_student_to_db(&student);
    
    return student.id;
}

int update_student(StudentDB *db, Student student) {
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].id == student.id) {
            // Preserve some fields
            student.course_count = db->students[i].course_count;
            memcpy(student.course_ids, 
                   db->students[i].course_ids,
                   sizeof(int) * MAX_COURSES);
            
            db->students[i] = student;
            
            // Update in persistent storage
            update_student_in_db(&student);
            return 1;
        }
    }
    return 0;
}

int delete_student(StudentDB *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].id == id) {
            // Soft delete
            db->students[i].active = 0;
            
            // Update in persistent storage
            delete_student_from_db(id);
            return 1;
        }
    }
    return 0;
}

Student* find_student(StudentDB *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->students[i].id == id && db->students[i].active) {
            return &db->students[i];
        }
    }
    return NULL;
}

void list_students(StudentDB *db) {
    printf("\nStudent List:\n");
    printf("ID    Name                  Email                 GPA  Courses\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < db->count; i++) {
        Student *s = &db->students[i];
        if (!s->active) continue;

        printf("%-5d %-20s %-20s %.2f  %d\n",
               s->id,
               s->first_name,
               s->email,
               s->gpa,
               s->course_count);
    }
    printf("\n");
}

int enroll_student(StudentDB *db, int student_id, int course_id) {
    Student *student = find_student(db, student_id);
    if (!student) return 0;

    if (student->course_count >= MAX_COURSES) return 0;

    // Check if course exists and has space
    if (!is_course_available(course_id)) return 0;

    student->course_ids[student->course_count++] = course_id;
    update_student_in_db(student);
    
    return 1;
}

void update_gpa(StudentDB *db, int student_id) {
    Student *student = find_student(db, student_id);
    if (!student) return;

    float total = 0;
    int count = 0;

    for (int i = 0; i < student->course_count; i++) {
        float grade = get_student_grade(student_id, 
                                      student->course_ids[i]);
        if (grade >= 0) {
            total += grade;
            count++;
        }
    }

    if (count > 0) {
        student->gpa = total / count;
        update_student_in_db(student);
    }
} 