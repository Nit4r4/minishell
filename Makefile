PURP = \e[35m
GREEN = \e[32m
GREEN2 = \033[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \033[33m
ORANGE = $(shell tput setaf 208)
HIDDEN = \e[8m
RESET = \e[0
BLUE = \033[34m
CYAN = \033[36m

NAME = minishell

SRCS 	= srcs/minishell.c\
		get_path.c\
		split_modif.c\
		signals.c\
		exec_builtins.c\
		one_cmd.c\
		multi_cmds.c\
		errors.c\
		echo.c\
		cd.c\
		unset.c\
		env.c\
		export.c\
		pwd.c\
		exit.c\
		export_utils.c\
		minishell_utils.c\
		free.c\
		malloc.c\
		code_char.c\
		redirections_main.c\
		redir_in.c\
		redir_out.c\
		redir_in_out.c\
		quotes.c\
		first_process.c\
		mid_process.c\
		last_process.c\
		close_fd.c\
		dollar.c\
		dollar_utils.c\
		dollar_utils_bis.c\
		heredoc.c\
		vodka.c\
		exit_utils.c\
		first_process_utils.c\
		export_utils_bis.c\
		heredoc_utils.c\
		last_process_utils.c\
		multi_cmds_utils.c\
		one_cmd_utils.c\
		redir_out_utils.c\
		heredoc_utils_bis.c\
		unset_utils.c\
		redir_in_out_utils.c\
		redirections_main_utils.c

OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/minishell.c

HEADER	= -Iinclude

RL_V	:= $(shell brew list --versions  readline | sed 's/.*[[:blank:]]//')
RL_P	:= $(shell brew --cellar readline)
RL		= $(RL_P)/$(RL_V)

INC		= -I. -I $(RL)/include/

LIB = utils/libft/libft.a utils/ft_printf/libftprintf.a
LBFT_PATH = ./utils/libft/
PRINTF_PATH = ./utils/ft_printf/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror #-g -fsanitize=address
LFLAGS = -lreadline

LIBS	= -L $(RL)/lib/ -lreadline -lhistory

AR = ar rc
RM = rm -f

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $(INC) $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "$(CYAN)---- Compiling library ----"
					@sleep 0.2
					@echo "$(GREEN2)📚 Link paths"
					@$(MAKE) -C $(LBFT_PATH)
					@$(MAKE) -C $(PRINTF_PATH)
					@$(CC) $(CFLAGS) ${LFLAGS} ${OBJS} -o $(NAME) $(LIB) $(LIBS)
					@printf "$(BLUE)🍵 Creating $(NAME)$(RESET)\n"
					@sleep 0.2
					@echo "$(CYAN)MiniShell Compiled ! \033[39m(\033[31m๑\033[39m╹◡╹\033[31m๑\033[39m)"
					@sleep 0.2

clean:	
					@${RM} ${OBJS}
					@echo "$(YELLOW)---- Cleaning library ----"
					@sleep 0.2
					@printf "$(BLUE)🧽 Cleaning $(NAME)$(RESET)\n"
					@$(MAKE) -C $(LBFT_PATH) clean
					@$(MAKE) -C $(PRINTF_PATH) clean
					@echo "$(GREEN2)📚 Cleaning paths"
					@sleep 0.2
					@echo "$(YELLOW)MiniShell is all clean ! $(ORANGE)(ﾉ◕ヮ◕)ﾉ$(YELLOW)*:･ﾟ✧"
					@sleep 0.2

fclean: 	clean
					@${RM} $(NAME)
					@$(MAKE) -C $(LBFT_PATH) fclean
					@echo "\033[31mEverything is deleting now ! ¯\_(ツ)_/¯"
					@sleep 0.2
					@printf "\r$(PURP)🗑  $(NAME) have been removed$(RESET)\n"
					@sleep 0.2

re:			fclean all

.PHONY: all clean fclean re party