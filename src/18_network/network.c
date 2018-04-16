//
// Created by marc on 01/03/18.
//

#include "headers.h"

// doit avoir l'adresse du serveur

void tcp_thread_client(t_control *control) {
    SDL_Thread *thread;

    if (SDL_CreateThread(tcp_client, "tcp_client", (void *) control) < 0) {
        printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
    }

//    pthread_t p_thread;
//
//    if (pthread_create(&p_thread, NULL, tcp_client, (void*) control) < 0)
//    {
//        perror("could not create thread");
//        return;
//    }
}

void tcp_thread_server(void *control) {

    SDL_Thread *thread;

    if (SDL_CreateThread(tcp_server, "tcp_server", (void *) control) < 0) {
        printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
    }

//    pthread_t p_thread;
//
//    if (pthread_create(&p_thread, NULL, tcp_server, (void *) control) < 0) {
//        perror("could not create thread");
//        return;
//    }
    SDL_Delay(100);
}