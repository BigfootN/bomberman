#include "headers.h"

/* 
 * permet de choisir la route (1-4) dans les routes dispo
 * continuer a marcher dans le meme clock_direction (0-1)
 * cours après un joueur proche (0, 1)
 */
int my_way_rand(int nbre)
{
    static int tp = 0;
    int number;

    number = 0;
    if (tp++ == 0)
        srand(time(NULL));
    while (number == 0)
        number = (int) (rand() / (double) RAND_MAX * (nbre));
    return (number);
}
// choix monster and bonus malus

int my_rand(int nbre)
{
    static int tp = 0;
    int number;

    number = 0;
    if (tp++ == 0)
        srand(time(NULL));
    while (number == 0)
        number = (int) (rand() / (double) RAND_MAX * (nbre));
    return (number);
}

int my_rand_binaire()
{
    int number;
    double rt;

    number = 0;
    srand(time(NULL));
    while (number == 0)
    {
        rt = rand() % 2;
        number = (int) rt;
    }
    return (number);
}


