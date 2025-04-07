/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:58:59 by achu              #+#    #+#             */
/*   Updated: 2025/04/06 01:31:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>

// *** Convertion ***
int		ft_atoi(const char *str);
char	*ft_itoa(int nb);

// *** Memory
int		ft_memcmp(const void *p1, const void *p2, size_t size);
void	*ft_memchr(const void *str, int find, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
void	*ft_memset(void *ptr, int value, size_t size);
void	ft_bzero(void *str, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	ft_freeptrs(void **tab);

// *** Character ***
int		is_alnum(int c);
int		is_alpha(int c);
int		is_ascii(int c);
int		is_digit(int c);
int		is_print(int c);
int		is_space(int c);
int		do_lower(int c);
int		do_upper(int c);

// *** String ***
size_t	ft_strlen(const char *str);
size_t	ft_arrlen(char **str);
size_t	ft_diclen(char ***str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	**ft_split(const char *str, char set);
char	*ft_strchr(const char *str, int find);
char	*ft_strdup(const char *src);
void	ft_striteri(const char *src, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str, const char *find, size_t len);
char	*ft_strrchr(const char *str, int cfind);
char	*ft_strtrim(const char *src, const char *set);
char	*ft_substr(const char *src, unsigned int pos, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_strnend(const char *str, char *find);

// *** GNL ***
char	*get_next_line(int fd);

#endif
