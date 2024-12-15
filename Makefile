# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 11:01:59 by achu              #+#    #+#              #
#    Updated: 2024/12/15 17:51:04 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCDIR = src
INCLUDE = includes
LIBDIR = lib/minilibx-linux
LIBFT =  lib/libft
INCLUDES = -I$(LIBDIR)
LDFLAGS =  -L$(LIBDIR) -lmlx -lXext -lX11 -lm -lz
HEADERS = $(LIBFT)/libft.h $(INCLUDE)/so_long.h  $(INCLUDE)/sprite.h

SRC =	main.c \
		map_parser.c \
		input_handler.c \

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(OBJS) $(LIBFT)/libft.a $(LDFLAGS) $(INCLUDES) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(INCLUDES) -I $(LIBFT) -c $< -o $@

$(OBJS): $(HEADERS)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
