//
// Created by marc on 01/03/18.
//

#include "headers.h"

int ip_choice_central(t_control* control)
{
    control->write_loop = 0;
    int menu_select = 1;
    window_init(control);
    create_panel(control);
    create_panel_white(control);
    create_banderole(control);
    create_etiquettes(control);
    encart_white(control);
    create_panel_aide_ip(control);
    button_action_choice_partie(control);
    SDL_RenderPresent(control->main_renderer);

    events_loop_ip_choice(control, &menu_select);
    SDL_DestroyRenderer(control->main_renderer);

    return (menu_select);
}

void create_panel_aide_ip(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = 500;
    SrcR.h = 180;
    SrcR.x = 180;
    SrcR.y = 370;

    SDL_Texture* ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->daide);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->caide->img), &SrcR);
    SDL_DestroyTexture(ptexture);
    SDL_RenderPresent(control->main_renderer);

}

void button_action_choice_partie(t_control* control)
{
    SDL_Rect dest = {150,
                     (WINDOW_HEIGHT - 62),
                     control->sprites->cmenu[4].img.w,
                     control->sprites->cmenu[4].img.h};
    display_button(control, dest);
    dest.x = 350;
    display_button(control, dest);
    dest.x = 550;
    display_button(control, dest);

    SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, (int)my_strlen("Return") * 18, 50};
    write_text_51(control, renderQuad, "Return");
    renderQuad.x = 360;
    renderQuad.w = (int)my_strlen("Select") * 18;
    write_text_51(control, renderQuad, "Select");
    renderQuad.x = 570;
    renderQuad.w = (int)my_strlen("Close") * 18;
    write_text_51(control, renderQuad, "Close");
}
