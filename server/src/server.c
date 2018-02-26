#include "server.h"

static struct sockaddr* init_addr(int port) {
	struct sockaddr_in* addr;
	struct sockaddr* ret;

	addr = malloc(sizeof(*addr));
	addr->sin_addr.s_addr = INADDR_ANY;
	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);

	ret = (struct sockaddr*) addr;

	return ret;
}

static void init_socket(socket_t* sockfd, struct sockaddr* addr) {
	*sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bind(*sockfd, addr, sizeof(struct sockaddr_in));
}

static void save_client(server_t* server, const socket_t sockfd_clt) {
	const size_t nb_conn = server->nb_conn + 1;

	server->sockfd_clts = realloc(server->sockfd_clts, nb_conn);
	server->sockfd_clts[nb_conn - 1] = sockfd_clt;
	server->nb_conn++;
}

server_t* server_init(const size_t port, const size_t max_conn) {
	server_t* ret;

	ret = malloc(sizeof(*ret));

	ret->nb_conn = 0;
	ret->sockfd_clts = NULL;
	ret->max_conn = max_conn;

	ret->addr = init_addr(port);
	init_socket(&(ret->sockfd), ret->addr);

	return ret;
}

void server_kill(server_t* server) {
	close(server->sockfd);
}

void server_free(server_t* server) {
	free(server->sockfd_clts);
	free(server);
}

void server_wait_conn(server_t* server) {
	socket_t sockfd_clt;
	const size_t max_conn = server->max_conn;

	while (server->nb_conn < max_conn) {
		sockfd_clt = accept(server->sockfd, NULL, NULL);
		save_client(server, sockfd_clt);
	}
}

char* server_next_msg(server_t* server, size_t* msg_length) {
	fd_set read_fds;
	int select_res;
	char* ret;

	ret = NULL;
	FD_ZERO(&read_fds);
	FD_SET(server->sockfd, &read_fds);

	select_res = select(server->sockfd + 1, &read_fds, NULL, NULL, NULL);
	if (select_res != -1) {
		if (FD_ISSET(server->sockfd, &read_fds)) {
			ioctl(server->sockfd, FIONREAD, msg_length);
			ret = malloc(sizeof(*ret) * *msg_length);
			read(server->sockfd, ret, *msg_length);
		}
	}

	FD_CLR(server->sockfd, &read_fds);

	return ret;
}
