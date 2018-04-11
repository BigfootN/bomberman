/*
** my_strcmp.c for  in /home/marc/etna/rendu/devc/battle/final
** 
** Made by BORRAS Pierre-Marc
** Login   <borras_m@etna-alternance.net>
** 
** Started on  Sat Dec 10 22:54:49 2016 BORRAS Pierre-Marc
** Last update Sat Dec 10 22:54:55 2016 BORRAS Pierre-Marc
*/

#include "headers.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (-2);
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}

