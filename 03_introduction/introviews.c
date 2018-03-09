#include "headers.h"

int introductionCentral(t_control *control)
{
    int menuSelect = 0;

    window_init(control);
    createPanel(control);
    SpritePanelIntroduction(control);
    SDL_RenderPresent(control->Main_Renderer);

    eventsLoopIntroduction(control, &menuSelect);
    SDL_DestroyRenderer(control->Main_Renderer);

    return (menuSelect);
}

void SpritePanelIntroduction(t_control* control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT - 64;

      SDL_Texture* logo = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dlogo);
      SDL_RenderCopy(control->Main_Renderer, logo, &(control->sprites->clogo->img), &SrcR);
      SDL_DestroyTexture(logo);
     
    SDL_Rect dest = {150,
        (WINDOW_HEIGHT - 62),
        control->sprites->cmenu[4].img.w,
        control->sprites->cmenu[4].img.h};

    displayButton(control, dest);
    dest.x = 350;
    displayButton(control, dest);
    dest.x = 550;
    displayButton(control, dest);
  /*  dest.x = 590;
    displayButton(control, dest);*/

    SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, my_strlen("Serveur") * 18, 50};
    writeText_51(control, renderQuad, "Serveur");
    renderQuad.x = 370;
    renderQuad.w = my_strlen("Client") * 18;
    writeText_51(control, renderQuad, "Client");
   /* renderQuad.x = 430;
    renderQuad.w = my_strlen("Credits") * 18;
    writeText_51(control, renderQuad, "Credits");*/
    renderQuad.x = 570;
    renderQuad.w = my_strlen("Close") * 18;
    writeText_51(control, renderQuad, "Close");

}