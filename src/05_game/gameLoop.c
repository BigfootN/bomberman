#include "headers.h"

int area_button(t_control *control, SDL_Event event)
{
    if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) && event.button.button == SDL_BUTTON_LEFT)
    {
        if (event.motion.x >= 150 && event.motion.x <= 300)
        {
            if (control->send_state == 1)
                prepare_requetClient(control, control->network->client_id, 12, 12, 0);
            if (control->network->net_clt_srv_state == 1)
            {
                prepare_requetClient(control, control->network->client_id, 50, 0, 0);
                control->send_state = 0;
                return (1);
            }
            control->send_state = 0;
            return (2);
        }
        else if (event.motion.x >= 350 && event.motion.x <= 500 && control->network->net_clt_srv_state == 1)
        {
            if (control->send_state == 1)
                startGame(control);
        }
        else if (event.motion.x >= 550 && event.motion.x <= 700)
        {
            if (control->send_state == 1)
            {
                prepare_requetClient(control, control->network->client_id, 12, 12, 0);
                control->send_state = 0;
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
    input_t in;

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
                in.mouse_x = event.motion.x;
                in.mouse_y = event.motion.y;
                in.mouse_xrel = event.motion.xrel;
                in.mouse_yrel = event.motion.yrel;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    prepare_requetClient(control, control->network->client_id, 2, 2, 0);
                    break;
                case SDLK_RIGHT:
                    prepare_requetClient(control, control->network->client_id, 2, 2, 1);
                    break;
                case SDLK_UP:
                    prepare_requetClient(control, control->network->client_id, 2, 3, 0);
                    break;
                case SDLK_DOWN:
                    prepare_requetClient(control, control->network->client_id, 2, 3, 1);
                    break;
                case SDLK_b:
                    prepare_requetClient(control, control->network->client_id, 2, 4, -1);
                    break;
                case SDLK_s:
                    prepare_requetClient(control, control->network->client_id, 2, 5, -1);
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


