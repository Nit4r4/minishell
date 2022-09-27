/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:59:08 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:29 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_process_middle_bis(int fd_in, int fd_out, char **cmd, char **envp)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(cmd);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	execve(path_cmd, cmd, envp);
}

void	ft_close_because_too_long(int **fd_pipe, int k)
{
	close(fd_pipe[k][0]);
	close(fd_pipe[k + 1][1]);
}

void	ft_execute_mid(int *fd_redir, int **fd_pipe,
		char **commande, char **envp)
{
	int	k;

	k = ft_static_multi(100);
	if (fd_redir[0] > 0 && fd_redir[1] > 0)
	{
		ft_close_because_too_long(fd_pipe, k);
		ft_process_middle_bis(fd_redir[0], fd_redir[1], commande, envp);
	}
	else if (fd_redir[0] > 0 && fd_redir[1] == 0)
	{
		close(fd_pipe[k][0]);
		ft_process_middle_bis(fd_redir[0], fd_pipe[k + 1][1], commande, envp);
	}
	else if (fd_redir[0] == 0 && fd_redir[1] > 0)
	{
		close(fd_pipe[k + 1][1]);
		ft_process_middle_bis(fd_pipe[k][0], fd_redir[1], commande, envp);
	}
	else if (fd_redir[0] == 0 && fd_redir[1] == 0)
		ft_process_middle_bis(fd_pipe[k][0], fd_pipe[k + 1][1], commande, envp);
	else if (fd_redir[0] < 0)
	{
		ft_free_tab_simple(commande);
		exit(130);
	}
}

void	ft_inbuilts_mid(int *fd_redir, int **fd_pipe,
		char **commande, char **envp)
{
	int	k;

	k = ft_static_multi(100);
	if (fd_redir[1] == 0)
	{
		close(fd_pipe[k][0]);
		ft_execute_inbuilt_fd_multi(fd_pipe[k + 1][1], commande, envp);
	}
	else
	{
		close(fd_pipe[k][0]);
		close(fd_pipe[k][1]);
		ft_execute_inbuilt_fd_multi(fd_redir[1], commande, envp);
	}
}

void	ft_middle_process(int i, char **split_pipe, int **fd_pipe, char **envp)
{
	char	**split_space;
	char	**commande;
	int		*fd_redir;

	fd_redir = malloc(2 * sizeof(int));
	fd_redir[0] = 0;
	fd_redir[1] = 0;
	ft_static_multi(i - 1);
	split_space = ft_split_modif(split_pipe[i], ' ',
			ft_code_char(split_pipe[i]));
	commande = ft_malloc_tab(split_space);
	ft_check_redir(fd_redir, split_space, commande);
	if (ft_check_builtins(commande) == 0)
		ft_execute_mid(fd_redir, fd_pipe, commande, envp);
	else
		ft_inbuilts_mid(fd_redir, fd_pipe, commande, envp);
}
