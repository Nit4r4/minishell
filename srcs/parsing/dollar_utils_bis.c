/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:24:32 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 11:20:16 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}

void	ft_free_all(t_cmd *cmd, char *s1, char *s2)
{
	free(s1);
	free(s2);
	free(cmd->code_caractere);
}

char	*ft_strjoin_free_free(t_cmd *cmd, char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		dst = ft_strdup(s2);
		free(cmd->code_caractere);
		free(s2);
		return (dst);
	}
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	ft_free_all(s1, s2, cmd->code_caractere);
	return (dst);
}

char	*ft_return_change(char *str, char **g_var, int start, int len)
{
	char	*change;

	change = NULL;
	if (ft_co(str, g_var, start, len) == 1)
		change = ft_change_value(str, g_var, start, len);
	return (change);
}

char	*ft_strjoin_modif_free_free(char *s1, char const s2, int *c_c)
{
	char	*dst;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		dst = malloc(2);
		dst[0] = s2;
		dst[1] = '\0';
		free(c_c);
		return (dst);
	}
	dst = malloc(ft_strlen(s1) + 2);
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	dst[i] = s2;
	dst[i + 1] = '\0';
	free(s1);
	free(c_c);
	return (dst);
}
