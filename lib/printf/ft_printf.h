/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:27:04 by achu              #+#    #+#             */
/*   Updated: 2024/11/13 11:27:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_format(va_list args, const char conv);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_ptrtohex(void *ptr);
int		ft_putdec(int nb);
int		ft_putint(int nb);
int		ft_putudec(unsigned int nb);
int		ft_puthexlow(unsigned int nb);
int		ft_puthexup(unsigned int nb);
char	*ft_hexalloc(unsigned long long nb);

#endif
