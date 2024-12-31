#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student student = {1, "John Doe", 95.5};
    printf("ID: %d, Name: %s, Marks: %.2f\n", student.id, student.name, student.marks);
    return 0;
}
