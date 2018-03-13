//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_IA_EXPLOSION_H
#define BOMBERMAN_IA_EXPLOSION_H

void prepa_bomb_map(t_etat* etat);
void explosion_clean(t_etat* etat, int row, int col);
void display_fire(t_etat *etat, SDL_Rect lposition, int **tab);
int **check_array();
int check_tuple(t_etat *etat, int tuile);
void __print_explosion(int **tab);
int check_wall(int answer, int tuile, int pion);
int **prepa_grid_fire(t_etat *etat, SDL_Rect position);

#endif //BOMBERMAN_IA_EXPLOSION_H
