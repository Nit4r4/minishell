/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:40:34 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*ft_last_part(char *tmp)
{
	char	*infile;

	infile = ft_strdup(tmp);
	free(tmp);
	return (infile);
}

char	*ft_set_magic_word(char **cmd, int *j, int i)
{
	int		start;
	int		len;
	char	*tmp;
	char	*infile;

	if (cmd[i][*j + 1])
	{
		*j = *j + 1;
		start = *j;
		len = 0;
		while (cmd[i][*j] == '<' || cmd[i][*j] == '>')
		{
			len++;
			*j = *j + 1;
		}	
		while (cmd[i][*j] != '<' && cmd[i][*j] != '>' && cmd[i][*j])
		{
			len++;
			*j = *j + 1;
		}
		tmp = ft_substr(cmd[i], start, len);
		infile = ft_last_part(tmp);
		return (infile);
	}
	return (NULL);
}

char	*ft_set_magic_word_split(char **cmd, int *j, int i)
{
	int		start;
	int		len;
	char	*tmp;
	char	*infile;

	if (cmd[i][*j])
	{
		start = *j;
		len = 0;
		while (cmd[i][*j] == '<' || cmd[i][*j] == '>')
		{
			len++;
			*j = *j + 1;
		}
		while (cmd[i][*j] != '<' && cmd[i][*j] != '>' && cmd[i][*j])
		{
			len++;
			*j = *j + 1;
		}
		tmp = ft_substr(cmd[i], start, len);
		infile = ft_strdup(tmp);
		free(tmp);
		return (infile);
	}
	return (NULL);
}

char	*ft_strfinal_join(char *str_final, char *str_tmp)
{
	str_final = ft_strjoin_free(str_final, str_tmp);
	str_final = ft_strjoin_free(str_final, "\n");
	return (str_final);
}

void	ft_free_infile_tmp(char *str_tmp, char *magic_word, char *str_final)
{
	free(str_tmp);
	free(magic_word);
	free(str_final);
}
