/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in_out_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:22:45 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 15:35:24 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_set_file(t_cmd *cmd, int *j, int i)
{
	int		start;
	int		len;
	char	*tmp;
	char	*infile;

	if (cmd->cmd[i][*j + 1])
	{
		*j = *j + 1;
		start = *j;
		len = 0;
		while (cmd->cmd[i][*j] != '<' && cmd->cmd[i][*j] != '>' 
            && cmd->cmd[i][*j])
		{
			len++;
			*j = *j + 1;
		}
		tmp = ft_substr(cmd->cmd[i], start, len);
		infile = ft_strdup(tmp);
		free(tmp);
		return (infile);
	}
	return (NULL);
}

char	*ft_set_file_bis(t_cmd *cmd, int *j, int *i)
{
	int		start;
	int		len;
	char	*tmp;
	char	*infile;

	if (cmd->cmd[*i][*j])
	{
		start = *j;
		len = 0;
		while (cmd->cmd[*i][*j] == '<' || cmd->cmd[*i][*j] == '>')
		{
			len++;
			*j = *j + 1;
		}	
		while (cmd->cmd[*i][*j] != '<' && cmd->cmd[*i][*j] != '>' 
            && cmd->cmd[*i][*j])
		{
			len++;
			*j = *j + 1;
		}
		tmp = ft_substr(cmd->cmd[*i], start, len);
		infile = ft_strdup(tmp);
		free(tmp);
		return (infile);
	}
	return (NULL);
}

int	a(int j)
{
	return (j + 1);
}

int	b(int j)
{
	return (j + 2);
}

void	ft_very_first_if(t_cmd *cmd, t_shell *shell, int *i, int *j)
{
    char **c;

    c = cmd->cmd;
	if (c[*i][*j + 1] != '<' && c[*i][*j + 1])
		ft_infile_nosplit(c, shell->fd, j, *i);
	else if (c[*i][*j + 1] != '<' && !c[*i][*j + 1] && c[*i + 1])
		ft_infile_split(c, shell->fd, i, j);
	else if (c[*i][*j + 1] && c[*i][*j + 1] == '<' && c[*i][*j + 2])
		ft_infile_tmp(c, shell->fd, *i, j);
	else if (c[*i][*j + 1] == '<' && !c[*i][*j + 2] && c[*i + 1])
		ft_infile_tmp_split(c, shell->fd, i, j);
	else
		shell->fd[0] = -5;
}