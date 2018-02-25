#include "headers.h"

/*
 *  init la win et le renderer
 */

void window_init(t_control *control)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Quit();
        return;
    }

    if (control->win == NULL)
        control->win = SDL_CreateWindow("Bomberman",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            WINDOW_WIDTH, WINDOW_HEIGHT,
                                            SDL_WINDOW_SHOWN);
    control->main_renderer = SDL_CreateRenderer(control->win, -1, SDL_RENDERER_ACCELERATED);
}

/* 
 * encart d'inscription
 */

void encartClair(t_control* control)
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
    writeText(control);
    SDL_RenderPresent(control->main_renderer);
}

/*
 *  cree un encart blanc pour couvrir le win
 */

void createPanelWhite(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT - 64;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_SetRenderDrawColor(control->main_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(control->main_renderer, &SrcR);
}

// encart de fond jaune qui occupe toute la surface de la win meme des buttons

void createPanel(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_SetRenderDrawColor(control->main_renderer, 255, 242, 1, 255);
    SDL_RenderFillRect(control->main_renderer, &SrcR);
}

// du haut de la win

void createBanderole(t_control *control)
{
    SDL_Rect SrcR;

    SrcR.w = WINDOW_WIDTH;
    SrcR.h = 100;
    SrcR.y = 0;
    SrcR.x = 0;
    SDL_Texture* logo = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->banner_surf);
    SDL_RenderCopy(control->main_renderer, logo, &(control->sprites->logo_coord->img), &SrcR);
    SDL_DestroyTexture(logo);
}

void writeString(t_control *control, SDL_Rect renderQuad, char* string)
{
    SDL_Color colorNoire = {0, 0, 0, 255};
    TTF_Font *font = NULL;

    TTF_Init();
    font = TTF_OpenFont("roboto/Roboto-Black.ttf", 24);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, string, colorNoire);
    SDL_Texture* text = SDL_CreateTextureFromSurface(control->main_renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(control->main_renderer, text, NULL, &renderQuad);
    SDL_DestroyTexture(text);
    TTF_CloseFont(font);
    TTF_Quit();
}

void writeText_51(t_control* control, SDL_Rect renderQuad, char *string)
{
    SDL_Color colorNoire = {255, 255, 255, 255};
    TTF_Font *font = NULL;
    
    TTF_Init();
    font = TTF_OpenFont("roboto/Roboto-Black.ttf", 24);
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, string, colorNoire);
    SDL_Texture* text = SDL_CreateTextureFromSurface(control->main_renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(control->main_renderer, text, NULL, &renderQuad);
    SDL_DestroyTexture(text);
    TTF_CloseFont(font);
    TTF_Quit();
}

void displayButton(t_control* control, SDL_Rect posdest)
{
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->menu_surf);
    SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->menu_coord[4].img), &posdest);
    SDL_DestroyTexture(pTexture);
}

void displayBackgroundButton(t_control* control, SDL_Rect posdest)
{
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->menu_surf);
    SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->menu_coord[18].img), &posdest);
    SDL_DestroyTexture(pTexture);
}

void createPanelWait(t_control *control)
{
    SDL_Rect SrcR;

    SrcR.w = 320 * 1.2;
    SrcR.h = 162 * 1.2;
    SrcR.y = 100;
    SrcR.x = 220;

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->wait_surf);
    SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->wait_coord->img), &SrcR);
    SDL_DestroyTexture(pTexture);
}

int dblClick(int CurrentClickTicks, int LastClickTicks)
{
    CurrentClickTicks = SDL_GetTicks();
    if (CurrentClickTicks - LastClickTicks < 200)
        return 1;
    return SDL_GetTicks();
}