#include "student.h"

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

    new_students = realloc_student(*students, (*count_student + 1));

    if (new_students == NULL)
        return;

    *students = new_students;

    (*students)[*count_student] = student;
    (*count_student)++;
}

char *destructure_student_into_txt(Student *students, int *count_student)
{
    char *data = malloc(1);

    if (data == NULL)
        return NULL;

    data[0] = '\0';
    for (int i = 0; i < *count_student; i++)
    {
        int taille_ligne = snprintf(
            NULL,
            0,
            "%d;%s;%s;%d;%.2f\n",
            students[i].id,
            students[i].first_name,
            students[i].last_name,
            students[i].age,
            students[i].average);
        char *ligne = malloc(taille_ligne + 1);

        if (ligne == NULL)
        {
            free(data);
            return NULL;
        }
        snprintf(
            ligne,
            taille_ligne + 1,
            "%d;%s;%s;%d;%.2f\n",
            students[i].id,
            students[i].first_name,
            students[i].last_name,
            students[i].age,
            students[i].average);
        size_t taille_actuelle = strlen(data);

        char *temp = realloc(
            data,
            taille_actuelle + taille_ligne + 1);

        if (temp == NULL)
        {
            free(ligne);
            free(data);
            return NULL;
        }

        data = temp;

        strcat(data, ligne);
        free(ligne);
    }
    return data;
}

void *construct_student_from_txt(Student *students, int *count_student, char *file_name)
{
    char *text = get_text_file(file_name);
    char **tokens;

    tokens = str_split(text, '\n');

    if (tokens)
    {
        for (int i = 0; *(tokens + i); i++)
        {
            char **tokens_student = str_split((tokens+i), ";");
            for ( int index_item_student = 0; i < STUDENT_COL_COUNT; i++)
            {
                printf("%s", tokens_student);
            }
            


            Student student;


            add_student(student, students, count_student);
        }
    }
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