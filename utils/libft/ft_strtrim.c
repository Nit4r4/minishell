/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 08:59:57 by vferraro          #+#    #+#             */
/*   Updated: 2021/10/27 15:03:53 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_setsize(char c, const char *set)
	{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	up;
	size_t	down;

	if (!s1)
		return (0);
	up = 0;
	while (s1[up] && ft_setsize(s1[up], set))
		up++;
	down = ft_strlen(s1);
	while (down > up && ft_setsize(s1[down - 1], set))
		down--;
	str = (char *)malloc(sizeof(*s1) * ((down - up) + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (up < down)
	{
		str[i] = s1[up];
		i++;
		up++;
	}
	str[i] = '\0';
	return (str);
}
