#include "headers.h"
/*
 * initilaise la partie
 */

void *centralIA(void *tmp)
{
    t_etat *etat;
    pthread_detach(pthread_self());

    if ((etat = (t_etat*) malloc(sizeof (t_etat))) == NULL)
        return NULL;
    etat = initEtat(etat);
    gestionData(etat, "carte1.lvl");
    tcpthreadServer(etat);
    IALooop(etat);
    sendEndParty(etat);
    pthread_exit((void*) tmp);
}

/*
 * boucle de la IA
 */
int IALooop(t_etat *etat)
{
    int pause;

    pause = 1;
    while (pause)
    {
        SDL_Delay(100);
        checkRequetePlayer(etat);
        checkAllPions(etat);
        prepaBombMap(etat);
        checkCounter(etat);
        if (serializeMap(etat))
            CentralSend(etat);

        if (etat->partie == 2)
            pause = 0;
        SDL_Delay(100);
    }
    return (1);
}