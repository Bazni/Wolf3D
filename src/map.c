/*
** map.c for map in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Thu Dec 29 00:12:07 2016 Gwendal Bazin
** Last update Thu Jan  5 16:00:45 2017 Gwendal Bazin
*/

#include "my.h"
#include "wolf3d.h"

t_map   *map_create(long height, long width)
{
  t_map	*map;
  long  x;
  long  y;

  if ((map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  map->width = width;
  map->height = height;
  if ((map->tab = malloc(sizeof(int*) * height)) == NULL)
    return (NULL);
  x = 0;
  while (x < height)
    {
      if ((map->tab[x] = malloc(sizeof(int) * width)) == NULL)
	return (NULL);
      y = 0;
      while (y < width)
	{
	  map->tab[x][y] = ' ';
	  y++;
	}
      x++;
    }
  return (map);
}

void	map_destroy(t_map *map)
{
  long	count;

  count = 0;
  while (count < map->height)
    {
      free(map->tab[count]);
      count++;
    }
  free(map->tab);
  free(map);
}

t_map	*map_extend_width(t_map *map)
{
  t_map	*tmp;
  long	x;
  long	y;

  x = 0;
  tmp = map_create(map->height, map->width + 1);
  while (x < map->height)
    {
      y = 0;
      while (y < map->width)
	{
	  tmp->tab[x][y] = map->tab[x][y];
	  y++;
	}
      x++;
    }
  map_destroy(map);
  return (tmp);
}

t_map	*map_extend_height(t_map *map)
{
  t_map	*tmp;
  long  x;
  long  y;

  x = 0;
  tmp = map_create(map->height + 1, map->width);
  while (x < map->height)
    {
      y = 0;
      while (y < map->width)
	{
	  tmp->tab[x][y] = map->tab[x][y];
	  y++;
	}
      x++;
    }
  map_destroy(map);
  return (tmp);
}
