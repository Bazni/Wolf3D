/*
** raycast.c for raycast in /home/bazni/wolf3d/src
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Thu Dec 29 00:10:34 2016 Gwendal Bazin
** Last update Tue Jan 10 13:21:24 2017 Gwendal Bazin
*/

#include "wolf3d.h"

void	set(t_ray *ray, sfVector2f pos, float direction)
{
  ray->raydirx = cosf(direction * M_PI / 180.0f);
  ray->raydiry = sinf(direction * M_PI / 180.0f);
  ray->mapx = (int)pos.x;
  ray->mapy = (int)pos.y;
  ray->deltadistx = sqrt(1 + (ray->raydiry * ray->raydiry) /
			 (ray->raydirx * ray->raydirx));
  ray->deltadisty = sqrt(1 + (ray->raydirx * ray->raydirx) /
			 (ray->raydiry * ray->raydiry));
  ray->hit = 0;
  ray->side = 0;
}

void	hit(sfVector2i mapSize, t_ray *ray, sfVector2f *sidedist, int **map)
{
  while (!ray->hit)
    {
      if (sidedist->x < sidedist->y)
	{
	  sidedist->x += ray->deltadistx;
	  ray->mapx += ray->stepx;
	  ray->side = 0;
	}
      else
	{
	  sidedist->y += ray->deltadisty;
	  ray->mapy += ray->stepy;
	  ray->side = 1;
	}
      if (ray->mapx >= mapSize.x || ray->mapy >= mapSize.y ||
	  ray->mapx < 0 || ray->mapy < 0)
	ray->hit = 1;
      else if (map[ray->mapy][ray->mapx] > 0)
	ray->hit = 1;
    }
}

void	calc_dir(t_ray *ray, sfVector2f *sidedist, sfVector2f pos)
{
  if (ray->raydirx < 0)
    {
      ray->stepx = -1;
      sidedist->x = (pos.x - ray->mapx) * ray->deltadistx;
    }
  else
    {
      ray->stepx = 1;
      sidedist->x = (ray->mapx + 1.0f - pos.x) * ray->deltadistx;
    }
  if (ray->raydiry < 0)
    {
      ray->stepy = -1;
      sidedist->y = (pos.y - ray->mapy) * ray->deltadisty;
    }
  else
    {
      ray->stepy = 1;
      sidedist->y = (ray->mapy + 1.0f - pos.y) * ray->deltadisty;
    }
}

float		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapSize)
{
  t_ray		ray;
  sfVector2f	sidedist;
  float		perpWallDist;

  set(&ray, pos, direction);
  calc_dir(&ray, &sidedist, pos);
  hit(mapSize, &ray, &sidedist, map);
  if (ray.side == 0)
    perpWallDist = (ray.mapx - pos.x + (1 - ray.stepx) / 2) / ray.raydirx;
  else
    perpWallDist = (ray.mapy - pos.y + (1 - ray.stepy) / 2) / ray.raydiry;
  return (perpWallDist);
}
