//
// Created by marc on 09/04/18.
//

#ifndef BOMBERMAN_IA_H
#define BOMBERMAN_IA_H

void *central_ia(void *tmp);
void *loop_ia_pion(void *tmp);
void intern_ia_pions(void *tmp);
int loop_ia(t_etat *etat);
void transfert_data_party(t_etat *etat, t_control *control);

#endif //BOMBERMAN_IA_H
