/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:46:35 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 13:52:22 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_process_last(t_shell *shell)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(shell->cmd->cmd);
	dup2(shell->fd_in, STDIN_FILENO);
	close(shell->fd_in);
	close(shell->fd_out);
	execve(path_cmd, shell->cmd->cmd, shell->envp);
}

void	ft_process_last_out(t_shell *shell)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(shell->cmd->cmd);
	dup2(shell->fd_in, STDIN_FILENO);
	dup2(shell->fd_out, STDOUT_FILENO);
	close(shell->fd_in);
	close(shell->fd_out);
	execve(path_cmd, shell->cmd->cmd, shell->envp);
}

void	ft_close_two_sup(t_cmd *cmd)
{
	close(cmd->fd_pipe[cmd->k][0]);
	close(cmd->fd_pipe[cmd->k][1]);
}
