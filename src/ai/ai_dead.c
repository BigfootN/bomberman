#include "ai_dead.h"
#include "../kernel/linked_list.h"

int del_inis_activ_piece(state_t* state) {
	piece_t* tmp;

	tmp = state->piece;
	while (tmp != NULL) {
		if (tmp->is_activ == 0)
			if (tmp->type > 26 && tmp->type < 23) {
				if (tmp->type >= 27 && tmp->type <= 30)
				tmp = delete_list_chevron(tmp);
			}
		tmp = tmp->next;
	}
	return (1);
}
