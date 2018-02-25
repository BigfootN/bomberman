#include "headers.h"

int serializeMap(state_t *state)
{
    int row;
    int col;
    int decor;
    int bm;
    int action;

    // if ((state->msg = (server_t*) malloc(sizeof (server_t))) != NULL)
    // {
    state->msg->pos[0] = state->map_info->pos.x;
    state->msg->pos[1] = state->map_info->pos.y;
    row = 0;
    while (row < state->map_info->pos.x)
    {
        col = 0;
        while (col < state->map_info->pos.y)
        {
            decor = state->map_info->real_map[row][col]; // code des murs et autres
            action = state->map_info->action_map[row][col];
            bm = state->map_info->penalty_bonus_map[row][col];

            if (state->map_info->wall[decor] != 1)
            {
                state->msg->action_map[row][col] = action;
                state->msg->map_bitmap[row][col] = bm;
            }
            else
            {
                state->msg->action_map[row][col] = -1;
                state->msg->map_bitmap[row][col] = -1;
            }
            state->msg->map_scenery[row][col] = decor;
            col++;
        }
        row++;
    }
    return (1);
    //}
    return (0);
}