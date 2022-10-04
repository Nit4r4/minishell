/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:23:45 by creyt             #+#    #+#             */
/*   Updated: 2022/10/02 14:09:42 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_nbr_args(t_shell *shell)
{
	int	i;
	int	nbr_args;

	i = 1;
	nbr_args = 0;
	while (shell->cmd->args[i])
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

void	ft_print_all(char **sorted)
{
	int	i;

	i = 0;
	while (sorted[i])
	{
		ft_printf("declare -x %s\n", sorted[i]);
		i++;
	}
}

void	ft_write_all(int fd_out, char **sorted)
{
	int		i;
	char	**split_tmp;

	i = 0;
	while (sorted[i])
	{
		split_tmp = ft_split(sorted[i], '=');
		write(fd_out, "declare -x ", 11);
		write(fd_out, split_tmp[0], ft_strlen(split_tmp[0]));
		write(fd_out, "=", 1);
		write(fd_out, "\"", 1);
		write(fd_out, split_tmp[1], ft_strlen(split_tmp[1]));
		write(fd_out, "\"", 1);
		write(fd_out, "\n", 1);
		i++;
		ft_free_tab_simple(split_tmp);
	}
}