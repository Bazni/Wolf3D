/*
** wall.c for wall in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Fri Jan  6 12:31:54 2017 Gwendal Bazin
** Last update Sun Jan 15 22:04:48 2017 Gwendal Bazin
*/

#include "wolf3d.h"
#include "my.h"

void            draw_wall(t_window *window, int x, float dist, sfColor color)
{
  int           lineheight;
  int           drawStart;
  int           drawEnd;
  sfVector2i    from;
  sfVector2i	to;

  lineheight = (int)((float)MY_HEIGHT / dist);
  drawStart = ((-lineheight) / 2) + MY_HEIGHT / 2;
  drawEnd = lineheight / 2 + MY_HEIGHT / 2;
  if (drawStart < 0)
    drawStart = 0;
  if (drawEnd >= MY_HEIGHT)
    drawEnd = MY_HEIGHT - 1;
  from.x = x;
  from.y = drawStart;
  to.x = x;
  to.y = drawEnd;
  my_draw_line(window->buffer, from, to, color);
}

void	       wall_loop(sfVector2f pos, float direction, t_window *window,
			 t_map *map)
{
  int		i;
  float		angle, alpha;
  sfVector2i	mapSize;
  float		dist;
  sfColor	color;

  mapSize.x = map->height;
  mapSize.y = map->width;
  i = 0;
  alpha = FOV / (float)MY_WIDTH;
  angle = direction - (FOV / 2.0f);
  while (i < MY_WIDTH)
    {
      dist = raycastt(pos, angle, map->tab, mapSize);
      if (dist < 0.0f)
	{
	  dist = dist * -1.0f;
	  color = sfColor_fromRGBA(153, 0, 0, 255);
	}
      else
	color = sfRed;
      draw_wall(window, i, dist, color);
      angle += alpha;
      i++;
    }
}

void	draw_env(t_window *window)
{
  long	sx, sy;
  long	cx, cy;

  sx = 0;
  while (sx < MY_WIDTH)
    {
      sy = MY_HEIGHT / 2;
      while (sy++ < MY_HEIGHT)
	{
	  my_put_pixel(window->buffer, sx, sy,
		       sfColor_fromRGBA(139, 69, 19, 255));
	}
      sx++;
    }
  cx = 0;
  while (cx < MY_WIDTH)
    {
      cy = 0;
      while (cy++ < MY_HEIGHT / 2)
	{
	  my_put_pixel(window->buffer, cx, cy,
		       sfColor_fromRGBA(0, 191, 255, 255));
	}
      cx++;
    }
}
