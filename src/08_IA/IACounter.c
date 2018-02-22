#include "headers.h"

int checkCounter(t_etat *etat)
{
    checkPlayerActif(etat);
    difference(etat); // le temps
    return (1);
}

void prepaCounterPlayer(t_etat *etat, t_player *player)
{
    if (player->player != NULL && etat->msg != NULL)
    {
        etat->msg->statePlayer.score = player->player->score;
        etat->msg->statePlayer.bomb = player->player->bomb;
        etat->msg->statePlayer.speed = player->player->speed;
        etat->msg->statePlayer.life = player->player->life;
    }
}