#include "network.h"

// doit avoir l'adresse du serveur

void tcp_thread_client(control_t *control)
{
	pthread_t p_thread;

	if (pthread_create(&p_thread, NULL, tcp_client, (void*) control) < 0)
	{
		perror("could not create thread");
		return;
	}
}

void tcp_thread_server(void *tmp)
{
	pthread_t p_thread;

	if (pthread_create(&p_thread, NULL, tcp_server, (void*) tmp) < 0)
	{
		perror("could not create thread");
		return;
	}
	SDL_Delay(100);
}
