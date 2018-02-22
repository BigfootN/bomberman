#ifndef STRUCT_H
#define STRUCT_H

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
    char *ipserveur;
    // etat serveur ou client
    int srvorclt;
    // permet de connaitre quel user vous êtes
    int idClient;
    // enregistre la soccket de connexion avec le server pour pouvoir envoyer des données
    int socket_client;
} t_network;

// pour envoyer a chaque joueur leur etat

typedef struct s_Sendplayers {
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
} t_Sendplayers;

/* structure d'envoi reseau */
typedef struct s_svrSd {
    int idClient; /* TOUJOURS METTRE L'ID CLIENT */
    t_Sendplayers statePlayer; // pour le temps et les divers compteurs
    int pos[4];// 3 FIN PARTIE
    int mapDecor[20][20]; // map complete envoyée avec les numeros desprites a afficher
    int mapAction[20][20]; // map complete envoyée avec les numeros desprites a afficher
    int mapBM[20][20]; // map complete envoyée avec les numeros desprites a afficher
    int commandService; // permet de donner un ordre reseau arret attente etc...
    int reponse;
    // timer
    time_t departTime;
} t_svrSd;

/* structure d'envoi reseau */
typedef struct s_cltSd {
    int idClient;
    int requete_1;
    int requete_2;
    int commandService; // permet de donner un ordre reseau arret attente etc...
} t_cltSd;

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
    SDL_Surface *dresultat;
    t_coord *cresultat;
    SDL_Surface *dattente;
    TTF_Font *police; // la police du logiciel
    SDL_Color couleur;
} t_surface;

typedef struct s_control {
    // fenetre
    SDL_Window *fenetre;
    SDL_Renderer* Main_Renderer;
    // menu selectionnée
    int menuSelect;
    //// reseau
    t_network *network;
    ////// creation liste monstre et joueurs ////////////
    t_surface *sprites;
    //// carte
    int **realmap; /// emplacement reel des sprites sur la map
    int **map; /// emplacement recu depuis le server avec les numeros de chaque sprite a afficher
    // gestion ecriture adresse ip ou nom carte
    int writeLoop;
    // pour envoyer des messages
    int mesgenbale;
    t_cltSd *msg;
    // reception des messages
    t_svrSd *receiveMap;
    // l'emplacement du thread d'envoi de requete
    int etatsend;
} t_control;

#endif