/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:50:45 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:27 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_check_builtins(char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (1);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd[0], "export") == 0)
		return (1);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (1);
	return (0);
}

void	ft_execute_inbuilt_fd(int fd_out, char **cmd_test, char **envp_copy)
{
	if ((ft_strcmp(cmd_test[0], "echo")) == 0)
		ft_echo_fd(fd_out, cmd_test);
	if (ft_strcmp(cmd_test[0], "export") == 0)
		ft_export_fd_test(fd_out, cmd_test, g_var);
	if (ft_strcmp(cmd_test[0], "env") == 0)
		ft_env_fd(fd_out, envp_copy, g_var);
	if (ft_strcmp(cmd_test[0], "cd") == 0)
		ft_cd(cmd_test, envp_copy);
	if (ft_strcmp(cmd_test[0], "unset") == 0)
		ft_unset(cmd_test);
	if (ft_strcmp(cmd_test[0], "pwd") == 0)
		ft_pwd_fd(fd_out);
	if (ft_strcmp(cmd_test[0], "exit") == 0)
		ft_exit(&(cmd_test[0]));
}

void	ft_execute_inbuilt_fd_multi(int fd_out, char **cmd_test, char **e_c)
{
	if ((ft_strcmp(cmd_test[0], "echo")) == 0)
		ft_echo_fd(fd_out, cmd_test);
	if (ft_strcmp(cmd_test[0], "export") == 0)
		ft_export_fd_multi(fd_out, cmd_test, e_c);
	if (ft_strcmp(cmd_test[0], "env") == 0)
		ft_env_fd(fd_out, e_c, g_var);
	if (ft_strcmp(cmd_test[0], "cd") == 0)
		ft_cd(cmd_test, e_c);
	if (ft_strcmp(cmd_test[0], "unset") == 0)
		ft_unset_multi(cmd_test);
	if (ft_strcmp(cmd_test[0], "pwd") == 0)
		ft_pwd_fd(fd_out);
	if (ft_strcmp(cmd_test[0], "exit") == 0)
		ft_exit(&(cmd_test[0]));
}
