//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

// ajoute la bombe dans la liste des objects bombe et autres

void init_bomb(t_etat *etat, t_pions *player)
{
    t_pions *tmp;

    if (player->bomb > 0)
    {
        tmp = add_item_pions(etat, player->mappos); // creer un object bombe
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

void etat_bomb(t_etat *etat, t_pions *pions)
{
    t_pions *tmp;
    int temps_bombe;

    tmp = pions;
    if (tmp->life >= 10 && tmp->life < 80)
    {
        tmp->life++;
        if (tmp->life > 0 && 20 > tmp->life)
            temps_bombe = 0;
        else if (tmp->life > 20 && 40 > tmp->life)
            temps_bombe = 1;
        else if (tmp->life > 40 && 80 > tmp->life)
            temps_bombe = 2;
        else if (tmp->life > 80)
            temps_bombe = 3;
        etat->data_map->bmmap[tmp->mappos.x][tmp->mappos.y] = temps_bombe;
    }
    else if (tmp->life >= 80)// devient explosion
    {
        pions->requete_1 = 0;
        pions->requete_2 = 0;
        pions->etat_requete = 0;
        etat->data_map->bmmap[tmp->mappos.x][tmp->mappos.y] = 40; // numero faire exploser bomb
        // deleteListChevron(pions);  // detruit la bomb
    }
}