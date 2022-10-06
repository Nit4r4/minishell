
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:11:57 by creyt             #+#    #+#             */
/*   Updated: 2022/09/22 15:44:06 by creyt            ###   ########.fr       */
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
	char	**envp;
	char	**env_c;
	char	**envp_c;
	char	*cwd;
	char	*cwdbis;
	char	*home;
	int		*fd;
	int		fd_out;
	int		fd_in;
	char	**envp_sorted;
	char	**sorted;
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
	char	**e_c;
	char 	**cm;
	char	**split_pipe;
	char	*path;
	char	*path_cmd;
	int		**fd_pipe;
	int		*code_caractere;
	int		k;
	int		*fd_redir;
	t_shell	*shell;
}	t_cmd;


/* MANDATORY */

/* BUILTINS */

int		ft_cd(t_shell *shell);
int		ft_echo_fd(t_shell *shell);
int		ft_env(t_shell *shell);
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

void	ft_infile_nosplit(t_cmd *cmd, int *j, int i);
void	ft_infile_split(t_cmd *cmd, int *i, int *j);
void	ft_exec_in(t_shell *shell);
char	*ft_cmd_path(t_cmd *cmd);
char	*ft_absolute(t_cmd *cmd);
void	define_input_signals_block(void);
void	define_input_signals(void);
char	*ft_set_cmd(t_cmd *cmd, int *j, int i);

/* UTILS */

char	**ft_split_modif(char *s, char c, int *code_caractere);

/* MANDATORY */

#endif
