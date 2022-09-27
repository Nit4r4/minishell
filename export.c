/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:12:24 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:04 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_total_args_test(char **tmp, char *new_arg)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tmp[i])
	{
		g_var[i] = ft_strdup(tmp[i]);
		i++;
	}
	g_var[i] = ft_strdup(new_arg);
}

void	ft_sort_args_test(char *new_args)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = ft_malloc_tab(g_var);
	while (g_var[i])
	{
		tmp[i] = ft_strdup(g_var[i]);
		i++;
	}
	ft_free_tab_simple(g_var);
	g_var = malloc((i + 2) * sizeof(char *));
	g_var[i + 1] = NULL;
	ft_total_args_test(tmp, new_args);
	ft_free_tab_simple(tmp);
}

void	ft_sub_export(char **cmd_test, int i)
{
	char	*new_arg;

	new_arg = ft_strdup(cmd_test[i]);
	ft_sort_args_test(new_arg);
	free(new_arg);
}

void	ft_export_fd_test(int fd_out, char **cmd_test, char **g_var)
{
	int		nbr;
	int		i;

	i = 1;
	nbr = ft_nbr_args(cmd_test);
	if (nbr == 0)
	{
		ft_export_basic_fd(fd_out, g_var);
		exit (0);
	}
	while (cmd_test[i])
	{
		if (cmd_test[i][0] == '=')
		{
			printf ("not valid\n");
			ft_static(1);
		}
		else
		{
			ft_unset_export(cmd_test[i]);
			ft_sub_export(cmd_test, i);
		}
		i++;
	}
}

void	ft_export_fd_multi(int fd_out, char **cmd_test, char **envp)
{
	if (ft_nbr_args(cmd_test) == 0)
	{
		ft_export_basic_fd(fd_out, envp);
		exit (0);
	}
	if (ft_nbr_args(cmd_test) > 0)
		exit (0);
}
