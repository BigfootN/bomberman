#ifndef GAME_VIEWS_H
#define GAME_VIEWS_H

#include "types.h"
#include "game_display.h"
#include <pthread.h>
#include "ai.h"
#include "game_loop.h"

int central_game(control_t*);
void display_sprite(control_t*);
void display_screen_wait(control_t*);
void display_screen_game(control_t*);
void thread_ai();
void button_game(control_t*);

#endif
