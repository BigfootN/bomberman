#include "headers.h"

void CentralSend(t_etat *etat)
{
    sendEmail(etat);
}

void sendEmail(t_etat *etat)
{
    t_player *player;
    pthread_t p_thread;

    player = etat->players;
    etat->msg->commandService = 5;
    etat->msg->reponse = 0;
    if (etat->partie == 2)
        etat->msg->pos[2] = 1;

    while (player != NULL)
    {
        if (player->socket_player >= 0)
        {
            etat->socket_send = player->socket_player;
            etat->msg->idClient = player->id_connexion;
            etat->msg->departTime = etat->tdepart;
            prepaCounterPlayer(etat, player);
            etat->msg->pos[3] = 0;
            if (player->active == 0 || player->player->active == 0)
                etat->msg->pos[3] = 1;
            if (pthread_create(&p_thread, NULL, server_to_client, (void*) etat) < 0)
            {
                perror("could not create thread");
                return;
            }
        }
        SDL_Delay(5);
        player = player->next;
    }
}

/*
 *  prend en compte les joueurs encore present
 */

void checkPlayerActif(t_etat* etat)
{
    t_player *player;

    player = etat->players;
    while (player != NULL)
    {
        if (player->active)
            etat->pactif[player->id_connexion] = 1;
        player = player->next;
    }
}