# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achu <achu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 11:00:14 by achu              #+#    #+#              #
#    Updated: 2025/04/06 01:46:59 by achu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

CONV_SRC =	ft_atoi.c \
			ft_itoa.c
MEM_SRC =	ft_bzero.c \
			ft_calloc.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_realloc.c \
			ft_freeptrs.c
CHAR_SRC =	do_lower.c \
			do_upper.c \
			is_alnum.c \
			is_alpha.c \
			is_ascii.c \
			is_digit.c \
			is_print.c \
			is_space.c
STR_SRC =	ft_split.c \
			ft_strcat.c \
			ft_strcpy.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_arrlen.c \
			ft_diclen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strnend.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c
GNL_SRC = 	get_next_line.c

CONV_OBJS =	$(addprefix convertion/, $(CONV_SRC:.c=.o))
MEM_OBJS =	$(addprefix memory/, $(MEM_SRC:.c=.o))
CHAR_OBJS =	$(addprefix character/, $(CHAR_SRC:.c=.o))
STR_OBJS =	$(addprefix string/, $(STR_SRC:.c=.o))
GNL_OBJS =	$(addprefix gnl/, $(GNL_SRC:.c=.o))

OBJS = $(CONV_OBJS) $(MEM_OBJS) $(CHAR_OBJS) $(STR_OBJS) $(GNL_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@
	
clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
