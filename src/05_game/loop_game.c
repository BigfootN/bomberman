//
// Created by marc on 01/03/18.
//
#include "bomberman.h"

int area_button(t_control *control, SDL_Event event)
{
    if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) && event.button.button == SDL_BUTTON_LEFT)
    {
        if (event.motion.x >= 150 && event.motion.x <= 300)
        {
            if (control->etat_send == 1)
                prepare_requet_client(control, control->network->id_client, 12, 12, 0);
            if (control->network->srv_or_clt == 1)
            {
                prepare_requet_client(control, control->network->id_client, 50, 0, 0);
                control->etat_send = 0;
                return (1);
            }
            control->etat_send = 0;
            return (2);
        }
        else if (event.motion.x >= 350 && event.motion.x <= 500 && control->network->srv_or_clt == 1)
        {
            if (control->etat_send == 1)
                start_game(control);
        }
        else if (event.motion.x >= 550 && event.motion.x <= 700)
        {
            if (control->etat_send == 1)
            {
                prepare_requet_client(control, control->network->id_client, 12, 12, 0);
                control->etat_send = 0;
            }
            return 0;
        }
    }
    return -1;
}

void game_loop(t_control *control, int *menu_select)
{
    int current_click_ticks = 0;
    int last_click_ticks = 0;
    SDL_Event event;
    Input in;

    memset(&in, 0, sizeof (in));

    while (!in.key[SDLK_ESCAPE] && !in.quit)
    {
        ckeck_answer_srv(control);
        if(control->receive_map->etat_party_chrono == 1)
            chrono_session(control);
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    in.quit = 1;
                    break;
                case SDL_MOUSEMOTION:
                    in.mousex = event.motion.x;
                    in.mousey = event.motion.y;
                    in.mousexrel = event.motion.xrel;
                    in.mouseyrel = event.motion.yrel;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            prepare_requet_client(control, control->network->id_client, 2, 2, 0);
                            break;
                        case SDLK_RIGHT:
                            prepare_requet_client(control, control->network->id_client, 2, 2, 1);
                            break;
                        case SDLK_UP:
                            prepare_requet_client(control, control->network->id_client, 2, 3, 0);
                            break;
                        case SDLK_DOWN:
                            prepare_requet_client(control, control->network->id_client, 2, 3, 1);
                            break;
                        case SDLK_b:
                            prepare_requet_client(control, control->network->id_client, 2, 4, -1);
                            break;
                        case SDLK_s:
                            prepare_requet_client(control, control->network->id_client, 2, 5, -1);
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    last_click_ticks = dbl_click(current_click_ticks, last_click_ticks);
                    if (last_click_ticks == 1)
                        if ((*menu_select = area_button(control, event)) != -1)
                            return;
            }
        }
    }
}


