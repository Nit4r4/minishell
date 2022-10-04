/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:13:56 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:24 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_check_space_test(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isspace(str[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_cpy_tab(char **original, char **copy)
{
	int	i;

	i = 0;
	while (original[i])
	{
		copy[i] = ft_strdup(original[i]);
		i++;
	}
}

char	*ft_strjoin_modif_free(char *s1, char const s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		dst = malloc(2);
		dst[0] = s2;
		dst[1] = '\0';
		return (dst);
	}
	dst = malloc(ft_strlen(s1) + 2);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = s2;
	dst[i + 1] = '\0';
	free(s1);
	return (dst);
}
