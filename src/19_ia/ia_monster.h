//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_IA_MONSTER_H
#define BOMBERMAN_IA_MONSTER_H

void ia_monster(t_etat *etat, t_pions *tmp);
t_pions *search_monster(t_etat *etat, int numberMonster, SDL_Rect position);
void delete_monster(t_etat *etat, int numberMonster, SDL_Rect position);
int check_way(int **tab);
int checkFuturArea(t_etat *etat, int x, int y);
int conditionMove(int tab, int nbreWay);
int action_monster(t_etat *etat, SDL_Rect posOther, SDL_Rect pos_monster);
void monster_choice(t_etat *etat, t_pions *tmp, int **tab);
void __printf(int **tab);
int check_item_detect(int answer, int pion);
int **prepa_grid_bonus_malus(t_etat *etat, SDL_Rect position);

#endif //BOMBERMAN_IA_MONSTER_H
