/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:43:39 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:53 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_replace_pwd(char **copy_env, char *cwd, char *cwdbis)
{
	int	i;

	i = 0;
	while (copy_env[i])
	{
		if (ft_strncmp(copy_env[i], "PWD", 3) == 0)
		{
			free(copy_env[i]);
			copy_env[i] = ft_strdup("PWD=");
			copy_env[i] = ft_strjoin_free(copy_env[i], cwdbis);
		}
		if (ft_strncmp(copy_env[i], "OLDPWD", 6) == 0)
		{
			free(copy_env[i]);
			copy_env[i] = ft_strdup("OLDPWD=");
			copy_env[i] = ft_strjoin_free(copy_env[i], cwd);
		}
		i++;
	}
}

char	**ft_env_copy(char **envp_copy)
{
	int		i;
	char	**copy_env;

	i = 0;
	while (envp_copy[i])
		i++;
	copy_env = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (envp_copy[i])
	{
		copy_env[i] = ft_strdup(envp_copy[i]);
		i++;
	}
	copy_env[i] = NULL;
	return (copy_env);
}

void	ft_perror(char *cwd)
{
	free (cwd);
	perror("Error: ");
	ft_static(1);
}

void	ft_freeze(char *cwd, char *cwdbis, char *home)
{
	free (cwd);
	free (cwdbis);
	free (home);
}

int	ft_cd(char **cmd_test, char **envp_copy)
{
	int		i;
	char	*cwd;
	char	*cwdbis;
	char	*home;

	i = 0;
	cwd = NULL;
	cwdbis = NULL;
	cwd = getcwd(cwd, 0);
	home = ft_getenv_glob("HOME");
	if ((cmd_test[1] && cmd_test[1][0] != '~') ||
			(cmd_test[1] && cmd_test[1][0] == '~' && cmd_test[1][1]))
		i = chdir(cmd_test[1]);
	else if (!cmd_test[1] || (cmd_test[1][0] == '~' && !cmd_test[1][1]))
		i = chdir(home);
	if (i != 0)
	{
		ft_perror(cwd);
		return (0);
	}
	cwdbis = getcwd(cwdbis, 0);
	ft_replace_pwd(envp_copy, cwd, cwdbis);
	ft_freeze(cwd, cwdbis, home);
	return (0);
}
