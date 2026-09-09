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

    fprintf(fp, "%s",text);

    fclose(fp);

    printf("Fichier créé avec succès.\n");
    return 0;
}