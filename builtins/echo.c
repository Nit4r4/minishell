/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:01:44 by creyt             #+#    #+#             */
/*   Updated: 2022/09/22 14:54:29 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc >= 2)
		ft_env(argv[1]);
	else
		printf("error argument");
}

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
