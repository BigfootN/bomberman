//
// Created by marc on 08/03/18.
//

#ifndef BOMBERMAN_IA_PARTY_H
#define BOMBERMAN_IA_PARTY_H

void clean_bm_monsters(t_etat *etat);
void cleanplayers(t_etat *etat);
void party_choice(t_etat *etat);
void central_initpartie(t_etat *etat);
void select_user_win(t_etat *etat);
void update_user_win(t_etat *etat, int user_id);
void select_win(t_etat *etat);

#endif //BOMBERMAN_IA_PARTY_H
