/*
** my_strlen.c for strlen in /home/gwendal.bazin/CPool_Day04
**
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
**
** Started on  Thu Oct  6 11:34:39 2016 Gwendal Bazin
** Last update Mon Oct 10 10:20:07 2016 Gwendal Bazin
*/

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
