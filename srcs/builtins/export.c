/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:12:24 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 12:03:22 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_total_args_test(t_cmd *cmd, char **tmp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tmp[i])
	{
		g_var[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_var[i] = ft_strdup(cmd->new_arg);
}

void	ft_sort_args_test(t_cmd *cmd)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = ft_malloc_tab(g_var);
	while (g_var[i])
	{
		tmp[i] = ft_strdup(g_var[i]);
		i++;
	}
	ft_free_tab_simple(g_var);
	g_var = malloc((i + 2) * sizeof(char *));
	g_var[i + 1] = NULL;
	ft_total_args_test(tmp, cmd->new_args);
	ft_free_tab_simple(tmp);
}

void	ft_sub_export(char **cmd_test, int i)
{
	t_cmd	*cmd;

	cmd->new_arg = ft_strdup(cmd_test[i]);
	ft_sort_args_test(cmd->new_arg);
	free(cmd->new_arg);
}

void	ft_export_fd_test(t_shell *shell, char **g_var)
{
	int		nbr;
	int		i;

	i = 1;
	nbr = ft_nbr_args(shell->cmd->cmd_test);
	if (nbr == 0)
	{
		ft_export_basic_fd(shell->fd_out, g_var);
		exit (0);
	}
	while (shell->cmd->cmd_test[i])
	{
		if (shell->cmd->cmd_test[i][0] == '=')
		{
			printf ("not valid\n");
			ft_static(1);
		}
		else
		{
			ft_unset_export(shell->cmd->cmd_test[i]);
			ft_sub_export(shell->cmd->cmd_test, i);
		}
		i++;
	}
}

void	ft_export_fd_multi(t_shell *shell)
{
	if (ft_nbr_args(shell->cmd->cmd_test) == 0)
	{
		ft_export_basic_fd(shell->fd_out, shell->envp);
		exit (0);
	}
	if (ft_nbr_args(shell->cmd->cmd_test) > 0)
		exit (0);
}
