/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:47:24 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/08 14:41:02 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	if (!s)
		return (0);
	if (len > (ft_strlen(s)))
		len = (ft_strlen(s));
	dst = (char *)malloc(sizeof(*s) * (len + 1));
	if (dst == 0)
		return (0);
	while (s[i])
	{
		if (i >= (size_t)start && o < len)
		{
			dst[o] = s[i];
			o++;
		}
		i++;
	}
	dst[o] = '\0';
	return (dst);
}
