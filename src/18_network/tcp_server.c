//
// Created by marc on 01/03/18.
//

#include "headers.h"

/*
 * requete des clients
 */
int dispatchRequete(t_etat *etat, t_clt_sd *tab) {
    t_pions *pion;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->id_connexion <= 4) {
            if (pion->etat_requete == 0 &&
                tab->idclient == pion->id_connexion) {
                /* ici bloque les envois si le gamer est speed */
//            if(pion->speed >= 2)
//                waitspeed = 1;
                pion->etat_requete = 1;
                pion->requete_1 = tab->requete_1;
                pion->requete_2 = tab->requete_2;
                return (0);
            }
        }
        pion = pion->next;
    }
    return (1);
}

void delete_player_deconnect(t_etat *etat, int sock) {
    t_pions *pion;

    pion = etat->pion;
    while (pion != NULL) {
        if (pion->type >= 23 && pion->type <= 26) {
            if (pion->socket_player == sock) {
                etat->data_map->bmmap[pion->mappos.x][pion->mappos.y] = -1;
                etat->data_map->mapaction[pion->mappos.x][pion->mappos.y] = -1;
                etat->nbre_players--;
                pion->active = 0; /* désactive le joueur */
                pion->id_connexion = 0;
                // pion->type = 0;
                pion->socket_player = 0;
                pion->life = 0;
                return;
            }
        }
        pion = pion->next;
    }
}

/*
 *  attente message client
 */

int server_receive_from_client(void *tmp) {
    t_clt_sd *requete;
    t_etat *etat;
    ssize_t read_size;
    etat = (t_etat *) tmp;
    int stop_client = 0;

#if defined WIN32 || defined WIN64
    SOCKET sock;
    sock = (SOCKET) etat->sock_tmp;
#elif defined __linux__
    int sock;
    sock = etat->sock_tmp;
#endif
    puts("client connet\n");

    if (sock == -1)
        return (1);
    if ((requete = (t_clt_sd *) malloc(sizeof(t_clt_sd))) == NULL)
        return (1);

    while (((read_size = recv(sock, (char *) requete, sizeof(t_clt_sd), 0)) > 0)) {
        requete = (t_clt_sd *) requete;
        etat = (t_etat *) tmp;
        /* ajoute le client a la partie */
        if (requete->commandservice == 1 && etat->partie == 0) {
            if (add_client(etat, requete, sock) == -1) { /* si trop de clients envoi au dernier un message */
                /* envoi message 7 pour dire trop de clients */
                send_requete_for_uniq_player(etat, sock, 7, 0);
#if defined WIN32 || defined WIN64
                closesocket(sock);
                WSACleanup();
#elif defined __linux__
                shutdown(sock, 2);
#endif
            } else {
                stop_client = 1;
                /* verification de la version */
                if (my_strcmp(requete->version, VERSION) != 0) {
                    /* enlever le joueur qui sort */
                    delete_player_deconnect(etat, sock);
                    /* envoi message 8 pour dire que la version est differente */
                    send_requete_for_uniq_player(etat, sock, 8, 0);
#if defined WIN32 || defined WIN64
                    closesocket(sock);
                    WSACleanup();
#elif defined __linux__
                    shutdown(sock, 2);
#endif
                }
            }
        } else if (requete->commandservice == 50) { /* deconnect le client et le server */
            /* enlever le joueur qui sort */
            delete_player_deconnect(etat, sock);
#if defined WIN32 || defined WIN64
            // int iResult = shutdown(etat->sock_server, SD_SEND);
            closesocket(sock);
            closesocket(etat->sock_server);
            WSACleanup();
#elif defined __linux__
            shutdown(etat->sock_server, 2);
            close(etat->sock_server);
            shutdown(sock, 2);
#endif
        } else if (requete->commandservice == 12) { /* deconnect le client */
            /* enlever le joueur qui sort */
            delete_player_deconnect(etat, sock);
#if defined WIN32 || defined WIN64
            closesocket(sock);
            WSACleanup();
#elif defined __linux__
            shutdown(sock, 2);
#endif
        } else if (requete->commandservice == 1 && etat->partie == 1) { /* deconnect le client */
            /* enlever le joueur qui sort */
            delete_player_deconnect(etat, sock);
            /* envoi message 6 pour dire la partie est déjà engagée */
            send_requete_for_uniq_player(etat, sock, 6, 0);
#if defined WIN32 || defined WIN64
            closesocket(sock);
            WSACleanup();
#elif defined __linux__
            shutdown(sock, 2);
#endif
        } else if (requete->commandservice != 1) {/* A VERIFIER */
            dispatchRequete(etat, requete);
            stop_client = 1;
        }
        if (stop_client == 1) /* fonctionne que pour des insctruction game et non client/server */
            SDL_CondSignal(cv);/* MODIF AJOUT MUTEXT ET  pthread_cond_signal */
    }

#if defined __linux__
    if (read_size == -1)
        perror("recv failed");
    close(sock);
#endif

    puts("client disconnet\n");
    return (1);
}

