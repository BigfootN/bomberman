//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

int receive_signal(const int signal, void *ptr)
{
    static t_control *control = NULL;

    my_putstr("client transmets\n");
    if (control == NULL)
        control = ptr;
    my_putstr("init control\n");
    printf("signal %d \n", signal);
    if (signal == SIGNALWHATEVER)
        ckeck_answer_srv(control);

    return (0);
}

void ckeck_answer_srv(t_control *control)
{
    t_svr_sd *requete;

    if (control->mesg_en_bale == 1)
    {
        requete = control->receive_map;
        if (requete->command_service == 1)
        {
            display_screen_game(control);
            control->network->id_client = requete->idclient;
        }
        if (requete->command_service == 3)
            control->etat_send = 0;
        else if (requete->command_service == 5)
        {
            control->network->id_client = requete->idclient;
            display_screen_game(control);
            display_map(control, requete);
            display_time(control);
            if (requete->pos[2] != 0 || requete->pos[3] != 0)
                create_panel_result(control, requete);
            write_panet_score(control, requete);
        }
        control->mesg_en_bale = 0;
    }
    SDL_Delay(5);
}

void start_game(t_control *control)
{
    SDL_Rect dest = {350,
                     (WINDOW_HEIGHT - 62),
                     control->sprites->cmenu[4].img.w,
                     control->sprites->cmenu[4].img.h};

    display_background_button(control, dest);
    SDL_RenderPresent(control->main_renderer);
    prepare_requet_client(control, control->network->id_client, 11, 11, 0);
}