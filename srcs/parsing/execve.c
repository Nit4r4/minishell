/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:36:29 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/01 17:39:19 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_boarders(t_shell *sh, int in)
{
	int			i;
	int			ok;

	ok = 0;
	signal(SIGINT, sig_double);
	signal(SIGQUIT, sig_double);
	sh->in[in].pid = fork();
	if (sh->in[in].pid == 0)
	{
		if (builtins_selector(sh, in) == NO_RESULT)
		{
			if (on_my_way(sh, ok, sh->in[in].elem->cont[0], in) != 1)
			{
				i = where_in_env(sh, "PATH", 5);
				execution(sh, in, i, ok);
			}
		}
		freetab(sh->env_cpy, sh->nbr_env);
		free_sh(sh);
		exit (g_exit_stat);
	}
}

int	exec_middle(t_shell *sh, int in, int ok, int i)
{
	char		**tdpp;
	char		**tmp;
	char		*cmd_path;

	tmp = parse_env(sh->env_cpy[i]);
	tdpp = ft_split(tmp[1], ':');
	freetab(tmp, 2);
	i = 0;
	while (tdpp[i])
	{
		cmd_path = ft_strjoin(tdpp[i], "/");
		cmd_path = ft_strjoin_free(cmd_path, sh->in[in].elem->cont[0]);
		ok = on_my_way(sh, ok, cmd_path, in);
		if (ok == 1)
		{
			free(cmd_path);
			free_all(sh);
			freetab(tdpp, len_tab(tdpp));
			exit (ft_end(ERR_EXE, EXIT_FAILURE, 1));
		}
		i++;
		free(cmd_path);
	}
	freetab(tdpp, i + 1);
	return (ok);
}

int	on_my_way(t_shell *sh, int ok, char *cmd_path, int in)
{
	if (!access(cmd_path, X_OK))
	{
		if (sh->in[in].fd.out > 2)
			dup2(sh->in[in].fd.out, STDOUT_FILENO);
		if (sh->in[in].fd.in > 2)
			dup2(sh->in[in].fd.in, STDIN_FILENO);
		ft_close(sh);
		execve(cmd_path, sh->in[in].elem->cont, sh->env_cpy);
		ok = 1;
	}
	return (ok);
}

void	execution(t_shell *sh, int in, int i, int ok)
{
	if (i == NO_RESULT)
		msg_cmd_404(sh, in);
	else
	{
		ok = exec_middle(sh, in, ok, i);
		if (ok == 0)
			msg_cmd_404(sh, in);
	}
}

int	len_tab(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}
