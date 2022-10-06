/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:26:05 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 16:33:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_process_onlyone(t_cmd *cmd, char **g_var)
{
	execve(cmd->path_cmd, cmd->cmd, g_var);
	printf("Not an executable\n");
	exit(126);
}

int	ft_too_long(t_cmd *cmd, int i)
{
	free(cmd->path_cmd);
	ft_free_tab_simple(cmd->cmd);
	return (ft_static(i));
}

int	ft_too_long_bis(t_cmd *cmd, int i)
{
	char	*error;

	error = ft_strdup(cmd->cmd);
	printf("commande: %s not found\n", error);
	free(error);
	free(cmd->path_cmd);
	free(cmd->cmd);
	return (ft_static(i));
}
