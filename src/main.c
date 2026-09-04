#include "student.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Student student;

    student.id = 1;
    student.first_name = "test";
    student.last_name = "tested";
    student.age = 15;
    student.average = 15.7;

    print_student(student);

    Student *students;

    students = malloc_student(3);

    students[0] = student;
    students[1] = student;
    students[2] = student;
    print_array_student(students, 3);
    free_student(students);
    system("PAUSE");
    return 0;
}