#ifndef ADD_NETWORK_PLAYER_H
#define ADD_NETWORK_PLAYER_H

#include "types.h"
#include "linked_list.h"
#include "ai_piece.h"
#include "tcp_server.h"

void add_piece(state_t *state, int counter, int socket);
int check_first_record(state_t *state, int socket);
int reconnect_player(state_t *state, client_t *requete, int socket);
int *init_array_check_player();
int add_client(state_t *state, client_t *requete, int socket);

#endif
