/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:48:27 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:41:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	**ft_return_tab(char **commande)
{
	int	i;

	i = -1;
	while (commande[++i])
		commande[i] = ft_check_quote_simple(commande[i]);
	return (commande);
}

void	ft_check_nbr_cmd(char **commande, int k, char **cm)
{
	int	nbr_cmd;

	nbr_cmd = ft_nc(cmd);
	if (k == 0)
	{
		commande[k] = ft_strdup("\0");
		if (nbr_cmd > 1)
		{
			while (++k < nbr_cmd)
				commande[k] = NULL;
		}
	}
	else
		commande[k] = NULL;
}

int	ft_prob_redir(int *fd)
{
	if (fd[0] == -5 || fd[1] == -5)
	{
		printf("Probleme de redirection\n");
		ft_static(258);
		return (0);
	}
	return (1);
}

void	ft_big_if(char **cm, int *i, int *j, int *fd)
{
	while (cm[*i][*j])
	{
		ft_files(cm, fd, j, i);
		if (fd[0] == -5 || fd[1] == -5)
			return ;
	}
}

char	**ft_check_redir(t_cmd *cmd)
{
	int	*c;
	int	i;
	int	j;

	i = -1;
	cmd->k = 0;
	while (cmd->cm[++i])
	{
		c = ft_code_char(cmd->cm[i]);
		j = 0;
		while (cmd->cm[i][j] != 0)
		{
			if (((cmd->cm[i][j] != '<' && cmd->cm[i][j] != '>') || c[j] != 6) && cmd->cm[i][j])
				cmd->commande[cmd->k++] = ft_set_cmd(cm, &j, i, c);
			if ((cmd->cm[i][j] == '<' || cmd->cm[i][j] == '>') && c[j] == 6)
				ft_big_if(cmd->cm, &i, &j, cmd->shell->fd);
			if (ft_prob_redir(cmd->shell->fd) == 0)
				break ;
		}
		free(c);
	}
	ft_check_nbr_cmd(cmd);
	return (ft_return_tab(cmd->commande));
}
