//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_CHAINEDLIST_H
#define BOMBERMAN_CHAINEDLIST_H

int check_pions(t_pions *list);
t_pions *add_item_pions(t_etat *etat, SDL_Rect mappos);
t_pions *read_unit_pions(t_pions *list, int *tab);
t_pions *delete_list_chevron(t_pions *tmp);
t_player *add_item_player(t_etat *etat);
t_player *delete_list_player(t_player *tmp);

#endif //BOMBERMAN_CHAINEDLIST_H
