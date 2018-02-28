#include "inits.h"
#include "sprites.h"
#include "score_views.h"
#include "game_views.h"
#include "intro_views.h"
#include "choice_ip_views.h"

static const window_t l_bib[] = {
	{1, &intro_central},
	{2, &ip_choice_central},
	{3, &central_game},
	{4, &scores_central},
	{0, NULL}
};

int main()
{
	int choixpage;
	int index;
	control_t *control;

	control = init_control_t();
	if (central_init_sprites(control))
	{
		index = 0;
		choixpage = 1;
		control->network->net_clt_srv_state = 1;
		while (l_bib[index].number != 0)
		{
			if (l_bib[index].number == choixpage)
			{
				choixpage = l_bib[index].pfunc(control);
				index = -1;
			}
			index++;
		}
	}
	return 0;
}
