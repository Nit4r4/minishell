/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:36:28 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:50 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_comp_path(void)
{
	int		k;
	char	*tmp_cmp;

	k = 0;
	while (g_var[k])
	{
		tmp_cmp = ft_tmp_cmp(g_var, "PATH", k);
		if (ft_strcmp("PATH", tmp_cmp) != 0)
		{
			free (tmp_cmp);
			k++;
		}
		else
		{
			free (tmp_cmp);
			return (0);
		}
	}
	return (1);
}

char	**ft_get_path(void)
{
	char	*path;
	char	**tab_path;

	if (ft_comp_path() == 1)
	{
		path = "ERROR";
		tab_path = ft_split(path, ':');
		return (tab_path);
	}
	path = ft_getenv_glob("PATH");
	tab_path = ft_split(path, ':');
	free(path);
	return (tab_path);
}

char	*ft_sub_path(char **tab_path, int i, char *str)
{
	char	*path_cmd;
	char	*path_cmd_final;

	path_cmd = ft_strjoin(tab_path[i], "/");
	path_cmd_final = ft_strjoin_free(path_cmd, str);
	return (path_cmd_final);
}

char	*ft_path(char *str)
{
	int		i;
	char	*path_cmd_final;
	char	**tab_path;

	i = -1;
	if (open(str, O_CLOEXEC) >= 0)
		return (ft_strdup(str));
	tab_path = ft_get_path();
	while (tab_path[++i])
	{
		path_cmd_final = ft_sub_path(tab_path, i, str);
		if (open(path_cmd_final, O_RDONLY) < 0)
		{
			free(path_cmd_final);
			if (!tab_path[i + 1])
			{
				ft_free_tab_simple(tab_path);
				return (ft_strdup("ERROR"));
			}
		}
		else
			break ;
	}
	ft_free_tab_simple(tab_path);
	return (path_cmd_final);
}

char	*ft_path_test(char *str)
{
	int		i;
	char	*path_cmd;
	char	*path_cmd_final;
	char	**tab_path;

	i = -1;
	tab_path = ft_get_path();
	while (tab_path[++i])
	{
		path_cmd = ft_strjoin(tab_path[i], "/");
		path_cmd_final = ft_strjoin_free(path_cmd, str);
		if (open(path_cmd_final, O_RDONLY) < 0)
		{
			free(path_cmd_final);
			if (!tab_path[i + 1])
			{
				ft_free_tab_simple(tab_path);
				return ("ERROR");
			}
		}
		else
			break ;
	}
	ft_free_tab_simple(tab_path);
	return (path_cmd_final);
}
