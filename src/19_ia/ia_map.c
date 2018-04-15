//
// Created by marc on 01/03/18.
//

#include "headers.h"

int serialize_map(t_etat *etat)
{
    int row;
    int col;
    int decor;
    int bm;
    int action;
    int maxrows;
    int maxcols;

    etat->msg->pos[0] = etat->data_map->pos.x;
    etat->msg->pos[1] = etat->data_map->pos.y;

    if ( etat->msg->pos[0] == 0 && etat->msg->pos[1] == 0)
        return (-1);

    row = 0;
    while (row < etat->data_map->pos.x)
    {
        col = 0;
        while (col < etat->data_map->pos.y)
        {
            decor = etat->data_map->realmap[row][col]; // code des murs et autres
            action = etat->data_map->mapaction[row][col];
            bm = etat->data_map->bmmap[row][col];

            if (etat->data_map->wall[decor] != 1)
            {
                etat->msg->map_action[row][col] = action;
                etat->msg->map_bm[row][col] = bm;
            }
            else
            {
                etat->msg->map_action[row][col] = -1;
                etat->msg->map_bm[row][col] = -1;
            }
            etat->msg->map_decor[row][col] = decor;
            col++;
        }
        row++;
    }
    return (1);
}
