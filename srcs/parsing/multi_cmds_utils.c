/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmds_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:15:46 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:21 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_nc(char **split_pipe)
{
	int	nbr_cmd;

	nbr_cmd = 0;
	while (split_pipe[nbr_cmd])
		nbr_cmd++;
	return (nbr_cmd);
}

int	ft_pipes(int **fd, int nbr_cmd)
{
	int	j;

	j = 0;
	while (j < nbr_cmd - 1)
	{
		if (pipe(fd[j]) == -1)
			exit (1);
		j++;
	}
	return (0);
}

void	ft_waitpid_all(int nbr_cmd, int *pid)
{
	int	j;
	int	sortie;

	j = 0;
	sortie = 0;
	while (j < nbr_cmd)
	{
		waitpid(pid[j], &sortie, 0);
		ft_static(WEXITSTATUS(sortie));
		j++;
	}
}

void	ft_first_multi(int **fd_pipe, char **split_pipe, char **envp)
{
	int	nbr_cmd;

	nbr_cmd = 0;
	while (split_pipe[nbr_cmd])
		nbr_cmd++;
	ft_close_fl(0, nbr_cmd, fd_pipe);
	ft_first_process(split_pipe, fd_pipe, envp);
}
