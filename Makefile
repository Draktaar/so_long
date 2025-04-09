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

SRC =	engine/test.c \
		map/map_checker.c \
		map/map_parser.c \
		map/map_pathfinder.c \
		map/map_utils.c \
		setting/input_system.c \
		setting/window.c \
		setting/game_manager.c \
		graphic/pixel.c \
		graphic/render.c \
		graphic/sprite.c \
		level/level.c \
		player/player_controller.c \
		player/player_collision.c \
		player/player_movement.c \
		main.c

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	xset r off
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
