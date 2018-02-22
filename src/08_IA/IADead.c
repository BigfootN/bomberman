#include "headers.h"

int checkPionDisable(t_etat *etat)
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
                
                 tmp = deleteListChevron(tmp);
            }
         tmp = tmp->next;
    }
    return (1);
}