/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:27:08 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 13:41:07 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_no_in_process(t_shell *shell)
{
	char	*path_cmd;

	path_cmd = ft_error_cmd(shell->cmd);
	dup2(shell->fd_out, STDOUT_FILENO);
	close(shell->fd_in);
	close(shell->fd_out);
	execve(path_cmd, shell->cmd, shell->envp);
}

void	ft_inbuilts(t_cmd *cmd)
{
	char	**envp;

	envp = cmd->shell->envp;
	if (cmd->fd_redir[1] == 0)
	{
		close(cmd->fd_pipe[0][0]);
		ft_execute_inbuilt_fd_multi(cmd->fd_pipe[0][1], cmd->commande, envp);
	}
	else
	{
		close(cmd->fd_pipe[0][0]);
		close(cmd->fd_pipe[0][1]);
		ft_execute_inbuilt_fd_multi(cmd->fd_redir[1], cmd->commande, envp);
	}
}

void	ft_exec_first(t_cmd *cmd)
{
	char	**envp;

	envp = cmd->shell->envp;
	if (cmd->fd_redir[0] > 0 && cmd->fd_redir[1] > 0)
		ft_process_in_out(cmd->fd_redir, cmd->fd_pipe, cmd->commande, envp);
	else if (cmd->fd_redir[0] > 0 && cmd->fd_redir[1] == 0)
		ft_process_in(cmd->fd_redir, cmd->fd_pipe, cmd->commande, envp);
	else if (cmd->fd_redir[0] == 0 && cmd->fd_redir[1] > 0)
		ft_process_out(cmd->fd_redir, cmd->fd_pipe, cmd->commande, envp);
	else if (cmd->fd_redir[0] == 0 && cmd->fd_redir[1] == 0)
		ft_no_in_process(cmd->shell); // verifier si ca fonctionne sans les arguments complet sinon modifier
	else if (cmd->fd_redir[0] < 0)
		ft_prob_infile(cmd->commande);
}

void	ft_first_process(t_cmd *cmd, char **split_pipe)
{
	char	**split_space;

	cmd->fd_redir = malloc(2 * sizeof(int));
	cmd->fd_redir[0] = 0;
	cmd->fd_redir[1] = 0;
	if (0 < 1)
	{
		split_space = ft_split_modif(split_pipe[0], ' ',
				ft_code_char(split_pipe[0]));
		cmd->commande = ft_malloc_tab(split_space);
		ft_check_redir(cmd->fd_redir, split_space, cmd->commande);
		if (cmd->commande[0][0] == '\0')
		{
			ft_free_tab_simple(split_space);
			ft_free_tab_simple(cmd->commande);
			free(cmd->fd_redir);
			exit(130);
		}
		if (ft_check_builtins(cmd->commande) == 0)
			ft_exec_first(cmd);
		ft_inbuilts(cmd);
	}
}
