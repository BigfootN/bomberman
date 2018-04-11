//
// Created by marc on 01/03/18.
//

#include "headers.h"

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

void prepa_counter_player(t_etat *etat, t_pions *pion)
{
    if (pion != NULL && etat->msg != NULL)
    {
        etat->msg->stat_user[1] = pion->score;
        etat->msg->stat_user[5] = pion->bomb;
        etat->msg->stat_user[4] = pion->speed;
        etat->msg->stat_user[2] = pion->life;
        etat->msg->stat_user[6] = pion->win;
        if(etat->partie == 5)/* prend en compte si gagant ou perdant */
          etat->msg->stat_user[7] = pion->winner;
    }
}
