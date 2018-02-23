#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

struct player_s;
struct player_info_s;
struct piece_s;
struct server_s;
struct client_s;
struct clmap_s;
struct network_s;
struct surface_s;
struct input_s;

typedef struct player_s {
	// actif ou occupé
	int is_activ;
	// id de connexion
	int conn_id;
	// socket
	int sockfd_player;
	// requete
	int request_state;
	int requete_1;
	int requete_2;

	// liste double chainées
	struct player_s* next;
	struct player_s* prev;

	// emplacement dans la liste du joueur pour eviter de chercher
	struct s_pions* player;
} player_t;

typedef struct player_info_s {
	// time
	int ptime;
	// scores
	int score;
	// leur vie
	int life;
	// les divers sorts
	int spell;
	// le speed
	int speed;
	// le bonus
	int bomb;
} player_info_t;

typedef struct piece_s {
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
	char* clock_direction;
	// la vie
	int life;
	// vitesse deplacement pour connaitre si on doit le jouer ou non
	int speed;
	// degat bomb
	int degat;
	// emplacement dans la liste du joueur pour eviter de chercher
	struct player_s* elist;
	//
	int bomb;
	int score;
	// requete
	int etat_requete;
	int requete_1;
	int requete_2;
	// liste double chainées
	struct piece_s* next;
	struct piece_s* prev;
} piece_t;

/* structure d'envoi reseau */
typedef struct server_s {
	int idClient;
	struct player_info_s statePlayer;
	int pos[4];
	int map_scenery[20][20];
	int map_action[20][20];
	int map_bitmap[20][20];
	int cmd_service;
	int response;
	// timer
	time_t start_time;
} server_t;

typedef struct clmap_s {
	SDL_Rect nbreTiles;
	char* file_name;
	char* sprite_name;
	char* title;
	// map complete
	int** real_map;
	// map bonus malus
	int** penalty_bonus_map;
	// map deplacement
	int** action_map;
	const char* map_name;
	const char* tiles_name;
	SDL_Rect pos;
	SDL_Rect size;
	int* wall;
} clmap_t;

/* structure des etats du jeux */
typedef struct s_state {
	// flag qui bloque lors de la creation d'un user
	int flag_stop;
	// heure de demarrage
	time_t start_time;
	time_t cur_time;
	// socket serveur
	int sock_server;
	int sock_tmp;
	char* ip_addr;
	// chrono du jeux
	int ptime;
	// etat jeux
	int game_state;
	// listes des joueurs pour envoyer les données
	int nb_players;
	struct player_s* last_player;
	struct player_s* players;
	// les joueurs actifs
	int pactif[5];
	// listes des  joueurs et des monstres
	struct piece_s* piece;
	struct piece_s* last_piece;
	// pour la carte
	struct clmap_s* map_info;
	// structure message
	int socket_send;
	struct server_s* msg;
	// control la partie pour le depart et l'interuption
	int partie;
} state_t;

typedef struct s_control {
	// fenetre
	SDL_Window* fenetre;
	SDL_Renderer* Main_Renderer;
	// menu selectionnée
	int menuSelect;
	// reseau
	struct network_s* network;
	// creation liste monstre et joueurs
	struct surface_s* sprites;
	// carte
	int** realmap;
	/// emplacement reel des sprites sur la map
	int** map;
	// gestion ecriture adresse ip ou nom carte
	int writeLoop;
	// pour envoyer des messages
	int mesgenbale;
	struct client_s* msg;
	// reception des messages
	struct server_s* map_recv;
	// l'emplacement du thread d'envoi de requete
	int send_state;
} t_control;

typedef struct input_s {
	char key[SDL_NUM_SCANCODES];
	int mousex;
	int mousey;
	int mousexrel;
	int mouseyrel;
	char mousebuttons[8];
	char quit;
} input_t;

typedef struct coord_s {
	SDL_Rect img;
	int wall;
} coord_t;

typedef struct network_s {
	char* ipserveur;
	// etat serveur ou client
	int net_clt_srv_state;
	// permet de connaitre quel user vous êtes
	int client_id;
	// enregistre la soccket de connexion avec le server pour pouvoir envoyer des données
	int socket_client;
} network_t;

// pour envoyer a chaque joueur leur etat

/* structure d'envoi reseau */
typedef struct client_s {
	int idClient;
	int requete_1;
	int requete_2;
	int commandService;
} client_t;

typedef struct surface_s {
	struct coord_s* csprites;
	SDL_Surface* dsprites;
	struct coord_s* cmenu;
	SDL_Surface* dmenu;
	struct coord_s* cbandeau;
	SDL_Surface* dbandeau;
	struct coord_s* clogo;
	SDL_Surface* dlogo;
	struct coord_s* cattente;
	SDL_Surface* dresultat;
	struct coord_s* cresultat;
	SDL_Surface* dattente;
	TTF_Font* police;
	SDL_Color couleur;
} surface_s;

#endif