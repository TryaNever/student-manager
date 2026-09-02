#include "student.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int note = 10;

    Student student;

    student.id = 1;
    student.first_name = "test";
    student.last_name = "tested";
    student.age = 15;
    student.average = 15.7;

    print_student(student);
    system("PAUSE");
}