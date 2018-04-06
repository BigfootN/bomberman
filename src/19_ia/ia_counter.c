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

// 0 ptime
// 1 score
// 2 life
// 3 sort
// 4 speed
// 5 bomb
// 6 win

void prepa_counter_player(t_etat *etat, t_player *player)
{
    if (player->player != NULL && etat->msg != NULL)
    {
        t_pions *pion;
        pion = player->player;
        etat->msg->stat_user[11] = pion->score;
        etat->msg->stat_user[5] = pion->bomb;
        etat->msg->stat_user[4] = pion->speed;
        etat->msg->stat_user[2] =pion->life;
        if(etat->partie == 5)/* prend en compte si gagant ou perdant */
          etat->msg->stat_user[6] = pion->win;
    }
}
