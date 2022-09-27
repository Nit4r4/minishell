/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:46:35 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:37 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_execute_last(int *fd_redir, int **fd_pipe,
		char **commande, char **envp)
{
	int	k;

	k = ft_static_multi(100);
	if (fd_redir[0] == 0 && fd_redir[1] == 0)
		ft_process_last(fd_pipe[k][0], fd_pipe[k][1], commande, envp);
	else if (fd_redir[0] > 0 && fd_redir[1] == 0)
	{
		close(fd_pipe[k][0]);
		ft_process_last(fd_redir[0], fd_pipe[k][1], commande, envp);
	}
	else if (fd_redir[0] == 0 && fd_redir[1] > 0)
	{
		close(fd_pipe[k][1]);
		ft_process_last_out(fd_pipe[k][0], fd_redir[1], commande, envp);
	}
	else if (fd_redir[0] > 0 && fd_redir[1] > 1)
	{
		ft_close_two_sup(fd_pipe, k);
		ft_process_last_out(fd_redir[0], fd_redir[1], commande, envp);
	}
	else if (fd_redir[0] < 0)
	{
		ft_free_tab_simple(commande);
		exit(130);
	}
}

void	ft_inbuilts_last(int *fd_redir, int **fd_pipe,
		char **commande, char **envp)
{
	int	k;

	k = ft_static_multi(100);
	if (fd_redir[1] == 0)
	{
		close(fd_pipe[k][0]);
		close(fd_pipe[k][1]);
		ft_execute_inbuilt_fd_multi(0, commande, envp);
	}
	else
	{
		close(fd_pipe[k][0]);
		close(fd_pipe[k][1]);
		ft_execute_inbuilt_fd_multi(fd_redir[1], commande, envp);
	}
}

void	ft_last_process(int i, char **split_pipe, int **fd_pipe, char **envp)
{
	char	**commande;
	char	**split_space;
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
		ft_execute_last(fd_redir, fd_pipe, commande, envp);
	else
		ft_inbuilts_last(fd_redir, fd_pipe, commande, envp);
}
