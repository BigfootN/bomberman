#include "memory.h"

enum list_direction_free {
	NEXT,
	PREV
};

static void player_list_free(player_t* player, const enum list_direction_free direction) {
	player_t* next_player;

	if (player == NULL)
		return;

	if (direction == NEXT)
		next_player = player->next;
	else
		next_player = player->prev;

	free(player);
	player_list_free(next_player, direction);
}

static void piece_list_free(piece_t* piece, const enum list_direction_free direction) {
	piece_t* next_piece;

	if (piece == NULL)
		return;

	if (direction == NEXT)
		next_piece = piece->next;
	else
		next_piece = piece->prev;

	piece_list_free(next_piece, direction);
	free(piece);
}

void player_free(player_t* player) {
	player_list_free(player->next, NEXT);
	player_list_free(player->prev, PREV);
	free(player);
}

void piece_free(piece_t* piece) {
	free(piece->clock_direction);
	piece_list_free(piece->next, NEXT);
	piece_list_free(piece->prev, PREV);
	free(piece);
}

void clmap_free(clmap_t* map) {
	free(map->file_name);
	free(map->sprite_name);
	free(map->wall);
	free(map->real_map);
	free(map->penalty_bonus_map);
	free(map->action_map);
	free(map);
}

void state_free(state_t* state) {
	free(state->ip_addr);
	player_free(state->last_player);
	piece_free(state->last_piece);
	free(state->msg);
	clmap_free(state->map_info);
	free(state);
}

void free_coord(coord_t* coord) {
	free(coord);
}

void control_free(control_t* control) {
	SDL_DestroyRenderer(control->main_renderer);
	SDL_DestroyWindow(control->win);
	free(control->map);
	free(control);
}

void network_free(network_t* network) {
	free(network->server_addr);
	free(network);
}

void free_surface(surface_t* surface) {
	free_coord(surface->banner_coord);
	free_coord(surface->logo_coord);
	free_coord(surface->menu_coord);
	free_coord(surface->res_coord);

	SDL_UnlockSurface(surface->banner_surf);
	SDL_UnlockSurface(surface->logo_surf);
	SDL_UnlockSurface(surface->menu_surf);
	SDL_UnlockSurface(surface->res_surf);
}

void free_point(point_t* point) {
	free(point);
}

void free_client_state(client_state_t* client_state) {
	free(client_state->realmap);
	free(client_state->nitMap);
}
