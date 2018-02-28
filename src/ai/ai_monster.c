#include <linked_list.h>
#include "ai_monster.h"
#include "ai_piece.h"
#include "ai_blast.h"

// determine qui reste ou meurt lors d'une rencontre avec un monstre
// valable pour les players les sorts et autres monstres
// determiner si reste en vie ou non apres rencontre
static int monster_action(state_t* state, SDL_Rect posOther, SDL_Rect posMonster) {
	int monster;
	int next;

	monster = state->map_info->action_map[posOther.x][posOther.y];
	next = state->map_info->action_map[posMonster.x][posMonster.y];

	if ((next >= 23 && next <= 26)) {
		// si un joueur sur sa route il le tue
		piece_t* piece = search_player(state, next);
		//piece->elist->is_activ = 0;
		piece->is_activ = 0;
		piece->life = 0;
		//deactivate_players(state, next);
	} else if (next >= 27 && next <= 30)
		// les autres monstres
		if (next > monster) {
			// le monstre meurt
			del_monster(state, monster, posMonster);
			return (0);
			// mort
		} else
			// le monstre vie et l'autre monstre meurt
			del_monster(state, next, posOther);
	else if (next >= 4 && next <= 8)
		// les malus bonus il ne sont pas clock_directionible et les détruisent
		del_monster(state, next, posOther);

	return (1);
	// vivant
}

static int check_area(const state_t* state, const int x, const int y) {
	const int wall = state->map_info->real_map[x][y];

	if (wall != 1 && wall != 20)
		return 1;
	else
		return 0;
}

static int move_condition(int arr, int nb_way) {
	if ((arr != 1 && arr != 20) && (rand() >= 15 || nb_way <= 1))
		return 1;
	else
		return 0;
}

static int check_item_detect(int answer, int piece) {
	int choice;

	if (answer == 0)
		// si chemin libre
		choice = 0;
	if (answer == 0 && (piece >= 23 && piece <= 26))
		// les players
		choice = piece;
	if (answer == 0 && (piece >= 27 && piece <= 30))
		// les autres monstres
		choice = piece;
	if (answer == 0 && (piece >= 4 && piece <= 8))
		// les bonus malus
		choice = piece;
	if (answer == 1)
		// si mur on desis_activ
		choice = 1;

	return (choice);
}

void ai_monster(state_t* state, piece_t* tmp) {
	int** tab;

	if (tmp->life <= 15)
		tmp->life++;
	else{
		tmp->life = 10;
		// determiner les objects qui l'entoure
		tab = init_grid_bonus_penalty(state, tmp->map_pos);
		// determiner son clock_direction
		monster_choice(state, tmp, tab);
	}
}

