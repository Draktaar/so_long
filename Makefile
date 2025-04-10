# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 11:01:59 by achu              #+#    #+#              #
#    Updated: 2025/03/17 17:39:55 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -g3
NAME = so_long

SRCDIR = src
INCDIR = inc

LIBFT =		lib/libft
STDIO42 =	lib/stdio42
MLIBX = 	lib/minilibx-linux

LDFLAGS =  -L$(MLIBX) -lmlx -lXext -lX11 -lm -lz
HEADERS = $(INCDIR)/engine.h $(INCDIR)/game.h $(INCDIR)/map.h $(LIBFT)/libft.h $(STDIO42)/stdio42.h

SRC =	test/banner.c \
		engine/collision.c \
		engine/input_system.c \
		engine/window.c \
		engine/game.c \
		map/map_checker.c \
		map/map_parser.c \
		map/map_pathfinder.c \
		map/map_utils.c \
		graphic/debug.c \
		graphic/image.c \
		graphic/pixel.c \
		graphic/render.c \
		object/player/player_controller.c \
		object/player/player_collision.c \
		object/player/player_movement.c \
		object/berry.c \
		object/solid.c \
		object/spike.c \
		main.c

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	xset r on
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(STDIO42)
	@$(CC) $(OBJS) $(LIBFT)/libft.a $(STDIO42)/stdio42.a $(LDFLAGS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -I $(MLIBX) -I $(LIBFT) -I $(STDIO42) -c $< -o $@

$(OBJS): $(HEADERS)

clean:
	@$(MAKE) clean -C $(LIBFT)
	@$(MAKE) clean -C $(STDIO42)
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(STDIO42)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
