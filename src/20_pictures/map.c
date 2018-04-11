//
// Created by marc on 05/04/18.
//
#include "headers.h"

int gestion_map(t_etat *etat, char *name)
{
    char *title_brut;
    int index;
    int *list;
    FILE *fp;

    if ((fp = open_file(name)) != NULL)
    {
        free(etat->data_map);/* libere avant de réallouer */
        etat->data_map = (t_clmap*) malloc(sizeof (t_clmap));

        etat->data_map->namefile = (char*) malloc(sizeof (char) * 64);
        etat->data_map->namesprite = (char*) malloc(sizeof (char) * 64);
        etat->data_map->title = (char*) malloc(sizeof (char) * 64);

        title_brut = (char*) malloc(sizeof (char) * 64);
        list = (int*) malloc(sizeof (int) * 8);

        fscanf(fp, "%s", title_brut);
        index = 0;
        while (title_brut[index] != '\0')
        {
            etat->data_map->title[index] = filtre(title_brut[index]);
            index++;
        }
        free(title_brut);

        fscanf(fp, "%s", etat->data_map->namefile);
        fscanf(fp, "%s", etat->data_map->namesprite);
        fscanf(fp, "%d %d %d", &list[0], &list[1], &list[2]);
        fscanf(fp, "%d %d", &list[3], &list[4]);
        fscanf(fp, "%d %d %d", &list[5], &list[6], &list[7]);

        if (list[0] != 0 && list[1] != 0 && list[2] != 0 && list[3] != 0 && list[4] != 0)
        {
            write_config_map(etat, list);
            initi_map(etat, fp);
            init_sort(etat);
            fclose(fp);
            free(list);
            return (1);
        }
        fclose(fp);
    }
    free(list);
    return (0);
}

/* extrait du fichier de la map la carte et ls autres infos */
FILE *open_file(char *name)
{
    FILE *fp;
    //char *text;
    char *name_file;

    name_file = create_directory_file(name, 2);

    if ((fp = fopen(name_file, "r")) == NULL)
    {
        my_putstr("fichier ");
        my_putstr(name);
        my_putstr(" maquant !\n");
        free(name_file);
        SDL_Quit();
        return NULL;
    }
    free(name_file);
    return (fp);
}

/* nettoie le nom d ela carte pour l'enregistrer correctment */
char filtre(char c)
{
    if ((c >= 97 && 122 <= c) || (c >= 65 && 90 <= c))
        return c;
    else if (c == 95)
        return ' ';
    else
        return '\0';
}

int write_config_map(t_etat *etat, int *list)
{
    int index;

    /* initialise la map */
   // etat->data_map = (t_clmap*) malloc(sizeof (t_clmap));

    etat->data_map->nbreTiles.x = list[0];
    etat->data_map->nbreTiles.y = list[1];
    etat->data_map->nbreTiles.w = list[2];
    /* prend le nombre de ligne et de colonne */
    etat->data_map->pos.x = list[3];
    etat->data_map->pos.y = list[4];

    etat->data_map->pos.h = HEIGHT_TILE * etat->data_map->pos.x;
    etat->data_map->pos.w = WIDTH_TILE * etat->data_map->pos.y;
    etat->data_map->wall = (int*) malloc(sizeof (int) * list[2]);
    index = 0;
    while (index < list[2])
    {
        etat->data_map->wall[index] = 0;
        index++;
    }
    etat->data_map->wall[list[5]] = 1;
    etat->data_map->wall[list[6]] = 1;
    etat->data_map->wall[list[7]] = 1;
    return (1);
}

// les maps map et hidebonus

void initi_map(t_etat *etat, FILE *fp)
{
    int indexX;
    int indexY;

    indexX = 0;
    etat->data_map->map_user_castdown = (int**) malloc(sizeof (int*) * etat->data_map->pos.x); //11
    etat->data_map->realmap = (int**) malloc(sizeof (int*) * etat->data_map->pos.x); //11
    etat->data_map->mapaction = (int**) malloc(sizeof (int*) * etat->data_map->pos.x);
    etat->data_map->map_old = (int**) malloc(sizeof (int*) * etat->data_map->pos.x);
    while (indexX < etat->data_map->pos.x)
    {
        etat->data_map->map_user_castdown[indexX] = (int*) malloc(sizeof (int) * etat->data_map->pos.y); //15
        etat->data_map->realmap[indexX] = (int*) malloc(sizeof (int) * etat->data_map->pos.y); //15
        etat->data_map->mapaction[indexX] = (int*) malloc(sizeof (int) * etat->data_map->pos.y);
        etat->data_map->map_old[indexX] = (int*) malloc(sizeof (int) * etat->data_map->pos.y);
        indexY = 0;
        while (indexY < etat->data_map->pos.y)
        {
            etat->data_map->map_user_castdown[indexX][indexY] = 0;
            etat->data_map->realmap[indexX][indexY] = 0;
            etat->data_map->map_old[indexX][indexY] = 0;
            etat->data_map->mapaction[indexX][indexY] = -1;
            fscanf(fp, "%d", &etat->data_map->realmap[indexX][indexY]);
            indexY++;
        }
        indexX++;
    }
}

void init_sort(t_etat *etat)
{
    int indexX;
    int indexY;

    indexX = 0;
    etat->data_map->bmmap = (int**) malloc(sizeof (int*) * etat->data_map->pos.x);
    while (indexX < etat->data_map->pos.x)
    {
        etat->data_map->bmmap[indexX] = (int*) malloc(sizeof (int) * etat->data_map->pos.y);
        indexY = 0;
        while (indexY < etat->data_map->pos.y)
        {
            etat->data_map->bmmap[indexX][indexY] = -1;
            indexY++;
        }
        indexX++;
    }
}
