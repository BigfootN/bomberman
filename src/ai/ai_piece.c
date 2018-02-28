#include "ai_piece.h"
#include "tcp_server.h"

int check_all_pieces(state_t *state)
{
	piece_t *tmp;

	tmp = state->piece;
	while (tmp != NULL)
	{
		if (tmp->is_activ == 1 && state->partie == 1)
		{
			if (tmp->request_state == 1)
			{
				if (tmp->request_1 == 2)
					bomb_state(state, tmp);
				else if (tmp->request_1 == 3)
				{
					if (tmp->type >= 27 && tmp->type <= 30)
						ai_monster(state, tmp);
				}
			}

		}
		tmp = tmp->next;
	}
	return (1);
}

void deactivate_players(state_t *state, int numberPlayer)
{
	piece_t *tmp;

	tmp = state->piece;

	while (tmp != NULL)
	{
		if (tmp->id == numberPlayer || tmp->type == numberPlayer)
		{
			if (tmp->is_activ == 1)
			{
				tmp->is_activ = 0;
				if (tmp->type != 1)
					kill_piece(state, tmp);
				return;
			}
		}
	}
}

piece_t *search_player(state_t *state, int numberPlayer)
{
	piece_t *piece;

	piece = state->piece;
	while (piece != NULL)
	{
		if (piece->id == numberPlayer)
			return (piece);
		else if (piece->type == numberPlayer)
			return (piece);

		piece = piece->next;
	}
	return (NULL);
}

void kill_piece(state_t *state, piece_t *tmp)
{
	tmp->is_activ = 0;
	state->map_info->penalty_bonus_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
	state->map_info->action_map[tmp->map_pos.x][tmp->map_pos.y] = -1;
	delete_list_chevron(tmp);
}

int check_requesplayer_t(state_t *state)
{
	player_t *player;
	piece_t *tmp;

	player = state->players;

	while (player != NULL)
	{
		if (player->player->is_activ == 1)
		{
			tmp = player->player;
			tmp->request_1 = player->request_1;
			tmp->request_2 = player->request_2;
			if (player->request_state == 1)
			{
				if (player->request_1 == 2 && state->partie == 1)
					move_piece(state, tmp, 0, tmp->request_2);
				else if (player->request_1 == 3 && state->partie == 1)
					move_piece(state, tmp, 1, tmp->request_2);
				else if (player->request_1 == 4 && state->partie == 1)
					bomb_init(state, tmp);
				else if (player->request_1 == 6 && state->partie == 1)
				{

				}
				else if (player->request_1 == 10)
					init_gamers(state, tmp);
				else if (player->request_1 == 11)
				{
					if (state->partie == 0)
						time_start(state);
					state->partie = 1;
				}
				else if (player->request_1 == 12)
					state->partie = 2;
			}
			player->request_state = 0;
			player->request_1 = 0;
			player->request_2 = 0;
		}
		player = player->next;
	}
	return (1);
}
// init gamer

void init_gamers(state_t *state, piece_t *player)
{
	if (player->id == 1)
	{
		player->map_pos.x = 1;
		player->map_pos.y = 1;
		player->type = 23;
		state->map_info->action_map[1][1] = 23;
	}
	else if (player->id == 2)
	{
		player->map_pos.x = 1;
		player->map_pos.y = 13;
		player->type = 24;
		state->map_info->action_map[1][13] = 24;
	}
	else if (player->id == 3)
	{
		player->map_pos.x = 9;
		player->map_pos.y = 13;
		player->type = 25;
		state->map_info->action_map[9][13] = 25;
	}
	else if (player->id == 4)
	{
		player->map_pos.x = 9;
		player->map_pos.y = 1;
		player->type = 26;
		state->map_info->action_map[9][1] = 26;
	}
}

int collision_details(state_t* state, int dx, int dy)
{
	int stateX = (0 <= dx && (state->map_info->pos.x) >= dx);
	int stateY = (0 <= dy && (state->map_info->pos.y) >= dy);

	if (stateX && stateY)
	{
		int tuile = state->map_info->real_map[dx][dy];
		//printf("%d\n", tuile);
		if (state->map_info->wall[tuile] == 1)
			return 0;
		else
			return 1;
	}
	return 0;
}

