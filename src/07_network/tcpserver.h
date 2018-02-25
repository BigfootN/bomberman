//
// Created by layer on 25/02/18.
//

#ifndef BOMBERMAN_TCPSERVER_H
#define BOMBERMAN_TCPSERVER_H

#include "types.h"

int addClient(state_t* state, client_t* requete, int socket);
void* tcpClient(void* tmp);
void* server_receive_from_client(void* tmp);
void* server_to_client(void* tmp);
int send_request_uniq_player(state_t* state, int socket, int action, int message);
void deletePlayerDeconnect(state_t* state, int sock);

#endif //BOMBERMAN_TCPSERVER_H
