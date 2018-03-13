//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_VIEWS_GAME_H
#define BOMBERMAN_VIEWS_GAME_H

int central_game(t_control *control);
void display_sprite(t_control *control);
void display_screen_wait(t_control *control);
void display_screen_game(t_control *control);
void thread_ia();
void button_game(t_control* control);
void screen_result(t_control *control,  t_svr_sd *requete);
void screen_wait_end_set(t_control *control);
void display_counter_header(t_control *control, int *tabl);

#endif //BOMBERMAN_VIEWS_GAME_H
