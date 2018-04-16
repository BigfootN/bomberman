//
// Created by marc on 05/04/18.
//

#ifndef BOMBERMAN_INITS_H
#define BOMBERMAN_INITS_H

t_control *init_control();
void delete_control(t_control *control);
t_etat *init_etat();
void delete_etat(t_etat *etat);
void reinit_control(t_control *control);
//void realloc_ip_serveur(t_control *control);

#endif //BOMBERMAN_INITS_H
