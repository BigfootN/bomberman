#include "headers.h"

int checkAllPions(t_etat *etat)
{
    t_pions *tmp;

    tmp = etat->pion;
    while (tmp != NULL)
    {
        if (tmp->active == 1 && etat->partie == 1)
        {
            if (tmp->etat_requete == 1)
            {
                if (tmp->requete_1 == 2)
                    etatBomb(etat, tmp);
                else if (tmp->requete_1 == 3)
                {
                    if (tmp->type >= 27 && tmp->type <= 30)
                        IAMonster(etat, tmp);
                }
            }

        }
        tmp = tmp->next;
    }
    return (1);
}

void desactivePlayers(t_etat *etat, int numberPlayer)
{
    t_pions *tmp;

    tmp = etat->pion;

    while (tmp != NULL)
    {
        if (tmp->id == numberPlayer || tmp->type == numberPlayer)
        {
            if (tmp->active == 1)
            {
                tmp->active = 0;
                if (tmp->type != 1)
                    deadPion(etat, tmp);
                return;
            }
        }
    }
}

t_pions *searchPlayer(t_etat *etat, int numberPlayer)
{
    t_pions *pion;

    pion = etat->pion;
    while (pion != NULL)
    {
        if (pion->id == numberPlayer)
            return (pion);
        else if (pion->type == numberPlayer)
            return (pion);

        pion = pion->next;
    }
    return (NULL);
}

void deadPion(t_etat *etat, t_pions *tmp)
{
    tmp->active = 0;
    etat->dataMap->bmmap[tmp->mappos.x][tmp->mappos.y] = -1;
    etat->dataMap->mapaction[tmp->mappos.x][tmp->mappos.y] = -1;
    deleteListChevron(tmp);
}

int checkRequetePlayer(t_etat *etat)
{
    t_player *player;
    t_pions *tmp;

    player = etat->players;

    while (player != NULL)
    {
        if (player->player->active == 1)
        {
            tmp = player->player;
            tmp->requete_1 = player->requete_1;
            tmp->requete_2 = player->requete_2;
            if (player->etat_requete == 1)
            {
                if (player->requete_1 == 2 && etat->partie == 1)
                    movePions(etat, tmp, 0, tmp->requete_2);
                else if (player->requete_1 == 3 && etat->partie == 1)
                    movePions(etat, tmp, 1, tmp->requete_2);
                else if (player->requete_1 == 4 && etat->partie == 1)
                    initBomb(etat, tmp);
                else if (player->requete_1 == 6 && etat->partie == 1)
                {

                }
                else if (player->requete_1 == 10)
                    initGamers(etat, tmp);
                else if (player->requete_1 == 11)
                {
                    if (etat->partie == 0)
                        startTime(etat);
                    etat->partie = 1;
                }
                else if (player->requete_1 == 12)
                    etat->partie = 2;
            }
            player->etat_requete = 0;
            player->requete_1 = 0;
            player->requete_2 = 0;
        }
        player = player->next;
    }
    return (1);
}
// init gamer

void initGamers(t_etat *etat, t_pions *player)
{
    if (player->id == 1)
    {
        player->mappos.x = 1;
        player->mappos.y = 1;
        player->type = 23;
        etat->dataMap->mapaction[1][1] = 23;
    }
    else if (player->id == 2)
    {
        player->mappos.x = 1;
        player->mappos.y = 13;
        player->type = 24;
        etat->dataMap->mapaction[1][13] = 24;
    }
    else if (player->id == 3)
    {
        player->mappos.x = 9;
        player->mappos.y = 13;
        player->type = 25;
        etat->dataMap->mapaction[9][13] = 25;
    }
    else if (player->id == 4)
    {
        player->mappos.x = 9;
        player->mappos.y = 1;
        player->type = 26;
        etat->dataMap->mapaction[9][1] = 26;
    }
}

int collision_details(t_etat* etat, int dx, int dy)
{
    int etatX = (0 <= dx && (etat->dataMap->pos.x) >= dx);
    int etatY = (0 <= dy && (etat->dataMap->pos.y) >= dy);

    if (etatX && etatY)
    {
        int tuile = etat->dataMap->realmap[dx][dy];
        //printf("%d\n", tuile);
        if (etat->dataMap->wall[tuile] == 1)
            return 0;
        else
            return 1;
    }
    return 0;
}

