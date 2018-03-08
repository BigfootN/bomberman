//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

void ia_monster(t_etat *etat, t_pions *tmp)
{
    int **tab;

    if (tmp->life <= 15)
        tmp->life++;
    else
    {
        tmp->life = 10;
        tab = prepa_grid_bonus_malus(etat, tmp->mappos);
        monster_choice(etat, tmp, tab);
    }
}

t_pions *search_monster(t_etat *etat, int numberMonster, SDL_Rect position)
{
    t_pions *tmp;

    tmp = etat->pion;
    while (tmp != NULL)
    {
        if (tmp->active == 1)
            if (tmp->type == numberMonster)
                if ((position.x == tmp->mappos.x) && (position.y == tmp->mappos.y))
                    return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void delete_monster(t_etat *etat, int numberMonster, SDL_Rect position)
{
    t_pions *tmp;

    tmp = etat->pion;

    while (tmp != NULL)
    {
        if (tmp->active == 1)
        {
            if (tmp->type == numberMonster)
            {
                tmp->active = 0;
                if ((position.x == tmp->mappos.x) && (position.y == tmp->mappos.y))
                {
                    tmp->active = 0;
                    //réinitialise a zero un bonnus ou un player monstre
                    etat->data_map->bmmap[tmp->mappos.x][tmp->mappos.y] = -1;
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = -1;
                    // detruit le monstre
                    delete_list_chevron(tmp);
                    return;
                }
            }
        }
        tmp = tmp->next;
    }
}

// regarde nombre opportunitées

int check_way(int **tab)
{
    int nbre;

    nbre = 0;
    if (tab[2][1] == 0)
        nbre++;
    if (tab[2][3] == 0)
        nbre++;
    if (tab[1][2] == 0)
        nbre++;
    if (tab[3][2] == 0)
        nbre++;
    return (nbre);
}

// le monstre ce deplace
// deplacement automatique d'un monstre

int checkFuturArea(t_etat *etat, int x, int y)
{
    int wall = etat->data_map->realmap[x][y];

    if (wall != 1 && wall != 20)
        return 1;
    else
        return 0;
}

int conditionMove(int tab, int nbreWay)
{
    if ((tab != 1 && tab != 20) && (my_rand(30) >= 15 || nbreWay <= 1))
        return 1;
    else
        return 0;
}
// determine qui reste ou meurt lors d'une rencontre avec un monstre
// valable pour les players les sorts et autres monstres
// determiner si reste en vie ou non apres rencontre

int action_monster(t_etat *etat, SDL_Rect posOther, SDL_Rect pos_monster)
{
    int monster = etat->data_map->mapaction[posOther.x][posOther.y];
    int suivant = etat->data_map->mapaction[pos_monster.x][pos_monster.y];

    if ((suivant >= 23 && suivant <= 26)) // si un joueur sur sa route il le tue
    {
        t_pions *pion = search_player(etat, suivant);
        //pion->elist->active = 0;
        pion->active = 0;
        pion->life = 0;
        //desactivePlayers(etat, suivant);
    }
    else if (suivant >= 27 && suivant <= 30) // les autres monstres
        if (suivant > monster)// le monstre meurt
        {
            delete_monster(etat, monster, pos_monster);
            return (0); // mort
        }
        else // le monstre vie et l'autre monstre meurt
            delete_monster(etat, suivant, posOther);
    else if (suivant >= 4 && suivant <= 8) // les malus bonus il ne sont pas sensible et les détruisent
        delete_monster(etat, suivant, posOther);

    return (1); // vivant
}

void monster_choice(t_etat *etat, t_pions *tmp, int **tab)
{
    //tab[index][col]
    int position;
    int nbreWay;
    SDL_Rect posother;

    posother = tmp->mappos;
    nbreWay = check_way(tab);
    // remonter d'une ligne
    if (conditionMove(tab[1][2], nbreWay))// monte
    {
        if (my_strcmp(tmp->sens, "BOTTOM") != 0 || nbreWay <= 1)// si il existe une seule voie les conditions s'annule
        {
            position = tmp->mappos.x - 1;
            if ((0 <= position && (etat->data_map->pos.x) > position))
            {
                posother.x = position;
                if (action_monster(etat, tmp->mappos, posother) &&
                    checkFuturArea(etat, position, tmp->mappos.y))
                {
                    // ici mettre le depart du monstre effacer sa presence sur la carte
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = -1;
                    tmp->mappos.x -= 1;
                    tmp->sens = my_strdup("UP");
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = tmp->type;
                    return;
                }
            }
        }
    }
    // descendre d'une ligne
    if (conditionMove(tab[3][2], nbreWay)) // descend
    {
        if (my_strcmp(tmp->sens, "UP") != 0 || nbreWay <= 1)// si il existe une seule voie les conditions s'annule
        {
            position = tmp->mappos.x + 1;
            if ((0 <= position && (etat->data_map->pos.x) > position))
            {
                posother.x = position;
                if (action_monster(etat, tmp->mappos, posother) &&
                    checkFuturArea(etat, position, tmp->mappos.y))
                {
                    // ici mettre le depart du monstre effacer sa presence sur la carte
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = -1;
                    tmp->mappos.x += 1;
                    tmp->sens = my_strdup("BOTTOM");
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = tmp->type;
                    return;
                }
            }
        }
    }
    if (conditionMove(tab[2][1], nbreWay))// vers la gauche
    {//reculer d'une colonne
        if (my_strcmp(tmp->sens, "RIGHT") != 0 || nbreWay <= 1)// si il existe une seule voie les conditions s'annule
        {
            position = tmp->mappos.y - 1;
            if ((0 <= position && (etat->data_map->pos.y) > position))
            {
                posother.y = position;
                if (action_monster(etat, tmp->mappos, posother) &&
                    checkFuturArea(etat, tmp->mappos.x, position))
                {
                    // ici mettre le depart du monstre effacer sa presence sur la carte
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = -1;
                    tmp->mappos.y -= 1;
                    tmp->sens = my_strdup("LEFT");
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = tmp->type;
                    return;
                }
            }
        }
    }
    if (conditionMove(tab[2][3], nbreWay)) // vers la droite
    {// avancer d'une colonne
        if (my_strcmp(tmp->sens, "LEFT") != 0 || nbreWay <= 1)// si il existe une seule voie les conditions s'annule
        {
            position = tmp->mappos.y + 1;
            if ((0 <= position && (etat->data_map->pos.y) > position))
            {
                posother.y = position;
                if (action_monster(etat, tmp->mappos, posother) &&
                    checkFuturArea(etat, tmp->mappos.x, position))
                {
                    // ici mettre le depart du monstre effacer sa presence sur la carte
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = -1;
                    tmp->mappos.y += 1;
                    tmp->sens = my_strdup("RIGHT");
                    etat->data_map->mapaction[tmp->mappos.x][tmp->mappos.y] = tmp->type;

                    return;
                }
            }
        }
    }
    printf("sens du monstre %s\n", tmp->sens);
}

// le monstre rencontre un joueur

void __printf(int **tab)
{
    int index = 0;
    int col = 0;

    my_putstr("masque monsters\n\n");

    while (index < 5)
    {
        col = 0;
        while (col < 5)
        {

            printf("%d ", tab[index][col]);
            col++;
        }
        printf("\n");
        index++;
    }
    printf("\n");
}
// determiner qui il rencontre

int check_item_detect(int answer, int pion)
{
    int choice;

    if (answer == 0)// si chemin libre
        choice = 0;
    if (answer == 0 && (pion >= 23 && pion <= 26))// les players
        choice = pion;
    if (answer == 0 && (pion >= 27 && pion <= 30)) // les autres monstres
        choice = pion;
    if (answer == 0 && (pion >= 4 && pion <= 8)) // les bonus malus
        choice = pion;
    if (answer == 1)// si mur on desactive
        choice = 1;

    return (choice);
}

int **prepa_grid_bonus_malus(t_etat *etat, SDL_Rect position)
{
    //                             row col
    // control->dataMap->hidebonus[10][14] limite du tableau
    int index;
    int **tab;
    int answer;

    tab = check_array();
    answer = 0;
    index = position.x;
    // bas
    while (index < position.x + 3)
    {
        if ((0 <= index && (etat->data_map->pos.x) > index))
        {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[index][position.y];
            /* collision avec les murs */
            int tuile = etat->data_map->realmap[index][position.y];
            // check area
            if (check_tuple(etat, tuile))
                answer = 1;
            // check answer garde la meme colonne et descend les rows
            tab[(index + 2) - position.x][2] = check_item_detect(answer, pion);
        }
        index++;
    }

    // __printf(tab);

    answer = 0;
    index = position.x;
    // haut
    while (index > position.x - 3)
    {
        if ((0 <= index && (etat->data_map->pos.x) > index) &&
            (0 <= position.y && (etat->data_map->pos.y) > position.y))
        {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[index][position.y];
            int tuile = etat->data_map->realmap[index][position.y];
            if (check_tuple(etat, tuile))
                answer = 1;
            // garde la meme colone et monte
            tab[(index + 2) - position.x][2] = check_item_detect(answer, pion);
        }
        index--;
    }

    // __printf(tab);

    answer = 0;
    index = position.y;
    // vers la droite
    while (index < position.y + 3)
    {
        if ((0 <= index && (etat->data_map->pos.y) > index) &&
            (0 <= position.x && (etat->data_map->pos.x) > position.x))
        {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[position.x][index];
            int tuile = etat->data_map->realmap[position.x][index];
            if (check_tuple(etat, tuile))
                answer = 1;
            // on garde la meme row et on incremente
            tab[2][(index + 2) - position.y] = check_item_detect(answer, pion);
        }
        index++;
    }

    // __printf(tab);

    answer = 0;
    index = position.y;
    // vers la gauche
    while (index > position.y - 3)
    {
        if ((0 <= index && (etat->data_map->pos.y) > index) &&
            (0 <= position.x && (etat->data_map->pos.x) > position.x))
        {
            /* repaire les joueurs */
            int pion = etat->data_map->mapaction[position.x][index];
            int tuile = etat->data_map->realmap[position.x][index];
            if (check_tuple(etat, tuile))
                answer = 1;
            tab[2][(index + 2) - position.y] = check_item_detect(answer, pion);
        }
        index--;
    }

    __printf(tab);

    return (tab);
}