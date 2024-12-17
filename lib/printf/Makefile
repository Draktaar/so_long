# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 11:11:29 by achu              #+#    #+#              #
#    Updated: 2024/12/17 15:50:40 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
INCDIR = includes

SRC =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_ptrtohex.c \
		ft_putdec.c \
		ft_putint.c \
		ft_putudec.c \
		ft_puthexup.c \
		ft_puthexlow.c \
		ft_hexhelper.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
