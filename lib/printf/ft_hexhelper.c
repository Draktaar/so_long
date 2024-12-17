/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexhelper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:51:36 by achu              #+#    #+#             */
/*   Updated: 2024/11/13 15:51:37 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexsize(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

char	*ft_hexalloc(unsigned long long nb)
{
	int		i;
	int		len;
	char	*dec;
	char	*hex;

	i = 0;
	len = ft_hexsize(nb);
	hex = "0123456789abcdef";
	dec = (char *)malloc((len + 1) * sizeof(char));
	if (!dec)
		return (NULL);
	while (i < len)
	{
		dec[len - i - 1] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	dec[len] = 0;
	return (dec);
}
