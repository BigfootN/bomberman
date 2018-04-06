//
// Created by marc on 01/03/18.
//

#include "bomberman.h"


int check_pion_disable(t_etat *etat)
{
    t_pions *tmp;

    tmp = etat->pion;
    while (tmp != NULL)
    {
        if (tmp->active == 0)
            if(tmp->type > 26 && tmp->type < 23)
            {
                if(tmp->type >= 27 && tmp->type <= 30)
                {

                }

                tmp = delete_list_chevron(tmp);
            }
        tmp = tmp->next;
    }
    return (1);
}