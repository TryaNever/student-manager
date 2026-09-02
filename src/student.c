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
    printf("%d", student.age);
}