int collision_BM(t_etat* etat, t_pions *player, int dx, int dy)
{
    t_pions *pion;

    int etatX = (0 <= dx && (etat->dataMap->pos.x) >= dx);
    int etatY = (0 <= dy && (etat->dataMap->pos.y) >= dy);

    if (etatX && etatY)
    {
        int bm = etat->dataMap->bmmap[dx][dy];

        if (bm == 4)
            player->bomb += 1;
        else if (bm == 5)
        {
            if (player->bomb > 0)
                player->bomb -= 1;
        }
        else if (bm == 6)
            player->bomb += 3;
        else if (bm == 7)
            player->speed = 2;
        else if (bm == 8)
        {
            player->active = 0;
            player->life = 0;
            etat->dataMap->mapaction[dx][dy] = -1;
        }
        // retire le BM
        if (bm != -1)
            etat->dataMap->bmmap[dx][dy] = -1;

        int monster = etat->dataMap->mapaction[dx][dy];
        if (monster >= 27 && monster <= 30)
        {
            SDL_Rect empl;
            empl.x = dx;
            empl.y = dy;
            t_pions *tmp = searchMonster(etat, monster, empl);
            if (player->life > tmp->life)
            {
                deleteMonster(etat, tmp->type, empl);
                player->score += 1;
                etat->dataMap->mapaction[dx][dy] = player->id;
            }
            else
            {
                player->active = 0;
                player->life = 0;
            }
        }

        // rencontre entre players le plus fort l'emporte
        int otherPlayer = etat->dataMap->mapaction[dx][dy];
        if (otherPlayer >= 23 && otherPlayer <= 26)
        {
            pion = searchPlayer(etat, otherPlayer);
            if (pion->life > player->life)
            {
                pion->life -= player->life;
                player->life = 0;
                player->active = 0;
            }
            else if (pion->life < player->life)
            {
                player->life -= pion->life;
                pion->life = 0;
                pion->active = 0;
                etat->dataMap->mapaction[dx][dy] = player->id;
                player->score += 1;
            }
        }

        return (1);
    }
    return 0;
}

void movePions(t_etat* etat, t_pions *player, int type, int value)
{
    int col;
    int row;
    int dy;
    int dx;
    int index;

    index = 0;
    while (index < 1)
    {
        dx = player->mappos.x;
        dy = player->mappos.y;
        col = dy;
        row = dx;

        if (value == 0)
            value = -1;
        // prend en compte de maniere provisoire 
        // pour le test collision
        if (type == 1 && value < 0)// left
            dx = player->mappos.x + value;
        else if (type == 1 && value > 0) // right
            dx = player->mappos.x + value;
        else if (type == 0 && value < 0) // up
            dy = player->mappos.y + value;
        else if (type == 0 && value > 0) /// bottom
            dy = player->mappos.y + value;

        if (collision_details(etat, dx, dy))
        {
            int type;
            // mets a jour le joueur
            type = etat->dataMap->mapaction[row][col];
            etat->dataMap->mapaction[row][col] = -1;
            player->mappos.x = dx;
            player->mappos.y = dy;
            if (collision_BM(etat, player, dx, dy))/* verifie que l'emplacement est libre ou sinon fait le combat */
                etat->dataMap->mapaction[dx][dy] = type;
        }
        else
            return;
        index++;
    }
}
// envoi du message de fin de rencontre et destruction des players
//int sendRequeteForUniqPlayer(t_etat *etat, int socket, int action, int message)

void deletePlayers(t_etat* etat)
{
    t_player *player;

    player = etat->players; // utilisateur
    while (player != NULL)
    {
        sendRequeteForUniqPlayer(etat, player->socket_player, 3, 5);
        SDL_Delay(100);
        player = deleteListPlayer(player);
    }
    //free(player);
}

void deletePions(t_etat* etat)
{
    t_pions *pions;

    pions = etat->pion; // utilisateur
    while (pions != NULL)
    {
        pions = deleteListChevron(pions);
    }
    //free(pions);
}

void sendEndParty(t_etat* etat)
{
    deletePions(etat);
    deletePions(etat);
}
