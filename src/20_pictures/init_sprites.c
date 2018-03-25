//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int central_init_sprites(t_control *control) {

    if (search_folder(REP_SPRITES))
        if (search_folder(REP_TTF))
            if (search_folder(REP_MAP)) {
                if (init_sprites(control))
                    if (init_menu(control))
                        if (init_bandeau(control))
                            if (init_intro(control))
                                if (init_police(control))
                                    if (init_attente(control))
                                        if (init_panneau_resultat(control))
                                            if (init_manche(control))
                                                return (1);
            }
    return (5); /* indique qu'il y as eu probleme pour trouver les ou la ressource(s) */
}

char *create_directory_file(char const *name, int directory) {

    char *name_directory;
//    int index;
    int total_char;

    total_char = (int) my_strlen(REP_SPRITES) + (int) my_strlen(name) + 2;
    if ((name_directory = (char *) malloc(sizeof(char) * total_char)) == NULL)
        return NULL;
//    index = 0;
    memset(name_directory, '\0', total_char);
    /* while(name_directory[index] != '\0') {
         name_directory[index] = '\0';
         index++;
     }*/

    if (directory == 1)
        my_strcat(name_directory, REP_SPRITES);
    else if (directory == 2)
        my_strcat(name_directory, REP_MAP);
    else if (directory == 3)
        my_strcat(name_directory, REP_TTF);
    my_strcat(name_directory, name);

    return (name_directory);
}

// 31 sprites

int init_sprites(t_control *control) {
    int indexX;
    int indexY;
    int numtile;
    char *name_image;

    indexX = 0;
    numtile = 0;
    name_image = create_directory_file("Game_sprites.png", 1);

    control->sprites->dsprites = IMG_Load(name_image); // charge l'image dans image_ram en RAM
    if (control->sprites->dsprites == NULL) {
        my_putstr(" Game_sprites.png introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->csprites = (t_coord *) malloc(sizeof(t_coord) * 31);
    while (indexX < 4) {
        indexY = 0;
        while (indexY < 9) {
            if (31 > numtile) {
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

    name_image = create_directory_file("menu1.png", 1);
    control->sprites->dmenu = IMG_Load(name_image); // charge l'image dans image_ram en RAM
    if (control->sprites->dmenu == NULL) {
        my_putstr("menu1.png image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->cmenu = (t_coord *) malloc(sizeof(t_coord) * 20);
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

    name_image = create_directory_file("SuperBombermanR.jpg", 1);
    control->sprites->dlogo = IMG_Load(name_image);
    if (control->sprites->dlogo == NULL) {
        my_putstr("SuperBombermanR.jpg image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->clogo = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->clogo->img.w = 840;
    control->sprites->clogo->img.h = 473;
    control->sprites->clogo->img.x = 0;
    control->sprites->clogo->img.y = 0;
    return (1);
}

int init_intro(t_control *control) {
    char *name_image;

    name_image = create_directory_file("banderole.png", 1);
    control->sprites->dbandeau = IMG_Load(name_image);
    if (control->sprites->dbandeau == NULL) {
        my_putstr("banderole.png image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->cbandeau = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->cbandeau->img.w = 840;
    control->sprites->cbandeau->img.h = 473;
    control->sprites->cbandeau->img.x = 0;
    control->sprites->cbandeau->img.y = 0;
    return (1);
}

int init_police(t_control *control) {
    char *name_image;

    TTF_Init();
    control->sprites->couleur.b = 0;
    control->sprites->couleur.g = 0;
    control->sprites->couleur.r = 255;

    name_image = create_directory_file("Roboto-Black.ttf", 3);
    control->sprites->police = TTF_OpenFont(name_image, 45);
    if (control->sprites->police == NULL) {
        my_putstr("Roboto-Black.ttf image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    TTF_Quit();
    return (1);
}

int init_attente(t_control *control) {
    char *name_image;

    name_image = create_directory_file("attente2.png", 1);
    control->sprites->dattente = IMG_Load(name_image);
    if (control->sprites->dattente == NULL) {
        my_putstr("attente2.png image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->cattente = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->cattente->img.w = 320;
    control->sprites->cattente->img.h = 162;
    control->sprites->cattente->img.x = 0;
    control->sprites->cattente->img.y = 0;
    return (1);
}

int init_panneau_resultat(t_control *control) {
    char *name_image;

    name_image = create_directory_file("panneau_final2.png", 1);
    control->sprites->dresultat = IMG_Load(name_image);
    if (control->sprites->dresultat == NULL) {
        my_putstr("panneau_final2.png image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->cresultat = (t_coord *) malloc(sizeof(t_coord) * 20);
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

    name_image = create_directory_file("waitset.png", 1);
    control->sprites->dwaitset = IMG_Load(name_image);
    if (control->sprites->dwaitset == NULL) {
        my_putstr("waitset.png image introuvable !! \n");
        SDL_Quit();
        return (0);
    }
    control->sprites->cwaitset = (t_coord *) malloc(sizeof(t_coord));
    control->sprites->cwaitset->img.w = 320;
    control->sprites->cwaitset->img.h = 162;
    control->sprites->cwaitset->img.x = 0;
    control->sprites->cwaitset->img.y = 0;
    return (1);
}
