/*
** window.h for window in /home/bazni/wolf3d/include
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Thu Dec 29 23:08:17 2016 Gwendal Bazin
** Last update Mon Jan  9 22:02:50 2017 Gwendal Bazin
*/

#ifndef WINDOW_H_
# define WINDOW_H_

# include "frame_buffer.h"

typedef struct		s_window
{
  sfUint8               windowWidth;
  sfUint8               windowHeight;
  sfVideoMode           mode;
  sfRenderWindow        *window;
  sfTexture             *texture;
  sfSprite              *sprite;
  t_my_framebuffer      *buffer;
}			t_window;

t_window	*window_create(int, int, char*);
void		window_destroy(t_window*);
void		window_draw(t_window*);

#endif
