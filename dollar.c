/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:55:35 by santonie          #+#    #+#             */
/*   Updated: 2022/09/27 13:39:39 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_co(char *str, char **g_var, int start, int len)
{
	char	*tmp_bis;
	int		k;
	char	*tmp_cmp;

	tmp_bis = ft_substr(str, start, len);
	k = 0;
	if (g_var != NULL)
	{
		while (g_var[k])
		{
			tmp_cmp = ft_tmp_cmp(g_var, tmp_bis, k);
			if (ft_strcmp(tmp_bis, tmp_cmp) != 0)
			{
				free (tmp_cmp);
				k++;
			}
			else
			{
				ft_free_two(tmp_cmp, tmp_bis);
				return (1);
			}
		}
	}
	free (tmp_bis);
	return (0);
}

void	ft_final_part(char *tmp, char *change, int *code_caractere)
{
	tmp = ft_strjoin_free(tmp, change);
	free(change);
	free(code_caractere);
}

char	*ft_sub_dollar(char *s, int *i, char **g_var, char *tmp)
{
	char	*change;
	int		st;
	int		*c_c;
	int		len;

	change = NULL;
	len = 0;
	c_c = ft_code_char(s);
	if (s[*i] == '$' && c_c[*i] != 8 && s[*i + 1] == '?')
	{
		change = ft_itoa(ft_static(300));
		*i = *i + 1;
	}
	else if (s[*i] == '$' && c_c[*i] != 8 && (s[*i + 1] && s[*i + 1] != ' '))
	{
		*i = *i + 1;
		st = *i;
		ft_increase(i, &len, s);
		*i = *i - 1;
		if (ft_co(s, g_var, st, len) == 1)
			change = ft_return_change(s, g_var, st, len);
		else
			return (ft_strjoin_modif_free_free(tmp, '\0', c_c));
	}
	return (ft_strjoin_free_free(tmp, change, c_c));
}

char	*ft_check_dollars(char *str, char **g_var, int *code_caractere)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		if ((str[i] != '$') || (str[i] == '$' && code_caractere[i] == 8)
			|| (str[i] == '?' && str[i - 1] != '$')
			|| (str[i] == '$' && !str[i + 1]) || str[i + 1] == ' ')
			tmp = ft_strjoin_modif_free(tmp, str[i]);
		else
			tmp = ft_sub_dollar(str, &i, g_var, tmp);
		i++;
	}
	free (str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}
