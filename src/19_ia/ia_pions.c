//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

/*
 * function de test
 */

void __check_list_pions(t_etat *etat) {
    t_pions *tmp;

    tmp = etat->pion;
    while (tmp != NULL) {
        printf("type %d ", tmp->type);
        printf("id %d", tmp->id);
        printf("active %d ", tmp->active);
        printf("bombes %d ", tmp->bomb);
        printf("degat %d ", tmp->degat);
        printf("life %d ", tmp->life);
        printf("speed %d ", tmp->speed);
        printf("score %d ", tmp->score);
        tmp = tmp->next;
    }
}

/*
 * inscript l'user dans la partie
 */
int create_players_pions(t_etat *etat) {
    t_player *player;
    SDL_Rect mappos;
    int flag;

    flag = 0;
    player = etat->players;
    while (player != NULL) {
        if (player->active == 5) {
            mappos.x = 0;
            mappos.y = 0;
            mappos.w = 0;
            mappos.h = 0;
            player->player = (t_pions *) malloc(sizeof(t_pions));
            player->player = add_item_pions(etat, mappos);
            t_pions *pions = player->player;
            pions->speed = 0;
            pions->id = player->id_connexion;
            pions->type = 1;
            pions->life = 20;
            pions->sens = my_strdup("RIGHT");
            init_gamers(etat, player->player);
            pions->active = 1;
            player->active = 1;
            player->etat_requete = 0;
            player->requete_1 = 0;
            player->requete_2 = 0;
            send_requete_for_uniq_player(etat, player->socket_player, 1, player->id_connexion);
            flag = 1;
        }
        player = player->next;
    }
    return(flag);
}

int check_all_pions(t_etat *etat) {
    t_pions *pion;

    pion = etat->pion;
    while (pion != NULL) {
        if (etat->partie == 1) {
            if (pion->active == 1) {
                if (pion->etat_requete == 1) {
                    if (pion->requete_1 == 2) // bombe
                        etat_bomb(etat, pion);
                    else if (pion->requete_1 == 3) // deplacement monstre
                        if (pion->type >= 27 && pion->type <= 30)
                            ia_monster(etat, pion);
                }
            }
        }
        pion = pion->next;
    }
    return (1);
}

void desactive_players(t_etat *etat, int numberPlayer) {
    t_pions *tmp;

    tmp = etat->pion;

    while (tmp != NULL) {
        if (tmp->id == numberPlayer || tmp->type == numberPlayer) {
            if (tmp->active == 1) {
                tmp->active = 0;
                if (tmp->type != 1)
                    dead_pion(etat, tmp);
                return;
            }
        }
        tmp = tmp->next;
    }
}

t_pions *search_player(t_etat *etat, int numberPlayer) {
    t_pions *pion;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->id == numberPlayer)
            return (pion);
        else if (pion->type == numberPlayer)
            return (pion);

        pion = pion->next;
    }
    return (NULL);
}

void dead_pion(t_etat *etat, t_pions *tmp) {
    tmp->active = 0;
    //réinitialise à zero un bonus ou un player monstre
    etat->data_map->bmmap[tmp->mappos.x][tmp->mappos.y] = -1;
    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = -1;
    // detruit la bomb
    delete_list_chevron(tmp);
}

// incremente nouveau
void update_score_user(t_etat *etat, SDL_Rect posMap) {
    t_player *player;
    int userId;

    userId = etat->data_map->map_user_castdown[posMap.x][posMap.y];
    player = etat->players;

    if (userId != 0) {
        while (player != NULL) {
            if (player->player != NULL) {
                t_pions *pion = player->player;
                if (pion->id == userId)
                    pion->score += 1;
            }
            player = player->next;
        }
    }
}


/*
 * entrée des requetes
 */

int check_requete_player(t_etat *etat) {
    t_player *player;
    t_pions *tmp;

    player = etat->players;

    while (player != NULL) {
        if (player->player != NULL) {
            t_pions *pion = player->player;
            if (pion->active == 1) {
                tmp = player->player;
                //speed = tmp->speed;
                tmp->requete_1 = player->requete_1;
                tmp->requete_2 = player->requete_2;
                if (player->etat_requete == 1) {
                    if (player->requete_1 == 2 && etat->partie == 1)
                        move_pions(etat, tmp, 0, tmp->requete_2);
                    else if (player->requete_1 == 3 && etat->partie == 1)
                        move_pions(etat, tmp, 1, tmp->requete_2);
                    else if (player->requete_1 == 4 && etat->partie == 1)
                        init_bomb(etat, tmp);
                    else if (player->requete_1 == 6 && etat->partie == 1) {

                    } else if (player->requete_1 == 10)
                        init_gamers(etat, tmp);/* créé le joueur */
                    else if (player->requete_1 == 11) {
                        if (etat->partie == 0) /* debut de partie */
                        {
                            /* initialise le nombre de set pour la partie */
                            set_party = STEP;
                            /* permet de mettre le nombre de minutes pour chaque set */
                            send_time(etat, STEPTIME);//  1 = 1 minute
                        }
                        etat->partie = 1;
                    } else if (player->requete_1 == 12)
                        etat->partie = 2; /* fin de partie */
                }
                player->etat_requete = 0;
                player->requete_1 = 0;
                player->requete_2 = 0;
            }
        }
        player = player->next;
    }
    return (1);
}

