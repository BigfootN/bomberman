#include "tcp_client.h"

/*
 *  envoi au serveur les données
 */
void *client_send_to_server(void *tmp)
{
	pthread_detach(pthread_self());
	control_t *control = (control_t*) tmp;
	write(control->network->socket_client, control->msg, (sizeof (client_t)));
	pthread_exit((void*) tmp);
}
/*
 * formate une requete pour le serveur
 */
int prepare_client_request(control_t *control, int client_id, int cmd_service, int request_1, int request_2)
{
	pthread_t p_thread;

	if (control->send_state == 0)
		return (0);

	control->msg->client_id = client_id;
	control->msg->cmd_service = cmd_service;
	control->msg->request_1 = request_1;
	control->msg->request_2 = request_2;

	if (pthread_create(&p_thread, NULL, client_send_to_server, (void*) control) < 0)
	{
		perror("could not create thread");
		return 1;
	}
	return (0);
}
/*
 * reception client tcp
 */
void *tcp_client(void *tmp)
{
	server_t *requete;
	struct sockaddr_in server;
	control_t *control = (control_t*) tmp;

	requete = (server_t*) malloc(sizeof (server_t));
	control->network->socket_client = socket(AF_INET, SOCK_STREAM, 0);
	if (control->network->socket_client == -1) {
		free(requete);
		return (0);
	}

	server.sin_addr.s_addr = inet_addr(control->network->server_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	if (connect(control->network->socket_client, (struct sockaddr *) &server, sizeof (server)) < 0)
	{
		free(requete);
		perror("connect failed. Error\n");
		return (0);
	}
	control->send_state = 1;
	prepare_client_request(control, 0, 1, 0, 0);

	while (control->send_state)
	{
		if (recv(control->network->socket_client, requete, sizeof (server_t), 0) < 0)
		{
			puts("recv failed\n");
			control->send_state = 0;
			break;
		}
		if (control->msg_enable == 0)
		{
			control->map_recv = requete;
			control->msg_enable = 1;
		}
	}
	puts("client reception close\n");
	pthread_exit(NULL);
}
