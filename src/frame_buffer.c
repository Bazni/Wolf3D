/*
** frame_buffer.c for wireframe in /home/swann/Repos/wireframe/src/
**
** Made by Swann Jaunasse
** Login   <swann.jaunasse@epitech.eu>
**
** Started on  Tue Dec  6 00:54:50 2016 Swann Jaunasse
** Last update Tue Jan 10 14:34:57 2017 Gwendal Bazin
*/

#include "wolf3d.h"

void                    frameBuffer_clear(t_my_framebuffer *buffer)
{
  int			count;

  count = 0;
  while (count < buffer->width * buffer->height * 4)
    {
      buffer->pixels[count] = 0;
      count++;
    }
}

t_my_framebuffer        *frameBuffer_create(int width, int height)
{
  t_my_framebuffer      *buffer;

  buffer = malloc(sizeof(t_my_framebuffer));
  buffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
  if (buffer->pixels == NULL || buffer == NULL)
    return (NULL);
  buffer->width = width;
  buffer->height = height;
  frameBuffer_clear(buffer);
  return (buffer);
}

void			frameBuffer_destroy(t_my_framebuffer *buffer)
{
  free(buffer->pixels);
}
