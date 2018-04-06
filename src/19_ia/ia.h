//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_IA_H
#define BOMBERMAN_IA_H

int loop_ia(t_etat *etat);
void *central_ia(void *tmp);
int player_exist(t_etat *etat);

void *loop_ia_pion(void *tmp);
void intern_ia_pions(void *tmp);

#endif //BOMBERMAN_IA_H
