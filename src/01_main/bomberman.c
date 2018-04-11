//
// Created by marc on 05/04/18.
//

#include "headers.h"

int main(int argc, char *argv[]) {

    int choixpage;
    int index;
    t_control *control;

    lock = SDL_CreateMutex();
    cv = SDL_CreateCond();
    lockclient = SDL_CreateMutex();
    condclient = SDL_CreateCond();

    if ((argc == 0) && (sizeof(*argv) != 0))
        return 0;

    control = init_control();

    /* mets en memoire les divers parties des elements graphiques du jeux */
    if (((choixpage = central_init_sprites(control))) > 0) {
        if(choixpage == 0)
        {
            puts("problème avec les ressources");
            return(1);
        }

        index = 0;
        control->srv_or_clt = 1;
        while (l_bib[index].number != 0) {
            if (l_bib[index].number == choixpage) {
                choixpage = l_bib[index].pfunc(control);
                index = -1;
            }
            index++;
        }
    }

    delete_sprites(control);
    delete_control(control);

    return (0);
}