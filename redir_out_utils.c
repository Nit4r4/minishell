/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:45:06 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:37:50 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_process_onlyone_output(int fd_out, char *path_cmd,
		char **cmd, char **envp)
{
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execve(path_cmd, cmd, envp);
}

void	ft_outfile_split(char **cmd, int *fd, int *i, int *j)
{
	char	*outfile;

	if (fd[1] != 0)
		close(fd[1]);
	*i = *i + 1;
	*j = 0;
	outfile = ft_set_file_bis(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	ft_error_fd(fd[1], outfile);
	free (outfile);
}

void	ft_outfile_nosplit(char **cmd, int *fd, int i, int *j)
{
	char	*outfile;

	if (fd[1] != 0)
		close(fd[1]);
	outfile = ft_set_file(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	ft_error_fd(fd[1], outfile);
	free (outfile);
}

void	ft_outfile_nosplit_append(char **cmd, int *fd, int i, int *j)
{
	char	*outfile;

	*j = *j + 1;
	if (fd[1] != 0)
		close(fd[1]);
	outfile = ft_set_file(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	fd[1] = open(outfile, O_RDWR | O_APPEND | O_CREAT, 0666);
	ft_error_fd(fd[1], outfile);
	free (outfile);
}

void	ft_outfile_split_append(char **cmd, int *fd, int *i, int *j)
{
	char	*outfile;

	if (fd[1] != 0)
		close(fd[1]);
	*i = *i + 1;
	*j = 0;
	outfile = ft_set_file_bis(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	fd[1] = open(outfile, O_RDWR | O_APPEND | O_CREAT, 0666);
	ft_error_fd(fd[1], outfile);
	free (outfile);
}
