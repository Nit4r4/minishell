/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:29:49 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 13:32:03 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_sort_alpha_bis(void)
{
    t_shell *shell;
	int		k;
	int		j;
	char	*tmp;

	k = 0;
	j = 0;
	while (shell->env[k])
	{
		j = 0;
		while (shell->env[j])
		{
			if (ft_strcmp(shell->env[k], shell->env[j]) < 0)
			{
				tmp = ft_strdup(shell->env[k]);
				free(shell->env[k]);
				shell->env[k] = ft_strdup(shell->env[j]);
				free(shell->env[j]);
				shell->env[j] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		k++;
	}
}

void	ft_sort_alpha_bis_envp(t_shell *shell)
{
	int		k;
	int		j;
	char	*tmp;

	k = 0;
	j = 0;
	while (shell->env[k])
	{
		j = 0;
		while (shell->env[j])
		{
			if (ft_strcmp(shell->env[k], shell->env[j]) < 0)
			{
				tmp = ft_strdup(shell->env[k]);
				free(shell->env[k]);
				shell->env[k] = ft_strdup(shell->env[j]);
				free(shell->env[j]);
				shell->env[j] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		k++;
	}
}