#include "ai_counter.h"

int check_counter(state_t* state) {
	checkPlayerActif(state);
	time_diff(state);
	return (1);
}

void counter_player_init(state_t* state, player_t* player) {
	if (player->player != NULL && state->msg != NULL) {
		state->msg->statePlayer.score = player->player->score;
		state->msg->statePlayer.bomb = player->player->bomb;
		state->msg->statePlayer.speed = player->player->speed;
		state->msg->statePlayer.life = player->player->life;
	}
}
