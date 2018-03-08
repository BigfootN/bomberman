//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

/* pointeur de function pour le menu des differents panneaux */
typedef int (*p_fib)(t_control *);

typedef struct s_window {
    int number;
    p_fib pfunc;
} t_window;

static const t_window l_bib[] = {
        {1, &introduction_central},
        {2, &ip_choice_central},
        {3, &central_game},
        {4, &scores_central},
        {0, NULL}
};

int main()
{
    int choixpage;
    int index;
    t_control *control;

    control = init_control(); /* initialise les structures */
    if (((choixpage = central_init_sprites(control))) > 0)  /* mets en memoire les divers parties des elements graphiques du jeux */
    {
        index = 0;
        //choixpage = 1;
        control->network->srv_or_clt = 1;
        while (l_bib[index].number != 0)
        {
            if (l_bib[index].number == choixpage)
            {
                choixpage = l_bib[index].pfunc(control);
                index = -1;
            }
            index++;
        }
    }
    return 0;
}