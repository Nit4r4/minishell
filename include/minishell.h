/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:21:03 by vferraro          #+#    #+#             */
/*   Updated: 2022/10/04 15:23:30 by vferraro         ###   ########.fr       */
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
# include <pthread.h>
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

/* GLOBAL VARIABLE */
char	**g_var;

/* UTILS */
void	display_prompt(int num);
void	define_input_signals(void);
int		ft_echo(char **cmd_test);
void	ft_execute_inbuilt(char **cmd_test, char **envp_copy);
void	ft_process_onlyone(char *path_cmd, char **cmd, char **envp_copy);
int		ft_process_one_classic(char **cmd, char **envp_copy);
int		ft_process_one_nosplit(int *pid, char **cmd, char **enenvp_copyvp);
int		ft_process_one_split(int *pid, char **cmd, char **envp_copy);
void	ft_one(char **split_pipe, char **envp_copy, int *code_caractere);
int		ft_giant_pipex(char **split_pipe, int nbr_cmd, char **envp_copy,
			int *code_caractere);
char	**ft_get_path(void);
char	*ft_path(char *str);
void	ft_process_onlyone(char *path_cmd, char **cmd, char **envp_copy);
void	ft_process_last(int fd_in, int fd_out, char **cmd, char **envp_copy);
int		*ft_quote_place(char *str);
int		ft_nbr_quote(char *str);
void	ft_check_quote(char **tab, int n);
char	**ft_parsing_quote(char *str);
char	**ft_split_modif(char *s, char c, int *code_caractere);
int		ft_cmd_error(char *path_cmd, char **cmd_infile, int *pid);
int		ft_check_builtins(char **cmd);
void	ft_execute_inbuilt_fd(int fd_out, char **cmd_test, char **envp_copy);
int		ft_cd(char **cmd_test, char **envp_copy);
void	ft_unset(char **cmd_test);
int		ft_env(char **envp_copy, char **args_in);
int		ft_pwd(void);
int		ft_echo_fd(int fd_out, char **cmd_test);
int		ft_exit(char *args[]);
void	ft_sort_alpha(char **sorted);
int		ft_nbr_args(char **cmd_test);
char	**ft_malloc_tab(char **original);
char	**ft_malloc_var(char **original);
void	ft_sort_alpha(char **sorted);
void	ft_printf_all(char **sorted);
void	ft_free_tab_simple(char **tab);
int		ft_subopen_code_caractere(char *str, int i);
char	**ft_check_redir(int *fd, char **cmd, char **commande);
int		ft_pipex_multi(char **split_pipe, char **envp_copy);
void	ft_cpy_tab(char **original, char **copy);
int		ft_error(char *path_cmd, char **cmd_infile);
void	ft_exec_in(int fd_in, char **commande, char **envp_copy);
int		ft_exec_in_out(int *fd, char **commande);
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
void	ft_free_tab_int(int **fd, int *pid, int nbr_cmd);
void	ft_first_process(char **split_pipe, int **fd_pipe, char **envp_copy);
void	ft_middle_process(int i, char **split_pipe, int **fd_pipe,
			char **envp_copy);
void	ft_last_process(int i, char **split_pipe, int **fd_pipe,
			char **envp_copy);
void	ft_close_middle(int k, int nbr_cmd, int **fd_pipe);
void	ft_close_all(int nbr_cmd, int **fd_pipe);
void	ft_close_fl(int k, int nbr_cmd, int **fd_pipe);
char	*ft_check_dollars(char *str, char **envp, int *code_caractere);
char	*ft_strjoin_modif_free(char *s1, char const s2);
int		ft_static(int i);
void	ft_files(char **cmd, int *fd, int *j, int *i);
int		ft_write_tmp(int fd_out, char *str);
void	ft_infile_tmp(char **cmd, int *fd, int i, int *j);
char	*ft_absolute(char **cmd);
void	ft_write_all(int fd_out, char **sorted);
void	ft_export_fd(int fd_out, char **cmd_test, char **envp_copy);
int		ft_env_fd(int fd_out, char **envp_copy, char **args_in);
int		ft_pwd_fd(int fd_out);
char	*ft_error_cmd(char **cmd);
void	handle_global_signals(void);
char	*ft_cmd_path(char **cmd);
char	*ft_strjoin_free(char *s1, char const *s2);
void	ft_fork_or_not(char **commande, char **envp_copy, int fd_out);
void	ft_export_fd_multi(int fd_out, char **cmd_test, char **envp_copy);
void	ft_execute_inbuilt_fd_multi(int fd_out, char **cmd_test,
			char **envp_copy);
