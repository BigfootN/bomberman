//
// Created by marc on 05/04/18.
//

#ifndef BOMBERMAN_GAMES_H
#define BOMBERMAN_GAMES_H

long chrono_set;

/* prend en compte la carte */
typedef struct s_clmap {
    SDL_Rect nbreTiles;
    char *namefile; // la carte
    char *namesprite; // les sprites
    char *title; // titre de la carte
    // map complete
    int **realmap; // le decor
    int **map_old; // le decor
    int **map_user_castdown; // a qui appartient les bombes ou autres joyeusetés déposées
    int **bmmap; // les bonus malus et monstres en attente
    // map deplacement
    int **mapaction; // les deplacements des players zombies et explosions
    const char *Mapname; // le nom de la map
    const char *tilesname; // le nom des sprites
    SDL_Rect pos;
    int *wall;
} t_clmap;

/* profil des divers pions du jeux, joueurs, monstres bonus malus bombe */
typedef struct s_pions {
    /* si joueur */
    // id de connexion si joueur
    int id_connexion;
    // socket si joueur
    int socket_player;
    // si bombe a qui elle appartient pour donner les points si tue un joueur ou monstre
    int proprio;
    // vivant ou mort
    int active;
    // type pour connaitre le type de pion joueurs, monstres bonus malus, bombe
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
    int winner;
    // requete
    int etat_requete;
    int requete_1;
    int requete_2;
    // liste double chainées
    struct s_pions *next;
    struct s_pions *prev;
} t_pions;

/* structure des etats du jeux */
typedef struct s_etat {
    // detrmine si client ou server pour les commandes
    int master;
    // flag qui bloque lors de la creation d'un user
    int flage_stop;
    // heure de demarrage
    time_t tdepart;
    // socket serveur
#if defined WIN32 || defined WIN64
    SOCKET sock_server; // adresse socket du client coté serveur
    SOCKET sock_tmp; // adresse socket du client coté serveur
#elif defined __linux__
    int sock_server; // adresse socket du client coté serveur
    int sock_tmp; // adresse socket du client coté serveur
#endif
    //int sock_server; // adresse socket du client coté serveur
    //int sock_tmp; // adresse socket du client coté serveur
    char *ip_adress; // adresse du server
    // listes des joueurs pour envoyer les données
    int nbre_players;
    // les joueurs actifs
    int pactif[5]; // A REVOIR
    // les quatre compteurs
    int winusers[5];
    // listes des  joueurs et des monstres
    int nbre_pions;
    t_pions *pion; // premier emplacement
    t_pions *last_pions; // liste
    // pour la carte
    t_clmap *data_map;
    // structure message
    int socket_send;
    t_svr_sd *msg;
    // control la partie pour le depart et l'interuption
    int partie;
    // set en crours
    int set;
    int etat_party_chrono;
    // ecriture des paramettre du jeux
    int nbreset;
    int minutesgame;
    //envoi message
    int send_message;
} t_etat;


#endif //BOMBERMAN_GAMES_H
