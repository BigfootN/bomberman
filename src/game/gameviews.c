#include "headers.h"

int centralGame(t_control *control)
{
    int menuSelect;
    window_init(control);

    menuSelect = 0;
    control->network->idClient = -1;

    displayScreenWait(control);
    SDL_RenderPresent(control->Main_Renderer);
    if (control->network->srvorclt == 1)
        threadIA();
    SDL_Delay(500);
    tcpthreadClient(control);
    gameLoop(control, &menuSelect);
    SDL_DestroyRenderer(control->Main_Renderer);
    return (menuSelect);
}

void displaySprite(t_control *control)
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
                SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->Main_Renderer, control->sprites->dsprites);
                SDL_RenderCopy(control->Main_Renderer, pTexture1, &(control->sprites->csprites[number].img), &dest1);
                SDL_DestroyTexture(pTexture1);
                SDL_RenderPresent(control->Main_Renderer);
            }
            number++;
            indexY++;
        }
        indexX++;
    }
}

void displayScreenWait(t_control *control)
{
    createPanel(control);
    buttonGame(control);
    createPanelGame(control);
    createCompteur(control);
    createPanelWait(control);
}

void displayScreenGame(t_control *control)
{
    createPanel(control);
    buttonGame(control);
    createPanelGame(control);
    createareaMap(control);
    createCompteur(control);
    createareabonus(control);
}

void threadIA()
{
    pthread_t p_thread;

    if (pthread_create(&p_thread, NULL, centralIA, NULL) < 0)
    {
        perror("could not create thread");
        return;
    }
}

void buttonGame(t_control* control)
{
    SDL_Rect dest = {150,
        (WINDOW_HEIGHT - 62),
        control->sprites->cmenu[4].img.w,
        control->sprites->cmenu[4].img.h};
    displayButton(control, dest);
    dest.x = 350;
    if (control->network->srvorclt == 1)
        displayButton(control, dest);
    dest.x = 550;
    displayButton(control, dest);

    SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, my_strlen("Return") * 18, 50};
    writeText_51(control, renderQuad, "Return");
    if (control->network->srvorclt == 1)
    {
        renderQuad.x = 370;
        renderQuad.w = my_strlen("Start") * 18;
        writeText_51(control, renderQuad, "Start");
    }
    renderQuad.x = 570;
    renderQuad.w = my_strlen("Close") * 18;
    writeText_51(control, renderQuad, "Close");
}