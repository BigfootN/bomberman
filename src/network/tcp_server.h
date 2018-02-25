#ifndef BOMBERMAN_TCPSERVER_H
#define BOMBERMAN_TCPSERVER_H

#include "types.h"
#include <pthread.h>
#include "ai_piece.h"
#include "tcp_client.h"
#include "add_network_player.h"

int dispatch_request(state_t*, client_t*);
void delete_player_disconnect(state_t*, int);
void* server_receive_from_client(void *);
int send_request_for_unique_player(state_t *, int, int, int);
void* server_to_client(void*);
void* tcp_server(void*);

#endif //BOMBERMAN_TCPSERVER_H
