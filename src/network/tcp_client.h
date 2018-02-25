#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "types.h"
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

void* client_send_to_server(void*);
int prepare_client_request(control_t *, int, int, int, int);
void* tcp_client(void*);

#endif
