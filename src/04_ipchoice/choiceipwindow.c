//
// Created by marc on 01/03/18.
//

#include "headers.h"

void create_etiquettes(t_control *control) {
    SDL_Rect render_quad = {200, 200, 385, 60};
    write_string(control, render_quad, "adresse ip serveur");
}

int my_choice_number(int c) {
    if ((c >= 48 && c <= 57) || (c == 46))
        return (1);
    return (0);
}

void delete_data(t_control *control, SDL_Event event) {
    int index;
    char *tmp;
    tmp = (char *) malloc(sizeof(char) * 16);
    my_bzero(tmp, 16);
    my_strcat(tmp, control->ip_serveur);
    index = (int) my_strlen(tmp);

    if ((event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) && index) {
        index -= 1;
        tmp[index] = '\0';
        my_bzero(control->ip_serveur, my_strlen(control->ip_serveur));
        my_strcat(control->ip_serveur ,tmp);
    }
    encart_white(control);
    free(tmp);
}

char *write_data(char *data, char *tmp) {
//    char *lettre;
    int total;
//
    total = (int) my_strlen(data);
//    lettre = (char*) malloc(sizeof (char) * total);
//    lettre = data;

    if (my_choice_number(*data) && (total >= 0 && total < 15)) {
        my_strcat(tmp, data);
//        lettre = lettre + '\0';
//        tmp[total] = *lettre;
//        total += 1;
    }
//    tmp[total] = '\0';
    return (tmp);
}
