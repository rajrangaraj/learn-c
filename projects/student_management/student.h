#ifndef STUDENT_H
#define STUDENT_H

#include <time.h>

#define MAX_NAME 50
#define MAX_EMAIL 100
#define MAX_COURSES 10

typedef struct {
    int id;
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[15];
    time_t dob;
    int course_ids[MAX_COURSES];
    int course_count;
    float gpa;
    int active;
} Student;

typedef struct {
    Student *students;
    int count;
    int capacity;
} StudentDB;

// Student operations
StudentDB* init_student_db(int initial_capacity);
void free_student_db(StudentDB *db);
int add_student(StudentDB *db, Student student);
int update_student(StudentDB *db, Student student);
int delete_student(StudentDB *db, int id);
Student* find_student(StudentDB *db, int id);
void list_students(StudentDB *db);

// Course enrollment
int enroll_student(StudentDB *db, int student_id, int course_id);
int drop_course(StudentDB *db, int student_id, int course_id);

// Grade management
void update_gpa(StudentDB *db, int student_id);
void generate_transcript(StudentDB *db, int student_id);

#endif 