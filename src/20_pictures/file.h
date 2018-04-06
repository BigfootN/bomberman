//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_FILE_H
#define BOMBERMAN_FILE_H

char filtre(char c);
int write_configMap(t_etat *etat, int *list);
int gestion_data(t_etat *etat, char *name);
FILE *open_file(char *name);
void initi_map(t_etat *etat, FILE *fp);
void init_sort(t_etat *etat);

#endif //BOMBERMAN_FILE_H
