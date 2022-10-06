/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:45:35 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 11:27:16 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_env_fd(t_shell *shell, int fd_out, char **g_var)
{
	int	j;

	j = 0;
	(void) shell->envp;
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
