//
// Created by marc on 08/03/18.
//

#include "headers.h"

void central_initpartie(t_etat *etat) {

    /* arrete le jeux le temps de remettre tout en ordre */
    etat->partie = 0;
    etat->send_message = 0;
    SDL_Delay(1000);
    /* initialise le speed */
    //waitspeed = 0;
    etat->nbreset--;

    /* selectionne une partie */
    clean_bm_monsters(etat);
    party_choice(etat);
    select_user_win(etat);
    cleanplayers(etat);

    SDL_Delay(1000);
    if (etat->nbreset > 0)
        /* permet de mettre le nombre de minutes pour chaque set */
        send_time(etat, etat->minutesgame);//  1 = 1 minute
    else /* fin de partie */
    {
        etat->minutesgame = 0;
        select_win(etat);
        etat->etat_party_chrono = 0;
        etat->partie = 5;/* determine la fin */
    }
    SDL_Delay(1000);
    if (etat->partie != 5) {
        etat->partie = 1; /*fait repartir le jeux */
    }
    etat->send_message = 1;
}

/* recupere la carte */
void party_choice(t_etat *etat) {
    int random;
    random = my_rand(3);

    if (random <= 1)
        gestion_map(etat, "carte1.lvl");
    else if (random == 2)
        gestion_map(etat, "carte2.lvl");
    else if (random == 3)
        gestion_map(etat, "carte3.lvl");
}

/* reinitialise les joueurs */
void cleanplayers(t_etat *etat) {
    t_pions *pion;

    pion = etat->last_pions;
    while (pion != NULL) {
        t_pions *state;
        state = pion->prev;

        if (pion->type < 23 || pion->type > 26) {
            delete_pion(etat, pion);
            //delete_one_pion(etat, pion->id);
        }
        pion = state;
        // free(state);
    }
    etat->last_pions = NULL;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->id_connexion >= 1 && pion->id_connexion <= 4) {
            // on cree le joueur dans la liste des pions
            pion->active = 0;
            init_pion(pion);
            pion->id = pion->id_connexion;
            pion->type = 1;
            pion->life = 20;
            pion->bomb = 5;
            init_gamers(etat, pion); /* reinitialise le joueur avec ses données pour démarrer */
            pion->active = 1;
        }
        if (pion->next == NULL)/* permet de prendre le dernier pions enregistré */
            etat->last_pions = pion;
        pion = pion->next;
    }
}

/* nettoie les grilles des monstres et autres */
void clean_bm_monsters(t_etat *etat) {
    int row;
    int col;

    row = 0;
    while (row < etat->data_map->pos.x) {
        col = 0;
        while (col < etat->data_map->pos.y) {
            /* nettoie la map de travail */
            etat->data_map->map_user_castdown[row][col] = -1;
            etat->data_map->bmmap[row][col] = -1;
            etat->data_map->mapaction[row][col] = -1;
            etat->data_map->realmap[row][col] = -1;

            /* nettoie la map du message */
            etat->msg->map_action[row][col] = -1;
            etat->msg->map_bm[row][col] = -1;
            etat->msg->map_decor[row][col] = -1;

            col++;
        }
        row++;
    }
}

/* selection du vainqueur du set */
void select_user_win(t_etat *etat) {
    //   t_player *players;
    t_pions *pions;
    int win;
    int tab[4];
    int index;

    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;
    tab[3] = 0;
    win = 0;

    pions = etat->pion;

    /* récupère les résultats */
    while (pions != NULL) {
        if (pions->type >= 23 && pions->type <= 26) {
            if (pions->score >= win && pions->score > 0) {
                win = pions->score;
                tab[pions->type - 23] = win;
            }
        }
        pions = pions->next;
    }
    /* ajoute au */
    index = 0;
    while (index < 4) {
        if (tab[index] >= win && win > 0)
            etat->winusers[index] += 1;
        index++;
    }
}
/* mets les vainqueurs du jeux */
void select_win(t_etat *etat) {

    t_pions *pion;
    /* determine qui est gangant ou perdant */
    int index = 0;
    int win = 0;
   // int user_win = -1;

    while (index < 4) {
        if (etat->winusers[index] > win && etat->winusers[index] > 0) /* prend le vainqueur */
        {
            win = etat->winusers[index];
            // user_win = index;
        }
// else if (etat->winusers[index] > win && win > 0) /* si plusieurs vainqueurs */
//        {
//            win = etat->winusers[index];
//            update_user_win(etat, user_win);
//            user_win = index;
//        }
        index++;
    }

    if (win <= 0)
        return;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->id < 4) {
            if (etat->winusers[pion->id - 1] == win)
                pion->winner = 1;
        }
        pion = pion->next;
    }

//    if (user_win >= 0) /* pour le dernier */
//        update_user_win(etat, user_win);
}

/* selectionne les vainqueurs */
void update_user_win(t_etat *etat, int user_id) {
    t_pions *pion;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->id == user_id + 1)
            pion->winner = 1;
        pion = pion->next;
    }

}
