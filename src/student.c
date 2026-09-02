#include "student.h"
#include <stdlib.h>
#include <stdio.h>

int note_add(int note_choose)
{
    note_choose += 5;

    return note_choose;
}

void print_student(Student student)
{
    printf("Student : \n");
    printf("\tId : %d\n", student.id);
    printf("\tPrenom : %s\n", student.first_name);
    printf("\tNom : %s\n", student.last_name);
    printf("\tAge : %d\n", student.age);
    printf("\tNote Moyenne : %.2f\n", student.average);
}