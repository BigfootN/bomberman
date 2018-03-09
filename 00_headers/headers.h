#ifndef HEADERS_H
#define HEADERS_H

// SDL2
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
// annexe
#include <dirent.h>	// share file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string.h>
#include <strings.h>

/*#if defined (WIN32)
   //pour les sockets
 #include <winsock2.h>
   typedef int socklen_t;
   //pour les threads
 #include <windows.h>
 #define psleep(sec) Sleep ((sec) * 1000)

 #elif defined (linux)*/
// annexe
#include <time.h>
#include <unistd.h>
// network
#include <arpa/inet.h>
#include <endian.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>//for threading , link with lpthread
#include <signal.h>
#include <stdint.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
/*#endif*/

// headers
#include "annexe.h"
#include "define.h"
#include "game.h"
#include "IA.h"
#include "struct.h"

//noyeau.c
void window_init(t_control* control);
void createPanelWhite(t_control* control);
void createPanel(t_control* control);
void createBanderole(t_control* control);
int dblClick(int CurrentClickTicks, int LastClickTicks);
void displayButton(t_control* control, SDL_Rect posdest);
void writeString(t_control* control, SDL_Rect renderQuad, char* string);
void writeText_51(t_control* control, SDL_Rect renderQuad, char* string);
void createPanelWait(t_control* control);
void displayBackgroundButton(t_control* control, SDL_Rect posdest);
void encartClair(t_control* control);

// initSprites.c
int centralInitSprites(t_control* control);
char* initchar(char* str);
int initSprites(t_control* control);
int initMenu(t_control* control);
int initBandeau(t_control* control);
int initIntro(t_control* control);
int initPolice(t_control* control);
int initAttente(t_control* control);
int initPanneauResultat(t_control* control);

//inits.c
t_control* init_control();
t_etat* initEtat(t_etat* etat);
void killProcess(int pid);

// introviews.c
int introductionCentral(t_control* control);
//introloop
int eventsLoopIntroduction(t_control* control, int* menuSelect);

void SpritePanelIntroduction(t_control* control);

// choicepviews.c
int ipChoiceCentral(t_control* control);
void buttonActionChoicePartie(t_control* control);
void writeText(t_control* control);
// choiceipwindow
char* deleteData(t_control* control, SDL_Event event);
void createEtiquettes(t_control* control);
// choiceiploop
void eventsLoopipchoice(t_control* control, int* menuSelect);

// scrviews.c
int scoresCentral(t_control* control);
void buttonMenuScores(t_control* control);

// listechainée.c
int checkPions(t_pions* list);
t_pions* addItemPions(t_etat* etat, SDL_Rect mappos);
t_pions* readUnitPions(t_pions* list, int* tab);
t_pions* deleteListChevron(t_pions* tmp);
t_player* addItemPlayer(t_etat* etat);
t_player* deleteListPlayer(t_player* tmp);

// gameDisplay.c
void ckeckAnswerSrv(t_control* control);

// addNetworkPlayer.c
void addPion(t_etat* etat, int counter, int socket);
int checkFirstRecord(t_etat* etat, int socket);
int ReconnectPlayer(t_etat* etat, t_cltSd* requete, int socket);
int addClient(t_etat* etat, t_cltSd* requete, int socket);

typedef int (* p_fib)(t_control*);

typedef struct s_window {
	int number;
	p_fib pfunc;
} t_window;

static const t_window l_bib[] = {
	{1, &introductionCentral},
	{2, &ipChoiceCentral},
	{3, &centralGame},
	{4, &scoresCentral},
	{0, NULL}
};

#endif
