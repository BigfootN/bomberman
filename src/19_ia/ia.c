//
// Created by marc on 01/03/18.
//

#include "bomberman.h"
/*
 * initilaise la partie
 */

void *central_ia(void *tmp)
{
    t_etat *etat;
    pthread_detach(pthread_self());

    if ((etat = (t_etat*) malloc(sizeof (t_etat))) == NULL)
        return NULL;
    etat = init_etat(etat);
    gestion_data(etat, "carte1.lvl");
    tcp_thread_server(etat);
    Loop_ia(etat);
    //sendEndParty(etat);
    pthread_exit((void *)tmp);
}

/*
 * boucle de la IA
 */
int Loop_ia(t_etat *etat)
{
    int pause;

    pause = 1;
    while (pause)
    {
        create_players_pions(etat);
        check_requete_player(etat);
        check_all_pions(etat);
        prepa_bomb_map(etat);
        check_counter(etat);
        if (serialize_map(etat))
            central_send(etat);

        if (etat->partie == 2)
            pause = 0;
        SDL_Delay(100);
    }
    return (1);
}
