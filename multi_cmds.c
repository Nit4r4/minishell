/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:15:46 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:18 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_static_multi(int i)
{
	static int	return_val = 0;

	if (i != 100)
		return_val = i;
	return (return_val);
}

void	ft_mid_multi(int i, int **fd_pipe, char **split_pipe, char **envp)
{
	int	nbr_cmd;

	nbr_cmd = 0;
	while (split_pipe[nbr_cmd])
		nbr_cmd++;
	ft_close_middle(ft_static_multi(i - 1), nbr_cmd, fd_pipe);
	ft_middle_process(i, split_pipe, fd_pipe, envp);
}

void	ft_last_mutli(int i, int **fd_pipe, char **split_pipe, char **envp)
{
	int	nbr_cmd;

	nbr_cmd = 0;
	while (split_pipe[nbr_cmd])
		nbr_cmd++;
	ft_close_fl(ft_static_multi(i) - 1, nbr_cmd, fd_pipe);
	ft_last_process(i, split_pipe, fd_pipe, envp);
}

void	ft_exec_all_multi(int *pid, int **fd_pipe,
			char **split_pipe, char **envp)
{
	int	i;

	i = 0;
	pid[i] = fork();
	if (pid[i] < 0)
		return ;
	if (pid[i] == 0)
		ft_first_multi(fd_pipe, split_pipe, envp);
	while (++i < ft_nc(split_pipe) - 1)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
			ft_mid_multi(i, fd_pipe, split_pipe, envp);
		ft_static_multi(i + 1);
	}
	if (i < ft_nc(split_pipe))
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
			ft_last_mutli(i, fd_pipe, split_pipe, envp);
	}
}

int	ft_pipex_multi(char **split_pipe, char **envp)
{
	int	*pid;
	int	**fd_pipe;
	int	i;
	int	nbr_cmd;

	i = 0;
	nbr_cmd = 0;
	while (split_pipe[nbr_cmd])
		nbr_cmd++;
	define_input_signals_block();
	fd_pipe = malloc((nbr_cmd - 1) * sizeof(int *));
	while (i < nbr_cmd -1)
		fd_pipe[i++] = malloc(2 * sizeof(int));
	pid = malloc(nbr_cmd * sizeof(int));
	ft_pipes(fd_pipe, nbr_cmd);
	ft_exec_all_multi(pid, fd_pipe, split_pipe, envp);
	ft_close_all(nbr_cmd, fd_pipe);
	ft_waitpid_all(nbr_cmd, pid);
	ft_free_tab_int(fd_pipe, pid, nbr_cmd);
	return (0);
}
