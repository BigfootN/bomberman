//
// Created by marc on 01/03/18.
//

#include "headers.h"

void ckeck_answer_srv(t_control *control) {
//int ckeck_answer_srv(t_control *control) {
    t_svr_sd *requete;

    if (control->mesg_en_bale == 1) {
        requete = control->receive_map;
        if (requete->command_service == 1) { /* insertion des données id et affiche ecran */
            display_screen_game(control);
            control->id_client = requete->idclient;
        }
        if (requete->command_service == 3) /* fin de partie */
            control->etat_send = 0;
        else if (requete->command_service == 5) { /* mets à jour le jeux */
            control->id_client = requete->idclient;

            if ((requete->pos[2] == 3 || requete->pos[3] == 1)) /* le set ou user lost */
            {
                screen_wait_end_set(control); /* message d'attente de fin de set */
                clean_map(control, requete); /* nettoie la map */
            } else if (requete->pos[2] == 5 || requete->pos[3] == 1) { /* fin partie */
                /* disconnect le client */
                screen_result(control, requete);
            } else if (requete->pos[2] <= 2) { /* mets à jour la mapp */
                display_counter_header(control, requete->win_user);
                display_screen_game(control);
                display_map(control, requete);
                write_panel_score(control, requete);
            }
            SDL_RenderPresent(control->main_renderer); /* rafraichit l'image */
        }
        else if (requete->command_service == 6) { /* trop de client  */
            requete->etat_party_chrono = 0;
            requete->depart_time = 0;
            screen_party_start(control); /* message d'attente de fin de set */
            SDL_RenderPresent(control->main_renderer); /* rafraichit l'image */
        }
        else if (requete->command_service == 7) { /* trop de client  */
            requete->etat_party_chrono = 0;
            requete->depart_time = 0;
            screen_max_users(control); /* message d'attente de fin de set */
            SDL_RenderPresent(control->main_renderer); /* rafraichit l'image */
        }
        else if (requete->command_service == 8) { /* trop de client  */
            requete->etat_party_chrono = 0;
            requete->depart_time = 0;
            screen_version(control); /* message d'attente de fin de set */
            SDL_RenderPresent(control->main_renderer); /* rafraichit l'image */
        }
        control->mesg_en_bale = 0; /* désactive pour éviter d'inscrir des données non transmises */
    }
    SDL_Delay(5);
}

void end_game(t_control *control)
{
    SDL_Rect dest = {150,
                     (WINDOW_HEIGHT - 62),
                     control->sprites->cmenu[4].img.w,
                     control->sprites->cmenu[4].img.h};
    SDL_Rect renderQuad;

    dest.x = 350;
    display_button(control, dest);
    renderQuad.x = 370;
    renderQuad.w = (int)my_strlen("End") * 18;
    write_text_51(control, renderQuad, "End");

    SDL_RenderPresent(control->main_renderer);
}

void start_game(t_control *control) {
    SDL_Rect dest = {350,
                     (WINDOW_HEIGHT - 62),
                     control->sprites->cmenu[4].img.w,
                     control->sprites->cmenu[4].img.h + 1};

    display_background_button(control, dest);
    SDL_RenderPresent(control->main_renderer);
    prepare_requet_client(control, control->id_client, 11, 11, 0);
}