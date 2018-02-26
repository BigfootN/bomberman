#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>

struct server_s;
typedef int socket_t;

typedef struct server_s {
	size_t nb_conn;
	socket_t* sockfd_clts;
	socket_t sockfd;
	size_t max_conn;
	struct sockaddr* addr;
} server_t;

server_t* server_init(const size_t, const size_t);
void server_kill(server_t*);
void server_free(server_t*);
void server_wait_conn(server_t*);
char* server_next_msg(server_t*, size_t*);

#endif
