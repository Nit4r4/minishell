/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:45:52 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 15:00:48 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_return_tab(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->commande[++i])
		cmd->commande[i] = ft_check_quote_simple(cmd->commande[i]);
	return (cmd->commande);
}

void	ft_check_nbr_cmd(t_cmd *cmd, int k)
{
	int	nbr_cmd;

	nbr_cmd = ft_nc(cmd->cm);
	if (k == 0)
	{
		cmd->commande[k] = ft_strdup("\0");
		if (nbr_cmd > 1)
		{
			while (++k < nbr_cmd)
				cmd->commande[k] = NULL;
		}
	}
	else
		cmd->commande[k] = NULL;
}

int	ft_prob_redir(t_shell *shell)
{
	if (shell->fd[0] == -5 || shell->fd[1] == -5)
	{
		printf("Probleme de redirection\n");
		ft_static(258);
		return (0);
	}
	return (1);
}

void	ft_big_if(t_cmd *cmd, int *i, int *j)
{
	while (cmd->cm[*i][*j])
	{
		ft_files(cmd->cm, cmd->shell->fd, j, i);
		if (cmd->shell->fd[0] == -5 || cmd->shell->fd[1] == -5)
			return ;
	}
}

char	**ft_check_redir(t_cmd *cmd)
{
    int *cc;
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (cmd->cm[++i])
	{
		cmd->code_caractere = ft_code_char(cmd->cm[i]);
        cc = cmd->code_caractere;
		j = 0;
		while (cmd->cm[i][j] != 0)
		{
			if (((cmd->cm[i][j] != '<' && cmd->cm[i][j] != '>') || cc[j] != 6) && cmd->cm[i][j])
				cmd->commande[k++] = ft_set_cmd(cmd, &j, i);
			if ((cmd->cm[i][j] == '<' || cmd->cm[i][j] == '>') && cc[j] == 6)
				ft_big_if(cmd, &i, &j);
			if (ft_prob_redir(cmd->shell->fd) == 0)
				break ;
		}
		free(cc);
	}
	ft_check_nbr_cmd(cmd, k);
	return (ft_return_tab(cmd->commande));
}