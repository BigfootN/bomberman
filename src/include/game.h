#ifndef GAME_H
#define GAME_H

#include "types.h"

/* les events comme une bommbe qui va exploser ou explose */

/* structure des etats du jeux */
// structure map client
// structure pour le client
// GameCentral.c
/*int centralGame(t_control* control);
  void tcpthreadClient(t_control* control);
  void tcpthreadServer(void* tmp);

// gameLoop.c
void gameLoop(t_control* control, int* menuSelect);

// tcpserver.c
int addClient(t_etat* etat, t_cltSd* requete, int socket);
void* tcpClient(void* tmp);
void* server_receive_from_client(void* tmp);
void* server_to_client(void* tmp);
int sendRequeteForUniqPlayer(t_etat* etat, int socket, int action, int message);
void deletePlayerDeconnect(t_etat* etat, int sock);

// tcpclient.c
void* tcpServer(void* tmp);
//void *tcpServer(void *tmp);
void* client_send_to_server(void* tmp);
//int prepare_requete(t_control *control, int idclient, int action, int message);
int prepare_requetClient(t_control* control,
int idclient,
int commandService,
int requete_1,
int requete_2);

// gameServer.c
void centralServerGame(void* tmp);

// gameviews.c
void threadIA();
void buttonGame(t_control* control);
void initGamers(t_etat* etat, t_pions* player);
void displayScreenGame(t_control* control);
void displayScreenWait(t_control* control);
void gamereceive(t_control* control);
int receiveSignal(const int signal, void* ptr);
// gamepanel.c
void createPanelGame(t_control* control);
void createareaMap(t_control* control);
void createCompteur(t_control* control);
void DisplayMap(t_control* control, t_svrSd* requete);
void displayCounter(t_control* control, int minute1, int minute2, int seconde1, int seconde2);
void createPanelResult(t_control* control, t_svrSd* requete);
void writePanetScore(t_control* control, t_svrSd* requete);
void createareabonus(t_control* control);
void startGame(t_control* control);
// gameDisplay
void startGame(t_control* control);
// gameTime.c
void displayTime(t_control* control);
//

// file.c
int writeConfigMap(t_etat* etat, int* list);
int gestionData(t_etat* etat, char* name);
FILE* openFile(char* name);
void initiMap(t_etat* etat, FILE* fp);
void initsort(t_etat* etat);*/

#endif
