# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubonill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 18:17:10 by jubonill          #+#    #+#              #
#    Updated: 2020/10/25 10:29:55 by jubonill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=srcs/*.c
OBJS=*.o
HEADERS_FOLDER=includes/*.h
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all:${NAME}

${NAME}:
	${CC} ${CFLAGS} -I ${HEADERS_FOLDER} -c ${SRCS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
