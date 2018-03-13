//
// Created by marc on 03/03/18.
//

#include "bomberman.h"

int search_folder(char *dirname) {
    DIR *FD;
//    struct dirent *f;

    if (NULL == (FD = opendir(dirname))) {
        fprintf(stderr, "opendir() impossible\n");
        return (-1);
    }
   /* my_putstr(dirname);
    while ((f = readdir(FD))) {
        my_putstr(f->d_name);
    }*/
    closedir(FD);
    return (1);
}