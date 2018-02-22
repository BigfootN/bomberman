#include "headers.h"

int ipChoiceCentral(t_control* control)
{
    control->writeLoop = 0;
    int menuSelect = 1;
    window_init(control);
    createPanel(control);
    createPanelWhite(control);
    createBanderole(control);
    // creation etiquette
    createEtiquettes(control);
    encartClair(control);
    buttonActionChoicePartie(control);
    SDL_RenderPresent(control->Main_Renderer);

    eventsLoopipchoice(control, &menuSelect);
    SDL_DestroyRenderer(control->Main_Renderer);

    return (menuSelect);
}

void buttonActionChoicePartie(t_control* control)
{
     SDL_Rect dest = {150,
        (WINDOW_HEIGHT - 62),
        control->sprites->cmenu[4].img.w,
        control->sprites->cmenu[4].img.h};
    displayButton(control, dest);
    dest.x = 350;
    displayButton(control, dest);
    dest.x = 550;
    displayButton(control, dest);
    
    SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, my_strlen("Return") * 18, 50};
    writeText_51(control, renderQuad, "Return");
    renderQuad.x = 360;
    renderQuad.w = my_strlen("Select") * 18;
    writeText_51(control, renderQuad, "Select");
    renderQuad.x = 570;
    renderQuad.w = my_strlen("Close") * 18;
    writeText_51(control, renderQuad, "Close");
}