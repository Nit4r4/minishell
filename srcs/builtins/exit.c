/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:32:29 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 13:40:16 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	_get_err_code(int err_code, bool set_err_code)
{
	static int	static_err_code = 0;

	if (set_err_code)
		static_err_code = err_code;
	return (static_err_code);
}

int	get_err_code(void)
{
	return (_get_err_code(0, false));
}

long long	ft_atol(char *str)
{
	long long	n;
	int			is_negative;

	n = 0;
	is_negative = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = (n * 10) + (*str - '0');
		if (n < 0 && is_negative == -1)
			return (0);
		else if (n < 0 && is_negative == 1)
			return (-1);
		str++;
	}
	return (n * is_negative);
}

static bool	is_valid_exit_arg(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd->args && cmd->args[i])
	{
		j = 0;
		while (cmd->args[i][j])
		{
			if (ft_issign(cmd->args[i][j]))
				j++;
			if (!ft_isdigit(cmd->args[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_exit(t_cmd *cmd)
{
	long long	exit_code;
	int			i;

	i = 1;
	if (!cmd->args[1])
	{
		printf("exit\n");
		exit_code = 0;
		exit(exit_code);
		return (exit_code);
	}
	if (cmd->args[i])
		exit_code = ft_atol(cmd->args[i]);
	else
		exit_code = get_err_code();
	if (!is_valid_exit_arg(cmd->args + i) || ft_strlen(cmd->args[i]) > 20)
	{
	    ft_printf("exit: not a valid argument\n");
		exit_code = 255;
	}
	ft_printf("exit\n");
	exit(exit_code);
	return (ft_static(exit_code));
}