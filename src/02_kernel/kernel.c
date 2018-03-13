//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

/*
 *  init la fenetre et le renderer
 */

void window_init(t_control *control)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Quit();
        return;
    }

    if (control->fenetre == NULL)
        control->fenetre = SDL_CreateWindow("Bomberman",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            WINDOW_WIDTH, WINDOW_HEIGHT,
                                            SDL_WINDOW_SHOWN);
    control->main_renderer = SDL_CreateRenderer(control->fenetre, -1, SDL_RENDERER_ACCELERATED);
}

/*
 * encart d'inscription
 */

void encart_white(t_control* control)
{
    SDL_Rect position;
    position.w = 400;
    position.h = 50;
    position.x = 200;
    position.y = 300;
    if (control->write_loop == 0)
        SDL_SetRenderDrawColor(control->main_renderer, 236, 236, 186, 255);
    else if (control->write_loop == 1)
        SDL_SetRenderDrawColor(control->main_renderer, 210, 210, 150, 255);
    SDL_RenderFillRect(control->main_renderer, &position);
    write_text(control);
    SDL_RenderPresent(control->main_renderer);
}

/*
 *  cree un encart blanc pour couvrir le fenetre
 */

void create_panel_white(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT - 64;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_SetRenderDrawColor(control->main_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(control->main_renderer, &SrcR);
}

// encart de fond jaune qui occupe toute la surface de la fenetre meme des buttons

void create_panel(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_SetRenderDrawColor(control->main_renderer, 255, 242, 1, 255);
    SDL_RenderFillRect(control->main_renderer, &SrcR);
}

// du haut de la fenetre

void create_banderole(t_control *control)
{
    SDL_Rect SrcR;

    SrcR.w = WINDOW_WIDTH;
    SrcR.h = 100;
    SrcR.y = 0;
    SrcR.x = 0;
    SDL_Texture* logo = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dbandeau);
    SDL_RenderCopy(control->main_renderer, logo, &(control->sprites->clogo->img), &SrcR);
    SDL_DestroyTexture(logo);
}

void write_string(t_control *control, SDL_Rect renderquad, char* string)
{
    SDL_Color couleurNoire = {0, 0, 0, 255};
    TTF_Font *police = NULL;

    TTF_Init();
    police = TTF_OpenFont(create_directory_file("Roboto-Black.ttf", 3), 24);
    SDL_Surface* textSurface = TTF_RenderText_Solid(police, string, couleurNoire);
    SDL_Texture* text = SDL_CreateTextureFromSurface(control->main_renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(control->main_renderer, text, NULL, &renderquad);
    SDL_DestroyTexture(text);
    TTF_CloseFont(police);
    TTF_Quit();
}

void write_text_51(t_control* control, SDL_Rect renderQuad, char *string)
{
    SDL_Color couleurNoire = {255, 255, 255, 255};
    TTF_Font *police = NULL;

    TTF_Init();
    //police = TTF_OpenFont("roboto/Roboto-Black.ttf", 24);
    //create_directory_file("Roboto-Black.ttf", 3);
    police = TTF_OpenFont(create_directory_file("Roboto-Black.ttf", 3), 24);
    SDL_Surface* textSurface = TTF_RenderText_Blended(police, string, couleurNoire);
    SDL_Texture* text = SDL_CreateTextureFromSurface(control->main_renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(control->main_renderer, text, NULL, &renderQuad);
    SDL_DestroyTexture(text);
    TTF_CloseFont(police);
    TTF_Quit();
}

void display_button(t_control* control, SDL_Rect posdest)
{
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->cmenu[4].img), &posdest);
    SDL_DestroyTexture(pTexture);
}

void display_background_button(t_control* control, SDL_Rect posdest)
{
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->cmenu[18].img), &posdest);
    SDL_DestroyTexture(pTexture);
}

void create_panel_wait(t_control *control)
{
    SDL_Rect srcr;

    srcr.w = (int)(320 * 1.2);
    srcr.h = (int)(162 * 1.2);
    srcr.y = 200;
    srcr.x = 220;

    SDL_Texture* ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dattente);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->cattente->img), &srcr);
    SDL_DestroyTexture(ptexture);
}

void create_panel_waitset(t_control *control)
{
    SDL_Rect srcr;

    srcr.w = (int)(320 * 1.2);
    srcr.h = (int)(162 * 1.2);
    srcr.y = 200;
    srcr.x = 220;

    SDL_Texture* ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dwaitset);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->cwaitset->img), &srcr);
    SDL_DestroyTexture(ptexture);
}

int dbl_click(int current_click_ticks, int last_click_ticks)
{
    current_click_ticks = SDL_GetTicks();
    if (current_click_ticks - last_click_ticks < 200)
        return 1;
    return SDL_GetTicks();
}
