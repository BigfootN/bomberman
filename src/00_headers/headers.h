//
// Created by marc on 05/04/18.
//

#ifndef BOMBERMAN_HEADERS_H
#define BOMBERMAN_HEADERS_H

/*
 * SDL2
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_ttf.h>

/*
 * annexe
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include <string.h>
#include <strings.h>

#if defined WIN32 || defined WIN64
//pour les sockets
#include <winsock2.h>
typedef int socklen_t;
//pour les threads
#include <pthread.h>
#include <windows.h>
#include <sys/time.h>
//#pragma comment(lib,"ws2_32.lib")
#define psleep(sec) Sleep ((sec) * 1000)
#elif defined __linux__
// annexe
#include <unistd.h>
#include <time.h>
// network
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <stdint.h>
#include <endian.h>
#include <pthread.h> //for threading , link with lpthread
#include <errno.h>
#endif


/*
 * 00_headers
 */
#include "define.h"
#include "structures.h"
#include "game.h"

/*
 *  01_main
 */
#include "bomberman.h"

/*
 * 02_kernel
 */
#include "inits.h"
#include "chainedlist.h"
#include "kernel.h"

/*
 * 03_introduction
 */
#include "introloop.h"
#include "introviews.h"

/*
 * 04_ipchoice
 */
#include "choiceiploop.h"
#include "choiceipwindow.h"
#include "choicepviews.h"


/*
 * 04_ prepa_game
 */
#include "display_prepagame.h"
#include "write_prepa_game.h"
#include "loop_prepagame.h"

/*
 * 05_game
 */
#include "display_game.h"
#include "loop_game.h"
#include "panel_game.h"
#include "time_game.h"
#include "views_game.h"

/*
 * 18_network
 */
#include "tcp_client.h"
#include "tcp_server.h"
#include "network_player.h"
#include "network.h"

/*
 * 19_ia
 */
#include "ia.h"
#include "ia_bolus_malus.h"
#include "ia_bomb.h"
#include "ia_counter.h"
#include "ia_dead.h"
#include "ia_explosion.h"
#include "ia_map.h"
#include "ia_monster.h"
#include "ia_pions.h"
#include "ia_send_msg.h"
#include "ia_timer.h"
#include "ia_party.h"

/*
 * 20_pictures
 */
#include "annexe_directory.h"
#include "map.h"
#include "init_pictures.h"
/*
 * 21_libs
 */
#include "libs.h"

/* pointeur de function pour le menu des differents panneaux */
typedef int (*p_fib)(t_control *);

typedef struct s_window {
    int number;
    p_fib pfunc;
} t_window;

static const t_window l_bib[] = {
        {1, &introduction_central},
        {2, &ip_choice_central},
        {5, &prepa_game_central},
        {3, &central_game},
        {0, NULL}
};

#endif //BOMBERMAN_HEADERS_H
