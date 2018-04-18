//
// Created by marc on 01/03/18.
//

#include "headers.h"

void prepa_bomb_map(t_etat *etat) {
    int indexX;
    int indexY;
    SDL_Rect position;
    SDL_Rect posMap;
    int **tab;

    indexX = 0;
    while (indexX < etat->data_map->pos.x) {
        position.x = indexX;
        indexY = 0;
        while (indexY < etat->data_map->pos.y) {
            position.y = indexY;
            int tuile = etat->data_map->bmmap[indexX][indexY];
            if (tuile >= 100)/* fait exploser la bomb car 40 */
            {
                posMap.x = indexX;
                posMap.y = indexY;
                tab = prepa_grid_fire(etat, posMap);
                //__print_explosion(tab);
                /* soustrait pour avoir le numero du proprio */
                etat->data_map->map_user_castdown[indexX][indexY] = tuile - 100;
                display_fire(etat, position, tab);
                etat->data_map->bmmap[indexX][indexY] = 41;
                etat->data_map->map_user_castdown[indexX][indexY] = -1;
            } else if (tuile >= 41 && tuile <= 50)// temps explosion
            {
                etat->data_map->bmmap[indexX][indexY] += 1; /* on detruit definitevement l'explosion */
                if (etat->data_map->bmmap[indexX][indexY] >= 50) {
                    etat->data_map->bmmap[indexX][indexY] = -1;
                    explosion_clean(etat, indexX, indexY);
                }
            }
            indexY++;
        }
        indexX++;
    }
}

// nettoyage explosion
// ce deplace en haut a gauche du point pour faire tout les 9 tuples
// et desactive les sprites explosion

void explosion_clean(t_etat *etat, int row, int col) {
    int indexX;
    int indexY;
    SDL_Rect position;

    indexX = row - 2;
    while (indexX < row + 3) {
        if (0 <= indexX && (etat->data_map->pos.x) > indexX) {
            indexY = col - 2;
            while (indexY < col + 3) {
                if (0 <= indexY && (etat->data_map->pos.y) > indexY) {
                    int tuile = etat->data_map->mapaction[indexX][indexY];
                    int mur = etat->data_map->realmap[indexX][indexY];
                    if (tuile >= 9 && tuile <= 17)// tue ceux qui sont dedans
                    {
                        etat->data_map->mapaction[indexX][indexY] = -1;
                        // mettre les morts et désactiver les players

                    }
                    if (mur == 19) {
                        etat->data_map->realmap[indexX][indexY] = 18;
                        if (indexX - 1 >= 0 && etat->data_map->realmap[indexX - 1][indexY] == 21)
                            etat->data_map->realmap[indexX][indexY] = 22;
                        int sort = create_bonus_malus();
                        // ici mettre le bonus voulue
                        // action car un joueur ou un monstre ne peut pas y etre ne meme temps dans lorsque qu'ils se rencontre l'un
                        // ou l'autre reste et un bonus ou un malus apparait pour le monstre ou le joueur concerné
                        // si sort le sort est donné au joueur ou au monstre et disparait
                        if ((sort >= 27 && sort <= 30))
                        {
                            etat->data_map->mapaction[indexX][indexY] = sort;
                            position.x = indexX;
                            position.y = indexY;
                            /* incrente ici le compteur principal pour donner un id au bm */
                            etat->nbre_pions++;
                            // pour la suppression chercher aussi les emplacements x y lorsque un est trouvé
                            t_pions *pion = add_pions(etat, position);
                            pion->active = 1;
                            pion->id =  etat->nbre_pions;
                            pion->life = 5;
                            pion->etat_requete = 1;
                            if (sort >= 27 && sort <= 30)
                                pion->requete_1 = 3;
                            else
                               pion->requete_1 = 4;
                            pion->type = sort;
                        } else// pour les sorts simples
                            etat->data_map->bmmap[indexX][indexY] = sort;
                    }
                }
                indexY++;
            }
        }
        indexX++;
    }
}

// fait la meme chose pour l'explosion, que la bombe
// donne un effet de souffle

