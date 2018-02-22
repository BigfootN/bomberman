#include "headers.h"

int choiceMenuChoiceIp(t_control* control, SDL_Event event) {
	if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) &&
		event.button.button == SDL_BUTTON_LEFT) {
		if (event.motion.x >= 150 && event.motion.x <= 300)
			return 1;
		else if (event.motion.x >= 350 && event.motion.x <= 500) {
			control->network->srvorclt = 0;
			return 3;
		} else if (event.motion.x >= 550 && event.motion.x <= 700)
			return 0;
	}

	/* ici les encart du nom et de l'adresse server IP 200, 298 */
	if (event.motion.x >= 200 && event.motion.x <= 600) {
		if (event.motion.y >= 300 && event.motion.y <= 350) {
			if (control->writeLoop == 0)
				control->writeLoop = 1;
			else
				control->writeLoop = 0;

			if (control->writeLoop == 1)
				encartClair(control);
		}
	}
	return -1;
}

void selectData(t_control* control) {
	char* tmp;
	tmp = (char*) malloc(sizeof (char*) * 16);
	bzero(tmp, 16);

	tmp = control->network->ipserveur;
	//control->network->ipserveur = writeData(event, tmp);
	encartClair(control);
}

void eventsLoopipchoice(t_control* control, int* menuSelect) {
	Input in;
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
				in.mousex = event.motion.x;
				in.mousey = event.motion.y;
				in.mousexrel = event.motion.xrel;
				in.mouseyrel = event.motion.yrel;
				break;
			case SDL_TEXTINPUT:
				if (control->writeLoop == 1)
					//strcat(text, event.text.text);
					selectData(control);
				break;
			case SDL_KEYDOWN:
				if (control->writeLoop == 1)
					deleteData(control, event);
				//    selectData(control, event);
				break;
			case SDL_MOUSEBUTTONDOWN:
				LastClickTicks = dblClick(CurrentClickTicks, LastClickTicks);
				if (LastClickTicks == 1) {
					//printf(" le nom empl souris x %d\n", event.motion.x);
					//printf(" le nom empl souris y %d\n", event.motion.y);
					if (event.button.button == SDL_BUTTON_LEFT)
						if ((*menuSelect = choiceMenuChoiceIp(control, event)) != -1)
							return;
				}

		}
	}
	SDL_StopTextInput();
}
