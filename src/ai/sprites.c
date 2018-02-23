#include "headers.h"

int centralInitSprites(t_control *control)
{
    if (initSprites(control))
        if (initMenu(control))
            if (initBandeau(control))
                if (initIntro(control))
                    if (initPolice(control))
                        if (initAttente(control))
                            if (initPanneauResultat(control))
                                return (1);
    return (0);
}

// 31 sprites

int initSprites(t_control *control)
{
    int indexX;
    int indexY;
    int numtile;

    indexY = 0;
    indexX = 0;
    numtile = 0;
    control->sprites->dsprites = IMG_Load("sprites/Game_sprites.png"); // charge l'image dans image_ram en RAM
    if (control->sprites->dsprites == NULL)
    {
        my_putstr(" Game_sprites.png introuvable !! \n");
        SDL_Quit();
        return (0);
    }

    control->sprites->csprites = (t_coord*) malloc(sizeof (t_coord) * 31);
    while (indexX < 4)
    {
        indexY = 0;
        while (indexY < 9)
        {
            if (31 > numtile)
            {
                control->sprites->csprites[numtile].img.w = WIDTH_TILE;
                control->sprites->csprites[numtile].img.h = HEIGHT_TILE;
                control->sprites->csprites[numtile].img.x = indexY * WIDTH_TILE;
                control->sprites->csprites[numtile].img.y = indexX * HEIGHT_TILE;
            }
            indexY++;
            numtile++;
        }

        indexX++;
    }
    return (1);
}

int initMenu(t_control *control)
{
    int indexX;
    

    control->sprites->dmenu = IMG_Load("sprites/menu1.png"); // charge l'image dans image_ram en RAM
    if (control->sprites->dmenu == NULL)
    {
        my_putstr("menu.png image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->cmenu = (t_coord*) malloc(sizeof (t_coord) * 20);

    // le bandeau comprenant les joueurs
    control->sprites->cmenu[1].img.w = 256;
    control->sprites->cmenu[1].img.h = 32;
    control->sprites->cmenu[1].img.x = 0;
    control->sprites->cmenu[1].img.y = 0;
    // le bout de bordure
    control->sprites->cmenu[2].img.w = 10;
    control->sprites->cmenu[2].img.h = 32;
    control->sprites->cmenu[2].img.x = 260;
    control->sprites->cmenu[2].img.y = 0;
    // les affiches scores
    control->sprites->cmenu[3].img.w = 138;
    control->sprites->cmenu[3].img.h = 339;
    control->sprites->cmenu[3].img.x = 285;
    control->sprites->cmenu[3].img.y = 0;
    // le bouton
    control->sprites->cmenu[4].img.w = 150;
    control->sprites->cmenu[4].img.h = 60;
    control->sprites->cmenu[4].img.x = 0;
    control->sprites->cmenu[4].img.y = 79;
    // le compteur seul
    control->sprites->cmenu[5].img.w = 30;
    control->sprites->cmenu[5].img.h = 14;
    control->sprites->cmenu[5].img.x = 40;
    control->sprites->cmenu[5].img.y = 0;
    // les chiffres
    indexX = 0;
    while (indexX < 10)
    {
        control->sprites->cmenu[indexX + 6].img.w = 8;
        control->sprites->cmenu[indexX + 6].img.h = 14;
        control->sprites->cmenu[indexX + 6].img.y = 60;
        control->sprites->cmenu[indexX + 6].img.x = indexX * 10;
        indexX++;
    }

    control->sprites->cmenu[17].img.w = 138;
    control->sprites->cmenu[17].img.h = 339;
    control->sprites->cmenu[17].img.x = 280;
    control->sprites->cmenu[17].img.y = 0;
    // fond jaune
    control->sprites->cmenu[18].img.w = 150;
    control->sprites->cmenu[18].img.h = 60;
    control->sprites->cmenu[18].img.x = 0;
    control->sprites->cmenu[18].img.y = 140;

    return (1);
}

int initBandeau(t_control *control)
{
    control->sprites->dlogo = IMG_Load("sprites/SuperBombermanR.jpg");
    if (control->sprites->dlogo == NULL)
    {
        SDL_Quit();
        return (0);
    }

    control->sprites->clogo = (t_coord*) malloc(sizeof (t_coord));
    control->sprites->clogo->img.w = 840;
    control->sprites->clogo->img.h = 473;
    control->sprites->clogo->img.x = 0;
    control->sprites->clogo->img.y = 0;
    return (1);
}

int initIntro(t_control *control)
{
    control->sprites->dbandeau = IMG_Load("sprites/banderole.png");
    if (control->sprites->dbandeau == NULL)
    {
        SDL_Quit();
        return (0);
    }
    control->sprites->cbandeau = (t_coord*) malloc(sizeof (t_coord));
    control->sprites->cbandeau->img.w = 840;
    control->sprites->cbandeau->img.h = 473;
    control->sprites->cbandeau->img.x = 0;
    control->sprites->cbandeau->img.y = 0;
    return (1);
}

int initPolice(t_control *control)
{
    TTF_Init();
    control->sprites->couleur.b = 0;
    control->sprites->couleur.g = 0;
    control->sprites->couleur.r = 255;

    control->sprites->police = TTF_OpenFont("roboto/Roboto-Black.ttf", 45);
    if (control->sprites->police == NULL)
    {
        SDL_Quit();
        return (0);
    }
    TTF_Quit();
    return (1);
}

int initAttente(t_control *control)
{
    control->sprites->dattente = IMG_Load("sprites/attente1.png");
    if (control->sprites->dattente == NULL)
    {
        SDL_Quit();
        return (0);
    }
    control->sprites->cattente = (t_coord*) malloc(sizeof (t_coord));
    control->sprites->cattente->img.w = 320;
    control->sprites->cattente->img.h = 162;
    control->sprites->cattente->img.x = 0;
    control->sprites->cattente->img.y = 0;
    return (1);
}

int initPanneauResultat(t_control *control)
{
    control->sprites->dresultat = IMG_Load("sprites/panneau_final.png");
    if (control->sprites->dresultat == NULL)
    {
        my_putstr("menu.png image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->cresultat = (t_coord*) malloc(sizeof (t_coord) * 20);
    control->sprites->cresultat[1].img.w = 320;
    control->sprites->cresultat[1].img.h = 165;
    control->sprites->cresultat[1].img.x = 0;
    control->sprites->cresultat[1].img.y = 0;
    control->sprites->cresultat[2].img.w = 320;
    control->sprites->cresultat[2].img.h = 165;
    control->sprites->cresultat[2].img.x = 0;
    control->sprites->cresultat[2].img.y = 165;
    return (1);
}