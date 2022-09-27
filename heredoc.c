/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:40:34 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:42 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_check_to_close_open(int *fd, char *infile)
{
	if (fd[0] < 0)
		return ;
	if (fd[0] != 0)
		close(fd[0]);
	fd[0] = open(infile, O_RDONLY);
}

void	ft_write_close(int fd_tmp, char *str_final)
{
	write(fd_tmp, str_final, ft_strlen(str_final));
	close (fd_tmp);
}

void	ft_fd_error(char *magic_word, int *fd)
{
	free(magic_word);
	if (magic_word[0] == '<' || magic_word[0] == '>')
	{
		fd[0] = -1;
		ft_error_fd(fd[0], magic_word);
	}
}

void	ft_index_heredoc(int *i, int *j)
{
	*i = *i + 1;
	*j = 0;
}

void	ft_infile_tmp_split(char **cmd, int *fd, int *i, int *j)
{
	char	*magic_word;
	char	*infile;

	infile = ".tmp_file";
	if (fd[0] < 0)
	{
		ft_index_heredoc(i, j);
		magic_word = ft_set_magic_word_split(cmd, j, *i);
		magic_word = ft_check_quote_simple(magic_word);
		free(magic_word);
		return ;
	}
	ft_index_heredoc(i, j);
	magic_word = ft_set_magic_word_split(cmd, j, *i);
	magic_word = ft_check_quote_simple(magic_word);
	if (magic_word[0] == '<' || magic_word[0] == '>')
	{
		fd[0] = -1;
		ft_error_fd(fd[0], magic_word);
		free(magic_word);
		return ;
	}
	else
		ft_boucle_while(infile, magic_word, fd);
}
