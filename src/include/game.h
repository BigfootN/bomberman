#ifndef GAME_H
#define GAME_H

#include "types.h"

/* les events comme une bommbe qui va exploser ou explose */
typedef struct s_events {
	// time
	int game_time;
	// type evement
	int typeevent;
	// vie evenement compteur decroissant
	int evlife;
} t_events;

// tout les acteurs sur la carte, player, monstres, bonusmalus


// structure map client
typedef struct s_point {
	SDL_Rect pos;
	int nSprite;
} t_point;

// structure pour le client
typedef struct s_state_clt {
	// map d'affichage calcul des emplacements
	t_point** real_map;
	// map de reception
	int** nitMap;
} state_t_clt;

// GameCentral.c
int centralGame(t_control* control);
void tcpthreadClient(t_control* control);
void tcpthreadServer(void* tmp);

// gameLoop.c
void gameLoop(t_control* control, int* menuSelect);

// tcpserver.c
int addClient(state_t* state, client_t* requete, int socket);
void* tcpClient(void* tmp);
void* server_receive_from_client(void* tmp);
void* server_to_client(void* tmp);
int sendRequeteForUniqPlayer(state_t* state, int socket, int action, int message);
void deletePlayerDeconnect(state_t* state, int sock);

// tcpclient.c
void* tcpServer(void* tmp);
//void *tcpServer(void *tmp);
void* client_send_to_server(void* tmp);
//int prepare_requete(t_control *control, int client_id, int action, int message);
int prepare_requetClient(t_control* control,
						 int client_id,
						 int cmd_service,
						 int request_1,
						 int request_2);

// gameServer.c
void centralServerGame(void* tmp);

// gameviews.c
void threadIA();
void buttonGame(t_control* control);
void init_gamers(state_t* state, piece_t* player);
void displayScreenGame(t_control* control);
void displayScreenWait(t_control* control);
void gamereceive(t_control* control);
int receiveSignal(const int signal, void* ptr);
// gamepanel.c
void createPanelGame(t_control* control);
void createareaMap(t_control* control);
void createCompteur(t_control* control);
void DisplayMap(t_control* control, server_t* requete);
void displayCounter(t_control* control, int minute1, int minute2, int seconde1, int seconde2);
void createPanelResult(t_control* control, server_t* requete);
void writePanetScore(t_control* control, server_t* requete);
void createareabonus(t_control* control);
void startGame(t_control* control);
// gameDisplay
void startGame(t_control* control);
// gameTime.c
void displayTime(t_control* control);
//

// file.c
int writeConfigMap(state_t* state, int* list);
int gestionData(state_t* state, char* name);
FILE* openFile(char* name);
void initiMap(state_t* state, FILE* fp);
void initsort(state_t* state);

#endif
