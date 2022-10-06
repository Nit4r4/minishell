/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:25:12 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 14:16:29 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_in_process(t_shell *shell)
{
	char	*path_cmd;
	char	**cmd;

	cmd = shell->cmd->cmd;
	path_cmd = ft_error_cmd(cmd);
	dup2(shell->fd_out, STDOUT_FILENO);
	dup2(shell->fd_in, STDIN_FILENO);
	close(shell->fd_in);
	close(shell->fd_out);
	execve(path_cmd, cmd, shell->envp);
}

void	ft_process_in_out(t_cmd *cmd)
{
	close (cmd->fd_pipe[0][0]);
	close (cmd->fd_pipe[0][1]);
	ft_in_process(cmd->shell);
	cmd->fd_redir[0] = 0;
}

void	ft_process_in(t_cmd *cmd)
{
	ft_in_process(cmd->shell);
	cmd->fd_redir[0] = 0;
}

void	ft_process_out(t_cmd *cmd)
{
	close(cmd->fd_pipe[0][1]);
	ft_no_in_process(cmd->shell);
}

int	ft_prob_infile(t_cmd *cmd)
{
	ft_free_tab_simple(cmd->commande);
	exit(130);
}
