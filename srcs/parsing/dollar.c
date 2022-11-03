/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:45:26 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/01 13:08:22 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	asc_question(t_shell *sh, int in, int i)
{
	if (sh->in[in].elem->cont[i][1] == '?')
	{
		free(sh->in[in].elem->cont[i]);
		sh->in[in].elem->cont[i] = ft_itoa(g_exit_stat);
	}
}

void	ft_dollar(t_shell *sh, int in, int i)
{
	char	*tmp;
	char	**env_tmp;
	int		j;

	tmp = ft_strchr(sh->in[in].elem->cont[i], '$');
	while (tmp)
	{
		asc_question(sh, in, i);
		tmp = ft_strtrim(sh->in[in].elem->cont[i], "$");
		j = where_in_env(sh, tmp, ft_strlen(tmp) + 1);
		if (j == NO_RESULT)
		{
			tmp = find_dollar(&sh->in[in], j, tmp, i);
			continue ;
		}
		free (sh->in[in].elem->cont[i]);
		env_tmp = parse_env(sh->env_cpy[j]);
		sh->in[in].elem->cont[i] = ft_strdup(env_tmp[1]);
		freetab(env_tmp, 2);
		free (tmp);
		tmp = ft_strchr(sh->in[in].elem->cont[i], '$');
	}
}

char	*find_dollar(t_input *in, int j, char *tmp, int i)
{
	j = ft_strlen(tmp) + 1;
	free(tmp);
	if (j < (int)ft_strlen(in->elem->cont[i]))
		tmp = ft_strchr(in->elem->cont[i] + j, '$');
	else
		tmp = NULL;
	return (tmp);
}