piece_t* search_monster(state_t* state, int nb_monster, SDL_Rect pos) {
	piece_t* tmp;

	tmp = state->piece;
	while (tmp != NULL) {
		if (tmp->is_activ == 1)
			if (tmp->type == nb_monster)
				if ((pos.x == tmp->map_pos.x) && (pos.y == tmp->map_pos.y))
					return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void del_monster(state_t* state, int nb_monster, SDL_Rect pos) {
	piece_t* tmp;

	tmp = state->piece;

	while (tmp != NULL) {
		if (tmp->is_activ == 1) {
			if (tmp->type == nb_monster) {
				tmp->is_activ = 0;
				if ((pos.x == tmp->map_pos.x) && (pos.y == tmp->map_pos.y)) {
					tmp->is_activ = 0;
					//réinitialise a zero un bonnus ou un player monstre
					state->map_info->penalty_bonus_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
					// detruit le monstre
					delete_list_chevron(tmp);
					return;
				}
			}
		}
		tmp = tmp->next;
	}
}

// regarde nombre opportunitées
int check_way(int** tab) {
	int nbre;

	nbre = 0;
	if (tab[2][1] == 0)
		nbre++;
	if (tab[2][3] == 0)
		nbre++;
	if (tab[1][2] == 0)
		nbre++;
	if (tab[3][2] == 0)
		nbre++;
	return (nbre);
}

// le monstre ce deplace
// deplacement automatique d'un monstre

void monster_choice(state_t* state, piece_t* tmp, int** tab) {
	int pos;
	int nb_way;
	SDL_Rect posother;

	posother = tmp->map_pos;
	nb_way = check_way(tab);
	// remonter d'une ligne
	if (move_condition(tab[1][2], nb_way)) {
		// monte
		if (strcmp(tmp->clock_direction, "BOTTOM") != 0 || nb_way <= 1) {
			// si il existe une seule voie les conditions s'annule
			pos = tmp->map_pos.x - 1;
			if ((0 <= pos && (state->map_info->pos.x) > pos)) {
				posother.x = pos;
				if (monster_action(state, tmp->map_pos, posother) &&
					check_area(state, pos, tmp->map_pos.y)) {
					// ici mettre le depart du monstre effacer sa presence sur la carte
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
					tmp->map_pos.x -= 1;
					tmp->clock_direction = strdup("UP");
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = tmp->type;
					return;
				}
			}
		}
	}
	// descendre d'une ligne
	if (move_condition(tab[3][2], nb_way)) {
		// descend
		if (strcmp(tmp->clock_direction, "UP") != 0 || nb_way <= 1) {
			// si il existe une seule voie les conditions s'annule
			pos = tmp->map_pos.x + 1;
			if ((0 <= pos && (state->map_info->pos.x) > pos)) {
				posother.x = pos;
				if (monster_action(state, tmp->map_pos, posother) &&
					check_area(state, pos, tmp->map_pos.y)) {
					// ici mettre le depart du monstre effacer sa presence sur la carte
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
					tmp->map_pos.x += 1;
					tmp->clock_direction = strdup("BOTTOM");
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = tmp->type;
					return;
				}
			}
		}
	}
	if (move_condition(tab[2][1], nb_way)) {
		// vers la gauche
		//reculer d'une colonne
		if (strcmp(tmp->clock_direction, "RIGHT") != 0 || nb_way <= 1) {
			// si il existe une seule voie les conditions s'annule
			pos = tmp->map_pos.y - 1;
			if ((0 <= pos && (state->map_info->pos.y) > pos)) {
				posother.y = pos;
				if (monster_action(state, tmp->map_pos, posother) &&
					check_area(state, tmp->map_pos.x, pos)) {
					// ici mettre le depart du monstre effacer sa presence sur la carte
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
					tmp->map_pos.y -= 1;
					tmp->clock_direction = strdup("LEFT");
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = tmp->type;
					return;
				}
			}
		}
	}
	if (move_condition(tab[2][3], nb_way)) {
		// vers la droite
		// avancer d'une colonne
		if (strcmp(tmp->clock_direction, "LEFT") != 0 || nb_way <= 1) {
			// si il existe une seule voie les conditions s'annule
			pos = tmp->map_pos.y + 1;
			if ((0 <= pos && (state->map_info->pos.y) > pos)) {
				posother.y = pos;
				if (monster_action(state, tmp->map_pos, posother) &&
					check_area(state, tmp->map_pos.x, pos)) {
					// ici mettre le depart du monstre effacer sa presence sur la carte
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
					tmp->map_pos.y += 1;
					tmp->clock_direction = strdup("RIGHT");
					state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = tmp->type;

					return;
				}
			}
		}
	}
}

// determiner qui il rencontre

int** init_grid_bonus_penalty(state_t* state, SDL_Rect pos) {
	//                             row col
	// control->map_info->hidebonus[10][14] limite du tableau
	int index;
	int** tab;
	int answer;

	tab = check_array();

	answer = 0;
	index = pos.x;
	// bas
	while (index < pos.x + 3) {
		if ((0 <= index && (state->map_info->pos.x) > index)) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[index][pos.y];
			/* collision avec les murs */
			int tile = state->map_info->real_map[index][pos.y];
			// check area
			if (check_tuple(state, tile))
				answer = 1;
			// check answer garde la meme colonne et descend les rows
			tab[(index + 2) - pos.x][2] = check_item_detect(answer, piece);
		}
		index++;
	}

	answer = 0;
	index = pos.x;
	// haut
	while (index > pos.x - 3) {
		if ((0 <= index && (state->map_info->pos.x) > index) &&
			(0 <= pos.y && (state->map_info->pos.y) > pos.y)) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[index][pos.y];
			int tile = state->map_info->real_map[index][pos.y];
			if (check_tuple(state, tile))
				answer = 1;
			// garde la meme colone et monte
			tab[(index + 2) - pos.x][2] = check_item_detect(answer, piece);
		}
		index--;
	}

	answer = 0;
	index = pos.y;
	// vers la droite
	while (index < pos.y + 3) {
		if ((0 <= index && (state->map_info->pos.y) > index) &&
			(0 <= pos.x && (state->map_info->pos.x) > pos.x)) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[pos.x][index];
			int tile = state->map_info->real_map[pos.x][index];
			if (check_tuple(state, tile))
				answer = 1;
			// on garde la meme row et on incremente
			tab[2][(index + 2) - pos.y] = check_item_detect(answer, piece);
		}
		index++;
	}

	answer = 0;
	index = pos.y;
	// vers la gauche
	while (index > pos.y - 3) {
		if ((0 <= index && (state->map_info->pos.y) > index) &&
			(0 <= pos.x && (state->map_info->pos.x) > pos.x)) {
			/* repaire les joueurs */
			int piece = state->map_info->action_map[pos.x][index];
			int tile = state->map_info->real_map[pos.x][index];
			if (check_tuple(state, tile))
				answer = 1;
			tab[2][(index + 2) - pos.y] = check_item_detect(answer, piece);
		}
		index--;
	}

	return (tab);
}
