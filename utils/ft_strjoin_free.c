/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:14:13 by creyt             #+#    #+#             */
/*   Updated: 2022/10/20 13:18:22 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	i;
	size_t	y;
	char	*dest;

	i = 0;
	if (!s1 || !s2)
		return (0);
	dest = malloc (sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (0);
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	y = 0;
	while (y < ft_strlen(s2))
	{
		dest[i] = s2[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	free((char *)s1);
	return (dest);
}
