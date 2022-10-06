/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:21:03 by vferraro          #+#    #+#             */
/*   Updated: 2022/10/06 16:37:39 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <termios.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../utils/libft/libft.h"
# include "../utils/ft_printf/ft_printf.h"

/* DEFINE COLORS */
# define PURP "\e[35m"
# define GREEN "\e[32m"
# define RED "\e[31m"
# define WHITE "\e[39m"
# define YELLOW "\033[33m"
# define ORANGE "$(shell tput setaf 208)"
# define RESET "\e[0"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

/* ERRORS MESSAGES */
# define ERR "\e[31mERROR"

/* STRUCT */
typedef struct s_shell
{
	char	**var;
	char	**env;
	char	**env_c;
	char	**envp;
	char	**sorted;
	char	*cwd;
	char	*cwdbis;
	char	*home;
	int		*fd;
	int		fd_out;
	int		fd_in;
	t_cmd	*cmd;

}	t_shell;

typedef struct s_cmd
{
	char	**args;
	char	**new_args;
	char	*new_arg;
	char	**cmd;
	char	**cmd_test;
	char	**commande;
	char	**e_c; // pourquoi e_c ? ca correspond a quoi
	char	**cm;
	char	**split_pipe;
	char	*path;
	char	*path_cmd;
	int		**fd_pipe;
	int		nbr_cmd;
	int		k;
	int		*code_caractere;
	int		*fd_redir;
	t_shell	*shell;

}	t_cmd;

/* GLOBAL VARIABLE */
char	**g_var;

/* UTILS */
void	ft_execute_inbuilt(char **cmd_test, char **envp_copy);
int		ft_process_one_nosplit(int *pid, char **cmd, char **enenvp_copyvp);
int		ft_process_one_split(int *pid, char **cmd, char **envp_copy);
char	**ft_get_path(void);
char	*ft_path(char *str);
int		*ft_quote_place(char *str);
int		ft_nbr_quote(char *str);
void	ft_check_quote(char **tab, int n);
char	**ft_parsing_quote(char *str);
char	**ft_split_modif(char *s, char c, int *code_caractere);
int		ft_cmd_error(char *path_cmd, char **cmd_infile, int *pid);
int		ft_check_builtins(char **cmd);
void	ft_execute_inbuilt_fd(int fd_out, char **cmd_test, char **envp_copy);
int		ft_cd(t_shell *shell);
void	ft_free_tab_simple(char **tab);
int		ft_subopen_code_caractere(char *str, int i);
char	**ft_check_redir(int *fd, char **cmd, char **commande);
void	ft_cpy_tab(char **original, char **copy);
int		ft_error(char *path_cmd, char **cmd_infile);
void	ft_exec_in(int fd_in, char **commande, char **envp_copy);
int		ft_exec_out(int fd_out, char **commande, char **envp_copy);
char	*ft_check_quote_simple(char *tab);
int		*ft_code_char(char *str);
char	*ft_set_file(char **cmd, int *j, int i);
void	ft_error_fd(int fd, char *infile);
void	ft_infile_split(char **cmd, int *fd, int *i, int *j);
void	ft_infile_nosplit(char **cmd, int *fd, int *j, int i);
void	ft_outfile_split(char **cmd, int *fd, int *i, int *j);
void	ft_outfile_nosplit(char **cmd, int *fd, int i, int *j);
void	ft_outfile_nosplit_append(char **cmd, int *fd, int i, int *j);
char	*ft_check_dollars(char *str, char **envp, int *code_caractere);
char	*ft_strjoin_modif_free(char *s1, char const s2);
int		ft_static(int i);
void	ft_files(char **cmd, int *fd, int *j, int *i);
int		ft_write_tmp(int fd_out, char *str);
void	ft_infile_tmp(char **cmd, int *fd, int i, int *j);
char	*ft_absolute(char **cmd);
void	ft_export_fd(int fd_out, char **cmd_test, char **envp_copy);
void	handle_global_signals(void);
char	*ft_cmd_path(char **cmd);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_set_file_bis(char **cmd, int *j, int *i);
void	ft_outfile_split_append(char **cmd, int *fd, int *i, int *j);
void	ft_infile_tmp_split(char **cmd, int *fd, int *i, int *j);
void	define_input_signals_block(void);
int		ft_static_multi(int i);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_return_change(char *str, char **envp_copy, int start, int len);
char	*ft_strjoin_modif_free_free(char *s1, char const s2, int *c_c);
void	ft_increase(int *i, int *len, char *str);
char	*ft_tmp_cmp(char **envp_copy, char *tmp_bis, int k);
char	*ft_change_value(char *str, char **envp_copy, int start, int len);
void	ft_free_two(char *tmp_cmp, char *tmp_bis);
int		ft_co(char *str, char **envp_copy, int start, int len);
int		ft_issign(char c);
int		ft_isspace(int c);
char	*ft_set_magic_word(char **cmd, int *j, int i);
char	*ft_set_magic_word_split(char **cmd, int *j, int i);
char	*ft_strfinal_join(char *str_final, char *str_tmp);
void	ft_free_infile_tmp(char *str_tmp, char *magic_word, char *str_final);
int		ft_check_close_quote(char *str);
void	ft_infile_tmp(char **cmd, int *fd, int i, int *j);
void	ft_boucle_while(char *infile, char *magic_word, int *fd);
void	ft_write_close(int fd_tmp, char *str_final);
void	ft_check_to_close_open(int *fd, char *infile);
void	ft_fd_error(char *magic_word, int *fd);
char	*ft_getenv_glob(char *str);
char	*ft_path_test(char *str);
int		ft_check_space_test(char *str);
void	ft_sort_alpha_bis(void);
char	*ft_set_file(char **cmd, int *j, int i);
char	*ft_set_file_bis(char **cmd, int *j, int *i);
int		a(int j);
int		b(int j);
void	ft_very_first_if(char **c, int *fd, int *i, int *j);
char	*ft_set_cmd(char **cmd, int *j, int i, int *code_caractere);

