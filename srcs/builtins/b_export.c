/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:05:18 by creyt             #+#    #+#             */
/*   Updated: 2022/10/27 16:42:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	b_export(t_shell *sh, int in)
{
	int		i;
	char	**splited;

	if (sh->in[in].nbr_elem == 1)
		sort_env(sh, in);
	else
	{
		i = 1;
		while (i < sh->in[in].nbr_elem)
		{
			splited = parse_env(sh->in[in].elem->cont[i]);
			add_key(sh, splited[0], splited[1]);
			freetab(splited, 2);
			i++;
		}
	}
	return (ft_end(NULL, EXIT_SUCCESS, 0));
}

void	update_arr(t_shell *sh, char **new_table, int add_key, char *new_val)
{
	if (add_key)
	{
		*new_table = new_val;
		*(new_table + 1) = NULL;
		sh->nbr_env++;
	}
	else
		new_table = NULL;
}

void	update_key(t_shell *sh, char *key, char *val, char **new_table)
{
	int		i;
	int		add_key;
	char	**exist_key;
	char	*new_val;

	i = -1;
	add_key = 1;
	new_val = define_val(key, val);
	while (++i < sh->nbr_env)
	{
		exist_key = parse_env(sh->env_cpy[i]);
		if (!ft_strncmp(key, exist_key[0], ft_strlen(exist_key[0])))
		{
			add_key = 0;
			if (val)
				new_table[i] = ft_strdup(new_val);
			else
				new_table[i] = ft_strdup(sh->env_cpy[i]);
			free(new_val);
		}
		else
			new_table[i] = ft_strdup(sh->env_cpy[i]);
		freetab(exist_key, 2);
	}
	update_arr(sh, &new_table[i], add_key, new_val);
}

void	add_key(t_shell *sh, char *key, char *val)
{
	char	**new_table;
	int		add_key;
	int		i;

	add_key = 1;
	new_table = ft_calloc(sizeof(char *), (sh->nbr_env + 2));
	protect_malloc((char *)new_table);
	i = 0;
	update_key(sh, key, val, new_table);
	freetab(sh->env_cpy, sh->nbr_env);
	dup_table_to_env(sh, new_table);
}

char	*define_val(char *key, char *val)
{
	char	*new_val;
	char	*new_key;
	char	*ret;

	if (val)
	{
		new_key = ft_strjoin(key, "=");
		new_val = ft_strtrim(val, "\"");
		ret = ft_strjoin(new_key, new_val);
		free(new_key);
		free(new_val);
	}
	else
		ret = ft_strdup(key);
	return (ret);
}
