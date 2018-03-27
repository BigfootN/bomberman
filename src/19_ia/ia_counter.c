//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int check_counter(t_etat *etat)
{
    int response;

    check_player_actif(etat);
    if((response = difference(etat)) > 0) // le temps
        return (response);
    else
        return (0);
}

void prepa_counter_player(t_etat *etat, t_player *player)
{
    if (player->player != NULL && etat->msg != NULL)
    {
        t_pions *pion;
        pion = player->player;
        etat->msg->state_player->score = pion->score;
        etat->msg->state_player->bomb = pion->bomb;
        etat->msg->state_player->speed = pion->speed;
        etat->msg->state_player->life =pion->life;
        if(etat->partie == 5)/* prend en compte si gagant ou perdant */
          etat->msg->state_player->win = pion->win;
    }
}
