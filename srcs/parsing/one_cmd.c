/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:26:05 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:41:11 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*ft_sub_pro_one(t_cmd *cmd)
{
	char	*cmd_saved;
	char	*check_path;

	cmd_saved = ft_strdup(cmd->cmd[0]);
	cmd->path_cmd = ft_absolute(cmd->cmd);
	check_path = ft_path(cmd->cmd[0]);
	free(check_path);
	free(cmd_saved);
	return (cmd->path_cmd);
}

int	ft_process_one_classic(t_cmd *cmd, char **g_var)
{
	int		pid;
	int		test;

	if (cmd->cmd[0][0] != '/')
	{
		cmd->path_cmd = ft_path(cmd->cmd[0]);
		if (ft_error(cmd->path_cmd, cmd) == 0)
			return (ft_static(127));
	}
	if (cmd->cmd[0][0] == '/')
		cmd->path_cmd = ft_sub_pro_one(cmd);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		ft_process_onlyone(cmd->path_cmd, cmd->cmd, g_var);
	waitpid(pid, &test, 0);
	if (!WIFEXITED(test))
		return (ft_too_long(cmd->path_cmd, cmd->cmd, ft_static(130)));
	return (ft_too_long(cmd->path_cmd, cmd->cmd, ft_static(WEXITSTATUS(test))));
}

void	ft_fork_or_not(t_cmd *cmd, char **envp_copy)
{
	int	pid;
	int	sortie;

	if ((ft_strcmp(cmd->commande[0], "export") != 0 ||
			(ft_strcmp(cmd->commande[0], "export") == 0 && !cmd->commande[1]))
		&& (ft_strcmp(cmd->commande[0], "cd") != 0)
		&& ft_strcmp(cmd->commande[0], "exit") != 0
		&& ft_strcmp(cmd->commande[0], "unset") != 0)
	{
		pid = fork();
		if (pid == 0)
			ft_execute_inbuilt_fd(cmd->shell->fd_out, cmd->commande, envp_copy);
		ft_free_tab_simple(cmd->commande);
		waitpid(pid, &sortie, 0);
		ft_static(WEXITSTATUS(sortie));
	}
	else
	{
		ft_execute_inbuilt_fd(cmd->shell->fd_out, cmd->commande, envp_copy);
		ft_free_tab_simple(cmd->commande);
	}
}

void	ft_exec_one(t_cmd *cmd, char **g_var)
{
	int	*fd;

	fd = cmd->shell->fd;
	if (fd[0] > 0 && fd[1] > 0)
		ft_exec_in_out(fd, cmd->commande);
	else if (fd[0] > 0 && fd[1] == 0)
		ft_exec_in(fd[0], cmd->commande, g_var);
	else if (fd[0] == 0 && fd[1] > 0)
		ft_exec_out(fd[1], cmd->commande, g_var);
	else if (fd[0] == 0 && fd[1] == 0)
		ft_process_one_classic(cmd->commande, g_var);
	else if (fd[0] < 0)
		ft_free_tab_simple(cmd->commande);
}

void	ft_one(t_cmd *cmd, char **g_var)
{
	cmd->shell->fd = malloc(2 * sizeof(int));
	cmd->shell->fd[0] = 0;
	cmd->shell->fd[1] = 0;
	cmd->cmd = ft_split_modif(cmd->split_pipe[0], ' ', cmd->code_caractere);
	cmd->commande = ft_malloc_tab(cmd->cmd);
	cmd->commande = ft_check_redir(cmd);
	if (cmd->commande[0][0] == '\0')
	{
		ft_free_tab_simple(cmd->cmd);
		ft_free_tab_simple(cmd->commande);
		free(cmd->shell->fd);
		return ;
	}
	define_input_signals_block();
	if (ft_check_builtins(cmd->commande) == 0)
		ft_exec_one(cmd, g_var);
	else
		ft_fork_or_not(cmd, g_var);
	ft_free_tab_simple(cmd->cmd);
	free(cmd->shell->fd);
}
