/*
** move_forward.c for move_forward in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Fri Jan  6 14:02:19 2017 Gwendal Bazin
** Last update Fri Jan  6 15:21:06 2017 Gwendal Bazin
*/

#include "wolf3d.h"
#include "my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  float		dirx;
  float		diry;

  dirx = cosf(direction * (float)M_PI / 180.0f);
  diry = sinf(direction * (float)M_PI / 180.0f);
  pos.x += dirx * distance;
  pos.y += diry * distance;
  return (pos);
}
