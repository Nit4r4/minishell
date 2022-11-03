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

SRCS 	= srcs/prompt/prompt.c srcs/prompt/to_the_end.c srcs/prompt/path.c srcs/prompt/files_redir.c \
		  srcs/parsing/parsing.c srcs/parsing/signals.c srcs/parsing/dollar.c srcs/parsing/execve.c \
		  srcs/parsing/quotes.c utils/for_redir.c srcs/prompt/redir.c srcs/prompt/re_redir.c utils/for_quotes.c\
		  utils/for_parsing.c utils/elem_for_parsing.c srcs/builtins/b_builtins.c utils/for_redir_security.c \
		  utils/ft_split_exception.c srcs/builtins/b_echo.c srcs/builtins/b_env_utils.c srcs/memory/free.c\
		  srcs/builtins/b_cd.c srcs/builtins/b_export.c utils/ft_split_ex_utils.c utils/ft_strjoin_free.c\
		  srcs/builtins/b_init.c srcs/builtins/b_unset.c srcs/builtins/cmd_selector.c srcs/minishell.c \

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
