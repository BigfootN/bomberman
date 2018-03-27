//
// Created by marc on 01/03/18.
//

#ifndef BOMBERMAN_GAME_H
#define BOMBERMAN_GAME_H

long chrono_set;

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
    struct s_players *next;
    struct s_players *prev;
    // emplacement dans la liste du joueur pour eviter de chercher
    struct s_pions *player;
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
    // fin de partie
    int win;
    int bomb;
    int score;
    // requete
    int etat_requete;
    int requete_1;
    int requete_2;
    // liste double chainées
    struct s_pions *next;
    struct s_pions *prev;
} t_pions;

typedef struct s_clmap {
    SDL_Rect nbreTiles;
    char *namefile; // la carte
    char *namesprite; // les sprites
    char *title; // titre de la carte
    // map complete
    int **realmap; // le decor
    int **map_old; // le decor
    int **map_user_castdown; // a qui appartient la bomb ou autres joyeusetés déposées
    // map bonus malus
    int **bmmap; // les bonus malus et monstres en attente
    // map deplacement
    int **mapaction; // les deplacements des players zombies et explosions
    const char *Mapname; // le nom de la map
    const char *tilesname; // le nom des sprites
    SDL_Rect pos;
    //SDL_Rect taille;
    int *wall;
} t_clmap;

/* structure des etats du jeux */
typedef struct s_etat {
    // flag qui bloque lors de la creation d'un user
    int flage_stop;
    // heure de demarrage
    time_t tdepart;
    //time_t tcourant;
#if defined WIN32 || defined WIN64
    SOCKET sock_server; // adresse socket du client coté serveur
#elif defined __linux__
    int sock_server; // adresse socket du client coté serveur
#endif
    int sock_tmp; // adresse socket du client coté serveur
    char *ip_adress; // adresse du server
    // chrono du jeux
    //int ptime;
    // etat jeux
    //int etat_jeux;
    // listes des joueurs pour envoyer les données
    int nbre_players;
    t_player *lastplayer; // premier emplacement
    t_player *players; // une liste
    // les joueurs actifs
    int pactif[5];
    // les quatre compteurs
    int winusers[5];
    // listes des  joueurs et des monstres
    t_pions *pion; // premier emplacement
    t_pions *last_pions; // liste
    // pour la carte
    t_clmap *data_map;
    // structure message
    int socket_send;
    t_svr_sd *msg;
    // control la partie pour le depart et l'interuption
    int partie;
    // timer
    //time_t depart_time;
    // set en crours
    int set;
} t_etat;

// structure map client
typedef struct s_point {
    SDL_Rect pos;
    int nSprite;
} t_point;

// structure pour le client
typedef struct s_etat_clt {
    // map d'affichage calcul des emplacements
    t_point **realmap;
    // map de reception
    int **nitMap;
} t_etat_clt;



#endif //BOMBERMAN_GAME_H
