/*
** move.c for move in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Fri Jan  6 15:31:23 2017 Gwendal Bazin
** Last update Wed Jan 18 02:13:13 2017 Gwendal Bazin
*/

#include <unistd.h>
#include "wolf3d.h"
#include "my.h"

void	move(sfVector2f *pos, float *direction, t_map *map)
{
  sfVector2i	mapSize;

  mapSize.x = map->height;
  mapSize.y = map->width;
  if (sfKeyboard_isKeyPressed(sfKeyUp))
    if (raycast(*pos, *direction, map->tab, mapSize) > 1.0f)
      *pos = move_forward(*pos, *direction, MOVE_SPEED);
  if (sfKeyboard_isKeyPressed(sfKeyDown))
    if (raycast(*pos, *direction + 180.0f, map->tab, mapSize) > 0.8f)
      *pos = move_forward(*pos, *direction, -MOVE_SPEED);
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    *direction -= ROTA_SPEED;
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    *direction += ROTA_SPEED;
}
