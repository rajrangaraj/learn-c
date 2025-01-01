#ifndef COURSE_H
#define COURSE_H

#define MAX_COURSE_NAME 100
#define MAX_INSTRUCTOR 50
#define MAX_STUDENTS 30

typedef struct {
    int id;
    char name[MAX_COURSE_NAME];
    char instructor[MAX_INSTRUCTOR];
    int credits;
    int capacity;
    int enrolled;
    int student_ids[MAX_STUDENTS];
    int active;
    char schedule[20];  // e.g., "MWF 10:00-11:20"
} Course;

typedef struct {
    Course *courses;
    int count;
    int capacity;
} CourseDB;

// Course operations
CourseDB* init_course_db(int initial_capacity);
void free_course_db(CourseDB *db);
int add_course(CourseDB *db, Course course);
int update_course(CourseDB *db, Course course);
int delete_course(CourseDB *db, int id);
Course* find_course(CourseDB *db, int id);
void list_courses(CourseDB *db);
int is_course_available(CourseDB *db, int id);

#endif 