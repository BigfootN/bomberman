//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int introduction_central(t_control *control)
{
    int menu_select = 0;

    window_init(control);
    create_panel(control);
    sprite_panel_introduction(control);
    SDL_RenderPresent(control->main_renderer);

    events_loop_introduction(control, &menu_select);
    SDL_DestroyRenderer(control->main_renderer);

    return (menu_select);
}

void sprite_panel_introduction(t_control* control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT - 64;

    SDL_Texture* logo = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dlogo);
    SDL_RenderCopy(control->main_renderer, logo, &(control->sprites->clogo->img), &SrcR);
    SDL_DestroyTexture(logo);

    SDL_Rect dest = {150,
                     (WINDOW_HEIGHT - 62),
                     control->sprites->cmenu[4].img.w,
                     control->sprites->cmenu[4].img.h};

    display_button(control, dest);
    dest.x = 350;
    display_button(control, dest);
    dest.x = 550;
    display_button(control, dest);
    /*  dest.x = 590;
      displayButton(control, dest);*/

    SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, (int)my_strlen("Serveur") * 18, 50};
    write_text_51(control, renderQuad, "Serveur");
    renderQuad.x = 370;
    renderQuad.w = (int)my_strlen("Client") * 18;
    write_text_51(control, renderQuad, "Client");
    /* renderQuad.x = 430;
     renderQuad.w = my_strlen("Credits") * 18;
     writeText_51(control, renderQuad, "Credits");*/
    renderQuad.x = 570;
    renderQuad.w = (int)my_strlen("Close") * 18;
    write_text_51(control, renderQuad, "Close");

}