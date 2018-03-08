//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

void add_pion(t_etat *etat, int counter, int socket)
{
    //t_pions *tmp;
    //SDL_Rect mappos;
    t_player *lplayer;

    etat->flage_stop = 1;
    // on cree le joueur dans la liste des pions
    lplayer = add_item_player(etat);
    lplayer->active = 0;
    lplayer->socket_player = socket;
    /* done un id unique */
    lplayer->id_connexion = counter;
    /* on incremente le nbre de players*/
    etat->nbre_players++;
    /*mappos.x = 0;
    mappos.y = 0;
    tmp = addItemPions(etat, mappos);
    tmp->bomb = 5;
    tmp->life = 20;
    tmp->speed = 1;
    tmp->score = 0;
    tmp->active = 1;*/
    /* pour ne pas le cherche inutilement */
    // lplayer->player = tmp;
    /* lplayer->player->id = lplayer->id_connexion;
     lplayer->player->type = 1;
     lplayer->player->life = 20;
     prend le numero du joueur courant
     //initGamers(etat, lplayer->player);
     lplayer->player->active = 1;*/
    /* active le player */
    // provisoire
    lplayer->active = 5;
    etat->flage_stop = 0;
    /* ici on envoi un mail de confirmation avec son id */
    //sendRequeteForUniqPlayer(etat, lplayer->socket_player, 1, lplayer->id_connexion);
}

int check_first_record(t_etat *etat, int socket)
{
    t_player *player;
    // si debut car aucun joueur donc liste vide
    player = etat->players;
    if (player == NULL)
    {
        add_pion(etat, 1, socket);
        return (1);
    }
    return (0);
}

int reconnect_player(t_etat *etat, t_clt_sd *requete, int socket)
{
    t_player *player;
    // on verifie qu'il ne s'agit pas d'une déconnexion
    player = etat->players;
    while (player != NULL)
    {
        if (player->id_connexion == requete->idclient && requete->idclient != 0)
        {
            player->socket_player = socket;
            return (1);
        }
        player = player->next;
    }
    return (0);
}

// ajout du client lorsqu'il arrive

int *init_array_check_player()
{
    int *tab;
    int index;

    index = 0;
    if ((tab = (int*) malloc(sizeof (int) * 5)) == NULL)
        return NULL;
    while (index < 5)
    {
        tab[index] = 0;
        index++;
    }

    return (tab);
}

int add_client(t_etat *etat, t_clt_sd *requete, int socket)
{
    if (etat->nbre_players < 4)
    {
        t_player *player;
        int *tabl;
        int index;

        tabl = init_array_check_player();
        if (check_first_record(etat, socket))
            return (0);
        /* ici rupture le serveur n'as pas compris que le client est parti */
        if (reconnect_player(etat, requete, socket))
            return (0);

        // on selectionne les emplacements libre
        player = etat->players;
        while (player != NULL)
        {
            if (player->id_connexion <= 4 && player->id_connexion >= 1)
                tabl[player->id_connexion] = 1;
            player = player->next;
        }
        // on ajoute le player au premier  chiffre manquant
        player = etat->players;
        while (player != NULL)
        {
            index = 1;
            while (index < 5)
            {
                if (tabl[index] == 0)
                {
                    add_pion(etat, index, socket);
                    return (0);
                }
                index++;
            }
            player = player->next;
        }
        free(tabl);
    }
    return (0);
}
