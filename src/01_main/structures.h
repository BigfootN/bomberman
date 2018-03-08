//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_STRUCTURES_H
#define BOMBERMAN_STRUCTURES_H

#include "define.h"
#include <time.h>

// les events du deplacement

typedef struct {
	char key[SDL_NUM_SCANCODES];
	int mousex, mousey;
	int mousexrel, mouseyrel;
	char mousebuttons[8];
	char quit;
} Input;

typedef struct s_coord {
	SDL_Rect img;	// x y w h image
	int wall;
} t_coord;

typedef struct s_network {
	char* ip_serveur;
	// etat serveur ou client
	int srv_or_clt;
	// permet de connaitre quel user vous êtes
	int id_client;
	// enregistre la soccket de connexion avec le server pour pouvoir envoyer des données
	int socket_client;
} t_network;

// pour envoyer a chaque joueur leur etat

typedef struct s_send_players {
	// time
	int ptime;
	// scores
	int score;
	// leur vie
	int life;
	// les divers sorts
	int sort;
	// le speed
	int speed;
	// le bonus
	int bomb;
} t_send_players;

/* structure d'envoi reseau */
typedef struct s_svr_sd {
	int idclient;	/* TOUJOURS METTRE L'ID CLIENT */
	t_send_players state_player;// pour le temps et les divers compteurs
	int pos[4];	// 3 FIN PARTIE
	int map_decor[20][20];	// map complete envoyée avec les numeros desprites a afficher
	int map_action[20][20];	// map complete envoyée avec les numeros desprites a afficher
	int map_bm[20][20];	// map complete envoyée avec les numeros desprites a afficher
	int command_service;// permet de donner un ordre reseau arret attente etc...
	int reponse;
	// timer
	time_t depart_time;	// temps réel de l'application
} t_svr_sd;

/* structure d'envoi reseau */
typedef struct s_clt_sd {
	int idclient;
	int requete_1;
	int requete_2;
	int commandservice;	// permet de donner un ordre reseau arret attente etc...
} t_clt_sd;

typedef struct s_surface {
	t_coord* csprites;	// contient les emplacements des images du jeux dans leur fichier
	SDL_Surface* dsprites;	// contient les images du jeux
	t_coord* cmenu;
	SDL_Surface* dmenu;	// contient les images du menu
	t_coord* cbandeau;
	SDL_Surface* dbandeau;
	t_coord* clogo;
	SDL_Surface* dlogo;
	t_coord* cattente;
	SDL_Surface* dresultat;
	t_coord* cresultat;
	SDL_Surface* dattente;
	TTF_Font* police;	// la police du logiciel
	SDL_Color couleur;
} t_surface;

typedef struct s_control {
	// fenetre
	SDL_Window* fenetre;
	SDL_Renderer* main_renderer;
	// menu selectionnée
	int menuselect;
	//// reseau
	t_network* network;
	////// creation liste monstre et joueurs ////////////
	t_surface* sprites;
	//// carte
	int** real_map;	/// emplacement reel des sprites sur la map
	int** map;	/// emplacement recu depuis le server avec les numeros de chaque sprite a afficher
	// gestion ecriture adresse ip ou nom carte
	int write_loop;
	// pour envoyer des messages
	int mesg_en_bale;
	t_clt_sd* msg;
	// reception des messages
	t_svr_sd* receive_map;
	// l'emplacement du thread d'envoi de requete
	int etat_send;
} t_control;

#endif	//BOMBERMAN_STRUCTURES_H
