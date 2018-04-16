//
// Created by marc on 05/04/18.
//

#include "headers.h"

int central_init_sprites(t_control *control) {

    if (search_folder(REP_SPRITES))
        if (search_folder(REP_TTF))
            if (search_folder(REP_MAP)) {
                if (init_sprites(control))
                    if (init_menu(control))
                        if (init_bandeau(control))
                            if (init_intro(control))
                                if (init_attente(control))
                                    if (init_panneau_resultat(control))
                                        if (init_manche(control))
                                            if (init_aides_ipserver(control))
                                                if (init_aides_prepa_game(control))
                                                    if (init_partie_start(control))
                                                        if (init_users_max(control))
                                                            return (1);
            }
    return (5); /* indique qu'il y as eu probleme pour trouver les ou la ressource(s) */
}

// 31 sprites

int init_sprites(t_control *control) {
    int indexX;
    int indexY;
    int numtile;
    char *name_image;

    indexX = 0;
    numtile = 0;

    name_image = create_directory_file("Game_sprites.gif", 1);

    control->sprites->csprites = (t_coord *) malloc(sizeof(t_coord) * 32);
    control->sprites->dsprites = IMG_Load(name_image); // charge l'image dans image_ram en RAM
    if (control->sprites->dsprites == NULL) {
        my_putstr(" Game_sprites.gif introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    while (indexX < 4) {
        indexY = 0;
        while (indexY < 9) {
            if (32 > numtile) {
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

int init_menu(t_control *control) {
    int indexX;
    char *name_image;

    name_image = create_directory_file("menu.gif", 1);

    control->sprites->cmenu = (t_coord *) malloc(sizeof(t_coord) * 20);
    control->sprites->dmenu = IMG_Load(name_image); // charge l'image dans image_ram en RAM
    if (control->sprites->dmenu == NULL) {
        my_putstr("menu1.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);
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
    while (indexX < 10) {
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

int init_bandeau(t_control *control) {
    char *name_image;

    name_image = create_directory_file("SuperBombermanR.gif", 1);
    control->sprites->clogo = (t_coord *) malloc(sizeof(t_coord));

    control->sprites->dlogo = IMG_Load(name_image);
    if (control->sprites->dlogo == NULL) {
        my_putstr("SuperBombermanR.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->clogo->img.w = 840;
    control->sprites->clogo->img.h = 473;
    control->sprites->clogo->img.x = 0;
    control->sprites->clogo->img.y = 0;
    return (1);
}

int init_intro(t_control *control) {
    char *name_image;

    name_image = create_directory_file("banderole.gif", 1);

    control->sprites->cbandeau = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->dbandeau = IMG_Load(name_image);

    if (control->sprites->dbandeau == NULL) {
        my_putstr("banderole.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->cbandeau->img.w = 840;
    control->sprites->cbandeau->img.h = 473;
    control->sprites->cbandeau->img.x = 0;
    control->sprites->cbandeau->img.y = 0;
    return (1);
}

int init_attente(t_control *control) {
    char *name_image;

    name_image = create_directory_file("attente.gif", 1);

    control->sprites->cattente = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->dattente = IMG_Load(name_image);

    if (control->sprites->dattente == NULL) {
        my_putstr("attente.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->cattente->img.w = 320;
    control->sprites->cattente->img.h = 162;
    control->sprites->cattente->img.x = 0;
    control->sprites->cattente->img.y = 0;
    return (1);
}

int init_panneau_resultat(t_control *control) {
    char *name_image;

    name_image = create_directory_file("panneau_final.gif", 1);

    control->sprites->cresultat = (t_coord *) malloc(sizeof(t_coord) * 20);
    control->sprites->dresultat = IMG_Load(name_image);
    if (control->sprites->dresultat == NULL) {
        my_putstr("panneau_final.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

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

int init_manche(t_control *control) {
    char *name_image;

    name_image = create_directory_file("waitset.gif", 1);

    control->sprites->cwaitset = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->dwaitset = IMG_Load(name_image);
    if (control->sprites->dwaitset == NULL) {
        my_putstr("waitset.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->cwaitset->img.w = 320;
    control->sprites->cwaitset->img.h = 162;
    control->sprites->cwaitset->img.x = 0;
    control->sprites->cwaitset->img.y = 0;
    return (1);
}

int init_aides_ipserver(t_control *control) {
    char *name_image;

    name_image = create_directory_file("aide_ipserver.gif", 1);
    control->sprites->caide = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->daide = IMG_Load(name_image);
    if (control->sprites->daide == NULL) {
        my_putstr("aide_ipserver.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->caide->img.w = 286;
    control->sprites->caide->img.h = 90;
    control->sprites->caide->img.x = 0;
    control->sprites->caide->img.y = 0;
    return (1);
}


int init_aides_prepa_game(t_control *control) {
    char *name_image;

    name_image = create_directory_file("aide_game.gif", 1);
    control->sprites->cprepagame = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->dprepagame = IMG_Load(name_image);
    if (control->sprites->dprepagame == NULL) {
        my_putstr("aide_game.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->cprepagame->img.w = 286;
    control->sprites->cprepagame->img.h = 90;
    control->sprites->cprepagame->img.x = 0;
    control->sprites->cprepagame->img.y = 0;
    return (1);
}

int init_partie_start(t_control *control) {
    char *name_image;

    name_image = create_directory_file("partiestart.gif", 1);
    control->sprites->cpartystart = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->dpartystart = IMG_Load(name_image);
    if (control->sprites->dpartystart == NULL) {
        my_putstr("partiestart.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->cpartystart->img.w = 286;
    control->sprites->cpartystart->img.h = 90;
    control->sprites->cpartystart->img.x = 0;
    control->sprites->cpartystart->img.y = 0;
    return (1);
}

int init_users_max(t_control *control) {
    char *name_image;

    name_image = create_directory_file("usersmax.gif", 1);
    control->sprites->cmaxusers = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->dmaxusers = IMG_Load(name_image);
    if (control->sprites->dmaxusers == NULL) {
        my_putstr("usersmax.gif image introuvable !! \n");
        free(name_image);
        SDL_Quit();
        return (0);
    }
    free(name_image);

    control->sprites->cmaxusers->img.w = 286;
    control->sprites->cmaxusers->img.h = 90;
    control->sprites->cmaxusers->img.x = 0;
    control->sprites->cmaxusers->img.y = 0;
    return (1);
}

void delete_sprites(t_control *control) {
    SDL_FreeSurface(control->sprites->dsprites);
    SDL_FreeSurface(control->sprites->dmenu);
    SDL_FreeSurface(control->sprites->dlogo);
    SDL_FreeSurface(control->sprites->dbandeau);
    SDL_FreeSurface(control->sprites->dattente);
    SDL_FreeSurface(control->sprites->dresultat);
    SDL_FreeSurface(control->sprites->dwaitset);
    SDL_FreeSurface(control->sprites->daide);
    SDL_FreeSurface(control->sprites->dprepagame);
    SDL_FreeSurface(control->sprites->dpartystart);
    SDL_FreeSurface(control->sprites->dmaxusers);
    free(control->sprites->csprites);
    free(control->sprites->cmenu);
    free(control->sprites->clogo);
    free(control->sprites->cbandeau);
    free(control->sprites->cattente);
    free(control->sprites->cresultat);
    free(control->sprites->cwaitset);
    free(control->sprites->caide);
    free(control->sprites->cprepagame);
    free(control->sprites->cpartystart);
    free(control->sprites->cmaxusers);
}