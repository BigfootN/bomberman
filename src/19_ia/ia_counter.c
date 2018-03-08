//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int check_counter(t_etat *etat)
{
    check_player_actif(etat);
    difference(etat); // le temps
    return (1);
}

void prepa_counter_player(t_etat *etat, t_player *player)
{
    if (player->player != NULL && etat->msg != NULL)
    {
        etat->msg->state_player.score = player->player->score;
        etat->msg->state_player.bomb = player->player->bomb;
        etat->msg->state_player.speed = player->player->speed;
        etat->msg->state_player.life = player->player->life;
    }
}
