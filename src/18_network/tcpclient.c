//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

/*
 *  envoi au serveur les données
 */
void *client_send_to_server(void *tmp) {
    pthread_detach(pthread_self());
    t_control *control = (t_control *) tmp;
   // write(control->network->socket_client, control->msg, (sizeof(t_clt_sd)));
    send(control->network->socket_client, (char*)&control->msg, sizeof(control->msg), 0);
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

    requete = (t_svr_sd *) malloc(sizeof(t_svr_sd));
    control->network->socket_client = socket(AF_INET, SOCK_STREAM, 0);
    if (control->network->socket_client == -1)
        return (0);

    server.sin_addr.s_addr = inet_addr(control->network->ip_serveur);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(control->network->socket_client, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error\n");
        return (0);
    }
    control->etat_send = 1;
    prepare_requet_client(control, 0, 1, 0, 0);

    char *buffer = (char *)malloc(sizeof(t_svr_sd));
    int sin_size = sizeof(buffer);

    while (control->etat_send) {
        if (recv(control->network->socket_client, (char*)&requete, sin_size, 0) < 0) {
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

