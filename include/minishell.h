/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:11:57 by creyt             #+#    #+#             */
/*   Updated: 2022/09/22 13:05:19 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../utils/libft/libft.h"

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

# define MAX_PATH 1024

/* ERRORS MESSAGES */

/* STRUCT */

/* UTILS */

/* MANDATORY */

int		ft_echo(char **tab);
int		ft_pwd(void);

#endif
