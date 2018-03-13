//
// Created by marc on 01/03/18.
//
#include "bomberman.h"

int choice_menu(t_control *control, SDL_Event event)
{
    if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) && event.button.button == SDL_BUTTON_LEFT)
    {
        if (event.motion.x >= 150 && event.motion.x <= 300)
        {
            control->network->srv_or_clt = 1;
            return 3;
        }
        else if (event.motion.x >= 350 && event.motion.x <= 500)
            return 2;
        else if (event.motion.x >= 550 && event.motion.x <= 700)
            return 0;
    }
    return 1;
}

int events_loop_introduction(t_control *control, int *menu_select)
{
    Input in;
    SDL_Event event;
    int CurrentClickTicks = 0, LastClickTicks = 0;

    memset(&in, 0, sizeof (in)); // Instanciation d'une structure Input, et initialisation : tous les champs à 0.
    while (!in.key[SDLK_ESCAPE] && !in.quit)
    {
        SDL_WaitEvent(&event);
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
            case SDL_MOUSEBUTTONDOWN:
                LastClickTicks = dbl_click(CurrentClickTicks, LastClickTicks);
                if (LastClickTicks == 1)
                    if ((*menu_select = choice_menu(control, event)) != 1)
                        return (*menu_select);
        }
    }
    return (*menu_select);
}

