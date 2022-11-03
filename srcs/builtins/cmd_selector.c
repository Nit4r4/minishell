/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_selector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:43:16 by creyt             #+#    #+#             */
/*   Updated: 2022/10/27 11:24:28 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_selector(t_shell *sh, int i)
{
	if (sh->nbr_cmd == 1)
	{
		sh->in[i].pid = NO_RESULT;
		if (builtins_selector(sh, i) == NO_RESULT)
			exec_boarders(sh, i);
	}
	else
		exec_boarders(sh, i);
}

void	bs_fd(t_shell *sh, int i, t_fd *fid)
{
	fid->out = dup(STDOUT_FILENO);
	fid->in = dup(STDIN_FILENO);
	if (sh->in[i].fd.out > 2)
	{
		dup2(sh->in[i].fd.out, STDOUT_FILENO);
		close(sh->in[i].fd.out);
	}
	if (sh->in[i].fd.in > 2)
	{
		dup2(sh->in[i].fd.in, STDIN_FILENO);
		close(sh->in[i].fd.in);
	}
}

int	is_bs(t_shell *sh, int i)
{
	int	bs;

	bs = 1;
	if (ft_strncmp(sh->in[i].elem->cont[0], "echo", 5) == 0)
		bs = 1;
	else if (ft_strncmp(sh->in[i].elem->cont[0], "pwd", 4) == 0)
		bs = 1;
	else if (ft_strncmp(sh->in[i].elem->cont[0], "cd", 3) == 0)
		bs = 1;
	else if (ft_strncmp(sh->in[i].elem->cont[0], "exit", 5) == 0)
		bs = 1;
	else if (ft_strncmp(sh->in[i].elem->cont[0], "env", 4) == 0)
		bs = 1;
	else if (ft_strncmp(sh->in[i].elem->cont[0], "export", 7) == 0)
		bs = 1;
	else if (ft_strncmp(sh->in[i].elem->cont[0], "unset", 6) == 0)
		bs = 1;
	else
		bs = 0;
	return (bs);
}

int	builtins_selector(t_shell *sh, int i)
{
	t_fd	fd_keeper;

	ft_strtolower(sh->in[i].elem->cont[0]);
	if (is_bs(sh, i))
		bs_fd(sh, i, &fd_keeper);
	if (ft_strncmp(sh->in[i].elem->cont[0], "echo", 5) == 0)
		b_echo(sh, i);
	else if (ft_strncmp(sh->in[i].elem->cont[0], "pwd", 4) == 0)
		b_pwd(sh);
	else if (ft_strncmp(sh->in[i].elem->cont[0], "cd", 3) == 0)
		b_cd(sh, i);
	else if (ft_strncmp(sh->in[i].elem->cont[0], "exit", 5) == 0)
		b_exit(sh, i);
	else if (ft_strncmp(sh->in[i].elem->cont[0], "env", 4) == 0)
		b_env(sh);
	else if (ft_strncmp(sh->in[i].elem->cont[0], "export", 7) == 0)
		b_export(sh, i);
	else if (ft_strncmp(sh->in[i].elem->cont[0], "unset", 6) == 0)
		b_unset(sh, i);
	else
		return (NO_RESULT);
	reset_fd(&fd_keeper);
	return (0);
}

char	*ft_strtolower(char *s)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
