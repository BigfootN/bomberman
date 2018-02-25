#include "headers.h"
#include "ai_map.h"
#include "ai_msg.h"
#include "ai_counter.h"

//??
void central_send(state_t *state)
{
    send_email(state);
}

//changer nom ?
void send_email(state_t *state)
{
    player_t *player;
    pthread_t p_thread;

    player = state->players;
    state->msg->cmd_service = 5;
    state->msg->response = 0;
    if (state->partie == 2)
        state->msg->pos[2] = 1;

    while (player != NULL)
    {
        if (player->socked_player >= 0)
        {
            state->socket_send = player->socked_player;
            state->msg->client_id = player->conn_id;
            state->msg->start_time = state->start_time;
            counter_player_init(state, player);
            state->msg->pos[3] = 0;
            if (player->is_activ == 0 || player->player->is_activ == 0)
                state->msg->pos[3] = 1;
            if (pthread_create(&p_thread, NULL, server_to_client, (void*) state) < 0)
            {
                perror("could not create thread");
                return;
            }
        }
        SDL_Delay(5);
        player = player->next;
    }
}

/*
 *  prend en compte les joueurs encore present
 */

void check_player_active(state_t* state)
{
    player_t *player;

    player = state->players;
    while (player != NULL)
    {
        if (player->is_activ)
            state->is_activ_players[player->conn_id] = 1;
        player = player->next;
    }
}