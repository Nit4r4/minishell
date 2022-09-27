/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:48:13 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:29 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_error(char *path_cmd, char **cmd_infile)
{
	if (path_cmd[0] == 'E' && path_cmd[1] == 'R')
	{
		printf("Command %s not found\n", cmd_infile[0]);
		ft_free_tab_simple(cmd_infile);
		free(path_cmd);
		return (0);
	}
	else
		return (1);
}

void	ft_error_fd(int fd, char *infile)
{
	if (fd < 0 && (infile[0] != '<' && infile[0] != '>'))
	{
		printf("Probleme d'access au fichier: %s\n", infile);
		ft_static(1);
	}
	if (fd < 0 && (infile[0] == '<' || infile[0] == '>'))
	{
		printf("Probleme avec les < ou >\n");
		ft_static(258);
	}
}

char	*ft_error_cmd(char **cmd)
{
	char	*path_cmd;
	char	*check_path;

	if (cmd[0][0] != '/')
	{
		path_cmd = ft_path(cmd[0]);
		if (ft_error(path_cmd, cmd) == 0)
		{
			ft_static(127);
			exit (127);
		}
	}
	if (cmd[0][0] == '/')
	{
		path_cmd = ft_absolute(cmd);
		check_path = ft_path(cmd[0]);
		if (ft_strcmp(path_cmd, check_path) != 0)
		{
			free(path_cmd);
			ft_static(127);
			exit (127);
		}
	}
	return (path_cmd);
}
