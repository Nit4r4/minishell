/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:45:06 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:37:47 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_sub_exec(int sortie)
{
	if (!WIFEXITED(sortie))
	{
		ft_static(130);
		return ;
	}
	ft_static(WEXITSTATUS(sortie));
}

void	ft_freeeee(char **commande, char *path, int fd_out)
{
	ft_free_tab_simple(commande);
	free(path);
	close(fd_out);
}

int	ft_exec_out(int fd_out, char **commande, char **envp)
{
	char	*path;
	int		pid;
	int		sortie;

	if (commande[0][0] != '/')
	{
		path = ft_path(commande[0]);
		if (ft_error(path, commande) == 0)
			return (ft_static(1));
	}
	if (commande[0][0] == '/')
		path = ft_absolute(commande);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		execve(path, commande, envp);
	}
	ft_freeeee(commande, path, fd_out);
	waitpid(pid, &sortie, 0);
	ft_sub_exec(sortie);
	return (0);
}
