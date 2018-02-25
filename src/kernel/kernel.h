#ifndef KERNEL_H
#define KERNEL_H

#include "types.h"
#include "define.h"
//#include "choice_ip_window.h"

void window_init(control_t*);
void encart_clair(control_t*);
void create_panel_white(control_t*);
void create_panel(control_t*);
void create_banner(control_t *);
void write_str(control_t *, SDL_Rect, char*);
void display_button(control_t*, SDL_Rect);
void display_background_button(control_t*, SDL_Rect);
void create_panel_wait(control_t *);
int dbl_click(int, int);
void write_text(control_t*);

#endif
