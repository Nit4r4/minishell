/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:23:45 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 16:14:53 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_nbr_args(t_shell *shell)
{
	int	i;
	int	nbr_args;

	i = 1;
	nbr_args = 0;
	while (shell->cmd->cmd_test[i])
	{
		i++;
		nbr_args++;
	}
	return (nbr_args);
}

void	ft_sort_alpha(t_shell *shell)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (shell->env[j])
	{
		j = 0;
		while (shell->env[i])
		{
			if (ft_strcmp(shell->env[j], shell->env[i]) < 0)
			{
				tmp = ft_strdup(shell->env[j]);
				free(shell->env[j]);
				shell->env[j] = ft_strdup(shell->env[i]);
				free(shell->env[i]);
				shell->env[i] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
}

void	ft_print_all(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->sorted[i])
	{
		ft_printf("declare -x %s\n", shell->sorted[i]);
		i++;
	}
}

void	ft_write_all(t_shell *shell)
{
	int		i;
	char	**split_tmp;

	i = 0;
	while (shell->sorted[i])
	{
		split_tmp = ft_split(shell->sorted[i], '=');
		ft_printf("declare -x ");
		ft_printf("%s", split_tmp[0]);
		ft_printf("=");
		ft_printf("\"");
		ft_printf("%s", split_tmp[1]);
		ft_printf("\"");
		ft_printf("\n");
		i++;
		ft_free_tab_simple(split_tmp);
	}
}