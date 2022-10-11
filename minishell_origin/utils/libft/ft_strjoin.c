/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:44:52 by vferraro          #+#    #+#             */
/*   Updated: 2021/10/26 17:20:38 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		o;
	int		j;
	char	*dst;

	i = 0;
	o = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	dst = (char *)malloc(sizeof(*s1) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (dst == 0)
		return (NULL);
	while (s1[i])
	{
		dst[j++] = s1[i];
		i++;
	}
	while (s2[o])
	{
		dst[j++] = s2[o];
		o++;
	}
	dst[j] = '\0';
	return (dst);
}
