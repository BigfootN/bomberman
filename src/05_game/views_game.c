//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int central_game(t_control *control)
{
    int menuSelect;
    window_init(control);

    menuSelect = 0;
    control->network->id_client = -1;

    display_screen_wait(control);
    SDL_RenderPresent(control->main_renderer);
    if (control->network->srv_or_clt == 1)
        thread_ia();
    SDL_Delay(500);
    tcp_thread_client(control);
    game_loop(control, &menuSelect);
    SDL_DestroyRenderer(control->main_renderer);
    return (menuSelect);
}

void display_sprite(t_control *control)
{
    int indexX;
    int indexY;
    int number;

    number = 0;
    indexX = 0;
    while (indexX < 4)
    {
        indexY = 0;
        while (indexY < 9)
        {
            if (number < 31)
            {
                SDL_Rect dest1 = {indexY * WIDTH_TILE, indexX * WIDTH_TILE, WIDTH_TILE, WIDTH_TILE};
                SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dsprites);
                SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->csprites[number].img), &dest1);
                SDL_DestroyTexture(pTexture1);
                SDL_RenderPresent(control->main_renderer);
            }
            number++;
            indexY++;
        }
        indexX++;
    }
}




void display_screen_wait(t_control *control)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control);
    create_compteur(control);
    create_panel_wait(control);
}

void display_screen_game(t_control *control)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control);
    create_area_map(control);
    create_compteur(control);
    create_area_bonus(control);
}

void thread_ia()
{
    pthread_t p_thread;

    if (pthread_create(&p_thread, NULL, central_ia, NULL) < 0)
    {
        perror("could not create thread");
        return;
    }
}

void button_game(t_control* control)
{
    SDL_Rect dest = {150,
                     (WINDOW_HEIGHT - 62),
                     control->sprites->cmenu[4].img.w,
                     control->sprites->cmenu[4].img.h};
    display_button(control, dest);
    dest.x = 350;
    if (control->network->srv_or_clt == 1)
        display_button(control, dest);
    dest.x = 550;
    display_button(control, dest);

    SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, my_strlen("Return") * 18, 50};
    write_text_51(control, renderQuad, "Return");
    if (control->network->srv_or_clt == 1)
    {
        renderQuad.x = 370;
        renderQuad.w = my_strlen("Start") * 18;
        write_text_51(control, renderQuad, "Start");
    }
    renderQuad.x = 570;
    renderQuad.w = my_strlen("Close") * 18;
    write_text_51(control, renderQuad, "Close");
}
