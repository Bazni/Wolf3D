/*
** test.c for graphic in /home/gwendal.bazin/C_Graphic
**
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
**
** Started on  Wed Nov 09 13:46:43 2016 Gwendal Bazin
** Last update Tue Jan 10 16:35:31 2017 Gwendal Bazin
*/

#include <stdlib.h>
#include "wolf3d.h"
#include "my.h"

void            window_destroy(t_window *window)
{
  frameBuffer_destroy(window->buffer);
  sfRenderWindow_destroy(window->window);
  sfTexture_destroy(window->texture);
  sfSprite_destroy(window->sprite);
}

void            window_draw(t_window *window)
{
  sfRenderWindow_clear(window->window, sfBlack);
  sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
  sfRenderWindow_display(window->window);
}

t_window      *window_create(int width, int height, char *title)
{
  t_window    *window;

  window = malloc(sizeof(t_window));
  window->mode.width = width;
  window->mode.height = height;
  window->mode.bitsPerPixel = 32;
  window->buffer = frameBuffer_create(width, height);
  window->texture = sfTexture_create(width, height);
  sfTexture_updateFromPixels(window->texture,
			     window->buffer->pixels, width, height, 0, 0);
  window->sprite = sfSprite_create();
  sfSprite_setTexture(window->sprite, window->texture, sfTrue);
  window->window = sfRenderWindow_create(window->mode, title,
					   sfResize | sfClose, NULL);
  if (window->window == NULL)
    return (NULL);
  return (window);
}
