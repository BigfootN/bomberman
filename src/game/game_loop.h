#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "types.h"
#include "define.h"
#include "tcp_client.h"
#include "game_display.h"
#include "kernel.h"

int area_button(control_t*, SDL_Event);
void game_loop(control_t*, int*);

#endif
