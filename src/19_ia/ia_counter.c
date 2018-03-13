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
        etat->msg->state_player.score = player->player->score;
        etat->msg->state_player.bomb = player->player->bomb;
        etat->msg->state_player.speed = player->player->speed;
        etat->msg->state_player.life = player->player->life;
        if(etat->partie == 5)/* prend en compte si gagant ou perdant */
          etat->msg->state_player.win = player->player->win;
    }
}
