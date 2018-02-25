#include "headers.h"

char filtre(char c)
{
    if ((c >= 97 && 122 <= c) || (c >= 65 && 90 <= c))
        return c;
    else if (c == 95)
        return ' ';
    else
        return '\0';
}

int writeConfigMap(state_t *state, int *list)
{
    int index;

    state->map_info = (clmap_t*) malloc(sizeof (clmap_t));
    state->map_info->nbreTiles.x = list[0];
    state->map_info->nbreTiles.y = list[1];
    state->map_info->nbreTiles.w = list[2];
    state->map_info->pos.x = list[3];
    state->map_info->pos.y = list[4];

    state->map_info->pos.h = HEIGHT_TILE * state->map_info->pos.x;
    state->map_info->pos.w = WIDTH_TILE * state->map_info->pos.y;
    state->map_info->wall = (int*) malloc(sizeof (int) * list[2]);
    index = 0;
    while (index < list[2])
    {
        state->map_info->wall[index] = 0;
        index++;
    }
    state->map_info->wall[list[5]] = 1;
    state->map_info->wall[list[6]] = 1;
    state->map_info->wall[list[7]] = 1;
    return (1);
}

int gestionData(state_t *state, char *name)
{
    char *title_brut;
    int index;
    int *list;
    FILE *fp;

    if ((fp = openFile(name)) != NULL)
    {
        state->map_info = (clmap_t*) malloc(sizeof (clmap_t));

        state->map_info->file_name = (char*) malloc(sizeof (char) * 64);
        state->map_info->sprite_name = (char*) malloc(sizeof (char) * 64);
        state->map_info->title = (char*) malloc(sizeof (char) * 64);

        title_brut = (char*) malloc(sizeof (char) * 64);
        list = (int*) malloc(sizeof (int) * 8);

        fscanf(fp, "%s", title_brut);
        index = 0;
        while (title_brut[index] != '\0')
        {
            state->map_info->title[index] = filtre(title_brut[index]);
            index++;
        }

        fscanf(fp, "%s", state->map_info->file_name);
        fscanf(fp, "%s", state->map_info->sprite_name);
        fscanf(fp, "%d %d %d", &list[0], &list[1], &list[2]);
        fscanf(fp, "%d %d", &list[3], &list[4]);
        fscanf(fp, "%d %d %d", &list[5], &list[6], &list[7]);

        if (list[0] != 0 && list[1] != 0 && list[2] != 0 && list[3] != 0 && list[4] != 0)
        {
            writeConfigMap(state, list);
            initiMap(state, fp);
            initsort(state);
            fclose(fp);
            return (1);
        }
        fclose(fp);
    }
    return (0);
}

FILE *openFile(char *name)
{
    FILE *fp;
    char *text;

    text = (char*) malloc(sizeof (char) * my_strlen("map/"));
    bzero(text, my_strlen("map/"));
    text = my_strcat(text, "map/");
    text = my_strcat(text, name);

    if ((fp = fopen(text, "r")) == NULL)
    {
        my_putstr("fichier ");
        my_putstr(name);
        my_putstr(" maquant !\n");
        SDL_Quit();
        return NULL;
    }
    return (fp);
}

// les maps map et hidebonus

void initiMap(state_t *state, FILE *fp)
{
    int indexX;
    int indexY;
 
    indexX = 0;
    state->map_info->real_map = (int**) malloc(sizeof (int*) * state->map_info->pos.x); //11
    state->map_info->action_map = (int**) malloc(sizeof (int*) * state->map_info->pos.x);
    while (indexX < state->map_info->pos.x)
    {
        state->map_info->real_map[indexX] = (int*) malloc(sizeof (int) * state->map_info->pos.y); //15
        state->map_info->action_map[indexX] = (int*) malloc(sizeof (int) * state->map_info->pos.y);
        indexY = 0;
        while (indexY < state->map_info->pos.y)
        {
            state->map_info->real_map[indexX][indexY] = 0;
            state->map_info->action_map[indexX][indexY] = -1;
            fscanf(fp, "%d", &state->map_info->real_map[indexX][indexY]);
            indexY++;
        }
        indexX++;
    }
}

void initsort(state_t *state)
{
    int indexX;
    int indexY;

    indexX = 0;
    state->map_info->penalty_bonus_map = (int**) malloc(sizeof (int*) * state->map_info->pos.x);
    while (indexX < state->map_info->pos.x)
    {
        state->map_info->penalty_bonus_map[indexX] = (int*) malloc(sizeof (int) * state->map_info->pos.y);
        indexY = 0;
        while (indexY < state->map_info->pos.y)
        {
            state->map_info->penalty_bonus_map[indexX][indexY] = -1;
            indexY++;
        }
        indexX++;
    }
}