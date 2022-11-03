/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:15:25 by vferraro          #+#    #+#             */
/*   Updated: 2022/10/27 11:25:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_quotes(t_input *in, char *s)
{
	int	s_quotes;
	int	d_quotes;
	int	i;

	s_quotes = 0;
	d_quotes = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			s_quotes++;
		if (s[i] == '\"')
			d_quotes++;
		i++;
	}
	if (s_quotes % 2 || d_quotes % 2)
		return (1);
	in->nbr_elem += (s_quotes + d_quotes);
	return (0);
}

int	avoid_spaces(char *s, int i)
{
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		return (i);
	}
	return (i);
}

int	avoid_quotes(t_input *in, int i)
{
	while (i < in->nbr_elem)
	{
		if (ft_strncmp(in->elem->cont[i], "\"", 1) == 0)
			i++;
		else if (ft_strncmp(in->elem->cont[i], "\'", 1) == 0)
			i++;
		else
			return (i);
	}
	return (i);
}

int	avoid_n(t_input *in, int i)
{
	while (i < in->nbr_elem)
	{
		if (ft_strncmp(in->elem->cont[i], "-n", 1) == 0)
			i++;
		else
			return (i);
	}
	return (i);
}

void	count_spaces(t_input *in, char *s)
{
	int	i;

	i = 0;
	i = avoid_spaces(s, i);
	while (i < (int) ft_strlen(s))
	{
		if (s[i] == '\"')
		{
			i++;
			while (i < (int) ft_strlen(s) && s[i] != '\"')
				i++;
		}
		else if (s[i] == '\'')
		{
			i++;
			while (i < (int) ft_strlen(s) && s[i] != '\'')
				i++;
		}
		else if (s[i] == ' ' && s[i + 1] == '\0')
			break ;
		else if (s[i] == ' ' && s[i + 1] != ' ')
			in->nbr_elem++;
		i++;
	}
}
