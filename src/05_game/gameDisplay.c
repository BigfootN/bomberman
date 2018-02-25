#include "headers.h"

int receiveSignal(const int signal, void *ptr)
{
    static t_control *control = NULL;

    my_putstr("client transmets\n");
    if (control == NULL)
        control = ptr;
    my_putstr("init control\n");
    printf("signal %d \n", signal);
    if (signal == SIGNALWHATEVER)
        ckeckAnswerSrv(control);

    return (0);
}

void ckeckAnswerSrv(t_control *control)
{
    server_t *requete;

    if (control->mesg_enbale == 1)
    {
        requete = control->map_recv;
        if (requete->cmd_service == 1)
        {
            displayScreenGame(control);
            control->network->client_id = requete->client_id;
        }
        if (requete->cmd_service == 3)
            control->send_state = 0;
        else if (requete->cmd_service == 5)
        {
            control->network->client_id = requete->client_id;
            displayScreenGame(control);
            DisplayMap(control, requete);
            displayTime(control);
            if (requete->pos[2] != 0 || requete->pos[3] != 0)
                createPanelResult(control, requete);
            writePanetScore(control, requete);
        }
        control->mesg_enbale = 0;
    }
    SDL_Delay(5);
}

void startGame(t_control *control)
{
    SDL_Rect dest = {350,
        (WINDOW_HEIGHT - 62),
        control->sprites->menu_coord[4].img.w,
        control->sprites->menu_coord[4].img.h};

    displayBackgroundButton(control, dest);
    SDL_RenderPresent(control->main_renderer);
    prepare_requetClient(control, control->network->client_id, 11, 11, 0);
}