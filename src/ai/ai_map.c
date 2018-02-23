#include "headers.h"

int serializeMap(t_etat *etat)
{
    int row;
    int col;
    int decor;
    int bm;
    int action;

    // if ((etat->msg = (t_svrSd*) malloc(sizeof (t_svrSd))) != NULL)
    // {
    etat->msg->pos[0] = etat->dataMap->pos.x;
    etat->msg->pos[1] = etat->dataMap->pos.y;
    row = 0;
    while (row < etat->dataMap->pos.x)
    {
        col = 0;
        while (col < etat->dataMap->pos.y)
        {
            decor = etat->dataMap->realmap[row][col]; // code des murs et autres
            action = etat->dataMap->mapaction[row][col];
            bm = etat->dataMap->bmmap[row][col];

            if (etat->dataMap->wall[decor] != 1)
            {
                etat->msg->mapAction[row][col] = action;
                etat->msg->mapBM[row][col] = bm;
            }
            else
            {
                etat->msg->mapAction[row][col] = -1;
                etat->msg->mapBM[row][col] = -1;
            }
            etat->msg->mapDecor[row][col] = decor;
            col++;
        }
        row++;
    }
    return (1);
    //}
    return (0);
}