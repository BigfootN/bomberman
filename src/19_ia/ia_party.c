//
// Created by marc on 08/03/18.
//

#include "bomberman.h"

void central_initpartie(t_etat *etat) {

    /* arrete le jeux le temps de remettre tout en ordre */
    etat->partie = 0;
    /* initialise le speed */
    waitspeed = 0;
    //set_party = 0;

    /* calcul les gagant du set */

    /* selectionne une partie */
    clean_bm_monsters(etat);
    party_choice(etat);
    select_user_win(etat);
    cleanplayers(etat);

    /* permet de mettre le nombre de minutes pour chaque set */
    send_time(etat, 0);//  1 = 1 minute
    etat->partie = 1; /*fait repartir le jeux */
}

/* recupere la carte */
void party_choice(t_etat *etat) {
    int random;
    random = my_rand(3);

    if (random <= 1)
        gestion_data(etat, "carte1.lvl");
    else if (random == 2)
        gestion_data(etat, "carte2.lvl");
    else if (random == 3)
        gestion_data(etat, "carte3.lvl");
}

/* reinitialise les joueurs */
void cleanplayers(t_etat *etat) {
    t_player *players;
    t_etat *etat2;
    t_pions *pions;
//    t_pions *listpions;
    SDL_Rect mappos;
    //int flage_stop;

    mappos.x = 0;
    mappos.y = 0;
    mappos.h = 0;
    mappos.w = 0;

    etat2 = etat;
    players = etat2->players;
    pions = etat->last_pions;

    while (pions != NULL) {
        t_pions *state;
        state = pions->prev;
        if(pions != etat->last_pions)
            delete_list_chevron(pions);
        free(pions);
        pions = state;
        state = NULL;
    }
    pions = NULL;
    etat->last_pions = NULL;
    etat->pion = NULL;

    while (players != NULL) {
        if (players->socket_player > 0) {
            // on cree le joueur dans la liste des pions
            players->player = (t_pions *) malloc(sizeof(t_pions));
            players->player = add_item_pions(etat, mappos);/* ajoute l'user dans la liste des pions */

            players->player->id = players->id_connexion;
            players->player->type = 1;
            players->player->life = 20;
            init_gamers(etat, players->player); /* reinitialise le joueur avec ses données pour démarrer */
            players->player->active = 1;
            players->active = 1;
        }
        if (players->next == NULL)/* permet de prendre le dernier pions enregistré */
            etat->last_pions = players->player;
        players = players->next;
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

void select_win(t_etat *etat)
{
    /* determine qui est gangant ou perdant */
    int index = 0;
    int win = 0;
    int user_win = -1;

    while(index < 4)
    {
        if(etat->winusers[index] > win && win > 0) /* prend le vainqueur */
        {
            win = etat->winusers[index];
            user_win = index;
        }
        else if(etat->winusers[index] > win && win > 0) /* si plusieurs vainqueurs */
        {
            win = etat->winusers[index];
            update_user_win(etat,user_win);
            user_win = index;
        }
        index++;
    }
    if (user_win >= 0) /* pour le dernier */
        update_user_win(etat,user_win);
}
/* selectionne les vainqueurs */
void update_user_win(t_etat *etat, int user_id)
{
    t_pions *pion;

    pion = etat->pion;
    while(pion != NULL)
    {
        if(pion->id == user_id - 1)
            pion->win = 1;
        pion = pion->next;
    }
}
