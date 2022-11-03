/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:05:52 by creyt             #+#    #+#             */
/*   Updated: 2022/10/27 11:25:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	b_echo(t_shell *sh, int in)
{
	int		i;

	if (sh->in[in].nbr_elem == 1)
		ft_printf("\n");
	if (sh->in[in].nbr_elem > 1)
	{
		i = 1;
		if (ft_strncmp(sh->in[in].elem->cont[i], "-n", 2) == 0)
			print_echo_n(&sh->in[in], i);
		else
		{
			while (i < sh->in[in].nbr_elem)
			{
				ft_printf("%s", sh->in[in].elem->cont[i++]);
				if (i != sh->in[in].nbr_elem)
					ft_printf(" ");
			}
			ft_printf("\n");
		}
	}
	return (ft_end(NULL, EXIT_SUCCESS, 0));
}

void	print_echo_n(t_input *in, int i)
{
	i = avoid_n(in, i);
	while (i < in->nbr_elem)
	{
		if (ft_strncmp(in->elem->cont[i], "\0", 1))
		{
			ft_printf("%s", in->elem->cont[i]);
			if (i != in->nbr_elem - 1)
				ft_printf(" ");
			i++;
		}
	}
}
