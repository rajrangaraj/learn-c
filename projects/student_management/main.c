#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "course.h"
#include "grade.h"
#include "database.h"

#define INITIAL_CAPACITY 100

void print_menu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. Update Student\n");
    printf("3. Delete Student\n");
    printf("4. List Students\n");
    printf("5. Add Course\n");
    printf("6. List Courses\n");
    printf("7. Enroll Student\n");
    printf("8. Add Grades\n");
    printf("9. Generate Report\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

Student input_student() {
    Student s = {0};
    printf("First Name: ");
    scanf("%s", s.first_name);
    printf("Last Name: ");
    scanf("%s", s.last_name);
    printf("Email: ");
    scanf("%s", s.email);
    printf("Phone: ");
    scanf("%s", s.phone);
    return s;
}

Course input_course() {
    Course c = {0};
    printf("Course Name: ");
    scanf(" %[^\n]s", c.name);
    printf("Instructor: ");
    scanf(" %[^\n]s", c.instructor);
    printf("Credits: ");
    scanf("%d", &c.credits);
    printf("Capacity: ");
    scanf("%d", &c.capacity);
    printf("Schedule: ");
    scanf("%s", c.schedule);
    return c;
}

Grade input_grade(int student_id, int course_id) {
    Grade g = {0};
    g.student_id = student_id;
    g.course_id = course_id;
    printf("Midterm Grade: ");
    scanf("%f", &g.midterm);
    printf("Final Grade: ");
    scanf("%f", &g.final);
    printf("Assignments Grade: ");
    scanf("%f", &g.assignments);
    printf("Participation Grade: ");
    scanf("%f", &g.participation);
    return g;
}

int main() {
    // Initialize databases
    StudentDB *sdb = init_student_db(INITIAL_CAPACITY);
    CourseDB *cdb = init_course_db(INITIAL_CAPACITY);
    GradeDB *gdb = init_grade_db(INITIAL_CAPACITY);
    
    if (!sdb || !cdb || !gdb) {
        fprintf(stderr, "Failed to initialize databases\n");
        return 1;
    }
    
    // Initialize database files
    init_database();
    
    // Load existing data
    load_database(sdb, cdb, gdb);
    
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {  // Add Student
                Student s = input_student();
                int id = add_student(sdb, s);
                printf("Student added with ID: %d\n", id);
                break;
            }
            case 2: {  // Update Student
                int id;
                printf("Enter student ID: ");
                scanf("%d", &id);
                Student *s = find_student(sdb, id);
                if (s) {
                    Student new_s = input_student();
                    new_s.id = id;
                    update_student(sdb, new_s);
                    printf("Student updated\n");
                } else {
                    printf("Student not found\n");
                }
                break;
            }
            case 3: {  // Delete Student
                int id;
                printf("Enter student ID: ");
                scanf("%d", &id);
                if (delete_student(sdb, id)) {
                    printf("Student deleted\n");
                } else {
                    printf("Student not found\n");
                }
                break;
            }
            case 4:  // List Students
                list_students(sdb);
                break;
            case 5: {  // Add Course
                Course c = input_course();
                int id = add_course(cdb, c);
                printf("Course added with ID: %d\n", id);
                break;
            }
            case 6:  // List Courses
                list_courses(cdb);
                break;
            case 7: {  // Enroll Student
                int student_id, course_id;
                printf("Student ID: ");
                scanf("%d", &student_id);
                printf("Course ID: ");
                scanf("%d", &course_id);
                if (enroll_student(sdb, student_id, course_id)) {
                    printf("Student enrolled\n");
                } else {
                    printf("Enrollment failed\n");
                }
                break;
            }
            case 8: {  // Add Grades
                int student_id, course_id;
                printf("Student ID: ");
                scanf("%d", &student_id);
                printf("Course ID: ");
                scanf("%d", &course_id);
                Grade g = input_grade(student_id, course_id);
                if (add_grade(gdb, g)) {
                    update_gpa(sdb, student_id);
                    printf("Grades added\n");
                } else {
                    printf("Failed to add grades\n");
                }
                break;
            }
            case 9: {  // Generate Report
                int student_id;
                printf("Student ID: ");
                scanf("%d", &student_id);
                generate_grade_report(gdb, student_id);
                break;
            }
        }
    } while (choice != 0);
    
    // Cleanup
    free_student_db(sdb);
    free_course_db(cdb);
    free_grade_db(gdb);
    
    return 0;
} 