//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_STRUCTURES_H
#define BOMBERMAN_STRUCTURES_H

// gestion thread ia et reception serveur_client
pthread_cond_t cv;
pthread_mutex_t lock;

pthread_cond_t cv_user;
pthread_mutex_t lock_user;

// les events du deplacement
typedef struct {
    char key[SDL_NUM_SCANCODES];
    int mousex, mousey;
    int mousexrel, mouseyrel;
    char mousebuttons[8];
    char quit;
} Input;

typedef struct s_coord {
    SDL_Rect img; // x y w h image
    int wall;
} t_coord;

typedef struct s_network {
    char *ip_serveur;
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
    // fin de partie
    int win;
} t_send_players;

/* structure d'envoi reseau */
typedef struct s_svr_sd {
    int idclient; /* TOUJOURS METTRE L'ID CLIENT */
    t_send_players state_player; // pour le temps et les divers compteurs
    int pos[4];// 3 FIN PARTIE
    int win_user[5];
    int map_old[20][20]; // map complete envoyée avec les numeros desprites a afficher
    int map_decor[20][20]; // map complete envoyée avec les numeros desprites a afficher
    int map_action[20][20]; // map complete envoyée avec les numeros desprites a afficher
    int map_bm[20][20]; // map complete envoyée avec les numeros desprites a afficher
    int command_service; // permet de donner un ordre reseau arret attente etc...
    int reponse;
    // timer
    time_t depart_time; // donne le temps max du set (temps réel de l'application OBSOLETE)
    time_t end_time; // l'heure de fin de partie avec le temps impartie intégré exemple 15h00 + 00h05 = 15h05 fin de partie important pour la synchro
    int set_start; // depart du set de la partie, déclenche chez les joueurs le timer
} t_svr_sd;

/* structure d'envoi reseau */
typedef struct s_clt_sd {
    int idclient;
    int requete_1;
    int requete_2;
    int set; // le set en cours
    int commandservice; // permet de donner un ordre reseau arret attente etc...
} t_clt_sd;

typedef struct s_surface {
    t_coord *csprites; // contient les emplacements des images du jeux dans leur fichier
    SDL_Surface *dsprites; // contient les images du jeux
    t_coord *cmenu;
    SDL_Surface *dmenu; // contient les images du menu
    t_coord *cbandeau;
    SDL_Surface *dbandeau;
    t_coord *clogo;
    SDL_Surface *dlogo;
    t_coord *cattente;
    t_coord *cwaitset;
    SDL_Surface *dresultat;
    t_coord *cresultat;
    SDL_Surface *dattente;
    SDL_Surface *dwaitset;
    TTF_Font *police; // la police du logiciel
    SDL_Color couleur;
} t_surface;

typedef struct s_control {
    // fenetre
    SDL_Window *fenetre;
    SDL_Renderer *main_renderer;
    // menu selectionnée
    int menuselect;
    //// reseau
    t_network *network;
    ////// creation liste monstre et joueurs ////////////
    t_surface *sprites;
    //// carte
    int **real_map; /// emplacement reel des sprites sur la map
    int **map; /// emplacement recu depuis le server avec les numeros de chaque sprite a afficher
    int map_area_old[20][20];
    int map_bm_old[20][20];
    int map_action_old[20][20];
    // gestion ecriture adresse ip ou nom carte
    int write_loop;
    // pour envoyer des messages
    int mesg_en_bale;
    t_clt_sd *msg;
    // reception des messages
    t_svr_sd *receive_map;
    // l'emplacement du thread d'envoi de requete
    int etat_send;
} t_control;

#endif //BOMBERMAN_STRUCTURES_H
