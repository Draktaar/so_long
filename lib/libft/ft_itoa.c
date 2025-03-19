/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:17:28 by achu              #+#    #+#             */
/*   Updated: 2024/12/12 13:37:44 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoalen(int nb)
{
	int	i;

	i = 0;
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

static char	*totoa(char *totoa, int nb)
{
	int	i;
	int	sign;
	int	len;

	i = 0;
	sign = 1;
	len = itoalen(nb);
	if (nb < 0)
	{
		nb = -nb;
		sign = -sign;
	}
	while (nb > 0)
	{
		totoa[len - i - 1] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (sign < 0)
		totoa[len - i - 1] = '-';
	totoa[len] = 0;
	return (totoa);
}

char	*ft_itoa(int nb)
{
	char	*itoa;

	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	itoa = (char *)malloc((itoalen(nb) + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa = totoa(itoa, nb);
	return (itoa);
}
