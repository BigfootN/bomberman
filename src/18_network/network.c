//
// Created by marc on 01/03/18.
//

#include "../00_headers/headers.h"
#include "bomberman.h"

// doit avoir l'adresse du serveur

void tcp_thread_client(t_control *control)
{
   pthread_t p_thread;

    if (pthread_create(&p_thread, NULL, tcp_client, (void*) control) < 0)
    {
        perror("could not create thread");
        return;
    }
    //pthread_join(store_user.thread_clients[store_user.index], NULL);
   // store_user.index++;
}

void tcp_thread_server(void *tmp)
{
     pthread_t p_thread;
    // compteur_mutex = 0;

    // pthread_mutex_init (&mutex, NULL);
     if (pthread_create (&p_thread, NULL, tcp_server, (void*) tmp) < 0)
   // if (pthread_create(&initial_loop.thread_server, NULL, tcp_server, (void*) tmp) < 0)
    {
        perror("could not create thread");
        return;
    }
   // pthread_join(store_user.thread_clients[store_user.index], NULL);
   // store_user.index++;
    SDL_Delay(100);
}
