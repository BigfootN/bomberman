#ifndef AI_MSG_H
#define AI_MSG_H

#include "types.h"
#include "ai_map.h"
#include "ai_msg.h"
#include "ai_counter.h"
#include "tcp_server.h"

#include "types.h"

void central_send(state_t *state);
void send_email(state_t *state);
void check_player_active(state_t* state);

#endif

