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

void print_array_student(Student *student, int count_student)
{
    for (int i = 0; i < count_student; i++)
    {
        print_student(student[i]);
    }
}

void add_student(Student student, Student **students, int *count_student)
{
    Student *new_students;

    new_students = realloc(*students, (*count_student + 1) * sizeof(Student));

    if (new_students == NULL)
        return;

    *students = new_students;

    (*students)[*count_student] = student;
    (*count_student)++;
}

void remove_student(int id_student, Student **students, int *count_student)
{
    Student *new_students;
    int index_new_student = 0;

    new_students = malloc_student(*count_student - 1);
    for (int i = 0; i < *count_student; i++)
    {
        if ((*students)[i].id != id_student)
        {
            new_students[index_new_student] = (*students)[i];
            index_new_student++;
        }
    }
    free_student(*students);

    *students = new_students;
    (*count_student)--;
}

Student *malloc_student(int size)
{
    Student *mem_al = malloc(size * sizeof(Student));

    if (!mem_al && size)
        printf("Cannot allocate %llu bytes", size * sizeof(Student));
    return mem_al;
}

Student *realloc_student(Student *students, int size)
{
    Student *mem_al = realloc(students, size * sizeof(Student));
    if (!mem_al && size)
    {
        printf("Cannot add %llu bytes to allocation", size * sizeof(Student));
    }
    return mem_al;
}

void free_student(Student *malloc_student)
{
    free(malloc_student);
}