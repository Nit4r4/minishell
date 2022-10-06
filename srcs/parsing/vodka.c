/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vodka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:10:04 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 14:12:23 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_cmd_path(t_cmd *cmd)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(cmd->cmd[0], '/');
	free(cmd->cmd[0]);
	while (tmp[i])
		i++;
	cmd->cmd[0] = ft_strdup(tmp[i - 1]);
	ft_free_tab_simple(tmp);
	return (cmd->cmd[0]);
}

char	*ft_absolute(t_cmd *cmd)
{
	char	*path_cmd;

	path_cmd = ft_strdup(cmd->cmd[0]);
	ft_cmd_path(cmd->cmd);
	return (path_cmd);
}