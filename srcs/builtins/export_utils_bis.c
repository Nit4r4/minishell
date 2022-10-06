/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:41:39 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 11:35:13 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_export_basic(t_shell *shell, char **envp_sorted)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		envp_sorted[i] = ft_strdup(shell->envp[i]);
		i++;
	}
	ft_sort_alpha(envp_sorted);
	ft_printf_all(envp_sorted);
	if (shell->cmd->args)
	{
		ft_sort_alpha(shell->cmd->args);
		ft_printf_all(shell->cmd->args);
	}
}

void	ft_export_basic_fd(int fd_out, char **g_var)
{
	if (g_var)
	{
		ft_sort_alpha(g_var);
		ft_write_all(fd_out, g_var);
	}
}

void	ft_export_new_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < ft_nbr_args(cmd->cmd_test))
	{
		cmd->new_args[i] = ft_strdup(cmd->cmd_test[i + 1]);
		i++;
	}
}

void	ft_sort_new_args(t_cmd *cmd)
{
	int	i;

	i = 0;
	ft_sort_alpha(cmd->new_args);
	while (cmd->new_args[i])
	{
		g_var[i] = ft_strdup(cmd->new_args[i]);
		i++;
	}
}
