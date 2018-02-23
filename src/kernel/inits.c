#include "headers.h"

t_control *init_control()
{
    t_control *control;

    if ((control = (t_control*) malloc(sizeof (t_control))) == NULL)
        return NULL;
    /* parametres reseaux */
    if ((control->network = (t_network*) malloc(sizeof (t_network))) == NULL)
        return NULL;
    // contient les emplacements des images du jeux dans leur fichier
    if ((control->sprites = (t_surface*) malloc(sizeof (t_surface))) == NULL)
        return NULL;

    control->Main_Renderer = NULL;
    control->fenetre = NULL;
    control->map = NULL;
    control->realmap = NULL;
    control->network ->idClient = 0;
    control->network->ipserveur = (char*) malloc(sizeof (char) * my_strlen("127.0.0.1"));
    control->network->ipserveur = "127.0.0.1";
    control->network->srvorclt = 1; // serveur par default
    control->mesgenbale = 0; // pour les receptions de paquet
    control->menuSelect = 0; // pour le smenus
    control->msg = (t_cltSd*) malloc(sizeof (t_cltSd));

    return (control);
}

t_etat *initEtat(t_etat *etat)
{
    if ((etat = (t_etat*) malloc(sizeof (t_etat))) == NULL)
        return NULL;

    etat->lastpions = NULL;
    etat->lastplayer = NULL;
    etat->pion = NULL;
    etat->players = NULL;
    etat->ipAdress = my_strdup("");
    etat->ptime = 0;
    etat->sock_server = 0;
    etat->nbrePlayers = 0;
    etat->partie = 0;
    etat->msg = (t_svrSd*) malloc(sizeof (t_svrSd));
    //etat->msg->statePlayer = (t_Sendplayers*) malloc(sizeof (t_Sendplayers));

    return (etat);
}

/*void killProcess(int pid)
{
    int result;
    int status;

    printf("hello");

    while ((result = waitpid(-1, &status, WNOHANG)) > 0)
    {
        ;
    }
    if (result == -1)
    {
        perror("waitpid");
        exit(1);
    }
}*/