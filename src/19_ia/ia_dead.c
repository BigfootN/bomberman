//
// Created by marc on 01/03/18.
//

#include "headers.h"


int check_pion_disable(t_etat *etat)
{
    t_pions *tmp;

    tmp = etat->pion;
    while (tmp != NULL)
    {
        if (tmp->active == 0)
            if(tmp->type <= 4)
            {
                if(tmp->type >= 27 && tmp->type <= 30)
                {

                }

               // tmp = delete_pion(tmp);
            }
        tmp = tmp->next;
    }
    return (1);
}