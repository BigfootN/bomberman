#include "ai_dead.h"

int del_inactive_piece(state_t* state) {
	piece_t* tmp;

	tmp = state->piece;
	while (tmp != NULL) {
		if (tmp->active == 0)
			if (tmp->type > 26 && tmp->type < 23) {
				if (tmp->type >= 27 && tmp->type <= 30);
				tmp = deleteListChevron(tmp);
			}
		tmp = tmp->next;
	}
	return (1);
}
