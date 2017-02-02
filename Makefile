##
## Makefile for make in /home/gwendal.bazin/PSU_2016_my_ls
## 
## Made by Gwendal Bazin
## Login   <gwendal.bazin@epitech.net>
## 
## Started on  Sat Dec  3 22:47:42 2016 Gwendal Bazin
## Last update Tue Jan 10 18:24:19 2017 Gwendal Bazin
##


NAME		=	wolf3d

DIR		=	src/

SRC		=	$(DIR)map.c		\
			$(DIR)map_new.c		\
			$(DIR)my_draw_line.c	\
			$(DIR)raycast.c		\
			$(DIR)ray.c		\
			$(DIR)my_put_pixel.c	\
			$(DIR)window.c		\
			$(DIR)frame_buffer.c	\
			$(DIR)square.c		\
			$(DIR)wolf3d.c		\
			$(DIR)wall.c		\
			$(DIR)move_forward.c	\
			$(DIR)move.c

OBJ		= $(SRC:.c=.o)

CFLAGS		+= -Wall -Wextra -Wpedantic #-Werror
CFLAGS		+= -I./include/

CC		= gcc -g
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L./$(DIR)my/ -lmy -lc_graph_prog -lm

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
