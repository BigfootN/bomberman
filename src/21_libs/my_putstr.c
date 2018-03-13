/*
** my_putstr.c for  in /home/marc/etna/rendu/devc/battle/final
** 
** Made by BORRAS Pierre-Marc
** Login   <borras_m@etna-alternance.net>
** 
** Started on  Sat Dec 10 22:54:25 2016 BORRAS Pierre-Marc
** Last update Sat Dec 10 22:54:32 2016 BORRAS Pierre-Marc
*/

#include "bomberman.h"

void	my_putstr(const char *str)
{
  while (*str != '\0')
    my_putchar(*str++);
}
