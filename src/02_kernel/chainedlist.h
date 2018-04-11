//
// Created by marc on 05/04/18.
//

#ifndef BOMBERMAN_CHAINEDLIST_H
#define BOMBERMAN_CHAINEDLIST_H

t_pions *add_pions(t_etat *etat, SDL_Rect mappos);
void delete_pion(t_etat *etat, t_pions *pion);
void delete_list_pions(t_etat *etat);
void init_pion(t_pions *pion);
void clean_players(t_etat *etat);
void delete_one_pion(t_etat *etat, int idpion);
void change_id_pion(t_pions *pion, int id_user);
int player_exist(t_etat *etat);

#endif //BOMBERMAN_CHAINEDLIST_H
