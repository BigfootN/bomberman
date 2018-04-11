//
// Created by marc on 09/04/18.
//

#include "headers.h"

int my_convert_number(int c) {
    if ((c >= 48 && c <= 57))
        return (c - 48);
    return (-1);
}

void create_panel_aide_prepa_game(t_control *control) {
    SDL_Rect position;
    position.w = 500;
    position.h = 180;
    position.x = 180;
    position.y = 370;

    SDL_Texture *ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dprepagame);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->cprepagame->img), &position);
    SDL_DestroyTexture(ptexture);
    SDL_RenderPresent(control->main_renderer);

}

void create_requete_prepa_game(t_control *control) {
    SDL_Rect render_quad = {120, 200, 500, 60};
    write_string(control, render_quad, "combien de minutes pour une manche : ");
    SDL_Rect render_quad2 = {320, 255, 300, 60};
    write_string(control, render_quad2, "combien de manche : ");
}

void encart_write_minutes(t_control *control) {
    SDL_Rect position;
    position.w = 50;
    position.h = 50;
    position.x = 621;
    position.y = 200;
    if (control->write_time == 0)
        SDL_SetRenderDrawColor(control->main_renderer, 236, 236, 186, 255);
    else if (control->write_time == 1)
        SDL_SetRenderDrawColor(control->main_renderer, 210, 210, 150, 255);
    SDL_RenderFillRect(control->main_renderer, &position);
    write_game_set(control, 1);
    SDL_RenderPresent(control->main_renderer);
}


void encart_write_manches(t_control *control) {
    SDL_Rect position;
    position.w = 50;
    position.h = 50;
    position.x = 621;
    position.y = 255;
    if (control->write_set == 0)
        SDL_SetRenderDrawColor(control->main_renderer, 236, 236, 186, 255);
    else if (control->write_set == 1)
        SDL_SetRenderDrawColor(control->main_renderer, 210, 210, 150, 255);
    SDL_RenderFillRect(control->main_renderer, &position);
    write_game_set(control, 2);
    SDL_RenderPresent(control->main_renderer);
}

void delete_number(t_control *control, SDL_Event event) {

    if ((event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)) {
        if (control->write_set == 1) {
            control->nbreset = 1;
            write_game_set(control, 1);
        }
        if (control->write_time == 1) {
            control->minutesgame = 1;
            write_game_set(control, 2);
        }
        SDL_RenderPresent(control->main_renderer);
    }
}

void select_number(t_control *control, char *number) {

    int dataint;

    dataint = atoi(number);

    if (dataint > 0 && dataint < 6) {
        if (control->write_set == 1) {
            control->nbreset = dataint;
          //  write_game_set(control, 2);
        }
        if (control->write_time == 1) {
            control->minutesgame = dataint;
           // write_game_set(control, 1);
        }
        encart_color_for_write(control);
        SDL_RenderPresent(control->main_renderer);
    }
}

/* ecrit le nbre de manche et les mintues pour les celle-ci */
void write_game_set(t_control *control, int flag) {
    char *string;

    string = (char *) malloc(sizeof(char) * 4);
    if (flag == 1) {
        sprintf(string, "%3d", control->minutesgame);
        SDL_Rect render_quad = {620, 200, (int) my_strlen(string) * 15, 60};
        write_string(control, render_quad, string);
    } else if (flag == 2) {
        sprintf(string, "%3d", control->nbreset);
        SDL_Rect render_quad = {620, 250, (int) my_strlen(string) * 15, 60};
        write_string(control, render_quad, string);
    }
    free(string);
}

void encart_color_for_write(t_control *control) {
    SDL_Rect position;


        position.w = 50;
        position.h = 50;
        position.x = 621;
        position.y = 200;

        if (control->write_time == 0)
            SDL_SetRenderDrawColor(control->main_renderer, 236, 236, 186, 255);
        else if (control->write_time == 1)
            SDL_SetRenderDrawColor(control->main_renderer, 210, 210, 150, 255);
        SDL_RenderFillRect(control->main_renderer, &position);
        write_game_set(control, 1);

        position.w = 50;
        position.h = 50;
        position.x = 621;
        position.y = 255;

        if (control->write_set == 0)
            SDL_SetRenderDrawColor(control->main_renderer, 236, 236, 186, 255);
        else if (control->write_set == 1)
            SDL_SetRenderDrawColor(control->main_renderer, 210, 210, 150, 255);
        SDL_RenderFillRect(control->main_renderer, &position);
        write_game_set(control, 2);

    SDL_RenderPresent(control->main_renderer);
}
