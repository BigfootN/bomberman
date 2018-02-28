#include "ai.h"
#include "file.h"


/*
 * initilaise la partie
 */

void *central_ai(void *tmp)
{
	state_t *state;
	pthread_detach(pthread_self());

	if ((state = (state_t*) malloc(sizeof (state_t))) == NULL)
		return NULL;
	state = init_state(state);
	manage_data(state, "/home/bigfoot/bomberman/res/map/carte1.lvl");
	tcp_thread_server(state);
	ai_loop(state);
	send_end_game(state);
	pthread_exit((void*) tmp);
}

/*
 * boucle de la IA
 */
int ai_loop(state_t *state)
{
	int pause;

	pause = 1;
	while (pause)
	{
		SDL_Delay(100);
		check_requesplayer_t(state);
		check_all_pieces(state);
		init_bomb_map(state);
		check_counter(state);
		if (serialize_map(state))
			central_send(state);

		if (state->partie == 2)
			pause = 0;
		SDL_Delay(100);
	}
	return (1);
}
