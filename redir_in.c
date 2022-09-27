/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:43:13 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:37:52 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_infile_nosplit(char **cmd, int *fd, int *j, int i)
{
	char	*infile;

	if (fd[0] < 0)
	{
		infile = ft_set_file(cmd, j, i);
		infile = ft_check_quote_simple(infile);
		free(infile);
		return ;
	}
	if (fd[0] != 0)
		close(fd[0]);
	infile = ft_set_file(cmd, j, i);
	infile = ft_check_quote_simple(infile);
	fd[0] = open(infile, O_RDONLY);
	ft_error_fd(fd[0], infile);
	free (infile);
}

void	ft_infile_split(char **cmd, int *fd, int *i, int *j)
{
	char	*infile;

	if (fd[0] < 0)
	{
		*i = *i + 1;
		*j = 0;
		infile = ft_set_file_bis(cmd, j, i);
		infile = ft_check_quote_simple(infile);
		free(infile);
		return ;
	}
	if (fd[0] != 0)
		close(fd[0]);
	*i = *i + 1;
	*j = 0;
	infile = ft_set_file_bis(cmd, j, i);
	infile = ft_check_quote_simple(infile);
	fd[0] = open(infile, O_RDONLY);
	ft_error_fd(fd[0], infile);
	free (infile);
}

void	ft_exec_in(int fd_in, char **commande, char **envp)
{
	char	*path;
	int		pid;
	int		sortie;

	path = ft_error_cmd(commande);
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		execve(path, commande, envp);
	}
	ft_free_tab_simple(commande);
	free(path);
	close(fd_in);
	waitpid(pid, &sortie, 0);
	if (!WIFEXITED(sortie))
	{
		ft_static(130);
		return ;
	}
	ft_static(WEXITSTATUS(sortie));
	return ;
}
