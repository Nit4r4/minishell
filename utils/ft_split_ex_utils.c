/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:57:59 by creyt             #+#    #+#             */
/*   Updated: 2022/10/25 13:58:42 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_qts_split(char *s, int i, char c)
{
	if (s[i] == c)
	{
		i++;
		while (s[i] != c)
		{
			if (!s[i])
				return (NO_RESULT);
			i++;
			if ((s[i] == c && s[i + 1] == ' ')
				|| (s[i] == c && s[i + 1] == '\0')
				|| (s[i] == c && s[i + 1] == '|'))
				return (i);
		}
		if (s[i] == c && s[i + 1] != ' ')
		{
			while (i < (int) ft_strlen(s) && s[i] != ' ')
				i++;
		}
	}
	return (i);
}
