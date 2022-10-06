/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:48:13 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 13:09:32 by vferraro         ###   ########.fr       */
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

char	*ft_error_cmd(t_cmd *cmd)
{
	char	*path_cmd;
	char	*check_path;

	if (cmd->cmd[0][0] != '/')
	{
		path_cmd = ft_path(cmd->cmd[0]);
		if (ft_error(path_cmd, cmd->cmd) == 0)
		{
			ft_static(127);
			exit (127);
		}
	}
	if (cmd->cmd[0][0] == '/')
	{
		path_cmd = ft_absolute(cmd);
		check_path = ft_path(cmd->cmd[0]);
		if (ft_strcmp(path_cmd, check_path) != 0)
		{
			free(path_cmd);
			ft_static(127);
			exit (127);
		}
	}
	return (path_cmd);
}
