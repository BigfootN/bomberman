//
// Created by marc on 01/03/18.
//

#include "headers.h"

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
/* les résultats des joueurs dans l'entete */
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
/*nettoie les carte*/
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

void write_version(t_control *control)
{
    SDL_Rect renderQuad3 = {WINDOW_WIDTH - 70, WINDOW_HEIGHT -20, 11 * 5, 15};
    write_string(control, renderQuad3, VERSION);
    SDL_RenderPresent(control->main_renderer);
}

void write_panel_score(t_control *control, t_svr_sd *requete) {
    int number;
    char buf[255];

    number = requete->stat_user[1]; /* score */
    sprintf(buf, "%d", number);

    SDL_Rect renderQuad = {(15 * 40) + 100, (int) (32 * 1.8) + 70, (int) my_strlen(buf) * 18, 50};
    write_string(control, renderQuad, buf);

    number = requete->stat_user[5]; //bomb;
    sprintf(buf, "%d", number);
    SDL_Rect renderQuad2 = {(15 * 40) + 100, (int) (32 * 1.8) + 180, (int) my_strlen(buf) * 18, 50};
    write_string(control, renderQuad2, buf);

    number = requete->stat_user[2]; //life;
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

    if (requete->stat_user[7] > 0) { //win
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dresultat);
        SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->cresultat[2].img), &position);
        SDL_DestroyTexture(pTexture);
    } else if (requete->stat_user[7] <= 0) { //win
        SDL_Texture *pTexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dresultat);
        SDL_RenderCopy(control->main_renderer, pTexture, &(control->sprites->cresultat[1].img), &position);
        SDL_DestroyTexture(pTexture);
    }
}

void create_party_start(t_control *control)
{
    SDL_Rect srcr;

    srcr.w = (int)(320 * 1.2);
    srcr.h = (int)(162 * 1.2);
    srcr.y = 200;
    srcr.x = 220;

    SDL_Texture* ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dpartystart);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->cpartystart->img), &srcr);
    SDL_DestroyTexture(ptexture);
}

void create_max_users(t_control *control)
{
    SDL_Rect srcr;

    srcr.w = (int)(320 * 1.2);
    srcr.h = (int)(162 * 1.2);
    srcr.y = 200;
    srcr.x = 220;

    SDL_Texture* ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dmaxusers);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->cmaxusers->img), &srcr);
    SDL_DestroyTexture(ptexture);
}

void create_version(t_control *control)
{
    SDL_Rect srcr;

    srcr.w = (int)(320 * 1.2);
    srcr.h = (int)(162 * 1.2);
    srcr.y = 200;
    srcr.x = 220;

    SDL_Texture* ptexture = SDL_CreateTextureFromSurface(control->main_renderer, control->sprites->dversion);
    SDL_RenderCopy(control->main_renderer, ptexture, &(control->sprites->cversion->img), &srcr);
    SDL_DestroyTexture(ptexture);
}