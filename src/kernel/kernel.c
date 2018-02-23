#include "headers.h"

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
    control->Main_Renderer = SDL_CreateRenderer(control->fenetre, -1, SDL_RENDERER_ACCELERATED);
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
    if (control->writeLoop == 0)
        SDL_SetRenderDrawColor(control->Main_Renderer, 236, 236, 186, 255);
    else if (control->writeLoop == 1)
        SDL_SetRenderDrawColor(control->Main_Renderer, 210, 210, 150, 255);
    SDL_RenderFillRect(control->Main_Renderer, &position);
    writeText(control);
    SDL_RenderPresent(control->Main_Renderer);
}

/*
 *  cree un encart blanc pour couvrir le fenetre
 */

void createPanelWhite(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT - 64;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_SetRenderDrawColor(control->Main_Renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(control->Main_Renderer, &SrcR);
}

// encart de fond jaune qui occupe toute la surface de la fenetre meme des buttons

void createPanel(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_SetRenderDrawColor(control->Main_Renderer, 255, 242, 1, 255);
    SDL_RenderFillRect(control->Main_Renderer, &SrcR);
}

// du haut de la fenetre

void createBanderole(t_control *control)
{
    SDL_Rect SrcR;

    SrcR.w = WINDOW_WIDTH;
    SrcR.h = 100;
    SrcR.y = 0;
    SrcR.x = 0;
    SDL_Texture* logo = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dbandeau);
    SDL_RenderCopy(control->Main_Renderer, logo, &(control->sprites->clogo->img), &SrcR);
    SDL_DestroyTexture(logo);
}

void writeString(t_control *control, SDL_Rect renderQuad, char* string)
{
    SDL_Color couleurNoire = {0, 0, 0, 255};
    TTF_Font *police = NULL;

    TTF_Init();
    police = TTF_OpenFont("roboto/Roboto-Black.ttf", 24);
    SDL_Surface* textSurface = TTF_RenderText_Solid(police, string, couleurNoire);
    SDL_Texture* text = SDL_CreateTextureFromSurface(control->Main_Renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(control->Main_Renderer, text, NULL, &renderQuad);
    SDL_DestroyTexture(text);
    TTF_CloseFont(police);
    TTF_Quit();
}

void writeText_51(t_control* control, SDL_Rect renderQuad, char *string)
{
    SDL_Color couleurNoire = {255, 255, 255, 255};
    TTF_Font *police = NULL;
    
    TTF_Init();
    police = TTF_OpenFont("roboto/Roboto-Black.ttf", 24);
    SDL_Surface* textSurface = TTF_RenderText_Blended(police, string, couleurNoire);
    SDL_Texture* text = SDL_CreateTextureFromSurface(control->Main_Renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(control->Main_Renderer, text, NULL, &renderQuad);
    SDL_DestroyTexture(text);
    TTF_CloseFont(police);
    TTF_Quit();
}

void displayButton(t_control* control, SDL_Rect posdest)
{
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->Main_Renderer, pTexture, &(control->sprites->cmenu[4].img), &posdest);
    SDL_DestroyTexture(pTexture);
}

void displayBackgroundButton(t_control* control, SDL_Rect posdest)
{
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->Main_Renderer, pTexture, &(control->sprites->cmenu[18].img), &posdest);
    SDL_DestroyTexture(pTexture);
}

void createPanelWait(t_control *control)
{
    SDL_Rect SrcR;

    SrcR.w = 320 * 1.2;
    SrcR.h = 162 * 1.2;
    SrcR.y = 100;
    SrcR.x = 220;

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dattente);
    SDL_RenderCopy(control->Main_Renderer, pTexture, &(control->sprites->cattente->img), &SrcR);
    SDL_DestroyTexture(pTexture);
}

int dblClick(int CurrentClickTicks, int LastClickTicks)
{
    CurrentClickTicks = SDL_GetTicks();
    if (CurrentClickTicks - LastClickTicks < 200)
        return 1;
    return SDL_GetTicks();
}