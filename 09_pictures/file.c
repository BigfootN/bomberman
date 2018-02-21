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

int writeConfigMap(t_etat *etat, int *list)
{
    int index;

    etat->dataMap = (t_clmap*) malloc(sizeof (t_clmap));
    etat->dataMap->nbreTiles.x = list[0];
    etat->dataMap->nbreTiles.y = list[1];
    etat->dataMap->nbreTiles.w = list[2];
    etat->dataMap->pos.x = list[3];
    etat->dataMap->pos.y = list[4];

    etat->dataMap->pos.h = HEIGHT_TILE * etat->dataMap->pos.x;
    etat->dataMap->pos.w = WIDTH_TILE * etat->dataMap->pos.y;
    etat->dataMap->wall = (int*) malloc(sizeof (int) * list[2]);
    index = 0;
    while (index < list[2])
    {
        etat->dataMap->wall[index] = 0;
        index++;
    }
    etat->dataMap->wall[list[5]] = 1;
    etat->dataMap->wall[list[6]] = 1;
    etat->dataMap->wall[list[7]] = 1;
    return (1);
}

int gestionData(t_etat *etat, char *name)
{
    char *title_brut;
    int index;
    int *list;
    FILE *fp;

    if ((fp = openFile(name)) != NULL)
    {
        etat->dataMap = (t_clmap*) malloc(sizeof (t_clmap));

        etat->dataMap->namefile = (char*) malloc(sizeof (char) * 64);
        etat->dataMap->namesprite = (char*) malloc(sizeof (char) * 64);
        etat->dataMap->title = (char*) malloc(sizeof (char) * 64);

        title_brut = (char*) malloc(sizeof (char) * 64);
        list = (int*) malloc(sizeof (int) * 8);

        fscanf(fp, "%s", title_brut);
        index = 0;
        while (title_brut[index] != '\0')
        {
            etat->dataMap->title[index] = filtre(title_brut[index]);
            index++;
        }

        fscanf(fp, "%s", etat->dataMap->namefile);
        fscanf(fp, "%s", etat->dataMap->namesprite);
        fscanf(fp, "%d %d %d", &list[0], &list[1], &list[2]);
        fscanf(fp, "%d %d", &list[3], &list[4]);
        fscanf(fp, "%d %d %d", &list[5], &list[6], &list[7]);

        if (list[0] != 0 && list[1] != 0 && list[2] != 0 && list[3] != 0 && list[4] != 0)
        {
            writeConfigMap(etat, list);
            initiMap(etat, fp);
            initsort(etat); 
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

void initiMap(t_etat *etat, FILE *fp)
{
    int indexX;
    int indexY;
 
    indexX = 0;
    etat->dataMap->realmap = (int**) malloc(sizeof (int*) * etat->dataMap->pos.x); //11
    etat->dataMap->mapaction = (int**) malloc(sizeof (int*) * etat->dataMap->pos.x);
    while (indexX < etat->dataMap->pos.x)
    {
        etat->dataMap->realmap[indexX] = (int*) malloc(sizeof (int) * etat->dataMap->pos.y); //15
        etat->dataMap->mapaction[indexX] = (int*) malloc(sizeof (int) * etat->dataMap->pos.y);
        indexY = 0;
        while (indexY < etat->dataMap->pos.y)
        {
            etat->dataMap->realmap[indexX][indexY] = 0;
            etat->dataMap->mapaction[indexX][indexY] = -1;
            fscanf(fp, "%d", &etat->dataMap->realmap[indexX][indexY]);
            indexY++;
        }
        indexX++;
    }
}

void initsort(t_etat *etat)
{
    int indexX;
    int indexY;

    indexX = 0;
    etat->dataMap->bmmap = (int**) malloc(sizeof (int*) * etat->dataMap->pos.x);
    while (indexX < etat->dataMap->pos.x)
    {
        etat->dataMap->bmmap[indexX] = (int*) malloc(sizeof (int) * etat->dataMap->pos.y);
        indexY = 0;
        while (indexY < etat->dataMap->pos.y)
        {
            etat->dataMap->bmmap[indexX][indexY] = -1;
            indexY++;
        }
        indexX++;
    }
}