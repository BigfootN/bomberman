//
// Created by marc on 09/04/18.
//

#ifndef BOMBERMAN_WRITE_PREPA_GAME_H
#define BOMBERMAN_WRITE_PREPA_GAME_H

int my_convert_number(int c);
void create_requete_prepa_game(t_control *control);
void encart_write_minutes(t_control* control);
void encart_write_manches(t_control* control);
void write_game_set(t_control* control, int flag);
void encart_color_for_write(t_control* control);
void select_number(t_control *control, char *number);
void delete_number(t_control *control, SDL_Event event);

#endif //BOMBERMAN_WRITE_PREPA_GAME_H