/*
 *  envoi un message pour un player specifique
 */
int send_requete_for_uniq_player(t_etat *etat, int socket, int action, int message) {
    etat->msg->command_service = action; /* envoi de son id*/
    etat->msg->reponse = message;
    etat->msg->idclient = message;
    etat->msg->depart_time = etat->tdepart;
    etat->msg->set_start = etat->set; /// initialise le set
    send(socket, (char *) etat->msg, sizeof(t_svr_sd), 0);
    return (1);
}

/*
 *  envoi la map au client
 */
void *server_to_client(void *tmp) {
    pthread_detach(pthread_self());
    t_etat *etat;
    etat = (t_etat *) tmp;
    if (etat->msg->pos[0] == 0)
        my_putstr("serveur envoi vide\n");
    send(etat->socket_send, (char *) etat->msg, sizeof(t_svr_sd), 0);
    pthread_exit(NULL);
}

int tcp_server(void *tmp) {
    int c;
    struct sockaddr_in server;
    struct sockaddr_in client;
    t_etat *etat = (t_etat *) tmp;
    int opt = 1;

    int activity;

#if defined WIN32 || defined WIN64
    SOCKET client_sock;
    SOCKET max_sd;
    WSADATA wsa;
    //crée la socket du serveur
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        printf("Failed. Error Code : %d", WSAGetLastError());
    printf("Initialised.\n");

    //Create a socket
    if ((etat->sock_server = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
    }
    printf("Socket created.\n");
#elif defined __linux__
    int client_sock;
    int max_sd;
    //crée la socket du serveur
    etat->sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if (etat->sock_server == -1)
        return (0);
#endif
    client_sock = 0;
    // permet le sconnexions multiples
    if (setsockopt(etat->sock_server, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(etat->sock_server, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed. Error\n");
        shutdown(etat->sock_server, 2);
#if defined WIN32 || defined WIN64
        closesocket(etat->sock_server);
        WSACleanup();
#elif defined __linux__
        close(etat->sock_server);
#endif
        return (1);
    }
    puts("bind done\n");

    listen(etat->sock_server, 4);
    puts("en attentes pour les connexions entrantes...");
    c = sizeof(struct sockaddr_in);
    //set of socket descriptors
    fd_set readfds;

    while (opt) {
        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(etat->sock_server, &readfds);
        max_sd = etat->sock_server;

        //wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        activity = select((int) max_sd + 1, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR)) {
            printf("select error : ");
            opt = 0;
        }

        //If something happened on the master socket , then its an incoming connection
        if (FD_ISSET(etat->sock_server, &readfds)) {
            if ((client_sock = accept(etat->sock_server, (struct sockaddr *) &client, (socklen_t *) &c))) {
                etat->sock_tmp = client_sock;
                if ((SDL_CreateThread(server_receive_from_client, "server_receive_from_client", (void *) etat)) < 0) {
                    printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
                    opt = 0;
                }
            }
        }
    }

#if defined WIN32 || defined WIN64
    closesocket(etat->sock_server);
    WSACleanup();
#elif defined __linux__
    close(etat->sock_server);
#endif

    if (client_sock < 0)
        perror("accept failed : ");
    puts("server disconnet\n");
    return (1);
}