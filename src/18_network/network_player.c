//
// Created by marc on 01/03/18.
//

#include "headers.h"

void add_pion(t_etat *etat, int counter, int socket) {
    t_pions *pion;
    SDL_Rect mappos = {0};

    etat->flage_stop = 1;
    // on cree le joueur dans la liste des pions
    pion = add_pions(etat, mappos);
    pion->active = 0;
    pion->socket_player = socket;
    /* done un id unique */
    pion->id_connexion = counter;
    pion->id = counter;
    /* on incremente le nbre de players*/
    etat->nbre_players++;

   // init_pion(pion);
    pion->speed = 0;
    pion->type = 1;
    pion->life = 20;
    pion->bomb = 5;
    init_gamers(etat, pion);
    pion->active = 1;
    etat->flage_stop = 0;
    send_requete_for_uniq_player(etat, pion->socket_player, 1, pion->id_connexion);
}

int check_first_record(t_etat *etat, int socket) {
    t_pions *pion;
    // si debut car aucun joueur donc liste vide
    pion = etat->pion;
    if (pion == NULL) {
        add_pion(etat, 1, socket);
        return (1);
    }
    return (0);
}

int reconnect_player(t_etat *etat, t_clt_sd *requete, int socket) {
    t_pions *pion;
    // on verifie qu'il ne s'agit pas d'une déconnexion
    pion = etat->pion;
    while (pion != NULL) {
        if (pion->id_connexion <= 4) {
            if (pion->id_connexion == requete->idclient && requete->idclient != 0) {
                pion->socket_player = socket;
                return (1);
            }
        }
        pion = pion->next;
    }
    return (0);
}

/*
 * ajout du client lorsqu'il arrive
 */

int *init_array_check_player() {
    int *tab;
    int index;

    index = 0;
    if ((tab = (int *) malloc(sizeof(int) * 5)) == NULL)
        return NULL;
    while (index < 5) {
        tab[index] = 0;
        index++;
    }

    return (tab);
}

int add_client(t_etat *etat, t_clt_sd *requete, int socket) {
    if (etat->nbre_players < 4) {
        t_pions *pion;
        int *tabl;
        int index;

        tabl = init_array_check_player();
        if (check_first_record(etat, socket))
            return (0);
        /* ici rupture le serveur n'as pas compris que le client est parti */
        if (reconnect_player(etat, requete, socket))
            return (0);

        // on selectionne les emplacements libre
        pion = etat->pion;
        while (pion != NULL) {
            if (pion->id_connexion <= 4)
                tabl[pion->id_connexion] = 1;
            pion = pion->next;
        }
        // on ajoute le player au premier  chiffre manquant
        pion = etat->pion;
        while (pion != NULL) {
            index = 1;
            while (index < 5) {
                if (tabl[index] == 0) {
                    add_pion(etat, index, socket);
                    return (0);
                }
                index++;
            }
            pion = pion->next;
        }
        free(tabl);
    }
    return (-1);
}
