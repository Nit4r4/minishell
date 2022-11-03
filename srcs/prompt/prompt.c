/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:56:12 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/03 10:24:20 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	prompt(char **envp)
{
	t_shell	sh;
	int		i;

	g_exit_stat = 0;
	b_init(&sh, envp);
	while (42)
	{
		if (ft_new_prompt(&sh) == 1)
			continue ;
		prompt_quotes(&sh);
		i = 0;
		exec_redir(&sh);
		while (i < sh.nbr_cmd)
		{
			if (!sh.in[i].elem->cont[0])
				break ;
			cmd_selector(&sh, i);
			i++;
		}
		ft_close(&sh);
		i = 0;
		ft_wait(&sh, i);
		free_sh(&sh);
	}
}

void	ft_close(t_shell *sh)
{
	int	i;

	i = 0;
	while (i < sh->nbr_cmd)
	{
		if (sh->in[i].fd.out > 2)
			close(sh->in[i].fd.out);
		if (sh->in[i].fd.in > 2)
			close(sh->in[i].fd.in);
		i++;
	}
}

int	ft_new_prompt(t_shell *sh)
{
	char			*prompt;
	char			*new_prompt;

	prompt = ft_set_signal();
	signal(SIGINT, SIG_IGN);
	new_prompt = ft_strtrim(prompt, " \t\n\r");
	free(prompt);
	if (!new_prompt)
	{
		freetab(sh->env_cpy, sh->nbr_env);
		exit(ft_end("exit\n", EXIT_SUCCESS, 1));
	}
	if (!new_prompt[0] || parsing_init(new_prompt, sh) == NO_RESULT)
	{
		free(new_prompt);
		return (1);
	}
	add_history(new_prompt);
	free(new_prompt);
	return (0);
}

void	prompt_quotes(t_shell *sh)
{
	int	i;
	int	j;

	i = 0;
	while (i < sh->nbr_cmd)
	{
		init_redir(sh, i);
		j = 0;
		checker_redir_files(sh, i, j);
		if (sh->in[i].pos_red == NO_RESULT)
			break ;
		i++;
	}
}

void	ft_wait(t_shell *sh, int i)
{
	while (i < sh->nbr_cmd)
	{
		if (sh->in[i].pid != NO_RESULT)
		{
			waitpid(sh->in[i].pid, &g_exit_stat, 0);
			if (WIFSIGNALED(g_exit_stat))
				g_exit_stat = ERR_SIGN + g_exit_stat;
			if (WIFEXITED(g_exit_stat))
				g_exit_stat = WEXITSTATUS(g_exit_stat);
		}
		i++;
	}
}