/* BUILTINS */
void	ft_replace_pwd(t_shell *shell);
int		ft_cd(t_shell *shell);
int		ft_echo_fd(t_shell *shell);
int		ft_env_fd(t_shell *shell);
int		ft_exit(t_cmd *cmd);
int		ft_issign(char c);
int		ft_isspace(int c);
int		ft_export(t_shell *shell);
int		ft_nbr_args(t_shell *shell);
void	ft_sort_alpha(t_shell *shell);
void	ft_print_all(t_shell *shell);
void	ft_write_all(t_shell *shell);
int		ft_pwd(void);
int		ft_pwd_fd(t_shell *shell);
void	ft_unset(t_shell *shell);
void	ft_unset_export(t_shell *shell);
void	ft_unset_multi(t_shell *shell);
void	ft_sort_alpha_bis(void);
void	ft_sort_alpha_bis_envp(t_shell *shell);

/* PARSING */
void	display_prompt(int num);
void	define_input_signals(void);
void	ft_close_middle(t_cmd *cmd);
void	ft_close_all(t_cmd *cmd);
void	ft_close_fl(t_cmd *cmd);
void	ft_free_all(t_cmd *cmd, char *s1, char *s2);
char	*ft_strjoin_free_free(t_cmd *cmd, char *s1, char *s2);
void	ft_export_basic(t_shell *shell, char **envp_sorted);
void	ft_export_basic_fd(int fd_out, char **envp);
void	ft_export_fd_multi(t_shell *shell);
void	ft_export_fd_test(t_shell *shell, char **g_var);
void	ft_export_new_args(t_cmd *cmd);
void	ft_sort_new_args(t_cmd *cmd);
char	*ft_error_cmd(t_cmd *cmd);
void	ft_no_in_process(t_shell *shell);
void	ft_inbuilts(t_cmd *cmd);
void	ft_exec_first(t_cmd *cmd);
void	ft_first_process(t_cmd *cmd, char **split_pipe);
void	ft_in_process(t_shell *shell);
void	ft_process_in_out(t_cmd *cmd);
void	ft_process_in(t_cmd *cmd);
void	ft_process_out(t_cmd *cmd);
int		ft_prob_infile(t_cmd *cmd);
void	ft_process_last(t_shell *shell);
void	ft_process_last_out(t_shell *shell);
void	ft_close_two_sup(t_cmd *cmd);
void	ft_execute_last(t_cmd *cmd);
void	ft_last_process(t_cmd *cmd, int i);
void	ft_process_middle_bis(t_shell *shell);
void	ft_close_because_too_long(t_cmd *cmd);
void	ft_process_middle_bis(t_shell *shell);
void	ft_execute_mid(t_cmd *cmd);
void	ft_inbuilts_mid(t_cmd *cmd);
void	ft_middle_process(t_cmd *cmd, int i);
int		ft_nc(t_cmd *cmd);
int		ft_pipes(t_cmd *cmd, int **fd);
void	ft_waitpid_all(t_cmd *cmd, int *pid);
void	ft_first_multi(t_cmd *cmd);
int		ft_static_multi(int i);
void	ft_mid_multi(t_cmd *cmd, int i);
void	ft_last_mutli(t_cmd *cmd, int i);
void	ft_exec_all_multi(t_cmd *cmd, int *pid);
int		ft_pipex_multi(t_cmd *cmd);
char	*ft_sub_pro_one(t_cmd *cmd);
int		ft_process_one_classic(t_cmd *cmd, char **g_var);
void	ft_fork_or_not(t_cmd *cmd, char **envp_copy);
void	ft_exec_one(t_cmd *cmd, char **g_var);
void	ft_one(t_cmd *cmd, char **g_var);
void	ft_files(char **c, int *fd, int *j, int *i);
void	ft_dup_close(int *fd);
void	ft_execute(t_cmd *cmd);
void	ft_close_close(int *fd);
int		ft_exec_in_out(t_cmd *cmd);
void	ft_process_onlyone(t_cmd *cmd, char **g_var);
int		ft_too_long(t_cmd *cmd, int i);
int		ft_too_long_bis(t_cmd *cmd, int i);

/* MEMORY */
char	**ft_malloc_tab(char **original);
char	**ft_malloc_var(char **original);
void	ft_free_tab_simple(char **tab);
void	ft_free_tab_int(t_shell *shell, int *pid);

#endif