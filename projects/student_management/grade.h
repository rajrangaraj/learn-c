#ifndef GRADE_H
#define GRADE_H

typedef struct {
    int student_id;
    int course_id;
    float midterm;
    float final;
    float assignments;
    float participation;
    float total;
    char letter_grade;
} Grade;

typedef struct {
    Grade *grades;
    int count;
    int capacity;
} GradeDB;

// Grade operations
GradeDB* init_grade_db(int initial_capacity);
void free_grade_db(GradeDB *db);
int add_grade(GradeDB *db, Grade grade);
int update_grade(GradeDB *db, Grade grade);
float get_student_grade(GradeDB *db, int student_id, int course_id);
void calculate_final_grade(GradeDB *db, int student_id, int course_id);
void generate_grade_report(GradeDB *db, int student_id);

#endif 