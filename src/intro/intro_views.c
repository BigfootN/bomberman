#include "intro_views.h"

int intro_central(control_t *control)
{
	int menuSelect = 0;

	window_init(control);
	create_panel(control);
	sprite_panel_intro(control);
	SDL_RenderPresent(control->main_renderer);

	events_loop_intro(control, &menuSelect);
	SDL_DestroyRenderer(control->main_renderer);

	return (menuSelect);
}

void sprite_panel_intro(control_t* control)
{
	SDL_Rect SrcR;
	SrcR.w = WINDOW_WIDTH;
	SrcR.h = WINDOW_HEIGHT - 64;

	SDL_Texture* logo = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->logo_surf);
	SDL_RenderCopy(control->main_renderer, logo, &(control->sprites->logo_coord->img), &SrcR);
	SDL_DestroyTexture(logo);

	SDL_Rect dest = {150,
		(WINDOW_HEIGHT - 62),
		control->sprites->menu_coord[4].img.w,
		control->sprites->menu_coord[4].img.h};

	display_button(control, dest);
	dest.x = 350;
	display_button(control, dest);
	dest.x = 550;
	display_button(control, dest);
	/*  dest.x = 590;
		display_button(control, dest);*/

	SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, strlen("Serveur") * 18, 50};
	write_str(control, renderQuad, "Serveur");
	renderQuad.x = 370;
	renderQuad.w = strlen("Client") * 18;
	write_str(control, renderQuad, "Client");
	/* renderQuad.x = 430;
	   renderQuad.w = strlen("Credits") * 18;
	   writeText_51(control, renderQuad, "Credits");*/
	renderQuad.x = 570;
	renderQuad.w = strlen("Close") * 18;
	write_str(control, renderQuad, "Close");

}
