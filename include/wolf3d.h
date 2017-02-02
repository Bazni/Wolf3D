/*
** wire.h for wire in /home/gwendal.bazin/wireframe/include
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.net>
** 
** Started on  Mon Dec  5 16:21:47 2016 Gwendal Bazin
** Last update Wed Jan 18 02:14:05 2017 Gwendal Bazin
*/

#ifndef WOLF3D_H_
# define WOLF3D_H

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "window.h"
# include "raycast.h"

# define MY_WIDTH	900
# define MY_HEIGHT      500
# define FOV		66.6f
# define MOVE_SPEED	0.09f
# define ROTA_SPEED	2.0f

typedef struct		s_map
{
  int			**tab;
  int			width;
  int			height;
}			t_map;

void			my_draw_line(t_my_framebuffer*, sfVector2i, sfVector2i,
				     sfColor);
void			my_put_pixel(t_my_framebuffer*, int x, int y, sfColor);

t_map			*map_create(long, long);
void			map_destroy(t_map*);
t_map			*map_extend_width(t_map*);
t_map			*map_extend_height(t_map*);

t_map			*map_read(int);
t_map			*map_loop(char*);

void			draw_square(t_my_framebuffer*, size_t, size_t, sfColor);
void			draw_wall(t_window*, int, float, sfColor);
void			wall_loop(sfVector2f, float, t_window*, t_map*);
void			draw_env(t_window*);
void			draw_map(t_window*, t_map*);
float			raycast(sfVector2f, float, int**, sfVector2i);
float			raycastt(sfVector2f, float, int**, sfVector2i);

void			move(sfVector2f*, float*, t_map*);
sfVector2f		move_forward(sfVector2f, float, float);

#endif
