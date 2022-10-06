/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:31:10 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 13:28:40 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_unset_change_var(char **tmp)
{
	int	    i;
    t_shell *shell;

	shell->env = ft_malloc_var(tmp);
	i = 0;
	while (ft_strcmp(tmp[i], "zzzzzz") != 0)
	{
		shell->env[i] = ft_strdup(tmp[i]);
		i++;
	}
	shell->env[i] = NULL;
}

void	ft_big_else(int i)
{
	char	**tmp;
    t_shell *shell;

	free(shell->env[i]);
	shell->env[i] = ft_strdup("zzzzzz");
	ft_sort_alpha_bis();
	tmp = ft_malloc_tab(shell->env);
	ft_cpy_tab(shell->env, tmp);
	ft_free_tab_simple(shell->env);
	ft_unset_change_var(tmp);
	ft_free_tab_simple(tmp);
}

void	ft_unset(t_shell *shell)
{
	int		i;
	int		j;
	char	*cmp;

	j = 0;
	if (!shell->cmd->cmd_test[1])
		return ;
	while (shell->cmd->cmd_test[++j])
	{
		i = 0;
		while (shell->env[i])
		{
			cmp = ft_tmp_cmp(shell->env, NULL, i);
			if (ft_strcmp(cmp, shell->cmd->cmd_test[j]) != 0)
				i++;
			else
				ft_big_else(i);
			free(cmp);
		}
	}
}

void	ft_unset_export(t_shell *shell)
{
	int		i;
	char	*cmp;
	char	**split;

	split = ft_split(shell->cmd->cmd_test, '=');
	i = 0;
	while (shell->env[i])
	{
		cmp = ft_tmp_cmp(shell->env, NULL, i);
		if (ft_strcmp(cmp, split[0]) != 0)
			i++;
		else
			ft_big_else(i);
		free(cmp);
	}
	ft_free_tab_simple(split);
}

void	ft_unset_multi(t_shell *shell)
{
	(void) shell->cmd->cmd_test;
	exit (0);
}