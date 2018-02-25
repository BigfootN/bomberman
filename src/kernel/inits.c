#include "headers.h"

t_control *init_control()
{
    t_control *control;

    if ((control = (t_control*) malloc(sizeof (t_control))) == NULL)
        return NULL;
    /* parametres reseaux */
    if ((control->network = (network_t*) malloc(sizeof (network_t))) == NULL)
        return NULL;
    // contient les emplacements des images du jeux dans leur fichier
    if ((control->sprites = (surface_t*) malloc(sizeof (surface_t))) == NULL)
        return NULL;

    control->main_renderer = NULL;
    control->win = NULL;
    control->map = NULL;
    control->real_map = NULL;
    control->network->client_id = 0;
    control->network->sever_addr = (char*) malloc(sizeof (char) * my_strlen("127.0.0.1"));
    control->network->sever_addr = "127.0.0.1";
    control->network->net_clt_srv_state = 1; // serveur par default
    control->mesg_enbale = 0; // pour les receptions de paquet
    control->menu_select = 0; // pour le smenus
    control->msg = (client_t*) malloc(sizeof (client_t));

    return (control);
}

state_t *initEtat(state_t *state)
{
    if ((state = (state_t*) malloc(sizeof (state_t))) == NULL)
        return NULL;

    state->last_piece = NULL;
    state->last_player = NULL;
    state->piece = NULL;
    state->players = NULL;
    state->ip_addr = my_strdup("");
    state->game_time = 0;
    state->sock_server = 0;
    state->nb_players = 0;
    state->partie = 0;
    state->msg = (server_t*) malloc(sizeof (server_t));
    //state->msg->player_state = (t_Sendplayers*) malloc(sizeof (t_Sendplayers));

    return (state);
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