/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:58:59 by achu              #+#    #+#             */
/*   Updated: 2025/03/18 01:19:07 by achu             ###   ########.fr       */
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

//*** Libft functions ***
int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_freeptrs(void **tab);
char	*ft_itoa(int nb);
void	*ft_memchr(const void *str, int find, size_t size);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
void	*ft_memset(void *ptr, int value, size_t size);
char	**ft_split(const char *str, char set);
char	*ft_strchr(const char *str, int find);
char	*ft_strdup(const char *src);
void	ft_striteri(const char *src, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlen_dbl(char **str);
size_t	ft_strlen_trpl(char ***str);
char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strnstr(const char *str, const char *find, size_t len);
char	*ft_strrchr(const char *str, int cfind);
int 	ft_strrend(const char *str, char *find);
char	*ft_strtrim(const char *src, const char *set);
char	*ft_substr(const char *src, unsigned int pos, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// *** is_bool ***
int		is_alnum(int c);
int		is_alpha(int c);
int		is_ascii(int c);
int		is_digit(int c);
int		is_print(int c);
int		is_space(int c);

// *** Get_next_line function ***
char	*get_next_line(int fd);

#endif
