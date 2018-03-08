//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_DEFINE_H
#define BOMBERMAN_DEFINE_H

// fenetre principale
#define WINDOW_WIDTH 840
#define WINDOW_HEIGHT 640 //473

// string
#define STRING_BLOCK_SIZE 1024
#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))

// le mesuration de chaque titles
#define HEIGHT_TILE 40
#define WIDTH_TILE 40

#if defined (WIN32)
#define REP_SPRITES "res\\/sprites\\/"
#define REP_MAP "res\\/map\\/"
#define REP_TTF "res\\/roboto\\/"
#elif defined (linux)
#define REP_SPRITES "res/sprites/"
#define REP_MAP "res/map/"
#define REP_TTF "res/roboto/"
#endif




#define SIGNALWHATEVER 45

#endif //BOMBERMAN_DEFINE_H