#include "tcp_server.h"
#include "ai_piece.h"

/*
 * requete des clients
 */
int dispatch_request(state_t *state, client_t *tab)
{
	player_t *lplayer;

	lplayer = state->players;
	while (lplayer != NULL)
	{
		if (lplayer->request_state == 0 &&
				tab->client_id == lplayer->conn_id)
		{
			lplayer->request_state = 1;
			lplayer->request_1 = tab->request_1;
			lplayer->request_2 = tab->request_2;
			return (0);
		}
		lplayer = lplayer->next;
	}
	return (1);
}

void delete_player_disconnect(state_t *state, int sock)
{
	player_t *lplayer;
	lplayer = state->players;
	while (lplayer != NULL)
	{
		if (lplayer->sockfd_player == sock)
		{
			state->nb_players--; // enleve le joueur
			lplayer->sockfd_player = -1;
			lplayer->conn_id = -1;
			kill_piece(state, lplayer->player);
			return;
		}
		lplayer = lplayer->next;
	}
}

/*
 *  attente message client
 */

void *server_receive_from_client(void *tmp)
{
	client_t *requete;
	state_t *state;
	int sock;
	int read_size;
	int stopServer;

	state = (state_t*) tmp;
	sock = state->sock_tmp;
	stopServer = 1;

	if (sock == -1)
		return (NULL);
	if ((requete = (client_t*) malloc(sizeof (client_t))) == NULL)
		return (NULL);

	while (stopServer && ((read_size = recv(sock, requete, sizeof (client_t), 0)) > 0))
	{
		if (requete->cmd_service == 1 && stopServer == 1)
			add_client(state, requete, sock);
		else if (requete->cmd_service == 50)
		{
			shutdown(sock, 2);
			close(sock);
		}
		else if (stopServer == 1)
			dispatch_request(state, requete);
	}
	if (read_size == -1)
		perror("recv failed");
	puts("client disconnet\n");
	pthread_exit(NULL);
}

/*
 *  envoi un message pour un player specifique
 */
int send_request_for_unique_player(state_t *state, int socket, int action, int message)
{
	state->msg->cmd_service = action; /* envoi de son id*/
	state->msg->response = message;
	state->msg->client_id = message;
	state->msg->start_time = state->start_time;
	write(socket, state->msg, sizeof (server_t));
	return (1);
}

/*
 *  envoi la map au client
 */
void *server_to_client(void *tmp)
{
	pthread_detach(pthread_self());
	state_t *state;
	state = (state_t*) tmp;

	if (state->msg->pos[0] == 0)
		printf("serveur envoi vide\n");
	write(state->socket_send, state->msg, sizeof (server_t));
	pthread_exit(NULL);
}
/*
 *  serveur tcp
 */
void *tcp_server(void *tmp)
{
	int c;
	int client_sock;
	struct sockaddr_in server;
	struct sockaddr_in client;
	state_t *state = (state_t*) tmp;

	state->sock_server = socket(AF_INET, SOCK_STREAM, 0);
	if (state->sock_server == -1)
		return (0);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	if (bind(state->sock_server, (struct sockaddr *) &server, sizeof (server)) < 0)
	{
		perror("bind failed. Error\n");
		close(state->sock_server);
		shutdown(state->sock_server, 2);
		return (NULL);
	}
	puts("bind done\n");

	listen(state->sock_server, 10);
	puts("en attentes pour les connexions entrantes...");
	c = sizeof (struct sockaddr_in);
	while ((client_sock = accept(state->sock_server, (struct sockaddr *) &client, (socklen_t*) & c)))
	{
		pthread_t p_thread;
		state->sock_tmp = client_sock;
		if (pthread_create(&p_thread, NULL, server_receive_from_client, (void*) state) < 0)
		{
			perror("could not create thread");
			return  (NULL);
		}
	}
	if (client_sock < 0)
	{
		perror("accept failed");
		return  (NULL);
	}
	pthread_exit(NULL);
}
