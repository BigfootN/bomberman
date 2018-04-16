//
// Created by marc on 05/04/18.
//

#include "headers.h"

t_control *reinit_control(t_control *control)
{
    int indeRow = 0;
    int indCol = 0;

    control->srv_or_clt = 1;
    control->mesg_en_bale = 0;
    control->menuselect = 0;
    control->write_loop = 0;
    control->etat_send = 0;
    control->nbreset = 1; // nbre de set dans la partie
    control->minutesgame = 1; // durée d'un set nombre de minutes
    control->write_set = 0;
    control->write_time = 0;

    control->msg->requete_2 = 0;
    control->msg->requete_1 = 0;
    control->msg->commandservice = 0;
    control->msg->idclient = 0;
    control->msg->idclient = 0;
    control->msg->set = 0;

    control->receive_map->idclient = 0;
    control->receive_map->etat_party_chrono = 0;
    control->receive_map->command_service = 0;
    control->receive_map->depart_time = 0;
    control->receive_map->depart_time = 0;
    control->receive_map->end_time = 0;

    indCol = 0;
    while (indCol < 4) {
        control->receive_map->pos[indCol] = 0;
        indCol++;
    }

    indeRow = 0;
    while (indeRow < 20) {
        indCol = 0;
        while (indCol < 20) {
            control->receive_map->map_action[indeRow][indCol] = 0;
            control->receive_map->map_old[indeRow][indCol] = 0;
            control->receive_map->map_decor[indeRow][indCol] = 0;
            control->receive_map->map_bm[indeRow][indCol] = 0;
            control->map_action_old[indeRow][indCol] = 0;
            control->map_area_old[indeRow][indCol] = 0;
            control->map_bm_old[indeRow][indCol] = 0;
            indCol++;
        }
        indeRow++;
    }

    control->receive_map->reponse = 0;
    control->receive_map->set_start = 0;

    indCol = 0;
    while (indCol < 8) {
        control->receive_map->stat_user[indCol] = 0;
        indCol++;
    }
}


t_control *init_control() {
    t_control *control;
    int index;

    if ((control = (t_control *) malloc(sizeof(t_control))) == NULL)
        return NULL;
    if ((control->sprites = (t_surface *) malloc(sizeof(t_surface))) == NULL)
        return NULL;
    if ((control->receive_map = (t_svr_sd *) malloc(sizeof(t_svr_sd))) == NULL)
        return NULL;
    if ((control->ip_serveur = (char *) malloc(sizeof(char) * 17)) == NULL)
        return NULL;
    my_bzero(control->ip_serveur, 17);
    control->main_renderer = NULL;
    control->fenetre = NULL;
    control->map = NULL;
    control->real_map = NULL;
    control->id_client = 0;
    strcpy(control->ip_serveur, "127.0.0.1");
    control->srv_or_clt = 1;
    control->mesg_en_bale = 0;
    control->menuselect = 0;
    control->write_loop = 0;
    control->etat_send = 0;
    control->nbreset = 1; // nbre de set dans la partie
    control->minutesgame = 1; // durée d'un set nombre de minutes
    control->write_set = 0;
    control->write_time = 0;

    if ((control->msg = (t_clt_sd *) malloc(sizeof(t_clt_sd))) == NULL)
        return NULL;

    control->msg->requete_2 = 0;
    control->msg->requete_1 = 0;
    control->msg->commandservice = 0;
    control->msg->idclient = 0;
    control->msg->idclient = 0;
    control->msg->set = 0;

    control->receive_map->idclient = 0;
    control->receive_map->etat_party_chrono = 0;
    control->receive_map->command_service = 0;
    control->receive_map->depart_time = 0;
    control->receive_map->depart_time = 0;
    control->receive_map->end_time = 0;

    index = 0;
    while (index < 4) {
        control->receive_map->pos[index] = 0;
        index++;
    }

    int indeRow = 0;
    int indCol = 0;

    while (indeRow < 20) {
        indCol = 0;
        while (indCol < 20) {
            control->receive_map->map_action[indeRow][indCol] = 0;
            control->receive_map->map_old[indeRow][indCol] = 0;
            control->receive_map->map_decor[indeRow][indCol] = 0;
            control->receive_map->map_bm[indeRow][indCol] = 0;
            control->map_action_old[indeRow][indCol] = 0;
            control->map_area_old[indeRow][indCol] = 0;
            control->map_bm_old[indeRow][indCol] = 0;
            indCol++;
        }
        indeRow++;
    }

    control->receive_map->reponse = 0;
    control->receive_map->set_start = 0;

    indCol = 0;
    while (indCol < 8) {
        control->receive_map->stat_user[indCol] = 0;
        indCol++;
    }

    return (control);
}

