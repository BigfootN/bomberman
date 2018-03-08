//
// Created by marc on 01/03/18.
//

#ifndef KERNEL_H
#define KERNEL_H

void window_init(t_control *control);
void encart_white(t_control* control);
void create_panel_white(t_control *control);
void create_panel(t_control *control);
void create_banderole(t_control *control);
void write_string(t_control *control, SDL_Rect renderquad, char* string);
void write_text_51(t_control* control, SDL_Rect renderQuad, char *string);
void display_button(t_control* control, SDL_Rect posdest);
void display_background_button(t_control* control, SDL_Rect posdest);
void create_panel_wait(t_control *control);
int dbl_click(int CurrentClickTicks, int Lastclickticks);

#endif //KERNEL_H
