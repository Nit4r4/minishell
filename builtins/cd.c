/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:01:22 by creyt             #+#    #+#             */
/*   Updated: 2022/10/02 15:51:15 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_pwd(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env_c[i])
	{
		if (ft_strncmp(shell->env_c[i], "PWD", 3) == 0)
		{
			free(shell->env_c[i]);
			shell->env_c[i] = ft_strdup("PWD=");
			shell->env_c[i] = ft_strjoin_free(shell->env_c[i], shell->cwdbis);
		}
		if (ft_strncmp(shell->env_c[i], "OLDPWD", 6) == 0)
		{
			free(shell->env_c[i]);
			shell->env_c[i] = ft_strdup("OLDPWD=");
			shell->env_c[i] = ft_strjoin_free(shell->env_c[i], shell->cwd);
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

int	ft_free_cwd(t_shell *shell)
{
	free(shell->cwd);
	free(shell->cwdbis);
	free(shell->home);
}

void	p_error(t_shell *shell)
{
	free(shell->cwd);
	perror("\033[31mError");
}

int	ft_cd(t_shell *shell)
{
	int	i;
    char **args;

	i = 0;
    args = shell->cmd->args;
	shell->cwd = NULL;
	shell->cwdbis = NULL;
	shell->cwd = getcwd(shell->cwd, 0);
	shell->home = NULL;
	/* trouver comme initialiser le home par une fonction */
	if ((args[1] && args[1][0] != '~') || (args[1] && args[1][0] == '~' && args[1][1]))
		i = chdir(args[1]);
	else if (!args[1] || (args[1][0] == '~') && !args[1] && !args[1][1])
		i = chdir(shell->home);
	if (i != 0)
	{
		p_error(shell->cwd);
		return (0);
	}
	shell->cwdbis = getcwd(shell->cwdbis, 0);
    ft_replace_pwd(shell);
	ft_free_cwd(shell);
	return (0);
}