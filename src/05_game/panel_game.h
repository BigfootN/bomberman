//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_PANEL_GAME_H
#define BOMBERMAN_PANEL_GAME_H

void create_panel_result(t_control *control, t_svr_sd *requete);
void write_panel_score(t_control *control, t_svr_sd *requete);
void display_map(t_control *control, t_svr_sd *requete);
void create_area_bonus(t_control *control);
void display_counter(t_control *control, int minute1, int minute2, int seconde1, int seconde2);
void create_compteur(t_control *control);
void create_area_map(t_control *control);
void create_panel_game(t_control *control);
void clean_map(t_control *control, t_svr_sd *requete);
void create_party_start(t_control *control);
void create_max_users(t_control *control);

#endif //BOMBERMAN_PANEL_GAME_H
