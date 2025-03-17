/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:27:04 by achu              #+#    #+#             */
/*   Updated: 2025/03/17 17:36:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO42_H
# define STDIO42_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int 	ft_fprintf(int fd, const char *str, ...);
void	ft_perror(const char *s);

int		ft_putchar(char c, int fd);
int		ft_putstr(char *str, int fd);
int		ft_ptrtohex(void *ptr, int fd);
int		ft_putdec(int nb, int fd);
int		ft_putint(int nb, int fd);
int		ft_putudec(unsigned int nb, int fd);
int		ft_puthexlow(unsigned int nb, int fd);
int		ft_puthexup(unsigned int nb, int fd);
char	*ft_hexalloc(unsigned long long nb);

#endif
