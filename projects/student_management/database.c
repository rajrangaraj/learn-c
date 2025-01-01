#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "student.h"
#include "course.h"
#include "grade.h"

#define DB_PATH "./data/"
#define STUDENTS_FILE "students.dat"
#define COURSES_FILE "courses.dat"
#define GRADES_FILE "grades.dat"

// Initialize database
int init_database() {
    // Create data directory if it doesn't exist
    #ifdef _WIN32
    system("mkdir data 2> nul");
    #else
    system("mkdir -p data");
    #endif
    
    return 1;
}

// Student persistence
int save_student_to_db(Student *student) {
    FILE *file = fopen(DB_PATH STUDENTS_FILE, "ab");
    if (!file) return 0;
    
    size_t written = fwrite(student, sizeof(Student), 1, file);
    fclose(file);
    
    return written == 1;
}

int update_student_in_db(Student *student) {
    FILE *file = fopen(DB_PATH STUDENTS_FILE, "r+b");
    if (!file) return 0;
    
    Student temp;
    while (fread(&temp, sizeof(Student), 1, file)) {
        if (temp.id == student->id) {
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(student, sizeof(Student), 1, file);
            fclose(file);
            return 1;
        }
    }
    
    fclose(file);
    return 0;
}

// Course persistence
int save_course_to_db(Course *course) {
    FILE *file = fopen(DB_PATH COURSES_FILE, "ab");
    if (!file) return 0;
    
    size_t written = fwrite(course, sizeof(Course), 1, file);
    fclose(file);
    
    return written == 1;
}

// Grade persistence
int save_grade_to_db(Grade *grade) {
    FILE *file = fopen(DB_PATH GRADES_FILE, "ab");
    if (!file) return 0;
    
    size_t written = fwrite(grade, sizeof(Grade), 1, file);
    fclose(file);
    
    return written == 1;
}

// Load database into memory
int load_database(StudentDB *sdb, CourseDB *cdb, GradeDB *gdb) {
    // Load students
    FILE *sfile = fopen(DB_PATH STUDENTS_FILE, "rb");
    if (sfile) {
        Student student;
        while (fread(&student, sizeof(Student), 1, sfile)) {
            if (student.active) {
                add_student(sdb, student);
            }
        }
        fclose(sfile);
    }
    
    // Load courses
    FILE *cfile = fopen(DB_PATH COURSES_FILE, "rb");
    if (cfile) {
        Course course;
        while (fread(&course, sizeof(Course), 1, cfile)) {
            if (course.active) {
                add_course(cdb, course);
            }
        }
        fclose(cfile);
    }
    
    // Load grades
    FILE *gfile = fopen(DB_PATH GRADES_FILE, "rb");
    if (gfile) {
        Grade grade;
        while (fread(&grade, sizeof(Grade), 1, gfile)) {
            add_grade(gdb, grade);
        }
        fclose(gfile);
    }
    
    return 1;
} 