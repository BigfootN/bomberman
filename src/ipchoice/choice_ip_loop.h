#ifndef CHOICE_IP_LOOP
#define CHOICE_IP_LOOP

#include "types.h"
#include "define.h"
#include "kernel.h"
#include "choice_ip_window.h"

int choice_menu_choice_ip(control_t*, SDL_Event);
void select_data(control_t*);
void events_loop_ip_choice(control_t*, int*);

#endif
