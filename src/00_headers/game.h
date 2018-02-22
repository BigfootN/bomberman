#ifndef GAME_H
#define GAME_H

#include "struct.h"

/* les events comme une bommbe qui va exploser ou explose */
typedef struct s_events {
	// time
	int ptime;
	// type evement
	int typeevent;
	// vie evenement compteur decroissant
	int evlife;
} t_events;

// liste interne pour trouver rapidement les joueurs

typedef struct s_players {
	// actif ou occupé
	int active;
	// id de connexion
	int id_connexion;
	// socket
	int socket_player;
	// requete
	int etat_requete;
	int requete_1;
	int requete_2;
	// liste double chainées
	struct s_players* next;
	struct s_players* prev;
	// emplacement dans la liste du joueur pour eviter de chercher
	struct s_pions* player;
} t_player;

// tout les acteurs sur la carte, player, monstres, bonusmalus

typedef struct s_pions {
	// player give
	int proprio;
	// actif ou occupé
	int active;
	// type pour connaitre le type d epions dan sle jeux
	int type;
	// id
	int id;
	// Emplacement reel
	SDL_Rect realpos;
	// Emplacement carte
	SDL_Rect mappos;
	// sens pour les monstres
	char* sens;
	// la vie
	int life;
	// vitesse deplacement pour connaitre si on doit le jouer ou non
	int speed;
	// degat bomb
	int degat;
	// emplacement dans la liste du joueur pour eviter de chercher
	t_player* elist;
	//
	int bomb;
	int score;
	// requete
	int etat_requete;
	int requete_1;
	int requete_2;
	// liste double chainées
	struct s_pions* next;
	struct s_pions* prev;
} t_pions;

typedef struct s_clmap {
	SDL_Rect nbreTiles;
	char* namefile;	// la carte
	char* namesprite;	// les sprites
	char* title;// titre de la carte
	// map complete
	int** realmap;	// le decor
	// map bonus malus
	int** bmmap;// les bonus malus et monstres en attente
	// map deplacement
	int** mapaction;// les deplacements des players zombies et explosions
	const char* Mapname;// le nom de la map
	const char* tilesname;	// le nom des sprites
	SDL_Rect pos;
	SDL_Rect taille;
	int* wall;
} t_clmap;

/* structure des etats du jeux */
typedef struct s_etat {
	// flag qui bloque lors de la creation d'un user
	int flageStop;
	// heure de demarrage
	time_t tdepart;
	time_t tcourant;
	// socket serveur
	int sock_server;// adresse socket du client coté serveur
	int sock_tmp;	// adresse socket du client coté serveur
	char* ipAdress;	// adresse du server
	// chrono du jeux
	int ptime;
	// etat jeux
	int etat_jeux;
	// listes des joueurs pour envoyer les données
	int nbrePlayers;
	t_player* lastplayer;	// premier emplacement
	t_player* players;	// une liste
	// les joueurs actifs
	int pactif[5];
	// listes des  joueurs et des monstres
	t_pions* pion;	// premier emplacement
	t_pions* lastpions;	// liste
	// pour la carte
	t_clmap* dataMap;
	// structure message
	int socket_send;
	t_svrSd* msg;
	// control la partie pour le depart et l'interuption
	int partie;
	// timer
	time_t departTime;
} t_etat;

// structure map client
typedef struct s_point {
	SDL_Rect pos;
	int nSprite;
} t_point;

// structure pour le client
typedef struct s_etat_clt {
	// map d'affichage calcul des emplacements
	t_point** realmap;
	// map de reception
	int** nitMap;
} t_etat_clt;

// GameCentral.c
int centralGame(t_control* control);
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
void initsort(t_etat* etat);

#endif