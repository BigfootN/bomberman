//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

/*
 * requete des clients
 */
int dispatchRequete(t_etat *etat, t_clt_sd *tab) {
    t_player *lplayer;

    lplayer = etat->players;
    while (lplayer != NULL) {
        if (lplayer->etat_requete == 0 &&
            tab->idclient == lplayer->id_connexion) {
            /* ici bloque les envois si le gamer est speed */
//            if (lplayer ->player->speed >= 2) // faux le chevron n'est pas bon
//                waitspeed = 1;
            lplayer->etat_requete = 1;
            lplayer->requete_1 = tab->requete_1;
            lplayer->requete_2 = tab->requete_2;
            return (0);
        }
        lplayer = lplayer->next;
    }
    return (1);
}

void delete_player_deconnect(t_etat *etat, int sock) {
    t_player *lplayer;
    lplayer = etat->players;
    while (lplayer != NULL) {
        if (lplayer->socket_player == sock) {
            etat->nbre_players--; // enleve le joueur
            lplayer->socket_player = -1;
            lplayer->id_connexion = -1;
            dead_pion(etat, lplayer->player);
            return;
        }
        lplayer = lplayer->next;
    }
}

/*
 *  attente message client
 */

void *server_receive_from_client(void *tmp) {
    t_clt_sd *requete;
    t_etat *etat;
#if defined WIN32 || defined WIN64
    SOCKET sock;
#elif defined __linux__
    int sock;
#endif
    int read_size;

    etat = (t_etat *) tmp;
    sock = etat->sock_tmp;

    if (sock == -1)
        return (NULL);
    if ((requete = (t_clt_sd *) malloc(sizeof(t_clt_sd))) == NULL)
        return (NULL);

    while (((read_size = recv(sock, (char *) &requete, sizeof(requete), 0)) != SOCKET_ERROR)) {

        requete = (t_clt_sd *) requete;
        etat = (t_etat *) tmp;
        sock = (SOCKET) etat->sock_tmp;

        if (requete->commandservice == 1)
            add_client(etat, requete, (int) etat->sock_tmp);
        else if (requete->commandservice == 50) // deconnect le client
        {
            shutdown(sock, 2);
            // close(etat->sock_tmp);
        } else {
            dispatchRequete(etat, requete);
        }
        requete = (t_clt_sd *) malloc(sizeof(t_clt_sd));
        pthread_cond_signal(&cv);  // MODIF AJOUT MUTEXT ET  pthread_cond_signal
    }
    if (read_size == -1)
        perror("recv failed");
    puts("client disconnet\n");
    pthread_exit(NULL);
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
    //write(socket, etat->msg, sizeof(t_svr_sd));
    send(socket, (char *) &etat->msg, sizeof(etat->msg), 0);
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
    // write(etat->socket_send, etat->msg, sizeof(t_svr_sd));
    send(etat->socket_send, (char *) &etat->msg, sizeof(etat->msg), 0);
    pthread_exit(NULL);
}

int mutex_update(int local_compteur) {
    pthread_mutex_lock(&mutex);
    local_compteur = compteur_mutex;
    local_compteur++;
    compteur_mutex = local_compteur;
    pthread_mutex_unlock(&mutex);
    return (local_compteur);
}

#if defined WIN32 || defined WIN64

