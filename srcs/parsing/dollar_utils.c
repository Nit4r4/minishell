/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:17:48 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_increase(int *i, int *len, char *str)
{
	while (ft_isalnum(str[*i]) == 1 || str[*i] == '|')
	{
		*i = *i + 1;
		*len = *len + 1;
	}
}

char	*ft_tmp(char **g_var, char *tmp_bis, int k)
{
	char	**split;
	char	*retour;

	(void) tmp_bis;
	split = ft_split(g_var[k], '=');
	retour = ft_strdup(split[1]);
	ft_free_tab_simple(split);
	return (retour);
}

char	*ft_tmp_cmp(char **g_var, char *tmp_bis, int k)
{
	char	**split;
	char	*retour;

	(void) tmp_bis;
	split = ft_split(g_var[k], '=');
	retour = ft_strdup(split[0]);
	ft_free_tab_simple(split);
	return (retour);
}

char	*ft_change_value(char *str, char **g_var, int start, int len)
{
	char	*tmp_bis;
	int		k;
	char	*tmp_cmp;

	tmp_bis = ft_substr(str, start, len);
	k = 0;
	while (g_var[k])
	{
		tmp_cmp = ft_tmp_cmp(g_var, tmp_bis, k);
		if (ft_strcmp(tmp_bis, tmp_cmp) != 0)
		{
			free (tmp_cmp);
			k++;
		}
		else
		{
			free (tmp_cmp);
			tmp_cmp = ft_tmp(g_var, tmp_bis, k);
			free (tmp_bis);
			return (tmp_cmp);
		}
	}
	free (tmp_bis);
	return (NULL);
}

void	ft_free_two(char *tmp_cmp, char *tmp_bis)
{
	free (tmp_cmp);
	free (tmp_bis);
}
