/*
** my_draw_line.c for draw_line in /home/gwendal.bazin/C_Graphic
**
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
**
** Started on  Tue Nov 15 15:42:26 2016 Gwendal Bazin
** Last update Mon Jan  9 21:54:02 2017 Gwendal Bazin
*/

#include "wolf3d.h"

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int	dx;
  int	sx;
  int	dy;
  int	sy;
  int	err;
  int	e2;

  dx = abs(to.x - from.x);
  sx = from.x < to.x ? 1 : -1;
  dy = abs(to.y - from.y);
  sy = from.y < to.y ? 1 : -1;
  err = (dx > dy ? dx : -dy) / 2;
  while (1)
    {
      my_put_pixel(framebuffer, from.x, from.y, color);
      if (from.x == to.x && from.y == to.y)
	break;
      e2 = err;
      e2 > -dx ? err -= dy : 0;
      e2 > -dx ? from.x += sx : 0;
      e2 < dy ? err += dx : 0;
      e2 < dy ? from.y += sy : 0;
    }
}
