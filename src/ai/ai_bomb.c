#include "headers.h"

// ajoute la bombe dans la liste des objects bombe et autres

void initBomb(t_etat *etat, t_pions *player)
{
    t_pions *tmp;

    if (player->bomb > 0)
    {
        tmp = addItemPions(etat, player->mappos); // creer un object bombe
        tmp->proprio = player->id;
        tmp->active = 1;
        tmp->degat = 5;
        tmp->etat_requete = 1;
        tmp->requete_1 = 2;
        // ici la vie de la bomb IMPORTANT
        tmp->life = 10;
        player->bomb--;
    }
}
//la mets sur la carte

void etatBomb(t_etat *etat, t_pions *pions)
{
    t_pions *tmp;
    int tempsBombe;

    tmp = pions;
    if (tmp->life >= 10 && tmp->life < 80)
    {
        tmp->life++;
        if (tmp->life > 0 && 20 > tmp->life)
            tempsBombe = 0;
        else if (tmp->life > 20 && 40 > tmp->life)
            tempsBombe = 1;
        else if (tmp->life > 40 && 80 > tmp->life)
            tempsBombe = 2;
        else if (tmp->life > 80)
            tempsBombe = 3;
        etat->dataMap->bmmap[tmp->mappos.x][tmp->mappos.y] = tempsBombe;
    }
    else if (tmp->life >= 80)// devient explosion
    {
        pions->requete_1 = 0;
        pions->requete_2 = 0;
        pions->etat_requete = 0;
        etat->dataMap->bmmap[tmp->mappos.x][tmp->mappos.y] = 40; // numero faire exploser bomb
        // deleteListChevron(pions);  // detruit la bomb
    }
}