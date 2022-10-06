/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:40:00 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 14:43:04 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_set_cmd(t_cmd *cmd, int *j, int i)
{
	int		start;
	int		len;
	char	*tmp;
	char	*commande;

	start = *j;
	len = 0;
	while (((cmd->cmd[i][*j] != '<' && cmd->cmd[i][*j] != '>')
			|| cmd->code_caractere[*j] != 6) && cmd->cmd[i][*j])
	{
		len++;
		*j = *j + 1;
	}
	tmp = ft_substr(cmd->cmd[i], start, len);
	commande = ft_strdup(tmp);
	free(tmp);
	return (commande);
}