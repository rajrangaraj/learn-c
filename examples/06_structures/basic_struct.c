#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student student1 = {"John", 20, 3.8};
    
    printf("Student: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.gpa);
    
    return 0;
} 