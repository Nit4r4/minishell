/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:01:44 by creyt             #+#    #+#             */
/*   Updated: 2022/10/02 16:19:28 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_write_echo(int fd_out, char *str)
{
	write(fd_out, str, ft_strlen(str));
	write(fd_out, " ", 1);
}

int	ft_echo_fd(int fd_out, t_shell *shell)
{
	int	i;

	if (ft_strncmp(cmd_test[1], "-n", 2) == 0 && !cmd_test[1][2])
	{
		i = 2;
		while (cmd_test[i] && cmd_test[i + 1])
		{
			ft_write_echo(fd_out, cmd_test[i]);
			i++;
		}
		write(fd_out, cmd_test[i], ft_strlen(cmd_test[i]));
	}
	else
	{
		i = 1;
		while (cmd_test[i] && cmd_test[i + 1])
		{
			ft_write_echo(fd_out, cmd_test[i]);
			i++;
		}
		write(fd_out, cmd_test[i], ft_strlen(cmd_test[i]));
		write(fd_out, "\n", 1);
	}
	exit(0);
}

int	ft_write_tmp(int fd_out, char *str)
{
	write(fd_out, &str, ft_strlen(str));
	return (0);
}

/*
int	ft_echo(char **tab)
{
	int	i;

	i = 1;
	if (!tab[i])
		printf("\n");
	else if (ft_strncmp(tab[i], "-n\0", 3) == 0 && !tab[i + 1])
		return (0);
	else if (ft_strncmp(tab[i], "-n\0", 3) == 0 && tab[i + 1])
	{
		while (tab[++i])
		{
			printf("%s", tab[i]);
			if (tab[i + 1])
				printf(" ");
		}
	}
	else
	{
		i = i - 1;
		while (tab[++i])
			printf("%s", tab[i]);
		printf("\n");
	}
	return (0);
}
*/
/* main pwd
int	main(int argc, char **argv)
{
	(void) argv;
	if (argc >= 2)
		ft_pwd();
	else
		printf("error argument");
}
*/
/* main echo
int	main(int argc, char **argv)
{
	if (argc >= 2)
		ft_echo(argv);
	else
		printf("error argument");
}
*/
