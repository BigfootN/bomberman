#include "choice_ip_loop.h"

int choice_menu_choice_ip(control_t* control, SDL_Event event) {
	if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) &&
			event.button.button == SDL_BUTTON_LEFT) {
		if (event.motion.x >= 150 && event.motion.x <= 300)
			return 1;
		else if (event.motion.x >= 350 && event.motion.x <= 500) {
			control->network->net_clt_srv_state = 0;
			return 3;
		} else if (event.motion.x >= 550 && event.motion.x <= 700)
			return 0;
	}

	/* ici les encart du nom et de l'adresse server IP 200, 298 */
	if (event.motion.x >= 200 && event.motion.x <= 600) {
		if (event.motion.y >= 300 && event.motion.y <= 350) {
			if (control->write_loop == 0)
				control->write_loop = 1;
			else
				control->write_loop = 0;

			if (control->write_loop == 1)
				encart_clair(control);
		}
	}
	return -1;
}

void select_data(control_t* control) {
	/*char* tmp;

	  tmp = (char*) malloc(sizeof(char) * 16);
	  bzero(tmp, 16);

	  tmp = control->network->server_addr;
	  control->network->server_addr = write_data(event, tmp);*/
	encart_clair(control);
}

void events_loop_ip_choice(control_t* control, int* menuSelect) {
	input_t in;
	SDL_Event event;
	SDL_StartTextInput();
	int CurrentClickTicks = 0, LastClickTicks = 0;
	//SDL_EnableUNICODE(1);
	memset(&in, 0, sizeof (in));// Instanciation d'une structure Input, et initialisation : tous les champs à 0.
	SDL_StartTextInput();

	while (!in.key[SDLK_ESCAPE] && !in.quit) {
		SDL_WaitEvent(&event);

		switch (event.type)
		{
			case SDL_QUIT:
				in.quit = 1;
				break;
			case SDL_MOUSEMOTION:
				in.mouse_x = event.motion.x;
				in.mouse_y = event.motion.y;
				in.mouse_xrel = event.motion.xrel;
				in.mouse_yrel = event.motion.yrel;
				break;
			case SDL_TEXTINPUT:
				if (control->write_loop == 1)
					//strcat(text, event.text.text);
					select_data(control);
				break;
			case SDL_KEYDOWN:
				if (control->write_loop == 1)
					delete_data(control, event);
				//    selectData(control, event);
				break;
			case SDL_MOUSEBUTTONDOWN:
				LastClickTicks = dbl_click(CurrentClickTicks, LastClickTicks);
				if (LastClickTicks == 1) {
					//printf(" le nom empl souris x %d\n", event.motion.x);
					//printf(" le nom empl souris y %d\n", event.motion.y);
					if (event.button.button == SDL_BUTTON_LEFT)
						if ((*menuSelect = choice_menu_choice_ip(control, event)) != -1)
							return;
				}

		}
	}
	SDL_StopTextInput();
}
