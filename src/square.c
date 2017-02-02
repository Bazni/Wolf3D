/*
** square.c for square in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Thu Dec 29 22:58:43 2016 Gwendal Bazin
** Last update Mon Jan  2 13:20:55 2017 Gwendal Bazin
*/

#include "wolf3d.h"

void draw_square(t_my_framebuffer *buffer, size_t x, size_t y, sfColor color)
{
  size_t	tmpx;
  size_t	tmpy;

  tmpx = x;
  while (tmpx < x + 20)
    {
      tmpy = y;
      while (tmpy < y + 20)
	{
	  my_put_pixel(buffer, tmpx, tmpy, color);
	  tmpy++;
	}
      tmpx++;
    }
}
