//
// Created by marc on 01/03/18.
//

#include "bomberman.h"

void create_panel_game(t_control *control) {
    SDL_Rect position;
    position.w = WINDOW_WIDTH;
    position.h = WINDOW_HEIGHT - 64;
    position.x = 0;
    position.y = 0;
    SDL_SetRenderDrawColor(control->main_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(control->main_renderer, &position);
}

void create_area_map(t_control *control) {
    SDL_Rect position;

    position.w = 15 * 40;
    position.h = 11 * 40;
    position.x = 10;
    position.y = (int) ((32.0 * 1.8) + 10.0);

    SDL_SetRenderDrawColor(control->main_renderer, 240, 128, 0, 255);
    SDL_RenderFillRect(control->main_renderer, &position);
}

void create_compteur(t_control *control) {
    SDL_Rect encart = {0, 0, WINDOW_WIDTH, (int) (32 * 1.8)};
    SDL_Texture *p_texture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[2].img), &encart);
    SDL_DestroyTexture(p_texture);

    SDL_Rect encart_left = {(WINDOW_WIDTH / 5), 0, (int) (256 * 1.8), (int) (32 * 1.8)};
    SDL_Texture *p_texture_left = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->main_renderer, p_texture_left, &(control->sprites->cmenu[1].img), &encart_left);
    SDL_DestroyTexture(p_texture_left);
}

void display_counter(t_control *control, int minute1, int minute2, int seconde1, int seconde2) {
    SDL_Rect dimension = {(WINDOW_WIDTH / 5) + 195, 15, (int) (8 * 1.8), (int) (14 * 1.8)};

    SDL_Texture *p_texture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[minute1 + 6].img), &dimension);

    dimension.x = (WINDOW_WIDTH / 5) + 209;
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[minute2 + 6].img), &dimension);

    dimension.x = (WINDOW_WIDTH / 5) + 230;
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[seconde1 + 6].img), &dimension);

    dimension.x = (WINDOW_WIDTH / 5) + 243;
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[seconde2 + 6].img), &dimension);
    SDL_DestroyTexture(p_texture);
    SDL_RenderPresent(control->main_renderer);
}

void display_counter_header(t_control *control, int *tabl)
{
    SDL_Rect dimension = {(WINDOW_WIDTH / 5) + 70, 15, (int) (8 * 1.8), (int) (14 * 1.8)};

    SDL_Texture *p_texture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[tabl[0] + 6].img), &dimension);

    dimension.x = (WINDOW_WIDTH / 5)  + 157;
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[tabl[1] + 6].img), &dimension);

    dimension.x = (WINDOW_WIDTH / 5) + 315;
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[tabl[2] + 6].img), &dimension);

    dimension.x = (WINDOW_WIDTH / 5) + 402;
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[tabl[3] + 6].img), &dimension);

    SDL_DestroyTexture(p_texture);
    SDL_RenderPresent(control->main_renderer);
}

void create_area_bonus(t_control *control) {
    SDL_Rect dimension = {(15 * 40) + 40, (int) (32 * 1.8) + 10, 138, 339};
    SDL_Texture *p_texture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmenu);
    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->cmenu[17].img), &dimension);
    SDL_DestroyTexture(p_texture);
}
/* obsolete */
void display_map_old(t_control *control, t_svr_sd *requete) {
    int row;
    int col;
    int tuile;
    int bm;
    int action;

    col = 0;
    row = 0;
    if (requete->pos[0] == 0 && requete->pos[1] == 0)
        return;
    while (row < requete->pos[0]) {
        col = 0;
        while (col < requete->pos[1]) {
            tuile = requete->map_decor[row][col];
            SDL_Rect dimension = {(col * WIDTH_TILE) + 10, (row * HEIGHT_TILE) + (int) (32 * 1.8) + 10, WIDTH_TILE,
                                  HEIGHT_TILE};
            SDL_Texture *p_texture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dsprites);
            if (tuile >= 0)
                SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->csprites[tuile].img), &dimension);
            bm = requete->map_bm[row][col];
            if (bm >= 0)
                SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->csprites[bm].img), &dimension);
            action = requete->map_action[row][col];
            if (action >= 0)
                SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->csprites[action].img),
                               &dimension);
            SDL_DestroyTexture(p_texture);
            col++;
        }
        row++;
    }
}

