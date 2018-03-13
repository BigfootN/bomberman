//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_INITSPRITES_H
#define BOMBERMAN_INITSPRITES_H

int central_init_sprites(t_control *control);
int init_sprites(t_control *control);
int init_menu(t_control *control);
int init_bandeau(t_control *control);
int init_intro(t_control *control);
int init_police(t_control *control);
int init_attente(t_control *control);
int init_panneau_resultat(t_control *control);
char *create_directory_file(char const *name, int directory);
int init_manche(t_control *control);

#endif //BOMBERMAN_INITSPRITES_H
