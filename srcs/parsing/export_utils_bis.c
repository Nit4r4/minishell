/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:41:39 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:19 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_export_basic(char **envp, char **envp_sorted, char **args)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		envp_sorted[i] = ft_strdup(envp[i]);
		i++;
	}
	ft_sort_alpha(envp_sorted);
	ft_printf_all(envp_sorted);
	if (args)
	{
		ft_sort_alpha(args);
		ft_printf_all(args);
	}
}

void	ft_export_basic_fd(int fd_out, char **g_var)
{
	if (g_var)
	{
		ft_sort_alpha(g_var);
		ft_write_all(fd_out, g_var);
	}
}

void	ft_export_new_args(char **cmd_test, char **new_args)
{
	int	i;

	i = 0;
	while (i < ft_nbr_args(cmd_test))
	{
		new_args[i] = ft_strdup(cmd_test[i + 1]);
		i++;
	}
}

void	ft_sort_new_args(char **new_args)
{
	int	i;

	i = 0;
	ft_sort_alpha(new_args);
	while (new_args[i])
	{
		g_var[i] = ft_strdup(new_args[i]);
		i++;
	}
}
