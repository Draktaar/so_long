# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 11:01:59 by achu              #+#    #+#              #
#    Updated: 2025/01/07 15:35:27 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCDIR = src
INCLUDE = includes
LIBDIR = lib/minilibx-linux
LIBFT =  lib/libft
PRINTF =  lib/printf
INCLUDES = -I$(LIBDIR)
LDFLAGS =  -L$(LIBDIR) -lmlx -lXext -lX11 -lm -lz
HEADERS = $(LIBFT)/libft.h $(PRINTF)/ft_printf.h $(INCLUDE)/game.h  $(INCLUDE)/map.h  $(INCLUDE)/engine.h

SRC =	main.c \
		game_manager.c \
		input_handler.c \
		map_checker.c \
		map_parser.c \
		map_pathfinder.c \
		map_utils.c \
		player_movement.c \
		sprite.c \

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) $(OBJS) $(LIBFT)/libft.a $(PRINTF)/printf.a $(LDFLAGS) $(INCLUDES) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(INCLUDES) -I $(LIBFT) $(PRINTF) -c $< -o $@

$(OBJS): $(HEADERS)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(PRINTF)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(PRINTF)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