int collision_bitmap(state_t* state, piece_t *player, int dx, int dy)
{
	piece_t *piece;

	int stateX = (0 <= dx && (state->map_info->pos.x) >= dx);
	int stateY = (0 <= dy && (state->map_info->pos.y) >= dy);

	if (stateX && stateY)
	{
		int bm = state->map_info->penalty_bonus_map[dx][dy];

		if (bm == 4)
			player->bomb += 1;
		else if (bm == 5)
		{
			if (player->bomb > 0)
				player->bomb -= 1;
		}
		else if (bm == 6)
			player->bomb += 3;
		else if (bm == 7)
			player->speed = 2;
		else if (bm == 8)
		{
			player->is_activ = 0;
			player->life = 0;
			state->map_info->action_map[dx][dy] = -1;
		}
		// retire le BM
		if (bm != -1)
			state->map_info->penalty_bonus_map[dx][dy] = -1;

		int monster = state->map_info->action_map[dx][dy];
		if (monster >= 27 && monster <= 30)
		{
			SDL_Rect empl;
			empl.x = dx;
			empl.y = dy;
			piece_t *tmp = search_monster(state, monster, empl);
			if (player->life > tmp->life)
			{
				del_monster(state, tmp->type, empl);
				player->score += 1;
				state->map_info->action_map[dx][dy] = player->id;
			}
			else
			{
				player->is_activ = 0;
				player->life = 0;
			}
		}

		// rencontre entre players le plus fort l'emporte
		int otherPlayer = state->map_info->action_map[dx][dy];
		if (otherPlayer >= 23 && otherPlayer <= 26)
		{
			piece = search_player(state, otherPlayer);
			if (piece->life > player->life)
			{
				piece->life -= player->life;
				player->life = 0;
				player->is_activ = 0;
			}
			else if (piece->life < player->life)
			{
				player->life -= piece->life;
				piece->life = 0;
				piece->is_activ = 0;
				state->map_info->action_map[dx][dy] = player->id;
				player->score += 1;
			}
		}

		return (1);
	}
	return 0;
}

void move_piece(state_t* state, piece_t *player, int type, int value)
{
	int col;
	int row;
	int dy;
	int dx;
	int index;

	index = 0;
	while (index < 1)
	{
		dx = player->map_pos.x;
		dy = player->map_pos.y;
		col = dy;
		row = dx;

		if (value == 0)
			value = -1;
		// prend en compte de maniere provisoire
		// pour le test collision
		if (type == 1 && value < 0)// left
			dx = player->map_pos.x + value;
		else if (type == 1 && value > 0) // right
			dx = player->map_pos.x + value;
		else if (type == 0 && value < 0) // up
			dy = player->map_pos.y + value;
		else if (type == 0 && value > 0) /// bottom
			dy = player->map_pos.y + value;

		if (collision_details(state, dx, dy))
		{
			int type;
			// mets a jour le joueur
			type = state->map_info->action_map[row][col];
			state->map_info->action_map[row][col] = -1;
			player->map_pos.x = dx;
			player->map_pos.y = dy;
			if (collision_bitmap(state, player, dx, dy))/* verifie que l'emplacement est libre ou sinon fait le combat */
				state->map_info->action_map[dx][dy] = type;
		}
		else
			return;
		index++;
	}
}
// envoi du message de fin de rencontre et destruction des players
//int sendRequeteForUniqPlayer(state_t *state, int socket, int action, int message)

void deletePlayers(state_t* state)
{
	player_t *player;

	player = state->players; // utilisateur
	while (player != NULL)
	{
		send_request_for_unique_player(state, player->sockfd_player, 3, 5);
		SDL_Delay(100);
		player = delete_list_player(player);
	}
	//free(player);
}

void deletePions(state_t* state)
{
	piece_t *pieces;

	pieces = state->piece; // utilisateur
	while (pieces != NULL)
	{
		pieces = delete_list_chevron(pieces);
	}
	//free(pieces);
}

void send_end_game(state_t* state)
{
	deletePions(state);
	deletePions(state);
}
