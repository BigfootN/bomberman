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
    if ((etat->msg->state_player = (t_send_players*)malloc(sizeof(t_send_players))) == NULL)
        return NULL;

    etat->flage_stop = 0;
    etat->tdepart = 0;
    etat->sock_server = 0;
    etat->sock_tmp = 0;
    etat->socket_send = 0;
    etat->last_pions = NULL;
    etat->lastplayer = NULL;
    etat->pion = NULL;
    etat->players = NULL;
    etat->ip_adress = my_strdup("");
    etat->sock_server = 0;
    etat->nbre_players = 0;
    etat->partie = 0;
    etat->set = 0;
    etat->winusers[0] = 0;
    etat->winusers[1] = 0;
    etat->winusers[2] = 0;
    etat->winusers[3] = 0;
    etat->msg->state_player->speed = 0;
    etat->msg->state_player->sort = 0;
    etat->msg->state_player->bomb = 0;
    etat->msg->state_player->life = 0;
    etat->msg->state_player->ptime = 0;
    etat->msg->state_player->score = 0;
    etat->msg->state_player->win = 0;
    etat->msg->idclient = 0;
    etat->msg->command_service = 0;
    etat->msg->reponse = 0;
    etat->msg->depart_time = 0;
    etat->msg->end_time = 0;
    etat->msg->set_start = 0;
    etat->msg->pos[0] = 0;
    etat->msg->pos[1]= 0;
    etat->msg->pos[2]= 0;
    etat->msg->pos[3]= 0;
    etat->msg->win_user[0] = 0;
    etat->msg->win_user[1] = 0;
    etat->msg->win_user[2] = 0;
    etat->msg->win_user[3] = 0;

    int indeRow = 0;
    int indCol = 0;

    while(indeRow < 20) {
        indCol = 0;
        while (indCol < 20) {
            etat->msg->map_action[indeRow][indCol] = 0;
            etat->msg->map_old[indeRow][indCol] = 0;
            etat->msg->map_decor[indeRow][indCol] = 0;
            etat->msg->map_bm[indeRow][indCol] = 0;
            indCol++;
        }
        indeRow++;
    }

    return (etat);
}
