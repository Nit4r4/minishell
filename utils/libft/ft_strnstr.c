/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:19:39 by vferraro          #+#    #+#             */
/*   Updated: 2021/10/23 14:48:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	o;
	size_t	nlen;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	nlen = ft_strlen(needle);
	if (nlen == 0 || haystack == needle)
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		o = 0;
		while (hay[i + o] != '\0' && needle[o] != '\0'
			&& hay[i + o] == needle[o] && i + o < len)
			o++;
		if (o == nlen)
			return (hay + i);
		i++;
	}
	return (0);
}
