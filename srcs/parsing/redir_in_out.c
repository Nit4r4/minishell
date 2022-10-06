/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:13:59 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:46:57 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_files(char **c, int *fd, int *j, int *i)
{
	if (c[*i][*j] == '<')
		ft_very_first_if(c, fd, i, j);
	else if (c[*i][*j] == '>')
	{
		if (c[*i][*j + 1] != '>' && c[*i][*j + 1])
			ft_outfile_nosplit(c, fd, *i, j);
		else if (c[*i][*j + 1] && c[*i][*j + 1] == '>' && c[*i][*j + 2])
			ft_outfile_nosplit_append(c, fd, *i, j);
		else if (c[*i][a(*j)] == 62 && !c[*i][b(*j)] && c[a(*i)])
			ft_outfile_split_append(c, fd, i, j);
		else if (c[*i][*j + 1] != '>' && !c[*i][*j + 1] && c[*i + 1])
			ft_outfile_split(c, fd, i, j);
		else
			fd[1] = -5;
	}
}

void	ft_dup_close(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	ft_execute(t_cmd *cmd)
{
	ft_dup_close(cmd->shell->fd);
	execve(cmd->path, cmd->commande, g_var);
}

void	ft_close_close(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	ft_exec_in_out(t_cmd *cmd)
{
	int		pid;
	int		sortie;

	if (cmd->commande[0][0] != '/')
	{
		cmd->path = ft_path(cmd->commande[0]);
		if (ft_error(cmd->path, cmd->commande) == 0)
			return (ft_static(1));
	}
	if (cmd->commande[0][0] == '/')
		cmd->path = ft_absolute(cmd->commande);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		ft_execute(cmd);
	ft_free_tab_simple(cmd->commande);
	free(cmd->path);
	ft_close_close(cmd->shell->fd);
	waitpid(pid, &sortie, 0);
	if (!WIFEXITED(sortie))
		return (ft_static(130));
	ft_static(WEXITSTATUS(sortie));
	return (0);
}
