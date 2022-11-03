/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:10:18 by creyt             #+#    #+#             */
/*   Updated: 2022/10/27 16:42:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_shell *sh, int in, char **elem)
{
	int		i;
	char	**export;

	if (sh->in[in].nbr_elem == 1)
	{
		i = 0;
		while (i < sh->nbr_env)
		{
			export = parse_env(elem[i]);
			if (export[1])
				ft_printf("declare -x %s=\"%s\"\n", export[0], export[1]);
			else if (export[0])
				ft_printf("declare -x %s\n", export[0]);
			i++;
			freetab(export, 2);
		}
	}
}

char	**parse_env(char *s)
{
	char	**elem;

	elem = ft_split(s, '=');
	return (elem);
}

char	**dup_env(t_shell *sh)
{
	int		i;
	char	**export;

	export = malloc(sizeof(char *) * sh->nbr_env);
	protect_malloc((char *)export);
	i = 0;
	while (i < sh->nbr_env)
	{
		export[i] = ft_strdup(sh->env_cpy[i]);
		i++;
	}
	return (export);
}

void	sort_env(t_shell *sh, int in)
{
	int		i;
	int		j;
	char	*tmp;
	char	**export;

	export = dup_env(sh);
	i = 0;
	while (i < sh->nbr_env)
	{
		j = i + 1;
		while (j < sh->nbr_env)
		{
			if (ft_strncmp(export[j], export[i], MAX_PATH) < 0)
			{
				tmp = export[i];
				export[i] = export[j];
				export[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_env(sh, in, export);
	freetab(export, sh->nbr_env);
}

void	dup_table_to_env(t_shell *sh, char **table)
{
	int	i;

	sh->env_cpy = malloc (sizeof(char *) * (sh->nbr_env + 1));
	protect_malloc((char *)sh->env_cpy);
	i = -1;
	while (++i < sh->nbr_env)
		sh->env_cpy[i] = table[i];
	sh->env_cpy[i] = NULL;
	free(table);
}
