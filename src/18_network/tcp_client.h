//
// Created by marc on 09/04/18.
//

#ifndef BOMBERMAN_TCP_CLIENT_H
#define BOMBERMAN_TCP_CLIENT_H

int prepare_requet_client(t_control *control, int idclient, int commandService, int requete_1, int requete_2);
int tcp_client(void *tmp);
//void *tcp_client(void *tmp);

#endif //BOMBERMAN_TCP_CLIENT_H
