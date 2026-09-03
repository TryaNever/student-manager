#include "student.h"
#include <stdlib.h>
#include <stdio.h>

void print_student(Student student)
{
    printf("Student : \n");
    printf("\tId : %d\n", student.id);
    printf("\tPrenom : %s\n", student.first_name);
    printf("\tNom : %s\n", student.last_name);
    printf("\tAge : %d\n", student.age);
    printf("\tNote Moyenne : %.2f\n", student.average);
}

Student *malloc_student(int size)
{
    Student *mem_al = malloc(size * sizeof(Student));

    if (!mem_al && size)
        printf("Cannot allocate %d bytes", size);
    return mem_al;
}

void free_student(Student *malloc_student)
{
    free(malloc_student);
}