#include "score_views.h"

int scores_central(control_t* control)
{
	int menuSelect = -1;
	window_init(control);
	create_panel(control);
	create_banner(control);
	button_menu_scores(control);
	SDL_RenderPresent(control->main_renderer);
	//eventsLoopScores(control, &menuSelect);
	SDL_DestroyRenderer(control->main_renderer);
	return (menuSelect);
}

void button_menu_scores(control_t* control)
{
	SDL_Surface *lbutton = NULL;
	SDL_Texture* button;

	lbutton = IMG_Load("button/boutonReturn.png");
	SDL_Rect dest = {250, WINDOW_HEIGHT - 62, 1, 10};
	dest.w = 150;
	dest.h = 60;
	button = SDL_CreateTextureFromSurface(control->main_renderer, lbutton);
	SDL_FreeSurface(lbutton);
	SDL_RenderCopy(control->main_renderer, button, NULL, &dest);

	lbutton = IMG_Load("button/boutonClose.png");
	dest.x = 500;
	button = SDL_CreateTextureFromSurface(control->main_renderer, lbutton);
	SDL_FreeSurface(lbutton);
	SDL_RenderCopy(control->main_renderer, button, NULL, &dest);
}
