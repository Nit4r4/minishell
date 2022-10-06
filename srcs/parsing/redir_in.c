/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:50:17 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 15:51:46 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_infile_nosplit(t_cmd *cmd, int *j, int i)
{
	char	*infile;

	if (cmd->shell->fd[0] < 0)
	{
		infile = ft_set_file(cmd->cmd, j, i);
		infile = ft_check_quote_simple(infile);
		free(infile);
		return ;
	}
	if (cmd->shell->fd[0] != 0)
		close(cmd->shell->fd[0]);
	infile = ft_set_file(cmd->cmd, j, i);
	infile = ft_check_quote_simple(infile);
	cmd->shell->fd[0] = open(infile, O_RDONLY);
	ft_error_fd(cmd->shell->fd[0], infile);
	free (infile);
}

void	ft_infile_split(t_cmd *cmd, int *i, int *j)
{
	char	*infile;

	if (cmd->shell->fd[0] < 0)
	{
		*i = *i + 1;
		*j = 0;
		infile = ft_set_file_bis(cmd->cmd, j, i);
		infile = ft_check_quote_simple(infile);
		free(infile);
		return ;
	}
	if (cmd->shell->fd[0] != 0)
		close(cmd->shell->fd[0]);
	*i = *i + 1;
	*j = 0;
	infile = ft_set_file_bis(cmd->cmd, j, i);
	infile = ft_check_quote_simple(infile);
	cmd->shell->fd[0] = open(infile, O_RDONLY);
	ft_error_fd(cmd->shell->fd[0], infile);
	free (infile);
}

void	ft_exec_in(t_shell *shell)
{
	char	*path;
	int		pid;
	int		sortie;

	path = ft_error_cmd(shell->cmd->commande);
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		dup2(shell->fd_in, STDIN_FILENO);
		close(shell->fd_in);
		execve(path, shell->cmd->commande, shell->envp);
	}
	ft_free_tab_simple(shell->cmd->commande);
	free(path);
	close(shell->fd_in);
	waitpid(pid, &sortie, 0);
	if (!WIFEXITED(sortie))
	{
		ft_static(130);
		return ;
	}
	ft_static(WEXITSTATUS(sortie));
	return ;
}
