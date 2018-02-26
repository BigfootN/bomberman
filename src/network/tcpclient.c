#include "headers.h"

/*
 *  envoi au serveur les données
 */
void *client_send_to_server(void *tmp)
{
    pthread_detach(pthread_self());
    t_control *control = (t_control*) tmp;
    write(control->network->socket_client, control->msg, (sizeof (t_cltSd)));
    pthread_exit((void*) tmp);
}
/*
 * formate une requete pour le serveur
 */
int prepare_requetClient(t_control *control, int idclient, int commandService, int requete_1, int requete_2)
{
    pthread_t p_thread;

    if (control->etatsend == 0)
        return (0);

    control->msg->idClient = idclient;
    control->msg->commandService = commandService;
    control->msg->requete_1 = requete_1;
    control->msg->requete_2 = requete_2;

    if (pthread_create(&p_thread, NULL, client_send_to_server, (void*) control) < 0)
    {
        perror("could not create thread");
        return 1;
    }
    return (0);
}
/*
 * reception client tcp
 */
void *tcpClient(void *tmp)
{
    t_svrSd *requete;
    struct sockaddr_in server;
    t_control *control = (t_control*) tmp;

    requete = (t_svrSd*) malloc(sizeof (t_svrSd));
    control->network->socket_client = socket(AF_INET, SOCK_STREAM, 0);
    if (control->network->socket_client == -1)
        return (0);

    server.sin_addr.s_addr = inet_addr(control->network->ipserveur);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(control->network->socket_client, (struct sockaddr *) &server, sizeof (server)) < 0)
    {
        perror("connect failed. Error\n");
        return (0);
    }
    control->etatsend = 1;
    prepare_requetClient(control, 0, 1, 0, 0);

    while (control->etatsend)
    {
        if (recv(control->network->socket_client, requete, sizeof (t_svrSd), 0) < 0)
        {
            puts("recv failed\n");
            control->etatsend = 0;
            break;
        }
        if (control->mesgenbale == 0)
        {
            control->receiveMap = requete;
            control->mesgenbale = 1;
        }
    }
    puts("client reception close\n");
    pthread_exit(NULL);
}