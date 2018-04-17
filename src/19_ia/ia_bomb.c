//
// Created by marc on 01/03/18.
//

#include "headers.h"

// ajoute la bombe dans la liste des objects bombe et autres

void init_bomb(t_etat *etat, t_pions *pion) {
    t_pions *tmp;

    /* incrente ici le compteur principalpour donner un id à la bombe */
    etat->nbre_pions++;

    if (pion->bomb > 0) {
        tmp = add_pions(etat, pion->mappos); // creer un object bombe
        tmp->active = 0;/* desactive */
        tmp->proprio = pion->id;// détermine le proprio
        tmp->degat = 5;
        tmp->etat_requete = 1;
        tmp->requete_1 = 2;
        tmp->requete_2 = 0;
        tmp->id = etat->nbre_pions;
        tmp->life = 10;// ici la vie de la bomb IMPORTANT
        pion->bomb--; /* retire une bombe à l'utilisateur */
        tmp->active = 1;/* active à la fin*/
    }
}

//la mets sur la carte
void etat_bomb(t_etat *etat, t_pions *pion) {
    t_pions *tmp;
    int temps_bombe;

    temps_bombe = 0;
    tmp = pion;
    if (tmp->life >= 10 && tmp->life < 50) {
        tmp->life++;
        if (tmp->life > 0 && 15 > tmp->life)
            temps_bombe = 0;
        else if (tmp->life > 15 && 30 > tmp->life)
            temps_bombe = 1;
        else if (tmp->life > 30 && 45 > tmp->life)
            temps_bombe = 2;
        else if (tmp->life >= 45) {
            pion->requete_1 = 0;
            pion->requete_2 = 0;
            pion->etat_requete = 0;
            temps_bombe = 100 + pion->proprio;
        }
        etat->data_map->bmmap[tmp->mappos.x][tmp->mappos.y] = temps_bombe;
    }
}