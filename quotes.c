/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:37:01 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:01 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_subopen_code_caractere(char *str, int i)
{
	if (str[i] == 34)
		return (1);
	if (str[i] == 39)
		return (3);
	return (0);
}

void	ft_init_int(int *j, int *c_q, int *k)
{
	*j = 0;
	*c_q = 0;
	*k = 0;
}

char	*ft_check_quote_simple(char *tab)
{
	int		c_q;
	int		j;
	int		k;
	char	*temp;

	temp = malloc(400 * sizeof(char));
	ft_init_int(&j, &c_q, &k);
	while (tab[j])
	{
		if ((tab[j] == 34 || tab[j] == 39) && c_q == 0)
			c_q = ft_subopen_code_caractere(tab, j);
		else if ((tab[j] == 34 && c_q == 1) || (tab[j] == 39 && c_q == 3))
			c_q = 0;
		else if ((c_q == 0) || (c_q == 1 && tab[j] != 34)
			|| (c_q == 3 && tab[j] != 39))
			temp[k++] = tab[j];
		j++;
	}
	temp[k] = '\0';
	free(tab);
	tab = ft_strdup(temp);
	free(temp);
	return (tab);
}

int	ft_check_close_quote(char *str)
{
	int		c_q;
	int		j;
	int		k;
	char	*temp;

	temp = malloc(400 * sizeof(char));
	ft_init_int(&j, &c_q, &k);
	while (str[j])
	{
		if ((str[j] == 34 || str[j] == 39) && c_q == 0)
			c_q = ft_subopen_code_caractere(str, j);
		else if ((str[j] == 34 && c_q == 1) || (str[j] == 39 && c_q == 3))
			c_q = 0;
		else if ((c_q == 0) || (c_q == 1 && str[j] != 34)
			|| (c_q == 3 && str[j] != 39))
			temp[k++] = str[j];
		j++;
	}
	temp[k] = '\0';
	free(temp);
	if (c_q != 0)
		free(str);
	return (c_q);
}
