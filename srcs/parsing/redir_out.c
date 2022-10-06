/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:17:35 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 15:23:03 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_sub_exec(int sortie)
{
	if (!WIFEXITED(sortie))
	{
		ft_static(130);
		return ;
	}
	ft_static(WEXITSTATUS(sortie));
}

void	ft_freeeee(t_cmd *cmd, char *path)
{
	ft_free_tab_simple(cmd->commande);
	free(path);
	close(cmd->shell->fd_out);
}

int	ft_exec_out(t_shell *shell)
{
	char	*path;
	int		pid;
	int		sortie;

	if (shell->cmd->commande[0][0] != '/')
	{
		path = ft_path(shell->cmd->commande[0]);
		if (ft_error(path, shell->cmd->commande) == 0)
			return (ft_static(1));
	}
	if (shell->cmd->commande[0][0] == '/')
		path = ft_absolute(shell->cmd->commande);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(shell->fd_out, STDOUT_FILENO);
		close(shell->fd_out);
		execve(path, shell->cmd->commande, shell->envp);
	}
	ft_freeeee(shell, path);
	waitpid(pid, &sortie, 0);
	ft_sub_exec(sortie);
	return (0);
}