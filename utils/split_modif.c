/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:14:18 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 14:14:55 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_get_nbr_word_modif(const char *str, char c, int *code_caractere)
{
	int	nbr;
	int	verif;
	int	i;

	verif = 0;
	nbr = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*str == c && code_caractere[i] == 6)
		{
			verif = 0;
			str++;
			i++;
			continue ;
		}
		if (!verif)
		{
			verif = 1;
			nbr++;
		}
		str++;
		i++;
	}
	return (nbr);
}

void	ft_index(int *k, int *j)
{
	*k = *k + 1;
	*j = *j + 1;
}

void	ft_get_words_modif(char **tab, char *str, char c, int *code_caractere)
{
	int	i;
	int	j;
	int	k;
	int	n;

	n = ft_get_nbr_word_modif(str, c, code_caractere);
	i = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (*str == c && (code_caractere[k]) == 6)
		{
			str++;
			k++;
		}
		while ((*(str + j) && *(str + j) != c) || (*(str + j) == c
				&& (code_caractere[k] != 6)))
			ft_index(&k, &j);
		tab[i] = ft_substr(str, 0, j);
		str += j;
		i++;
	}
}

char	**ft_split_modif(char *s, char c, int *code_caractere)
{
	int		n;
	char	**tab;

	if (!s)
		return (NULL);
	n = ft_get_nbr_word_modif(s, c, code_caractere);
	tab = malloc((n + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[n] = NULL;
	ft_get_words_modif(tab, s, c, code_caractere);
	return (tab);
}