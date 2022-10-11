/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:47:32 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/08 14:32:00 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	stringlenght;

	stringlenght = 0;
	while (s[stringlenght] != '\0')
	{
		stringlenght++;
	}
	return (stringlenght);
}
