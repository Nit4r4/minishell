/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:45:35 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:32 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_env_fd(int fd_out, char **envp, char **g_var)
{
	int	j;

	j = 0;
	(void) envp;
	if (g_var)
	{
		while (g_var[j])
		{
			write(fd_out, g_var[j], ft_strlen(g_var[j]));
			write(fd_out, "\n", 1);
			j++;
		}
	}
	exit (0);
}
