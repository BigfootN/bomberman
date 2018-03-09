#include "headers.h"

/*
 * requete des clients
 */
int dispatchRequete(t_etat *etat, t_cltSd *tab)
{
    t_player *lplayer;

    lplayer = etat->players;
    while (lplayer != NULL)
    {
        if (lplayer->etat_requete == 0 &&
                tab->idClient == lplayer->id_connexion)
        {
            lplayer->etat_requete = 1;
            lplayer->requete_1 = tab->requete_1;
            lplayer->requete_2 = tab->requete_2;
            return (0);
        }
        lplayer = lplayer->next;
    }
    return (1);
}

void deletePlayerDeconnect(t_etat *etat, int sock)
{
    t_player *lplayer;
    lplayer = etat->players;
    while (lplayer != NULL)
    {
        if (lplayer->socket_player == sock)
        {
            etat->nbrePlayers--; // enleve le joueur
            lplayer->socket_player = -1;
            lplayer->id_connexion = -1;
            deadPion(etat, lplayer->player);
            return;
        }
        lplayer = lplayer->next;
    }
}

/*
 *  attente message client
 */

void *server_receive_from_client(void *tmp)
{
    t_cltSd *requete;
    t_etat *etat;
    int sock;
    int read_size;
    int stopServer;

    etat = (t_etat*) tmp;
    sock = etat->sock_tmp;
    stopServer = 1;

    if (sock == -1)
        return (NULL);
    if ((requete = (t_cltSd*) malloc(sizeof (t_cltSd))) == NULL)
        return (NULL);

    while (stopServer && ((read_size = recv(sock, requete, sizeof (t_cltSd), 0)) > 0))
    {
        if (requete->commandService == 1 && stopServer == 1)
            addClient(etat, requete, sock);
        else if (requete->commandService == 50)
        {
            shutdown(sock, 2);
            close(sock);
        }
        else if (stopServer == 1)
            dispatchRequete(etat, requete);
    }
    if (read_size == -1)
        perror("recv failed");
    puts("client disconnet\n");
    pthread_exit(NULL);
}

/*
 *  envoi un message pour un player specifique 
 */
int sendRequeteForUniqPlayer(t_etat *etat, int socket, int action, int message)
{
    etat->msg->commandService = action; /* envoi de son id*/
    etat->msg->reponse = message;
    etat->msg->idClient = message;
    etat->msg->departTime = etat->tdepart;
    write(socket, etat->msg, sizeof (t_svrSd));
    return (1);
}

/*
 *  envoi la map au client
 */
void *server_to_client(void *tmp)
{
    pthread_detach(pthread_self());
    t_etat *etat;
    etat = (t_etat*) tmp;

    if (etat->msg->pos[0] == 0)
        my_putstr("serveur envoi vide\n");
    write(etat->socket_send, etat->msg, sizeof (t_svrSd));
    pthread_exit(NULL);
}
/*
 *  serveur tcp
 */
void *tcpServer(void *tmp)
{
    int c;
    int client_sock;
    struct sockaddr_in server;
    struct sockaddr_in client;
    t_etat *etat = (t_etat*) tmp;

    etat->sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if (etat->sock_server == -1)
        return (0);
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
    while ((client_sock = accept(etat->sock_server, (struct sockaddr *) &client, (socklen_t*) & c)))
    {
        pthread_t p_thread;
        etat->sock_tmp = client_sock;
        if (pthread_create(&p_thread, NULL, server_receive_from_client, (void*) etat) < 0)
        {
            perror("could not create thread");
            return  (NULL);
        }
    }
    if (client_sock < 0)
    {
        perror("accept failed");
        return  (NULL);
    }
    pthread_exit(NULL);
}