# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 16:55:24 by mle-duc           #+#    #+#              #
#    Updated: 2023/10/09 16:55:10 by mle-duc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			minishell

CC =			cc

RM =			rm -f

INC_DIR =		./inc

LIBFT_DIR =		./libft

SRCS =			$(addprefix src/, \
				$(addprefix builtin/, \
				exit.c \
				echo.c \
				env.c \
				pwd.c) \
				main.c)

OBJS =			${SRCS:.c=.o}

CFLAGS =		-g3 #-Wall -Werror -Wextra

LIBFT_PATH =	libft/libft.a

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I $(INC_DIR) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	@$(CC) $(OBJS) ${CFLAGS} -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
