/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:34:26 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:53 by vferraro         ###   ########.fr       */
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

void	ft_free_tab_int(int **fd, int *pid, int nbr_cmd)
{
	int	j;

	j = 0;
	free(pid);
	while (j < nbr_cmd - 1)
	{
		free(fd[j]);
		j++;
	}
	free(fd);
}
