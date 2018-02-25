#include "headers.h"

int introductionCentral(t_control *control)
{
    int menuSelect = 0;

    window_init(control);
    createPanel(control);
    SpritePanelIntroduction(control);
    SDL_RenderPresent(control->main_renderer);

    eventsLoopIntroduction(control, &menuSelect);
    SDL_DestroyRenderer(control->main_renderer);

    return (menuSelect);
}

void SpritePanelIntroduction(t_control* control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT - 64;

      SDL_Texture* logo = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->logo_surf);
      SDL_RenderCopy(control->main_renderer, logo, &(control->sprites->logo_coord->img), &SrcR);
      SDL_DestroyTexture(logo);
     
    SDL_Rect dest = {150,
        (WINDOW_HEIGHT - 62),
        control->sprites->menu_coord[4].img.w,
        control->sprites->menu_coord[4].img.h};

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