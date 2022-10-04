/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:26:05 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:06 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*ft_sub_pro_one(char *path_cmd, char **cmd)
{
	char	*cmd_saved;
	char	*check_path;

	cmd_saved = ft_strdup(cmd[0]);
	path_cmd = ft_absolute(cmd);
	check_path = ft_path(cmd[0]);
	free(check_path);
	free(cmd_saved);
	return (path_cmd);
}

int	ft_process_one_classic(char **cmd, char **g_var)
{
	int		pid;
	char	*path_cmd;
	int		test;

	if (cmd[0][0] != '/')
	{
		path_cmd = ft_path(cmd[0]);
		if (ft_error(path_cmd, cmd) == 0)
			return (ft_static(127));
	}
	if (cmd[0][0] == '/')
		path_cmd = ft_sub_pro_one(path_cmd, cmd);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		ft_process_onlyone(path_cmd, cmd, g_var);
	waitpid(pid, &test, 0);
	if (!WIFEXITED(test))
		return (ft_too_long(path_cmd, cmd, ft_static(130)));
	return (ft_too_long(path_cmd, cmd, ft_static(WEXITSTATUS(test))));
}

void	ft_fork_or_not(char **commande, char **envp_copy, int fd_out)
{
	int	pid;
	int	sortie;

	if ((ft_strcmp(commande[0], "export") != 0
			|| (ft_strcmp(commande[0], "export") == 0 && !commande[1]))
		&& (ft_strcmp(commande[0], "cd") != 0)
		&& ft_strcmp(commande[0], "exit") != 0
		&& ft_strcmp(commande[0], "unset") != 0)
	{
		pid = fork();
		if (pid == 0)
			ft_execute_inbuilt_fd(fd_out, commande, envp_copy);
		ft_free_tab_simple(commande);
		waitpid(pid, &sortie, 0);
		ft_static(WEXITSTATUS(sortie));
	}
	else
	{
		ft_execute_inbuilt_fd(fd_out, commande, envp_copy);
		ft_free_tab_simple(commande);
	}
}

void	ft_exec_one(int *fd, char **commande, char **g_var)
{
	if (fd[0] > 0 && fd[1] > 0)
		ft_exec_in_out(fd, commande);
	else if (fd[0] > 0 && fd[1] == 0)
		ft_exec_in(fd[0], commande, g_var);
	else if (fd[0] == 0 && fd[1] > 0)
		ft_exec_out(fd[1], commande, g_var);
	else if (fd[0] == 0 && fd[1] == 0)
		ft_process_one_classic(commande, g_var);
	else if (fd[0] < 0)
		ft_free_tab_simple(commande);
}

void	ft_one(char **split_pipe, char **g_var, int *code_caractere)
{
	char	**cmd;
	int		*fd;
	char	**commande;

	fd = malloc(2 * sizeof(int));
	fd[0] = 0;
	fd[1] = 0;
	cmd = ft_split_modif(split_pipe[0], ' ', code_caractere);
	commande = ft_malloc_tab(cmd);
	commande = ft_check_redir(fd, cmd, commande);
	if (commande[0][0] == '\0')
	{
		ft_free_tab_simple(cmd);
		ft_free_tab_simple(commande);
		free(fd);
		return ;
	}
	define_input_signals_block();
	if (ft_check_builtins(commande) == 0)
		ft_exec_one(fd, commande, g_var);
	else
		ft_fork_or_not(commande, g_var, fd[1]);
	ft_free_tab_simple(cmd);
	free(fd);
}
