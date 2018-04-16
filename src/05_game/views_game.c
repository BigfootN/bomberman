//
// Created by marc on 01/03/18.
//

#include "headers.h"

int central_game(t_control *control)
{
    int menu_select;
    /* initialise le la d'affichage */
    window_init(control);
    /* initialise le chrono de la partie */
    chrono_set = 0;
    /* menu des partie du jeux */
    menu_select = 0;
    /* rénitialise le numéro de socket du joueur */
    control->id_client = -1;
    /* affiche un panneau d'attente */
    display_screen_wait(control);
    write_version(control);
    /* */
    SDL_RenderPresent(control->main_renderer);
    /* lance la ia lors que le serveur est pret */
    control->master = 0;
    if (control->srv_or_clt == 1){
        control->master = 1;
        thread_ia(control);
    }
    /* attend pour demarrer le client */
    SDL_Delay(500);
    /* demarre la socket du client*/
    tcp_thread_client(control);
    /* lance la boucle des commandes du client */
    game_loop(control, &menu_select);
    /* attend pour demarrer le client */
    SDL_Delay(500);
    /* fin de partie détruit l'interface cliente */
    SDL_DestroyRenderer(control->main_renderer);
    /* return avec la sélection choisie dans la boucle */
    return (menu_select);
}

void display_sprite(t_control *control)
{
    int indexX;
    int indexY;
    int number;

    number = 0;
    indexX = 0;
    while (indexX < 4)
    {
        indexY = 0;
        while (indexY < 9)
        {
            if (number < 31)
            {
                SDL_Rect dest1 = {indexY * WIDTH_TILE, indexX * WIDTH_TILE, WIDTH_TILE, WIDTH_TILE};
                SDL_Texture* pTexture1 = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dsprites);
                SDL_RenderCopy(control->main_renderer, pTexture1, &(control->sprites->csprites[number].img), &dest1);
                SDL_DestroyTexture(pTexture1);
                SDL_RenderPresent(control->main_renderer);
            }
            number++;
            indexY++;
        }
        indexX++;
    }
}

void display_screen_wait(t_control *control)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control);
    create_compteur(control);
    create_panel_wait(control);
}

void create_panel_end_set(t_control *control)
{
    SDL_Rect srcr;

    srcr.w = (int)(320 * 1.2);
    srcr.h = (int)(162 * 1.2);
    srcr.y = 200;
    srcr.x = 220;

    SDL_Texture* ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dattente);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->cattente->img), &srcr);
    SDL_DestroyTexture(ptexture);
}

void screen_wait_end_set(t_control *control)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control); // le panel blanc
    create_compteur(control);
    create_panel_waitset(control);
}

/*
 * la party est déjà commencée
 */

void screen_party_start(t_control *control)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control);
    create_compteur(control);
    create_party_start(control);
}

/*
 * le nombre d'utlisateurs est déjà présent
 */

void screen_max_users(t_control *control)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control);
    create_compteur(control);
    create_max_users(control);
}

void screen_version(t_control *control)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control);
    create_compteur(control);
    create_version(control);
}



void display_screen_game(t_control *control)
{
   // create_panel(control);
    //button_game(control);
    //create_panel_game(control);
    //create_area_map(control);
   // create_compteur(control);
    create_area_bonus(control);
}

void screen_result(t_control *control,  t_svr_sd *requete)
{
    create_panel(control);
    button_game(control);
    create_panel_game(control); // le panel blanc
    create_panel_result(control, requete);
    create_compteur(control);
    //create_compteur(control);
}

void thread_ia(t_control *control)
{
    pthread_t p_thread;

    if (pthread_create(&p_thread, NULL, central_ia, (void*)control) < 0)
    {
        perror("could not create thread");
        return;
    }
}

void button_game(t_control* control)
{
    SDL_Rect dest = {150,
                     (WINDOW_HEIGHT - 62),
                     control->sprites->cmenu[4].img.w,
                     control->sprites->cmenu[4].img.h};
    display_button(control, dest);
    dest.x = 350;
    if (control->srv_or_clt == 1)
        display_button(control, dest);
    dest.x = 550;
    display_button(control, dest);

    SDL_Rect renderQuad = {160, WINDOW_HEIGHT - 61, (int)my_strlen("Return") * 18, 50};
    write_text_51(control, renderQuad, "Return");
    if (control->srv_or_clt == 1)
    {
        renderQuad.x = 370;
        renderQuad.w = (int)my_strlen("Start") * 18;
        write_text_51(control, renderQuad, "Start");
    }
    renderQuad.x = 570;
    renderQuad.w = (int)my_strlen("Close") * 18;
    write_text_51(control, renderQuad, "Close");
}