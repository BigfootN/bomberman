//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int create_bonus_malus()
{
    int nb_monster;
    int choice;

    nb_monster = my_rand(10);
    if (nb_monster == 0)
        choice = 28;
    else if (nb_monster == 1)
        choice = 6;
    else if (nb_monster == 2)
        choice = 29;
    else if (nb_monster == 3)
        choice = 5;
    else if (nb_monster == 4)
        choice = 27;
    else if (nb_monster == 5)
        choice = 8;
    else if (nb_monster == 6)
        choice = 7;
    else if (nb_monster == 7)
        choice = 4;
    else if (nb_monster == 8)
        choice = 30;
    else
        choice = -1; // sinon rien pas de BM

    /* if (nbreMonstre == 0)
         choice = 8;
     else if (nbreMonstre == 1)
         choice = 6;
     else if (nbreMonstre == 2)
         choice = 5;
     else if (nbreMonstre == 3)
         choice = 7;
     else
         choice = -1;
    if (nbreMonstre == 0)
        choice = 28;
    else if (nbreMonstre == 1)
        choice = 30;
    else if (nbreMonstre == 2)
        choice = 29;
    else if (nbreMonstre == 3)
        choice = 27;*/


    return (choice);
}
