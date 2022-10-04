/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:05:33 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:37:26 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_unset_change_var(char **tmp)
{
	int	i;

	g_var = ft_malloc_var(tmp);
	i = 0;
	while (ft_strcmp(tmp[i], "zzzzzz") != 0)
	{
		g_var[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_var[i] = NULL;
}

void	ft_big_else(int i)
{
	char	**tmp;

	free(g_var[i]);
	g_var[i] = ft_strdup("zzzzzz");
	ft_sort_alpha_bis();
	tmp = ft_malloc_tab(g_var);
	ft_cpy_tab(g_var, tmp);
	ft_free_tab_simple(g_var);
	ft_unset_change_var(tmp);
	ft_free_tab_simple(tmp);
}

void	ft_unset(char **cmd_test)
{
	int		i;
	int		j;
	char	*cmp;

	j = 0;
	if (!cmd_test[1])
		return ;
	while (cmd_test[++j])
	{
		i = 0;
		while (g_var[i])
		{
			cmp = ft_tmp_cmp(g_var, NULL, i);
			if (ft_strcmp(cmp, cmd_test[j]) != 0)
				i++;
			else
				ft_big_else(i);
			free(cmp);
		}
	}
}

void	ft_unset_export(char *cmd_test)
{
	int		i;
	char	*cmp;
	char	**split;

	split = ft_split(cmd_test, '=');
	i = 0;
	while (g_var[i])
	{
		cmp = ft_tmp_cmp(g_var, NULL, i);
		if (ft_strcmp(cmp, split[0]) != 0)
			i++;
		else
			ft_big_else(i);
		free(cmp);
	}
	ft_free_tab_simple(split);
}

void	ft_unset_multi(char **cmd_test)
{
	(void) cmd_test;
	exit (0);
}
