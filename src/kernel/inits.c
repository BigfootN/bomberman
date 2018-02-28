#include "inits.h"

control_t *init_control_t()
{
	control_t *control;

	if ((control = (control_t*) malloc(sizeof (control_t))) == NULL)
		return NULL;

	/* parametres reseaux */
	if ((control->network = (network_t*) malloc(sizeof (network_t))) == NULL) {
		free(control);
		return NULL;
	}

	// contient les emplacements des images du jeux dans leur fichier
	if ((control->sprites = (surface_t*) malloc(sizeof (surface_t))) == NULL) {
		free(control->network);
		free(control);
		return NULL;
	}

	control->main_renderer = NULL;
	control->win = NULL;
	control->map = NULL;
	control->real_map = NULL;
	control->network->client_id = 0;
	control->network->server_addr = (char*) malloc(sizeof (char) * strlen("127.0.0.1"));
	control->network->server_addr = "127.0.0.1";
	control->network->net_clt_srv_state = 1; // serveur par default
	control->msg_enable = 0; // pour les receptions de paquet
	control->menu_select = 0; // pour le smenus
	control->msg = (client_t*) malloc(sizeof (client_t));

	return (control);
}

state_t *init_state(state_t *state)
{
	if ((state = (state_t*) malloc(sizeof (state_t))) == NULL)
		return NULL;

	state->last_piece = NULL;
	state->last_player = NULL;
	state->piece = NULL;
	state->players = NULL;
	state->ip_addr = strdup("");
	state->game_time = 0;
	state->sock_server = 0;
	state->nb_players = 0;
	state->partie = 0;
	state->msg = (server_t*) malloc(sizeof (server_t));

	return (state);
}
