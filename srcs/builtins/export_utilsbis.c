/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilsbis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:37:59 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 12:54:12 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_export_basic(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		shell->envp_sorted[i] = ft_strdup(shell->envp[i]);
		i++;
	}
	ft_sort_alpha(shell->envp_sorted);
	ft_printf_all(shell->envp_sorted);
	if (shell->cmd->args)
	{
		ft_sort_alpha(shell->cmd->args);
		ft_printf_all(shell->cmd->args);
	}
}

void	ft_export_basic_fd(t_shell *shell)
{
	if (shell->env)
	{
		ft_sort_alpha(shell->env);
		ft_write_all(shell);
	}
}

void	ft_export_new_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < ft_nbr_args(cmd->cmd_test))
	{
		cmd->new_arg[i] = ft_strdup(cmd->cmd_test[i + 1]);
		i++;
	}
}

void	ft_sort_new_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	ft_sort_alpha(cmd->new_arg);
	while (cmd->new_arg[i])
	{
		cmd->shell->env[i] = ft_strdup(cmd->new_arg[i]);
		i++;
	}
}