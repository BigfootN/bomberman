//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_IA_PIONS_H
#define BOMBERMAN_IA_PIONS_H

void __check_list_pions(t_etat *etat);
void create_players_pions(t_etat *etat);
int check_all_pions(t_etat *etat);
void desactive_players(t_etat *etat, int numberPlayer);
t_pions *search_player(t_etat *etat, int numberPlayer);
void dead_pion(t_etat *etat, t_pions *tmp);
int check_requete_player(t_etat *etat);
void init_gamers(t_etat *etat, t_pions *player);
int collision_details(t_etat *etat, int dx, int dy);
int collision_bm(t_etat *etat, t_pions *player, int dx, int dy);
void move_pions(t_etat *etat, t_pions *player, int type, int value);
void delete_players(t_etat *etat);
void delete_pions(t_etat *etat);
void send_end_party(t_etat *etat);
void update_score_user(t_etat *etat, SDL_Rect posMap);
t_pions *wanted_pion_pos(t_etat *etat,int x, int y);

#endif //BOMBERMAN_IA_PIONS_H
