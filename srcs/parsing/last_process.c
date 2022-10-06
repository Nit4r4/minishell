/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:46:35 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:05:26 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_execute_last(t_cmd *cmd)
{
	cmd->k = ft_static_multi(100);
	if (cmd->fd_redir[0] == 0 && cmd->fd_redir[1] == 0)
		ft_process_last(cmd->shell);
	else if (cmd->fd_redir[0] > 0 && cmd->fd_redir[1] == 0)
	{
		close(cmd->fd_pipe[cmd->k][0]);
		ft_process_last(cmd->shell);
	}
	else if (cmd->fd_redir[0] == 0 && cmd->fd_redir[1] > 0)
	{
		close(cmd->fd_pipe[cmd->k][1]);
		ft_process_last_out(cmd->shell);
	}
	else if (cmd->fd_redir[0] > 0 && cmd->fd_redir[1] > 1)
	{
		ft_close_two_sup(cmd);
		ft_process_last_out(cmd->shell);
	}
	else if (cmd->fd_redir[0] < 0)
	{
		ft_free_tab_simple(cmd->commande);
		exit(130);
	}
}

void	ft_inbuilts_last(t_cmd *cmd)
{
	cmd->k = ft_static_multi(100);
	if (cmd->fd_redir[1] == 0)
	{
		close(cmd->fd_pipe[cmd->k][0]);
		close(cmd->fd_pipe[cmd->k][1]);
		ft_execute_inbuilt_fd_multi(0, cmd->commande, cmd->shell->envp);
	}
	else
	{
		close(cmd->fd_pipe[cmd->k][0]);
		close(cmd->fd_pipe[cmd->k][1]);
		ft_execute_inbuilt_fd_multi(cmd);
	}
}

void	ft_last_process(t_cmd *cmd, int i)
{
	char	**split_space;

	cmd->fd_redir = malloc(2 * sizeof(int));
	cmd->fd_redir[0] = 0;
	cmd->fd_redir[1] = 0;
	ft_static_multi(i - 1);
	split_space = ft_split_modif(cmd->split_pipe[i], ' ',
			ft_code_char(cmd->split_pipe[i]));
	cmd->commande = ft_malloc_tab(split_space);
	ft_check_redir(cmd);
	if (ft_check_builtins(cmd->commande) == 0)
		ft_execute_last(cmd);
	else
		ft_inbuilts_last(cmd);
}
