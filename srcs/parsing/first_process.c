/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:27:08 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:56 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_no_in_process(int fd_in, int fd_out, char **cmd, char **envp)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(cmd);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	execve(path_cmd, cmd, envp);
}

void	ft_inbuilts(int *fd_redir, int **fd_pipe, char **commande, char **envp)
{
	if (fd_redir[1] == 0)
	{
		close(fd_pipe[0][0]);
		ft_execute_inbuilt_fd_multi(fd_pipe[0][1], commande, envp);
	}
	else
	{
		close(fd_pipe[0][0]);
		close(fd_pipe[0][1]);
		ft_execute_inbuilt_fd_multi(fd_redir[1], commande, envp);
	}
}

void	ft_exec_first(int *fd_redir, int **fd_pipe,
			char **commande, char **envp)
{
	if (fd_redir[0] > 0 && fd_redir[1] > 0)
		ft_process_in_out(fd_redir, fd_pipe, commande, envp);
	else if (fd_redir[0] > 0 && fd_redir[1] == 0)
		ft_process_in(fd_redir, fd_pipe, commande, envp);
	else if (fd_redir[0] == 0 && fd_redir[1] > 0)
		ft_process_out(fd_redir, fd_pipe, commande, envp);
	else if (fd_redir[0] == 0 && fd_redir[1] == 0)
		ft_no_in_process(fd_pipe[0][0], fd_pipe[0][1], commande, envp);
	else if (fd_redir[0] < 0)
		ft_prob_infile(commande);
}

void	ft_first_process(char **split_pipe, int **fd_pipe, char **envp)
{
	char	**commande;
	char	**split_space;
	int		*fd_redir;

	fd_redir = malloc(2 * sizeof(int));
	fd_redir[0] = 0;
	fd_redir[1] = 0;
	if (0 < 1)
	{
		split_space = ft_split_modif(split_pipe[0], ' ',
				ft_code_char(split_pipe[0]));
		commande = ft_malloc_tab(split_space);
		ft_check_redir(fd_redir, split_space, commande);
		if (commande[0][0] == '\0')
		{
			ft_free_tab_simple(split_space);
			ft_free_tab_simple(commande);
			free(fd_redir);
			exit(130);
		}
		if (ft_check_builtins(commande) == 0)
			ft_exec_first(fd_redir, fd_pipe, commande, envp);
		ft_inbuilts(fd_redir, fd_pipe, commande, envp);
	}
}
