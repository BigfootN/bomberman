#include "headers.h"

int choiceMenu(t_control *control, SDL_Event event)
{
    if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) && event.button.button == SDL_BUTTON_LEFT)
    {
        if (event.motion.x >= 150 && event.motion.x <= 300)
        {
            control->network->srvorclt = 1;
            return 3;
        }
        else if (event.motion.x >= 350 && event.motion.x <= 500)
            return 2;
        else if (event.motion.x >= 550 && event.motion.x <= 700)
            return 0;
    }
    return 1;
}

int eventsLoopIntroduction(t_control *control, int *menuSelect)
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
            LastClickTicks = dblClick(CurrentClickTicks, LastClickTicks);
            if (LastClickTicks == 1)
                if ((*menuSelect = choiceMenu(control, event)) != 1)
                    return (*menuSelect);
        }
    }
    return (*menuSelect);
}
