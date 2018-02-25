#include "headers.h"

int scoresCentral(t_control* control)
{
    int menuSelect = -1;
    window_init(control);
    createPanel(control);
    createBanderole(control);
    buttonMenuScores(control);
    SDL_RenderPresent(control->main_renderer);
    //eventsLoopScores(control, &menuSelect);
    SDL_DestroyRenderer(control->main_renderer);
    return (menuSelect);
}

void buttonMenuScores(t_control* control)
{
    SDL_Surface *lbutton = NULL;
    SDL_Texture* button;

    lbutton = IMG_Load("button/boutonReturn.png");
    SDL_Rect dest = {250, WINDOW_HEIGHT - 62, 1, 10};
    dest.w = 150;
    dest.h = 60;
    button = SDL_CreateTextureFromSurface(control->main_renderer, lbutton);
    SDL_FreeSurface(lbutton);
    SDL_RenderCopy(control->main_renderer, button, NULL, &dest);

    lbutton = IMG_Load("button/boutonClose.png");
    dest.x = 500;
    button = SDL_CreateTextureFromSurface(control->main_renderer, lbutton);
    SDL_FreeSurface(lbutton);
    SDL_RenderCopy(control->main_renderer, button, NULL, &dest);
}