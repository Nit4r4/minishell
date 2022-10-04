/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:44:10 by lbelet            #+#    #+#             */
/*   Updated: 2022/09/27 13:38:48 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_boucle_while(char *infile, char *magic_word, int *fd)
{
	int		fd_tmp;
	char	*str_final;
	char	*str_tmp;

	str_final = NULL;
	fd_tmp = open(infile, O_RDWR | O_TRUNC | O_CREAT, 0666);
	while (1)
	{
		str_tmp = readline("> ");
		if (ft_strcmp(str_tmp, magic_word) != 0)
			str_final = ft_strfinal_join(str_final, str_tmp);
		else if (ft_strncmp(str_tmp, magic_word, ft_strlen(magic_word)) == 0)
		{
			ft_write_close(fd_tmp, str_final);
			break ;
		}
		free (str_tmp);
	}
	ft_free_infile_tmp(str_tmp, magic_word, str_final);
	ft_check_to_close_open(fd, infile);
}

void	ft_infile_tmp(char **cmd, int *fd, int i, int *j)
{
	char	*magic_word;
	char	*infile;

	infile = ".tmp_file";
	*j = *j + 1;
	magic_word = ft_set_magic_word(cmd, j, i);
	ft_check_quote_simple(magic_word);
	if (fd[0] < 0 || magic_word[0] == '<' || magic_word[0] == '>')
	{
		ft_fd_error(magic_word, fd);
		return ;
	}
	else
		ft_boucle_while(infile, magic_word, fd);
}
