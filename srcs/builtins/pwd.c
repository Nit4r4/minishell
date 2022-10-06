/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:20:45 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 13:08:22 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(void)
{
	t_shell *shell;

	shell->cwd = NULL;
	shell->cwd = getcwd(shell->cwd, 0);
	if (shell->cwd == NULL)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	else
		ft_printf("%s\n", shell->cwd);
	return (EXIT_SUCCESS);
}

int	ft_pwd_fd(t_shell *shell)
{
	shell->cwd = NULL;
	shell->cwd = getcwd(shell->cwd, 0);
	if (shell->cwd == NULL)
	{
		perror("Error");
		exit (1);
	}
	else
		ft_printf("%s\n", shell->cwd);
	exit (0);
}