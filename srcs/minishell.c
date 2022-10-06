/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:07:17 by santonie          #+#    #+#             */
/*   Updated: 2022/10/06 15:20:51 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_static(int i)
{
	static int	return_val = 0;

	if (i != 300)
		return_val = i;
	return (return_val);
}

int	ft_np(char *str)
{
	int	i;
	int	*c_c;
	int	nbr_pipe;

	i = 0;
	nbr_pipe = 0;
	c_c = ft_code_char(str);
	while (str[i])
	{
		if (str[i] == '|' && c_c[i] == 6)
			nbr_pipe++;
		i++;
	}
	free (c_c);
	return (nbr_pipe);
}

char	*ft_getenv_glob(char *str)
{
	int		i;
	char	*tmp;
	char	**tab_tmp;

	i = 0;
	while (g_var[i])
	{
		tmp = ft_tmp_cmp(g_var, "", i);
		if (ft_strcmp(str, tmp) != 0)
		{
			free (tmp);
			i++;
		}
		else
		{
			tab_tmp = ft_split(g_var[i], '=');
			free (tmp);
			tmp = ft_strdup(tab_tmp[1]);
			ft_free_tab_simple(tab_tmp);
			return (tmp);
		}
	}
	return (NULL);
}

void	ft_exec_cmd(char *str, char **envp_copy)
{
	t_cmd	*cmd;
	t_shell	*shell;

	define_input_signals_block();
	if (ft_check_close_quote(str) != 0)
		return ;
	cmd->code_caractere = ft_code_char(str);
	if (str[0])
		str = ft_check_dollars(str, envp_copy, cmd->code_caractere);
	free(cmd->code_caractere);
	cmd->code_caractere = ft_code_char(str);
	cmd->split_pipe = ft_split_modif(str, '|', cmd->code_caractere);
	if (ft_nc(cmd->split_pipe) == 1 && (ft_nc(cmd->split_pipe) > ft_np(str)))
		ft_one(cmd->split_pipe, envp_copy, cmd->code_caractere);
	else if (ft_nc(cmd->split_pipe) >= 2 && (ft_nc(cmd->split_pipe) > ft_np(str)))
		ft_pipex_multi(cmd->split_pipe, envp_copy);
	else if (str[0] != '\0')
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		ft_static(258);
	}
	ft_free_tab_simple(cmd->split_pipe);
	free(str);
	free(cmd->code_caractere);
}

int	main(int argc, char **argv)
{
	t_shell	*shell;
	//t_cmd	*cmd;
	char	*str;

	(void)argv;
	g_var = ft_malloc_tab(shell->envp);
	ft_cpy_tab(shell->envp, g_var);
	if (argc != 1)
		return (1);
	while (42)
	{
		define_input_signals();
		str = readline("minishell-1.0$ ");
		if (str == NULL)
			break ;
		if (ft_check_space_test(str) == 1 || str[0] == '\0')
		{
			ft_static(0);
			str[0] = '\0';
		}
		else
			add_history(str);
		ft_exec_cmd(str, g_var);
	}
	ft_free_tab_simple(g_var);
	return (ft_static(300));
}
