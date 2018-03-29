//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

/*
 *  envoi au serveur les données
 */
void *client_send_to_server(void *tmp) {
    pthread_detach(pthread_self());
    t_clt_sd *requete;
    t_control *control = (t_control *) tmp;

    if((requete = (t_clt_sd *) malloc(sizeof(t_clt_sd))) == NULL)
        return (NULL);
    char *table;
    if((table = (char *) malloc(sizeof(char) * 2000)) == NULL)
        return (NULL);

    table = "helllo";
   // write(control->network->socket_client, control->msg, (sizeof(t_clt_sd)));
    send(control->network->socket_client, (char*)&control->msg, sizeof(requete), 0);
   // send(control->network->socket_client, table, sizeof(table), 0);
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
void *tcp_client(void *tmp) {

    t_svr_sd *requete;
    struct sockaddr_in server;
    t_control *control = (t_control *) tmp;

#if defined WIN32 || defined WIN64
    WSADATA wsa;
    printf("initialise winsock...");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0)
        printf("failed. error Code : %d", WSAGetLastError());
    //Create a socket
    if ((control->network->socket_client = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
    }
#elif defined __linux__
    control->network->socket_client = 0;
    control->network->socket_client = socket(AF_INET, SOCK_STREAM, 0);
    if (control->network->socket_client == -1)
    {
        printf("failed. error ");
        return (0);
    }
#endif
    printf("Socket created.\n");

    if((requete = (t_svr_sd *) malloc(sizeof(t_svr_sd))) == NULL)
        return (NULL);

    server.sin_addr.s_addr = inet_addr(control->network->ip_serveur);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(control->network->socket_client, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error\n");
        return (0);
    }
    control->etat_send = 1;
    prepare_requet_client(control, 0, 1, 0, 0);
  // char *buffer = (char *)malloc(sizeof(t_svr_sd));

    while (control->etat_send) {
        if (recv(control->network->socket_client, (char*)&requete, sizeof(requete), 0) < 0) {
            puts("recv failed\n");
            control->etat_send = 0;
            break;
        }
        if (control->mesg_en_bale == 0) {
            control->receive_map = requete;
            control->mesg_en_bale = 1;
        }
    }
    puts("client reception close\n");
    pthread_exit(NULL);
}

