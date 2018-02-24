#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "types.h"

int check_pieces(piece_t*);
t_piece* add_pieces(state_t*, SDL_Rect);
t_piece* read_unit_piece(t_piece*, int*);
t_piece* delete_list_chevron(t_piece*);

#endif
