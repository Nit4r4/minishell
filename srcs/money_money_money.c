/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   money_money_money.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:45:26 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/22 16:30:07 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Check strict caracters in a given str and return them */
int	ft_no_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == ' ' || str[i] == '/'
			|| str[i] == '\0' || str[i] == '\'')
			return (i);
		if (str[i + 1] && str[i + 1] == '$')
			return (i + 1);
		i++;
	}
	return (i);
}
