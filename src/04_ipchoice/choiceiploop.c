//
// Created by marc on 01/03/18.
//

#include "headers.h"

int choice_menu_choice_ip(t_control *control, SDL_Event event) {
    if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) &&
        event.button.button == SDL_BUTTON_LEFT) {
        if (event.motion.x >= 150 && event.motion.x <= 300)
            return 1;
        else if (event.motion.x >= 350 && event.motion.x <= 500) {
            control->srv_or_clt = 0;
            return 3;
        } else if (event.motion.x >= 550 && event.motion.x <= 700)
            return 0;
    }

    /* ici les encart du nom et de l'adresse server IP 200, 298 */
    if (event.motion.x >= 200 && event.motion.x <= 600) {
        if (event.motion.y >= 300 && event.motion.y <= 350) {
            if (control->write_loop == 0)
                control->write_loop = 1;
            else
                control->write_loop = 0;

            if (control->write_loop == 1)
                encart_white(control);
        }
    }
    return -1;
}

void select_data(t_control *control, char *data) {
    char *tmp;
    int size;

    size = ((int) my_strlen(control->ip_serveur) + (int) my_strlen(data) + 1);
    tmp = (char *) malloc(sizeof(char) * size);
    my_bzero(tmp, (size_t) size);

    if (my_choice_number(*data) && (size >= 0 && size <= 16)) {
        my_strcat(tmp, control->ip_serveur);
        //realloc_ip_serveur(control);
        my_bzero(control->ip_serveur, my_strlen(control->ip_serveur));
        my_strcat(tmp, data);
        my_strcat(control->ip_serveur ,tmp);
        encart_white(control);
    }
    free(tmp);
}

void events_loop_ip_choice(t_control *control, int *menu_select) {
    Input in;
    SDL_Event event;
    SDL_StartTextInput();
    int current_click_ticks = 0, last_click_ticks = 0;
    memset(&in, 0, sizeof(in)); // Instanciation d'une structure Input, et initialisation : tous les champs à 0.
    while (!in.key[SDLK_ESCAPE] && !in.quit) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                in.quit = 1;
            case SDL_MOUSEMOTION:
                in.mousex = event.motion.x;
                in.mousey = event.motion.y;
                in.mousexrel = event.motion.xrel;
                in.mouseyrel = event.motion.yrel;
                break;
            case SDL_TEXTINPUT:
                if (control->write_loop == 1)
                    select_data(control, event.text.text);
                break;
            case SDL_KEYDOWN:
                if (control->write_loop == 1)
                    delete_data(control, event);
                //    selectData(control, event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                last_click_ticks = dbl_click(current_click_ticks, last_click_ticks);
                if (last_click_ticks == 1) {
                    if (event.button.button == SDL_BUTTON_LEFT)
                        if ((*menu_select = choice_menu_choice_ip(control, event)) != -1)
                            return;
                }
        }
    }
    SDL_StopTextInput();
}
