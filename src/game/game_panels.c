#include "game_panels.h"
#include "kernel.h"

void create_panel_game(control_t *control)
{
	SDL_Rect SrcR;
	SrcR.w = WINDOW_WIDTH;
	SrcR.h = WINDOW_HEIGHT - 64;
	SrcR.x = 0;
	SrcR.y = 0;
	SDL_SetRenderDrawColor(control->main_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(control->main_renderer, &SrcR);
}

void create_area_map(control_t *control)
{
	SDL_Rect position;

	position.w = 15 * 40;
	position.h = 11 * 40;
	position.x = 10;
	position.y = (32 * 1.8) + 10;

	SDL_SetRenderDrawColor(control->main_renderer, 240, 128, 0, 255);
	SDL_RenderFillRect(control->main_renderer, &position);
}

void create_counter(control_t *control)
{
	SDL_Rect dest = {0, 0, WINDOW_WIDTH, (32 * 1.8)};
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->menu_surf);
	SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->menu_coord[2].img), &dest);
	SDL_DestroyTexture(pTexture);

	SDL_Rect dest1 = {(WINDOW_WIDTH / 5), 0, (256 * 1.8), (32 * 1.8)};
	SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->menu_surf);
	SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->menu_coord[1].img), &dest1);
	SDL_DestroyTexture(pTexture1);
}

void create_area_bonus(control_t *control)
{
	SDL_Rect dest = {(15 * 40) + 40, (32 * 1.8) + 10, 138, 339};
	SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->menu_surf);
	SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->menu_coord[17].img), &dest);
	SDL_DestroyTexture(pTexture1);
}

void display_map(control_t *control, server_t *requete)
{
	int row;
	int col;
	int tuile;
	int bm;
	int action;

	row = 0;

	if (requete->pos[0] == 0 && requete->pos[1] == 0)
		return;

	while (row < requete->pos[0])
	{
		col = 0;
		while (col < requete->pos[1])
		{
			tuile = requete->map_scenery[row][col];
			SDL_Rect dest = {(col * WIDTH_TILE) + 10, (row * HEIGHT_TILE) + (32 * 1.8) + 10, WIDTH_TILE, HEIGHT_TILE};
			SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->sprite_surf);
			if (tuile >= 0)
				SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->sprite_coord[tuile].img), &dest);
			bm = requete->map_bitmap[row][col];
			if (bm != -1 && bm >= 0)
				SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->sprite_coord[bm].img), &dest);
			action = requete->map_action[row][col];
			if (action != -1 && action >= 0)
				SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->sprite_coord[action].img), &dest);
			SDL_DestroyTexture(pTexture1);
			col++;
		}
		row++;
	}
}

void write_panel_score(control_t *control, server_t *requete)
{
	int number;
	char buf[255];

	number = requete->player_state.score;
	sprintf(buf, "%d", number);

	SDL_Rect renderQuad = {(15 * 40) + 100, (32 * 1.8) + 70, strlen(buf) * 18, 50};
	write_str(control, renderQuad, buf);

	number = requete->player_state.bomb;
	sprintf(buf, "%d", number);
	SDL_Rect renderQuad2 = {(15 * 40) + 100, (32 * 1.8) + 180, strlen(buf) * 18, 50};
	write_str(control, renderQuad2, buf);

	number = requete->player_state.speed;
	sprintf(buf, "%d", number);
	SDL_Rect renderQuad3 = {(15 * 40) + 100, (32 * 1.8) + 290, strlen(buf) * 18, 50};
	write_str(control, renderQuad3, buf);
	SDL_RenderPresent(control->main_renderer);
}

void create_panel_res(control_t *control, server_t *requete)
{
	SDL_Rect SrcR;
	SrcR.w = 320 * 1.2;
	SrcR.h = 162 * 1.2;
	SrcR.y = 100;
	SrcR.x = 220;

	if (requete->player_state.life > 0)
	{
		SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->res_surf);
		SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->res_coord[2].img), &SrcR);
		SDL_DestroyTexture(pTexture);
	}
	else if (requete->player_state.life <= 0)
	{
		SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->res_surf);
		SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->res_coord[1].img), &SrcR);
		SDL_DestroyTexture(pTexture);
	}
}
