#include "saver.h"
#include "student.h"
#include <stdlib.h>
#include <stdio.h>

int write_into_file(char *name_file, Student student)
{
    FILE *fp;
    fp = fopen("test.txt", "w");

    if (fp == NULL)
    {
        printf("Erreur lors de la création du fichier.\n");
        return 1;
    }

    fprintf(fp, "Bonjour, ceci est un test.\n");

    fclose(fp);

    printf("Fichier créé avec succès.\n");
}