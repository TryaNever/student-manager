#include "student.h"
#include "saver.h"
#include <stdlib.h>
#include <stdio.h>

int write_into_file(char *name_file, char *text)
{
    FILE *fp;
    fp = fopen(name_file, "w");

    if (fp == NULL)
    {
        printf("Erreur lors de la création du fichier.\n");
        return 1;
    }
    printf("%s", text);

    fprintf(fp, "%s", text);

    fclose(fp);

    printf("Fichier créé avec succès.\n");
    return 0;
}

long get_size_file(char *name_file)
{
    FILE *fp;
    fp = fopen(name_file, "r");

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    return size;
}

int get_text_file(char *name_file)
{
    FILE *fp;
    fp = fopen(name_file, "r");
    long size_file = get_size_file(name_file);

    char *text = malloc(size_file + 1);
    fgets(text, size_file, fp);
    printf("%s", text);
    return 0;
}