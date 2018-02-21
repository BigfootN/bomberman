#include "headers.h"

int area_button(t_control *control, SDL_Event event)
{
    if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) && event.button.button == SDL_BUTTON_LEFT)
    {
        if (event.motion.x >= 150 && event.motion.x <= 300)
        {
            if (control->etatsend == 1)
                prepare_requetClient(control, control->network->idClient, 12, 12, 0);
            if (control->network->srvorclt == 1)
            {
                prepare_requetClient(control, control->network->idClient, 50, 0, 0);
                control->etatsend = 0;
                return (1);
            }
            control->etatsend = 0;
            return (2);
        }
        else if (event.motion.x >= 350 && event.motion.x <= 500 && control->network->srvorclt == 1)
        {
            if (control->etatsend == 1)
                startGame(control);
        }
        else if (event.motion.x >= 550 && event.motion.x <= 700)
        {
            if (control->etatsend == 1)
            {
                prepare_requetClient(control, control->network->idClient, 12, 12, 0);
                control->etatsend = 0;
            }
            return 0;
        }
    }
    return -1;
}

void gameLoop(t_control *control, int *menuSelect)
{
    int CurrentClickTicks = 0;
    int LastClickTicks = 0;
    SDL_Event event;
    Input in;

    memset(&in, 0, sizeof (in));

    while (!in.key[SDLK_ESCAPE] && !in.quit)
    {
        ckeckAnswerSrv(control);
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
                    prepare_requetClient(control, control->network->idClient, 2, 2, 0);
                    break;
                case SDLK_RIGHT:
                    prepare_requetClient(control, control->network->idClient, 2, 2, 1);
                    break;
                case SDLK_UP:
                    prepare_requetClient(control, control->network->idClient, 2, 3, 0);
                    break;
                case SDLK_DOWN:
                    prepare_requetClient(control, control->network->idClient, 2, 3, 1);
                    break;
                case SDLK_b:
                    prepare_requetClient(control, control->network->idClient, 2, 4, -1);
                    break;
                case SDLK_s:
                    prepare_requetClient(control, control->network->idClient, 2, 5, -1);
                    break;
                default:
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                LastClickTicks = dblClick(CurrentClickTicks, LastClickTicks);
                if (LastClickTicks == 1)
                    if ((*menuSelect = area_button(control, event)) != -1)
                        return;
            }
        }
    }
}


