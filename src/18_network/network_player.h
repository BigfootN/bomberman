//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_ADDNETWORKPLAYER_H
#define BOMBERMAN_ADDNETWORKPLAYER_H

void add_pion(t_etat *etat, int counter, int socket);
int check_first_record(t_etat *etat, int socket);
int reconnect_player(t_etat *etat, t_clt_sd *requete, int socket);
int *init_array_check_player();
int add_client(t_etat *etat, t_clt_sd *requete, int socket);

#endif //BOMBERMAN_ADDNETWORKPLAYER_H
