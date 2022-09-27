/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:56:42 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:38:32 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	**ft_malloc_tab(char **original)
{
	int		i;
	char	**sorted;

	i = 0;
	while (original[i])
		i++;
	sorted = malloc((i + 1) * sizeof(char *));
	sorted[i] = NULL;
	return (sorted);
}

char	**ft_malloc_var(char **original)
{
	int		i;
	char	**sorted;

	i = 1;
	while (original[i])
		i++;
	sorted = malloc(i * sizeof(char *));
	sorted[i - 1] = NULL;
	return (sorted);
}
