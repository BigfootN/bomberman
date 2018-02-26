#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "types.h"

int check_pieces(piece_t*);
piece_t* add_pieces(state_t*, SDL_Rect);
piece_t* read_unipiece_t(piece_t*, int*);
piece_t* delete_list_chevron(piece_t*);

#endif
