#include "add_network_player.h"

void add_piece(state_t *state, int counter, int socket)
{
	piece_t *tmp;
	SDL_Rect map_pos;
	player_t *lplayer;

	state->flag_stop = 1;

	// on cree le joueur dans la liste des pieces
	lplayer = add_item_player(state);
	lplayer->is_activ = 0;
	lplayer->sockfd_player = socket;
	/* done un id unique */
	lplayer->conn_id = counter;
	/* on incremente le nbre de players*/
	state->nb_players++;
	/* ici on l'ajoute au dernier */
	map_pos.x = 0;
	map_pos.y = 0;
	tmp = add_pieces(state, map_pos);
	/*init value player */
	tmp->bomb = 5;
	tmp->life = 20;
	tmp->speed = 1;
	tmp->score = 0;
	tmp->is_activ = 1;
	/* pour ne pas le cherche inutilement */
	lplayer->player = tmp;
	lplayer->player->id = lplayer->conn_id;
	lplayer->player->type = 1;
	lplayer->player->life = 20;
	/* prend le numero du joueur courant*/
	init_gamers(state, lplayer->player);
	lplayer->player->is_activ = 1;
	/* is_activ le player */
	lplayer->is_activ = 1;

	state->flag_stop = 0;
	/* ici on envoi un mail de confirmation avec son id */
	send_request_for_unique_player(state, lplayer->sockfd_player, 1, lplayer->conn_id);
}

int check_first_record(state_t *state, int socket)
{
	player_t *player;
	// si debut car aucun joueur donc liste vide
	player = state->players;
	if (player == NULL)
	{
		add_piece(state, 1, socket);
		return (1);
	}
	return (0);
}

int reconnect_player(state_t *state, client_t *requete, int socket)
{
	player_t *player;
	// on verifie qu'il ne s'agit pas d'une déconnexion
	player = state->players;
	while (player != NULL)
	{
		if (player->conn_id == requete->client_id && requete->client_id != 0)
		{
			player->sockfd_player = socket;
			return (1);
		}
		player = player->next;
	}
	return (0);
}

// ajout du client lorsqu'il arrive

int *init_array_check_player()
{
	int *tab;
	int index;

	index = 0;
	if ((tab = (int*) malloc(sizeof (int) * 5)) == NULL)
		return NULL;
	while (index < 5)
	{
		tab[index] = 0;
		index++;
	}

	return (tab);
}

int add_client(state_t *state, client_t *requete, int socket)
{
	if (state->nb_players < 4)
	{
		player_t *player;
		int *tabl;
		int index;

		tabl = init_array_check_player();
		if (check_first_record(state, socket))
			return (0);
		/* ici rupture le serveur n'as pas compris que le client est parti */
		if (reconnect_player(state, requete, socket))
			return (0);

		// on selectionne les emplacements libre
		player = state->players;
		while (player != NULL)
		{
			if (player->conn_id <= 4 && player->conn_id >= 1)
				tabl[player->conn_id] = 1;
			player = player->next;
		}
		// on ajoute le player au premier  chiffre manquant
		player = state->players;
		while (player != NULL)
		{
			index = 1;
			while (index < 5)
			{
				if (tabl[index] == 0)
				{
					add_piece(state, index, socket);
					return (0);
				}
				index++;
			}
			player = player->next;
		}
		free(tabl);
	}
	return (0);
}
