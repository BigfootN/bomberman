//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int check_pions(t_pions *list)
{
    if (list == NULL)
        return 1;
    else
        return 0;
}

t_pions *add_item_pions(t_etat *etat, SDL_Rect mappos)
{
    t_pions *tmp;
    if ((tmp = (t_pions*) malloc(sizeof (t_pions))) == NULL)
        return (NULL);
    tmp->id = 0;
    tmp->active = 0;
    tmp->mappos.x = 0;
    tmp->mappos.y = 0;
    tmp->mappos.w = 0;
    tmp->mappos.h = 0;
    tmp->mappos = mappos;
    tmp->life = 0;
    tmp->bomb = 5;
    tmp->life = 5;
    tmp->speed = 0;
    tmp->score = 0;
    tmp->proprio = 0;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (etat->last_pions == NULL && etat->pion == NULL)
    {
        etat->last_pions = tmp;
        etat->pion = tmp;
    }
    else if (etat->last_pions != NULL)
    {
        etat->last_pions->next = tmp;
        tmp->prev = etat->last_pions;
        etat->last_pions = tmp;
    }
    return (tmp);
}
// mettre un & pour la list quand sollicité

t_pions *read_unit_pions(t_pions *list, int *tab)
{
    if (list != NULL)
    {
        tab[0] = list->id;
        tab[2] = list->life;
        list = list->next;
    }
    return (list);
}

t_pions *delete_list_chevron(t_pions *tmp)
{
    if (tmp == NULL)
        return (NULL);
    if (tmp->next == NULL && tmp->prev != NULL)
        tmp->prev->next = NULL;
        //  else if (tmp->next == NULL && tmp->prev == NULL)
        //    free(tmp);
    else if (tmp->next != NULL && tmp->prev != NULL)
    {
        if( tmp->prev->next != NULL)
            tmp->prev->next = tmp->next;
        if( tmp->next->prev != NULL)
            tmp->next->prev = tmp->prev;
    }
    if (tmp->prev != NULL)
        return (tmp->prev->next);
    else
        return (NULL);
}

t_player *add_item_player(t_etat *etat)
{
    t_player *tmp;

    if ((tmp = (t_player*) malloc(sizeof (t_player))) == NULL)
        return (NULL);
    tmp->id_connexion = 0;
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->active = 1;
    if (etat->lastplayer == NULL && etat->players == NULL)
    {
        etat->players = tmp;
        etat->lastplayer = tmp;
    }
    else if (etat->lastplayer != NULL)
    {
        etat->lastplayer->next = tmp;
        tmp->prev = etat->lastplayer;
        etat->lastplayer = tmp;
    }
    return (tmp);
}

t_player *delete_list_player(t_player *tmp)
{
    if (tmp == NULL)
        return (NULL);
    if (tmp->next == NULL && tmp->prev != NULL)
        tmp->prev->next = NULL;
        //  else if (tmp->next == NULL && tmp->prev == NULL)
        //    free(tmp);
    else if (tmp->next != NULL && tmp->prev != NULL)
    {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    if (tmp->prev != NULL)
        return (tmp->prev->next);
    else
        return (NULL);
}