/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:09:39 by creyt             #+#    #+#             */
/*   Updated: 2022/11/01 17:38:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_init(t_shell *sh, char *envp[])
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	sh->nbr_env = i;
	sh->env_cpy = malloc(sizeof(char *) * (sh->nbr_env + 1));
	protect_malloc((char *)sh->env_cpy);
	i = 0;
	while (i < sh->nbr_env)
	{
		sh->env_cpy[i] = ft_strdup(envp[i]);
		protect_malloc(sh->env_cpy[i++]);
	}
	sh->env_cpy[i] = NULL;
}

void	protect_malloc(char *s)
{
	if (!s)
		exit(ft_end(ERR_MALL, EXIT_FAILURE, 1));
}