void clean_map(t_control *control, t_svr_sd *requete)
{
    int row;
    int col;

    row = 0;
    while (row < requete->pos[0]) {
        col = 0;
        while (col < requete->pos[1]) {
            control->map_area_old[row][col] = -1;
            control->map_bm_old[row][col]  = -1;
            control->map_action_old[row][col]   = -1;
            col++;
        }
        row++;
    }
}

void display_map(t_control *control, t_svr_sd *requete) {
    int row;
    int col;
    int tuile;
    int bm;
    int action;

    col = 0;
    row = 0;
    if (requete->pos[0] == 0 && requete->pos[1] == 0)
        return;
    while (row < requete->pos[0]) {
        col = 0;
        while (col < requete->pos[1]) {

            tuile = requete->map_decor[row][col];
            bm = requete->map_bm[row][col];
            action = requete->map_action[row][col];
            if(action > 31)/* probleme */
                return;

            if(control->map_area_old[row][col] != tuile
               || control->map_bm_old[row][col] != bm
               || control->map_action_old[row][col] != action)
            {
                SDL_Rect dimension = {(col * WIDTH_TILE) + 10, (row * HEIGHT_TILE) + (int) (32 * 1.8) + 10, WIDTH_TILE,
                                      HEIGHT_TILE};
                SDL_Texture *p_texture = SDL_CreateTextureFromSurface(control->main_renderer,
                                                                      control->sprites->dsprites);
                if (tuile >= 0)
                    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->csprites[tuile].img),
                                   &dimension);
                control->map_area_old[row][col] = tuile;

                if (bm >= 0)
                    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->csprites[bm].img),
                                   &dimension);
                control->map_bm_old[row][col] = bm;

                if (action >= 0)
                    SDL_RenderCopy(control->main_renderer, p_texture, &(control->sprites->csprites[action].img),
                                   &dimension);
                control->map_action_old[row][col] = action;

                SDL_DestroyTexture(p_texture);
            }
            col++;
        }
        row++;
    }
}

void write_panel_score(t_control *control, t_svr_sd *requete) {
    int number;
    char buf[255];

    number = requete->state_player.score;
    sprintf(buf, "%d", number);

    SDL_Rect renderQuad = {(15 * 40) + 100, (int) (32 * 1.8) + 70, (int) my_strlen(buf) * 18, 50};
    write_string(control, renderQuad, buf);

    number = requete->state_player.bomb;
    sprintf(buf, "%d", number);
    SDL_Rect renderQuad2 = {(15 * 40) + 100, (int) (32 * 1.8) + 180, (int) my_strlen(buf) * 18, 50};
    write_string(control, renderQuad2, buf);

    number = requete->state_player.speed;
    sprintf(buf, "%d", number);
    SDL_Rect renderQuad3 = {(15 * 40) + 100, (int) (32 * 1.8) + 290, (int) my_strlen(buf) * 18, 50};
    write_string(control, renderQuad3, buf);
    SDL_RenderPresent(control->main_renderer);
}

void create_panel_result(t_control *control, t_svr_sd *requete) {
    SDL_Rect position;
    position.w = (int) (320 * 1.2);
    position.h = (int) (162 * 1.2);
    position.y = 200;
    position.x = 220;

    if (requete->state_player.win > 0) {
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dresultat);
        SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->cresultat[2].img), &position);
        SDL_DestroyTexture(pTexture);
    } else if (requete->state_player.win <= 0) {
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dresultat);
        SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->cresultat[1].img), &position);
        SDL_DestroyTexture(pTexture);
    }
}
