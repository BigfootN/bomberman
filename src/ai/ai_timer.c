#include "ai_timer.h"

void time_start(t_state* state) {
	time(&state->tdepart);
}

void time_diff(state_t* state) {
	if (state->tdepart > 0) {
		if (difftime(state->tcourant, state->tdepart) > 120)
			state->partie = 2;
		else
			time(&state->tcourant);
	}
}
