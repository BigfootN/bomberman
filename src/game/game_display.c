#include "game_display.h"

int recv_signal(const int signal, void *ptr)
{
	static control_t *control = NULL;

	printf("%s\n", "client transmets");
	if (control == NULL)
		control = ptr;
	printf("%s\n", "init control");
	printf("signal %d \n", signal);
	if (signal == SIGNALWHATEVER)
		check_answer_serv(control);

	return (0);
}

void ckeck_answer_serv(control_t* control)
{
	server_t *requete;

	if (control->msg_enable == 1)
	{
		requete = control->map_recv;
		if (requete->cmd_service == 1)
		{
			display_screen_game(control);
			control->network->client_id = requete->client_id;
		}
		if (requete->cmd_service == 3)
			control->send_state = 0;
		else if (requete->cmd_service == 5)
		{
			control->network->client_id = requete->client_id;
			display_screen_game(control);
			display_map(control, requete);
			display_time(control);
			if (requete->pos[2] != 0 || requete->pos[3] != 0)
				create_panel_res(control, requete);
			write_panel_score(control, requete);
		}
		control->msg_enable = 0;
	}
	SDL_Delay(5);
}

void start_game(control_t *control)
{
	SDL_Rect dest = {350,
		(WINDOW_HEIGHT - 62),
		control->sprites->menu_coord[4].img.w,
		control->sprites->menu_coord[4].img.h};

	display_background_button(control, dest);
	SDL_RenderPresent(control->main_renderer);
	prepare_client_request(control, control->network->client_id, 11, 11, 0);
}