void delete_control(t_control *control) {
    free(control->ip_serveur);
    free(control->receive_map);
    free(control->msg);
    free(control->sprites);
    free(control);
}

t_etat *init_etat() {
    t_etat *etat;
    int indrow;
    int indcol;

    if ((etat = (t_etat *) malloc(sizeof(t_etat))) == NULL)
        return NULL;
    if ((etat->msg = (t_svr_sd *) malloc(sizeof(t_svr_sd))) == NULL)
        return NULL;
    if ((etat->data_map = (t_clmap *) malloc(sizeof(t_clmap))) == NULL)
        return NULL;

    etat->master = 0;
    etat->flage_stop = 0;
    etat->tdepart = 0;
    etat->sock_server = 0;
    etat->sock_tmp = 0;
    etat->socket_send = 0;
    etat->last_pions = NULL;
    etat->pion = NULL;
    etat->ip_adress = my_strdup("");
    etat->sock_server = 0;
    etat->nbre_players = 0;
    etat->partie = 0;
    etat->set = 0;
    indrow = 0;
    while (indrow < 8) {
        etat->msg->stat_user[indrow] = 0;
        indrow++;
    }
    etat->msg->idclient = 0;
    etat->msg->command_service = 0;
    etat->msg->reponse = 0;
    etat->msg->depart_time = 0;
    etat->msg->end_time = 0;
    etat->msg->set_start = 0;
    indrow = 0;
    while (indrow < 4) {
        etat->winusers[indrow] = 0;
        etat->msg->pos[indrow] = 0;
        etat->msg->win_user[indrow] = 0;
        indrow++;
    }
    etat->msg->etat_party_chrono = 0;
    etat->nbre_pions = 5;

    indrow = 0;
    while (indrow < 20) {
        indcol = 0;
        while (indcol < 20) {
            etat->msg->map_action[indrow][indcol] = 0;
            etat->msg->map_old[indrow][indcol] = 0;
            etat->msg->map_decor[indrow][indcol] = 0;
            etat->msg->map_bm[indrow][indcol] = 0;
            indcol++;
        }
        indrow++;
    }

    etat->etat_party_chrono = 0;
    etat->nbreset = 0;
    etat->minutesgame = 0;
    etat->send_message = 1;

    return (etat);
}

void delete_etat(t_etat *etat) {

    int indexX;

    indexX = 0;

    free(etat->msg);
    free(etat->ip_adress);

    free(etat->data_map->namefile);
    free(etat->data_map->namesprite);
    free(etat->data_map->title);

    while (indexX < etat->data_map->pos.x) {
        free(etat->data_map->map_user_castdown[indexX]); //15
        free(etat->data_map->realmap[indexX]); //15
        free(etat->data_map->mapaction[indexX]);
        free(etat->data_map->map_old[indexX]);
        indexX++;
    }
    indexX = 0;
    while (indexX < etat->data_map->pos.x) {
        free(etat->data_map->bmmap[indexX]);
        indexX++;
    }

    free(etat->data_map->bmmap);
    free(etat->data_map->map_user_castdown);
    free(etat->data_map->realmap);
    free(etat->data_map->mapaction);
    free(etat->data_map->map_old);
    free(etat->data_map->wall);
    free(etat->data_map);

    free(etat);
}
