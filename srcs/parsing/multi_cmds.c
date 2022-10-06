/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:15:46 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:23:05 by vferraro         ###   ########.fr       */
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

void	ft_mid_multi(t_cmd *cmd, int i)
{
	while (cmd->split_pipe[cmd->nbr_cmd])
		cmd->nbr_cmd++;
	ft_close_middle(ft_static_multi(i - 1));
	ft_middle_process(cmd, i);
}

void	ft_last_mutli(t_cmd *cmd, int i)
{
	while (cmd->split_pipe[cmd->nbr_cmd])
		cmd->nbr_cmd++;
	ft_close_fl(ft_static_multi(i) - 1);
	ft_last_process(cmd, i);
}

void	ft_exec_all_multi(t_cmd *cmd, int *pid)
{
	int	i;

	i = 0;
	pid[i] = fork();
	if (pid[i] < 0)
		return ;
	if (pid[i] == 0)
		ft_first_multi(cmd);
	while (++i < ft_nc(cmd->split_pipe) - 1)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
			ft_mid_multi(cmd, i);
		ft_static_multi(i + 1);
	}
	if (i < ft_nc(cmd->split_pipe))
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
			ft_last_mutli(cmd, i);
	}
}

int	ft_pipex_multi(t_cmd *cmd)
{
	int	*pid;
	int	i;

	i = 0;
	while (cmd->split_pipe[cmd->nbr_cmd])
		cmd->nbr_cmd++;
	define_input_signals_block();
	cmd->fd_pipe = malloc((cmd->nbr_cmd - 1) * sizeof(int *));
	while (i < cmd->nbr_cmd - 1)
		cmd->fd_pipe[i++] = malloc(2 * sizeof(int));
	pid = malloc(cmd->nbr_cmd * sizeof(int));
	ft_pipes(cmd->fd_pipe, cmd->nbr_cmd);
	ft_exec_all_multi(cmd, pid);
	ft_close_all(cmd);
	ft_waitpid_all(cmd->nbr_cmd, pid);
	ft_free_tab_int(cmd->fd_pipe, pid, cmd->nbr_cmd);
	return (0);
}
