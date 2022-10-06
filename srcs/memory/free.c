/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:34:26 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 16:24:36 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_free_tab_simple(char **tab)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (tab[n])
		n++;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_tab_int(t_shell *shell, int *pid)
{
	int	j;

	j = 0;
	free(pid);
	while (j < shell->cmd->nbr_cmd - 1)
	{
		free(shell->fd[j]);
		j++;
	}
	free(shell->fd);
}