// init gamer
void init_gamers(t_etat *etat, t_pions *player) {
    if (player->id == 1) {
        player->mappos.x = 1;
        player->mappos.y = 1;
        player->type = 23;
        etat->data_map->mapaction[1][1] = 23;
    } else if (player->id == 2) {
        player->mappos.x = 1;
        player->mappos.y = 13;
        player->type = 24;
        etat->data_map->mapaction[1][13] = 24;
    } else if (player->id == 3) {
        player->mappos.x = 9;
        player->mappos.y = 13;
        player->type = 25;
        etat->data_map->mapaction[9][13] = 25;
    } else if (player->id == 4) {
        player->mappos.x = 9;
        player->mappos.y = 1;
        player->type = 26;
        etat->data_map->mapaction[9][1] = 26;
    }
}

int collision_details(t_etat *etat, int dx, int dy) {
    int etatX = (0 <= dx && (etat->data_map->pos.x) >= dx);
    int etatY = (0 <= dy && (etat->data_map->pos.y) >= dy);

    if (etatX && etatY) {
        int tuile = etat->data_map->realmap[dx][dy];
        //printf("%d\n", tuile);
        if (etat->data_map->wall[tuile] == 1)
            return 0;
        else
            return 1;
    }
    return 0;
}

int collision_bm(t_etat *etat, t_pions *player, int dx, int dy) {
    t_pions *pion;

    int etatX = (0 <= dx && (etat->data_map->pos.x) >= dx);
    int etatY = (0 <= dy && (etat->data_map->pos.y) >= dy);

    if (etatX && etatY) {
        int bm = etat->data_map->bmmap[dx][dy];

        if (bm == 4)
            player->bomb += 1;
        else if (bm == 5) {
            if (player->bomb > 0)
                player->bomb -= 1;
        } else if (bm == 6)
            player->bomb += 3;
        else if (bm == 7)
            player->speed = 2;
        else if (bm == 8) {
            player->active = 0;
            player->life = 0;
            etat->data_map->mapaction[dx][dy] = -1;
        }
        // retire le BM
        if (bm != -1)
            etat->data_map->bmmap[dx][dy] = -1;

        int monster = etat->data_map->mapaction[dx][dy];
        if (monster >= 27 && monster <= 30) {
            SDL_Rect empl;
            empl.x = dx;
            empl.y = dy;
            t_pions *tmp = search_monster(etat, monster, empl);
            if (tmp != NULL) {
                if (player->life > tmp->life) {
                    delete_monster(etat, tmp->type, empl);
                    player->score += 1;
                    etat->data_map->mapaction[dx][dy] = player->id;
                } else {
                    player->active = 0;
                    player->life = 0;
                }
            }
        }

        // rencontre entre players le plus fort l'emporte
        int otherPlayer = etat->data_map->mapaction[dx][dy];
        if (otherPlayer >= 23 && otherPlayer <= 26) {
            pion = search_player(etat, otherPlayer);
            if (pion->life > player->life) {
                pion->life -= player->life;
                player->life = 0;
                player->active = 0;
            } else if (pion->life < player->life) {
                player->life -= pion->life;
                pion->life = 0;
                pion->active = 0;
                etat->data_map->mapaction[dx][dy] = player->id;
                player->score += 1;
            }
        }

        return (1);
    }
    return 0;
}

void move_pions(t_etat *etat, t_pions *player, int type, int value) {
    int col;
    int row;
    int dy;
    int dx;
    int index;
    int speed;
    index = 0;

    if (player->speed >= 2)
        speed = 2;
    else
        speed = 1;

    while (speed) {
        while (index < 1) {
            dx = player->mappos.x;
            dy = player->mappos.y;
            col = dy;
            row = dx;

            if (value == 0)
                value = -1;
            // prend en compte de maniere provisoire
            // pour le test collision
            if (type == 1 && value < 0)// left
                dx = player->mappos.x + value;
            else if (type == 1 && value > 0) // right
                dx = player->mappos.x + value;
            else if (type == 0 && value < 0) // up
                dy = player->mappos.y + value;
            else if (type == 0 && value > 0) /// bottom
                dy = player->mappos.y + value;

            if (collision_details(etat, dx, dy)) {
                int type;
                // mets a jour le joueur
                type = etat->data_map->mapaction[row][col];
                etat->data_map->mapaction[row][col] = -1;
                player->mappos.x = dx;
                player->mappos.y = dy;
                if (collision_bm(etat, player, dx, dy))/* verifie que l'emplacement est libre ou sinon fait le combat */
                    etat->data_map->mapaction[dx][dy] = type;
            } else
                return;
            index++;
        }
        speed--;
    }
}
// envoi du message de fin de rencontre et destruction des players
//int sendRequeteForUniqPlayer(t_etat *etat, int socket, int action, int message)

void delete_players(t_etat *etat) {
    t_player *player;

    player = etat->players; // utilisateur
    while (player != NULL) {
        send_requete_for_uniq_player(etat, player->socket_player, 3, 5);
        SDL_Delay(100);
        player = delete_list_player(player);
    }
    //free(player);
}

void delete_pions(t_etat *etat) {
    t_pions *pions;

    pions = etat->pion;
    while (pions != NULL) {
        pions = delete_list_chevron(pions);
    }
}

void send_end_party(t_etat *etat) {
    delete_pions(etat);
    //delete_pions(etat);
}
