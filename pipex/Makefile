# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 16:55:24 by mle-duc           #+#    #+#              #
#    Updated: 2023/07/10 14:11:04 by mle-duc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			pipex

CC =			cc

RM =			rm -f

INC_DIR =		./inc

LIBFT_DIR =		./libft

SRCS =			$(addprefix src/, \
				utils.c \
				path.c \
				main.c)

OBJS =			${SRCS:.c=.o}

CFLAGS =		-Wall -Werror -Wextra

LIBFT_PATH =	libft/libft.a

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -I $(INC_DIR) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	$(CC) $(OBJS) ${CFLAGS} -L${LIBFT_DIR} -lft -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
