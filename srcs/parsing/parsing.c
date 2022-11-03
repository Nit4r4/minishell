/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:00:11 by vferraro          #+#    #+#             */
/*   Updated: 2022/10/27 16:42:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parsing_init(char *args, t_shell *sh)
{
	int		i;
	char	**input;

	i = 0;
	sh->nbr_cmd = 0;
	if (args)
	{
		sh->nbr_cmd = 1;
		if (nbr_cmd(sh, args, i) == NO_RESULT)
			return (NO_RESULT);
	}
	sh->in = ft_calloc(sizeof(t_input), sh->nbr_cmd + 1);
	i = -1;
	input = ft_split_ex(args, '|');
	if (parsing_misc(sh, i, input) == NO_RESULT)
		return (NO_RESULT);
	freetab(input, sh->nbr_cmd);
	return (EXIT_SUCCESS);
}

void	parsing_elem(t_shell *sh, char *s, int in)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] && n < sh->in[in].nbr_elem)
	{
		i += (each_elem(&sh->in[in], s, i, n++));
		if (n == sh->in[in].nbr_elem)
			break ;
		i++;
	}
	sh->in[in].elem->cont[n] = NULL;
}

int	each_elem(t_input *in, char *s, int i, int n)
{
	int		j;
	char	*tmp;

	s = ft_substr(s, avoid_spaces(s, i), ft_strlen(s));
	tmp = ft_strtrim(s, " \t\n\r");
	free (s);
	s = tmp;
	i = 0;
	j = malloc_elem(in, s, i, n);
	while (i < j)
	{
		i = into_elem_quotes(in, s, i, n);
		if (s[i] == ' ')
			break ;
		in->elem->cont[n][i] = s[i];
		i++;
	}
	in->elem->cont[n][i] = '\0';
	free(s);
	return (i);
}

int	parsing_misc(t_shell *sh, int i, char **input)
{
	while (++i < sh->nbr_cmd)
	{
		if (input[i] == NULL && sh->nbr_cmd > 1)
		{
			ft_end(ERR_TOKEN, ERR_REDIR, 1);
			return (NO_RESULT);
		}
		sh->in[i].cont = input[i];
	}
	i = -1;
	while (++i < sh->nbr_cmd)
	{
		sh->in[i].nbr_elem = 1;
		count_spaces(&sh->in[i], sh->in[i].cont);
		sh->in[i].elem = malloc(sizeof(t_elem));
		protect_malloc((char *)sh->in[i].elem);
		sh->in[i].elem->cont = malloc(sizeof(char *)
				* (sh->in[i].nbr_elem + 1));
		protect_malloc((char *)sh->in[i].elem->cont);
		parsing_elem(sh, sh->in[i].cont, i);
	}
	return (0);
}
