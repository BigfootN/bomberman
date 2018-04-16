//
// Created by marc on 09/04/18.
//

#include "headers.h"

/*
 *  envoi au serveur les données
 */
void *client_send_to_server(void *tmp) {
//    t_clt_sd *requete;
    pthread_detach(pthread_self());
    t_control *control = (t_control *) tmp;

//    if ((requete = (t_clt_sd *) malloc(sizeof(t_clt_sd))) == NULL)
//        return (NULL);

    send(control->socket_client, (char *) control->msg, sizeof(t_clt_sd), 0);
    pthread_exit((void *) tmp);
}

/*
 * formate une requete pour le serveur
 */
int prepare_requet_client(t_control *control, int idclient, int commandService, int requete_1, int requete_2) {
    pthread_t p_thread;

    if (control->etat_send == 0)
        return (0);

    control->msg->idclient = idclient;
    control->msg->commandservice = commandService;
    control->msg->requete_1 = requete_1;
    control->msg->requete_2 = requete_2;

    if (pthread_create(&p_thread, NULL, client_send_to_server, (void *) control) < 0) {
        perror("could not create thread");
        return 1;
    }
    return (0);
}

/*
 * reception client tcp
 */

int tcp_client(void *tmp)
//void *tcp_client(void *tmp)
{
    t_svr_sd *requete;
    struct sockaddr_in server;
    t_control *control = (t_control *) tmp;

#if defined WIN32 || defined WIN64
    WSADATA wsa;
    printf("initialise winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        printf("failed. error Code : %d", WSAGetLastError());
    //Create a socket
    if ((control->socket_client = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
    }
#elif defined __linux__
    control->socket_client = 0;
    control->socket_client = socket(AF_INET, SOCK_STREAM, 0);
    if (control->socket_client == -1) {
        printf("failed. error ");
        return (0);
    }
    //    control->socket_client = socket(AF_INET, SOCK_STREAM, 0);
    //    if (control->socket_client == -1)
    //        return (0);
#endif

    if ((requete = (t_svr_sd *) malloc(sizeof(t_svr_sd))) == NULL)
        return (1);

    server.sin_addr.s_addr = inet_addr(control->ip_serveur);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(control->socket_client, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error\n");
        return (0);
    }
    control->etat_send = 1;
    prepare_requet_client(control, 0, 1, 0, 0);

    while (control->etat_send) {
        if (recv(control->socket_client, (char *) requete, sizeof(t_svr_sd), 0) < 0) {
            puts("client recv failed\n");
            control->etat_send = 0;
            break;
        }

        if (control->mesg_en_bale == 0) {
            control->receive_map = requete;
            control->mesg_en_bale = 1;
            /* si client */
            if (requete->pos[2] == 5 && control->master == 0)
                /* indique la fin de la connexion car la partie est finie */
                control->etat_send = 0;
            if (requete->command_service >= 6)
                /*
                 * quand le client est rejeté par le serveur trop d'users
                 * ou partie déjà démarrée
                 */
                control->etat_send = 0;
        }
    }

    control->etat_send = 0;

#if defined WIN32 || defined WIN64
    closesocket(control->socket_client);
#elif defined __linux__
    shutdown(control->socket_client, 2);
    close(control->socket_client);
#endif
    puts("client reception close\n");
    //pthread_exit(NULL);
    return (1);
}