/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:27:30 by creyt             #+#    #+#             */
/*   Updated: 2022/11/01 13:08:04 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	b_cd(t_shell *sh, int in)
{
	char	dir[MAX_PATH];
	int		i;

	if (sh->in[in].nbr_elem == 1)
	{
		find_home(sh);
		i = 0;
	}
	else
		i = 1;
	if (i)
	{
		if (sh->in[in].elem->cont[i][0] == '-')
			i = print_cd(OPT_IGN, 2);
		if (i >= sh->in[in].nbr_elem)
			return (ft_end(ERR_NO_ARG, EXIT_FAILURE, 1));
		if (chdir(sh->in[in].elem->cont[i]))
			return (ft_end(ERROR, EXIT_FAILURE, 1));
	}
	update_env(sh, dir);
	return (ft_end(NULL, EXIT_SUCCESS, 0));
}

void	update_env(t_shell *sh, char *dir)
{
	int		i;
	int		j;
	char	**splited;

	i = where_in_env(sh, "PWD", 4);
	j = where_in_env(sh, "OLDPWD", 7);
	if (i == NO_RESULT)
		ft_printf(CMD_404);
	else
	{
		free(sh->env_cpy[j]);
		splited = parse_env(sh->env_cpy[i]);
		sh->env_cpy[j] = ft_strjoin("OLDPWD=", splited[1]);
		freetab(splited, 2);
		free(sh->env_cpy[i]);
		sh->env_cpy[i] = ft_strjoin("PWD=", getcwd(dir, MAX_PATH));
	}
}

int	where_in_env(t_shell *sh, char *key, int len)
{
	int	i;
	int	diff;

	i = 0;
	while (i < sh->nbr_env)
	{
		diff = ft_strncmp(sh->env_cpy[i], key, len);
		if (diff == 0 || diff == 61)
			return (i);
		i++;
	}
	return (NO_RESULT);
}

int	print_cd(char *s, int i)
{
	ft_printf(s);
	return (i);
}

int	find_home(t_shell *sh)
{
	int		i;
	char	**tmp;

	i = where_in_env(sh, "HOME", 5);
	if (i == NO_RESULT)
		ft_end(HOME_SET, EXIT_FAILURE, 1);
	else
	{
		tmp = parse_env(sh->env_cpy[i]);
		if (chdir(tmp[1]))
			ft_end(ERROR, EXIT_FAILURE, 1);
		freetab(tmp, 2);
	}
	return (ft_end(NULL, EXIT_SUCCESS, 0));
}
