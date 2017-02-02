/*
** map_new.c for map_new in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Thu Dec 29 00:19:50 2016 Gwendal Bazin
** Last update Mon Jan  9 21:57:09 2017 Gwendal Bazin
*/

#include "my.h"
#include "wolf3d.h"

t_map		*map_read(int fd)
{
  long		x, y;
  ssize_t	len;
  char		buffer;
  t_map		*map;

  x = y = 0;
  map = map_create(x + 1, y + 1);
  while ((len = read(fd, &buffer, 1)) > 0)
    {
      if (len == -1)
	return (NULL);
      if (buffer != '\n')
	{
	  if (y >= map->width)
	    map = map_extend_width(map);
	  map->tab[x][y++] = buffer - '0';
	}
      else
	{
	  if (++x >= map->height)
	    map = map_extend_height(map);
	  y = 0;
	}
    }
  return (map);
}

t_map	*map_loop(char *path)
{
  int	fd;
  t_map	*map;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (NULL);
  map = map_read(fd);
  if (map == NULL)
    return (NULL);
  if (close(fd) == -1)
    return (NULL);
  return (map);
}
