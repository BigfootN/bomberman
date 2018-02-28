#include "choice_ip_views.h"

int ip_choice_central(control_t* control)
{
	control->write_loop = 0;
	int menuSelect = 1;
	window_init(control);
	create_panel(control);
	create_panel_white(control);
	create_banner(control);
	// creation etiquette
	create_tag(control);
	encart_clair(control);
	button_action_choice_game(control);
	SDL_RenderPresent(control->main_renderer);

	events_loop_ip_choice(control, &menuSelect);
	SDL_DestroyRenderer(control->main_renderer);

	return (menuSelect);
}

void button_action_choice_game(control_t* control)
{
	SDL_Rect dest = {150,
		(WINDOW_HEIGHT - 62),
		control->sprites->menu_coord[4].img.w,
		control->sprites->menu_coord[4].img.h};
	display_button(control, dest);
	dest.x = 350;
	display_button(control, dest);
	dest.x = 550;
	display_button(control, dest);

	SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, strlen("Return") * 18, 50};
	write_str(control, renderQuad, "Return");
	renderQuad.x = 360;
	renderQuad.w = strlen("Select") * 18;
	write_str(control, renderQuad, "Select");
	renderQuad.x = 570;
	renderQuad.w = strlen("Close") * 18;
	write_str(control, renderQuad, "Close");
}
