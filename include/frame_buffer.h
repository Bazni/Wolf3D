/*
** frame_buffer.h for frame_buffer in /home/bazni/wolf3d
** 
** Made by Gwendal Bazin
** Login   <gwendal.bazin@epitech.eu>
** 
** Started on  Fri Dec 30 20:40:57 2016 Gwendal Bazin
** Last update Tue Jan 10 14:19:54 2017 Gwendal Bazin
*/

#ifndef	FRAME_BUFFER_H_
# define FRAME_BUFFER_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>

typedef struct		 s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

void                    frameBuffer_clear(t_my_framebuffer *buffer);
t_my_framebuffer        *frameBuffer_create(int width, int height);
void			frameBuffer_destroy(t_my_framebuffer *buffer);

#endif
