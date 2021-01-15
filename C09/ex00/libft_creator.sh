# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubonill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 17:50:15 by jubonill          #+#    #+#              #
#    Updated: 2020/10/26 12:49:33 by jubonill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash/
gcc -c -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a *.o
ranlib libft.a
