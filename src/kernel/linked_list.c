#include "linked_list.h"


int check_pieces(piece_t* list) {
	if (list == NULL)
		return 1;
	else
		return 0;
}

piece_t* add_pieces(state_t* state, SDL_Rect map_pos) {
	piece_t* tmp;

	if ((tmp = (piece_t*) malloc(sizeof (piece_t))) == NULL)
		return (NULL);

	tmp->id = 0;
	tmp->is_activ = 0;
	tmp->map_pos = map_pos;
	tmp->life = 0;
	tmp->bomb = 5;
	tmp->life = 5;
	tmp->speed = 1;
	tmp->score = 0;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (state->last_piece == NULL && state->piece == NULL) {
		state->last_piece = tmp;
		state->piece = tmp;
	} else if (state->last_piece != NULL) {
		state->last_piece->next = tmp;
		tmp->prev = state->last_piece;
		state->last_piece = tmp;
	}
	return (tmp);
}

// mettre un & pour la list quand sollicité

piece_t* read_unipiece_t(piece_t* list, int* tab) {
	if (list != NULL) {
		tab[0] = list->id;
		tab[2] = list->life;
		list = list->next;
	}
	return (list);
}

piece_t* delete_list_chevron(piece_t* tmp) {
	if (tmp == NULL)
		return (NULL);
	if (tmp->next == NULL && tmp->prev != NULL)
		tmp->prev->next = NULL;
	//  else if (tmp->next == NULL && tmp->prev == NULL)
	//    free(tmp);
	else if (tmp->next != NULL && tmp->prev != NULL) {
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	if (tmp->prev != NULL)
		return (tmp->prev->next);
	else
		return (NULL);
}

player_t* addItemPlayer(state_t* state) {
	player_t* tmp;

	if ((tmp = (player_t*) malloc(sizeof (player_t))) == NULL)
		return (NULL);
	tmp->conn_id = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->is_activ = 1;
	if (state->last_player == NULL && state->players == NULL) {
		state->players = tmp;
		state->last_player = tmp;
	} else if (state->last_player != NULL) {
		state->last_player->next = tmp;
		tmp->prev = state->last_player;
		state->last_player = tmp;
	}
	return (tmp);
}

player_t* deleteListPlayer(player_t* tmp) {
	if (tmp == NULL)
		return (NULL);
	if (tmp->next == NULL && tmp->prev != NULL)
		tmp->prev->next = NULL;
	//  else if (tmp->next == NULL && tmp->prev == NULL)
	//    free(tmp);
	else if (tmp->next != NULL && tmp->prev != NULL) {
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	if (tmp->prev != NULL)
		return (tmp->prev->next);
	else
		return (NULL);
}
