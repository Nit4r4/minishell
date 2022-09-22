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

SRCS 	= builtins/echo.c builtins/pwd.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= builtins/echo.c

HEADER	= -Iinclude

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror #-g -fsanitize=address

LIBFT_PATH = ./utils/libft/
LIB = utils/libft/libft.a

AR = ar rc
RM = rm -f

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "$(CYAN)---- Compiling library ----"
					@$(MAKE) -C $(LIBFT_PATH)
					@$(CC) $(CFLAGS) ${OBJS} -o $(NAME) $(LIB)
					@sleep 0.2
					@printf "$(GREEN)🍵 Creating $(NAME)$(RESET)\n"
					@sleep 0.2
					@echo "$(GREEN2)Minishell Compiled ! \033[32m(\033[31m๑\033[32m╹◡╹\033[31m๑\033[32m)"
					@sleep 0.2

clean:
					@${RM} ${OBJS}
					@$(MAKE) -C $(LIBFT_PATH) clean
					@echo "$(CYAN)---- Compiling library ----"
					@sleep 0.2
					@printf "$(YELLOW)🧽 Cleaning $(NAME)$(RESET)\n"
					@sleep 0.2
					@echo "$(YELLOW)Minishell is clean ! $(ORANGE)(ﾉ◕ヮ◕)ﾉ$(YELLOW)*:･ﾟ✧"
					@sleep 0.2

fclean: 	clean
					@${RM} $(NAME)
					@$(MAKE) -C $(LIBFT_PATH) fclean
					@echo "\033[31mEverything is deleting now ! ¯\_(ツ)_/¯"
					@sleep 0.2
					@printf "\r$(PURP)🗑  $(NAME) have been removed$(RESET)\n"
					@sleep 0.2

re:			fclean all

.PHONY: all clean fclean re party
