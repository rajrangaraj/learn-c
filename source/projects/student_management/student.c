#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define MAX_STUDENTS 100
struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter ID: ");
        scanf("%d", &students[studentCount].id);
        printf("Enter Name: ");
        scanf("%s", students[studentCount].name);
        printf("Enter Marks: ");
        scanf("%f", &students[studentCount].marks);
    }
    studentCount++;
}

void displayStudents() {
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

void saveStudents() {
    FILE *file = fopen("students.dat", "wb");
    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(struct Student), studentCount, file);
    fclose(file);
}

void loadStudents() {
    FILE *file = fopen("students.dat", "rb");
    if (file) {
        fread(&studentCount, sizeof(int), 1, file);
        fread(students, sizeof(struct Student), studentCount, file);
        fclose(file);
    }
}
