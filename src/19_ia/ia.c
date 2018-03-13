//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

/*
 * initialise la partie
 */

void *central_ia(void *tmp) {
    t_etat *etat;

    pthread_detach(pthread_self());
    /* initialise le speed */
    waitspeed = 0;

    if ((etat = (t_etat *) malloc(sizeof(t_etat))) == NULL)
        return NULL;
    etat = init_etat(etat);
    party_choice(etat);
    //gestion_data(etat, "carte1.lvl");/* recupere la carte */
    tcp_thread_server(etat); /* demarre le serveur */
    loop_ia(etat); /* demarre la ia */

    pthread_exit((void *) tmp);
}

/*
 * verifie si existe des joueurs dans la liste des players
 */

int player_exist(t_etat *etat) {
    if (etat->players != NULL && etat->nbre_players > 0)
        if (etat->players->player != NULL)
            return (1);
    return (0);
}

void *loop_ia_pion(void *tmp) {
    t_etat *etat = (t_etat *) tmp;
    int pause;
    pause = 1;

    while (pause) {
        if (etat->partie == 1) {
            check_all_pions(etat);
            prepa_bomb_map(etat);
            int delay = check_counter(etat);
            if (delay == 1)
                central_initpartie(etat);/* à la fin de chaque set */
        }
        if (player_exist(etat)) {
            if (etat->partie == 5) /* fin de partie */
            {
                select_win(etat);
                pause = 0;
            }
            if (serialize_map(etat))
                central_send(etat);

        }
        SDL_Delay(100);
    }
    pthread_exit(NULL);
}

/*
 *
 */

void intern_ia_pions(void *tmp) {
    pthread_t p_thread;

    if (pthread_create(&p_thread, NULL, loop_ia_pion, (void *) tmp) < 0) {
        perror("could not create thread");
        return;
    }
    SDL_Delay(100);
}

/*
 * boucle de la IA
 */

int loop_ia(t_etat *etat) {
    int pause;
    pause = 1;
    int flag;

    flag = 1;
    while (pause) {
        pthread_mutex_lock(&lock);

        create_players_pions(etat);
        check_requete_player(etat);

        /* si le joueur n'a pas de speed */
        if (waitspeed == 0)
            SDL_Delay(200);

        if (etat->partie == 1 && flag == 1) /* MODIF ce base sur le compteur interne de la partie pour  */
        {
            intern_ia_pions(etat);
            flag = 0;
        }
        if (player_exist(etat)) /* MODIF vérifie qu'il existe des players avant d'envoyer un message */
        {
            if (etat->partie == 5)
            {
                select_win(etat);
                pause = 0;
            }

            if (serialize_map(etat))
                central_send(etat);

            /* desactive waitspeed */
            waitspeed = 0;

            if (pause != 0)
                pthread_cond_wait(&cv, &lock); /* MODIF AJOUT MUTEXT ET  pthread_cond_signal */
        }
        pthread_mutex_unlock(&lock);
    }
    return (1);
}
