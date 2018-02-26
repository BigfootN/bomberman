#include "headers.h"

// doit avoir l'adresse du serveur

void tcpthreadClient(t_control *control)
{
    pthread_t p_thread;

    if (pthread_create(&p_thread, NULL, tcpClient, (void*) control) < 0)
    {
        perror("could not create thread");
        return;
    }
}

void tcpthreadServer(void *tmp)
{
    pthread_t p_thread;

    if (pthread_create(&p_thread, NULL, tcpServer, (void*) tmp) < 0)
    {
        perror("could not create thread");
        return;
    }
    SDL_Delay(100);
}