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
        tmp->active = 0;/* desactive */
        tmp->proprio = player->id;// détermine le proprio
        tmp->degat = 5;
        tmp->etat_requete = 1;
        tmp->requete_1 = 2;
        // ici la vie de la bomb IMPORTANT
        tmp->life = 10;
        player->bomb--;
        tmp->active = 1;/* active à la fin*/
    }
}
//la mets sur la carte

void etat_bomb(t_etat *etat, t_pions *pions)
{
    t_pions *tmp;
    int temps_bombe;

    temps_bombe = 0;
    tmp = pions;
    if (tmp->life >= 10 && tmp->life < 50)
    {
        tmp->life++;
        if (tmp->life > 0 && 15 > tmp->life)
            temps_bombe = 0;
        else if (tmp->life > 15 && 30 > tmp->life)
            temps_bombe = 1;
        else if (tmp->life > 30 && 45 > tmp->life)
            temps_bombe = 2;
        else if (tmp->life > 45)
            temps_bombe = 3;

        etat->data_map->bmmap[tmp->mappos.x][tmp->mappos.y] = temps_bombe;
    }
    else if (tmp->life >= 45)// devient explosion
    {
        pions->requete_1 = 0;
        pions->requete_2 = 0;
        pions->etat_requete = 0;
        etat->data_map->bmmap[tmp->mappos.x][tmp->mappos.y] = 100 + pions->proprio; // numero faire exploser bomb
    }
}