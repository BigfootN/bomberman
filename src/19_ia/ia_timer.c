//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

void start_time(t_etat *etat) {
    time(&etat->tdepart);
}

int difference(t_etat *etat) {
    if ((etat->tdepart) > 0)// prend en compte quand la partie demarre
    {
        if(etat->tdepart <= time(NULL) && set_party > 0)
        {
            set_party--;
            etat->partie = STEP; /* determine les maches */
            send_time(etat, STEPTIME);
            return (1);
        }
       else if(etat->tdepart <= time(NULL) && set_party == 0) {
            etat->partie = 5;/* determine la fin */
            return (2);
        }
    }
    return (0);
}

/* donne le temps de fin de set */
void send_time(t_etat *etat, int delaychrono) {
    /* prend le temps en seconde */
    time_t seconds;

    delaychrono = 0;
    seconds = time(NULL);
    etat->tdepart = (seconds + ((delaychrono * 60) + 15)); // second = minute/60
}