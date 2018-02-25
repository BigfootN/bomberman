#include "types.h"
#include "ai_timer.h"

void time_start(state_t* state) {
	time(&state->start_time);
}

void time_diff(state_t* state) {
	if (state->start_time > 0) {
		if (difftime(state->cur_time, state->start_time) > 120)
			state->partie = 2;
		else
			time(&state->cur_time);
	}
}
