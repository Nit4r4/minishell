/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmds_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:15:46 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:08:31 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_nc(t_cmd *cmd)
{
	cmd->nbr_cmd = 0;
	while (cmd->split_pipe[cmd->nbr_cmd])
		cmd->nbr_cmd++;
	return (cmd->nbr_cmd);
}

int	ft_pipes(t_cmd *cmd, int **fd)
{
	int	j;

	j = 0;
	while (j < cmd->nbr_cmd - 1)
	{
		if (pipe(fd[j]) == -1)
			exit (1);
		j++;
	}
	return (0);
}

void	ft_waitpid_all(t_cmd *cmd, int *pid)
{
	int	j;
	int	sortie;

	j = 0;
	sortie = 0;
	while (j < cmd->nbr_cmd)
	{
		waitpid(pid[j], &sortie, 0);
		ft_static(WEXITSTATUS(sortie));
		j++;
	}
}

void	ft_first_multi(t_cmd *cmd)
{
	cmd->nbr_cmd = 0;
	while (cmd->split_pipe[cmd->nbr_cmd])
		cmd->nbr_cmd++;
	ft_close_fl(cmd);
	ft_first_process(cmd, cmd->split_pipe);
}
