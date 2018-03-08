//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_CHOICEIPWINDOW_H
#define BOMBERMAN_CHOICEIPWINDOW_H

void create_etiquettes(t_control *control);
void write_text(t_control* control);
int my_choice_number(int c);
char * delete_data(t_control* control, SDL_Event event);
char *write_data(SDL_Event event, char *tmp);

#endif //BOMBERMAN_CHOICEIPWINDOW_H
