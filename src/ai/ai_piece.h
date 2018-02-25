#ifndef AI_PIECE_H
#define AI_PIECE_H

#include "types.h"

// iapieces.c
int check_request(state_t* state);
void move_piece(state_t* state, piece_t* player, int type, int value);
void kill_piece(state_t* state, piece_t* tmp);
void deactivate_players(state_t* state, int nb_players);
void send_end_game(state_t* state);
piece_t* search_player(state_t* state, int nb_players);
void init_gamers(state_t* state, piece_t* player);
int collision_bitmap(state_t* state, piece_t* player, int dx, int dy);
int check_all_pieces(state_t* state);
int check_requesplayer_t(state_t* state);

#endif
