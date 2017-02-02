/*
** raycast.h for raycast in /home/bazni/wolf3d
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Sat Jan  7 12:53:39 2017 Gwendal Bazin
** Last update Mon Jan  9 22:03:55 2017 Gwendal Bazin
*/

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct	s_ray
{
  float		raydirx;
  float		raydiry;
  int		mapx;
  int		mapy;
  float		deltadistx;
  float		deltadisty;
  char		hit;
  char		side;
  char          stepx;
  char		stepy;
}               t_ray;

#endif
