/*
** wolf3d.c for wolf in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Thu Dec 29 00:46:34 2016 Gwendal Bazin
** Last update Wed Jan 18 02:13:29 2017 Gwendal Bazin
*/

#include "my.h"
#include "wolf3d.h"

void            window_loop(t_window *window, t_map *map)
{
  sfEvent       event;
  sfVector2f	pos;
  float		direction;

  pos.x = 5.5f;
  pos.y = 5.5f;
  direction = 90.0f;
  while (sfRenderWindow_isOpen(window->window))
    {
      while (sfRenderWindow_pollEvent(window->window, &event))
	{
	  if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
	    sfRenderWindow_close(window->window);
	}
      move(&pos, &direction, map);
      frameBuffer_clear(window->buffer);
      draw_env(window);
      wall_loop(pos, direction, window, map);
      window_draw(window);
      sfTexture_updateFromPixels(window->texture, window->buffer->pixels,
				 window->buffer->width, window->buffer->height, 0, 0);
    }
}

int		main(int ac, char **av)
{
  t_map         *map;
  t_window	*window;

  if (ac != 2)
    return (84);
  map = map_loop(av[1]);
  if (map == NULL)
    return (84);
  window = window_create(MY_WIDTH, MY_HEIGHT, "Wolf3d");
  if (window == NULL)
    return (84);
  window_loop(window, map);
  window_destroy(window);
  return (0);
}
