/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:46:28 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 16:30:47 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_fd(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->env)
	{
		while (shell->env[i])
		{
			ft_printf("%s\n", shell->env[i]);
			i++;
		}
	}
	exit (0);
}
