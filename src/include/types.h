#ifndef STRUCT_H
#define STRUCT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

// les events du deplacement

typedef struct {
	char key[SDL_NUM_SCANCODES];
	int mousex;
	int mousey;
	int mousexrel;
	int mouseyrel;
	char mousebuttons[8];
	char quit;
} Input;

typedef struct s_coord {
	SDL_Rect img;
	int wall;
} t_coord;

typedef struct s_network {
	char* ipserveur;
	// etat serveur ou client
	int srvorclt;
	// permet de connaitre quel user vous êtes
	int idClient;
	// enregistre la soccket de connexion avec le server pour pouvoir envoyer des données
	int socket_client;
} t_network;

// pour envoyer a chaque joueur leur etat

/* structure d'envoi reseau */
typedef struct s_cltSd {
	int idClient;
	int requete_1;
	int requete_2;
	int commandService;
} t_cltSd;

typedef struct s_surface {
	t_coord* csprites;
	SDL_Surface* dsprites;
	t_coord* cmenu;
	SDL_Surface* dmenu;
	t_coord* cbandeau;
	SDL_Surface* dbandeau;
	t_coord* clogo;
	SDL_Surface* dlogo;
	t_coord* cattente;
	SDL_Surface* dresultat;
	t_coord* cresultat;
	SDL_Surface* dattente;
	TTF_Font* police;
	SDL_Color couleur;
} t_surface;

typedef struct s_control {
	// fenetre
	SDL_Window* fenetre;
	SDL_Renderer* Main_Renderer;
	// menu selectionnée
	int menuSelect;
	// reseau
	t_network* network;
	// creation liste monstre et joueurs
	t_surface* sprites;
	// carte
	int** realmap;
	/// emplacement reel des sprites sur la map
	int** map;
	// gestion ecriture adresse ip ou nom carte
	int writeLoop;
	// pour envoyer des messages
	int mesgenbale;
	t_cltSd* msg;
	// reception des messages
	t_svrSd* receiveMap;
	// l'emplacement du thread d'envoi de requete
	int etatsend;
} t_control;

#endif
