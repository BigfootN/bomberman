#ifndef STRUCT_H
#define STRUCT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
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
struct point_s;
struct client_state_s;
struct window_s;
struct control_s;

typedef struct player_s {
	// actif ou occupé
	int is_activ;
	// id de connexion
	int conn_id;
	// socket
	int sockfd_player;
	// requete
	int request_state;
	int request_1;
	int request_2;

	// liste double chainées
	struct player_s* next;
	struct player_s* prev;

	// emplacement dans la liste du joueur pour eviter de chercher
	struct piece_s* player;
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
	int is_activ;
	// type pour connaitre le type d epions dan sle jeux
	int type;
	// id
	int id;
	// Emplacement reel
	SDL_Rect real_pos;
	// Emplacement carte
	SDL_Rect map_pos;
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
	int request_state;
	int request_1;
	int request_2;
	// liste double chainées
	struct piece_s* next;
	struct piece_s* prev;
} piece_t;

/* structure d'envoi reseau */
typedef struct server_s {
	int client_id;
	struct player_info_s player_state;
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
typedef struct state_s {
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
	int game_time;
	// etat jeux
	int game_state;
	// listes des joueurs pour envoyer les données
	int nb_players;
	struct player_s* last_player;
	struct player_s* players;
	// les joueurs actifs
	int active_players[5];
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

typedef struct control_s {
	// fenetre
	SDL_Window* win;
	SDL_Renderer* main_renderer;
	// menu selectionnée
	int menu_select;
	// reseau
	struct network_s* network;
	// creation liste monstre et joueurs
	struct surface_s* sprites;
	// carte
	int** real_map;
	/// emplacement reel des sprites sur la map
	int** map;
	// gestion ecriture adresse ip ou nom carte
	int write_loop;
	// pour envoyer des messages
	int msg_enable;
	struct client_s* msg;
	// reception des messages
	struct server_s* map_recv;
	// l'emplacement du thread d'envoi de requete
	int send_state;
} control_t;

typedef struct input_s {
	char key[SDL_NUM_SCANCODES];
	int mouse_x;
	int mouse_y;
	int mouse_xrel;
	int mouse_yrel;
	char mouse_buttons[8];
	char quit;
} input_t;

typedef struct coord_s {
	SDL_Rect img;
	int wall;
} coord_t;

typedef struct network_s {
	char* server_addr;
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
	int client_id;
	int request_1;
	int request_2;
	int cmd_service;
} client_t;

typedef struct surface_s {
	struct coord_s* sprite_coord;
	SDL_Surface* sprite_surf;

	struct coord_s* menu_coord;
	SDL_Surface* menu_surf;

	struct coord_s* banner_coord;
	SDL_Surface* banner_surf;

	struct coord_s* logo_coord;
	SDL_Surface* logo_surf;

	struct coord_s* wait_coord;
	SDL_Surface* res_surf;

	struct coord_s* res_coord;
	SDL_Surface* wait_surf;

	TTF_Font* font;
	SDL_Color color;
} surface_t;


typedef struct event_s {
	// time
	int ptime;
	// type evement
	int typeevent;
	// vie evenement compteur decroissant
	int evlife;
} event_t;

typedef struct point_s {
	SDL_Rect pos;
	int nSprite;
} point_t;

typedef struct client_state_s {
	// map d'affichage calcul des emplacements
	struct point_s** realmap;
	// map de reception
	int** nitMap;
} client_state_t;

typedef int (* p_fib)(control_t*);

typedef struct window_s {
	int number;
	p_fib pfunc;
} window_t;


/*int intro_central(control_t*);
  int ip_choice_central(control_t*);
  int central_game(control_t*);
  int scores_central(control_t*);
  */
/*static const window_t l_bib[] = {
  {1, &intro_central},
  {2, &ip_choice_central},
  {3, &central_game},
  {4, &scores_central},
  {0, NULL}
  };**/

#endif
