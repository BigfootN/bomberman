//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

void central_send(t_etat *etat) {
    send_email(etat);
}

void send_email(t_etat *etat) {
    t_player *player;
    pthread_t p_thread;
    int index;

    player = etat->players;
    etat->msg->command_service = 5;
    etat->msg->reponse = 0;
    if (set_party != 0)
        etat->msg->set_start = set_party;/* pour les manche de la partie */
    else
        etat->msg->set_start = 0;

    etat->msg->pos[2] = etat->partie;

    while (player != NULL) {
        if (player->socket_player >= 0) {
            /* résultat des victoires de chaque users */
            index = 0;
            while(index < 5)
            {
                etat->msg->win_user[index] = etat->winusers[index];
                index++;
            }

            etat->socket_send = player->socket_player;
            etat->msg->idclient = player->id_connexion;
            if (etat->tdepart != 0)/* envoi le depart de la partie */
                etat->msg->depart_time = etat->tdepart;
            prepa_counter_player(etat, player);
            etat->msg->pos[3] = 0; /* signale que l'user est en vie */
            if (player->active == 0 || player->player->active == 0)
                etat->msg->pos[3] = 1; /* signale que l'user est éliminé */
            if (pthread_create(&p_thread, NULL, server_to_client, (void *) etat) < 0) {
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

void check_player_actif(t_etat *etat) {
    t_player *player;

    player = etat->players;
    while (player != NULL) {
        if (player->active)
            etat->pactif[player->id_connexion] = 1;
        player = player->next;
    }
}
