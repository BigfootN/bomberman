//
// Created by marc on 01/03/18.
//

#include "bomberman.h"


int scores_central(t_control* control)
{
    int menu_select = -1;
    window_init(control);
    create_panel(control);
    create_banderole(control);
    button_menu_scores(control);
    SDL_RenderPresent(control->main_renderer);
    //eventsLoopScores(control, &menuSelect);
    SDL_DestroyRenderer(control->main_renderer);
    return (menu_select);
}

void button_menu_scores(t_control* control)
{
    SDL_Surface *lbutton = NULL;
    SDL_Texture* button;
    char *name_image;

    name_image = create_directory_file("boutonReturn.png", 1);
    lbutton = IMG_Load(name_image); // charge l'image dans image_ram en RAM
    SDL_Rect dest = {250, WINDOW_HEIGHT - 62, 1, 10};
    dest.w = 150;
    dest.h = 60;
    button = SDL_CreateTextureFromSurface(control->main_renderer, lbutton);
    SDL_FreeSurface(lbutton);
    SDL_RenderCopy(control->main_renderer, button, NULL, &dest);

    name_image = create_directory_file("boutonClose.png", 1);
    lbutton = IMG_Load(name_image);
    dest.x = 500;
    button = SDL_CreateTextureFromSurface(control->main_renderer, lbutton);
    SDL_FreeSurface(lbutton);
    SDL_RenderCopy(control->main_renderer, button, NULL, &dest);
}
