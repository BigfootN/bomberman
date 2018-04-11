//
// Created by marc on 05/04/18.
//

#include "headers.h"

/* recherche le répertoire demandé */
int search_folder(char *dirname) {
    DIR *FD;

    if (NULL == (FD = opendir(dirname))) {
        fprintf(stderr, "opendir() impossible\n");
        return (-1);
    }
    closedir(FD);
    return (1);
}

/* assemble la directory (repertoire + nom) du fichier pour mettre en mémoire */
char *create_directory_file(char const *name, int directory) {

    char *name_directory;
    int total_char;

    /* alloue la mémoire */
    total_char = (int) my_strlen(REP_SPRITES) + (int) my_strlen(name) + 1;
    if ((name_directory = (char *) malloc(sizeof(char) * total_char)) == NULL)
        return NULL;

    /* nettoie le char avant de le remplir */
    memset(name_directory, '\0', total_char);

    /* choisit le répertoire */
    if (directory == 1)
        my_strcat(name_directory, REP_SPRITES);
    else if (directory == 2)
        my_strcat(name_directory, REP_MAP);
    else if (directory == 3)
        my_strcat(name_directory, REP_TTF);
    /* assemble l'url */
    my_strcat(name_directory, name);

    return (name_directory);
}

