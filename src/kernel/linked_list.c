#include "linked_list.h"

int check_pieces(t_pions* list) {
	if (list == NULL)
		return 1;
	else
		return 0;
}

t_pions* add_pieces(t_etat* etat, SDL_Rect mappos) {
	t_pions* tmp;

	if ((tmp = (t_pions*) malloc(sizeof (t_pions))) == NULL)
		return (NULL);

	tmp->id = 0;
	tmp->active = 0;
	tmp->mappos = mappos;
	tmp->life = 0;
	tmp->bomb = 5;
	tmp->life = 5;
	tmp->speed = 1;
	tmp->score = 0;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (etat->lastpions == NULL && etat->pion == NULL) {
		etat->lastpions = tmp;
		etat->pion = tmp;
	} else if (etat->lastpions != NULL) {
		etat->lastpions->next = tmp;
		tmp->prev = etat->lastpions;
		etat->lastpions = tmp;
	}
	return (tmp);
}

// mettre un & pour la list quand sollicité

t_piece* read_unit_piece(t_piece* list, int* tab) {
	if (list != NULL) {
		tab[0] = list->id;
		tab[2] = list->life;
		list = list->next;
	}
	return (list);
}

t_piece* delete_list_chevron(t_piece* tmp) {
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

t_player* addItemPlayer(t_etat* etat) {
	t_player* tmp;

	if ((tmp = (t_player*) malloc(sizeof (t_player))) == NULL)
		return (NULL);
	tmp->id_connexion = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->active = 1;
	if (etat->lastplayer == NULL && etat->players == NULL) {
		etat->players = tmp;
		etat->lastplayer = tmp;
	} else if (etat->lastplayer != NULL) {
		etat->lastplayer->next = tmp;
		tmp->prev = etat->lastplayer;
		etat->lastplayer = tmp;
	}
	return (tmp);
}

t_player* deleteListPlayer(t_player* tmp) {
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
