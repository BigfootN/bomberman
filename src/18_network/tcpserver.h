//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_TCPSERVER_H
#define BOMBERMAN_TCPSERVER_H

int waitspeed;

int dispatchRequete(t_etat *etat, t_clt_sd *tab);
void delete_player_deconnect(t_etat *etat, int sock);
void *server_receive_from_client(void *tmp);
//static int server_receive_from_client(void *tmp);
int send_requete_for_uniq_player(t_etat *etat, int socket, int action, int message);
void *server_to_client(void *tmp);
void *tcp_server(void *tmp);
int mutex_update(int local_compteur);

#endif //BOMBERMAN_TCPSERVER_H
