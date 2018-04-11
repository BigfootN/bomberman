//
// Created by marc on 05/04/18.
//

#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

FILE *open_file(char *name);
char filtre(char c);
int write_config_map(t_etat *etat, int *list);
int gestion_map(t_etat *etat, char *name);
void init_sort(t_etat *etat);
void initi_map(t_etat *etat, FILE *fp);

#endif //BOMBERMAN_MAP_H
