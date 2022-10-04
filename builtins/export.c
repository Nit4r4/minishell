/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:15:01 by creyt             #+#    #+#             */
/*   Updated: 2022/10/02 14:49:00 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_total_args(t_shell *shell, char **temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i])
	{
		shell->var[i] = ft_strdup(temp[i]);
		i++;
	}
	shell->var[i] = ft_strdup(shell->cmd->new_arg);
}

void	ft_sort_args(t_shell *shell)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = malloc(sizeof(shell->var));
	while (shell->var[i])
	{
		temp[i] = ft_strdup(shell->var[i]);
		i++;
	}
	free(temp);
	shell->var = malloc((i + 2) * sizeof(char *));
	shell->var[i + 1] = NULL;
	ft_total_args(shell, temp);
}

void	ft_sub_export(t_shell *shell, int i)
{
	shell->cmd->new_arg = ft_strdup(shell->cmd->args);
	ft_sort_args(shell->cmd->new_arg);
	free(shell->cmd->new_arg);
}

void	ft_export_alone(t_shell *shell)
{
	int	i;
	int	nb;

	i = 1;
	nb = ft_nb_args(shell->cmd->args[i]);
	if (nb == 0)
	{
		ft_export_basic(shell);
		exit (0);
	}
	while (shell->cmd->args[i])
	{
		if (shell->cmd->args[i][0] == '=')
			ft_printf("not valid\n");
		else
		{
			ft_unset_export(shell->cmd->args[i]);
			ft_sub_export(shell->cmd->args, i);
		}
		i++;
	}
}