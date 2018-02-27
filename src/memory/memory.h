#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

void player_free(player_t*);
void piece_free(piece_t*);
void clmap_free(clmap_t*);
void state_free(state_t*);
void control_free(control_t*);
void free_network(network_t*);
void free_coord(coord_t*);
void free_point(point_t*);
void free_client_state(client_state_t*);

#endif
