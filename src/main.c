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
}