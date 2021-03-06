#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

#include "types.h"
#include "define.h"
#include "game_views.h"
#include "kernel.h"
#include "game_panels.h"
#include "game_time.h"
#include "tcp_client.h"

int recv_signal(const int, void*);
void check_answer_serv(control_t*);
void start_game(control_t*);

#endif
