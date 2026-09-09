#include "student.h"
#include "saver.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Student student;
    int count_student = 0;

    student.id = 1;
    student.first_name = "test";
    student.last_name = "tested";
    student.age = 15;
    student.average = 15.7;

    print_student(student);

    Student *students;

    students = malloc_student(3);

    students[0] = student;
    student.id = 2;
    students[1] = student;
    student.id = 3;
    students[2] = student;
    count_student = 3;
    print_array_student(students, count_student);

    remove_student(2, &students, &count_student);
    print_array_student(students, count_student);
    char *text = destructure_student_into_txt(students, &count_student);

    write_into_file("testessss.txt", text);
    free_student(students);
    system("PAUSE");
    return 0;
}