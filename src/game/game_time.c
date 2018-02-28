#include "game_time.h"

int convert(int time, int number, int flag)
{
	int data;

	if (time >= number)
		data = time / number;
	else
	{
		if (flag == 2)
			data = time;
		if (flag == 1)
			data = 0;
	}

	return (data);
}

void display_time(control_t *control)
{
	time_t arrivee;
	if (control->map_recv->start_time > 0)
	{
		time(&arrivee);
		if (difftime(arrivee, control->map_recv->start_time) > 240)
		{

		}
		else
		{
			int change;
			int pminute;
			int pseconde;
			int minute1;
			int minute2;
			int seconde1;
			int seconde2;

			change = arrivee - control->map_recv->start_time;
			if (change > 0)
			{
				pminute = convert(change, 60, 1); // 3 minutes si inferieur 0 minutes
				pseconde = convert(change % 60, 60, 2);

				minute1 = convert(pminute, 10, 1);
				minute2 = convert(pminute  % 10, 10, 2);

				seconde1 = convert(pseconde, 10, 1);
				seconde2 = convert(pseconde % 10, 10, 2);

				display_counter(control, minute1, minute2, seconde1, seconde2);
			}

		}
	}
}

void display_counter(control_t *control, int minute1, int minute2, int seconde1, int seconde2)
{
	SDL_Rect dest1 = {(WINDOW_WIDTH / 5) + 195, 15, (8 * 1.8), (14 * 1.8)};

	SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->menu_surf);
	SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->menu_coord[minute1 + 6].img), &dest1);

	dest1.x = (WINDOW_WIDTH / 5) + 209;
	SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->menu_coord[minute2 + 6].img), &dest1);

	dest1.x = (WINDOW_WIDTH / 5) + 230;
	SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->menu_coord[seconde1 + 6].img), &dest1);

	dest1.x = (WINDOW_WIDTH / 5) + 243;
	SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->menu_coord[seconde2 + 6].img), &dest1);
	SDL_DestroyTexture(pTexture1);
}
