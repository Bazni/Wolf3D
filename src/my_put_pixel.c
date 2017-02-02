/*
** my_put_pixel.c for my_put_pixel in /home/gwendal.bazin/wireframe/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
** 
** Started on  Mon Dec  5 16:16:06 2016 Gwendal Bazin
** Last update Tue Jan 10 14:49:55 2017 Gwendal Bazin
*/

#include "wolf3d.h"

void my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (x > 0 && y > 0 && x < framebuffer->width && y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
