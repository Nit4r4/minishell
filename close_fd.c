/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:48:57 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:50 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_close_fl(int k, int nbr_cmd, int **fd_pipe)
{
	int	j;

	j = 0;
	while (j < nbr_cmd - 1)
	{
		if (j != k)
		{
			close(fd_pipe[j][0]);
			close(fd_pipe[j][1]);
		}
		j++;
	}
}

void	ft_close_all(int nbr_cmd, int **fd_pipe)
{
	int	j;

	j = 0;
	while (j < nbr_cmd - 1)
	{
		close(fd_pipe[j][0]);
		close(fd_pipe[j][1]);
		j++;
	}
}

void	ft_close_middle(int k, int nbr_cmd, int **fd_pipe)
{
	int	j;

	j = 0;
	while (j < nbr_cmd - 1)
	{
		if (j != k)
			close(fd_pipe[j][0]);
		if (j != (k + 1))
			close(fd_pipe[j][1]);
		j++;
	}
}
