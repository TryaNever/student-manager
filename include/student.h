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

int note_add(int note_choose);
void print_student(Student student);

#endif