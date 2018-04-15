//
// Created by marc on 01/03/18.
//

#include "headers.h"

void start_time(t_etat *etat) {
    time(&etat->tdepart);
}

int difference(t_etat *etat) {
    if (etat->tdepart > 0)// prend en compte quand la partie demarre
    {
        if (etat->tdepart <= time(NULL) && etat->nbreset > 0) {
            /* si partie en cours on fai tpartir le compteur */
            if (etat->partie == 1) {
                send_time(etat, etat->minutesgame);
                return (1);
            } else {
                return (2);
            }
        } else if (etat->tdepart <= time(NULL) && etat->nbreset <= 0) {
            etat->partie = 5;/* determine la fin */
            etat->etat_party_chrono = 0;
            return (2);
        }
    }
    return (0);
}

/* donne le temps de fin de set */
void send_time(t_etat *etat, int delaychrono) {
    /* prend le temps en seconde */
    time_t seconds;


    //delaychrono = 0;
    seconds = time(NULL);
    etat->tdepart = (seconds + ((delaychrono * 60))); // second = minute/60
    etat->etat_party_chrono = 1;
}