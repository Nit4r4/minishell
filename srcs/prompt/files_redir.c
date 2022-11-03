/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:47:54 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/01 17:59:28 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	checker_redir_files(t_shell *sh, int i, int j)
{
	int	quote;
	int	redir_file;

	while (j < sh->in[i].nbr_elem)
	{
		trimquotes(sh, "\"", i, j);
		quote = trimquotes(sh, "\'", i, j);
		if (!quote)
			ft_dollar(sh, i, j);
		redir_file = checker_redir(sh, i, j);
		if (redir_file == NO_RESULT)
			break ;
		else if (redir_file > 0)
			continue ;
		j++;
	}
}
