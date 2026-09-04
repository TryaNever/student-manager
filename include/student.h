#ifndef STUDENT_H
#define STUDENT_H

typedef struct
{
    int id;
    char *first_name;
    char *last_name;
    int age;
    float average;
} Student;

void print_student(Student student);
void add_student(Student student, Student **students, int *count_student);
Student *malloc_student(int size);
Student *realloc_student(Student *students, int size);
void free_student(Student *malloc_student);
void print_array_student(Student *student, int count_student);
#endif