#include "headers.h"

void *my_memcpy(void *s1, const void *s2, size_t n)
{
    unsigned char *str1;
    unsigned char *str2;
    size_t i;

    i = 0;
    str1 = (unsigned char *) s1;
    str2 = (unsigned char *) s2;

    if (str1 == NULL || str2 == NULL)
        return (0);

    while (i < n)
    {
        str1[i] = str2[i];
        i++;
    }
    return (str1);
}

/* 
 * Allocation de mémoire pour une nouvelle chaîne, vide.
 * Correspondance Glib : g_string_new("").
 */

string_t *string_new(void)
{
    string_t *s;
    if (NULL != (s = malloc(sizeof *s)))
    {
        s->str = NULL;
        s->size = 0;
        s->len = 0;
    }
    return (s);
}

/* 
 * Allocation de mémoire pour une nouvelle chaîne,
 * avec préallocation d’un bloc de mémoire.
 * La chaîne est vide.
 * Correspondance Glib : g_string_new_len("", STRING_BLOCK_SIZE).
 */

/*string_t *string_new_initial_len(void)
{
    string_t *str;
    if (NULL != (str = malloc(sizeof *str)))
    {
        str->str = malloc(STRING_BLOCK_SIZE * sizeof *str->str);
        str->size = STRING_BLOCK_SIZE;
        str->len = 0;
    }
    return (str);
}*/

/* 
 * Libération de la mémoire allouée pour une chaîne
 * Correspondance Glib : g_string_free(str, TRUE).
 */

void string_free(string_t * str)
{
    if (str)
    {
        if (str->str)
            free(str->str);
        free(str);
    }
}
/* 
 * Concaténation d’une chaîne char* à une chaîne string_t
 */

/* 
 * Note : pour concaténer deux chaînes string_t, faire
 * string_ajout(resultat, chaine->str);
 * Correspondance Glib : g_string_append(str, str2).
 */

void string_ajout(string_t * str, const char *str2)
{
    int l;
    l = my_strlen(str2);
    if (str->size < (str->len + l + 1))
    {
        str->size = (1 + (str->size + l + 1) / STRING_BLOCK_SIZE) * STRING_BLOCK_SIZE;
        str->str = realloc(str->str, str->size * sizeof (*str->str));
    }
    my_memcpy(str->str + str->len, str2, l + 1);
    str->len += l;
}