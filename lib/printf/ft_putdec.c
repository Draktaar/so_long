/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:24:03 by achu              #+#    #+#             */
/*   Updated: 2024/11/13 12:24:03 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_decsize(int nb)
{
	int	size;

	if (nb == 0)
		return (1);
	size = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		size *= 10;
	}
	return (size);
}

static int	ft_declen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_decalloc(int nb)
{
	int		i;
	int		len;
	int		size;
	char	*dec;

	i = 0;
	len = ft_declen(nb);
	size = ft_decsize(nb);
	dec = (char *)malloc((len + 1) * sizeof(char));
	if (!dec)
		return (NULL);
	if (nb < 0)
	{
		dec[i++] = '-';
		nb = -nb;
	}
	while (size != 0)
	{
		dec[i] = (nb / size) + '0';
		nb %= size;
		size /= 10;
		i++;
	}
	dec[i] = 0;
	return (dec);
}

int	ft_putdec(int nb)
{
	int		i;
	char	*dec;

	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	dec = ft_decalloc(nb);
	i = ft_putstr(dec);
	free(dec);
	return (i);
}
