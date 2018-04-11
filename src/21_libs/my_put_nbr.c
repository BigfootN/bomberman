#include "headers.h"

static int my_nb_len(int n) {
    int index;

    index = 0;
    if (n < 0)
        n = n * (-1);

    while (n >= 10 || n <= -10) {
        n = n / 10;
        index++;
    }
    return (index);
}

static char *my_putwnbr(int n, int index) {
    char *number;
    int indexb;
    int indexc;
    char *tmp, *tmp2;

    indexc = index;
    indexb = 0;
    tmp = (char *) malloc(sizeof(char) * (index));
    tmp2 = (char*) malloc(sizeof(char));
    number = (char *) malloc(sizeof(char) * (index));
    my_bzero(number, sizeof(char) * (index));
    my_bzero(tmp, sizeof(char) * (index));
    my_bzero(tmp2, sizeof(char) * 1);

    if (n < 0)
        n = n * (-1);
    while (indexb < indexc + 1) {
        if (n >= 10) {
            n = n / 10;
            n = (n % 10);
            tmp2[0] =  (n + '0');
            strcat(tmp, tmp2);
        } else {
            tmp2[0] =  (n + '0');
            strcat(tmp, tmp2);
        }
        // tmp[indexb] = n + '0';
        indexb++;
    }
    indexb = 0;
    while (indexc >= 0) {
        number[indexb] = tmp[indexc];
        indexb++;
        indexc--;
    }
    free(tmp);
    free(tmp2);
    number[indexb] = '\0';
    return (number);
}

char *my_put_nbr(int n) {
    int index;
    char *str;

    index = my_nb_len(n);
    str = my_putwnbr(n, index);
    return (str);
}