#ifndef GAME_PANELS_H
#define GAME_PANELS_H

#include "types.h"
#include "define.h"

void create_panel_game(control_t *);
void create_area_map(control_t *);
void create_counter(control_t*);
void create_area_bonus(control_t *);
void display_map(control_t*, server_t *);
void create_panel_res(control_t *, server_t *);
void write_panel_score(control_t*, server_t*);

#endif
