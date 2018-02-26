#include "headers.h"

void createPanelGame(t_control *control)
{
    SDL_Rect SrcR;
    SrcR.w = WINDOW_WIDTH;
    SrcR.h = WINDOW_HEIGHT - 64;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_SetRenderDrawColor(control->Main_Renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(control->Main_Renderer, &SrcR);
}

void createareaMap(t_control *control)
{
    SDL_Rect position;

    position.w = 15 * 40;
    position.h = 11 * 40;
    position.x = 10;
    position.y = (32 * 1.8) + 10;

    SDL_SetRenderDrawColor(control->Main_Renderer, 240, 128, 0, 255);
    SDL_RenderFillRect(control->Main_Renderer, &position);
}

void createCompteur(t_control *control)
{
    SDL_Rect dest = {0, 0, WINDOW_WIDTH, (32 * 1.8)};
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->Main_Renderer, pTexture, &(control->sprites->cmenu[2].img), &dest);
    SDL_DestroyTexture(pTexture);

    SDL_Rect dest1 = {(WINDOW_WIDTH / 5), 0, (256 * 1.8), (32 * 1.8)};
    SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->cmenu[1].img), &dest1);
    SDL_DestroyTexture(pTexture1);
}

void displayCounter(t_control *control, int minute1, int minute2, int seconde1, int seconde2)
{
    SDL_Rect dest1 = {(WINDOW_WIDTH / 5) + 195, 15, (8 * 1.8), (14 * 1.8)};

    SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->cmenu[minute1 + 6].img), &dest1);

    dest1.x = (WINDOW_WIDTH / 5) + 209;
    SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->cmenu[minute2 + 6].img), &dest1);

    dest1.x = (WINDOW_WIDTH / 5) + 230;
    SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->cmenu[seconde1 + 6].img), &dest1);

    dest1.x = (WINDOW_WIDTH / 5) + 243;
    SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->cmenu[seconde2 + 6].img), &dest1);
    SDL_DestroyTexture(pTexture1);
}

void createareabonus(t_control *control)
{
    SDL_Rect dest = {(15 * 40) + 40, (32 * 1.8) + 10, 138, 339};
    SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->cmenu[17].img), &dest);
    SDL_DestroyTexture(pTexture1);
}

void DisplayMap(t_control *control, t_svrSd *requete)
{
    int row;
    int col;
    int tuile;
    int bm;
    int action;

    col = 0;
    row = 0;
    if (requete->pos[0] == 0 && requete->pos[1] == 0)
        return;
    while (row < requete->pos[0])
    {
        col = 0;
        while (col < requete->pos[1])
        {
            tuile = requete->mapDecor[row][col];
            SDL_Rect dest = {(col * WIDTH_TILE) + 10, (row * HEIGHT_TILE) + (32 * 1.8) + 10, WIDTH_TILE, HEIGHT_TILE};
            SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dsprites);
            if (tuile >= 0)
                SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->csprites[tuile].img), &dest);
            bm = requete->mapBM[row][col];
            if (bm != -1 && bm >= 0)
                SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->csprites[bm].img), &dest);
            action = requete->mapAction[row][col];
            if (action != -1 && action >= 0)
                SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->csprites[action].img), &dest);
            SDL_DestroyTexture(pTexture1);
            col++;
        }
        row++;
    }
}

void writePanetScore(t_control *control, t_svrSd *requete)
{
    int number;
    char buf[255];

    number = requete->statePlayer.score;
    sprintf(buf, "%d", number);

    SDL_Rect renderQuad = {(15 * 40) + 100, (32 * 1.8) + 70, my_strlen(buf) * 18, 50};
    writeString(control, renderQuad, buf);

    number = requete->statePlayer.bomb;
    sprintf(buf, "%d", number);
    SDL_Rect renderQuad2 = {(15 * 40) + 100, (32 * 1.8) + 180, my_strlen(buf) * 18, 50};
    writeString(control, renderQuad2, buf);

    number = requete->statePlayer.speed;
    sprintf(buf, "%d", number);
    SDL_Rect renderQuad3 = {(15 * 40) + 100, (32 * 1.8) + 290, my_strlen(buf) * 18, 50};
    writeString(control, renderQuad3, buf);
    SDL_RenderPresent(control->Main_Renderer);
}

void createPanelResult(t_control *control, t_svrSd *requete)
{
    SDL_Rect SrcR;
    SrcR.w = 320 * 1.2;
    SrcR.h = 162 * 1.2;
    SrcR.y = 100;
    SrcR.x = 220;

    if (requete->statePlayer.life > 0)
    {
        SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dresultat);
        SDL_RenderCopy(control->Main_Renderer, pTexture, &(control->sprites->cresultat[2].img), &SrcR);
        SDL_DestroyTexture(pTexture);
    }
    else if (requete->statePlayer.life <= 0)
    {
        SDL_Texture* pTexture = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dresultat);
        SDL_RenderCopy(control->Main_Renderer, pTexture, &(control->sprites->cresultat[1].img), &SrcR);
        SDL_DestroyTexture(pTexture);
    }
}