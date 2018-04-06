//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_TCPCLIENT_H
#define BOMBERMAN_TCPCLIENT_H

void *client_send_to_server(void *tmp);
int prepare_requet_client(t_control *control, int idclient, int commandService, int requete_1, int requete_2);
void *tcp_client(void *tmp);

#endif //BOMBERMAN_TCPCLIENT_H
