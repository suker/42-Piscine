# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubonill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 18:17:10 by jubonill          #+#    #+#              #
#    Updated: 2020/10/28 18:47:30 by jubonill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=ft_cat
SRCS=srcs/main.c srcs/ft_algo.c
OBJS=${SRCS:.c=.o}
CC=gcc
CFLAGS=-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
