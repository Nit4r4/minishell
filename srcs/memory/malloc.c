/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:56:42 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 16:16:44 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	**ft_malloc_tab(char **original)
{
	t_shell	*shell;
	int		i;

	i = 0;
	while (original[i])
		i++;
	shell->sorted = malloc((i + 1) * sizeof(char *));
	shell->sorted[i] = NULL;
	return (shell->sorted);
}

char	**ft_malloc_var(char **original)
{
	t_shell	*shell;
	int		i;

	i = 1;
	while (original[i])
		i++;
	shell->sorted = malloc(i * sizeof(char *));
	shell->sorted[i - 1] = NULL;
	return (shell->sorted);
}
