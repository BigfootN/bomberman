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
    t_svrSd *requete;

    if (control->mesgenbale == 1)
    {
        requete = control->receiveMap;
        if (requete->commandService == 1)
        {
            displayScreenGame(control);
            control->network->idClient = requete->idClient;
        }
        if (requete->commandService == 3)
            control->etatsend = 0;
        else if (requete->commandService == 5)
        {
            control->network->idClient = requete->idClient;
            displayScreenGame(control);
            DisplayMap(control, requete);
            displayTime(control);
            if (requete->pos[2] != 0 || requete->pos[3] != 0)
                createPanelResult(control, requete);
            writePanetScore(control, requete);
        }
        control->mesgenbale = 0;
    }
    SDL_Delay(5);
}

void startGame(t_control *control)
{
    SDL_Rect dest = {350,
        (WINDOW_HEIGHT - 62),
        control->sprites->cmenu[4].img.w,
        control->sprites->cmenu[4].img.h};

    displayBackgroundButton(control, dest);
    SDL_RenderPresent(control->Main_Renderer);
    prepare_requetClient(control, control->network->idClient, 11, 11, 0);
}