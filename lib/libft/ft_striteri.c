/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:24:47 by achu              #+#    #+#             */
/*   Updated: 2024/11/06 15:24:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(const char *src, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		(*f)(i, (char *)src + i);
		i++;
	}
}
