//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

t_control *init_control()
{
    t_control *control;

    if ((control = (t_control*) malloc(sizeof (t_control))) == NULL)
        return NULL;
    if ((control->network = (t_network*) malloc(sizeof (t_network))) == NULL)
        return NULL;
    if ((control->sprites = (t_surface*) malloc(sizeof (t_surface))) == NULL)
        return NULL;
    control->main_renderer = NULL;
    control->fenetre = NULL;
    control->map = NULL;
    control->real_map = NULL;
    control->network ->id_client = 0;
    //control->network->ip_serveur = (char*) malloc(sizeof (char) * my_strlen("127.0.0.1"));
    control->network->ip_serveur = my_strdup("127.0.0.1");
    control->network->srv_or_clt = 1;
    control->mesg_en_bale = 0;
    control->menuselect = 0;
    control->msg = (t_clt_sd*) malloc(sizeof(t_clt_sd));

    return (control);
}

void delete_control(t_control *control)
{
    free(control->network);
    free(control->sprites);
    free(control->main_renderer);
    free(control->fenetre);
    free(control->map);
    free(control->real_map);
    free(control->network->ip_serveur);
    free(control->msg);
    free(control);
}

t_etat *init_etat(t_etat *etat)
{
    if ((etat = (t_etat*) malloc(sizeof (t_etat))) == NULL)
        return NULL;
    if ((etat->msg = (t_svr_sd*) malloc(sizeof (t_svr_sd))) == NULL)
        return NULL;

    etat->last_pions = NULL;
    etat->lastplayer = NULL;
    etat->pion = NULL;
    etat->players = NULL;
    etat->ip_adress = my_strdup("");
    //etat->ptime = 0;
    etat->sock_server = 0;
    etat->nbre_players = 0;
    etat->partie = 0;
    etat->set = 0;
    etat->winusers[0] = 0;
    etat->winusers[1] = 0;
    etat->winusers[2] = 0;
    etat->winusers[3] = 0;
    return (etat);
}
