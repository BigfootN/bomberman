#ifndef IA_H
#define IA_H

#include "game.h"
#include "types.h"

//iasendmsg
void checkPlayerActif(state_t* state);
void sendEmail(state_t* state);
void CentralSend(state_t* state);

// ia.c
int IALooop();
void* centralIA();
// iapieces.c
int checkRequete(state_t* state);
void move_piece(state_t* state, piece_t* player, int type, int value);
void kill_piece(state_t* state, piece_t* tmp);
void deactivate_players(state_t* state, int numberPlayer);
void send_end_game(state_t* state);
piece_t* search_player(state_t* state, int numberPlayer);
int collision_bitmap(state_t* state, piece_t* player, int dx, int dy);
int check_all_pieces(state_t* state);
int check_requesplayer_t(state_t* state);

// iamap
int serializeMap(state_t* state);
// iabomb.c
void bomb_init(state_t* state, piece_t* player);
void bomb_state(state_t* state, piece_t* player);
//ia explosion.c
void prepaBombMap(state_t* state);
void displayFire(state_t* state, SDL_Rect lposition, int** tab);
void displayBombMap(t_control* control);
int** checkArray();
int checktuple(state_t* state, int tuile);
int** prepaGridFire(state_t* state, SDL_Rect position);
void explosionClean(state_t* state, int row, int col);
//iamonster
int checkWay(int** tab);
void monsterChoice(state_t* state, piece_t* tmp, int** tab);
int** prepaGridBonusMalus(state_t* state, SDL_Rect position);
piece_t* search_monster(state_t* state, int numberMonster, SDL_Rect position);
void IAMonster(state_t* state, piece_t* tmp);
void del_monster(state_t* state, int numberMonster, SDL_Rect position);
// iagame.c
void* centralIA(void* tmp);
//iaTime
void time_start(state_t* state);
void difference(state_t* state);
//iacounter
void counter_player_init(state_t* state, player_t* player);
int checkCounter(state_t* state);
//iabonusmalus
int bonus_penalty_init();

#endif
