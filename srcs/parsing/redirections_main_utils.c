/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_main_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:48:27 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:37:44 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*ft_set_cmd(char **cmd, int *j, int i, int *code_caractere)
{
	int		start;
	int		len;
	char	*tmp;
	char	*commande;

	start = *j;
	len = 0;
	while (((cmd[i][*j] != '<' && cmd[i][*j] != '>')
			|| code_caractere[*j] != 6) && cmd[i][*j])
	{
		len++;
		*j = *j + 1;
	}
	tmp = ft_substr(cmd[i], start, len);
	commande = ft_strdup(tmp);
	free(tmp);
	return (commande);
}
