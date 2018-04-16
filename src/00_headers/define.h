//
// Created by marc on 05/04/18.
//

#ifndef BOMBERMAN_DEFINE_H
#define BOMBERMAN_DEFINE_H

/* version du produit */
#define VERSION "0.0.2"

/* fenetre principale */
#define WINDOW_WIDTH 840
#define WINDOW_HEIGHT 640

// string
#define STRING_BLOCK_SIZE 1024
#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

/* le mesuration de chaque titles carré du jeux */
#define HEIGHT_TILE 40
#define WIDTH_TILE 40

/* le chemin des ressources */
#define REP_SPRITES "res/pictures/"
#define REP_MAP "res/maps/"
#define REP_TTF "res/fonts/"

/* les manches et le nombre de minutes pour chaque manche */
#define STEP 3
#define STEPTIME 3

/* port de connexion au serveur */
#define PORT 8888

#endif //BOMBERMAN_DEFINE_H
