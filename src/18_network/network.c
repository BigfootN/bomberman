//
// Created by marc on 01/03/18.
//

#include "headers.h"

// doit avoir l'adresse du serveur

void tcp_thread_client(t_control *control) {
    if ((SDL_CreateThread(tcp_client, "tcp_client", (void *) control)) == NULL) {
        printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
    }
}

void tcp_thread_server(void *control) {

    if (SDL_CreateThread(tcp_server, "tcp_server", (void *) control) == NULL) {
        printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
    }
    SDL_Delay(100);
}