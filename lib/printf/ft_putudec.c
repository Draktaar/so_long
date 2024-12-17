/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:10:07 by achu              #+#    #+#             */
/*   Updated: 2024/11/13 16:10:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_udeclen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_udecalloc(unsigned int nb)
{
	int		i;
	int		len;
	char	*dec;

	i = 0;
	len = ft_udeclen(nb);
	dec = (char *)malloc((len + 1) * sizeof(char));
	if (!dec)
		return (NULL);
	while (i < len)
	{
		dec[len - i - 1] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	dec[len] = 0;
	return (dec);
}

int	ft_putudec(unsigned int nb)
{
	int		i;
	char	*udec;

	udec = ft_udecalloc(nb);
	i = ft_putstr(udec);
	free(udec);
	return (i);
}