void display_fire(t_etat *etat, SDL_Rect lposition, int **tab) {
    int indexX;
    int indexY;
    int flag;
    SDL_Rect position;
    int col, row;

    indexX = 0;
    flag = 0;
    while (indexX < 5) {
        indexY = 0;
        while (indexY < 5) {
            if (tab[indexX][indexY] != 1) {
                col = 0;
                row = 0;
                flag = -1;
                position = lposition;

                if (indexX == 0 && indexY == 2) // pointe haut
                {
                    position.x -= 2;
                    flag = 9;
                } else if (indexX == 1 && indexY == 2) // centre haut
                {
                    position.x -= 1;
                    flag = 10;
                } else if (indexX == 2 && indexY == 0) // pointe milieu gauche
                {
                    position.y -= 2;
                    flag = 11;
                } else if (indexX == 2 && indexY == 1) // bras milieu gauche
                {
                    position.y -= 1;
                    flag = 12;
                } else if (indexX == 2 && indexY == 2) // centre
                    flag = 13;
                else if (indexX == 2 && indexY == 3) // bras centre droit
                {
                    position.y += 1;
                    flag = 14;
                } else if (indexX == 2 && indexY == 4) // pointe centre droit
                {
                    position.y += 2;
                    flag = 15;
                } else if (indexX == 3 && indexY == 2) // bras bas
                {
                    position.x += 1;
                    flag = 16;
                } else if (indexX == 4 && indexY == 2) // pointe bas
                {
                    position.x += 2;
                    flag = 17;
                }
                col = position.y;
                row = position.x;

                if (flag != -1) {// couloirs vides
                    if (tab[indexX][indexY] == 18 || tab[indexX][indexY] == 22)
                        etat->data_map->mapaction[row][col] = flag;
                    else if (tab[indexX][indexY] == 20) /* mur fractionnable*/
                        etat->data_map->realmap[row][col] = 19; /* change sur la carte de decor un object */
                    else if (tab[indexX][indexY] >= 23 && tab[indexX][indexY] <= 26) /* player */
                    {
                        update_score_user(etat, lposition);/* incremente le score */
                        int player = etat->data_map->mapaction[row][col];
                        etat->data_map->mapaction[row][col] = flag; /* on mets l'explosion */
                        // dire detruit avant de le supprimer
                        t_pions *pion = search_player(etat, player);
                        pion->active = 0;
                        pion->life = 0;
                    } else if ((tab[indexX][indexY] >= 27 && tab[indexX][indexY] <= 30) ||
                               (tab[indexX][indexY] >= 0 && tab[indexX][indexY] <= 8)) /* monstre ou bm */
                    {
                        update_score_user(etat, lposition);/* incremente le score */
                        //int monstre = etat->data_map->mapaction[row][col]; // supprimer immediatement
                        etat->data_map->mapaction[row][col] = flag; /* on mets l'explosion */
                       // desactive_players(etat, monstre); /* supprime immediatement du jeux */
                        t_pions *pion = wanted_pion_pos(etat, row, col);
                        if(pion != NULL)
                            dead_pion(etat, pion);
                    }
                }
            }
            indexY++;
        }
        indexX++;
    }
}

int **check_array() {
    int index;
    int index2;
    int **tab;

    index = 0;
    tab = (int **) malloc(sizeof(int *) * 5);
    if (tab == NULL)
        return (NULL);
    while (index < 5) {
        tab[index] = (int *) malloc(sizeof(int) * 5);
        if (tab[index] == NULL)
            return (NULL);
        index2 = 0;
        while (index2 < 5) {
            tab[index][index2] = 1;
            index2++;
        }
        index++;
    }
    return (tab);
}

// repere les tuiles murs et non amovibles
int check_tuple(t_etat *etat, int tuile) {
    if (etat->data_map->wall[tuile] == 1)//  && tuile != 20
        return 1;
    else
        return 0;
}
// mettre hors service les zombie et autres joueurs qui sont dans le lot

void __print_explosion(int **tab) {
    int index = 0;
    int col = 0;

    my_putstr("masque explosion\n\n");

    while (index < 5) {
        col = 0;
        while (col < 5) {
            printf("%d ", tab[index][col]);
            col++;
        }
        printf("\n");
        index++;
    }
    printf("\n");
}

int check_wall(int answer, int tuile, int pion) {
    int choice;

    choice = 0;

    if (tuile == 20)// si chemin libre
        choice = tuile;
    else if (answer == 1)// si mur on desactive
        choice = 1;
    else if (answer == 0 && (pion >= 23 && pion <= 26))// les players
        choice = pion;
    else if (answer == 0 && (pion >= 27 && pion <= 30)) // les autres monstres
        choice = pion;
    else if (answer == 0 && (pion >= 4 && pion <= 8)) // les bonus malus
        choice = pion;
    else if (answer == 0)
        choice = tuile;

    return (choice);
}

int **prepa_grid_fire(t_etat *etat, SDL_Rect position) {
    int index;
    int **tab;
    int answer;

    tab = check_array();
    answer = 0;
    index = position.x;
    while (index < position.x + 3) {// to bottom
        if (0 <= index && (etat->data_map->pos.x) > index) {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[index][position.y];
            int tuile = etat->data_map->realmap[index][position.y];
            if (check_tuple(etat, tuile))
                answer = 1;
            tab[(index + 2) - position.x][2] = check_wall(answer, tuile, pion);
        }
        index++;
    }

    answer = 0;
    index = position.x;
    while (index > position.x - 3) { // to up
        if (0 <= index && (etat->data_map->pos.x) > index) {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[index][position.y];
            int tuile = etat->data_map->realmap[index][position.y];
            if (check_tuple(etat, tuile))
                answer = 1;
            tab[(index + 2) - position.x][2] = check_wall(answer, tuile, pion);
        }
        index--;
    }

    answer = 0;
    index = position.y;
    while (index < position.y + 3) {
        if (0 <= index && (etat->data_map->pos.y) > index) {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[position.x][index];
            int tuile = etat->data_map->realmap[position.x][index];
            if (check_tuple(etat, tuile))
                answer = 1;
            tab[2][(index + 2) - position.y] = check_wall(answer, tuile, pion);
        }
        index++;
    }

    answer = 0;
    index = position.y;
    while (index > position.y - 3) {
        if (0 <= index && (etat->data_map->pos.y) > index) {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[position.x][index];
            int tuile = etat->data_map->realmap[position.x][index];
            if (check_tuple(etat, tuile))
                answer = 1;
            tab[2][(index + 2) - position.y] = check_wall(answer, tuile, pion);
        }
        index--;
    }
    return (tab);
}