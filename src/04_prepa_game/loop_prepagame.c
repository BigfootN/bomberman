//
// Created by marc on 08/04/18.
//

#include "headers.h"

int choice_prepa_game(t_control *control, SDL_Event event) {
    if (event.motion.y >= (WINDOW_HEIGHT - 64) && event.motion.y <= (WINDOW_HEIGHT - 4) &&
        event.button.button == SDL_BUTTON_LEFT) {
        if (event.motion.x >= 150 && event.motion.x <= 300) {
            return 1;
        } else if (event.motion.x >= 350 && event.motion.x <= 500) {
            control->srv_or_clt = 1;
            return 3;
        }else if (event.motion.x >= 550 && event.motion.x <= 700)
            return 0;
    }

    /* les encart pour ecrire les minutes */
    if (event.motion.x >= 621 && event.motion.x <= 671) {
        if (event.motion.y >= 200 && event.motion.y <= 250) {

            if (control->write_time == 0) {
                control->write_time = 1;
                control->write_set = 0;/* désactive l'autre car seulement un en action */
            } else
                control->write_time = 0;

            encart_color_for_write(control);
        }

        if (event.motion.y >= 250 && event.motion.y <= 300) {
            if (control->write_set == 0) {
                control->write_set = 1;
                control->write_time = 0;
            } else
                control->write_set = 0;

            encart_color_for_write(control);
        }
    }
    return (-1);
}

int events_loop_prepa_game(t_control *control, int *menu_select) {

    Input in;
    SDL_Event event;
    int CurrentClickTicks = 0;
    int LastClickTicks = 0;

    memset(&in, 0, sizeof(in));
    memset(&event, 0, sizeof(event));

    while (!in.key[SDLK_ESCAPE] && !in.quit) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                in.quit = 1;
                break;
            case SDL_MOUSEMOTION:
                in.mousex = event.motion.x;
                in.mousey = event.motion.y;
                in.mousexrel = event.motion.xrel;
                in.mouseyrel = event.motion.yrel;
                break;
            case SDL_TEXTINPUT:
                if (control->write_set == 1 || control->write_time == 1)
                    select_number(control, event.text.text);
                break;
            case SDL_KEYDOWN:
                if (control->write_set == 1 || control->write_time == 1)
                    delete_number(control, event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                LastClickTicks = dbl_click(CurrentClickTicks, LastClickTicks);
                if (LastClickTicks == 1) {
                    if ((*menu_select = choice_prepa_game(control, event)) != -1) {
                        in.mousex = 0;
                        in.mousexrel = 0;
                        in.mousey = 0;
                        in.mouseyrel = 0;
                        in.quit = 0;
                        return (*menu_select);
                    }
                }
                break;
            default:
                break;
        }

    }
    return (*menu_select);
}