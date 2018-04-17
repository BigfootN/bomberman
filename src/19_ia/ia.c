//
// Created by marc on 01/03/18.
//

#include "headers.h"

/*
 * initialise la partie
 */

void *central_ia(void *tmp) {
    t_etat *etat;
    t_control *control = (t_control *) tmp;

    pthread_detach(pthread_self());

    etat = init_etat();
    transfert_data_party(etat, control);
    party_choice(etat);
    tcp_thread_server(etat); /* demarre le serveur */
    loop_ia(etat); /* demarre la ia */
    SDL_Delay(500);
    delete_etat(etat);

    pthread_exit((void *) tmp);
#if defined WIN32 || defined WIN64
    return (NULL);
#endif
}

/*
 * transfert les données de configuration du jeux
 */
void transfert_data_party(t_etat *etat, t_control *control) {
    etat->nbreset = control->nbreset;
    etat->minutesgame = control->minutesgame;
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
            if (serialize_map(etat))
                central_send(etat);
        }
        if (etat->partie == 5) /* fin de partie */
            pause = 0;
        SDL_Delay(100);
    }
    pthread_exit(NULL);
#if defined WIN32 || defined WIN64
    return (NULL);
#endif
}

/*
 * crée la ia pour les monstres et autres
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
        //pthread_mutex_lock(&lock);
        SDL_mutexP(lock);

        create_players_pions(etat);
        check_requete_player(etat);

        /* si le joueur n'a pas de speed */
//        if (waitspeed == 0)
//            SDL_Delay(200);

        if (etat->partie == 1 && flag == 1) /* MODIF ce base sur le compteur interne de la partie pour  */
        {
            intern_ia_pions(etat);
            flag = 0;
        }
        if (player_exist(etat)) /* MODIF vérifie qu'il existe des players avant d'envoyer un message */
        {
            if (etat->partie == 5) {
                select_win(etat);
                pause = 0;
            }

            if (serialize_map(etat))
                central_send(etat);

            /* desactive waitspeed */
            //waitspeed = 0;

            if (pause != 0)
                SDL_CondWait(cv, lock);
            // pthread_cond_wait(&cv, &lock); /* MODIF AJOUT MUTEXT ET  pthread_cond_signal */
        } else if (etat->partie == 5) {
            pause = 0;
        }

        SDL_mutexV(lock);
        //pthread_mutex_unlock(&lock);
    }
    return (1);
}
