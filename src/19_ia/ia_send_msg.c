//
// Created by marc on 01/03/18.
//

#include "headers.h"

void central_send(t_etat *etat) {
    send_email(etat);
}

void send_email(t_etat *etat) {
   t_pions *pion;
    pthread_t p_thread;
    int index;

    etat->msg->command_service = 5;
    etat->msg->reponse = 0;
    if (etat->nbreset != 0)
        etat->msg->set_start = etat->nbreset;/* pour les manche de la partie */
    else
        etat->msg->set_start = 0;
    etat->msg->pos[2] = etat->partie;

    /* si il n'y plus de de joueurs ou si la partie est à l'arret */
    if(etat->send_message == 0)
        return;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->type >= 23 && pion->type <= 26) {
//        if (pion->id_connexion <= 4) {
            if (pion->socket_player >= 0) {
                /* résultat des victoires de chaque users */
                index = 0;
                while (index < 5) {
                    etat->msg->win_user[index] = etat->winusers[index];
                    index++;
                }
                etat->socket_send = pion->socket_player;
                etat->msg->idclient = pion->id_connexion;
                if (etat->tdepart != 0)/* envoi le depart de la partie */
                    etat->msg->depart_time = etat->tdepart;
                prepa_counter_player(etat, pion);
                etat->msg->pos[3] = 0; /* signale que l'user est en vie */
                etat->msg->etat_party_chrono = etat->etat_party_chrono; /* dis que le chrono est pret */
                if (pion->active == 0)
                    etat->msg->pos[3] = 1; /* signale que l'user est éliminé */
                if (pthread_create(&p_thread, NULL, server_to_client, (void *) etat) < 0) {
                    perror("could not create thread");
                    return;
                }
            }
        }
        SDL_Delay(5);
        pion = pion->next;
    }
}

/*
 *  prend en compte les joueurs encore present AREVOIR
 */

void check_player_actif(t_etat *etat) {
    t_pions *pion;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->id_connexion <= 4) {
            if (pion->active)
                etat->pactif[pion->id_connexion] = 1;
        }
        pion = pion->next;
    }
}
