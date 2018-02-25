#ifndef NETWORK_H
#define NETWORK_H

#include "types.h"
#include "tcp_server.h"
#include "tcp_client.h"
#include <pthread.h>

void tcp_thread_client(control_t *control);
void tcp_thread_server(void *tmp);

#endif
