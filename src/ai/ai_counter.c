#include "ai_counter.h"
#include "ai_msg.h"

int check_counter(state_t* state) {
	check_player_active(state);
	time_diff(state);
	return (1);
}

void counter_player_init(state_t* state, player_t* player) {
	if (player->player != NULL && state->msg != NULL) {
		state->msg->player_state.score = player->player->score;
		state->msg->player_state.bomb = player->player->bomb;
		state->msg->player_state.speed = player->player->speed;
		state->msg->player_state.life = player->player->life;
	}
}
