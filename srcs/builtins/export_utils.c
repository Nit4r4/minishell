/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:20:31 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 11:38:39 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_nbr_args(t_cmd *cmd)
{
	int	i;
	int	nbr_args;

	i = 1;
	nbr_args = 0;
	while (cmd->cmd_test[i])
	{
		i++;
		nbr_args++;
	}
	return (nbr_args);
}

void	ft_sort_alpha(char **g_var)
{
	int		k;
	int		j;
	char	*tmp;

	k = 0;
	j = 0;
	while (g_var[k])
	{
		j = 0;
		while (g_var[j])
		{
			if (ft_strcmp(g_var[k], g_var[j]) < 0)
			{
				tmp = ft_strdup(g_var[k]);
				free(g_var[k]);
				g_var[k] = ft_strdup(g_var[j]);
				free(g_var[j]);
				g_var[j] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		k++;
	}
}

void	ft_printf_all(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->sorted[i])
	{
		printf("declare -x %s\n", cmd->sorted[i]);
		i++;
	}
}

void	ft_write_all(t_cmd *cmd, int fd_out)
{
	int		i;
	char	**split_tmp;

	i = 0;
	while (cmd->sorted[i])
	{
		split_tmp = ft_split(cmd->sorted[i], '=');
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
