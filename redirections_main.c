/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:48:27 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:37:41 by vferraro         ###   ########.fr       */
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

	nbr_cmd = ft_nc(cm);
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

char	**ft_check_redir(int *fd, char **cm, char **commande)
{
	int	*c;
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (cm[++i])
	{
		c = ft_code_char(cm[i]);
		j = 0;
		while (cm[i][j] != 0)
		{
			if (((cm[i][j] != '<' && cm[i][j] != '>') || c[j] != 6) && cm[i][j])
				commande[k++] = ft_set_cmd(cm, &j, i, c);
			if ((cm[i][j] == '<' || cm[i][j] == '>') && c[j] == 6)
				ft_big_if(cm, &i, &j, fd);
			if (ft_prob_redir(fd) == 0)
				break ;
		}
		free(c);
	}
	ft_check_nbr_cmd(commande, k, cm);
	return (ft_return_tab(commande));
}
