#include "headers.h"

char *my_strdup(const char *s1)
{
    char *tab;
    int total;

    total = my_strlen(s1);
    tab = (char*) malloc(sizeof (char) * (total + 1));
    if (tab == NULL)
        return (NULL);
    while (*s1 != '\0')
        *tab++ = *s1++;
    *tab = '\0';
    return (tab - total);
}