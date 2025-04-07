/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:36:00 by achu              #+#    #+#             */
/*   Updated: 2024/12/18 19:23:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_ischarset(char c, char set)
{
	return (c == set);
}

static int	ft_countword(const char *str, char set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_ischarset(str[i], set))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_ischarset(str[i], set))
			i++;
	}
	return (count);
}

static char	*ft_stralloc(const char *src, char set)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (src[len] != '\0' && !ft_ischarset(src[len], set))
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	clear_map(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(const char *str, char set)
{
	int		i;
	char	**split;

	i = 0;
	split = (char **)malloc((ft_countword(str, set) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && ft_ischarset(*str, set))
			str++;
		if (*str)
		{
			split[i] = ft_stralloc(str, set);
			if (!split[i])
				return (clear_map(split), NULL);
			i++;
		}
		while (*str && !ft_ischarset(*str, set))
			str++;
	}
	split[i] = 0;
	return (split);
}
