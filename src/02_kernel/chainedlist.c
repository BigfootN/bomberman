//
// Created by marc on 05/04/18.
//

#include "headers.h"

void init_pion(t_pions *pion) {
    /* joueur */
    //  pion->id_connexion = 0;
    //  pion->socket_player = 0;
    /* object jeux BM Monstre bomb etc... */
    pion->proprio = 0;
    pion->active = 0;
    pion->type = 0;
    //  pion->id = 0;
    pion->mappos.y = 0;
    pion->mappos.x = 0;
    pion->mappos.h = 0;
    pion->mappos.w = 0;
    pion->sens = 0;
    pion->life = 0;
    pion->speed = 0;
    pion->degat = 0;
    // pion->win = 0; ne touche pas car ensuite on fait le total avec les autres joueurs
    /*  si joueur */
    pion->bomb = 0;
    pion->score = 0;
    /* requete si joueur */
    pion->etat_requete = 0;
    pion->requete_1 = 0;
    pion->requete_2 = 0;
}

void change_id_pion(t_pions *pion, int id_user) {
    pion->id = id_user;
}
/* creation pion doit bloquer la réception de commande de direction lors d'une création */
t_pions *add_pions(t_etat *etat, SDL_Rect mappos) {
    t_pions *tmp;

    if ((tmp = (t_pions *) malloc(sizeof(t_pions))) == NULL)
        return (NULL);

    /* joueur */
    tmp->id_connexion = 0;
    tmp->socket_player = 0;
    /* object jeux BM Monstre bomb etc... */
    tmp->proprio = 0;
    tmp->active = 0;
    tmp->type = 0;
    tmp->id = 0;
    tmp->mappos.x = mappos.x;
    tmp->mappos.y = mappos.y;
    tmp->mappos.w = mappos.w;
    tmp->mappos.h = mappos.h;
    tmp->sens = 0;
    tmp->life = 0;
    tmp->speed = 0;
    tmp->degat = 0;
    tmp->win = 0;
    tmp->winner = 0;
    /*  si joueur */
    tmp->bomb = 0;
    tmp->score = 1;
    /* requete si joueur */
    tmp->etat_requete = 0;
    tmp->requete_1 = 0;
    tmp->requete_2 = 0;
    /* initialise à zero */
    tmp->next = NULL;
    tmp->prev = NULL;

    if (etat->last_pions == NULL && etat->pion == NULL) {
        etat->last_pions = tmp;
        etat->pion = tmp;
    } else if (etat->last_pions != NULL) {
        etat->last_pions->next = tmp;
        tmp->prev = etat->last_pions;
        etat->last_pions = tmp;
    }
    return (tmp);
}

void delete_pion(t_etat *etat, t_pions *pion) {

    t_pions *tmp;
    /* si pas de pion on ressort*/
    if (pion == NULL)
        return;
    /* si le pion est le dernier pion */
    if (pion->next == NULL && pion->prev == NULL) {
        etat->last_pions = NULL;
        etat->pion = NULL;
        free(pion);
    }
        /* si le pion est entre deux pions */
    else if (pion->next != NULL && pion->prev != NULL) {
        tmp = pion->next;/* prend l'adresse du pion suivant */
        tmp->prev = pion->prev; /* mets le pion précedent à la place du pion a enlever */

        tmp = pion->prev;/* prend l'adresse du pion précedent */
        tmp->next = pion->next; /* mets le pion suivant  à la place du pion a enlever */
        free(pion);
    }
        /* si le pion est à la fin */
    else if (pion->next == NULL && pion->prev != NULL) {
        tmp = pion->prev;/* prend l'adresse du pion précedent */
        tmp->next = NULL; /* enleve le pion */
        etat->last_pions = tmp; /* indique le dernier pion */
        free(pion);
        /* si l epion est au debut */
    } else if (pion->next != NULL && pion->prev == NULL) {
        tmp = pion->next;/* prend l'adresse du pion suivant */
        tmp->prev = NULL; /* supprime le pion du précedent */
        etat->pion = tmp; /* met le pion comme premier */
        free(pion);
    }
}

/* détruit toute la liste des données en partant par le début */
void delete_list_pions(t_etat *etat) {
    t_pions *tmp;
    t_pions *sauv;

    tmp = etat->pion;
    while (tmp != NULL) {
        sauv = tmp;
        tmp = tmp->next;
        delete_pion(etat, sauv);
    }
}

/* détruit tout les pions qui ne sont pas des joueurs */
void clean_players(t_etat *etat) {
    t_pions *tmp;
    t_pions *sauv;

    tmp = etat->last_pions;
    while (tmp != NULL) {
        sauv = tmp;
        tmp = tmp->prev;
        if (sauv->id_connexion < 23 || sauv->id_connexion > 26)
            delete_pion(etat, sauv);
        else /* réinitialise le joueur en gardant le score de victoire*/
            init_pion(sauv);
    }
}

/* détruit un pions spécifique */
void delete_one_pion(t_etat *etat, int idpion) {
    t_pions *tmp;
    t_pions *sauv;

    tmp = etat->pion;
    while (tmp != NULL) {
        sauv = tmp;
        tmp = tmp->next;
        if (sauv->id == idpion) {
            delete_pion(etat, sauv);
        }
    }
}

/*
 * vérifie qu'il exist un joueur au moins
 */
int player_exist(t_etat *etat) {

    t_pions *tmp;

    tmp = etat->pion;
    if (tmp != NULL && etat->nbre_players > 0) {
            if (tmp->id_connexion <= 4)
                return (1);
    }
    return (0);
}