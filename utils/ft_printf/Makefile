# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 13:38:07 by vferraro          #+#    #+#              #
#    Updated: 2021/11/26 14:16:14 by vferraro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_printf.c ft_putchar_c.c ft_putstr_s.c ft_ptr_p.c ft_putnbr_d.c \
			 ft_printf_u.c ft_printfhex_x.c
OBJ			= $(SRC:.c=.o)
CC			= @gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= @rm -f
NAME		= libftprintf.a
all:		$(NAME)

$(NAME):	$(OBJ)
				@ar -rcs $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
