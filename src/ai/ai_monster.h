#ifndef AI_MONSTER_H
#define AI_MONSTER_H

#include "types.h"
#include <string.h>

int check_way(int** arr);
void monster_choice(state_t* state, piece_t* tmp, int** arr);
int** init_grid_bonus_penalty(state_t* state, SDL_Rect pos);
piece_t* search_monster(state_t* state, int nb_monster, SDL_Rect pos);
void ai_monster(state_t* state, piece_t* tmp);
void del_monster(state_t* state, int nb_monster, SDL_Rect pos);

#endif
