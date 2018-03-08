//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

void central_send(t_etat *etat)
{
    send_email(etat);
}

void send_email(t_etat *etat)
{
    t_player *player;
    pthread_t p_thread;

    player = etat->players;
    etat->msg->command_service = 5;
    etat->msg->reponse = 0;
    if (etat->partie == 2)
        etat->msg->pos[2] = 1;

    while (player != NULL)
    {
        if (player->socket_player >= 0)
        {
            etat->socket_send = player->socket_player;
            etat->msg->idclient = player->id_connexion;
            if (etat->tdepart != 0)
                etat->msg->depart_time = etat->tdepart;
            prepa_counter_player(etat, player);
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

void check_player_actif(t_etat* etat)
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