void *tcp_server(void *tmp) {

    WSADATA wsa;
    int c;
    SOCKET client_sock;
    struct sockaddr_in server;
    struct sockaddr_in client;
    t_etat *etat = (t_etat *) tmp;
    int opt = 1;
    int max_sd;
    int activity;
    int local_compteur;

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

    // permet les connexions multiples
    if (setsockopt(etat->sock_server, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(etat->sock_server, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed. Error\n");
        shutdown(etat->sock_server, 2);
        return (NULL);
    }
    puts("bind done\n");

    listen(etat->sock_server, 10);
    c = sizeof(struct sockaddr_in);
    //   c = sizeof(etat->sock_server);
    puts("en attentes pour les connexions entrantes...");

    fd_set readfds;
    local_compteur = 0;
    max_sd = 0;

    while (opt) {
//        struct sockaddr_in client;
//        SOCKET client_sock;

        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(etat->sock_server, &readfds);
       // max_sd = (int) etat->sock_server;

        local_compteur = mutex_update(local_compteur);
        //wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
      //  activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        max_sd++;
        activity = select(0, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR))
            printf("select error");
        //If something happened on the master socket , then its an incoming connection

        if (FD_ISSET(etat->sock_server, &readfds)) {
            SOCKET   socket = (int) etat->sock_server;
            client_sock = 0;
            if ((client_sock = accept(socket, (struct sockaddr *) &client, (socklen_t *) &c))) {

//                t_clt_sd* requete;
//                if ((requete = (t_clt_sd *) malloc(sizeof(t_clt_sd))) == NULL)
//                    return (NULL);
//
////                char *table;
////                if((table = (char *) malloc(sizeof(char) * 2000)) == NULL)
////                    return (NULL);
//                getpeername(client_sock, (struct sockaddr *) &client, (socklen_t *) &c);
//             //   if (((recv(client_sock, table, sizeof(table), 0)) != SOCKET_ERROR)) {
////               if (((recv(client_sock, (char *)&requete, sizeof(requete), 0)) != SOCKET_ERROR)) {
//               if (((recv(client_sock, (char *)&requete, sizeof(requete), 0)) != SOCKET_ERROR)) {
//                    requete = (t_clt_sd *) requete;
//                }

                pthread_t p_thread;
                etat->sock_tmp = client_sock;
                if (pthread_create(&p_thread, NULL, server_receive_from_client, (void *) etat) < 0) {
                    opt = 0; //desactive le serveur
                    perror("could not create thread");
                }
            }
        }
    }
    closesocket(etat->sock_server);
    WSACleanup();
    pthread_exit(NULL);
}

#elif defined __linux__

void *tcp_server(void *tmp)
{
    int c;
    int client_sock;
    struct sockaddr_in server;
    struct sockaddr_in client;
    t_etat *etat = (t_etat*) tmp;
    int opt = 1;
    int max_sd;
    int activity;
    int local_compteur;

    //crée la socket du serveur
    etat->sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if (etat->sock_server == -1)
        return (0);

    // pemret les connexions multiples
    if (setsockopt(etat->sock_server, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof (opt)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(etat->sock_server, (struct sockaddr *) &server, sizeof (server)) < 0)
    {
        perror("bind failed. Error\n");
        close(etat->sock_server);
        shutdown(etat->sock_server, 2);
        return (NULL);
    }
    puts("bind done\n");

    listen(etat->sock_server, 10);
    puts("en attentes pour les connexions entrantes...");
    c = sizeof (struct sockaddr_in);
    //set of socket descriptors
    fd_set readfds;
    local_compteur = 0;

    while (opt)
    {
        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(etat->sock_server, &readfds);
        max_sd = etat->sock_server;

        local_compteur = mutex_update(local_compteur);

        //wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR))
            printf("select error");

        //If something happened on the master socket , then its an incoming connection
        if (FD_ISSET(etat->sock_server, &readfds))
        {
            if ((client_sock = accept(etat->sock_server, (struct sockaddr *) &client, (socklen_t*) & c)))
            {
                pthread_t p_thread;
                etat->sock_tmp = client_sock;
                if (pthread_create(&p_thread, NULL, server_receive_from_client, (void*) etat) < 0)
                {
                    perror("could not create thread");
                    opt = 0; //desactive le serveur
                    return (NULL);
                }
            }
        }
    }

    if (client_sock < 0)
    {
        perror("accept failed");
        return (NULL);
    }
    pthread_exit(NULL);
}

#endif