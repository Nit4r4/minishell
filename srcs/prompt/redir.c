/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:48:14 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/01 14:50:42 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_redir(t_shell *sh)
{
	init_fd(sh);
	run_fd(sh);
}

// '<' read th fd
void	redir_input(t_shell *sh, int i, int j)
{
	int	fd;

	fd = open(sh->in[i].red[j].file, O_RDONLY);
	if (fd == NO_RESULT)
		ft_end(ERR_FILE, EXIT_FAILURE, 1);
	else
	{
		more_security_in(sh, i);
		sh->in[i].fd.in = fd;
	}
}

// '>' write in the fd
void	redir_output(t_shell *sh, int i, int j)
{
	int	fd;

	fd = open(sh->in[i].red[j].file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == NO_RESULT)
		ft_end(ERR_FILE, EXIT_FAILURE, 1);
	else
	{
		more_security_out(sh, i);
		sh->in[i].fd.out = fd;
	}
}

// '>>' ajoute a la fin du fichier sans ecraser le fichier
void	append_in(t_shell *sh, int i, int j)
{
	int	fd;

	fd = open(sh->in[i].red[j].file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd == NO_RESULT)
		ft_end(ERR_FILE, EXIT_FAILURE, 1);
	else
	{
		more_security_out(sh, i);
		sh->in[i].fd.out = fd;
	}
}

// '<<'
void	heredoc(t_shell *sh, int i, int j)
{
	int		fd[2];
	char	*limiter;
	char	*h_prompt;

	if (pipe(fd) == NO_RESULT)
		ft_end(ERR_PIPE, EXIT_FAILURE, 1);
	limiter = sh->in[i].red[j].file;
	h_prompt = NULL;
	while (1)
	{
		h_prompt = readline("> ");
		if (!h_prompt
			|| ft_strncmp(h_prompt, limiter, (ft_strlen(limiter) + 1)) == 0)
			break ;
		ft_putendl_fd(h_prompt, fd[1]);
		free(h_prompt);
	}
	free(h_prompt);
	close(fd[1]);
	more_security_in(sh, i);
	sh->in[i].fd.in = fd[0];
}
