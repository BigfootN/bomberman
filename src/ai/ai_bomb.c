#include "ai_bomb.h"

// ajoute la bombe dans la liste des objects bombe et autres

void bomb_init(state_t *state, piece_t *player)
{
	piece_t *tmp;

	if (player->bomb > 0)
	{
		tmp = add_pieces(state, player->map_pos); // creer un object bombe
		tmp->proprio = player->id;
		tmp->is_activ = 1;
		tmp->degat = 5;
		tmp->request_state = 1;
		tmp->request_1 = 2;
		// ici la vie de la bomb IMPORTANT
		tmp->life = 10;
		player->bomb--;
	}
}
//la mets sur la carte

void bomb_state(state_t *state, piece_t *pieces)
{
	piece_t *tmp;
	int tempsBombe;

	tmp = pieces;
	if (tmp->life >= 10 && tmp->life < 80)
	{
		tmp->life++;
		if (tmp->life > 0 && 20 > tmp->life)
			tempsBombe = 0;
		else if (tmp->life > 20 && 40 > tmp->life)
			tempsBombe = 1;
		else if (tmp->life > 40 && 80 > tmp->life)
			tempsBombe = 2;
		else
			tempsBombe = 3;
		state->map_info->penalty_bonus_map[tmp->map_pos.x][tmp->map_pos.y] = tempsBombe;
	}
	else if (tmp->life >= 80)// devient explosion
	{
		pieces->request_1 = 0;
		pieces->request_2 = 0;
		pieces->request_state = 0;
		state->map_info->penalty_bonus_map[tmp->map_pos.x][tmp->map_pos.y] = 40; // numero faire exploser bomb
		// delete_list_chevron(pieces);  // detruit la bomb
	}
}
