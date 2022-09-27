/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:46:35 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:39 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_process_last(int fd_in, int fd_out, char **cmd, char **envp)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(cmd);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	close(fd_out);
	execve(path_cmd, cmd, envp);
}

void	ft_process_last_out(int fd_in, int fd_out, char **cmd, char **envp)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(cmd);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	execve(path_cmd, cmd, envp);
}

void	ft_close_two_sup(int **fd_pipe, int k)
{
	close(fd_pipe[k][0]);
	close(fd_pipe[k][1]);
}
