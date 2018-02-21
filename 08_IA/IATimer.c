#include "headers.h"

void startTime(t_etat *etat)
{
    time(&etat->tdepart);
}

void difference(t_etat *etat)
{
    if ((etat->tdepart) > 0)// prend en compte quand la partie demarre
    {
        if (difftime(etat->tcourant, etat->tdepart) > 120)
            etat->partie = 2;
        else
            time(&etat->tcourant);
    }
}