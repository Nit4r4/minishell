/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:56:50 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/01 17:45:06 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_redir(t_shell *sh, int in)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (j < sh->in[in].nbr_elem)
	{
		if (ft_strncmp(sh->in[in].elem->cont[j], ">", 2) == 0)
			count++;
		else if (ft_strncmp(sh->in[in].elem->cont[j], "<", 2) == 0)
			count++;
		else if (ft_strncmp(sh->in[in].elem->cont[j], ">>", 3) == 0)
			count++;
		else if (ft_strncmp(sh->in[in].elem->cont[j], "<<", 3) == 0)
			count++;
		j++;
	}
	return (count);
}

void	init_redir(t_shell *sh, int in)
{
	sh->in[in].nbr_redir = count_redir(sh, in);
	sh->in[in].pos_red = 0;
	if (sh->in[in].nbr_redir > 0)
	{
		sh->in[in].red = ft_calloc(sizeof(t_redir), sh->in[in].nbr_redir);
		protect_malloc((char *)sh->in[in].red);
	}
}

void	shift_elem(t_shell *sh, int in, int i)
{
	int	j;

	j = i;
	while (j < sh->in[in].nbr_elem)
	{
		sh->in[in].elem->cont[j] = sh->in[in].elem->cont[j + 1];
		j++;
	}
	sh->in[in].nbr_elem--;
}

int	pop_redir(t_shell *sh, int in, int i)
{
	int	j;

	j = sh->in[in].pos_red;
	sh->in[in].red[j].chevron = sh->in[in].elem->cont[i];
	shift_elem(sh, in, i);
	if (i < sh->in[in].nbr_elem)
	{
		sh->in[in].red[j].file = sh->in[in].elem->cont[i];
		shift_elem(sh, in, i);
	}
	else
	{
		sh->in[in].pos_red = NO_RESULT;
		return (ft_end(ERR_RDIR, ERR_REDIR, 1));
	}
	sh->in[in].pos_red++;
	return (sh->in[in].pos_red);
}

int	checker_redir(t_shell *sh, int in, int i)
{
	int	err;

	err = 0;
	if (ft_strncmp(sh->in[in].elem->cont[i], ">", 2) == 0)
	{
		err = pop_redir(sh, in, i);
	}
	else if (ft_strncmp(sh->in[in].elem->cont[i], "<", 2) == 0)
	{
		err = pop_redir(sh, in, i);
	}
	else if (ft_strncmp(sh->in[in].elem->cont[i], ">>", 3) == 0)
	{
		err = pop_redir(sh, in, i);
	}
	else if (ft_strncmp(sh->in[in].elem->cont[i], "<<", 3) == 0)
	{
		err = pop_redir(sh, in, i);
	}
	return (err);
}
