/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vodka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:56:54 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:37:15 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*ft_cmd_path(char **cmd)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(cmd[0], '/');
	free(cmd[0]);
	while (tmp[i])
		i++;
	cmd[0] = ft_strdup(tmp[i - 1]);
	ft_free_tab_simple(tmp);
	return (cmd[0]);
}

char	*ft_absolute(char **cmd)
{
	char	*path_cmd;

	path_cmd = ft_strdup(cmd[0]);
	ft_cmd_path(cmd);
	return (path_cmd);
}
