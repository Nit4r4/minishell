/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:59:08 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:01:32 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_process_middle_bis(t_shell *shell)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(shell->cmd->cmd);
	dup2(shell->fd_in, STDIN_FILENO);
	dup2(shell->fd_out, STDOUT_FILENO);
	close(shell->fd_in);
	close(shell->fd_out);
	execve(path_cmd, shell->cmd->cmd, shell->envp);
}

void	ft_close_because_too_long(t_cmd *cmd)
{
	close(cmd->fd_pipe[cmd->k][0]);
	close(cmd->fd_pipe[cmd->k + 1][1]);
}

void	ft_execute_mid(t_cmd *cmd)
{
	cmd->k = ft_static_multi(100);
	if (cmd->fd_redir[0] > 0 && cmd->fd_redir[1] > 0)
	{
		ft_close_because_too_long(cmd);
		ft_process_middle_bis(cmd->shell);
	}
	else if (cmd->fd_redir[0] > 0 && cmd->fd_redir[1] == 0)
	{
		close(cmd->fd_pipe[cmd->k][0]);
		ft_process_middle_bis(cmd->shell);
	}
	else if (cmd->fd_redir[0] == 0 && cmd->fd_redir[1] > 0)
	{
		close(cmd->fd_pipe[cmd->k + 1][1]);
		ft_process_middle_bis(cmd->shell);
	}
	else if (cmd->fd_redir[0] == 0 && cmd->fd_redir[1] == 0)
		ft_process_middle_bis(cmd->shell);
	else if (cmd->fd_redir[0] < 0)
	{
		ft_free_tab_simple(cmd->commande);
		exit(130);
	}
}

void	ft_inbuilts_mid(t_cmd *cmd)
{
	cmd->k = ft_static_multi(100);
	if (cmd->fd_redir[1] == 0)
	{
		close(cmd->fd_pipe[cmd->k][0]);
		ft_execute_inbuilt_fd_multi(cmd);
	}
	else
	{
		close(cmd->fd_pipe[k][0]);
		close(cmd->fd_pipe[k][1]);
		ft_execute_inbuilt_fd_multi(cmd);
	}
}

void	ft_middle_process(t_cmd *cmd, int i)
{
	char	**split_space;

	cmd->fd_redir = malloc(2 * sizeof(int));
	cmd->fd_redir[0] = 0;
	cmd->fd_redir[1] = 0;
	ft_static_multi(i - 1);
	split_space = ft_split_modif(split_pipe[i], ' ',
			ft_code_char(split_pipe[i]));
	cmd->commande = ft_malloc_tab(split_space);
	ft_check_redir(cmd);
	if (ft_check_builtins(cmd->commande) == 0)
		ft_execute_mid(cmd);
	else
		ft_inbuilts_mid(cmd);
}
