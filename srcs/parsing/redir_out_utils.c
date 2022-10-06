/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:02:16 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 15:07:41 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_process_onlyone_output(t_shell *shell, t_cmd *cmd)
{
	dup2(shell->fd_out, STDOUT_FILENO);
	close(shell->fd_out);
	execve(cmd->path_cmd, cmd->cmd, shell->envp);
}

void	ft_outfile_split(t_cmd *cmd, int *i, int *j)
{
	char	*outfile;

	if (cmd->shell->fd[1] != 0)
		close(cmd->shell->fd[1]);
	*i = *i + 1;
	*j = 0;
	outfile = ft_set_file_bis(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	cmd->shell->fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	ft_error_fd(cmd->shell->fd[1], outfile);
	free (outfile);
}

void	ft_outfile_nosplit(t_cmd *cmd, int i, int *j)
{
	char	*outfile;

	if (cmd->shell->fd[1] != 0)
		close(cmd->shell->fd[1]);
	outfile = ft_set_file(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	cmd->shell->fd[1] = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	ft_error_fd(cmd->shell->fd[1], outfile);
	free (outfile);
}

void	ft_outfile_nosplit_append(t_cmd *cmd, int i, int *j)
{
	char	*outfile;

	*j = *j + 1;
	if (cmd->shell->fd[1] != 0)
		close(cmd->shell->fd[1]);
	outfile = ft_set_file(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	cmd->shell->fd[1] = open(outfile, O_RDWR | O_APPEND | O_CREAT, 0666);
	ft_error_fd(cmd->shell->fd[1], outfile);
	free (outfile);
}

void	ft_outfile_split_append(t_cmd *cmd, int *i, int *j)
{
	char	*outfile;

	if (cmd->shell->fd[1] != 0)
		close(cmd->shell->fd[1]);
	*i = *i + 1;
	*j = 0;
	outfile = ft_set_file_bis(cmd, j, i);
	outfile = ft_check_quote_simple(outfile);
	cmd->shell->fd[1] = open(outfile, O_RDWR | O_APPEND | O_CREAT, 0666);
	ft_error_fd(cmd->shell->fd[1], outfile);
	free (outfile);
}