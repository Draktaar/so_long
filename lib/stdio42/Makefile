# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 11:11:29 by achu              #+#    #+#              #
#    Updated: 2025/04/07 16:30:36 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = stdio42.a

SRC =	ft_putchar.c \
		ft_putstr.c \
		ft_ptrtohex.c \
		ft_putdec.c \
		ft_putint.c \
		ft_putudec.c \
		ft_puthexup.c \
		ft_puthexlow.c \
		ft_hexhelper.c \
		ft_perror.c \
		ft_fprintf.c \
		ft_printf.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
