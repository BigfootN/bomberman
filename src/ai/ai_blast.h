#ifndef AI_BLAST
#define AI_BLAST

#include "ai_bonus_penalty.h"
#include "types.h"

void init_bomb_map(state_t* state);
void display_fire(state_t* state, SDL_Rect lpos, int** tab);
void display_bomb_map(t_control* control);
int** check_array();
int check_tuple(state_t* state, int tuile);
int** init_grid_fire(state_t* state, SDL_Rect pos);
void blast_clean(state_t* state, int row, int col);

#endif
