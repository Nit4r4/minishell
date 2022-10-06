/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:48:57 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 11:14:19 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_close_fl(t_cmd *cmd)
{
	int	j;

	j = 0;
	while (j < cmd->nbr_cmd - 1)
	{
		if (j != cmd->k)
		{
			close(cmd->fd_pipe[j][0]);
			close(cmd->fd_pipe[j][1]);
		}
		j++;
	}
}

void	ft_close_all(t_cmd *cmd)
{
	int	j;

	j = 0;
	while (j < cmd->nbr_cmd - 1)
	{
		close(cmd->fd_pipe[j][0]);
		close(cmd->fd_pipe[j][1]);
		j++;
	}
}

void	ft_close_middle(t_cmd *cmd)
{
	int	j;

	j = 0;
	while (j < cmd->nbr_cmd - 1)
	{
		if (j != cmd->k)
			close(cmd->fd_pipe[j][0]);
		if (j != (cmd->k + 1))
			close(cmd->fd_pipe[j][1]);
		j++;
	}
}
