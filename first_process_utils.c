/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:25:12 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:59 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_in_process(int fd_in, int fd_out, char **cmd, char **envp)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(cmd);
	dup2(fd_out, STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	close(fd_out);
	execve(path_cmd, cmd, envp);
}

void	ft_process_in_out(int *fd_redir, int **fd_pipe,
			char **commande, char **envp)
{
	close (fd_pipe[0][0]);
	close (fd_pipe[0][1]);
	ft_in_process(fd_redir[0], fd_redir[1], commande, envp);
	fd_redir[0] = 0;
}

void	ft_process_in(int *fd_redir, int **fd_pipe,
			char **commande, char **envp)
{
	close(fd_pipe[0][0]);
	ft_in_process(fd_redir[0], fd_pipe[0][1], commande, envp);
	fd_redir[0] = 0;
}

void	ft_process_out(int *fd_redir, int **fd_pipe,
			char **commande, char **envp)
{
	close(fd_pipe[0][1]);
	ft_no_in_process(fd_pipe[0][0], fd_redir[1], commande, envp);
}

int	ft_prob_infile(char **commande)
{
	ft_free_tab_simple(commande);
	exit(130);
}
