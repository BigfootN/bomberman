#include "bomberman.h"

static int my_nb_len(int n)
{
    int index;

    index = 0;
    if (n < 0)
        n = n * (-1);

    while (n >= 10 || n <= -10)
    {
        n = n / 10;
        index++;
    }
    return (index);
}

static char *my_putwnbr(int n, int index)
{
    char *number;
    int indexb;
    int indexc;
    char *tmp;

    indexc = index;
    indexb = 0;
    tmp = (char*) malloc(sizeof (char) * (index + 1));
    number = (char*) malloc(sizeof (char) * (index + 1));
    bzero(number, index + 1);
    bzero(tmp, index + 1);

    if (n < 0)
        n = n * (-1);
    while (indexb < indexc + 1)
    {
        if (n >= 10)
        {
            n = n / 10;
            tmp[indexb] = (n % 10) + '0';
        }
        else
            tmp[indexb] = n + '0';
        indexb++;
    }
    indexb = 0;
    while (indexc >= 0)
    {
        number[indexb] = tmp[indexc];
        indexb++;
        indexc--;
    }
    return (number);
}

char *my_put_nbr(int n)
{
    int index;
    char *str;

    index = my_nb_len(n);
    str = my_putwnbr(n, index);
    return (str);
}