void	ft_unset_multi(char **cmd_test);
char	*ft_set_file_bis(char **cmd, int *j, int *i);
void	ft_outfile_split_append(char **cmd, int *fd, int *i, int *j);
void	ft_infile_tmp_split(char **cmd, int *fd, int *i, int *j);
void	define_input_signals_block(void);
int		ft_static_multi(int i);
char	*ft_strjoin_free(char *s1, char const *s2);
void	ft_free_all(char *s1, char *s2, int *code_caractere);
char	*ft_strjoin_free_free(char *s1, char *s2, int *code_caractere);
char	*ft_return_change(char *str, char **envp_copy, int start, int len);
char	*ft_strjoin_modif_free_free(char *s1, char const s2, int *c_c);
void	ft_increase(int *i, int *len, char *str);
char	*ft_tmp_cmp(char **envp_copy, char *tmp_bis, int k);
char	*ft_change_value(char *str, char **envp_copy, int start, int len);
void	ft_free_two(char *tmp_cmp, char *tmp_bis);
int		ft_co(char *str, char **envp_copy, int start, int len);
int		ft_issign(char c);
int		ft_isspace(int c);
void	ft_no_in_process(int fd_in, int fd_out, char **cmd, char **envp);
void	ft_in_process(int fd_in, int fd_out, char **cmd, char **envp);
void	ft_process_in_out(int *fd_redir, int **fd_pipe,
			char **commande, char **envp);
void	ft_process_in(int *fd_redir, int **fd_pipe,
			char **commande, char **envp);
void	ft_process_out(int *fd_redir, int **fd_pipe,
			char **commande, char **envp);
int		ft_prob_infile(char **commande);
char	*ft_error_cmd(char **cmd);
void	ft_inbuilts(int *fd_redir, int **fd_pipe, char **commande, char **envp);
void	ft_exec_first(int *fd_redir, int **fd_pipe,
			char **commande, char **envp);
void	ft_first_process(char **split_pipe, int **fd_pipe, char **envp);
void	ft_export_basic(char **envp, char **envp_sorted, char **args);
void	ft_export_basic_fd(int fd_out, char **envp);
void	ft_export_new_args(char **cmd_test, char **new_args);
void	ft_sort_new_args(char **new_args);
char	*ft_set_magic_word(char **cmd, int *j, int i);
char	*ft_set_magic_word_split(char **cmd, int *j, int i);
char	*ft_strfinal_join(char *str_final, char *str_tmp);
void	ft_free_infile_tmp(char *str_tmp, char *magic_word, char *str_final);
void	ft_process_last(int fd_in, int fd_out, char **cmd, char **envp);
void	ft_process_last_out(int fd_in, int fd_out, char **cmd, char **envp);
void	ft_close_two_sup(int **fd_pipe, int k);
int		ft_nc(char **split_pipe);
int		ft_pipes(int **fd, int nbr_cmd);
void	ft_waitpid_all(int nbr_cmd, int *pid);
void	ft_first_multi(int **fd_pipe, char **split_pipe, char **envp);
void	ft_process_onlyone(char *path_cmd, char **cmd, char **g_var);
int		ft_too_long(char *path_cmd, char **cmd, int i);
int		ft_check_close_quote(char *str);
void	ft_infile_tmp(char **cmd, int *fd, int i, int *j);
void	ft_boucle_while(char *infile, char *magic_word, int *fd);
void	ft_write_close(int fd_tmp, char *str_final);
void	ft_check_to_close_open(int *fd, char *infile);
void	ft_fd_error(char *magic_word, int *fd);
int		ft_too_long_bis(char *path_cmd, char *cmd, int i);
char	*ft_getenv_glob(char *str);
void	ft_unset_export(char *cmd_test);
void	ft_export_fd_test(int fd_out, char **cmd_test, char **g_var);
char	*ft_path_test(char *str);
int		ft_check_space_test(char *str);
void	ft_sort_alpha_bis(void);
void	ft_sort_alpha_bis_envp(char **g_var);
char	*ft_set_file(char **cmd, int *j, int i);
char	*ft_set_file_bis(char **cmd, int *j, int *i);
int		a(int j);
int		b(int j);
void	ft_very_first_if(char **c, int *fd, int *i, int *j);
char	*ft_set_cmd(char **cmd, int *j, int i, int *code_caractere);

/* BUILTINS */
/* PARSING */
/* MANDATORY */

int		ft_no_one(char *str);

#endif