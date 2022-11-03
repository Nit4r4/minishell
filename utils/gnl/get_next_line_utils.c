/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:52:13 by vferraro          #+#    #+#             */
/*   Updated: 2022/01/25 13:49:03 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return ((char *)str + i);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*src;
	char	*dst;
	size_t	count;

	dst = malloc(len + 1);
	if (!dst)
	{
		return (0);
	}
	if (dst == 0)
		return (0);
	src = (char *)str + start;
	count = 0;
	while (*src && count < len)
	{
		dst[count] = *src;
		src++;
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	stock;
	size_t	len;
	char	*res;

	len = ft_strlen(str1) + ft_strlen(str2);
	res = malloc(len + 1);
	if (!res)
		return (0);
	stock = 0;
	while (*str1)
	{
		res[stock] = *str1;
		stock++;
		str1++;
	}
	while (*str2)
	{
		res[stock] = *str2;
		stock++;
		str2++;
	}
	res[stock] = '\0';
	return (res);
}
