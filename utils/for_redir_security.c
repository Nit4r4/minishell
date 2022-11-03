/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_redir_security.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:09:16 by vferraro          #+#    #+#             */
/*   Updated: 2022/10/27 14:20:16 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	more_security_in(t_shell *sh, int i)
{
	if (sh->in[i].fd.in > 2)
		close(sh->in[i].fd.in);
}

void	more_security_out(t_shell *sh, int i)
{
	if (sh->in[i].fd.out > 2)
		close(sh->in[i].fd.out);
}
