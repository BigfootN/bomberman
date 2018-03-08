/*
** my_strcat.c for  in /home/marc/test/devc/my_flt
** 
** Made by BORRAS Pierre-Marc
** Login   <borras_m@etna-alternance.net>
** 
** Started on  Fri Nov 11 09:13:39 2016 BORRAS Pierre-Marc
** Last update Fri Nov 11 09:14:02 2016 BORRAS Pierre-Marc
*/

#include "bomberman.h"

char	*my_strcat(char *dest, const char *src)
{
  int	index;

  index = my_strlen(dest);
  while (*src != '\0')
    {
      *(dest + index) = *src;
      src++;
      index++;
    }
  *(dest + index) = '\0';
  return (dest);
}
