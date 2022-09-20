# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 12:40:16 by vferraro          #+#    #+#              #
#    Updated: 2021/11/15 18:00:43 by vferraro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD 		= libft.h
SRC 		= ft_isalnum.c ft_memcmp.c ft_strncmp.c ft_strlcat.c \
					ft_substr.c	ft_strncmp.c ft_strdup.c ft_atoi.c ft_isalpha.c \
					ft_strjoin.c ft_memcpy.c ft_strchr.c  ft_strlcpy.c ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
					ft_isprint.c ft_memmove.c ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c \

OBJ 			= $(SRC:.c=.o)
BONUS			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c
BONUS_OBJS		= $(BONUS:.c=.o)
CC 				= @gcc 
CFLAGS  		= -Wall -Wextra -Werror
RM 				= @rm -f
NAME 			= libft.a
all: 		$(NAME)

$(NAME): 	$(OBJ)
##				$(CC) $(FLAGS) -c $(SRC)
				@ar -rc $(NAME) $(OBJ)

clean:		
				$(RM) $(OBJ) $(BONUS_OBJS)
fclean:		clean 
				$(RM) $(NAME)

re:			fclean $(NAME)
bonus:			$(OBJS) $(BONUS_OBJS)
				@ar -rc $(NAME) $(OBJS) $(BONUS_OBJS)
.PHONY: 	all clean fclean re
