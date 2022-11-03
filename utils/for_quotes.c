/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:12:33 by creyt             #+#    #+#             */
/*   Updated: 2022/10/25 14:14:23 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	trimquotes(t_shell *sh, char *s, int in, int i)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if (ft_strncmp(sh->in[in].elem->cont[i], s, ft_strlen(s)) == 0)
	{
		tmp = sh->in[in].elem->cont[i];
		sh->in[in].elem->cont[i] = ft_strtrim(sh->in[in].elem->cont[i], s);
		free(tmp);
		ret = 1;
	}
	return (ret);
}
